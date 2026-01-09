// SPDX-License-Identifier: MIT
// Main Amiga custom chip register definitions header
// Includes all individual chip register definitions
// Based on Amiga Hardware Reference Manual (ADCD 2.1)

#ifndef AMIGA_CUSTOM_CHIPS_H
#define AMIGA_CUSTOM_CHIPS_H

// Include all individual chip headers
#include "agnus.h"
#include "paula.h"
#include "blitter.h"
#include "denise.h"
#include "cia.h"

// Define base addresses for convenience
#ifndef CUSTOM_CHIP_BASE
#define CUSTOM_CHIP_BASE 0xDFF000
#endif

#ifndef CIAA_BASE
#define CIAA_BASE        0xBFE001
#endif

#ifndef CIAB_BASE
#define CIAB_BASE        0xBFD000
#endif

// Common register aliases for easier access
#ifndef CUSTOM_BASE
#define CUSTOM_BASE CUSTOM_CHIP_BASE
#endif

// Define custom chip register range
#ifndef CUSTOM_CHIP_START
#define CUSTOM_CHIP_START 0xDFF000
#endif

#ifndef CUSTOM_CHIP_END
#define CUSTOM_CHIP_END   0xDFFFFF
#endif

#ifndef CUSTOM_CHIP_SIZE
#define CUSTOM_CHIP_SIZE  (CUSTOM_CHIP_END - CUSTOM_CHIP_START + 1)
#endif

// Define CIA register ranges
#ifndef CIAA_START
#define CIAA_START 0xBFE001
#endif

#ifndef CIAA_END
#define CIAA_END   0xBFEF01
#endif

#ifndef CIAB_START
#define CIAB_START 0xBFD000
#endif

#ifndef CIAB_END
#define CIAB_END   0xBFDF00
#endif

// Common bit definitions used across chips (only if not already defined)
#ifndef BIT0
#define BIT0  0x0001
#endif
#ifndef BIT1
#define BIT1  0x0002
#endif
#ifndef BIT2
#define BIT2  0x0004
#endif
#ifndef BIT3
#define BIT3  0x0008
#endif
#ifndef BIT4
#define BIT4  0x0010
#endif
#ifndef BIT5
#define BIT5  0x0020
#endif
#ifndef BIT6
#define BIT6  0x0040
#endif
#ifndef BIT7
#define BIT7  0x0080
#endif
#ifndef BIT8
#define BIT8  0x0100
#endif
#ifndef BIT9
#define BIT9  0x0200
#endif
#ifndef BIT10
#define BIT10 0x0400
#endif
#ifndef BIT11
#define BIT11 0x0800
#endif
#ifndef BIT12
#define BIT12 0x1000
#endif
#ifndef BIT13
#define BIT13 0x2000
#endif
#ifndef BIT14
#define BIT14 0x4000
#endif
#ifndef BIT15
#define BIT15 0x8000
#endif

// Common register access macros (only if not already defined)
#ifndef CUSTOM_REG_OFFSET
#define CUSTOM_REG_OFFSET(reg_addr) ((reg_addr) - CUSTOM_CHIP_BASE)
#endif

#ifndef CIAA_REG_OFFSET
#define CIAA_REG_OFFSET(reg_addr)   ((reg_addr) - CIAA_BASE)
#endif

#ifndef CIAB_REG_OFFSET
#define CIAB_REG_OFFSET(reg_addr)   ((reg_addr) - CIAB_BASE)
#endif

#endif // AMIGA_CUSTOM_CHIPS_H
