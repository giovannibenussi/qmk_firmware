# QMK Firmware

- Always add spacing so I can look at the keymap file as if I'm looking at my keyboard. Right now it's hard to know how it should look.

Three keyboards sharing a similar keymap philosophy. All keymaps aim to stay in sync.

## Keyboards

### Mode M256WH (primary)
- 65% ANSI layout
- Keymap: `keyboards/mode/m256wh/keymaps/giovannibenussi/keymap.c`
- Flash: `qmk flash -kb mode/m256wh -km giovannibenussi`
- Bootloader: hold ESC while plugging in USB (bootmagic), or use QK_BOOT key

### ZSA Moonlander
- Split ortholinear keyboard with thumb clusters
- Keymap: `keyboards/zsa/moonlander/keymaps/giovannibenussi/keymap.c`
- Config: `keyboards/zsa/moonlander/keymaps/giovannibenussi/config.h`
- Colors: `keyboards/zsa/moonlander/keymaps/giovannibenussi/colors.h`
- Flash: `qmk flash -kb zsa/moonlander -km giovannibenussi`
- Bootloader: reset button (small hole on top-left of left half) or QK_BOOT key
- Rule: never assign keys to the right side of the left hand or the left side of the right hand (uncomfortable to reach)

### Nuphy Halo65 V2 (separate folder)
- 65% ANSI layout with side RGB LEDs
- Lives in the `halo_qmk_firmware/` folder due to QMK version incompatibility
- Keymap: `keyboards/nuphy/halo65_v2/ansi/keymaps/default/keymap.c`
- Flash: `qmk flash -kb nuphy/halo65_v2/ansi -km default`
- Has custom RGB effects in `rgb_matrix_user.inc` (position_mode, game_mode)
- Side LEDs controlled separately via `side.c` (not standard QMK RGB matrix)

## Shared Keymap Features

All three keyboards share these features (keep them in sync when making changes):

- Home row mods: A=Cmd, S=Ctrl, D=Opt, F=Shift, J=Shift, K=Opt, L=Ctrl, ;=Cmd
- ; sends Backspace on tap, Cmd on hold (`LCMD_T(KC_BSPC)`)
- Left Shift sends Caps Lock on tap, Shift on hold (`LSFT_T(KC_CAPS)`)
- V hold activates symbols layer: `()`, `-=`, `*`, `{}`, `'`, `?/`, `<>`
- N/M hold activates numbers + tmux/vim layer: 1-0 on QWERTY row
- Space hold activates navigation layer: arrow keys on HJKL
- J+K combo sends Enter (with `COMBO_MUST_TAP` so holding for mods doesn't trigger it)
- S+D combo = previous tab, D+F combo = next tab, S+D+F combo = previous application
- F+G combo sends Enter
- Fn + number row: `` ` ``, brightness, mission control, launchpad, media controls, volume

## Tmux Macros
- TMUX_PREVIOUS_WINDOW: `Ctrl+S p`
- TMUX_NEXT_WINDOW: `Ctrl+S n`
- TMUX_CREATE_WINDOW: `Ctrl+S c`
- TMUX_CLOSE_WINDOW: `Ctrl+S xy`
- TMUX_CLOSE_PANE: `Ctrl+S x`
- TMUX_LIST: `Ctrl+S s`
- TMUX_PREVIOUS: `Ctrl+S L`
- TMUX_SCROLL: `Ctrl+S [`
- TMUX_SCROLL_AND_SEARCH: `Ctrl+S [?`
- TMUX_ZOOM: `Ctrl+S z`
