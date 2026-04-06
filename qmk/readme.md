# QMK Firmware

Custom QMK firmware for my keyboards.

## Keyboards

### Mode M256WH

#### Compile

```bash
qmk compile -kb mode/m256wh -km giovannibenussi
```

#### Flash

```bash
qmk flash -kb mode/m256wh -km giovannibenussi
```

#### Keymap

```
keyboards/mode/m256wh/keymaps/giovannibenussi/keymap.c
```

### ZSA Moonlander

#### Compile

```bash
qmk compile -kb zsa/moonlander -km giovannibenussi
```

#### Flash

```bash
qmk flash -kb zsa/moonlander -km giovannibenussi
```

Press the reset button (small hole on top-left edge of left half) or use a QK_BOOT key to enter bootloader mode.

#### Keymap

```
keyboards/zsa/moonlander/keymaps/giovannibenussi/keymap.c
```

## Shared Features

- Home row mods (A=Cmd, S=Ctrl, D=Opt, F=Shift, J=Shift, K=Opt, L=Ctrl, ;=Cmd)
- ; sends Backspace on tap, Cmd on hold
- Left Shift sends Caps Lock on tap, Shift on hold
- V hold activates symbols layer
- N/M hold activates numbers + tmux/vim layer
- Space hold activates navigation layer
- J+K combo sends Enter
- S+D combo sends previous tab, D+F combo sends next tab, S+D+F combo sends previous application
