```bash
qmk setup
qmk new-keymap -kb ferris/sweep

# qmk compile -kb ferris/sweep -km default
# qmk flash [FIRMWARE_FILE]

# you can set the "master" side in config.h with #define MASTER_RIGHT or #define MASTER_LEFT

cd ~/qmk_firmware
make ferris/sweep:docluis:avrdude-split-left
make ferris/sweep:docluis:avrdude-split-right
```
