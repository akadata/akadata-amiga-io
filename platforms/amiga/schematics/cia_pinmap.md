# CIA (Complex Interface Adapter) Pin Mapping Documentation

Based on CIA specification documents and Amiga Hardware Reference.

## CIAA (MOS 8520) Pin Mapping

### Physical Package
- **Package**: 48-pin Plastic Leaded Chip Carrier (PLLL)
- **Chip**: MOS 8520 (Complex Interface Adapter)
- **Function**: System control, keyboard, gameports

### Pin Assignments

#### Data Bus (D0-D7) - Pins 1-8, 41-48
- **D0 (Pin 1)**: Data bus bit 0 (bidirectional)
- **D1 (Pin 2)**: Data bus bit 1 (bidirectional)
- **D2 (Pin 3)**: Data bus bit 2 (bidirectional)
- **D3 (Pin 4)**: Data bus bit 3 (bidirectional)
- **D4 (Pin 5)**: Data bus bit 4 (bidirectional)
- **D5 (Pin 6)**: Data bus bit 5 (bidirectional)
- **D6 (Pin 7)**: Data bus bit 6 (bidirectional)
- **D7 (Pin 8)**: Data bus bit 7 (bidirectional)
- **D8 (Pin 41)**: Data bus bit 8 (bidirectional)
- **D9 (Pin 42)**: Data bus bit 9 (bidirectional)
- **D10 (Pin 43)**: Data bus bit 10 (bidirectional)
- **D11 (Pin 44)**: Data bus bit 11 (bidirectional)
- **D12 (Pin 45)**: Data bus bit 12 (bidirectional)
- **D13 (Pin 46)**: Data bus bit 13 (bidirectional)
- **D14 (Pin 47)**: Data bus bit 14 (bidirectional)
- **D15 (Pin 48)**: Data bus bit 15 (bidirectional)

#### Address Bus (A0-A3) - Pins 10-13
- **A0 (Pin 10)**: Address bit 0 (input to CIAA)
- **A1 (Pin 11)**: Address bit 1 (input to CIAA)
- **A2 (Pin 12)**: Address bit 2 (input to CIAA)
- **A3 (Pin 13)**: Address bit 3 (input to CIAA)

#### Control Signals - Pins 14-20
- **CS (Pin 14)**: Chip Select (input, active low)
- **R/W* (Pin 15)**: Read/Write control (input, active low)
- **FLAG (Pin 16)**: Flag input (input) - external interrupt source
- **SP (Pin 17)**: Serial Port (bidirectional) - serial data I/O
- **CNT (Pin 18)**: Counter input (input) - external timer input
- **TODIN (Pin 19)**: Time Of Day input (input) - 50/60Hz clock
- **TODOUT (Pin 20)**: Time Of Day output (output) - alarm output

#### Port A (PA0-PA7) - Pins 21-28
- **PA0 (Pin 21)**: Port A bit 0 (bidirectional)
  - A500: OVERLAY* (memory overlay control)
  - A600/A1200: System control
- **PA1 (Pin 22)**: Port A bit 1 (bidirectional)
  - A500: LED control (0=bright, 1=dim)
  - A600/A1200: System control
- **PA2 (Pin 23)**: Port A bit 2 (bidirectional)
  - A500: DSKCHANGE* (disk change)
  - A600/A1200: System control
- **PA3 (Pin 24)**: Port A bit 3 (bidirectional)
  - A500: DSKPROT* (disk write protect)
  - A600/A1200: System control
- **PA4 (Pin 25)**: Port A bit 4 (bidirectional)
  - A500: DSKTRACK0* (track 0 sensor)
  - A600/A1200: System control
- **PA5 (Pin 26)**: Port A bit 5 (bidirectional)
  - A500: DSKRDY* (disk ready)
  - A600/A1200: System control
- **PA6 (Pin 27)**: Port A bit 6 (bidirectional)
  - A500: GAMEPORT0 (fire button)
  - A600/A1200: System control
- **PA7 (Pin 28)**: Port A bit 7 (bidirectional)
  - A500: GAMEPORT1 (fire button)
  - A600/A1200: System control

#### Port B (PB0-PB7) - Pins 29-36
- **PB0 (Pin 29)**: Port B bit 0 (bidirectional) - Keyboard column 0
- **PB1 (Pin 30)**: Port B bit 1 (bidirectional) - Keyboard column 1
- **PB2 (Pin 31)**: Port B bit 2 (bidirectional) - Keyboard column 2
- **PB3 (Pin 32)**: Port B bit 3 (bidirectional) - Keyboard column 3
- **PB4 (Pin 33)**: Port B bit 4 (bidirectional) - Keyboard column 4
- **PB5 (Pin 34)**: Port B bit 5 (bidirectional) - Keyboard column 5
- **PB6 (Pin 35)**: Port B bit 6 (bidirectional) - Keyboard column 6
- **PB7 (Pin 36)**: Port B bit 7 (bidirectional) - Keyboard column 7

#### Timer Control - Pins 37-38
- **PC6 (Pin 37)**: Port C bit 6 (output) - Timer A output (when PBON set)
- **PC7 (Pin 38)**: Port C bit 7 (output) - Timer B output (when PBON set)

