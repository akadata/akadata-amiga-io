# BUSTER Timing Documentation

Based on BUSTER specification documents and Amiga Hardware Reference for A3000/A4000 systems.

## Overview
BUSTER is the memory control chip for A3000/A4000 systems responsible for:
- Chip RAM control and timing (A3000)
- Memory refresh management
- DRAM control signals
- Memory configuration and mapping
- System control functions

## Bus Interface Timing

### Address Space
- Base address: $DD0000 (A3000/A4000 specific)
- Address range: $DD0000 - $DDFFFF (64KB)
- BUSTER registers: $DD0000 - $DD001F (32 bytes)
- Access width: 16-bit word access
- Timing: Synchronous with system clock (28.37516 MHz PAL / 28.63636 MHz NTSC)

### Access Timing
- CPU access: 2-4 system clock cycles (typically 140-280ns)
- Memory-mapped register access
- No special timing requirements beyond standard 68000 bus protocol
- Direct control of DRAM timing

## Memory Control Timing

### BUSTER Control Register (CTRL)
- Address: $DD0000
- Controls memory system features
- Reset control for memory subsystem
- Enable/disable memory features
- Sleep/power management controls

### Control Register Bits Timing
- **CHIPRST**: Chip reset control (active high)
- **MEMRST**: Memory reset control (active high)
- **CLKRST**: Clock reset control (active high)
- **BUSRST**: Bus reset control (active high)
- **CHIPEN**: Chip enable control
- **MEMEN**: Memory enable control
- **CLKEN**: Clock enable control
- **BUSEN**: Bus enable control
- **CHIPSLP**: Chip sleep control
- **MEMSLP**: Memory sleep control
- **CLKSLP**: Clock sleep control
- **BUSSLP**: Bus sleep control
- **CHIPCFG**: Chip configuration
- **MEMCFG**: Memory configuration
- **CLKCFG**: Clock configuration
- **BUSCFG**: Bus configuration

## DRAM Timing Control

### DRAM Control Register (DRAM_CTRL)
- Address: $DD0008
- Controls DRAM timing parameters
- CAS and RAS timing
- Refresh timing
- Burst mode control

### DRAM Timing Parameters
- **CAS Latency**: 2, 3, or 4 clock cycles
- **RAS Latency**: 2, 3, or 4 clock cycles
- **Precharge time**: Configurable
- **Activate time**: Configurable
- **Write recovery**: Configurable
- **Refresh cycle**: Configurable

### DRAM Timing Values
- **CAS Latency 2**: 280ns at 7MHz, 140ns at 14MHz
- **CAS Latency 3**: 420ns at 7MHz, 210ns at 14MHz
- **CAS Latency 4**: 560ns at 7MHz, 280ns at 14MHz
- **RAS to CAS delay**: Configurable based on memory type
- **Row precharge**: Configurable based on memory type

## Memory Configuration Timing

### Configuration Register (CONFIG)
- Address: $DD0004
- **RAM Size**: 512K, 1M, 2M, 4M, 8M, etc.
- **RAM Type**: FPM, EDO, SDRAM
- **Clock Type**: 28MHz, 28.375MHz, 28.636MHz
- **Bus Width**: 8-bit, 16-bit, 32-bit

### Memory Size Configuration
- **512K**: Standard A3000 configuration
- **1M**: A4000 standard configuration
- **2M**: A4000 expanded configuration
- **4M-8M**: A4000 high-end configurations
- **Up to 256M**: With proper expansion

### Memory Type Timing
- **FPM (Fast Page Mode)**: Traditional DRAM timing
- **EDO (Extended Data Out)**: Faster access timing
- **SDRAM**: Synchronous timing requirements
- **Auto-refresh**: Built-in refresh control

## Refresh Timing

### Refresh Control Register (REFRESH)
- Address: $DD0006
- Controls DRAM refresh cycles
- Refresh counter value
- Refresh enable/disable
- Refresh mode selection

### Refresh Timing Parameters
- **Refresh rate**: 15.625kHz (PAL) / 15.734kHz (NTSC)
- **Refresh cycles**: 8 per 16-line period
- **Refresh distribution**: Across scan lines
- **Auto-refresh**: Built-in refresh counter

