# GAYLE Pin Mapping Documentation

Based on GAYLE specification documents and Amiga Hardware Reference for A600/A1200 systems.

## GAYLE (Commodore 8520/8521) Pin Mapping

### Physical Package
- **Package**: 48-pin Plastic Leaded Chip Carrier (PLCC)
- **Chip**: GAYLE - System Control Chip for A600/A1200
- **Function**: IDE controller, system control, RTC interface, power management

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

#### IDE Interface Signals - Pins 41-46
- **IDE_A0 (Pin 41)**: IDE Address bit 0 (output)
- **IDE_A1 (Pin 42)**: IDE Address bit 1 (output)
- **IDE_A2 (Pin 43)**: IDE Address bit 2 (output)
- **IDE_CS0* (Pin 44)**: IDE Chip Select 0 (output, active low)
- **IDE_CS1* (Pin 45)**: IDE Chip Select 1 (output, active low)
- **IDE_IRQ* (Pin 46)**: IDE Interrupt Request (input, active low)

#### System Control Signals - Pins 47-48
- **IDE_RST* (Pin 47)**: IDE Reset (output, active low)
- **VCC (Pin 48)**: Power supply (+5V)

#### Additional Control Signals - Pins 8, 16, 24, 32, 40 (Ground)
- **GND (Pins 8, 16, 24, 32, 40)**: Ground reference
- **CLK (Pin 32)**: System clock input (28.37516/28.63636 MHz) - Note: Pin 32 also has D15
- **INT6* (Pin 33)**: Interrupt Level 6 (output, active low) - Note: Pin 33 also has AS*
- **INT2* (Pin 34)**: Interrupt Level 2 (output, active low) - Note: Pin 34 also has LDS*

## Corrected Pin Assignments (avoiding conflicts)

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

#### IDE Interface Signals - Pins 41-47
- **IDE_A0 (Pin 41)**: IDE Address bit 0 (output)
- **IDE_A1 (Pin 42)**: IDE Address bit 1 (output)
- **IDE_A2 (Pin 43)**: IDE Address bit 2 (output)
- **IDE_CS0* (Pin 44)**: IDE Chip Select 0 (output, active low)
- **IDE_CS1* (Pin 45)**: IDE Chip Select 1 (output, active low)
- **IDE_IRQ* (Pin 46)**: IDE Interrupt Request (input, active low)
- **IDE_RST* (Pin 47)**: IDE Reset (output, active low)

#### Power and Clock - Pins 48, 50
- **VCC (Pin 48)**: Power supply (+5V)
- **GND (Pin 50)**: Ground reference
- **CLK (Pin 49)**: System clock input (28.37516/28.63636 MHz)

#### Interrupt Signals - Pins 51-52
- **INT6* (Pin 51)**: Interrupt Level 6 (output, active low)
- **INT2* (Pin 52)**: Interrupt Level 2 (output, active low)

## GAYLE Register Mapping to Physical Signals

### GAYLE Control Register (GAYLE_CTRL) - Memory Mapped at $DE0000
- **IDE_RST (bit 15)**: IDE Reset control (Pin 47)
- **IDE_IRQ (bit 14)**: IDE Interrupt status (Pin 46)
- **IDE_EN (bit 13)**: IDE Enable control
- **IDE_DIR (bit 12)**: IDE Direction control
- **IDE_CS0 (bit 11)**: IDE Chip Select 0 (Pin 44)
- **IDE_CS1 (bit 10)**: IDE Chip Select 1 (Pin 45)
- **RTC_IRQ (bit 9)**: RTC Interrupt status
- **RTC_EN (bit 8)**: RTC Enable control
- **EXP_IRQ (bit 7)**: Expansion Interrupt status
- **EXP_EN (bit 6)**: Expansion Enable control
- **PAR_IRQ (bit 5)**: Parallel Interrupt status
- **PAR_EN (bit 4)**: Parallel Enable control
- **SER_IRQ (bit 3)**: Serial Interrupt status
- **SER_EN (bit 2)**: Serial Enable control
- **MISC_IRQ (bit 1)**: Miscellaneous Interrupt status
- **MISC_EN (bit 0)**: Miscellaneous Enable control

### IDE Interface Registers (Memory Mapped at $DE0000)
- **IDE_DATA**: IDE Data register (Pins 17-32, bidirectional)
- **IDE_ERROR**: IDE Error register (Pins 17-24, input)
- **IDE_FEATURES**: IDE Features register (Pins 17-24, output)
- **IDE_SECTORCNT**: IDE Sector Count register (Pins 17-24, bidirectional)
- **IDE_SECTOR**: IDE Sector register (Pins 17-24, bidirectional)
- **IDE_CYL_LOW**: IDE Cylinder Low register (Pins 17-24, bidirectional)
- **IDE_CYL_HIGH**: IDE Cylinder High register (Pins 17-24, bidirectional)
- **IDE_DRIVEHEAD**: IDE Drive/Head register (Pins 17-24, bidirectional)
- **IDE_STATUS**: IDE Status register (Pins 17-24, input)
- **IDE_COMMAND**: IDE Command register (Pins 17-24, output)

