# GAYLE Timing Documentation

Based on GAYLE specification documents and Amiga Hardware Reference.

## Overview
GAYLE is the system control chip for A600/A1200 systems responsible for:
- IDE controller interface
- System control and configuration
- Power management
- RTC interface
- Expansion slot control

## Bus Interface Timing

### Address Space
- Base address: $DE0000 (A600/A1200 specific)
- Address range: $DE0000 - $DEFFFF (64KB)
- IDE registers: $DE0000 - $DE000F (primary IDE)
- GAYLE control registers: $DE0010 - $DE001F
- Access width: 16-bit word access
- Timing: Synchronous with system clock (28.37516 MHz PAL / 28.63636 MHz NTSC)

### Access Timing
- CPU access: 2-4 system clock cycles (typically 140-280ns)
- Memory-mapped register access
- IDE register access follows standard IDE timing
- No special timing requirements beyond standard 68000 bus protocol

## IDE Interface Timing

### IDE Register Mapping
- **IDE_DATA**: $DE0000 (16-bit data register)
- **IDE_ERROR**: $DE0002 (8-bit error register)
- **IDE_FEATURES**: $DE0002 (8-bit features register)
- **IDE_SECTORCNT**: $DE0004 (8-bit sector count)
- **IDE_SECTOR**: $DE0006 (8-bit sector number)
- **IDE_CYL_LOW**: $DE0008 (8-bit cylinder low)
- **IDE_CYL_HIGH**: $DE000A (8-bit cylinder high)
- **IDE_DRIVEHEAD**: $DE000C (8-bit drive/head)
- **IDE_STATUS**: $DE000E (8-bit status register)
- **IDE_COMMAND**: $DE000E (8-bit command register)

### IDE Timing Requirements
- **Minimum register access time**: 350ns
- **Minimum data access time**: 165ns
- **Setup time for address**: 10ns
- **Hold time for address**: 10ns
- **Data setup time**: 50ns
- **Data hold time**: 20ns

### IDE DMA Timing
- **DMA burst timing**: Follows IDE specification
- **Bus arbitration**: Shares with custom chips
- **Priority**: Medium (below video/audio, above CPU)
- **Transfer rate**: Up to 16.6 MB/s (PIO mode 4)

## System Control Timing

### GAYLE Control Register (CTRL)
- Address: $DE0010
- Controls system-wide features
- IDE reset, enable, and direction control
- RTC interrupt control
- Expansion slot control

### Control Register Bits Timing
- **IDE_RST**: IDE controller reset (active low)
- **IDE_IRQ**: IDE interrupt request status
- **IDE_EN**: IDE enable control
- **IDE_DIR**: IDE direction (0=read, 1=write)
- **IDE_CS0/CS1**: IDE chip select control
- **RTC_IRQ**: RTC interrupt request status
- **RTC_EN**: RTC enable control
- **EXP_IRQ**: Expansion interrupt request
- **EXP_EN**: Expansion enable control

## Interrupt Timing

### IDE Interrupt Timing
- **Interrupt type**: Level 6 (same as disk)
- **Latency**: ~2-4 instruction cycles after IDE operation complete
- **Acknowledgment**: Via INTREQR/INTENA registers
- **Masking**: Via INTENA register

### RTC Interrupt Timing
- **Interrupt type**: Level 6 (same as disk)
- **Frequency**: 1Hz (seconds), 50/60Hz (field rate), 244Hz (quarter seconds)
- **Latency**: ~2-4 instruction cycles after RTC event
- **Alarm**: Programmable alarm interrupt

### Expansion Interrupt Timing
- **Interrupt type**: Configurable (usually level 6)
- **Latency**: ~2-4 instruction cycles after expansion card request
- **Routing**: Through GAYLE to CPU

## Power Management Timing

### Power Control Features
- **IDE power control**: Controls IDE device power
- **RTC power control**: Controls RTC oscillator
- **Sleep modes**: Various system sleep states
- **Wake-up sources**: IDE, RTC, expansion, keyboard

### Power State Transitions
- **Sleep entry**: ~10-20 CPU cycles
- **Sleep exit**: ~10-20 CPU cycles
- **Power sequencing**: Proper power-up sequence required
- **Clock gating**: Clocks can be gated for power savings

## RTC Interface Timing

### Real-Time Clock Control
- **RTC registers**: Accessible via GAYLE
- **Time base**: 32.768 kHz crystal
- **Update rate**: 1024Hz internal rate
- **Alarm capability**: Programmable alarm interrupt

### RTC Access Timing
- **Register access**: Standard 68000 timing
- **Read/write**: ~2-4 CPU cycles
- **Alarm timing**: ~2-4 cycles after alarm condition
- **Update interrupt**: Every second

## Configuration Timing

### GAYLE Configuration Register
- **Address**: $DE0018
- **IDE mode**: Primary, secondary, or both
- **RTC mode**: Enabled/disabled
- **Expansion mode**: Enabled/disabled
- **Chipset config**: OCS/ECS/AGA detection

### Configuration Changes
- **Immediate effect**: Most configuration changes take effect immediately
- **Reset required**: Some changes may require system reset
- **Timing sensitive**: IDE mode changes should be done carefully

## Safe Access Guidelines

### IDE Register Access
- Follow standard IDE timing specifications
- Check status register before data access
- Allow proper delays between IDE operations
- Use proper handshaking protocols

### GAYLE Register Access
- All registers can be accessed at any time
- IDE registers should be accessed according to IDE timing
- RTC registers can be accessed during any available bus cycle
- Configuration registers should be set during initialization

### Timing-Sensitive Operations
- IDE operations require strict timing compliance
- DMA operations should be coordinated with system state
- Power management operations should be done carefully
- Interrupt enable/disable should be atomic

## Potential Side Effects

### Read Side Effects
- Reading IDE status clears some status flags
- Reading RTC registers may latch time values
- Reading interrupt registers clears interrupt flags
- No other significant read side effects

### Write Side Effects
- Writing IDE command starts IDE operation immediately
- Writing IDE data may initiate transfer
- Writing to control registers affects system state immediately
- Writing to RTC registers may start new alarm countdown

## Board Model Differences

### A600
- Standard GAYLE implementation
- IDE interface only
- RTC support
- No SCSI interface

### A1200
- Enhanced GAYLE features
- IDE interface with better performance
- RTC support
- Expansion slot support
- Power management features

## DMA Contention Notes

- IDE DMA competes with custom chip DMA
- IDE DMA has medium priority
- May conflict with heavy video/audio DMA
- IDE DMA uses system bus cycles
- CPU access to GAYLE registers may be delayed during heavy IDE DMA
- Custom chip DMA has higher priority than IDE DMA