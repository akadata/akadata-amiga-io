# AGNUS (Address Generator) Pin Mapping Documentation

Based on AGNUS specification documents and Amiga Hardware Reference.

## AGNUS (MOS 8367/8370/8371/8372/8374/8375) Pin Mapping

### Physical Package
- **Package**: 84-pin Plastic Leaded Chip Carrier (PLCC)
- **Chip**: MOS 8367/8370/8371/8372/8374/8375 - AGNUS/ALICE
- **Function**: Address generation, DMA control, beam position, memory refresh

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

#### Memory Address Outputs - Pins 27-46
- **MA0 (Pin 27)**: Memory address bit 0 (output)
- **MA1 (Pin 28)**: Memory address bit 1 (output)
- **MA2 (Pin 29)**: Memory address bit 2 (output)
- **MA3 (Pin 30)**: Memory address bit 3 (output)
- **MA4 (Pin 31)**: Memory address bit 4 (output)
- **MA5 (Pin 32)**: Memory address bit 5 (output)
- **MA6 (Pin 33)**: Memory address bit 6 (output)
- **MA7 (Pin 34)**: Memory address bit 7 (output)
- **MA8 (Pin 35)**: Memory address bit 8 (output)
- **MA9 (Pin 36)**: Memory address bit 9 (output)
- **MA10 (Pin 37)**: Memory address bit 10 (output)
- **MA11 (Pin 38)**: Memory address bit 11 (output)
- **MA12 (Pin 39)**: Memory address bit 12 (output)
- **MA13 (Pin 40)**: Memory address bit 13 (output)
- **MA14 (Pin 41)**: Memory address bit 14 (output)
- **MA15 (Pin 42)**: Memory address bit 15 (output)
- **MA16 (Pin 43)**: Memory address bit 16 (output)
- **MA17 (Pin 44)**: Memory address bit 17 (output)
- **MA18 (Pin 45)**: Memory address bit 18 (output)
- **MA19 (Pin 46)**: Memory address bit 19 (output)

#### Memory Control Signals - Pins 47-56
- **RAS0* (Pin 47)**: Row Address Strobe 0 (output, active low)
- **RAS1* (Pin 48)**: Row Address Strobe 1 (output, active low)
- **CASL* (Pin 49)**: Column Address Strobe Low (output, active low)
- **CASU* (Pin 50)**: Column Address Strobe Upper (output, active low)
- **LDS* (Pin 51)**: Lower Data Strobe (output, active low)
- **UDS* (Pin 52)**: Upper Data Strobe (output, active low)
- **A0 (Pin 53)**: Address bit 0 (output to memory)
- **A1 (Pin 54)**: Address bit 1 (output to memory)
- **A2 (Pin 55)**: Address bit 2 (output to memory)
- **A3 (Pin 56)**: Address bit 3 (output to memory)

#### Register Address Outputs (RGA) - Pins 57-65
- **RGA0 (Pin 57)**: Register address bit 0 (output)
- **RGA1 (Pin 58)**: Register address bit 1 (output)
- **RGA2 (Pin 59)**: Register address bit 2 (output)
- **RGA3 (Pin 60)**: Register address bit 3 (output)
- **RGA4 (Pin 61)**: Register address bit 4 (output)
- **RGA5 (Pin 62)**: Register address bit 5 (output)
- **RGA6 (Pin 63)**: Register address bit 6 (output)
- **RGA7 (Pin 64)**: Register address bit 7 (output)
- **RGA8 (Pin 65)**: Register address bit 8 (output)

#### Sync and Timing Outputs - Pins 66-75
- **HSY* (Pin 66)**: Horizontal Sync (bidirectional, active low)
- **VSY* (Pin 67)**: Vertical Sync (bidirectional, active low)
- **CSY* (Pin 68)**: Composite Sync (output, active low)
- **LP* (Pin 69)**: Light Pen strobe (output, active low)
- **RST* (Pin 70)**: Reset (input, active low)
- **INT3* (Pin 71)**: Interrupt level 3 (output, active low)
- **DMAL (Pin 72)**: DMA request (input)
- **BLS* (Pin 73)**: Blitter strobe (input, active low)
- **DBR* (Pin 74)**: Data Bus Request (output, active low)
- **RRW (Pin 75)**: Refresh Read/Write (output)

