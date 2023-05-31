```
qmk setup
qmk new-keymap -kb ferris/sweep
qmk compile -kb ferris/sweep -km default
qmk flash [FIRMWARE_FILE]

cd ~/qmk_firmware
make ferris/sweep:default:avrdude-split-left
```
