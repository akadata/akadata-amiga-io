# GARY Timing Documentation

Based on GARY specification documents and Amiga Hardware Reference.

## Overview
GARY (Gate Array) is the system control chip for A2000/A3000 systems responsible for:
- System control and configuration
- Memory management
- Interrupt routing
- Expansion slot control
- RTC and IDE interface management

## Bus Interface Timing

### Address Space
- Base address: $DE0000 (A2000/A3000 specific)
- Address range: $DE0000 - $DEFFFF (64KB)
- Access width: 16-bit word access
- Timing: Synchronous with system clock (28.37516 MHz PAL / 28.63636 MHz NTSC)

### Access Timing
- CPU access: 2-4 system clock cycles (typically 140-280ns)
- Memory-mapped register access
- No special timing requirements beyond standard 68000 bus protocol
- DTACK* handling is internal to system

## System Control Timing

### GARY Control Register (CSR)
- Address: $DE0000
- Controls system-wide features
- IDE reset, enable, and status bits
- RTC presence detection
- Memory configuration flags

### Control Register Bits Timing
- **IDE_RST**: IDE controller reset (active low)
- **IDE_EN**: IDE enable control
- **RTC_PRESENT**: RTC presence indicator
- **IDE_PRESENT**: IDE controller presence
- **MEM_PRESENT**: Memory presence indicator
- **MEM_TYPE**: Memory type (slow/fast)
- **MEM_SIZE**: Memory size configuration
- **CHIPSET**: Chipset type (OCS/ECS/AGA)
- **MODEL**: Model type (A2000/A3000)

## Interrupt Timing

### Interrupt Control
- GARY manages system-level interrupts
- IDE, RTC, expansion interrupts
- Interrupt routing to CPU
- Level 6 interrupt for IDE operations

### Interrupt Latency
- Typical latency: 2-4 instruction cycles
- IDE interrupts: ~2-4 cycles after IDE operation complete
- RTC interrupts: ~2-4 cycles after RTC alarm
- Expansion interrupts: ~2-4 cycles after expansion card request

### Interrupt Acknowledgment
- Reading INTREQR clears interrupt request flags
- Writing to INTREQ with SETCLR clears specific interrupts
- Master interrupt enable controls global interrupt state

## Memory Management Timing

### Memory Configuration
- Controls memory mapping and configuration
- Chip RAM vs Fast RAM selection
- Memory size detection and configuration
- Bank switching for large memory configurations

### Memory Access Timing
- No direct impact on memory access timing
- Memory timing controlled by CPU and Agnus
- GARY provides configuration information
- Memory size and type configuration affects system behavior

## IDE Interface Timing

### IDE Control Timing
- IDE registers mapped in GARY address space
- Standard IDE timing requirements apply
- 350ns minimum access time for IDE registers
- 600ns minimum for IDE data transfers

### IDE Register Access
- IDE data register: 16-bit access
- IDE command/status register: 8-bit access
- IDE address register: 8-bit access
- Timing must meet IDE specification requirements

### IDE DMA Timing
- IDE DMA uses system bus
- DMA arbitration with custom chips
- IDE DMA has medium priority
- May conflict with heavy video/audio DMA

## RTC Interface Timing

### Real-Time Clock Control
- RTC registers accessible via GARY
- Standard MC146818-compatible timing
- 1024Hz time base for RTC
- Alarm interrupt capability

### RTC Access Timing
- RTC registers: 8-bit access
- Read/write timing: ~2-4 CPU cycles
- RTC runs independently of system clock
- Battery-backed operation

## Expansion Slot Timing

### AutoConfig Timing
- Expansion cards use AutoConfig protocol
- GARY provides AutoConfig support
- Card detection and configuration
- Memory mapping for expansion cards

### Expansion DMA Timing
- Expansion DMA shares system bus
- Priority below custom chips
- May be affected by heavy system DMA
- Expansion cards must follow 68000 timing

## Power Management Timing

### Power Control Features
- Controls power to various system components
- IDE power control
- RTC power control
- Expansion slot power control

### Sleep Mode Timing
- System sleep/wake timing
- Clock gating for power savings
- Wake-up from various sources
- Power state transitions

## Safe Access Guidelines

### Register Access Timing
- All GARY registers can be accessed at any time
- IDE registers should be accessed according to IDE timing spec
- RTC registers can be accessed during any available bus cycle
- No special setup required for GARY register access

### Timing-Sensitive Operations
- IDE operations require proper timing compliance
- RTC operations should follow MC146818 timing
- Expansion card configuration should be done carefully
- Memory configuration changes should be coordinated with system state

## Potential Side Effects

### Read Side Effects
- Reading CSR provides current system status
- Reading interrupt registers clears interrupt flags
- No other significant read side effects

### Write Side Effects
- Writing to CSR may reset system components
- IDE control register changes affect IDE operation immediately
- RTC control register changes affect RTC behavior immediately
- Expansion control changes affect card operation immediately

## Board Model Differences

### A2000
- Standard GARY implementation
- IDE interface support
- RTC support
- Expansion slot control

### A3000
- Enhanced GARY features
- SCSI interface support
- Additional memory management features
- Same basic timing characteristics

### A4000
- Gayle chip replaces GARY functionality
- Enhanced IDE interface
- Different memory management approach

## DMA Contention Notes

- GARY does not use dedicated DMA channels
- IDE DMA competes with custom chip DMA
- Expansion DMA may compete with system DMA
- No direct conflict with custom chip operations
- CPU access to GARY registers may be delayed during heavy DMA