#### Additional Control - Pins 76-84
- **PRW (Pin 76)**: Processor Read/Write (input)
- **RGEN* (Pin 77)**: Register Enable (input, active low)
- **RAMEN* (Pin 78)**: RAM Enable (input, active low)
- **14M (Pin 79)**: 14MHz clock output (output)
- **CCK (Pin 80)**: Color clock output (output)
- **CCKQ (Pin 81)**: Color clock quadrature (output)
- **7MHZ (Pin 82)**: 7MHz clock output (output)
- **CDAC* (Pin 83)**: Color DAC clock (output)
- **NOOP (Pin 84)**: No operation (output, Copper NOP)

#### Power and Ground - Pins 15, 40, 50, 60, 70, 84
- **VCC (Pins 15, 84)**: Power supply (+5V)
- **GND (Pins 14, 40, 50, 60, 70)**: Ground reference

## AGNUS Register Mapping to Physical Signals

### DMA Control Registers - Pins 24, 74
- **DMACONR**: DMA Control Read (Pin 24 - DMAOUT, Pin 74 - DBR*)
- **DMACON**: DMA Control Write (Pin 72 - DMAL, Pin 73 - BLS*)

### Beam Position Registers - Pins 20, 26, 69
- **VPOSR**: Vertical Position Read (Pin 28 - LOF bit)
- **VHPOSR**: Vertical/Horizontal Position Read (Pin 26 - E clock)
- **VPOSW**: Vertical Position Write (Pin 70 - RST*)
- **VHPOSW**: Vertical/Horizontal Position Write (Pin 26 - E clock)

### Display Window Registers - Pins 66-68
- **DIWSTRT**: Display Window Start (Pin 66 - HSY*, Pin 67 - VSY*)
- **DIWSTOP**: Display Window Stop (Pin 66 - HSY*, Pin 67 - VSY*)
- **DDFSTRT**: Display Data Fetch Start (Pin 66 - HSY*)
- **DDFSTOP**: Display Data Fetch Stop (Pin 66 - HSY*)

### Copper Registers - Pins 65, 66, 68
- **COPCON**: Copper Control (Pin 68 - CSY*)
- **COPxLCH/COPxLCL**: Copper List Pointers (Pin 65 - RGA8)
- **COPJMPx**: Copper Jump Registers (Pin 66 - HSY*)

### Bitplane Pointer Registers - Pins 27-46
- **BPLxPTH/BPLxPTL**: Bitplane Pointers (Pins 27-46 - MA0-MA19)
- **BPLxMOD**: Bitplane Modulo (Pins 27-46 - MA0-MA19)

### Sprite Pointer Registers - Pins 27-46
- **SPRxPTH/SPRxPTL**: Sprite Pointers (Pins 27-46 - MA0-MA19)

### Blitter Registers - Pins 27-46, 74
- **BLTxPTH/BLTxPTL**: Blitter Pointers (Pins 27-46 - MA0-MA19)
- **BLTSIZE**: Blitter Size (Pin 74 - DBR*)
- **BLTCON0/BLTCON1**: Blitter Control (Pin 74 - DBR*)

### ECS Timing Registers - Pins 66-68
- **HTOTAL**: Horizontal Total (Pin 66 - HSY*)
- **VTOTAL**: Vertical Total (Pin 67 - VSY*)
- **HSSTOP**: Horizontal Sync Stop (Pin 66 - HSY*)
- **VSSTOP**: Vertical Sync Stop (Pin 67 - VSY*)
- **HBSTRT**: Horizontal Blank Start (Pin 66 - HSY*)
- **HBSTOP**: Horizontal Blank Stop (Pin 66 - HSY*)
- **VBSTRT**: Vertical Blank Start (Pin 67 - VSY*)
- **VBSTOP**: Vertical Blank Stop (Pin 67 - VSY*)
- **BEAMCON0**: Beam Counter Control (Pin 68 - CSY*)

