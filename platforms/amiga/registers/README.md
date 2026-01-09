# Amiga Custom Chip Register Documentation

This directory contains comprehensive register definitions and documentation for Amiga custom chips, designed for use with the PISTORM project to interface Raspberry Pi with Amiga hardware.

## Overview

The Amiga custom chip set consists of several key chips that provide the distinctive features of Amiga computers:

- **Agnus/Alice**: Address generation, DMA control, beam position
- **Denise/Lisa**: Video output, color palette, sprite serialization
- **Paula**: Audio, disk, serial, input sampling, interrupts
- **CIA**: System control, timers, I/O ports
- **Blitter**: High-speed block transfer and graphics operations

## File Structure

```
registers/
├── amiga_custom_chips.h     # Main header including all custom chips
├── amiga_memory_map.h       # Memory map and register definitions
├── amiga_model_identification.h # Model-specific identification and capabilities
├── agnus.h                  # AGNUS chip register definitions
├── denise.h                 # DENISE chip register definitions
├── paula.h                  # PAULA chip register definitions
├── cia.h                    # CIA chip register definitions
├── blitter.h                # Blitter chip register definitions
├── registers.csv            # Complete register reference in CSV format
└── ...
```

## Key Features

### Register Definitions
- Complete address mappings for all custom chips
- Proper include guards to prevent conflicts
- Bit field definitions for control registers
- Model-specific register availability

### Memory Map Coverage
- Chip RAM regions (512KB, 1MB, 2MB, 8MB configurations)
- Fast RAM regions (Zorro II/III)
- IO expansion regions
- Custom chip register space (0xDFF000-0xDFFFFF)
- CIA register space (0xBFE000-0xBFDFFF)

### Model Support
- A500 (OCS): Original Chip Set
- A500+ (ECS): Enhanced Chip Set
- A600 (ECS): Enhanced Chip Set
- A1200 (AGA): Advanced Graphics Architecture
- A2000 (OCS/ECS): Original/Enhanced Chip Set
- A3000 (ECS): Enhanced Chip Set
- A4000 (AGA): Advanced Graphics Architecture

### Chip Set Classifications
- **OCS (Original Chip Set)**: A500, early A2000
- **ECS (Enhanced Chip Set)**: A500+, A600, late A2000, A3000
- **AGA (Advanced Graphics Architecture)**: A1200, A4000, CD32

## Usage

Include the main header in your PISTORM project:
```c
#include "platforms/amiga/registers/amiga_custom_chips.h"
```

Or include specific chip headers as needed:
```c
#include "platforms/amiga/registers/agnus.h"
#include "platforms/amiga/registers/denise.h"
#include "platforms/amiga/registers/paula.h"
#include "platforms/amiga/registers/cia.h"
```

## Register Access Patterns

All registers follow the standard Amiga custom chip addressing scheme:
- Base address: 0xDFF000
- Even addresses: 16-bit word access
- Some registers have special strobe behavior (COPJMP1, COPJMP2, etc.)

## Compatibility Notes

- Headers are compatible with both Musl Libc and standard libc
- All register definitions include proper model support information
- Bit field definitions are consistent across all headers
- Safe access guidelines are documented in timing files

## Documentation References

- Amiga Hardware Reference Manual (ADCD 2.1)
- Official Amiga chipset specification documents
- Technical reference manuals for each Amiga model