# DENISE (Display Encoder) Timing Documentation

Based on Amiga Hardware Reference Manual and official documentation.

## Overview
DENISE is the Amiga video output chip responsible for:
- Color palette management
- Sprite serialization and positioning
- Collision detection
- Video output generation

## Bus Interface Timing

### Address Space
- Base address: $DFF000 (shared with other custom chips)
- Address range: $DFF000 - $DFF1FF (512 bytes)
- Access width: 16-bit word access only
- Timing: Synchronous with system clock (28.37516 MHz PAL / 28.63636 MHz NTSC)

### Access Timing
- CPU access: 2-4 system clock cycles (typically 140-280ns)
- DMA access: Integrated with video DMA from AGNUS
- No wait states required for custom chip access
- All registers are memory-mapped

## Video Output Timing

### Pixel Clock Timing
- **LoRes**: 7.09375 MHz (PAL) / 7.15909 MHz (NTSC) - 140ns per pixel
- **HiRes**: 14.1875 MHz (PAL) / 14.31818 MHz (NTSC) - 70ns per pixel
- **SHiRes**: 28.375 MHz (PAL) / 28.63636 MHz (NTSC) - 35ns per pixel
- **UHRes**: 56.75 MHz (PAL) / 57.27272 MHz (NTSC) - 17.5ns per pixel (AGA)

### Horizontal Timing
- **NTSC**: 227.5 color clocks per line (262/263 lines)
- **PAL**: 228 color clocks per line (312/313 lines)
- **Variable**: Configurable via HTOTAL, HSSTOP, HBSTRT, HBSTOP (ECS)

### Vertical Timing
- **NTSC**: 262/263 lines per frame (59.94 Hz)
- **PAL**: 312/313 lines per frame (49.92 Hz)
- **Variable**: Configurable via VTOTAL, VSSTOP, VBSTRT, VBSTOP (ECS)

## Bitplane Timing

### Bitplane Serialization
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

### Bitplane Data Registers (BPLxDAT)
- Writing to BPL1DAT triggers serialization of all bitplanes
- Data is latched and serialized MSB first (leftmost pixel)
- Each write dumps 16 pixels worth of data to display
- Bitplane data must be ready before serialization trigger

## Sprite Timing

### Sprite DMA Timing
- Sprites get DMA slots during horizontal blanking
- Each sprite requires 2 words per active line (position/control + data A/B)
- Maximum 8 sprites per line
- Sprite attachment doubles cycle requirement

### Sprite Position Timing
- SPRxPOS: Horizontal position (bits 7-0 of low byte)
- SPRxCTL: Vertical position (bits 0,2,6-15 of high byte)
- Sprite activation occurs when beam counter matches position
- Sprite deactivation occurs when beam counter matches stop position

### Sprite Data Timing
- SPRxDATA/SPRxDATB: 16-bit data registers
- Data is serialized when sprite is active
- Each word provides 16 pixels of sprite data
- Sprite priority determined by position in list (0=highest, 7=lowest)

## Color Palette Timing

### Color Register Access
- COLOR00-COLOR31: 12-bit RGB color registers
- Format: TTTT RRRR GGGG BBBB (T=transparency, R=red, G=green, B=blue)
- Colors updated immediately when register is written
- Palette changes take effect on next frame

### Color Output Timing
- Color selection occurs during visible display
- 32 possible colors in palette (expandable with HAM mode)
- Color output synchronized with pixel clock
- RGB values output to external video DAC

## Collision Detection Timing

### Collision Detection
- Real-time collision detection between sprites and bitplanes
- Collision detection occurs during active display
- CLXDAT register contains collision status
- Reading CLXDAT clears all collision flags

### Collision Register Timing
- CLXCON: Configure collision detection (enable/disable bitplanes/sprites)
- CLXDAT: Read collision data and clear flags
- Collision detection is immediate and continuous
- No latency in collision detection

## HAM (Hold And Modify) Mode Timing

### HAM Mode Operation
- Uses bitplane 5 as control signal
- Allows 256 colors from full 4096-color palette
- Color changes occur during visible display
- HAM mode requires special bitplane data formatting

### HAM Timing Requirements
- Bitplane 5 must contain HAM control bits
- Other bitplanes provide color data
- Color changes synchronized with pixel clock
- HAM mode reduces available bitplanes by 1

## Video Priority and Control Timing

### Priority Control (BPLCON2)
- Controls priority between playfields and sprites
- PF2PRI bit gives playfield 2 priority over playfield 1
- Priority bits affect color selection
- Priority changes take effect immediately

### Video Control (BPLCON0)
- HAM bit enables Hold and Modify mode
- DPF bit enables Double Playfield mode
- COLOR bit enables composite color output
- Control changes take effect on next frame

## Safe Access Guidelines

### Register Access Timing
- All registers can be accessed at any time
- Color registers can be changed during active display (flickering may occur)
- Sprite registers should be updated during vertical blank
- Bitplane registers should be configured before display start

### Timing-Sensitive Operations
- Sprite positioning should be coordinated with beam position
- Color palette changes during active display may cause flickering
- Bitplane configuration changes during display may cause visual artifacts
- Best practice: Update video registers during vertical blank

## Board Model Differences

### A500/A2000 (OCS)
- Standard DENISE implementation
- 6 bitplanes maximum
- 32-color palette
- No AGA features

### A600/A1200 (ECS/AGA)
- Enhanced DENISE (Lisa) with AGA features
- Up to 8 bitplanes
- 256-color capability from 4096-color palette
- HAM8 mode support

### A3000/A4000 (ECS/AGA)
- Lisa chip with AGA features
- Full 8-bit color support
- Enhanced collision detection
- Same basic timing characteristics

## Potential Side Effects

### Read Side Effects
- Reading CLXDAT clears all collision detection flags
- No other significant read side effects

### Write Side Effects
- Writing to color registers immediately changes color output
- Writing to sprite registers may affect current display
- Changing BPLCON0 during display affects all subsequent pixels

## DMA Contention Notes

- DENISE does not use dedicated DMA channels
- Video DMA is handled by AGNUS
- DENISE receives data from AGNUS bitplane channels
- No direct conflict with other DMA operations
- CPU access to DENISE registers may be delayed during heavy video DMA