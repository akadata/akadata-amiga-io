# RAMSEY Pin Mapping Documentation

Based on RAMSEY specification documents and Amiga Hardware Reference for A4000/A3000 systems.

## RAMSEY (Commodore 8520) Pin Mapping

### Physical Package
- **Package**: 44-pin Plastic Leaded Chip Carrier (PLCC)
- **Chip**: RAMSEY - Memory Control Chip for A4000/A3000
- **Function**: Chip RAM control, refresh, DRAM interface, memory configuration

### Pin Assignments

#### Address Bus (A0-A15) - Pins 1-16
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

#### Data Bus (D0-D15) - Pins 17-32
- **D0 (Pin 17)**: Data bit 0 (bidirectional)
- **D1 (Pin 18)**: Data bit 1 (bidirectional)
- **D2 (Pin 19)**: Data bit 2 (bidirectional)
- **D3 (Pin 20)**: Data bit 3 (bidirectional)
- **D4 (Pin 21)**: Data bit 4 (bidirectional)
- **D5 (Pin 22)**: Data bit 5 (bidirectional)
- **D6 (Pin 23)**: Data bit 6 (bidirectional)
- **D7 (Pin 24)**: Data bit 7 (bidirectional)
- **D8 (Pin 25)**: Data bit 8 (bidirectional)
- **D9 (Pin 26)**: Data bit 9 (bidirectional)
- **D10 (Pin 27)**: Data bit 10 (bidirectional)
- **D11 (Pin 28)**: Data bit 11 (bidirectional)
- **D12 (Pin 29)**: Data bit 12 (bidirectional)
- **D13 (Pin 30)**: Data bit 13 (bidirectional)
- **D14 (Pin 31)**: Data bit 14 (bidirectional)
- **D15 (Pin 32)**: Data bit 15 (bidirectional)

#### Control Signals - Pins 33-40
- **AS* (Pin 33)**: Address Strobe (input, active low)
- **LDS* (Pin 34)**: Lower Data Strobe (input, active low)
- **UDS* (Pin 35)**: Upper Data Strobe (input, active low)
- **R/W* (Pin 36)**: Read/Write control (input, active low)
- **DTACK* (Pin 37)**: Data Acknowledge (bidirectional, active low)
- **BERR* (Pin 38)**: Bus Error (output, active low)
- **BR* (Pin 39)**: Bus Request (output, active low)
- **BGACK* (Pin 40)**: Bus Grant Acknowledge (input, active low)

#### Memory Control Signals - Pins 41-44
- **RAS0* (Pin 41)**: Row Address Strobe 0 (output, active low)
- **RAS1* (Pin 42)**: Row Address Strobe 1 (output, active low)
- **CASL* (Pin 43)**: Column Address Strobe Low (output, active low)
- **CASU* (Pin 44)**: Column Address Strobe Upper (output, active low)

#### Additional Memory Signals - Pins 45-52
- **A0 (Pin 45)**: Memory address bit 0 (output)
- **A1 (Pin 46)**: Memory address bit 1 (output)
- **A2 (Pin 47)**: Memory address bit 2 (output)
- **A3 (Pin 48)**: Memory address bit 3 (output)
- **A4 (Pin 49)**: Memory address bit 4 (output)
- **A5 (Pin 50)**: Memory address bit 5 (output)
- **A6 (Pin 51)**: Memory address bit 6 (output)
- **A7 (Pin 52)**: Memory address bit 7 (output)

#### Memory Address Extension - Pins 53-56
- **A8 (Pin 53)**: Memory address bit 8 (output)
- **A9 (Pin 54)**: Memory address bit 9 (output)
- **A10 (Pin 55)**: Memory address bit 10 (output)
- **A11 (Pin 56)**: Memory address bit 11 (output)

#### Power and Clock - Pins 57-60
- **CLK (Pin 57)**: System clock input (28.37516/28.63636 MHz)
- **VCC (Pin 58)**: Power supply (+5V)
- **GND (Pins 59, 60)**: Ground reference

## RAMSEY Register Mapping to Physical Signals

