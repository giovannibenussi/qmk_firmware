# Nuphy Halo65 V2 QMK Firmware

Custom QMK firmware for the Nuphy Halo65 V2 (ANSI layout, 65% form factor).

## Compile

```bash
qmk compile -kb nuphy/halo65_v2/ansi -km default
```

## Flash

```bash
qmk flash -kb nuphy/halo65_v2/ansi -km default
```

This compiles the firmware and waits for the keyboard to enter bootloader mode (DFU). Put the keyboard in bootloader mode and it will flash automatically.

## Keymap

The keymap is located at:

```
keyboards/nuphy/halo65_v2/ansi/keymaps/default/keymap.c
```

### Features

- Home row mods (A=Cmd, S=Ctrl, D=Opt, F=Shift, J=Shift, K=Opt, L=Ctrl, ;=Cmd)
- ; sends Backspace on tap, Cmd on hold
- Left Shift sends Caps Lock on tap, Shift on hold
- V hold activates symbols layer
- N/M hold activates numbers + tmux/vim layer
- Space hold activates navigation layer
- J+K combo sends Enter
- U+I combo sends `"*` (Vim system clipboard register)
- S+D combo sends previous tab, D+F combo sends next tab, S+D+F combo sends previous application

## Reference

The Mode M256WH keyboard keymap is the primary reference for this keymap. See `qmk/keyboards/mode/m256wh/keymaps/giovannibenussi/keymap.c` in this repo.
