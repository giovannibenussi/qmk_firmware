# Nuphy Halo65 V2 QMK Firmware

## Keyboard

Nuphy Halo65 V2 (ANSI layout, 65% form factor).

Keymap: `keyboards/nuphy/halo65_v2/ansi/keymaps/default/keymap.c`

## Compile and Flash

```bash
qmk flash -kb nuphy/halo65_v2/ansi -km default
```

This compiles and waits for the keyboard to enter bootloader mode (DFU). Put the keyboard in bootloader mode and it will flash automatically.

## Inspiration

The keymap is ported from the Mode M256WH keyboard keymap in the `qmk/` folder:

```
qmk/keyboards/mode/m256wh/keymaps/giovannibenussi/keymap.c
```

Key features ported from the Mode keymap:
- Home row mods (A=Cmd, S=Ctrl, D=Opt, F=Shift, J=Shift, K=Opt, L=Ctrl, ;=Cmd)
- ; sends Backspace on tap, Cmd on hold (`LCMD_T(KC_BSPC)`)
- V hold activates symbols layer (layer 7): `()`, `-=`, `*`, `{}`, `'`, `?/`, `<>`, Enter on space
- N/M hold activates numbers layer (layer 8): numbers 1-0 on QWERTY row, Enter on space

The Mode keymap also has tmux/vim macros and combos that have not been ported yet.