### RAMSEY Control Register (RAMSEY_CTRL) - Memory Mapped at $DD0000
- **CHIPRST (bit 15)**: Chip reset control (Pin ?)
- **MEMRST (bit 14)**: Memory reset control (Pin ?)
- **CLKRST (bit 13)**: Clock reset control (Pin ?)
- **BUSRST (bit 12)**: Bus reset control (Pin ?)
- **CHIPEN (bit 11)**: Chip enable control
- **MEMEN (bit 10)**: Memory enable control
- **CLKEN (bit 9)**: Clock enable control
- **BUSEN (bit 8)**: Bus enable control
- **CHIPSLP (bit 7)**: Chip sleep control
- **MEMSLP (bit 6)**: Memory sleep control
- **CLKSLP (bit 5)**: Clock sleep control
- **BUSSLP (bit 4)**: Bus sleep control
- **CHIPCFG (bit 3)**: Chip configuration
- **MEMCFG (bit 2)**: Memory configuration
- **CLKCFG (bit 1)**: Clock configuration
- **BUSCFG (bit 0)**: Bus configuration

### RAMSEY Configuration Register (RAMSEY_CONFIG) - Memory Mapped at $DD0004
- **RAMSIZE (bits 15-12)**: RAM size configuration (0=512K, 1=1M, 2=2M, 3=4M, 4=8M)
- **RAMTYPE (bits 11-8)**: RAM type configuration (0=FPM, 1=EDO, 2=SDRAM)
- **CLKTYPE (bits 7-4)**: Clock type configuration (0=28MHz, 1=28.375MHz, 2=28.636MHz)
- **BUSWIDTH (bits 3-0)**: Bus width configuration (0=8bit, 1=16bit, 2=32bit)

### RAMSEY Refresh Control Register (RAMSEY_REFRESH) - Memory Mapped at $DD0006
- **REFCOUNT (bits 15-8)**: Refresh counter value
- **REFEN (bit 7)**: Refresh enable
- **REFMODE (bit 6)**: Refresh mode (0=normal, 1=fast)
- **REFSPEED (bits 5-0)**: Refresh speed configuration

### RAMSEY DRAM Control Register (RAMSEY_DRAM_CTRL) - Memory Mapped at $DD0008
- **CASLAT (bits 15-14)**: CAS latency (0=2, 1=3, 2=4 cycles)
- **RASLAT (bits 13-12)**: RAS latency (0=2, 1=3, 2=4 cycles)
- **PRECHARGE (bit 11)**: Precharge time
- **ACTIVATE (bit 10)**: Activate time
- **WRITE (bit 9)**: Write recovery time
- **REFRESH (bit 8)**: Refresh cycle time
- **BURST (bits 7-6)**: Burst mode (0=1, 1=2, 2=4, 3=8 beats)
- **TYPE (bit 5)**: DRAM type (0=FPM, 1=EDO)
- **WIDTH (bit 4)**: DRAM width (0=8bit, 1=16bit)
- **BANKS (bits 3-2)**: Number of banks (0=2, 1=4, 2=8)
- **PAGESIZE (bits 1-0)**: Page size (0=256, 1=512, 2=1024, 3=2048)

### RAMSEY Chip Select Control Register (RAMSEY_CHIPSEL) - Memory Mapped at $DD000A
- **CS_CHIP0 (bit 15)**: Chip Select 0 Enable
- **CS_CHIP1 (bit 14)**: Chip Select 1 Enable
- **CS_CHIP2 (bit 13)**: Chip Select 2 Enable
- **CS_CHIP3 (bit 12)**: Chip Select 3 Enable
- **CS_FAST0 (bit 11)**: Fast RAM 0 Enable
- **CS_FAST1 (bit 10)**: Fast RAM 1 Enable
- **CS_FAST2 (bit 9)**: Fast RAM 2 Enable
- **CS_FAST3 (bit 8)**: Fast RAM 3 Enable
- **CS_SLOW0 (bit 7)**: Slow RAM 0 Enable
- **CS_SLOW1 (bit 6)**: Slow RAM 1 Enable
- **CS_SLOW2 (bit 5)**: Slow RAM 2 Enable
- **CS_SLOW3 (bit 4)**: Slow RAM 3 Enable
- **CS_ROM0 (bit 3)**: ROM 0 Enable
- **CS_ROM1 (bit 2)**: ROM 1 Enable
- **CS_ROM2 (bit 1)**: ROM 2 Enable
- **CS_ROM3 (bit 0)**: ROM 3 Enable

