# AGNUS (Address Generator) Timing Documentation

Based on Amiga Hardware Reference Manual and official documentation.

## Overview
AGNUS is the Amiga address generator chip responsible for:
- DMA address generation
- Memory refresh control
- Beam position counting
- Copper operation
- Blitter DMA control

## Bus Interface Timing

### Address Space
- Base address: $DFF000 (shared with other custom chips)
- Address range: $DFF000 - $DFF1FF (512 bytes)
- Access width: 16-bit word access only
- Timing: Synchronous with system clock (28.37516 MHz PAL / 28.63636 MHz NTSC)

### Access Timing
- CPU access: 2-4 system clock cycles (typically 140-280ns)
- DMA access: Dedicated cycles during video blanking periods
- No wait states required for custom chip access
- All registers are memory-mapped

## DMA Control Timing

### DMA Arbitration
- **Refresh**: Highest priority (every 16 scan lines)
- **Video**: High priority (during visible display)
- **Audio**: Medium priority (every sample period)
- **Disk**: Medium priority (during data transfer)
- **Sprite**: Medium priority (during horizontal blank)
- **Copper**: Medium priority (every other cycle)
- **Blitter**: Variable priority (when BLTPRI set)
- **CPU**: Lowest priority (when no DMA active)

### DMA Enable Timing
- DMACON register controls all DMA channels
- SETCLR bit determines set/clear operation
- DMA channels can be enabled/disabled individually
- Master DMA enable (bit 9) controls all channels

## Beam Position Timing

### Vertical Position Counter (VPOSR/VPOSW)
- 9-bit vertical counter (V0-V7 + V8)
- LOF bit indicates long frame (interlace)
- Frame flip flop toggles every frame
- Counter resets at vertical blank start

### Horizontal Position Counter (VHPOSR/VHPOSW)
- 9-bit horizontal counter (H0-H8)
- Combined with vertical counter for beam position
- Counts color clocks (not pixels)
- Counter resets at horizontal blank start

### Beam Counter Access
- Reading VHPOSR/VPOSR provides current beam position
- Writing VHPOSW/VPOSW sets counter values
- Beam position used for Copper synchronization
- Copper WAIT/SKIP instructions compare against beam position

## Video DMA Timing

### Bitplane DMA Timing
- Bitplane DMA occurs during visible display area
- Each bitplane requires 1 cycle per word per 16 pixels
- Bitplane data fetch window defined by DDFSTRT/DDFSTOP
- Display window defined by DIWSTRT/DIWSTOP

### Bitplane Pointer Timing
- BPLxPTH/BPLxPTL: 20-bit bitplane pointers
- Pointers updated during vertical blank
- Modulo registers (BPL1MOD/BPL2MOD) adjust address per line
- Odd/even modulo allows different line lengths per bitplane

### Bitplane Modulo Timing
- BPL1MOD: Modulo for odd bitplanes
- BPL2MOD: Modulo for even bitplanes
- Modulo added to pointer at end of each line
- Allows different bitplane sizes within same display

## Copper Timing

