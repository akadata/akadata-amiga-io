/*
 * SPDX-License-Identifier: MIT
 * 
 * GARY chip register definitions for Amiga
 * Based on GARY specification document and Amiga Hardware Reference Manual
 * Addresses: System control and memory management registers
 */

#ifndef GARY_H
#define GARY_H

#include "amiga_custom_chips.h"

// GARY base address (varies by model)
#define GARY_BASE 0xDFF000  // Shared with other custom chips in some models

// GARY register addresses (A2000/A3000 specific)
#define GARY_CSR    0xDE0000  // GARY Control/Status Register
#define GARY_INTEN  0xDE0002  // Interrupt Enable Register
#define GARY_INTREQ 0xDE0004  // Interrupt Request Register
#define GARY_RESET  0xDE0006  // Reset Control Register
#define GARY_CONFIG 0xDE0008  // Configuration Register
#define GARY_SLOTSEL 0xDE000A // Slot Selection Register
#define GARY_ID     0xDE0010  // GARY Chip ID Register
#define GARY_REVISION 0xDE0012 // GARY Revision Register

// GARY Control/Status Register (CSR) bits
#define GARY_CSR_IDE_RST    0x8000  // IDE Reset (active low)
#define GARY_CSR_IDE_EN     0x4000  // IDE Enable
#define GARY_CSR_RTC_PRESENT 0x2000  // RTC Present
#define GARY_CSR_IDE_PRESENT 0x1000  // IDE Present
#define GARY_CSR_MEM_PRESENT 0x0800  // Memory Present
#define GARY_CSR_MEM_TYPE    0x0400  // Memory Type (0=Slow, 1=Fast)
#define GARY_CSR_MEM_SIZE    0x0200  // Memory Size (0=512K, 1=1M)
#define GARY_CSR_CHIPSET     0x0100  // Chipset Type (0=OCS, 1=ECS)
#define GARY_CSR_MODEL       0x0080  // Model Type (0=A2000, 1=A3000)
#define GARY_CSR_RAMSEY      0x0040  // Ramsey Present
#define GARY_CSR_AGNUS       0x0020  // Agnus Present
#define GARY_CSR_DENISE      0x0010  // Denise Present
#define GARY_CSR_PAULA       0x0008  // Paula Present
#define GARY_CSR_CIA         0x0004  // CIA Present
#define GARY_CSR_CUSTOM      0x0002  // Custom Chips Present
#define GARY_CSR_SYSTEM      0x0001  // System OK

// GARY Interrupt Enable Register bits
#define GARY_INTEN_IDE_INT   0x8000  // IDE Interrupt Enable
#define GARY_INTEN_RTC_INT   0x4000  // RTC Interrupt Enable
#define GARY_INTEN_EXP_INT   0x2000  // Expansion Interrupt Enable
#define GARY_INTEN_PAR_INT   0x1000  // Parallel Port Interrupt Enable
#define GARY_INTEN_SER_INT   0x0800  // Serial Port Interrupt Enable
#define GARY_INTEN_MISC_INT  0x0400  // Miscellaneous Interrupt Enable

// GARY Interrupt Request Register bits
#define GARY_INTREQ_IDE_INT  0x8000  // IDE Interrupt Request
#define GARY_INTREQ_RTC_INT  0x4000  // RTC Interrupt Request
#define GARY_INTREQ_EXP_INT  0x2000  // Expansion Interrupt Request
#define GARY_INTREQ_PAR_INT  0x1000  // Parallel Port Interrupt Request
#define GARY_INTREQ_SER_INT  0x0800  // Serial Port Interrupt Request
#define GARY_INTREQ_MISC_INT 0x0400  // Miscellaneous Interrupt Request

// GARY Reset Control Register bits
#define GARY_RESET_IDE_RST   0x8000  // IDE Reset Control
#define GARY_RESET_RTC_RST   0x4000  // RTC Reset Control
#define GARY_RESET_EXP_RST   0x2000  // Expansion Reset Control
#define GARY_RESET_PAR_RST   0x1000  // Parallel Port Reset Control
#define GARY_RESET_SER_RST   0x0800  // Serial Port Reset Control
#define GARY_RESET_MISC_RST  0x0400  // Miscellaneous Reset Control

// GARY Configuration Register bits
#define GARY_CONFIG_IDE_MODE 0xC000  // IDE Mode (0=Disabled, 1=Primary, 2=Secondary, 3=Both)
#define GARY_CONFIG_RTC_MODE 0x3000  // RTC Mode (0=Disabled, 1=Enabled)
#define GARY_CONFIG_EXP_MODE 0x0C00  // Expansion Mode (0=Disabled, 1=Enabled)
#define GARY_CONFIG_PAR_MODE 0x0300  // Parallel Mode (0=Disabled, 1=Enabled)
#define GARY_CONFIG_SER_MODE 0x00C0  // Serial Mode (0=Disabled, 1=Enabled)
#define GARY_CONFIG_MISC_MODE 0x0030  // Miscellaneous Mode (0=Disabled, 1=Enabled)
#define GARY_CONFIG_CHIPSET  0x000C  // Chipset Configuration (0=OCS, 1=ECS, 2=AGA)
#define GARY_CONFIG_MODEL    0x0003  // Model Configuration (0=A2000, 1=A3000, 2=A4000)

// GARY Slot Selection Register bits
#define GARY_SLOTSEL_IDE_SEL 0xF000  // IDE Slot Selection
#define GARY_SLOTSEL_RTC_SEL 0x0F00  // RTC Slot Selection
#define GARY_SLOTSEL_EXP_SEL 0x00F0  // Expansion Slot Selection
#define GARY_SLOTSEL_PAR_SEL 0x000F  // Parallel Slot Selection

// GARY ID Register bits
#define GARY_ID_MANUFACTURER 0xFF00  // Manufacturer ID
#define GARY_ID_PART_NUMBER  0x00FF  // Part Number

// GARY Revision Register bits
#define GARY_REVISION_MAJOR  0xF0    // Major Revision
#define GARY_REVISION_MINOR  0x0F    // Minor Revision

// GARY-specific functions
extern uint16_t gary_read_register(uint32_t addr);
extern void gary_write_register(uint32_t addr, uint16_t value);
extern void gary_set_interrupt_enable(uint16_t mask);
extern void gary_clear_interrupt_request(uint16_t mask);
extern uint16_t gary_get_interrupt_status(void);
extern void gary_reset_devices(void);
extern uint16_t gary_get_chip_revision(void);
extern void gary_set_configuration(uint16_t config);
extern uint16_t gary_get_configuration(void);

#endif // GARY_H