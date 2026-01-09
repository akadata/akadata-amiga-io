# ZORRO II/III Pin Mapping Documentation

Based on ZORRO specification documents and Amiga Hardware Reference for expansion bus.

## ZORRO II/III Expansion Bus Pin Mapping

### Physical Package and Connectors
- **ZORRO II**: 100-pin expansion connector (16-bit data bus)
- **ZORRO III**: 100-pin expansion connector (32-bit data bus with 16-bit compatibility)
- **Function**: Expansion bus interface for Amiga systems

### ZORRO II Pin Assignments (100-pin connector)

#### Address Bus (A1-A19) - Pins 1-19
- **A1 (Pin 1)**: Address bit 1 (output from CPU)
- **A2 (Pin 2)**: Address bit 2 (output from CPU)
- **A3 (Pin 3)**: Address bit 3 (output from CPU)
- **A4 (Pin 4)**: Address bit 4 (output from CPU)
- **A5 (Pin 5)**: Address bit 5 (output from CPU)
- **A6 (Pin 6)**: Address bit 6 (output from CPU)
- **A7 (Pin 7)**: Address bit 7 (output from CPU)
- **A8 (Pin 8)**: Address bit 8 (output from CPU)
- **A9 (Pin 9)**: Address bit 9 (output from CPU)
- **A10 (Pin 10)**: Address bit 10 (output from CPU)
- **A11 (Pin 11)**: Address bit 11 (output from CPU)
- **A12 (Pin 12)**: Address bit 12 (output from CPU)
- **A13 (Pin 13)**: Address bit 13 (output from CPU)
- **A14 (Pin 14)**: Address bit 14 (output from CPU)
- **A15 (Pin 15)**: Address bit 15 (output from CPU)
- **A16 (Pin 16)**: Address bit 16 (output from CPU)
- **A17 (Pin 17)**: Address bit 17 (output from CPU)
- **A18 (Pin 18)**: Address bit 18 (output from CPU)
- **A19 (Pin 19)**: Address bit 19 (output from CPU)

#### Data Bus (D0-D15) - Pins 20-35
- **D0 (Pin 20)**: Data bit 0 (bidirectional)
- **D1 (Pin 21)**: Data bit 1 (bidirectional)
- **D2 (Pin 22)**: Data bit 2 (bidirectional)
- **D3 (Pin 23)**: Data bit 3 (bidirectional)
- **D4 (Pin 24)**: Data bit 4 (bidirectional)
- **D5 (Pin 25)**: Data bit 5 (bidirectional)
- **D6 (Pin 26)**: Data bit 6 (bidirectional)
- **D7 (Pin 27)**: Data bit 7 (bidirectional)
- **D8 (Pin 28)**: Data bit 8 (bidirectional)
- **D9 (Pin 29)**: Data bit 9 (bidirectional)
- **D10 (Pin 30)**: Data bit 10 (bidirectional)
- **D11 (Pin 31)**: Data bit 11 (bidirectional)
- **D12 (Pin 32)**: Data bit 12 (bidirectional)
- **D13 (Pin 33)**: Data bit 13 (bidirectional)
- **D14 (Pin 34)**: Data bit 14 (bidirectional)
- **D15 (Pin 35)**: Data bit 15 (bidirectional)

#### Control Signals - Pins 36-50
- **AS* (Pin 36)**: Address Strobe (output from CPU, active low)
- **LDS* (Pin 37)**: Lower Data Strobe (output from CPU, active low)
- **UDS* (Pin 38)**: Upper Data Strobe (output from CPU, active low)
- **R/W* (Pin 39)**: Read/Write control (output from CPU, active low)
- **DTACK* (Pin 40)**: Data Acknowledge (bidirectional, active low)
- **BERR* (Pin 41)**: Bus Error (bidirectional, active low)
- **BR* (Pin 42)**: Bus Request (bidirectional, active low)
- **BGACK* (Pin 43)**: Bus Grant Acknowledge (bidirectional, active low)
- **RESET* (Pin 44)**: System Reset (output from CPU, active low)
- **INT2* (Pin 45)**: Interrupt Level 2 (bidirectional, active low)
- **INT6* (Pin 46)**: Interrupt Level 6 (bidirectional, active low)
- **INT7* (Pin 47)**: Interrupt Level 7 (bidirectional, active low)
- **AUTOS* (Pin 48)**: AutoConfig strobe (bidirectional, active low)
- **IPL0 (Pin 49)**: Interrupt Priority Level 0 (bidirectional)
- **IPL1 (Pin 50)**: Interrupt Priority Level 1 (bidirectional)