### Refresh Cycle Distribution
- **Total refresh cycles**: 8 per 16-line period
- **Distribution**: Across scan lines to minimize impact
- **Priority**: Below video DMA, above CPU
- **Timing**: During horizontal blank periods

## Chip Select Timing

### Chip Select Control Register (CHIPSEL)
- Address: $DD000A
- Controls memory bank selection
- Fast RAM enable/disable
- Slow RAM enable/disable
- ROM enable/disable

### Chip Select Timing
- **Chip Select 0-3**: Main memory banks
- **Fast RAM 0-3**: Zorro II/III fast RAM
- **Slow RAM 0-3**: Trapdoor/Slow RAM
- **ROM 0-3**: ROM bank selection

### Memory Bank Timing
- **Chip RAM**: Highest priority, fastest access
- **Fast RAM**: High priority, fast access
- **Slow RAM**: Low priority, slower access
- **ROM**: Read-only, various speeds

## Memory Access Timing

### Chip RAM Access
- **Access time**: 140ns (7MHz), 70ns (14MHz), 35ns (28MHz)
- **Cycle time**: 280ns (7MHz), 140ns (14MHz), 70ns (28MHz)
- **Page mode**: Faster access within same row
- **RAS/CAS timing**: Configurable based on memory type

### Fast RAM Access
- **Access time**: Variable based on memory type
- **Timing**: Controlled by memory controller
- **Priority**: Below chip RAM
- **Burst mode**: Available on some configurations

### Memory Bandwidth
- **Chip RAM**: Full bandwidth for custom chips
- **Fast RAM**: Available to CPU and expansion
- **Shared access**: Custom chips have priority
- **Bandwidth allocation**: Dynamic based on demand

## Power Management Timing

### Power Control Features
- **Memory power control**: Individual bank power control
- **Clock gating**: Clocks can be gated for power savings
- **Sleep modes**: Various memory sleep states
- **Wake-up timing**: Memory wake-up delays

### Power State Transitions
- **Sleep entry**: ~10-20 CPU cycles
- **Sleep exit**: ~20-50 CPU cycles (memory warm-up)
- **Power sequencing**: Proper power-up sequence required
- **Clock stabilization**: Clocks need stabilization time

## Configuration Timing

### BUSTER Configuration Register
- **RAM Size**: Configures memory size detection
- **RAM Type**: Configures memory type parameters
- **Clock Type**: Configures system clock parameters
- **Bus Width**: Configures bus width parameters

### Configuration Changes
- **Immediate effect**: Most changes take effect immediately
- **Memory reset**: Some changes require memory reset
- **Timing recalibration**: Memory timing may need adjustment
- **System stability**: Changes may affect system stability

## Safe Access Guidelines

### Register Access Timing
- All BUSTER registers can be accessed at any time
- Memory configuration registers should be set during initialization
- Timing registers should be set before memory access
- No special setup required for register access

### Memory Access Timing
- Follow DRAM timing specifications
- Allow proper setup/hold times
- Respect memory access priorities
- Coordinate with system DMA activity

### Timing-Sensitive Operations
- Memory configuration changes should be done carefully
- Timing adjustments may require system reboot
- Refresh timing should not be modified during operation
- Power management operations should be atomic

## Potential Side Effects

### Read Side Effects
- Reading test register may clear test results
- Reading configuration registers returns current values
- No significant read side effects on memory operation

### Write Side Effects
- Writing control register may reset memory subsystem
- Writing configuration may change memory timing immediately
- Writing refresh register affects DRAM refresh immediately
- Writing chip select affects memory mapping immediately

## Board Model Differences

### A3000
- BUSTER implementation for A3000
- Standard memory configuration
- FPM DRAM support
- Up to 8MB Chip RAM

### A4000
- Enhanced BUSTER features (AGA)
- EDO/SDRAM support
- Higher memory capacity support
- Better memory timing control
- Up to 8MB Chip RAM standard

## DMA Contention Notes

- BUSTER controls memory access timing
- Custom chip DMA has priority over CPU
- Memory refresh cycles steal from all accessors
- No direct conflict with custom chip operations
- CPU access to BUSTER registers may be delayed during heavy memory access
- Memory bandwidth shared between CPU and custom chips