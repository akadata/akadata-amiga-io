/*
 * SPDX-License-Identifier: MIT
 * 
 * CIA (Complex Interface Adapter) chip register definitions for Amiga
 * Based on Amiga Hardware Reference Manual and official documentation
 * Addresses: CIAA ($BFE001) and CIAB ($BFD000)
 */

#ifndef CIA_H
#define CIA_H

// CIA base addresses
#define CIAA_BASE 0xBFE001  // CIA A base address (odd, low byte)
#define CIAB_BASE 0xBFD000  // CIA B base address (even, high byte)

// CIA Register Offsets (added to base address)
#define CIAPRA    0x0000  // Port A data register
#define CIAPRB    0x0100  // Port B data register
#define CIADDRA   0x0200  // Port A data direction register
#define CIADDRB   0x0300  // Port B data direction register
#define CIATALO   0x0400  // Timer A low byte
#define CIATAHI   0x0500  // Timer A high byte
#define CIATBLO   0x0600  // Timer B low byte
#define CIATBHI   0x0700  // Timer B high byte
#define CIATODLOW 0x0800  // Time Of Day low
#define CIATODMID 0x0900  // Time Of Day mid
#define CIATODHI  0x0A00  // Time Of Day high
#define CIASDR    0x0C00  // Serial Data Register
#define CIAICR    0x0D00  // Interrupt Control Register
#define CIACRA    0x0E00  // Control Register A
#define CIACRB    0x0F00  // Control Register B

// CIAA Register Addresses
#define CIAAPRA   (CIAA_BASE + CIAPRA)    // CIA A Port A data (R/W)
#define CIAAPRB   (CIAA_BASE + CIAPRB)    // CIA A Port B data (R/W)
#define CIAADDR_A (CIAA_BASE + CIADDRA)   // CIA A Port A direction (R/W)
#define CIAADDR_B (CIAA_BASE + CIADDRB)   // CIA A Port B direction (R/W)
#define CIAATALO  (CIAA_BASE + CIATALO)   // CIA A Timer A low (R/W)
#define CIAATAHI  (CIAA_BASE + CIATAHI)   // CIA A Timer A high (R/W)
#define CIAATBLO  (CIAA_BASE + CIATBLO)   // CIA A Timer B low (R/W)
#define CIAATBHI  (CIAA_BASE + CIATBHI)   // CIA A Timer B high (R/W)
#define CIAATODLOW (CIAA_BASE + CIATODLOW) // CIA A Time Of Day low (R/W)
#define CIAATODMID (CIAA_BASE + CIATODMID) // CIA A Time Of Day mid (R/W)
#define CIAATODHI  (CIAA_BASE + CIATODHI)  // CIA A Time Of Day high (R/W)
#define CIAASDR   (CIAA_BASE + CIASDR)    // CIA A Serial Data Register (R/W)
#define CIAAICR   (CIAA_BASE + CIAICR)    // CIA A Interrupt Control Register (R)
#define CIAACRA   (CIAA_BASE + CIACRA)    // CIA A Control Register A (R/W)
#define CIAACRB   (CIAA_BASE + CIACRB)    // CIA A Control Register B (R/W)

// CIAB Register Addresses
#define CIABPRA   (CIAB_BASE + CIAPRA)    // CIA B Port A data (R/W)
#define CIABPRB   (CIAB_BASE + CIAPRB)    // CIA B Port B data (R/W)
#define CIABDDRA  (CIAB_BASE + CIADDRA)   // CIA B Port A direction (R/W)
#define CIABDDRB  (CIAB_BASE + CIADDRB)   // CIA B Port B direction (R/W)
#define CIABTALO  (CIAB_BASE + CIATALO)   // CIA B Timer A low (R/W)
#define CIABTAHI  (CIAB_BASE + CIATAHI)   // CIA B Timer A high (R/W)
#define CIABTBLO  (CIAB_BASE + CIATBLO)   // CIA B Timer B low (R/W)
#define CIABTBHI  (CIAB_BASE + CIATBHI)   // CIA B Timer B high (R/W)
#define CIABTODLOW (CIAB_BASE + CIATODLOW) // CIA B Time Of Day low (R/W)
#define CIABTODMID (CIAB_BASE + CIATODMID) // CIA B Time Of Day mid (R/W)
#define CIABTODHI  (CIAB_BASE + CIATODHI)  // CIA B Time Of Day high (R/W)
#define CIABSDR   (CIAB_BASE + CIASDR)    // CIA B Serial Data Register (R/W)
#define CIABICR   (CIAB_BASE + CIAICR)    // CIA B Interrupt Control Register (R)
#define CIABCRA   (CIAB_BASE + CIACRA)    // CIA B Control Register A (R/W)
#define CIABCRB   (CIAB_BASE + CIACRB)    // CIA B Control Register B (R/W)

