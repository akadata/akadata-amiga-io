/*
 * SPDX-License-Identifier: MIT
 * 
 * GAYLE chip register definitions for Amiga
 * Based on Gayle specification document and Amiga Hardware Reference
 * Addresses: IDE controller and system control registers for A600/A1200
 */

#ifndef GAYLE_H
#define GAYLE_H

#include "amiga_custom_chips.h"

// GAYLE base addresses (A600/A1200 specific)
#define GAYLE_BASE          0xDE0000  // GAYLE chip base address
#define GAYLE_IDE_BASE      0xDE0000  // IDE controller base address
#define GAYLE_IDE_DATA      0xDE0000  // IDE Data register
#define GAYLE_IDE_ERROR     0xDE0002  // IDE Error register
#define GAYLE_IDE_FEATURES  0xDE0002  // IDE Features register
#define GAYLE_IDE_SECTORCNT 0xDE0004  // IDE Sector Count register
#define GAYLE_IDE_SECTOR    0xDE0006  // IDE Sector register
#define GAYLE_IDE_CYL_LOW   0xDE0008  // IDE Cylinder Low register
#define GAYLE_IDE_CYL_HIGH  0xDE000A  // IDE Cylinder High register
#define GAYLE_IDE_DRIVEHEAD 0xDE000C  // IDE Drive/Head register
#define GAYLE_IDE_STATUS    0xDE000E  // IDE Status register
#define GAYLE_IDE_COMMAND   0xDE000E  // IDE Command register

// GAYLE Control Registers
#define GAYLE_CTRL          0xDE0010  // GAYLE Control Register
#define GAYLE_POWER         0xDE0012  // Power Management Register
#define GAYLE_INTREQ        0xDE0014  // GAYLE Interrupt Request
#define GAYLE_INTEN         0xDE0016  // GAYLE Interrupt Enable
#define GAYLE_CONFIG        0xDE0018  // Configuration Register
#define GAYLE_ID            0xDE001A  // GAYLE Chip ID
#define GAYLE_REVISION      0xDE001C  // GAYLE Revision

// GAYLE Expansion Registers
#define GAYLE_EXP_START     0xDE0020  // Expansion Control Start
#define GAYLE_EXP_END       0xDE003E  // Expansion Control End

// IDE Register Bit Definitions
#define IDE_STATUS_BUSY     0x80      // Busy bit
#define IDE_STATUS_READY    0x40      // Drive ready
#define IDE_STATUS_FAULT    0x20      // Drive fault
#define IDE_STATUS_SEEK     0x10      // Seek complete
#define IDE_STATUS_DRQ      0x08      // Data request
#define IDE_STATUS_CORR     0x04      // Corrected data
#define IDE_STATUS_IDX      0x02      // Index
#define IDE_STATUS_ERR      0x01      // Error

#define IDE_ERROR_AMNF      0x01      // Address mark not found
#define IDE_ERROR_TKNONF    0x02      // Track 0 not found
#define IDE_ERROR_ABRT      0x04      // Command aborted
#define IDE_ERROR_MCR       0x08      // Media change requested
#define IDE_ERROR_IDNF      0x10      // ID not found
#define IDE_ERROR_MC        0x20      // Media changed
#define IDE_ERROR_UNC       0x40      // Uncorrectable data
#define IDE_ERROR_BBK       0x80      // Bad block detected

