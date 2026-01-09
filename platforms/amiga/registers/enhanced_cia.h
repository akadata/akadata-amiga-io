/*
 * SPDX-License-Identifier: MIT
 * 
 * Enhanced CIA (Complex Interface Adapter) chip register definitions for Amiga
 * Based on Amiga Hardware Reference Manual and official documentation
 */

#ifndef ENHANCED_CIA_H
#define ENHANCED_CIA_H

#include "amiga_custom_chips.h"

// CIAA base address (odd addresses, low byte)
#ifndef CIAA_BASE
#define CIAA_BASE 0xBFE001
#endif

// CIAB base address (even addresses, high byte)
#ifndef CIAB_BASE
#define CIAB_BASE 0xBFD000
#endif

// CIA Register Offsets (added to base address)
#define CIAPRA    0x0000  // CIA Port A data register
#define CIAPRB    0x0100  // CIA Port B data register
#define CIADDRA   0x0200  // CIA Port A data direction register
#define CIADDRB   0x0300  // CIA Port B data direction register
#define CIATALO   0x0400  // CIA Timer A low byte
#define CIATAHI   0x0500  // CIA Timer A high byte
#define CIATBLO   0x0600  // CIA Timer B low byte
#define CIATBHI   0x0700  // CIA Timer B high byte
#define CIATODLOW 0x0800  // CIA Time Of Day low
#define CIATODMID 0x0900  // CIA Time Of Day mid
#define CIATODHI  0x0A00  // CIA Time Of Day high
#define CIASDR    0x0C00  // CIA Serial Data Register
#define CIAICR    0x0D00  // CIA Interrupt Control Register
#define CIACRA    0x0E00  // CIA Control Register A
#define CIACRB    0x0F00  // CIA Control Register B

// CIAA Register Addresses
#define CIAAPRA   (CIAA_BASE + CIAPRA)    // CIA A Port A data
#define CIAAPRB   (CIAA_BASE + CIAPRB)    // CIA A Port B data
#define CIAADDR_A (CIAA_BASE + CIADDRA)   // CIA A Port A direction
#define CIAADDR_B (CIAA_BASE + CIADDRB)   // CIA A Port B direction
#define CIAATALO  (CIAA_BASE + CIATALO)   // CIA A Timer A low
#define CIAATAHI  (CIAA_BASE + CIATAHI)   // CIA A Timer A high
#define CIAATBLO  (CIAA_BASE + CIATBLO)   // CIA A Timer B low
#define CIAATBHI  (CIAA_BASE + CIATBHI)   // CIA A Timer B high
#define CIAATODLOW (CIAA_BASE + CIATODLOW) // CIA A Time Of Day low
#define CIAATODMID (CIAA_BASE + CIATODMID) // CIA A Time Of Day mid
#define CIAATODHI  (CIAA_BASE + CIATODHI)  // CIA A Time Of Day high
#define CIAASDR   (CIAA_BASE + CIASDR)    // CIA A Serial Data Register
#define CIAAICR   (CIAA_BASE + CIAICR)    // CIA A Interrupt Control Register
#define CIAACRA   (CIAA_BASE + CIACRA)    // CIA A Control Register A
#define CIAACRB   (CIAA_BASE + CIACRB)    // CIA A Control Register B

// CIAB Register Addresses
#define CIABPRA   (CIAB_BASE + CIAPRA)    // CIA B Port A data
#define CIABPRB   (CIAB_BASE + CIAPRB)    // CIA B Port B data
#define CIABDDRA  (CIAB_BASE + CIADDRA)   // CIA B Port A direction
#define CIABDDRB  (CIAB_BASE + CIADDRB)   // CIA B Port B direction
#define CIABTALO  (CIAB_BASE + CIATALO)   // CIA B Timer A low
#define CIABTAHI  (CIAB_BASE + CIATAHI)   // CIA B Timer A high
#define CIABTBLO  (CIAB_BASE + CIATBLO)   // CIA B Timer B low
#define CIABTBHI  (CIAB_BASE + CIATBHI)   // CIA B Timer B high
#define CIABTODLOW (CIAB_BASE + CIATODLOW) // CIA B Time Of Day low
#define CIABTODMID (CIAB_BASE + CIATODMID) // CIA B Time Of Day mid
#define CIABTODHI  (CIAB_BASE + CIATODHI)  // CIA B Time Of Day high
#define CIABSDR   (CIAB_BASE + CIASDR)    // CIA B Serial Data Register
#define CIABICR   (CIAB_BASE + CIAICR)    // CIA B Interrupt Control Register
#define CIABCRA   (CIAB_BASE + CIACRA)    // CIA B Control Register A
#define CIABCRB   (CIAB_BASE + CIACRB)    // CIA B Control Register B

