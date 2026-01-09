# ZORRO II/III Timing Documentation

Based on ZORRO specification documents and Amiga Hardware Reference.

## Overview
ZORRO (Zorro) is the expansion bus standard for Amiga systems:
- ZORRO II: 16-bit expansion bus for A500/A2000/A3000
- ZORRO III: 32-bit expansion bus for A4000 and later
- AutoConfig protocol for device detection and configuration
- DMA and interrupt sharing with system

## Bus Interface Timing

### Address Space
- **ZORRO II**: $E80000 - $EBFFFF (256KB)
- **ZORRO III**: $200000 - $9FFFFF (up to 8MB per card)
- **AutoConfig**: $E80000 - $E8FFFF (first 64KB of ZORRO II space)
- **Expansion Cards**: Mapped in available address space
- **Access Width**: ZORRO II: 16-bit, ZORRO III: 32-bit (with 16-bit compatibility)

### Bus Timing
- **ZORRO II**: 7MHz timing (same as CPU)
- **ZORRO III**: Up to 28MHz timing (system clock)
- **Address Setup**: 100-200ns before AS*
- **Data Setup**: 50-100ns before R/W transition
- **Hold Time**: 20-50ns after control signals

## AutoConfig Protocol Timing

### AutoConfig Register Addresses
- **ZORRO_ID**: Offset 0x00 (Card ID register)
- **ZORRO_CS**: Offset 0x02 (Control/Status register)
- **ZORRO_ROM**: Offset 0x04 (Expansion ROM vector)
- **ZORRO_SIZE**: Offset 0x06 (Size register)
- **ZORRO_MEMSTART**: Offset 0x08 (Memory start)
- **ZORRO_MEMEND**: Offset 0x0A (Memory end)
- **ZORRO_EXPROM**: Offset 0x0C (Expansion ROM)
- **ZORRO_CTRL**: Offset 0x0E (Control register)

### AutoConfig Timing Sequence
1. **RESET**: System reset initializes all expansion cards
2. **PROBE**: CPU writes to each 64KB boundary looking for cards
3. **READ ID**: Read card ID register to identify manufacturer/product
4. **CONFIGURE**: Set up memory mapping and control registers
5. **ENABLE**: Enable card for operation

### AutoConfig Timing Requirements
- **Address Setup**: 100ns before AS*
- **Data Setup**: 50ns before R/W
- **Hold Time**: 20ns after control
- **Access Time**: 2-4 CPU cycles typical
- **Configuration Time**: Several hundred cycles per card

## ZORRO II Timing Specifications

### ZORRO II Bus Cycles
- **Address Phase**: AS* asserted, address valid
- **Data Phase**: R/W determines direction, data valid
- **Acknowledge**: DTACK* or expansion card acknowledge
- **Cycle Time**: ~280ns minimum for full cycle

### ZORRO II Control Signals
- **AS***: Address Strobe (active low)
- **R/W***: Read/Write control (active low)
- **UDS*/LDS***: Upper/Lower Data Strobe (16-bit access)
- **DTACK***: Data Acknowledge (active low)
- **BR***: Bus Request (active low)
- **BG***: Bus Grant (active low)
- **INT2***: Interrupt Level 2 (active low)
- **INT6***: Interrupt Level 6 (active low)
- **INT7***: Interrupt Level 7 (active low)

### ZORRO II Timing Parameters
- **Clock**: 7.09/7.16 MHz (system clock)
- **Access Time**: 140-280ns typical
- **Setup Time**: 100ns address, 50ns data
- **Hold Time**: 20ns address/data
- **Bus Release**: 100ns typical

## ZORRO III Timing Specifications

### ZORRO III Bus Cycles
- **32-bit Data Bus**: Full 32-bit transfers
- **Address Phase**: AS* asserted, address valid
- **Data Phase**: R/W determines direction, 32-bit data
- **Acknowledge**: DTACK* or expansion card acknowledge
- **Extended Timing**: Support for slower devices

### ZORRO III Control Signals
- **AS***: Address Strobe (active low)
- **R/W***: Read/Write control (active low)
- **LDS*/UDS***: Data strobes for 32-bit access
- **DTACK***: Data Acknowledge (active low)
- **BR***: Bus Request (active low)
- **BG***: Bus Grant (active low)
- **INT2***: Interrupt Level 2 (active low)
- **INT6***: Interrupt Level 6 (active low)
- **INT7***: Interrupt Level 7 (active low)
- **BERR***: Bus Error (active low)
- **RESET***: System Reset (active low)

