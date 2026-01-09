# Amiga Custom Chip Timing Specifications

Technical timing specifications for Amiga custom chips based on official documentation.

## Clock Domains

### System Clocks
- Master clock: 28.37516 MHz (PAL), 28.63636 MHz (NTSC)
- Color clock (CCK): Master clock / 8 = 3.546895 MHz (PAL), 3.579545 MHz (NTSC)
- Pixel clock (lores): Master clock / 4 = 7.09379 MHz (PAL), 7.15909 MHz (NTSC)
- Bus cycle: Master clock / 2 = 14.18758 MHz (PAL), 14.31818 MHz (NTSC)

### Timing Relationships
```
Master Clock (28.x MHz) → ÷2 → Bus Cycle (14.x MHz) → ÷2 → Memory Cycle (7.x MHz)
                                    ↓
                              ÷4 → Color Clock (3.5 MHz)
                                    ↓
                              ÷2 → Pixel Clock (7.x MHz)
```

## Memory Access Timing

### Chip RAM Access Patterns
- CPU gets odd cycles when DMA is not active
- DMA channels get even cycles primarily
- Refresh cycles steal additional cycles periodically
- Blitter can steal cycles from CPU (BLTPRI)

### Cycle Allocation Table
| Component | Cycles per Line | Notes |
|-----------|----------------|-------|
| CPU (odd) | Variable | When no DMA active |
| Bitplane DMA | Variable | Depends on # of planes |
| Audio DMA | 1 per sample | Per channel |
| Disk DMA | Variable | During data transfer |
| Sprite DMA | 1-2 per sprite | During active display |
| Copper DMA | Variable | During active display |
| Blitter DMA | Variable | When active |

## Video Timing Registers

### Horizontal Timing (ECS registers)
- HTOTAL: Total color clocks per line (0-255)
- HSSTRT: HSYNC start position
- HSSTOP: HSYNC stop position  
- HBSTRT: HBLANK start position
- HBSTOP: HBLANK stop position
- HCENTER: Horizontal center for VSYNC on interlace

### Vertical Timing (ECS registers)
- VTOTAL: Total lines per field (0-2047)
- VSSTRT: VSYNC start line
- VSSTOP: VSYNC stop line
- VBSTRT: VBLANK start line
- VBSTOP: VBLANK stop line

### Display Window Timing
- DIWSTRT: Display window start (V7-V0, H7-H0)
- DIWSTOP: Display window stop (V7-V0, H7-H0)
- DDFSTRT: Data fetch start (horizontal position)
- DDFSTOP: Data fetch stop (horizontal position)

## Bitplane DMA Timing

### Fetch Slots per Line
- Each line has 227.5 (NTSC) or 228 (PAL) memory cycles
- Bitplane DMA occurs during visible display area
- Each bitplane requires 1 cycle per word per 16 pixels
- More bitplanes = more cycles required per line

### Bitplane Cycle Requirements
| Bitplanes | Cycles per 16 pixels | Max width |
|-----------|---------------------|-----------|
| 1 | 1 | 3640 pixels |
| 2 | 2 | 1820 pixels |
| 3 | 3 | 1213 pixels |
| 4 | 4 | 910 pixels |
| 5 | 5 | 728 pixels |
| 6 | 6 | 606 pixels |
| 7 | 7 | 520 pixels |
| 8 | 8 | 455 pixels |

## Audio DMA Timing

### Period Register Values
- Minimum: 124 (3.547 kHz sample rate)
- Maximum: 65535 (0.108 Hz sample rate)
- Formula: Sample Rate = Clock Frequency / (2 * Period)
- NTSC: Rate = 3.579545 MHz / Period
- PAL: Rate = 3.546895 MHz / Period

### Audio Channel DMA Requirements
- Each sample requires 1 DMA cycle
- Stereo requires 2 channels
- Higher sample rates require more DMA bandwidth

## Sprite DMA Timing

### Sprite Slot Allocation
- Sprites get DMA slots during horizontal blank
- Each sprite requires 2 words per line (position + control, data A + B)
- Maximum 8 sprites per line
- Sprite data fetched during HBLANK

### Sprite Cycle Requirements
- 2 cycles per sprite per active line
- Additional cycles for data fetch during HBLANK
- Sprite attachment doubles cycle requirement

## Blitter Timing

### Blitter Cycle Usage
- Uses odd cycles (doesn't conflict with video DMA)
- Can hog CPU cycles when BLTPRI is set
- 4 cycles per word operation (2 memory cycles per word)
- Pipelined operation for efficiency

### Blitter Speed Calculation
- Minimum time = Setup time + (width * height * cycles_per_word)
- Width in words, height in lines
- Additional overhead for modulo calculations

## Copper Timing

### Copper Instruction Timing
- 2 bus cycles per instruction (4 memory cycles)
- Only operates on odd cycles
- Can be synchronized to beam position
- Priority over CPU but below blitter when active

### Copper Comparison Timing
- Horizontal comparisons: 0-11 bits (0-2047)
- Vertical comparisons: 0-9 bits (0-511) or 0-10 bits (0-1023) with ECS
- Can trigger on specific beam positions

## Interrupt Timing

### Interrupt Latency
- Level 3 (VBLANK, COPPER, BLIT): ~2-4 cycles
- Level 6 (AUDIO, DISK, RASTER): ~2-4 cycles
- Level 7 (PORTS): ~2-4 cycles
- Level 8+ (EXTERNAL): ~2-4 cycles

### Raster Interrupt Timing
- Triggered when beam counter matches programmed value
- Can be used for split-screen effects
- Must account for pipeline delays in copper programs

## ECS Specific Timings

### Variable Beam Counters
- When VARBEAMEN is set, HTOTAL and VTOTAL control beam counting
- Allows for custom display modes
- Required for higher resolution modes

### Dual-Playfield Timing
- Two playfields can be displayed simultaneously
- Requires additional DMA cycles
- Bitplane pairs used for each playfield

## AGA Specific Timings

### Enhanced Features
- Up to 8 bitplanes supported
- 256 colors from 4096-color palette
- Super Hires mode (1280x400/512)
- Enhanced collision detection

### UHRES Timing
- Ultra High Resolution modes
- Requires additional memory bandwidth
- Special pointer chains for data fetch

## Memory Refresh Timing

### DRAM Refresh
- 1 refresh cycle every 16 scan lines
- Steals cycles from normal operation
- Automatic in AGNUS, configurable in some systems

## Power-on Reset Timing

### Initialization Sequence
1. Reset all registers to default values
2. Initialize beam counters
3. Configure default display mode
4. Enable default DMA channels
5. Initialize interrupt system

## Model-Specific Timing Variations

### A500/A2000 (OCS)
- Fixed timing registers
- Maximum 6 bitplanes
- 320x200 or 640x200 standard modes

### A600/A1200 (ECS/AGA)
- Variable timing registers
- Up to 8 bitplanes (AGA)
- Enhanced resolution modes
- Improved memory management

### A3000/A4000 (ECS/AGA)
- Full AGA support
- Variable beam counters
- Enhanced blitter features
- Improved interrupt handling

## Bus Arbitration Timing

### Priority Levels
1. Refresh (highest)
2. Video DMA
3. Audio DMA
4. Disk DMA
5. Sprite DMA
6. Copper DMA
7. Blitter DMA (when BLTPRI set)
8. CPU (lowest, when no DMA active)

This timing information is essential for developing accurate Amiga emulation and hardware interfaces like PISTORM.