// CIA Interrupt Control Register (CIAICR) bits
#define CIAICR_TAIRQ   0x01  // Timer A interrupt
#define CIAICR_TBIRQ   0x02  // Timer B interrupt
#define CIAICR_ALARM   0x04  // Alarm interrupt
#define CIAICR_SP_IRQ  0x08  // Serial port interrupt
#define CIAICR_FLG_IRQ 0x10  // Flag pin interrupt
#define CIAICR_IRRQ    0x80  // Interrupt request (output)

// CIA Control Register A (CIACRA) bits
#define CIACRA_START    0x01  // Start/stop timer
#define CIACRA_PBON     0x02  // Timer A controls port B bit 6
#define CIACRA_OUTMODE  0x04  // Output mode
#define CIACRA_RUNMODE  0x08  // Run mode
#define CIACRA_LOAD     0x10  // Load timer from latch
#define CIACRA_INMODE   0x20  // Input mode
#define CIACRA_SPMODE   0x40  // Serial port mode
#define CIACRA_TODIN    0x80  // Time of day/increment mode

// CIA Control Register B (CIACRB) bits
#define CIACRB_START    0x01  // Start/stop timer
#define CIACRB_PBON     0x02  // Timer B controls port B bit 7
#define CIACRB_OUTMODE  0x04  // Output mode
#define CIACRB_RUNMODE  0x08  // Run mode
#define CIACRB_LOAD     0x10  // Load timer from latch
#define CIACRB_INMODE0  0x20  // Input mode bit 0
#define CIACRB_INMODE1  0x40  // Input mode bit 1
#define CIACRB_ALARM    0x80  // Alarm/TOD mode

// CIA Control Register A bit positions
#define CIAB_START    0
#define CIAB_PBON     1
#define CIAB_OUTMODE  2
#define CIAB_RUNMODE  3
#define CIAB_LOAD     4
#define CIAB_INMODE   5
#define CIAB_SPMODE   6
#define CIAB_TODIN    7

// CIA Control Register B bit positions
#define CIAB_START    0
#define CIAB_PBON     1
#define CIAB_OUTMODE  2
#define CIAB_RUNMODE  3
#define CIAB_LOAD     4
#define CIAB_INMODE0  5
#define CIAB_INMODE1  6
#define CIAB_ALARM    7

// CIAA Port A (CIAAPRA) - system control/input
#define CIAA_GAMEPORT1 0x80  // Gameport 1, pin 6 (fire button*)
#define CIAA_GAMEPORT0 0x40  // Gameport 0, pin 6 (fire button*)
#define CIAA_DSKRDY    0x20  // Disk ready*
#define CIAA_DSKTRACK0 0x10  // Disk on track 00*
#define CIAA_DSKPROT   0x08  // Disk write protect*
#define CIAA_DSKCHANGE 0x04  // Disk change*
#define CIAA_LED       0x02  // LED control (0 == bright/on)
#define CIAA_OVERLAY   0x01  // Memory overlay bit

// CIAA Port B (CIAAPRB) - keyboard matrix:
// Bits 7-0 represent keyboard matrix columns

// CIAB Port A (CIABPRA) - serial/printer control:
#define CIAB_COMDTR    0x80  // Serial Data Terminal Ready
#define CIAB_COMRTS    0x40  // Serial Request to Send
#define CIAB_COMCD     0x20  // Serial Carrier Detect
#define CIAB_COMCTS    0x10  // Serial Clear to Send
#define CIAB_COMDSR    0x08  // Serial Data Set Ready
#define CIAB_PRTRSEL   0x04  // Printer SELECT
#define CIAB_PRTRPOUT  0x02  // Printer paper out
#define CIAB_PRTRBUSY  0x01  // Printer busy

// CIAB Port B (CIABPRB) - disk control:
#define CIAB_DSKMOTOR  0x80  // Disk motor
#define CIAB_DSKSEL3   0x40  // Drive select 3
#define CIAB_DSKSEL2   0x20  // Drive select 2
#define CIAB_DSKSEL1   0x10  // Drive select 1
#define CIAB_DSKSEL0   0x08  // Drive select 0
#define CIAB_DSKSIDE   0x04  // Disk side
#define CIAB_DSKDIREC  0x02  // Disk direction
#define CIAB_DSKSTEP   0x01  // Disk step

// CIA Timer Modes
#define CIA_TIMER_ONESHOT    0x00  // One-shot mode
#define CIA_TIMER_CONTINUOUS 0x08  // Continuous mode

// CIA Input/Output Modes
#define CIA_OUTPUT_MODE      0x00  // Output mode
#define CIA_INPUT_MODE       0x04  // Input mode