### RTC Interface Registers (Memory Mapped at $DC0000)
- **RTC_SECONDS**: RTC Seconds register (Pins 17-24, bidirectional)
- **RTC_MINUTES**: RTC Minutes register (Pins 17-24, bidirectional)
- **RTC_HOURS**: RTC Hours register (Pins 17-24, bidirectional)
- **RTC_WEEKDAY**: RTC Weekday register (Pins 17-24, bidirectional)
- **RTC_DATE**: RTC Date register (Pins 17-24, bidirectional)
- **RTC_MONTH**: RTC Month register (Pins 17-24, bidirectional)
- **RTC_YEAR**: RTC Year register (Pins 17-24, bidirectional)
- **RTC_CNTL**: RTC Control register (Pins 17-24, bidirectional)

## PiStorm Interface Considerations

### Bus Interface Signals
- **Address Bus**: A0-A15 connected to CPU address bus
- **Data Bus**: D0-D15 connected to CPU data bus
- **Control Signals**: AS*, LDS*, UDS*, R/W* from CPU
- **Clock**: System clock (28.x MHz) from clock generator
- **DTACK***: Handled via system bus arbitration

### IDE Interface Signals
- **IDE Address**: A0-A2 for IDE register selection
- **IDE Data**: D0-D15 for IDE data transfer
- **IDE Control**: CS0*, CS1*, IRQ*, RST* for IDE control
- **Timing**: Standard IDE timing requirements (350ns min access)

### System Control Interface
- **Memory Control**: Chip RAM vs Fast RAM selection
- **Interrupt Routing**: Level 2, 6 interrupt routing
- **Expansion Control**: AutoConfig and expansion slot control
- **RTC Interface**: Real-time clock control and access

### Memory Configuration
- **Chip RAM**: Direct access through AGNUS
- **Fast RAM**: Through expansion bus
- **Memory Mapping**: Controlled via GAYLE configuration

## Board Model Differences

### A600
- Standard GAYLE implementation
- IDE interface support
- RTC support
- Expansion slot control
- Memory configuration control

### A1200
- Enhanced GAYLE features
- Improved IDE interface
- RTC support
- Expansion slot control
- Power management features
- Clock port access at $D80000

## Signal Timing Requirements

### Bus Interface Timing
- **Address Setup**: 100ns before AS*
- **Data Setup**: 50ns before R/W transition
- **Hold Time**: 20ns after control signals
- **Access Time**: 2-4 CPU cycles typical

### IDE Interface Timing
- **Address Setup**: 10ns before CS*
- **Data Setup**: 50ns before write, 100ns before read
- **Hold Time**: 20ns after CS* deassertion
- **Access Time**: 350ns minimum for IDE registers
- **Data Transfer**: 600ns minimum for IDE data

### Control Signal Timing
- **AS*, LDS*, UDS*, R/W***: Must meet 68000 timing specs
- **DTACK***: Response time within bus cycle
- **Interrupts**: Level-sensitive, must be acknowledged
- **Bus Request**: Follows standard 68000 arbitration

### RTC Interface Timing
- **Access Time**: Standard 68000 timing
- **Clock**: 32.768 kHz crystal input
- **Update Rate**: 1024Hz internal rate
- **Alarm**: Programmable interrupt capability

### Expansion Timing
- **AutoConfig**: Standard protocol timing
- **Memory Access**: Follows 68000 bus timing
- **DMA**: Shared with system DMA
- **Interrupts**: Level 2, 6 timing

## Power Management Features

### Power Control Signals
- **IDE Power**: Control IDE device power
- **RTC Power**: Control RTC oscillator
- **Expansion Power**: Control expansion slot power
- **Sleep Modes**: Various system sleep states

### Power State Transitions
- **Sleep Entry**: ~10-20 CPU cycles
- **Sleep Exit**: ~20-50 CPU cycles (device warm-up)
- **Power Sequencing**: Proper power-up sequence required
- **Clock Gating**: Clocks can be gated for power savings

## Interrupt Handling

### Interrupt Sources
- **IDE Interrupt**: Level 6 (same as disk)
- **RTC Interrupt**: Level 6 (same as disk)
- **Expansion Interrupt**: Level 2 or 6 depending on configuration
- **System Interrupts**: Various system events

### Interrupt Timing
- **Latency**: ~2-4 instruction cycles after event
- **Acknowledgment**: Via INTREQR/INTENA registers
- **Masking**: Via INTENA register
- **Priority**: Level 6 is higher than disk, level 2 is configurable

## DMA Considerations

### DMA Arbitration
- **IDE DMA**: Medium priority
- **System DMA**: High priority (video/audio)
- **Expansion DMA**: Variable priority
- **CPU Access**: Lowest priority when DMA active

### Memory Bandwidth
- **Chip RAM**: Highest priority, fastest access
- **Fast RAM**: High priority, expansion access
- **Shared Access**: All compete for memory bandwidth
- **IDE Bandwidth**: Can consume significant system bandwidth during transfers