// CIA Interrupt Control Register (CIAICR) bits
#define CIAICR_TAIRQ    0x01  // Timer A interrupt
#define CIAICR_TBIRQ    0x02  // Timer B interrupt
#define CIAICR_ALARM    0x04  // Alarm interrupt
#define CIAICR_SPIRQ    0x08  // Serial port interrupt
#define CIAICR_FLGIRQ   0x10  // Flag pin interrupt
#define CIAICR_IRRQ     0x80  // Interrupt request (output)

// CIA Control Register A (CIACRA) bits
#define CIACRA_START      0x01  // Start/stop timer
#define CIACRA_PBON       0x02  // Timer A controls port B bit 6
#define CIACRA_OUTMODE    0x04  // Output mode
#define CIACRA_RUNMODE    0x08  // Run mode (one-shot/continuous)
#define CIACRA_LOAD       0x10  // Load timer from latch
#define CIACRA_INMODE     0x20  // Input mode
#define CIACRA_SPMODE     0x40  // Serial port mode
#define CIACRA_TODIN      0x80  // Time of day/increment mode

// CIA Control Register B (CIACRB) bits
#define CIACRB_START      0x01  // Start/stop timer
#define CIACRB_PBON       0x02  // Timer B controls port B bit 7
#define CIACRB_OUTMODE    0x04  // Output mode
#define CIACRB_RUNMODE    0x08  // Run mode (one-shot/continuous)
#define CIACRB_LOAD       0x10  // Load timer from latch
#define CIACRB_INMODE0    0x20  // Input mode bit 0
#define CIACRB_INMODE1    0x40  // Input mode bit 1
#define CIACRB_ALARM      0x80  // Alarm/TOD mode

// CIA Control Register A bit positions
#define CIACRA_START_BIT    0
#define CIACRA_PBON_BIT     1
#define CIACRA_OUTMODE_BIT  2
#define CIACRA_RUNMODE_BIT  3
#define CIACRA_LOAD_BIT     4
#define CIACRA_INMODE_BIT   5
#define CIACRA_SPMODE_BIT   6
#define CIACRA_TODIN_BIT    7

// CIA Control Register B bit positions
#define CIACRB_START_BIT    0
#define CIACRB_PBON_BIT     1
#define CIACRB_OUTMODE_BIT  2
#define CIACRB_RUNMODE_BIT  3
#define CIACRB_LOAD_BIT     4
#define CIACRB_INMODE0_BIT  5
#define CIACRB_INMODE1_BIT  6
#define CIACRB_ALARM_BIT    7

// CIAA Port A (CIAAPRA) - System control/input
#define CIAA_GAMEPORT1    0x80  // Gameport 1, pin 6 (fire button*) - active low
#define CIAA_GAMEPORT0    0x40  // Gameport 0, pin 6 (fire button*) - active low
#define CIAA_DSKRDY       0x20  // Disk ready* - active low
#define CIAA_DSKTRACK0    0x10  // Disk on track 00* - active low
#define CIAA_DSKPROT      0x08  // Disk write protect* - active low
#define CIAA_DSKCHANGE    0x04  // Disk change* - active low
#define CIAA_LED          0x02  // LED control (0 == bright/on) - active low
#define CIAA_OVERLAY      0x01  // Memory overlay bit - active low

// CIAA Port B (CIAAPRB) - Keyboard matrix:
// Bits 7-0 represent keyboard matrix columns

// CIAB Port A (CIABPRA) - Serial/Printer control:
#define CIAB_COMDTR       0x80  // Serial Data Terminal Ready
#define CIAB_COMRTS       0x40  // Serial Request to Send
#define CIAB_COMCD        0x20  // Serial Carrier Detect
#define CIAB_COMCTS       0x10  // Serial Clear to Send
#define CIAB_COMDSR       0x08  // Serial Data Set Ready
#define CIAB_PRTRSEL      0x04  // Printer SELECT
#define CIAB_PRTRPOUT     0x02  // Printer paper out
#define CIAB_PRTRBUSY     0x01  // Printer busy