## PiStorm Interface Considerations

### Bus Interface Signals
- **Address Bus**: A0-A15 connected to CPU address bus
- **Data Bus**: D0-D15 connected to CPU data bus
- **Control Signals**: AS*, LDS*, UDS*, R/W* from CPU
- **Clock**: System clock (28.x MHz) from clock generator
- **DTACK***: Handled via system bus arbitration

### Memory Interface Signals
- **Address Outputs**: A0-A11 for DRAM addressing
- **RAS/CAS**: Row/Column Address Strobes for DRAM
- **Data Strobes**: LDS*/UDS* for memory data strobing
- **Refresh**: Internal refresh counter and timing

### Memory Configuration
- **Chip RAM**: Direct access through RAMSEY
- **Fast RAM**: Through expansion bus
- **Memory Mapping**: Controlled via RAMSEY configuration
- **Timing**: Configurable based on memory type

### DRAM Control
- **CAS Latency**: Configurable for different memory types
- **RAS Timing**: Configurable for different memory types
- **Refresh Rate**: Configurable for different memory types
- **Burst Mode**: Configurable for different memory types

## Board Model Differences

### A3000
- RAMSEY implementation for A3000
- Standard memory configuration
- FPM DRAM support
- Up to 8MB Chip RAM

### A4000
- Enhanced RAMSEY features (AGA)
- EDO/SDRAM support
- Higher memory capacity support
- Better memory timing control
- Up to 8MB Chip RAM standard

## Signal Timing Requirements

### Bus Interface Timing
- **Address Setup**: 100ns before AS*
- **Data Setup**: 50ns before R/W transition
- **Hold Time**: 20ns after control signals
- **Access Time**: 2-4 CPU cycles typical

### Memory Timing
- **RAS Setup**: Address valid before RAS* assertion
- **CAS Setup**: Column address valid before CAS* assertion
- **Data Valid**: After CAS* assertion
- **Refresh**: 1 refresh cycle every 16 scan lines

### DRAM Timing Parameters
- **CAS Latency**: 2, 3, or 4 clock cycles configurable
- **RAS to CAS Delay**: Configurable based on memory type
- **Row Precharge**: Configurable based on memory type
- **Refresh Interval**: Configurable based on memory type

### Control Signal Timing
- **AS*, LDS*, UDS*, R/W***: Must meet 68000 timing specs
- **DTACK***: Response time within bus cycle
- **Memory Access**: Follows DRAM timing specifications
- **Refresh**: Automatic refresh cycles during blanking

## Power Management Features

### Power Control Signals
- **Memory Power**: Individual bank power control
- **Clock Gating**: Clocks can be gated for power savings
- **Sleep Modes**: Various memory sleep states
- **Wake-up Timing**: Memory wake-up delays

### Power State Transitions
- **Sleep Entry**: ~10-20 CPU cycles
- **Sleep Exit**: ~20-50 CPU cycles (memory warm-up)
- **Power Sequencing**: Proper power-up sequence required
- **Clock Stabilization**: Clocks need stabilization time

## Memory Bandwidth Considerations

### Chip RAM Access
- **Access Time**: 140ns (7MHz), 70ns (14MHz), 35ns (28MHz)
- **Cycle Time**: 280ns (7MHz), 140ns (14MHz), 70ns (28MHz)
- **Page Mode**: Faster access within same row
- **RAS/CAS Timing**: Configurable based on memory type

### Fast RAM Access
- **Access Time**: Variable based on memory type
- **Timing**: Controlled by memory controller
- **Priority**: Below chip RAM
- **Burst Mode**: Available on some configurations

### Memory Arbitration
- **Custom Chips**: Highest priority for video/audio
- **CPU Access**: Lowest priority when DMA active
- **Refresh**: Automatic cycles steal from all accessors
- **Bandwidth**: Shared between all accessors