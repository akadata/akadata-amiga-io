# CIA (Complex Interface Adapter) Timing Documentation

Based on Amiga Hardware Reference Manual and official documentation.

## Bus Ownership and Timing

### CIA Access Timing
- CIA registers are accessed via 8-bit data bus
- CIAA uses odd addresses (low byte), CIAB uses even addresses (high byte)
- CIA registers are memory-mapped at addresses $BFE001 (CIAA) and $BFD000 (CIAB)
- Access timing is governed by system clock (28.37516 MHz PAL / 28.63636 MHz NTSC)

### Access Windows
- CIA registers can be accessed during any available bus cycle
- No dedicated DMA channels for CIA (unlike custom chips)
- CPU has direct access to CIA registers
- No special timing restrictions for CIA access

## Register Access Timing

### Read Operations
- Typical read access: 2-4 CPU cycles
- No special setup required for reads
- Data available immediately after address is stable

### Write Operations
- Typical write access: 2-4 CPU cycles
- Data must be stable for at least 1 system clock cycle after address
- Some registers have immediate effects (e.g., timers, interrupts)

## Timer Timing

### Timer A and B Characteristics
- Timers count down from programmed value to 0
- Clock source: system clock divided by 10 (default) or external signal
- NTSC: ~715.9 kHz timer clock, PAL: ~709.4 kHz timer clock
- Minimum period: 1 (every clock cycle), Maximum: 65535 (once per ~91ms at 709kHz)

### Timer Control Timing
- Setting START bit in control register starts timer immediately
- Timer counts down every clock cycle until reaching 0
- When timer reaches 0, it generates interrupt and reloads from latch (if continuous mode)
- One-shot mode: timer stops after reaching 0, requires manual restart

### Time Of Day (TOD) Timing
- Clock source: 50Hz (PAL) or 60Hz (NTSC) from external crystal
- Updates every vertical blank period
- Can be used as alarm timer when ALARM bit is set
- Reading TOD registers latches current time value

## Serial Port Timing

### Serial Data Register (SDR)
- Data shifts out at rate determined by Timer A when in serial mode
- 8-bit serial mode: 1 start bit, 8 data bits, 1 stop bit
- Serial clock can be derived from Timer A or crystal
- Data must be written to SDR before transmission begins

### Serial Port Access
- Writing to SDR initiates transmission
- Reading from SDR gets received data
- Serial interrupts generated when data transfer complete

## Interrupt Timing

### Interrupt Generation
- CIA can generate 6 interrupt sources (timer A, timer B, alarm, serial, flag, others)
- Interrupts are edge-triggered
- ICR register shows which interrupt(s) occurred
- Interrupt remains active until acknowledged by reading ICR

### Interrupt Acknowledgment
- Reading ICR acknowledges all pending interrupts
- Individual interrupts can be masked via ICR write
- Interrupt latency: typically 2-4 instruction cycles after interrupt occurs

## Port Access Timing

### Port A and B Timing
- Port registers are read/write accessible
- Reading port returns current pin state (may include external pull-ups)
- Writing to port drives pins according to direction register
- Port pins can be configured as input or output

### Port Direction Control
- DDR registers control pin direction (1=output, 0=input)
- Changing DDR affects pin direction immediately
- Output pins driven with current port data value
- Input pins reflect external signal state

## Special Timing Considerations

### Port B Output Enable (CIAA)
- Bit 6 of CIAAPRB controls LED brightness (0=bright, 1=dim)
- Bit 7 controls memory overlay (0=overlay enabled, 1=disabled)

### Port A Input (CIAA)
- Contains system status bits (disk ready, track 0, etc.)
- These are typically active-low signals
- Reading these bits provides current hardware status

### Port B Input (CIAA)
- Connected to keyboard matrix
- Reading provides current keyboard column state
- Combined with keyboard scanning via copper/list to determine pressed keys

### Port A (CIAB)
- Connected to serial/printer port
- Contains handshake signals (DTR, RTS, CTS, etc.)
- Used for RS-232 communication timing

### Port B (CIAB)
- Connected to disk controller
- Contains drive select, motor control, step, direction signals
- Timing critical for floppy disk operations

## Safe Access Guidelines

### Reading Registers
- Safe to read any CIA register at any time
- Some registers (TOD) should be read multiple times to ensure consistency
- ICR should be read to acknowledge pending interrupts

### Writing Registers
- Avoid writing to timer registers while timer is running (may cause glitches)
- When configuring timers, set latch values before enabling timer
- For TOD registers, write in sequence (low, mid, high) to avoid spurious alarms

### Timing-Sensitive Operations
- Disk operations require precise timing via CIAB port B
- Keyboard scanning should be coordinated with copper/list timing
- Serial communication timing depends on timer configuration

## Potential Side Effects

### Read Side Effects
- Reading ICR clears all pending interrupts
- Reading TOD registers latches current time value
- No other significant read side effects

### Write Side Effects
- Writing to ICR sets interrupt mask (does not clear pending interrupts)
- Writing to timers while running may cause unexpected behavior
- Writing to TOD registers starts new alarm countdown

## DMA Contention Notes

- CIA does not use dedicated DMA channels
- No direct conflict with custom chip DMA operations
- CPU access to CIA registers may be delayed during custom chip DMA bursts
- Serial port operations may be affected by overall system timing

## Board Model Differences

### A500/A2000
- Standard CIAA/CIAB configuration
- Keyboard matrix connection to CIAAPRB
- Game port connections to CIAAPRA

### A600/A1200
- Similar CIA configuration but with IDE interface
- CIAB port B may have additional IDE control signals
- Same basic timing characteristics

### A3000/A4000
- SCSI interface may share some CIA signals
- Similar basic CIA timing and operation