// CIAB Port B (CIABPRB) - Disk control:
#define CIAB_DSKMOTOR     0x80  // Disk motor
#define CIAB_DSKSEL3      0x40  // Drive select 3
#define CIAB_DSKSEL2      0x20  // Drive select 2
#define CIAB_DSKSEL1      0x10  // Drive select 1
#define CIAB_DSKSEL0      0x08  // Drive select 0
#define CIAB_DSKSIDE      0x04  // Disk side
#define CIAB_DSKDIREC     0x02  // Disk direction
#define CIAB_DSKSTEP      0x01  // Disk step

// Register access widths
#define CIA_REG_WIDTH     8     // All CIA registers are 8-bit

// Timer frequency constants
#define CIA_TIMER_FREQ_NTSC  715909  // NTSC timer frequency (Hz)
#define CIA_TIMER_FREQ_PAL   709379  // PAL timer frequency (Hz)

// TOD Clock frequencies
#define CIA_TOD_FREQ_NTSC    60      // NTSC TOD frequency (Hz)
#define CIA_TOD_FREQ_PAL     50      // PAL TOD frequency (Hz)

// CIA Port Direction Register Values
#define CIA_PORT_OUTPUT     0xFF    // All bits as output
#define CIA_PORT_INPUT      0x00    // All bits as input

// Timer Control Modes
#define CIA_TIMER_ONESHOT      0x00  // One-shot mode
#define CIA_TIMER_CONTINUOUS   0x08  // Continuous mode

// Serial Port Control Modes
#define CIA_SERIAL_DISABLED    0x00  // Serial port disabled
#define CIA_SERIAL_ENABLED     0x40  // Serial port enabled

// Time of Day Control Modes
#define CIA_TOD_INCREMENT      0x00  // Increment mode
#define CIA_TOD_ALARM          0x80  // Alarm mode

// CIA Timer Control Constants
#define CIA_TIMER_STOPPED      0x00  // Timer stopped
#define CIA_TIMER_STARTED      0x01  // Timer started

// CIA Flag Register Constants
#define CIA_FLAG_NEGEDGE       0x00  // Negative edge detection
#define CIA_FLAG_POSEDGE       0x80  // Positive edge detection

// CIA Serial Control Constants
#define CIA_SERIAL_STOP_BITS_1   0x00  // 1 stop bit
#define CIA_SERIAL_STOP_BITS_2   0x08  // 2 stop bits
#define CIA_SERIAL_DATA_BITS_8   0x00  // 8 data bits
#define CIA_SERIAL_DATA_BITS_1   0x04  // 1 data bit

// CIA Serial Clock Sources
#define CIA_SERIAL_CLOCK_TIMER   0x00  // Timer-based clock
#define CIA_SERIAL_CLOCK_CRYSTAL 0x01  // Crystal-based clock

// CIA Timer A/B Special Modes
#define CIA_TIMER_A_PBON_MODE    0x02  // Timer A controls port B bit 6
#define CIA_TIMER_B_PBON_MODE    0x02  // Timer B controls port B bit 7

// CIA Control Register Masks
#define CIA_CR_START_MASK        0x01  // Start/stop mask
#define CIA_CR_PBON_MASK         0x02  // Port B output enable mask
#define CIA_CR_OUTMODE_MASK      0x04  // Output mode mask
#define CIA_CR_RUNMODE_MASK      0x08  // Run mode mask
#define CIA_CR_LOAD_MASK         0x10  // Load mask
#define CIA_CR_INMODE_MASK       0x20  // Input mode mask
#define CIA_CR_SPMODE_MASK       0x40  // Serial port mode mask
#define CIA_CR_TODIN_MASK        0x80  // TOD input mask

// Safe register access macros
#define CIAA_READ(reg_offset) (*(volatile uint8_t *)((CIAA_BASE + (reg_offset))))
#define CIAA_WRITE(reg_offset, val) (*(volatile uint8_t *)((CIAA_BASE + (reg_offset))) = (val))
#define CIAB_READ(reg_offset) (*(volatile uint8_t *)((CIAB_BASE + (reg_offset))))
#define CIAB_WRITE(reg_offset, val) (*(volatile uint8_t *)((CIAB_BASE + (reg_offset))) = (val))

// Function prototypes for CIA register access
extern uint8_t ciaa_read_register(uint16_t offset);
extern void ciaa_write_register(uint16_t offset, uint8_t value);
extern uint8_t ciab_read_register(uint16_t offset);
extern void ciab_write_register(uint16_t offset, uint8_t value);
extern void cia_configure_ports(void);
extern void cia_initialize_timers(void);
extern void cia_enable_interrupts(uint8_t mask);
extern void cia_disable_interrupts(uint8_t mask);

#endif // CIA_H