### Copper Operation
- Operates on odd cycles only (doesn't conflict with video DMA)
- 2 cycles per instruction (4 memory cycles per instruction)
- Can be synchronized to beam position
- Priority over CPU but below blitter when active

### Copper Instruction Timing
- **MOVE**: 2 words (destination address + data)
- **WAIT**: 2 words (vertical position + horizontal position)
- **SKIP**: 2 words (vertical position + horizontal position)
- Each instruction requires 2 bus cycles

### Copper Synchronization
- Copper compares beam position against programmed values
- WAIT instruction halts Copper until position match
- SKIP instruction skips next MOVE if position match
- Copper restart at COPJMP1/COPJMP2 locations

## Blitter Timing

### Blitter Operation
- Uses odd cycles (doesn't conflict with video DMA)
- Can hog CPU cycles when BLTPRI is set in DMACON
- 4 cycles per word operation (2 memory cycles per word)
- Pipelined operation for efficiency

### Blitter DMA Requirements
- BLTAPTH/BLTAPTL: Source A pointer
- BLTBPTH/BLTBPTL: Source B pointer
- BLTCPTH/BLTCPTL: Source C pointer
- BLTDPTH/BLTDPTL: Destination D pointer

### Blitter Control Timing
- BLTCON0/BLTCON1: Control registers
- BLTSIZE: Start blitter operation and define size
- Blitter continues until operation complete
- BLTDDAT is dummy address for early read

## Display Window Timing

### Display Window Control
- DIWSTRT: Upper left corner (V7-V0, H7-H0)
- DIWSTOP: Lower right corner (V7-V0, H7-H0)
- Window defines visible display area
- Borders filled with COLOR00 outside window

### Data Fetch Window
- DDFSTRT: Horizontal start of data fetch
- DDFSTOP: Horizontal end of data fetch
- Data fetch occurs during visible display
- Must align with bitplane requirements

## ECS Timing Enhancements

### Variable Beam Counters
- When VARBEAMEN set in BEAMCON0:
  - HTOTAL controls horizontal line length
  - VTOTAL controls vertical line count
  - Allows custom display modes
  - Required for higher resolution modes

### Enhanced Timing Registers
- HTOTAL: Horizontal line count
- VTOTAL: Vertical line count
- HSSTOP: HSYNC stop position
- VSSTOP: VSYNC stop position
- HBSTRT: HBLANK start position
- VBSTRT: VBLANK start position

## Memory Refresh Timing

### DRAM Refresh
- 1 refresh cycle every 16 scan lines
- Refresh steals cycles from normal operation
- Refresh pointer (REFPTR) controls refresh address
- Refresh occurs during horizontal blank periods

### Refresh Cycle Distribution
- 8 refresh cycles per 16-line period
- Distributed across scan lines
- Does not interfere with critical DMA channels
- Automatic in AGNUS, configurable in some systems

## Interrupt Timing

### Raster Interrupt
- Triggered when beam counter matches programmed value
- Programmed via INTREQ/INTENA registers
- Can be used for split-screen effects
- Must account for pipeline delays in copper programs

### Interrupt Latency
- Raster interrupt: ~2-4 cycles
- Copper interrupt: ~2-4 cycles
- Blitter interrupt: ~2-4 cycles
- All interrupts have similar timing characteristics

## Safe Access Guidelines

### Register Access Timing
- All registers can be accessed at any time
- Some registers have immediate effects
- Writing to DMACON with SETCLR affects all DMA channels
- Reading DMACONR provides current DMA status

### Timing-Sensitive Operations
- Bitplane pointers should be updated during vertical blank
- Copper lists should be set up before vertical blank
- Blitter operations should be scheduled to avoid conflicts
- Display window changes during active display may cause artifacts

## Potential Side Effects

### Read Side Effects
- Reading DMACONR provides blitter status bits
- Reading INTREQR/INTENAR clears interrupt request/enable flags
- No other significant read side effects

### Write Side Effects
- Writing to DMACON immediately affects all DMA channels
- Writing to COPJMP1/COPJMP2 immediately restarts Copper
- Writing to BLTSIZE immediately starts blitter operation
- Writing to INTREQ/INTENA immediately affects interrupt state

## Board Model Differences

### A500/A2000 (OCS)
- Standard AGNUS implementation
- 512K/1M Chip RAM support
- No ECS features

### A600/A1200 (ECS)
- ECS AGNUS with variable beam counters
- Enhanced timing registers
- Up to 2M Chip RAM support

### A3000/A4000 (ECS/AGA)
- ECS/AGA AGNUS with enhanced features
- Full AGA support
- Variable beam counters and timing
- Same basic timing characteristics

## UHRES (Ultra High Resolution) Timing

### UHRES Features (ECS/AGA)
- SPRHSTRT/SPRHSTOP: UHRES sprite vertical start/stop
- BPLHSTRT/BPLHSTOP: UHRES bitplane vertical start/stop
- BPLHPTH/BPLHPTL: UHRES bitplane pointer
- SPRHPTH/SPRHPTL: UHRES sprite pointer
- Allows 1280x1024+ resolution modes