### ZORRO III Timing Parameters
- **Clock**: Up to 28.375/28.636 MHz (system clock)
- **Access Time**: 70-140ns typical
- **Setup Time**: 35ns address, 25ns data
- **Hold Time**: 10ns address/data
- **Bus Release**: 50ns typical

## DMA Timing on Expansion Bus

### DMA Arbitration
- **CPU**: Highest priority (when not using expansion)
- **Custom Chips**: High priority for video/audio
- **Expansion DMA**: Medium priority
- **CPU**: Lowest priority when expansion DMA active

### DMA Timing Considerations
- **Bus Request**: Expansion card requests bus via BR*
- **Bus Grant**: CPU grants bus via BG*
- **Cycle Stealing**: Expansion DMA can steal cycles
- **Burst Mode**: Some cards support burst transfers

### DMA Performance
- **ZORRO II**: Limited by 16-bit width and 7MHz clock
- **ZORRO III**: Higher bandwidth with 32-bit width and faster clock
- **Latency**: 2-4 cycles typical for bus grant
- **Throughput**: Up to 56MB/s theoretical for ZORRO III

## Interrupt Timing

### Interrupt Levels
- **INT2***: Level 2 interrupt (medium priority)
- **INT6***: Level 6 interrupt (high priority)
- **INT7***: Level 7 interrupt (highest priority)
- **Autovector**: Automatic interrupt vectoring

### Interrupt Latency
- **Request to Acknowledge**: 2-4 instruction cycles
- **Vector Fetch**: Additional 2-4 cycles
- **Service Entry**: 10-20 cycles typical
- **Return**: 6-10 cycles typical

### Interrupt Sharing
- **Multiple Cards**: Can share interrupt lines
- **Daisy Chain**: Some implementations support chaining
- **Software Polling**: May be required for shared interrupts
- **Priority**: Hardware priority or software arbitration

## Memory Mapping Timing

### Memory Configuration
- **Chip RAM**: Highest priority, fastest access
- **Fast RAM**: High priority, expansion access
- **Slow RAM**: Low priority, slower access
- **Expansion RAM**: Variable priority based on card

### Memory Access Timing
- **Chip RAM**: Direct access via custom chips
- **Expansion RAM**: Via expansion bus
- **Wait States**: Added for slower expansion cards
- **Burst Mode**: Available for faster cards

### Memory Size Limits
- **ZORRO II**: Up to 8MB per card (16-bit addressing)
- **ZORRO III**: Up to 1GB per card (32-bit addressing)
- **Total System**: Limited by address space and AutoConfig

## Safe Access Guidelines

### Register Access Timing
- AutoConfig registers accessed during system initialization
- Expansion card registers accessed during normal operation
- Follow standard 68000 bus timing requirements
- Respect card-specific timing requirements

### Memory Access Timing
- Configure memory mapping before access
- Follow card-specific timing specifications
- Use proper wait states for slower cards
- Coordinate with system DMA activity

### DMA Access Timing
- Request bus properly via BR*
- Respect bus grant timing
- Return bus promptly when done
- Coordinate with system DMA to avoid conflicts

### Timing-Sensitive Operations
- AutoConfig should be done during system initialization
- Memory mapping changes should be atomic
- Interrupt enable/disable should be coordinated
- DMA setup should be done carefully

## Potential Side Effects

### Read Side Effects
- Reading AutoConfig registers may advance configuration state
- Reading card registers may clear status flags
- Reading interrupt registers may acknowledge interrupts
- No significant side effects on system timing

### Write Side Effects
- Writing AutoConfig registers configures card immediately
- Writing control registers may reset card functions
- Writing interrupt registers may mask/unmask interrupts
- Writing DMA registers starts DMA operation immediately

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

## DMA Contention Notes

- Expansion DMA competes with custom chip DMA
- Expansion DMA has lower priority than video/audio
- CPU access to expansion may be delayed during heavy DMA
- Custom chip DMA has priority over expansion DMA
- Expansion cards must coordinate with system timing
- Bus arbitration prevents conflicts but may reduce performance