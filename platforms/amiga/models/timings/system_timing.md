# Amiga Custom Chip Timing Documentation

This document provides comprehensive timing information for all Amiga custom chips based on the hardware documentation.

## Chip Overview

### OCS (Original Chip Set)
- **Agnus**: DMA controller, memory addressing, beam position
- **Denise**: Video output, bitplane serialization, color palette
- **Paula**: Audio, disk, serial, input sampling, interrupts
- **CIA**: System control, timers, I/O ports

### ECS (Enhanced Chip Set)
- **Agnus**: Enhanced with variable beam counters
- **Denise**: Enhanced with additional video features
- **Paula**: Enhanced with additional features
- **CIA**: Same as OCS

### AGA (Advanced Graphics Architecture)
- **Alice**: Enhanced Denise (video output)
- **Ramsey**: Enhanced Agnus (memory control)
- **Gayle**: IDE controller and system control

## Bus Timing

### System Clock
- **NTSC**: 28.63636 MHz (7.15909 MHz / 4 cycles)
- **PAL**: 28.375 MHz (7.09375 MHz / 4 cycles)
- **Pixel Clocks**:
  - LoRes: 7.09/7.16 MHz (14.18/14.32 MHz for HiRes)
  - HiRes: 14.18/14.32 MHz (28.37/28.64 MHz for SHiRes)
  - SHiRes: 28.37/28.64 MHz

### Memory Access Cycles
- **Chip RAM**: 280ns per access (3.57 MHz effective)
- **Cycle allocation**:
  - CPU gets odd cycles when DMA is not active
  - DMA channels get even cycles primarily
  - Refresh cycles steal additional cycles periodically
  - Blitter can steal cycles from CPU when BLTPRI is set

## DMA Timing

### Priority Order
1. Refresh (highest priority)
2. Video DMA
3. Audio DMA
4. Disk DMA
5. Sprite DMA
6. Copper DMA
7. Blitter DMA (when BLTPRI set)
8. CPU (lowest priority when DMA active)

### Audio DMA Timing
- Each audio channel requires 1 DMA cycle per sample period
- Sample rate = Clock Frequency / (2 * Period Register Value)
- NTSC: Rate = 3.579545 MHz / Period
- PAL: Rate = 3.546895 MHz / Period
- Minimum period: 124 (3.547 kHz sample rate)
- Maximum period: 65535 (0.108 Hz sample rate)

### Video DMA Timing
- Bitplane DMA occurs during visible display area
- Each bitplane requires 1 cycle per word per 16 pixels
- More bitplanes = more cycles required per line
- Bitplane cycle requirements:
  - 1 bitplane: 1 cycle per 16 pixels
  - 2 bitplanes: 2 cycles per 16 pixels
  - 3 bitplanes: 3 cycles per 16 pixels
  - 4 bitplanes: 4 cycles per 16 pixels
  - 5 bitplanes: 5 cycles per 16 pixels
  - 6 bitplanes: 6 cycles per 16 pixels
  - 7 bitplanes: 7 cycles per 16 pixels (AGA)
  - 8 bitplanes: 8 cycles per 16 pixels (AGA)

### Sprite DMA Timing
- Sprites get DMA slots during horizontal blank
- Each sprite requires 2 words per line (position + control, data A + B)
- Maximum 8 sprites per line
- Sprite attachment doubles cycle requirement

### Disk DMA Timing
- Requires 1 cycle per word during data transfer
- Sync pattern matching can interrupt transfers
- Typically uses 1-2 cycles per word transferred

## Video Timing

### Standard Modes
- **LoRes**: 320 pixels wide, 140ns per pixel
- **HiRes**: 640 pixels wide, 70ns per pixel
- **SHiRes**: 1280 pixels wide, 35ns per pixel
- **UHRes**: 2560 pixels wide, 17.5ns per pixel (AGA)

### Display Window Timing
- **DIWSTRT**: Display window start (upper left corner)
- **DIWSTOP**: Display window stop (lower right corner)
- **DDFSTRT**: Display data fetch start
- **DDFSTOP**: Display data fetch stop

### Horizontal Timing
- **NTSC**: 227.5 color clocks per line (262/263 lines)
- **PAL**: 228 color clocks per line (312/313 lines)
- **Variable**: Configurable via HTOTAL, HSSTOP, HBSTRT, HBSTOP (ECS)

### Vertical Timing
- **NTSC**: 262/263 lines per frame (59.94 Hz)
- **PAL**: 312/313 lines per frame (49.92 Hz)
- **Variable**: Configurable via VTOTAL, VSSTOP, VBSTRT, VBSTOP (ECS)

## Interrupt Timing

### Interrupt Sources
- **Level 3**: Blitter done, Copper
- **Level 4**: Vertical blank
- **Level 5**: Sprite overflow/duplicate
- **Level 6**: Audio channels, Disk block done
- **Level 7**: External interrupts

### Interrupt Latency
- Typical latency: 2-4 instruction cycles
- Highest priority: Blitter finished
- Level 3: ~2-4 cycles
- Level 6: ~2-4 cycles
- Level 7: ~2-4 cycles

## Copper Timing

### Copper Operation
- Operates on odd cycles only (doesn't conflict with video DMA)
- 2 cycles per instruction (4 memory cycles per instruction)
- Can be synchronized to beam position
- Priority over CPU but below blitter when active

### Copper Instructions
- **MOVE**: Move immediate to destination (2 words)
- **WAIT**: Wait until beam position (2 words)
- **SKIP**: Skip if beam position (2 words)

## Blitter Timing

### Blitter Operation
- Uses odd cycles (doesn't conflict with video DMA)
- Can hog CPU cycles when BLTPRI is set
- 4 cycles per word operation (2 memory cycles per word)
- Pipelined operation for efficiency

### Blitter Speed Calculation
- Minimum time = Setup time + (width * height * cycles_per_word)
- Width in words, height in lines
- Additional overhead for modulo calculations

## CIA Timing

### Timer Operation
- NTSC: ~715.9 kHz timer clock
- PAL: ~709.4 kHz timer clock
- Minimum period: 1 (every clock cycle)
- Maximum: 65535 (once per ~91ms at 709kHz)

### Serial Port Timing
- Data shifts out at rate determined by Timer A when in serial mode
- 8-bit serial mode: 1 start bit, 8 data bits, 1 stop bit
- Serial clock can be derived from Timer A or crystal

## Model-Specific Timing

### A500/A2000 (OCS)
- Standard timing parameters
- 512KB/1MB Chip RAM
- No ECS features

### A600/A1200 (ECS/AGA)
- Variable beam counters available
- Enhanced timing registers
- Up to 8 bitplanes (AGA)

### A3000/A4000 (ECS/AGA)
- Full AGA support
- Variable beam counters
- Enhanced blitter features

## Safe Access Guidelines

### Register Access Timing
- All registers can be read/written at any time
- Some registers have side effects when written
- Reading INTREQR/INTENAR clears interrupt flags
- Reading CLXDAT clears all collision bits

### Potential Side Effects
- Reading INTREQR/INTENAR clears interrupt request/enable flags
- Reading CLXDAT clears all collision detection flags
- Reading DSKBYTR clears disk byte ready flag
- Reading SERDATR clears receive buffer full flag

## Board Model Differences

### A500/A2000
- Standard OCS timing
- Limited to 6 bitplanes
- No AGA features

### A600/A1200
- ECS enhanced features
- Variable beam counters
- IDE interface timing considerations

### A3000/A4000
- AGA features integrated
- Enhanced memory management
- SCSI/IDE timing considerations