#### Power and Ground - Pins 51-60
- **GND (Pins 51, 53, 55, 57, 59)**: Ground reference
- **VCC (Pins 52, 54, 56, 58, 60)**: Power supply (+5V)

#### Additional Signals - Pins 61-70
- **IPL2 (Pin 61)**: Interrupt Priority Level 2 (bidirectional)
- **IPL3 (Pin 62)**: Interrupt Priority Level 3 (bidirectional)
- **IPL4 (Pin 63)**: Interrupt Priority Level 4 (bidirectional)
- **IPL5 (Pin 64)**: Interrupt Priority Level 5 (bidirectional)
- **IPL6 (Pin 65)**: Interrupt Priority Level 6 (bidirectional)
- **IPL7 (Pin 66)**: Interrupt Priority Level 7 (bidirectional)
- **CLK (Pin 67)**: System clock (output from CPU, ~7MHz)
- **E (Pin 68)**: E clock (output from CPU, dot clock enable)
- **VPA* (Pin 69)**: Vector Pull Acknowledge (output from CPU, active low)
- **VMA* (Pin 70)**: Vector Memory Acknowledge (output from CPU, active low)

#### ZORRO III Additional Signals - Pins 71-100
- **A20 (Pin 71)**: Address bit 20 (output from CPU)
- **A21 (Pin 72)**: Address bit 21 (output from CPU)
- **A22 (Pin 73)**: Address bit 22 (output from CPU)
- **A23 (Pin 74)**: Address bit 23 (output from CPU)
- **A24 (Pin 75)**: Address bit 24 (output from CPU)
- **A25 (Pin 76)**: Address bit 25 (output from CPU)
- **A26 (Pin 77)**: Address bit 26 (output from CPU)
- **A27 (Pin 78)**: Address bit 27 (output from CPU)
- **A28 (Pin 79)**: Address bit 28 (output from CPU)
- **A29 (Pin 80)**: Address bit 29 (output from CPU)
- **A30 (Pin 81)**: Address bit 30 (output from CPU)
- **A31 (Pin 82)**: Address bit 31 (output from CPU)
- **D16 (Pin 83)**: Data bit 16 (bidirectional)
- **D17 (Pin 84)**: Data bit 17 (bidirectional)
- **D18 (Pin 85)**: Data bit 18 (bidirectional)
- **D19 (Pin 86)**: Data bit 19 (bidirectional)
- **D20 (Pin 87)**: Data bit 20 (bidirectional)
- **D21 (Pin 88)**: Data bit 21 (bidirectional)
- **D22 (Pin 89)**: Data bit 22 (bidirectional)
- **D23 (Pin 90)**: Data bit 23 (bidirectional)
- **D24 (Pin 91)**: Data bit 24 (bidirectional)
- **D25 (Pin 92)**: Data bit 25 (bidirectional)
- **D26 (Pin 93)**: Data bit 26 (bidirectional)
- **D27 (Pin 94)**: Data bit 27 (bidirectional)
- **D28 (Pin 95)**: Data bit 28 (bidirectional)
- **D29 (Pin 96)**: Data bit 29 (bidirectional)
- **D30 (Pin 97)**: Data bit 30 (bidirectional)
- **D31 (Pin 98)**: Data bit 31 (bidirectional)
- **BGL* (Pin 99)**: Bus Grant Lock (bidirectional, active low)
- **ZORROIII* (Pin 100)**: ZORRO III indicator (output from system, active low)

## AutoConfig Register Mapping

### AutoConfig ID Register (Offset 0x00)
- **MANUFACTURER (bits 15-8)**: Manufacturer ID (Commodore = 0x0200)
- **PRODUCT (bits 7-0)**: Product ID (specific to card type)

### AutoConfig Control/Status Register (Offset 0x02)
- **INITIALIZATION (bit 15)**: Initialization bit
- **CONFIGURED (bit 14)**: Configured bit
- **ENABLED (bit 13)**: Enabled bit
- **TYPE (bit 12)**: Type bit (0=ZORRO II, 1=ZORRO III)
- **SIZE (bits 11-8)**: Size field (memory size in 64KB chunks)
- **FLAGS (bits 7-0)**: Feature flags

### AutoConfig ROM Vector (Offset 0x04)
- **ROMVEC (bits 15-0)**: Expansion ROM vector address

### AutoConfig Size Register (Offset 0x06)
- **MEMSIZE (bits 15-8)**: Memory size (in 64KB chunks)
- **IOSIZE (bits 7-0)**: I/O size (in 64KB chunks)

