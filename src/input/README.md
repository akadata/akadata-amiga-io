# Amiga Input Device Drivers for PISTORM

This directory contains input drivers that interface with Amiga hardware via the PISTORM board, allowing Linux to receive input from Amiga keyboards, mice, and lightpens.

## Components

### Keyboard Driver (`keyboard.c`)
- Interfaces with the Amiga CIA keyboard matrix
- Scans the 6x9 keyboard matrix to detect key presses
- Translates Amiga scancodes to Linux input events
- Supports all standard Amiga keys including modifiers

### Mouse Driver (`mouse.c`)
- Reads mouse position from CIA registers
- Decodes quadrature mouse signals
- Reports relative movement and button states
- Supports both mouse buttons

### Lightpen Driver (`lightpen.c`)
- Reads lightpen position from beam position registers
- Detects lightpen presence via POTGOR register
- Reports absolute position and pressure
- Supports lightpen button

### Input Manager (`input_manager.c`)
- Coordinates all input devices
- Provides main polling loop
- Creates Linux uinput devices
- Handles graceful startup/shutdown

## Building

```bash
cd src/input
make
```

For debugging build:
```bash
make debug
```

## Running

```bash
# Normal operation
sudo ./amiga_input_manager

# Test mode (initialize and exit)
./amiga_input_manager --test
```

## Requirements

- PISTORM board connected to Raspberry Pi
- Properly configured PISTORM device driver
- Access to Amiga custom chip registers via PISTORM
- Linux with uinput support (standard in most distributions)

## Architecture

The input drivers work by:

1. Reading Amiga CIA registers to detect input events
2. Converting Amiga-specific input to Linux input events
3. Creating virtual input devices using Linux uinput subsystem
4. Providing a bridge between Amiga hardware and Linux input system

## Register Mapping

The drivers access the following Amiga registers:

- **Keyboard**: CIAA Port A/B (0xBFE001, 0xBFE101) for matrix scanning
- **Mouse**: CIAA Port A/B (0xBFE001, 0xBFE101) for counter values
- **Lightpen**: AGNUS beam position registers (VHPOSR, VPOSR) and POTGOR

## Compatibility

- Works with Musl Libc and standard libc implementations
- Compatible with OCS, ECS, and AGA Amiga systems
- Supports A500, A600, A1200, A2000, A3000, A4000 models
- Linux-compatible via uinput subsystem

## License

MIT License - see LICENSE file for details.