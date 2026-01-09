# DENISE (Display Encoder) Pin Mapping Documentation

Based on DENISE specification documents and Amiga Hardware Reference.

## DENISE (MOS 8361/8373) Pin Mapping

### Physical Package
- **Package**: 84-pin Plastic Leaded Chip Carrier (PLCC)
- **Chip**: MOS 8361 (OCS) / MOS 8373 (ECS/AGA) - DENISE/LISA
- **Function**: Video output, color palette, sprite serialization, collision detection

### Pin Assignments

#### Address Bus (A0-A17) - Pins 1-18
- **A0 (Pin 1)**: Address bit 0 (input)
- **A1 (Pin 2)**: Address bit 1 (input)
- **A2 (Pin 3)**: Address bit 2 (input)
- **A3 (Pin 4)**: Address bit 3 (input)
- **A4 (Pin 5)**: Address bit 4 (input)
- **A5 (Pin 6)**: Address bit 5 (input)
- **A6 (Pin 7)**: Address bit 6 (input)
- **A7 (Pin 8)**: Address bit 7 (input)
- **A8 (Pin 9)**: Address bit 8 (input)
- **A9 (Pin 10)**: Address bit 9 (input)
- **A10 (Pin 11)**: Address bit 10 (input)
- **A11 (Pin 12)**: Address bit 11 (input)
- **A12 (Pin 13)**: Address bit 12 (input)
- **A13 (Pin 14)**: Address bit 13 (input)
- **A14 (Pin 15)**: Address bit 14 (input)
- **A15 (Pin 16)**: Address bit 15 (input)
- **A16 (Pin 17)**: Address bit 16 (input)
- **A17 (Pin 18)**: Address bit 17 (input)

#### Data Bus (D0-D15) - Pins 67-74, 76-83
- **D0 (Pin 67)**: Data bit 0 (bidirectional)
- **D1 (Pin 68)**: Data bit 1 (bidirectional)
- **D2 (Pin 69)**: Data bit 2 (bidirectional)
- **D3 (Pin 70)**: Data bit 3 (bidirectional)
- **D4 (Pin 71)**: Data bit 4 (bidirectional)
- **D5 (Pin 72)**: Data bit 5 (bidirectional)
- **D6 (Pin 73)**: Data bit 6 (bidirectional)
- **D7 (Pin 74)**: Data bit 7 (bidirectional)
- **D8 (Pin 76)**: Data bit 8 (bidirectional)
- **D9 (Pin 77)**: Data bit 9 (bidirectional)
- **D10 (Pin 78)**: Data bit 10 (bidirectional)
- **D11 (Pin 79)**: Data bit 11 (bidirectional)
- **D12 (Pin 80)**: Data bit 12 (bidirectional)
- **D13 (Pin 81)**: Data bit 13 (bidirectional)
- **D14 (Pin 82)**: Data bit 14 (bidirectional)
- **D15 (Pin 83)**: Data bit 15 (bidirectional)

#### Control Signals - Pins 19-26
- **CLK (Pin 19)**: System clock input (28.37516/28.63636 MHz)
- **AS* (Pin 20)**: Address Strobe (input, active low)
- **LDS* (Pin 21)**: Lower Data Strobe (input, active low)
- **UDS* (Pin 22)**: Upper Data Strobe (input, active low)
- **R/W* (Pin 23)**: Read/Write control (input, active low)
- **DMAOUT (Pin 24)**: DMA request output (output)
- **BGEN (Pin 25)**: Bus grant enable (output)
- **E (Pin 26)**: E clock (dot clock enable) (input)

#### Video Output Signals - Pins 30-47
- **R0 (Pin 30)**: Red bit 0 (output)
- **R1 (Pin 31)**: Red bit 1 (output)
- **R2 (Pin 32)**: Red bit 2 (output)
- **R3 (Pin 33)**: Red bit 3 (output)
- **G0 (Pin 34)**: Green bit 0 (output)
- **G1 (Pin 35)**: Green bit 1 (output)
- **G2 (Pin 36)**: Green bit 2 (output)
- **G3 (Pin 37)**: Green bit 3 (output)
- **B0 (Pin 38)**: Blue bit 0 (output)
- **B1 (Pin 39)**: Blue bit 1 (output)
- **B2 (Pin 40)**: Blue bit 2 (output)
- **B3 (Pin 41)**: Blue bit 3 (output)
- **HSYNC* (Pin 42)**: Horizontal sync (output, active low)
- **VSYNC* (Pin 43)**: Vertical sync (output, active low)
- **CSYNC* (Pin 44)**: Composite sync (output, active low)
- **BLC (Pin 45)**: Blank control (output)
- **HCS (Pin 46)**: Horizontal color sync (output)
- **VCS (Pin 47)**: Vertical color sync (output)

