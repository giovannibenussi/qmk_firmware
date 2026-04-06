# Epomaker Galaxy68 QMK Firmware - Notes

## Important Configuration Notes

### Keyboard Layout Adjustments
The Epomaker Galaxy68 physical keyboard has a different key layout than the standard QMK TKL layout. When creating custom layers with special characters:

- **Keys must be shifted one column to the left** compared to standard layouts
- This was discovered when adapting layer 4 - the curly braces, parentheses, and other symbols needed to be positioned differently to match the physical keyboard
- Example: In layer 4, special characters like `KC_LEFT_CURLY_BRACE` and `KC_RIGHT_CURLY_BRACE` are positioned starting at column 5-6 instead of the typical 6-7

### Custom Layers
The firmware now supports 9 layers (0-8):
- **Layer 0**: Default QWERTY with home row mods
- **Layer 1**: Alternative layout
- **Layer 2**: Function layer (Fn key layer)
- **Layer 3**: Alternative function layer
- **Layer 4**: Symbol layer (parentheses, curly braces, angle brackets, etc.)
- **Layer 5**: Empty/transparent (reserved for future use)
- **Layer 6**: Empty/transparent (reserved for future use)
- **Layer 7**: Number pad layer (shifted one column left)
- **Layer 8**: Navigation and media controls (shifted one column left)

### Flashing Process
The Epomaker Galaxy68 uses a **mass storage bootloader** (not standard DFU):
- Keyboard mounts as a USB drive called "NO NAME" when in bootloader mode
- DO NOT use QMK Toolbox microcontroller selection dropdown
- Flash by copying the .bin file directly to the mounted drive

## Commands Reference

### Build and Flash (Single Command)
```bash
qmk compile -kb epomaker/galaxy68 -km via && cp epomaker_galaxy68_via.bin "/Volumes/NO NAME/FLASH.BIN"
```

### Build Only
```bash
qmk compile -kb epomaker/galaxy68 -km via -e SKIP_GIT=yes
```

**Note**: The `-e SKIP_GIT=yes` flag is required because the git submodules are not fully initialized, causing build errors related to git describe commands.

### Flash Only (after building)
```bash
cp epomaker_galaxy68_via.bin "/Volumes/NO NAME/FLASH.BIN"
```

### Alternative: Manual Flash via Finder
1. Put keyboard in bootloader mode
2. Open the "NO NAME" drive in Finder
3. Copy `epomaker_galaxy68_via.bin` to the drive
4. Rename it to `FLASH.BIN`
5. Keyboard will automatically flash and reboot

## Technical Details

### Processor
- **MCU**: FS026 (custom processor)
- **Bootloader**: Custom (mass storage type)
- **Board**: FS026

### Configuration Files Modified
- `keyboards/epomaker/galaxy68/keymaps/via/keymap.c` - Added layers 4-8, custom keycodes (TMUX_PREVIOUS_WINDOW, TMUX_PREVIOUS)
- `keyboards/epomaker/galaxy68/keymaps/via/config.h` - Set `DYNAMIC_KEYMAP_LAYER_COUNT` to 9
- `keyboards/epomaker/galaxy68/galaxy68.c` - Modified to call `process_record_keymap()` from keymap

### Custom Keycode Implementation
To add custom keycodes without causing multiple definition errors:
1. Define custom keycodes in `keymap.c` using `enum custom_keycodes { YOUR_CODE = SAFE_RANGE, ... }`
2. Implement `process_record_keymap()` (NOT `process_record_user()`) in `keymap.c` to handle your custom keycodes
3. The base `galaxy68.c` file automatically calls `process_record_keymap()` before handling USB/power management
4. This allows custom keycodes to work while preserving the keyboard's built-in functionality

### Combo Support
**Combos are NOT supported on the Epomaker Galaxy68** - they cause boot failure.
- QMK's combo feature is incompatible with the Epomaker custom firmware/bootloader
- Enabling `COMBO_ENABLE = yes` causes the keyboard to fail to boot (even with increased EEPROM)
- Tested with EEPROM sizes from 1152 to 2048 bytes - all configurations fail
- **Alternative solutions for chord-like input:**
  - Use layer-tap (LT) keys for accessing special characters
  - Use tap-dance (if supported)
  - Create custom keycodes that detect simultaneous key presses manually
  - Use VIA to remap keys dynamically

### Key Features
- VIA support (9 layers)
- Encoder support (rotary encoder for volume)
- RGB Matrix lighting
- Bluetooth support (custom)
- NKRO (forced on)

## Troubleshooting

### Compilation Error: "Number of keymap layers exceeds maximum"
- Increase `DYNAMIC_KEYMAP_LAYER_COUNT` in `keyboards/epomaker/galaxy68/keymaps/via/config.h`
- Current value: 9 (supports layers 0-8)

### Flash Error: "FLASH.BIN couldn't be removed"
- This is expected behavior with the mass storage bootloader
- The file is automatically deleted after flashing
- If flashing seems stuck, unplug and replug the keyboard

### Keys Not Matching Physical Layout
- Remember to shift special characters one column to the left
- Reference layer 4 as an example of the proper positioning
- Test each layer thoroughly after creating it

## Layer Activation
- **Layer 4**: Hold V key (LT(4, KC_V) on layer 0)
- **Layers 7-8**: Configure layer tap or momentary keys as needed

## Code Style Guidelines

### Keymap Formatting
When editing keymap layers in `keymap.c`, maintain consistent column alignment:
- Each column should be aligned consistently across all rows within a layer
- Use enough spacing so the longest keycode in each column determines the column width
- This makes the keymap visually readable and easier to maintain
- Example format (each column aligned to fit the widest entry in that column):
```c
[0] = LAYOUT_tkl_ansi(
    QK_GESC,         KC_1,         KC_2,         KC_3,          KC_4,          KC_5,        KC_6,        KC_7,                KC_8,
    KC_TAB,          KC_Q,         KC_W,         KC_E,          KC_R,          KC_T,        KC_Y,        KC_U,                KC_I,
    LT(2, KC_GRAVE), LCMD_T(KC_A), LCTL_T(KC_S), LOPT_T(KC_D),  LSFT_T(KC_F),  KC_G,        KC_H,        LSFT_T(KC_J),        LOPT_T(KC_K),
),
```

## Code Style Guidelines

### Keymap Formatting
When editing keymap layers in `keymap.c`:
- Each column should align to its own widest entry within that layer
- Different columns can have different widths
- Each row ends with a comma followed by a single space (`, `)
- This makes the keymap visually readable and aligned per column
