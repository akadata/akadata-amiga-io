# PAULA (Peripherals Audio Logic Unit Amiga) Pin Mapping Documentation

Based on PAULA specification documents and Amiga Hardware Reference.

## PAULA (MOS 8364) Pin Mapping

### Physical Package
- **Package**: 84-pin Plastic Leaded Chip Carrier (PLCC)
- **Chip**: MOS 8364 (PAULA - Peripherals Audio Logic Unit Amiga)
- **Function**: Audio, disk, serial, input sampling, interrupts

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

#### Audio Outputs - Pins 30-37
- **AUD0L (Pin 30)**: Audio channel 0 left (output)
- **AUD0R (Pin 31)**: Audio channel 0 right (output)
- **AUD1L (Pin 32)**: Audio channel 1 left (output)
- **AUD1R (Pin 33)**: Audio channel 1 right (output)
- **AUD2L (Pin 34)**: Audio channel 2 left (output)
- **AUD2R (Pin 35)**: Audio channel 2 right (output)
- **AUD3L (Pin 36)**: Audio channel 3 left (output)
- **AUD3R (Pin 37)**: Audio channel 3 right (output)

#### Disk Interface - Pins 38-47
- **DSKDAT0 (Pin 38)**: Disk data bit 0 (bidirectional)
- **DSKDAT1 (Pin 39)**: Disk data bit 1 (bidirectional)
- **DSKDAT2 (Pin 40)**: Disk data bit 2 (bidirectional)
- **DSKDAT3 (Pin 41)**: Disk data bit 3 (bidirectional)
- **DSKDAT4 (Pin 42)**: Disk data bit 4 (bidirectional)
- **DSKDAT5 (Pin 43)**: Disk data bit 5 (bidirectional)
- **DSKDAT6 (Pin 44)**: Disk data bit 6 (bidirectional)
- **DSKDAT7 (Pin 45)**: Disk data bit 7 (bidirectional)
- **DSKSYNC (Pin 46)**: Disk sync pattern (input/output)
- **DSKSEL0* (Pin 47)**: Drive select 0 (output, active low)

#### Additional Disk Control - Pins 48-54
- **DSKSEL1* (Pin 48)**: Drive select 1 (output, active low)
- **DSKSEL2* (Pin 49)**: Drive select 2 (output, active low)
- **DSKSEL3* (Pin 50)**: Drive select 3 (output, active low)
- **DSKMOTOR* (Pin 51)**: Disk motor control (output, active low)
- **DSKSTEP* (Pin 52)**: Disk step pulse (output)
- **DSKDIR* (Pin 53)**: Disk direction (output)
- **DSKINDEX* (Pin 54)**: Disk index pulse (input)

#### Serial Port - Pins 55-57
- **SERDO (Pin 55)**: Serial data out (output)
- **SERDI (Pin 56)**: Serial data in (input)
- **SERCLK (Pin 57)**: Serial clock (input)

#### Input Sampling - Pins 58-66
- **JX0 (Pin 58)**: Joystick 0 X-axis (input)
- **JY0 (Pin 59)**: Joystick 0 Y-axis (input)
- **JX1 (Pin 60)**: Joystick 1 X-axis (input)
- **JY1 (Pin 61)**: Joystick 1 Y-axis (input)
- **POTx0 (Pin 62)**: Pot counter 0 X (input)
- **POTy0 (Pin 63)**: Pot counter 0 Y (input)
- **POTx1 (Pin 64)**: Pot counter 1 X (input)
- **POTy1 (Pin 65)**: Pot counter 1 Y (input)
- **POTINP (Pin 66)**: Pot input pins (input)

#### Interrupt Signals - Pins 67-73
- **INT* (Pin 67)**: Interrupt request (output, active low)
- **I0 (Pin 68)**: Interrupt level 0 (output)
- **I1 (Pin 69)**: Interrupt level 1 (output)
- **I2 (Pin 70)**: Interrupt level 2 (output)
- **I3 (Pin 71)**: Interrupt level 3 (output)
- **I4 (Pin 72)**: Interrupt level 4 (output)
- **I5 (Pin 73)**: Interrupt level 5 (output)

#### Power and Ground - Pins 15, 40, 50, 60, 70, 84
- **VCC (Pins 15, 84)**: Power supply (+5V)
- **GND (Pins 14, 40, 50, 60, 70)**: Ground reference

#### System Control - Pins 75-76
- **LED (Pin 75)**: LED control (output)
- **OVERLAY* (Pin 76)**: Memory overlay control (output, active low)

## PAULA Register Mapping to Physical Signals

### Audio Channel 0 (AUD0) - Pins 30-31
- **AUD0LCH/AUD0LCL**: Audio channel 0 location registers
- **AUD0LEN**: Audio channel 0 length register
- **AUD0PER**: Audio channel 0 period register
- **AUD0VOL**: Audio channel 0 volume register
- **AUD0DAT**: Audio channel 0 data register
- **Physical**: Pins 30 (left), 31 (right) for analog output