#### Power and Clock - Pins 39-40
- **VCC (Pin 39)**: Power supply (+5V)
- **GND (Pin 40)**: Ground reference

## CIAB (MOS 8520) Pin Mapping

### Physical Package
- **Package**: 48-pin Plastic Leaded Chip Carrier (PLLL)
- **Chip**: MOS 8520 (Complex Interface Adapter)
- **Function**: Serial/printer, disk control

### Pin Assignments

#### Data Bus (D0-D7) - Pins 1-8, 41-48
- **D0-D15**: Same as CIAA (shared data bus)

#### Address Bus (A0-A3) - Pins 10-13
- **A0-A3**: Same as CIAA (shared address bus)

#### Control Signals - Pins 14-20
- **CS (Pin 14)**: Chip Select (input, active low)
- **R/W* (Pin 15)**: Read/Write control (input, active low)
- **FLAG (Pin 16)**: Flag input (input) - external interrupt source
- **SP (Pin 17)**: Serial Port (bidirectional) - serial data I/O
- **CNT (Pin 18)**: Counter input (input) - external timer input
- **TODIN (Pin 19)**: Time Of Day input (input) - 50/60Hz clock
- **TODOUT (Pin 20)**: Time Of Day output (output) - alarm output

#### Port A (PA0-PA7) - Pins 21-28
- **PA0 (Pin 21)**: Port A bit 0 (bidirectional) - PRTRBUSY
- **PA1 (Pin 22)**: Port A bit 1 (bidirectional) - PRTRPOUT
- **PA2 (Pin 23)**: Port A bit 2 (bidirectional) - PRTRSEL
- **PA3 (Pin 24)**: Port A bit 3 (bidirectional) - COMDSR
- **PA4 (Pin 25)**: Port A bit 4 (bidirectional) - COMCTS
- **PA5 (Pin 26)**: Port A bit 5 (bidirectional) - COMCD
- **PA6 (Pin 27)**: Port A bit 6 (bidirectional) - COMRTS
- **PA7 (Pin 28)**: Port A bit 7 (bidirectional) - COMDTR

#### Port B (PB0-PB7) - Pins 29-36
- **PB0 (Pin 29)**: Port B bit 0 (bidirectional) - DSKSTEP
- **PB1 (Pin 30)**: Port B bit 1 (bidirectional) - DSKDIREC
- **PB2 (Pin 31)**: Port B bit 2 (bidirectional) - DSKSIDE
- **PB3 (Pin 32)**: Port B bit 3 (bidirectional) - DSKSEL0
- **PB4 (Pin 33)**: Port B bit 4 (bidirectional) - DSKSEL1
- **PB5 (Pin 34)**: Port B bit 5 (bidirectional) - DSKSEL2
- **PB6 (Pin 35)**: Port B bit 6 (bidirectional) - DSKSEL3
- **PB7 (Pin 36)**: Port B bit 7 (bidirectional) - DSKMOTOR

#### Timer Control - Pins 37-38
- **PC6 (Pin 37)**: Port C bit 6 (output) - Timer A output (when PBON set)
- **PC7 (Pin 38)**: Port C bit 7 (output) - Timer B output (when PBON set)

#### Power and Clock - Pins 39-40
- **VCC (Pin 39)**: Power supply (+5V)
- **GND (Pin 40)**: Ground reference

## PiStorm Interface Considerations

### Bus Interface Signals
- **DTACK***: Data Transfer Acknowledge (handled by custom chip complex)
- **AS***: Address Strobe (from CPU)
- **UDS*/LDS***: Upper/Lower Data Strobe (for byte/word access)
- **R/W***: Read/Write control (from CPU)
- **IPL0/IPL1/IPL2**: Interrupt Priority Lines (to CPU)

### Clocking
- **Phi2**: System clock (~7MHz effective)
- **CNT**: External counter input (for timers)
- **TODIN**: Time of day clock (50/60Hz)

### Interrupt Handling
- **IPL lines**: Connected to CPU interrupt inputs
- **INTREQ**: Interrupt request output
- **Multiple interrupt sources**: Timers, serial, flag, etc.

## Board Model Differences

### A500/A2000
- Standard CIAA/CIAB configuration
- Keyboard matrix connected to CIAAPRB
- Game port connections to CIAAPRA
- Disk control via CIABPB

### A600/A1200
- Similar CIA configuration but with IDE interface
- CIAB port B may have additional IDE control signals
- Same basic pinout and functionality

### A3000/A4000
- SCSI interface may share some CIA signals
- Enhanced IDE interface on CIAB
- Same core CIA functionality preserved

## Signal Timing Requirements

### Address Setup/Hold Times
- Address must be stable before AS* assertion
- Hold time required after AS* deassertion
- Data setup/hold times per 68000 specifications

### Control Signal Timing
- AS*, R/W* must meet 68000 timing specs
- DMA arbitration follows standard protocols
- Interrupt timing compatible with 68000 interrupt handling

### Clock Domain Crossing
- All internal operations synchronized to system clock
- No special clock domain crossing required
- Compatible with 7MHz CPU clock domain