// CIA Serial Port Modes
#define CIA_SERIAL_DISABLED  0x00  // Serial port disabled
#define CIA_SERIAL_ENABLED   0x40  // Serial port enabled

// CIA Time of Day Modes
#define CIA_TOD_INCREMENT    0x00  // Increment mode
#define CIA_TOD_ALARM        0x80  // Alarm mode

// CIA Timer Control Constants
#define CIA_TIMER_STOPPED    0x00  // Timer stopped
#define CIA_TIMER_STARTED    0x01  // Timer started

// CIA Port Direction Constants
#define CIA_PORT_OUTPUT      0xFF  // All bits as output
#define CIA_PORT_INPUT       0x00  // All bits as input

// CIA Serial Data Register Constants
#define CIA_SDR_MASK         0xFF  // Serial data register mask

// CIA Interrupt Control Register Constants
#define CIA_ICR_MASK         0xFF  // Full register mask
#define CIA_ICR_CLEAR        0x00  // Clear all interrupts

// CIA TOD Clock Frequencies
#define CIA_NTSC_TOD_FREQ    60    // NTSC TOD frequency (Hz)
#define CIA_PAL_TOD_FREQ     50    // PAL TOD frequency (Hz)

// CIA Timer Frequency Divisors
#define CIA_TIMER_DIV_1      1     // Divide by 1
#define CIA_TIMER_DIV_10     10    // Divide by 10
#define CIA_TIMER_DIV_60     60    // Divide by 60
#define CIA_TIMER_DIV_75     75    // Divide by 75 (PAL)
#define CIA_TIMER_DIV_60HZ   60    // 60Hz timing
#define CIA_TIMER_DIV_50HZ   50    // 50Hz timing (PAL)

// CIA Timer Period Calculations
#define CIA_TIMER_PERIOD_US(freq_div) ((freq_div) * 1.272629)  // Period in microseconds for 709.379 KHz clock

// CIA Flag Register Constants
#define CIA_FLAG_NEGEDGE     0x00  // Negative edge detection
#define CIA_FLAG_POSEDGE     0x80  // Positive edge detection

// CIA Port A/B Special Functions
#define CIA_PORTA_SPECIAL    0x00  // Port A special function
#define CIA_PORTB_SPECIAL    0x00  // Port B special function

// CIA Timer Latch Values
#define CIA_TIMER_LATCH_MIN  0x0000  // Minimum timer latch value
#define CIA_TIMER_LATCH_MAX  0xFFFF  // Maximum timer latch value

// CIA TOD Register Masks
#define CIA_TOD_HOUR_MASK    0x1F    // Hour mask (5 bits)
#define CIA_TOD_MIN_MASK     0x3F    // Minute mask (6 bits)  
#define CIA_TOD_SEC_MASK     0x3F    // Second mask (6 bits)
#define CIA_TOD_TEN_MASK     0x7F    // Tenth second mask (7 bits)

// CIA TOD Register Bit Positions
#define CIA_TOD_HOUR_POS     0       // Hour position
#define CIA_TOD_MIN_POS      0       // Minute position
#define CIA_TOD_SEC_POS      0       // Second position
#define CIA_TOD_TEN_POS      0       // Tenth position

// CIA Serial Control Constants
#define CIA_SERIAL_STOP_BITS_1   0x00  // 1 stop bit
#define CIA_SERIAL_STOP_BITS_2   0x08  // 2 stop bits
#define CIA_SERIAL_DATA_BITS_8   0x00  // 8 data bits
#define CIA_SERIAL_DATA_BITS_1   0x04  // 1 data bit

// CIA Serial Clock Sources
#define CIA_SERIAL_CLOCK_TIMER  0x00  // Timer-based clock
#define CIA_SERIAL_CLOCK_CRYSTAL 0x01  // Crystal-based clock

// CIA Timer A/B Special Modes
#define CIA_TIMER_A_PBON_MODE  0x02  // Timer A controls port B bit 6
#define CIA_TIMER_B_PBON_MODE  0x02  // Timer B controls port B bit 7

// CIA Control Register Masks
#define CIA_CR_START_MASK      0x01  // Start/stop mask
#define CIA_CR_PBON_MASK       0x02  // Port B output enable mask
#define CIA_CR_OUTMODE_MASK    0x04  // Output mode mask
#define CIA_CR_RUNMODE_MASK    0x08  // Run mode mask
#define CIA_CR_LOAD_MASK       0x10  // Load mask
#define CIA_CR_INMODE_MASK     0x20  // Input mode mask
#define CIA_CR_SPMODE_MASK     0x40  // Serial port mode mask
#define CIA_CR_TODIN_MASK      0x80  // TOD input mask

#endif // ENHANCED_CIA_H