#### Sprite Data Inputs - Pins 48-63
- **SPR0A0 (Pin 48)**: Sprite 0 data A bit 0 (input)
- **SPR0A1 (Pin 49)**: Sprite 0 data A bit 1 (input)
- **SPR0B0 (Pin 50)**: Sprite 0 data B bit 0 (input)
- **SPR0B1 (Pin 51)**: Sprite 0 data B bit 1 (input)
- **SPR1A0 (Pin 52)**: Sprite 1 data A bit 0 (input)
- **SPR1A1 (Pin 53)**: Sprite 1 data A bit 1 (input)
- **SPR1B0 (Pin 54)**: Sprite 1 data B bit 0 (input)
- **SPR1B1 (Pin 55)**: Sprite 1 data B bit 1 (input)
- **SPR2A0 (Pin 56)**: Sprite 2 data A bit 0 (input)
- **SPR2A1 (Pin 57)**: Sprite 2 data A bit 1 (input)
- **SPR2B0 (Pin 58)**: Sprite 2 data B bit 0 (input)
- **SPR2B1 (Pin 59)**: Sprite 2 data B bit 1 (input)
- **SPR3A0 (Pin 60)**: Sprite 3 data A bit 0 (input)
- **SPR3A1 (Pin 61)**: Sprite 3 data A bit 1 (input)
- **SPR3B0 (Pin 62)**: Sprite 3 data B bit 0 (input)
- **SPR3B1 (Pin 63)**: Sprite 3 data B bit 1 (input)

#### Additional Sprite Data - Pins 64-75
- **SPR4A0 (Pin 64)**: Sprite 4 data A bit 0 (input)
- **SPR4A1 (Pin 65)**: Sprite 4 data A bit 1 (input)
- **SPR4B0 (Pin 66)**: Sprite 4 data B bit 0 (input)
- **SPR4B1 (Pin 67)**: Sprite 4 data B bit 1 (input)
- **SPR5A0 (Pin 68)**: Sprite 5 data A bit 0 (input)
- **SPR5A1 (Pin 69)**: Sprite 5 data A bit 1 (input)
- **SPR5B0 (Pin 70)**: Sprite 5 data B bit 0 (input)
- **SPR5B1 (Pin 71)**: Sprite 5 data B bit 1 (input)
- **SPR6A0 (Pin 72)**: Sprite 6 data A bit 0 (input)
- **SPR6A1 (Pin 73)**: Sprite 6 data A bit 1 (input)
- **SPR6B0 (Pin 74)**: Sprite 6 data B bit 0 (input)
- **SPR6B1 (Pin 75)**: Sprite 6 data B bit 1 (input)

#### More Sprite Data - Pins 76-83
- **SPR7A0 (Pin 76)**: Sprite 7 data A bit 0 (input)
- **SPR7A1 (Pin 77)**: Sprite 7 data A bit 1 (input)
- **SPR7B0 (Pin 78)**: Sprite 7 data B bit 0 (input)
- **SPR7B1 (Pin 79)**: Sprite 7 data B bit 1 (input)
- **ZD (Pin 80)**: Zero detect (output) - transparency control
- **BORDER (Pin 81)**: Border control (output)
- **BPL0 (Pin 82)**: Bitplane 0 serial data (input)
- **BPL1 (Pin 83)**: Bitplane 1 serial data (input)

#### Additional Bitplane Data - Pins 1-8 (second set)
- **BPL2 (Pin 1)**: Bitplane 2 serial data (input)
- **BPL3 (Pin 2)**: Bitplane 3 serial data (input)
- **BPL4 (Pin 3)**: Bitplane 4 serial data (input)
- **BPL5 (Pin 4)**: Bitplane 5 serial data (input)
- **BPL6 (Pin 5)**: Bitplane 6 serial data (input) - AGA only
- **BPL7 (Pin 6)**: Bitplane 7 serial data (input) - AGA only
- **BPL8 (Pin 7)**: Bitplane 8 serial data (input) - AGA only
- **BPL9 (Pin 8)**: Bitplane 9 serial data (input) - AGA only

#### Power and Ground - Pins 14, 40, 50, 60, 70, 84
- **VCC (Pins 14, 84)**: Power supply (+5V)
- **GND (Pins 13, 40, 50, 60, 70)**: Ground reference

#### System Control - Pins 27-29
- **BURST (Pin 27)**: Color burst enable (output)
- **LOF (Pin 28)**: Long field/frame (input/output)
- **FMODE (Pin 29)**: Fetch mode (input) - AGA only

## DENISE Register Mapping to Physical Signals

### Bitplane Data Registers (BPLxDAT) - Pins 82-83, 1-6
- **BPL1DAT**: Bitplane 1 serial data input (Pin 83)
- **BPL2DAT**: Bitplane 2 serial data input (Pin 1)
- **BPL3DAT**: Bitplane 3 serial data input (Pin 2)
- **BPL4DAT**: Bitplane 4 serial data input (Pin 3)
- **BPL5DAT**: Bitplane 5 serial data input (Pin 4)
- **BPL6DAT**: Bitplane 6 serial data input (Pin 5) - AGA
- **BPL7DAT**: Bitplane 7 serial data input (Pin 6) - AGA
- **BPL8DAT**: Bitplane 8 serial data input (Pin 7) - AGA

