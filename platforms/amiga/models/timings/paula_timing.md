# PAULA (Peripherals Audio Logic Unit Amiga) Timing Documentation

Based on Amiga Hardware Reference Manual and official documentation.

## Overview
PAULA is the Amiga peripheral and audio controller chip responsible for:
- Audio DMA and playback
- Disk DMA operations
- Serial port operations
- Joystick/mouse input sampling
- Potentiometer input sampling
- Interrupt control

## Bus Interface Timing

### Address Space
- Base address: $DFF000 (shared with other custom chips)
- Address range: $DFF000 - $DFF1FF (512 bytes)
- Access width: 16-bit word access only
- Timing: Synchronous with system clock (28.37516 MHz PAL / 28.63636 MHz NTSC)

### Access Timing
- CPU access: 2-4 system clock cycles (typically 140-280ns)
- DMA access: Dedicated cycles during video blanking periods
- No wait states required for custom chip access
- All registers are memory-mapped

## Audio DMA Timing

### Audio Channel Characteristics
- 4 independent audio channels (0-3)
- Each channel has dedicated DMA channel
- Sample rate determined by period register value
- Formula: Sample Rate = Clock Frequency / (2 * Period)
- NTSC: Rate = 3.579545 MHz / Period
- PAL: Rate = 3.546895 MHz / Period

### Audio Period Values
- Minimum period: 124 (3.547 kHz sample rate)
- Maximum period: 65535 (0.108 Hz sample rate)
- Each sample requires 1 DMA cycle
- Audio DMA occurs during horizontal blanking

### Audio Channel Register Timing
- AUDxLCH/AUDxLCL: Pointer to audio data (20-bit address)
- AUDxLEN: Length in words (0-65535)
- AUDxPER: Period for sample rate (0-65535)
- AUDxVOL: Volume control (0-64)
- AUDxDAT: Data register (written by CPU, read by DMA)

### Audio DMA Cycle Requirements
- Each audio channel requires 1 cycle per sample period
- Multiple channels can run simultaneously
- Total bandwidth shared among active channels
- Audio DMA has lower priority than video DMA

## Disk DMA Timing

### Disk Controller Timing
- Disk DMA uses dedicated channel
- 16-bit word transfers
- Sync pattern matching capability
- Bit rate: 28.8 kbps to 1.4 Mbps depending on configuration

### Disk Register Timing
- DSKPTH/DSKPTL: Disk data pointer (20-bit address)
- DSKLEN: Disk transfer length (14-bit, 0-16383 words)
- DSKDAT: Write data to disk
- DSKBYTR: Read data from disk
- DSKSYNC: Sync pattern register

### Disk Transfer Timing
- Each word transfer requires 1 DMA cycle
- Disk DMA has medium priority
- Can be synchronized to specific disk sync patterns
- Fast serial clock available for high-speed transfers

## Serial Port Timing

### Serial Communication Timing
- Configurable baud rate via SERPER register
- Formula: Baud Rate = 3.546895 MHz (PAL) / (2 * SERPER)
- 8-bit data, configurable stop bits
- Hardware handshaking support

### Serial Register Timing
- SERDAT: Write serial data and stop bits
- SERDATR: Read serial data and status
- SERPER: Serial period and control

### Serial DMA Requirements
- Uses CPU cycles during serial transfer
- Can be configured for different word lengths
- Supports both synchronous and asynchronous modes

## Input Sampling Timing

### Joystick/Mouse Timing
- JOY0DAT/JOY1DAT: Read 16-bit counter values
- Upper 8 bits: Vertical position
- Lower 8 bits: Horizontal position
- Quadrature decoding for mouse movement
- Debounced fire button inputs

### Pot Counter Timing
- POT0DAT/POT1DAT: Read potentiometer counter values
- Each pair provides vertical and horizontal position
- POTGO: Start pot counter conversion
- Conversion time: ~1 frame period for full scale

### Input Sampling Characteristics
- Mouse/joystick counters update continuously
- Values represent accumulated movement since last read
- Fire buttons are active low inputs
- Debouncing handled by hardware

## Interrupt Timing

### Interrupt Sources
- Level 3: Blitter done, Copper
- Level 4: Vertical blank
- Level 5: Sprite overflow/duplicate
- Level 6: Audio channels, Disk block done
- Level 7: External interrupts

### Interrupt Latency
- Typical latency: 2-4 instruction cycles
- Highest priority: Blitter finished
- Level 3: ~2-4 cycles
- Level 6: ~2-4 cycles
- Level 7: ~2-4 cycles

### Interrupt Acknowledgment
- Reading INTREQR clears interrupt request
- Writing to INTREQ with SETCLR bit clears specific interrupts
- Master interrupt enable in INTENA controls global interrupt state

## DMA Arbitration Timing

### Priority Levels
1. Refresh (highest)
2. Video DMA
3. Audio DMA
4. Disk DMA
5. Sprite DMA
6. Copper DMA
7. Blitter DMA (when BLTPRI set)
8. CPU (lowest when DMA active)

### DMA Channel Timing
- Each DMA channel gets dedicated cycles
- Audio channels: 1 cycle per sample period
- Disk: Variable cycles during data transfer
- Sprite: 1-2 cycles per active sprite per line
- Copper: Every other cycle during active period
- Blitter: Variable, can hog CPU cycles when BLTPRI set

## Collision Detection Timing

### Collision Register Timing
- CLXDAT: Read collision data and clear
- CLXCON: Configure collision detection
- Collision detection occurs in real-time
- Reading CLXDAT clears all collision bits

### Collision Detection Characteristics
- Sprite vs sprite collision detection
- Sprite vs bitplane collision detection
- Bitplane vs bitplane collision detection
- Immediate detection with no latency

## Audio/Disk Control Timing (ADKCON)

### Audio Control Features
- MFM compatibility mode
- Word sync control
- UART break control
- Precompensation control
- Serial delay control
- Channel linking

### Disk Control Features
- Write precompensation
- Serial delay adjustment
- MFM compatibility
- Word sync control

## Safe Access Guidelines

### Register Access Timing
- All registers can be read/written at any time
- Some registers have side effects when written
- Reading INTREQR/INTENAR clears interrupt flags
- Writing to DMACON with SETCLR affects all DMA channels

### Audio Channel Access
- Set period, volume, length before location
- Start audio by enabling DMA after setup
- Audio continues until length expires or DMA disabled
- Volume changes take effect immediately

### Disk Access
- Set pointer and length before enabling DMA
- Sync pattern should be set before transfer
- Disk DMA should be synchronized with disk rotation
- Monitor DSKBYTR for status and data

### Serial Access
- Set period before starting communication
- Check status bits before reading/writing data
- Handle overrun conditions appropriately
- Use proper handshaking protocols

## Potential Side Effects

### Read Side Effects
- Reading INTREQR/INTENAR clears interrupt request/enable flags
- Reading CLXDAT clears all collision detection flags
- Reading DSKBYTR clears disk byte ready flag
- Reading SERDATR clears receive buffer full flag

### Write Side Effects
- Writing to AUDxDAT starts audio sample playback
- Writing to DSKDAT initiates disk write operation
- Writing to SERDAT initiates serial transmission
- Writing to POTGO starts pot counter conversion

## Board Model Differences

### A500/A2000
- Standard PAULA implementation
- OCS audio capabilities (4 channels, 8-bit)
- Standard disk controller timing

### A600/A1200
- ECS enhanced features
- Improved audio capabilities
- IDE interface timing considerations

### A3000/A4000
- SCSI interface may share some timing
- Enhanced disk controller capabilities
- Same basic PAULA timing characteristics