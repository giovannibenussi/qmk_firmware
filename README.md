# Keyboards

Custom QMK firmware for my keyboards. Each folder contains a QMK firmware fork with custom keymaps.

## Keyboards

### Nuphy Halo65 V2 (`halo_qmk_firmware/`)

65% ANSI layout.

```bash
qmk flash -kb nuphy/halo65_v2/ansi -km default
```

Keymap: `keyboards/nuphy/halo65_v2/ansi/keymaps/default/keymap.c`

### Mode M256WH (`qmk/`)

65% ANSI layout.

```bash
qmk flash -kb mode/m256wh -km giovannibenussi
```

Keymap: `keyboards/mode/m256wh/keymaps/giovannibenussi/keymap.c`

### ZSA Moonlander (`qmk/`)

Split ortholinear with thumb clusters.

```bash
qmk flash -kb zsa/moonlander -km giovannibenussi
```

Keymap: `keyboards/zsa/moonlander/keymaps/giovannibenussi/keymap.c`

### Epomaker Galaxy68 (`galaxy68/`)

65% layout with mass storage bootloader.

```bash
qmk compile -kb epomaker/galaxy68 -km via -e SKIP_GIT=yes && cp epomaker_galaxy68_via.bin "/Volumes/NO NAME/FLASH.BIN"
```

Keymap: `keyboards/epomaker/galaxy68/keymaps/via/keymap.c`

## Shared Features

All keymaps share a common philosophy and are kept in sync:

- Home row mods (A=Cmd, S=Ctrl, D=Opt, F=Shift, J=Shift, K=Opt, L=Ctrl, ;=Cmd)
- ; sends Backspace on tap, Cmd on hold
- Left Shift sends Caps Lock on tap, Shift on hold
- V hold activates symbols layer
- N/M hold activates numbers + tmux/vim layer
- Space hold activates navigation layer (arrow keys on HJKL)
- J+K combo sends Enter
- S+D combo sends previous tab, D+F sends next tab, S+D+F sends previous application