// GAYLE Control Register bits
#define GAYLE_CTRL_IDE_RST  0x8000    // IDE Reset (active low)
#define GAYLE_CTRL_IDE_IRQ  0x4000    // IDE Interrupt Request
#define GAYLE_CTRL_IDE_EN   0x2000    // IDE Enable
#define GAYLE_CTRL_IDE_DIR  0x1000    // IDE Direction (0=read, 1=write)
#define GAYLE_CTRL_IDE_CS0  0x0800    // IDE Chip Select 0
#define GAYLE_CTRL_IDE_CS1  0x0400    // IDE Chip Select 1
#define GAYLE_CTRL_RTC_IRQ  0x0200    // RTC Interrupt Request
#define GAYLE_CTRL_RTC_EN   0x0100    // RTC Enable
#define GAYLE_CTRL_EXP_IRQ  0x0080    // Expansion Interrupt Request
#define GAYLE_CTRL_EXP_EN   0x0040    // Expansion Enable
#define GAYLE_CTRL_PAR_IRQ  0x0020    // Parallel Interrupt Request
#define GAYLE_CTRL_PAR_EN   0x0010    // Parallel Enable
#define GAYLE_CTRL_SER_IRQ  0x0008    // Serial Interrupt Request
#define GAYLE_CTRL_SER_EN   0x0004    // Serial Enable
#define GAYLE_CTRL_MISC_IRQ 0x0002    // Miscellaneous Interrupt Request
#define GAYLE_CTRL_MISC_EN  0x0001    // Miscellaneous Enable

// GAYLE Power Management Register bits
#define GAYLE_PWR_IDE_PWR   0x8000    // IDE Power Control
#define GAYLE_PWR_RTC_PWR   0x4000    // RTC Power Control
#define GAYLE_PWR_EXP_PWR   0x2000    // Expansion Power Control
#define GAYLE_PWR_PAR_PWR   0x1000    // Parallel Power Control
#define GAYLE_PWR_SER_PWR   0x0800    // Serial Power Control
#define GAYLE_PWR_MISC_PWR  0x0400    // Miscellaneous Power Control
#define GAYLE_PWR_IDE_CLK   0x0200    // IDE Clock Control
#define GAYLE_PWR_RTC_CLK   0x0100    // RTC Clock Control
#define GAYLE_PWR_EXP_CLK   0x0080    // Expansion Clock Control
#define GAYLE_PWR_PAR_CLK   0x0040    // Parallel Clock Control
#define GAYLE_PWR_SER_CLK   0x0020    // Serial Clock Control
#define GAYLE_PWR_MISC_CLK  0x0010    // Miscellaneous Clock Control
#define GAYLE_PWR_IDE_SLEEP 0x0008    // IDE Sleep Mode
#define GAYLE_PWR_RTC_SLEEP 0x0004    // RTC Sleep Mode
#define GAYLE_PWR_EXP_SLEEP 0x0002    // Expansion Sleep Mode
#define GAYLE_PWR_SYS_SLEEP 0x0001    // System Sleep Mode

// GAYLE Interrupt Request Register bits
#define GAYLE_INTREQ_IDE    0x8000    // IDE Interrupt Request
#define GAYLE_INTREQ_RTC    0x4000    // RTC Interrupt Request
#define GAYLE_INTREQ_EXP    0x2000    // Expansion Interrupt Request
#define GAYLE_INTREQ_PAR    0x1000    // Parallel Interrupt Request
#define GAYLE_INTREQ_SER    0x0800    // Serial Interrupt Request
#define GAYLE_INTREQ_MISC   0x0400    // Miscellaneous Interrupt Request
#define GAYLE_INTREQ_IDE_IRQ 0x0200   // IDE IRQ Status
#define GAYLE_INTREQ_RTC_IRQ 0x0100   // RTC IRQ Status
#define GAYLE_INTREQ_EXP_IRQ 0x0080   // Expansion IRQ Status
#define GAYLE_INTREQ_PAR_IRQ 0x0040   // Parallel IRQ Status
#define GAYLE_INTREQ_SER_IRQ 0x0020   // Serial IRQ Status
#define GAYLE_INTREQ_MISC_IRQ 0x0010  // Miscellaneous IRQ Status