### Sprite Data Registers - Pins 48-79
- **SPRxDATA/SPRxDATB**: Sprite data A/B inputs from AGNUS
- **Physical**: Pins 48-79 carry serialized sprite data from AGNUS
- **Format**: Each sprite has 2 data streams (A and B) with 2 bits each

### Color Palette Registers - Memory Mapped
- **COLOR00-COLOR31**: Memory-mapped registers at $DFF180-$DFF1BE
- **Physical**: No direct pins, uses data bus for access
- **Function**: Sets RGB color values for palette

### Video Control Registers
- **BPLCON0**: Bitplane control 0 (miscellaneous)
- **BPLCON1**: Bitplane control 1 (horizontal scroll)
- **BPLCON2**: Bitplane control 2 (priority control)
- **BPLCON3**: Bitplane control 3 (ECS features)
- **BPLCON4**: Bitplane control 4 (AGA features)

### Display Window Registers
- **DIWSTRT**: Display window start
- **DIWSTOP**: Display window stop
- **DDFSTRT**: Display data fetch start
- **DDFSTOP**: Display data fetch stop

### Collision Detection Registers
- **CLXCON**: Collision control register
- **CLXDAT**: Collision data register
- **Physical**: Uses bitplane and sprite inputs for collision detection

## PiStorm Interface Considerations

### Bus Interface Signals
- **Address Bus**: A0-A17 connected to CPU address bus
- **Data Bus**: D0-D15 connected to CPU data bus
- **Control Signals**: AS*, LDS*, UDS*, R/W* from CPU
- **Clock**: System clock (28.x MHz) from clock generator
- **DTACK***: Handled internally by custom chip complex

### Video Output Interface
- **RGB Outputs**: 4-bit per channel (12-bit total) color output
- **Sync Signals**: HSYNC*, VSYNC*, CSYNC* for display timing
- **Blank Control**: BLC for blanking control
- **Transparency**: ZD for transparency detection

### Bitplane Input Interface
- **Serial Data**: BPL0-BPL9 receive serialized bitplane data from AGNUS
- **Timing**: Synchronized with dot clock and horizontal timing
- **Format**: MSB first, left-to-right pixel order
- **Width**: Up to 8 bitplanes for AGA systems

### Sprite Input Interface
- **Sprite Data**: 16 input signals (A/B × 2 bits × 8 sprites)
- **Serialization**: From parallel AGNUS registers to serial DENISE inputs
- **Timing**: Synchronized with sprite position compare
- **Priority**: Controlled by BPLCON2 priority bits

### Color Palette Interface
- **Palette Size**: 32 entries (expandable with HAM)
- **Format**: 4-bit per channel RGB (12-bit total)
- **HAM Mode**: Hold-and-Modify for extended colors
- **Access**: Memory-mapped registers via CPU bus

## Board Model Differences

### A500/A2000 (OCS)
- Standard DENISE implementation (MOS 8361)
- 6 bitplanes maximum
- 32-color palette
- No AGA features

### A600/A1200 (ECS/AGA)
- Enhanced DENISE (Lisa) with AGA features
- Up to 8 bitplanes
- 256-color capability from 4096-color palette
- HAM8 mode support
- BPLCON3 and BPLCON4 registers

### A3000/A4000 (ECS/AGA)
- Lisa chip with AGA features
- Full 8-bit color support
- Enhanced collision detection
- Same basic pinout but with AGA capabilities

## Signal Timing Requirements

### Address Setup/Hold Times
- Address must be stable before AS* assertion
- Hold time required after AS* deassertion
- Data setup/hold times per 68000 specifications

### Video Output Timing
- **RGB Stability**: Stable during active video period
- **Sync Timing**: Precise timing relative to beam position
- **Color Clock**: Synchronized with system clock
- **Pixel Timing**: Dependent on display mode (LoRes/HiRes/SHiRes)

### Bitplane Input Timing
- **Serial Data**: Synchronized with dot clock
- **Data Valid**: Must be valid when consumed
- **Shift Rate**: Matches pixel clock rate
- **MSB First**: Most significant bit first in serial stream

### Sprite Input Timing
- **Data Latching**: When sprite position matches beam
- **Serialization**: From parallel AGNUS registers
- **Priority Resolution**: Based on BPLCON2 settings
- **Collision Detection**: Real-time with minimal latency

### Color Palette Access
- **Register Access**: Standard 68000 timing
- **Palette Updates**: Immediate effect on next pixels
- **HAM Mode**: Special handling for hold-and-modify
- **Transparency**: ZD output based on color 0 detection