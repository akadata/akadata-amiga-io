# akadata-amiga-io

Pi-side tools for direct control of classic Amiga custom chips over PiStorm GPIO.

This repo is a slimmed down, Pi-native toolkit: no 68k emulator, no RTG, no PiSCSI. It focuses on GPIO protocol + custom chip register access, plus small utilities for audio and register poking.

## Layout

- `gpio/` — PiStorm GPIO protocol + peripheral mapping.
- `platforms/amiga/registers/` — custom chip register headers, regtool, pimodplay.
- `build_regtool.sh` — builds regtool.
- `build_pimodplay.sh` — builds pimodplay.

## Build (on Pi)

```sh
./build_regtool.sh
./build_pimodplay.sh
```

## regtool

See `platforms/amiga/registers/REGTOOL.md` for full usage.

Quick examples:

```sh
sudo ./regtool --read16 0xDFF004
sudo ./regtool --disk-led on
```

## pimodplay

See `platforms/amiga/registers/README.md` for full usage.

Streaming raw audio:

```sh
sudo ./pimodplay --raw sample.raw --rate 11025 --stream --chunk-bytes 65536 --buffers 3
```

Stereo stream:

```sh
sudo ./pimodplay --raw stereo.raw --rate 11025 --stream --stereo --s8 --buffers 3
```

## Notes

- Requires root for `/dev/mem` access.
- Designed for Raspberry Pi Zero 2 W and Pi 4 class boards.
- Audio output is Paula DMA (AUD0/AUD1).


## CPLD + clock tools

- `cpld/clkpeek.c` — GPIO clock inspection tool.
- `cpld/rtl/` — CPLD RTL sources.
- `cpld/nprog*` — CPLD programming scripts.

## Hardware docs

The full ADCD mirror and curated references are stored under `Hardware/`.