### AutoConfig Memory Start/End Registers (Offsets 0x08-0x0A)
- **MEMSTART (bits 15-0)**: Memory start address (high 16 bits)
- **MEMEND (bits 15-0)**: Memory end address (high 16 bits)

### AutoConfig Expansion ROM Register (Offset 0x0C)
- **EXPROM (bits 15-0)**: Expansion ROM address

### AutoConfig Control Register (Offset 0x0E)
- **CONTROL (bits 15-0)**: Card control register

## PiStorm Interface Considerations

### Bus Interface Signals
- **Address Bus**: A1-A31 connected to expansion bus address lines
- **Data Bus**: D0-D31 connected to expansion bus data lines
- **Control Signals**: AS*, LDS*, UDS*, R/W* from CPU
- **Clock**: System clock (7MHz) from CPU
- **DTACK***: Handled via expansion bus arbitration

### AutoConfig Protocol
- **Initialization**: Cards respond to AutoConfig protocol during boot
- **ID Registration**: Cards register their ID and capabilities
- **Memory Mapping**: Cards request memory space allocation
- **Configuration**: Cards configure their memory and I/O space

### Expansion Card Types
- **Memory Cards**: RAM expansion cards
- **I/O Cards**: Serial, parallel, SCSI, IDE controllers
- **Graphics Cards**: Accelerator cards
- **Audio Cards**: Sound enhancement cards
- **Network Cards**: Ethernet controllers

### Interrupt Handling
- **INT2***: Level 2 interrupt line
- **INT6***: Level 6 interrupt line
- **INT7***: Level 7 interrupt line
- **IPL Lines**: Interrupt priority level lines
- **Shared Interrupts**: Multiple cards may share interrupt lines

## Board Model Differences

### A500/A2000 (ZORRO II)
- Standard ZORRO II implementation
- 16-bit expansion bus
- Up to 8MB expansion RAM
- Limited by physical space

### A3000 (ZORRO II/III)
- ZORRO II slot for compatibility
- ZORRO III slot for newer cards
- Enhanced memory management
- Better expansion support

### A4000 (ZORRO III)
- Full ZORRO III implementation
- 32-bit expansion bus
- Up to 1GB expansion RAM per card
- Multiple expansion slots

## Signal Timing Requirements

### Address Setup/Hold Times
- **Address Setup**: 100ns before AS* assertion
- **Address Hold**: 20ns after AS* deassertion
- **Data Setup**: 50ns before R/W transition
- **Data Hold**: 20ns after control signals

### Control Signal Timing
- **AS*, LDS*, UDS*, R/W***: Must meet 68000 timing specs
- **DTACK***: Response time within bus cycle
- **Interrupts**: Level-sensitive, must be acknowledged
- **Bus Request**: Follows standard 68000 arbitration

### AutoConfig Timing
- **Address Decode**: Cards must decode addresses during AutoConfig
- **Response Time**: Cards must respond to AutoConfig within specified time
- **Initialization**: Cards must initialize properly during boot
- **Configuration**: Cards must configure memory mapping correctly

### DMA Timing
- **Bus Request**: Cards request bus via BR*
- **Bus Grant**: CPU grants bus via BGACK*
- **Cycle Stealing**: Expansion DMA can steal cycles from CPU
- **Burst Mode**: Some cards support burst transfers

## Power Management Features

### Power Control Signals
- **VCC**: +5V power supply (typically 1-2A per card)
- **Ground**: Multiple ground connections for noise reduction
- **Reset**: System reset signal to expansion cards
- **Sleep Modes**: Some cards support power management

### Power State Transitions
- **Power-On**: Cards initialize during system power-on
- **Reset**: Cards reset when RESET* is asserted
- **Sleep**: Some cards support low-power modes
- **Wake-Up**: Cards must wake up properly from sleep

## Memory Mapping Considerations

### Address Space Allocation
- **ZORRO II**: $200000 - $9FFFFF (up to 8MB per card)
- **ZORRO III**: $200000 - $9FFFFF (up to 1GB per card)
- **Chip RAM**: Highest priority, fastest access
- **Expansion RAM**: Configurable priority and access

### Memory Configuration
- **Size Detection**: Cards report memory size via AutoConfig
- **Banking**: Memory can be banked for larger configurations
- **Wait States**: Slower cards may need wait states
- **Timing**: Memory access timing varies by card type

### DMA Arbitration
- **CPU Access**: Highest priority when no DMA active
- **Custom Chip DMA**: High priority for video/audio
- **Expansion DMA**: Medium priority
- **Bus Sharing**: All DMA shares system bus