// GAYLE Interrupt Enable Register bits
#define GAYLE_INTEN_IDE     0x8000    // IDE Interrupt Enable
#define GAYLE_INTEN_RTC     0x4000    // RTC Interrupt Enable
#define GAYLE_INTEN_EXP     0x2000    // Expansion Interrupt Enable
#define GAYLE_INTEN_PAR     0x1000    // Parallel Interrupt Enable
#define GAYLE_INTEN_SER     0x0800    // Serial Interrupt Enable
#define GAYLE_INTEN_MISC    0x0400    // Miscellaneous Interrupt Enable

// GAYLE Configuration Register bits
#define GAYLE_CONFIG_IDE_MODE  0xC000  // IDE Mode (0=Disabled, 1=Primary, 2=Secondary, 3=Both)
#define GAYLE_CONFIG_RTC_MODE  0x3000  // RTC Mode (0=Disabled, 1=Enabled)
#define GAYLE_CONFIG_EXP_MODE  0x0C00  // Expansion Mode (0=Disabled, 1=Enabled)
#define GAYLE_CONFIG_PAR_MODE  0x0300  // Parallel Mode (0=Disabled, 1=Enabled)
#define GAYLE_CONFIG_SER_MODE  0x00C0  // Serial Mode (0=Disabled, 1=Enabled)
#define GAYLE_CONFIG_MISC_MODE 0x0030  // Miscellaneous Mode (0=Disabled, 1=Enabled)
#define GAYLE_CONFIG_CHIPSET   0x000C  // Chipset Configuration (0=OCS, 1=ECS, 2=AGA)
#define GAYLE_CONFIG_MODEL     0x0003  // Model Configuration (0=A500, 1=A600, 2=A1200)

// GAYLE ID Register bits
#define GAYLE_ID_MANUFACTURER 0xFF00  // Manufacturer ID
#define GAYLE_ID_PART_NUMBER  0x00FF  // Part Number

// GAYLE Revision Register bits
#define GAYLE_REVISION_MAJOR  0xF0    // Major Revision
#define GAYLE_REVISION_MINOR  0x0F    // Minor Revision

// GAYLE Expansion Control Register bits
#define GAYLE_EXP_IDE_EN      0x8000  // IDE Expansion Enable
#define GAYLE_EXP_RTC_EN      0x4000  // RTC Expansion Enable
#define GAYLE_EXP_EXP_EN      0x2000  // Expansion Enable
#define GAYLE_EXP_PAR_EN      0x1000  // Parallel Expansion Enable
#define GAYLE_EXP_SER_EN      0x0800  // Serial Expansion Enable
#define GAYLE_EXP_MISC_EN     0x0400  // Miscellaneous Expansion Enable
#define GAYLE_EXP_IDE_IRQEN   0x0200  // IDE Interrupt Enable
#define GAYLE_EXP_RTC_IRQEN   0x0100  // RTC Interrupt Enable
#define GAYLE_EXP_EXP_IRQEN   0x0080  // Expansion Interrupt Enable
#define GAYLE_EXP_PAR_IRQEN   0x0040  // Parallel Interrupt Enable
#define GAYLE_EXP_SER_IRQEN   0x0020  // Serial Interrupt Enable
#define GAYLE_EXP_MISC_IRQEN  0x0010  // Miscellaneous Interrupt Enable

// GAYLE-specific functions
extern uint16_t gayle_read_register(uint32_t addr);
extern void gayle_write_register(uint32_t addr, uint16_t value);
extern uint8_t gayle_ide_read_data(void);
extern void gayle_ide_write_data(uint8_t data);
extern uint8_t gayle_ide_read_status(void);
extern void gayle_ide_write_command(uint8_t cmd);
extern void gayle_set_interrupt_enable(uint16_t mask);
extern void gayle_clear_interrupt_request(uint16_t mask);
extern uint16_t gayle_get_interrupt_status(void);
extern void gayle_reset_devices(void);
extern uint16_t gayle_get_chip_revision(void);
extern void gayle_set_configuration(uint16_t config);
extern uint16_t gayle_get_configuration(void);
extern void gayle_power_management(uint16_t power_ctrl);

#endif // GAYLE_H