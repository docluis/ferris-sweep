# Ferris Sweep

To use the Umlaute keys äöüß choose English (US, international with dead keys) as keyboard layout.

### QMK Setup
```bash
qmk setup
qmk new-keymap -kb ferris/sweep

# qmk compile -kb ferris/sweep -km default
# qmk flash [FIRMWARE_FILE]

# you can set the "master" side in config.h with #define MASTER_RIGHT or #define MASTER_LEFT
```

### Compile and Flash for ProMicro ATmega32U4
```bash
cd ~/qmk_firmware
make ferris/sweep:docluis:avrdude-split-left
make ferris/sweep:docluis:avrdude-split-right
```

### Compile for ProMicro RP2040
```bash
qmk compile -kb ferris/sweep -km docluis -e CONVERT_TO=rp2040_ce
```
And then flash the firmware using the UF2 file generated in the `qmk_firmware` folder.