### Audio Channel 1 (AUD1) - Pins 32-33
- **AUD1LCH/AUD1LCL**: Audio channel 1 location registers
- **AUD1LEN**: Audio channel 1 length register
- **AUD1PER**: Audio channel 1 period register
- **AUD1VOL**: Audio channel 1 volume register
- **AUD1DAT**: Audio channel 1 data register
- **Physical**: Pins 32 (left), 33 (right) for analog output

### Audio Channel 2 (AUD2) - Pins 34-35
- **AUD2LCH/AUD2LCL**: Audio channel 2 location registers
- **AUD2LEN**: Audio channel 2 length register
- **AUD2PER**: Audio channel 2 period register
- **AUD2VOL**: Audio channel 2 volume register
- **AUD2DAT**: Audio channel 2 data register
- **Physical**: Pins 34 (left), 35 (right) for analog output

### Audio Channel 3 (AUD3) - Pins 36-37
- **AUD3LCH/AUD3LCL**: Audio channel 3 location registers
- **AUD3LEN**: Audio channel 3 length register
- **AUD3PER**: Audio channel 3 period register
- **AUD3VOL**: Audio channel 3 volume register
- **AUD3DAT**: Audio channel 3 data register
- **Physical**: Pins 36 (left), 37 (right) for analog output

### Disk DMA Interface - Pins 38-54
- **DSKPTH/DSKPTL**: Disk pointer registers
- **DSKLEN**: Disk length register
- **DSKDAT**: Disk data register
- **DSKSYNC**: Disk sync register
- **Physical**: Pins 38-45 (data), 46 (sync), 47-51 (select), 52-53 (step/dir), 54 (index)

### Serial Port Interface - Pins 55-57
- **SERDAT**: Serial data write register
- **SERDATR**: Serial data read register
- **SERPER**: Serial period register
- **Physical**: Pins 55 (out), 56 (in), 57 (clock)

### Input Sampling Interface - Pins 58-66
- **JOY0DAT/JOY1DAT**: Joystick/mouse data registers
- **POT0DAT/POT1DAT**: Pot counter data registers
- **POTGOR/POTGO**: Pot port data registers
- **Physical**: Pins 58-61 (jx/y), 62-66 (pot)

## PiStorm Interface Considerations

### Bus Interface Signals
- **Address Bus**: A0-A17 connected to CPU address bus
- **Data Bus**: D0-D15 connected to CPU data bus
- **Control Signals**: AS*, LDS*, UDS*, R/W* from CPU
- **Clock**: System clock (28.x MHz) from clock generator
- **DTACK***: Handled internally by custom chip complex

### Audio Output Interface
- **Digital to Analog**: Audio channels converted to analog on-chip
- **Stereo Output**: Each channel has left/right analog outputs
- **Sampling Rate**: Determined by period registers
- **Volume Control**: 6-bit volume control per channel

### Disk Interface Timing
- **Data Transfer**: 16-bit word transfers
- **Sync Matching**: Pattern matching for sector alignment
- **DMA Control**: Disk DMA with priority arbitration
- **Drive Control**: Multiple drive selection and motor control

### Serial Interface Timing
- **Baud Rate**: Configurable via SERPER register
- **Word Length**: Configurable via control bits
- **Handshaking**: Hardware handshaking support
- **Clock Source**: From timer or crystal

### Input Sampling Interface
- **Quadrature Decoding**: For mouse movement
- **Counter Accumulation**: Continuous position tracking
- **Fire Button Inputs**: Active low button inputs
- **Pot Counter Interface**: Analog input sampling

## Board Model Differences

### A500/A2000 (OCS)
- Standard PAULA implementation
- 4-channel 8-bit audio
- Standard disk controller interface
- Basic serial port support

### A600/A1200 (ECS/AGA)
- ECS-enhanced PAULA features
- Improved audio capabilities
- IDE interface timing considerations
- Enhanced disk controller support

### A3000/A4000 (ECS/AGA)
- SCSI interface may share some signals
- Enhanced disk controller capabilities
- Same basic PAULA timing characteristics
- AGA audio enhancements

## Signal Timing Requirements

### Address Setup/Hold Times
- Address must be stable before AS* assertion
- Hold time required after AS* deassertion
- Data setup/hold times per 68000 specifications

### Control Signal Timing
- AS*, LDS*, UDS*, R/W* must meet 68000 timing specs
- DMA arbitration follows standard protocols
- Interrupt timing compatible with 68000 interrupt handling

### Audio Output Timing
- Audio data converted to analog at sample rate
- Output stable during sample period
- Volume changes take effect immediately
- Stereo channels synchronized

### Disk Interface Timing
- Data valid during disk transfer cycles
- Sync pattern matching during read
- Drive selection timing critical for operation
- Step/direction timing for head positioning