## PiStorm Interface Considerations

### Bus Interface Signals
- **Address Bus**: A0-A17 connected to CPU address bus
- **Data Bus**: D0-D15 connected to CPU data bus
- **Control Signals**: AS*, LDS*, UDS*, R/W* from CPU
- **Clock**: System clock (28.x MHz) from clock generator
- **DTACK***: Handled internally by custom chip complex

### Memory Interface Signals
- **Address Outputs**: MA0-MA19 for DRAM addressing
- **RAS/CAS**: Row/Column Address Strobes for DRAM
- **Data Strobes**: LDS*/UDS* for memory data strobing
- **Refresh**: Internal refresh counter and timing

### DMA Arbitration
- **Processor Access**: CPU gets odd cycles when DMA not active
- **Video DMA**: Even cycles during visible display
- **Audio DMA**: Dedicated cycles per channel
- **Disk DMA**: Dedicated cycles during data transfer
- **Sprite DMA**: During horizontal blank
- **Copper DMA**: Every other cycle during active period
- **Blitter DMA**: Variable, can hog CPU when BLTPRI set

### Sync Generation
- **HSY***: Horizontal sync output/input
- **VSY***: Vertical sync output/input
- **CSY***: Composite sync output
- **Timing**: Based on system clock and programmed values

### Interrupt Control
- **INT3***: Level 3 interrupt output (blitter, copper)
- **DMAL**: DMA request input
- **BLS***: Blitter strobe input
- **Priority**: Level 3 for blitter/copper, others via PAULA

## Board Model Differences

### A500/A2000 (OCS)
- Standard AGNUS implementation (MOS 8367)
- 512KB/1MB Chip RAM support
- No ECS features
- RAS0*/RAS1* for 512KB/1MB addressing

### A600/A1200 (ECS)
- ECS AGNUS with variable beam counters
- Enhanced timing registers
- Up to 2MB Chip RAM support
- Additional ECS control registers

### A3000/A4000 (ECS/AGA)
- ECS/AGA AGNUS with enhanced features
- Full AGA support
- Variable beam counters and timing
- Enhanced memory management

## Signal Timing Requirements

### Address Setup/Hold Times
- Address must be stable before AS* assertion
- Hold time required after AS* deassertion
- Data setup/hold times per 68000 specifications

### Memory Timing
- **RAS Setup**: Address valid before RAS* assertion
- **CAS Setup**: Column address valid before CAS* assertion
- **Data Valid**: After CAS* assertion
- **Refresh**: 1 refresh cycle every 16 scan lines

### DMA Timing
- **Odd/Even Cycles**: DMA on even, CPU on odd (when active)
- **Refresh Cycles**: Steal cycles from all operations
- **Blitter Priority**: Can hog CPU cycles when BLTPRI set
- **Video Priority**: High priority during visible display

### Sync Timing
- **HSY***: Horizontal sync timing (15.625kHz PAL, 15.734kHz NTSC)
- **VSY***: Vertical sync timing (50Hz PAL, 59.94Hz NTSC)
- **CSY***: Composite sync generation
- **Sync Generation**: From programmed timing values

### Clock Generation
- **System Clock**: 28.37516 MHz (PAL) / 28.63636 MHz (NTSC)
- **14M Output**: 14.18758 MHz (PAL) / 14.31818 MHz (NTSC)
- **CCK Output**: 3.546895 MHz (PAL) / 3.579545 MHz (NTSC)
- **7MHZ Output**: 7.09379 MHz (PAL) / 7.15909 MHz (NTSC)