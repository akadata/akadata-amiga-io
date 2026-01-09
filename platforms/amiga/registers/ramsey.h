/*
 * SPDX-License-Identifier: MIT
 * 
 * RAMSEY chip register definitions for Amiga
 * Based on Ramsey specification document and Amiga Hardware Reference
 * Addresses: Memory control registers for A4000/A3000
 */

#ifndef RAMSEY_H
#define RAMSEY_H

#include "amiga_custom_chips.h"

// RAMSEY base address (A4000/A3000 specific)
#define RAMSEY_BASE           0xDD0000  // RAMSEY chip base address
#define RAMSEY_CTRL           0xDD0000  // RAMSEY Control Register
#define RAMSEY_REVISION       0xDD0002  // RAMSEY Revision Register
#define RAMSEY_CONFIG         0xDD0004  // RAMSEY Configuration Register
#define RAMSEY_REFRESH        0xDD0006  // RAMSEY Refresh Control Register
#define RAMSEY_DRAM_CTRL      0xDD0008  // DRAM Control Register
#define RAMSEY_CHIPSEL        0xDD000A  // Chip Select Control Register
#define RAMSEY_ID             0xDD000C  // RAMSEY Chip ID Register
#define RAMSEY_TEST           0xDD000E  // RAMSEY Test Register

// RAMSEY Control Register bits
#define RAMSEY_CTRL_CHIPRST   0x8000  // Chip Reset Control
#define RAMSEY_CTRL_MEMRST    0x4000  // Memory Reset Control
#define RAMSEY_CTRL_CLKRST    0x2000  // Clock Reset Control
#define RAMSEY_CTRL_BUSRST    0x1000  // Bus Reset Control
#define RAMSEY_CTRL_CHIPEN    0x0800  // Chip Enable Control
#define RAMSEY_CTRL_MEMEN     0x0400  // Memory Enable Control
#define RAMSEY_CTRL_CLKEN     0x0200  // Clock Enable Control
#define RAMSEY_CTRL_BUSEN     0x0100  // Bus Enable Control
#define RAMSEY_CTRL_CHIPSLP   0x0080  // Chip Sleep Control
#define RAMSEY_CTRL_MEMSLP    0x0040  // Memory Sleep Control
#define RAMSEY_CTRL_CLKSLP    0x0020  // Clock Sleep Control
#define RAMSEY_CTRL_BUSSLP    0x0010  // Bus Sleep Control
#define RAMSEY_CTRL_CHIPCFG   0x0008  // Chip Configuration
#define RAMSEY_CTRL_MEMCFG    0x0004  // Memory Configuration
#define RAMSEY_CTRL_CLKCFG    0x0002  // Clock Configuration
#define RAMSEY_CTRL_BUSCFG    0x0001  // Bus Configuration

// RAMSEY Configuration Register bits
#define RAMSEY_CFG_RAMSIZE    0xF000  // RAM Size Configuration (0=512K, 1=1M, 2=2M, 3=4M, 4=8M)
#define RAMSEY_CFG_RAMTYPE    0x0F00  // RAM Type Configuration (0=FPM, 1=EDO, 2=SDRAM)
#define RAMSEY_CFG_CLKTYPE    0x00F0  // Clock Type Configuration (0=28MHz, 1=28.375MHz, 2=28.636MHz)
#define RAMSEY_CFG_BUSWIDTH   0x000F  // Bus Width Configuration (0=8bit, 1=16bit, 2=32bit)

// RAMSEY Refresh Control Register bits
#define RAMSEY_REF_COUNT      0xFF00  // Refresh Counter Value
#define RAMSEY_REF_ENABLE     0x0080  // Refresh Enable
#define RAMSEY_REF_MODE       0x0040  // Refresh Mode (0=Normal, 1=Fast)
#define RAMSEY_REF_SPEED      0x003F  // Refresh Speed Configuration

// RAMSEY DRAM Control Register bits
#define RAMSEY_DRAM_CASLAT    0xC000  // CAS Latency (0=2, 1=3, 2=4 cycles)
#define RAMSEY_DRAM_RASLAT    0x3000  // RAS Latency (0=2, 1=3, 2=4 cycles)
#define RAMSEY_DRAM_PRECHARGE 0x0800  // Precharge Time
#define RAMSEY_DRAM_ACTIVATE  0x0400  // Activate Time
#define RAMSEY_DRAM_WRITE     0x0200  // Write Recovery Time
#define RAMSEY_DRAM_REFRESH   0x0100  // Refresh Cycle Time
#define RAMSEY_DRAM_BURST     0x00C0  // Burst Mode (0=1, 1=2, 2=4, 3=8 beats)
#define RAMSEY_DRAM_TYPE      0x0020  // DRAM Type (0=FPM, 1=EDO)
#define RAMSEY_DRAM_WIDTH     0x0010  // DRAM Width (0=8bit, 1=16bit)
#define RAMSEY_DRAM_BANKS     0x000C  // Number of Banks (0=2, 1=4, 2=8)
#define RAMSEY_DRAM_PAGESIZE  0x0003  // Page Size (0=256, 1=512, 2=1024, 3=2048)

// RAMSEY Chip Select Control Register bits
#define RAMSEY_CS_CHIP0       0x8000  // Chip Select 0 Enable
#define RAMSEY_CS_CHIP1       0x4000  // Chip Select 1 Enable
#define RAMSEY_CS_CHIP2       0x2000  // Chip Select 2 Enable
#define RAMSEY_CS_CHIP3       0x1000  // Chip Select 3 Enable
#define RAMSEY_CS_FAST0       0x0800  // Fast RAM 0 Enable
#define RAMSEY_CS_FAST1       0x0400  // Fast RAM 1 Enable
#define RAMSEY_CS_FAST2       0x0200  // Fast RAM 2 Enable
#define RAMSEY_CS_FAST3       0x0100  // Fast RAM 3 Enable
#define RAMSEY_CS_SLOW0       0x0080  // Slow RAM 0 Enable
#define RAMSEY_CS_SLOW1       0x0040  // Slow RAM 1 Enable
#define RAMSEY_CS_SLOW2       0x0020  // Slow RAM 2 Enable
#define RAMSEY_CS_SLOW3       0x0010  // Slow RAM 3 Enable
#define RAMSEY_CS_ROM0        0x0008  // ROM 0 Enable
#define RAMSEY_CS_ROM1        0x0004  // ROM 1 Enable
#define RAMSEY_CS_ROM2        0x0002  // ROM 2 Enable
#define RAMSEY_CS_ROM3        0x0001  // ROM 3 Enable

// RAMSEY ID Register bits
#define RAMSEY_ID_MANUFACTURER 0xFF00  // Manufacturer ID
#define RAMSEY_ID_PART_NUMBER  0x00FF  // Part Number

// RAMSEY Revision Register bits
#define RAMSEY_REV_MAJOR       0xF0    // Major Revision
#define RAMSEY_REV_MINOR       0x0F    // Minor Revision

// RAMSEY Test Register bits
#define RAMSEY_TEST_PATTERN    0xFF00  // Test Pattern
#define RAMSEY_TEST_ENABLE     0x0080  // Test Enable
#define RAMSEY_TEST_MODE       0x0040  // Test Mode
#define RAMSEY_TEST_LOOP       0x0020  // Test Loop
#define RAMSEY_TEST_ERROR      0x0010  // Test Error Indicator
#define RAMSEY_TEST_PASS       0x0008  // Test Pass Indicator
#define RAMSEY_TEST_FAIL       0x0004  // Test Fail Indicator
#define RAMSEY_TEST_DONE       0x0002  // Test Done Indicator
#define RAMSEY_TEST_START      0x0001  // Test Start Control

// RAMSEY-specific functions
extern uint16_t ramsey_read_register(uint32_t addr);
extern void ramsey_write_register(uint32_t addr, uint16_t value);
extern void ramsey_set_memory_config(uint16_t config);
extern uint16_t ramsey_get_memory_config(void);
extern void ramsey_set_refresh_rate(uint16_t rate);
extern uint16_t ramsey_get_refresh_rate(void);
extern void ramsey_set_dram_timing(uint16_t timing);
extern uint16_t ramsey_get_dram_timing(void);
extern void ramsey_set_chip_select(uint16_t cs_mask);
extern uint16_t ramsey_get_chip_select(void);
extern void ramsey_reset(void);
extern uint16_t ramsey_get_revision(void);
extern uint16_t ramsey_get_id(void);
extern void ramsey_run_self_test(void);
extern uint16_t ramsey_get_test_result(void);

// RAMSEY Memory Size Constants
#define RAMSEY_MEM_512K       0x0000  // 512KB Memory
#define RAMSEY_MEM_1M         0x1000  // 1MB Memory
#define RAMSEY_MEM_2M         0x2000  // 2MB Memory
#define RAMSEY_MEM_4M         0x3000  // 4MB Memory
#define RAMSEY_MEM_8M         0x4000  // 8MB Memory
#define RAMSEY_MEM_16M        0x5000  // 16MB Memory
#define RAMSEY_MEM_32M        0x6000  // 32MB Memory
#define RAMSEY_MEM_64M        0x7000  // 64MB Memory
#define RAMSEY_MEM_128M       0x8000  // 128MB Memory
#define RAMSEY_MEM_256M       0x9000  // 256MB Memory

// RAMSEY Memory Type Constants
#define RAMSEY_TYPE_FPM       0x0000  // Fast Page Mode DRAM
#define RAMSEY_TYPE_EDO       0x0100  // Extended Data Out DRAM
#define RAMSEY_TYPE_SDRAM     0x0200  // Synchronous DRAM

// RAMSEY Clock Type Constants
#define RAMSEY_CLK_28MHZ      0x0000  // 28.000 MHz Clock
#define RAMSEY_CLK_PAL        0x0010  // 28.375 MHz Clock (PAL)
#define RAMSEY_CLK_NTSC       0x0020  // 28.636 MHz Clock (NTSC)

// RAMSEY Bus Width Constants
#define RAMSEY_BUS_8BIT       0x0000  // 8-bit Bus Width
#define RAMSEY_BUS_16BIT      0x0001  // 16-bit Bus Width
#define RAMSEY_BUS_32BIT      0x0002  // 32-bit Bus Width

// RAMSEY CAS Latency Constants
#define RAMSEY_CAS_2CYCLES    0x0000  // 2-cycle CAS Latency
#define RAMSEY_CAS_3CYCLES    0x4000  // 3-cycle CAS Latency
#define RAMSEY_CAS_4CYCLES    0x8000  // 4-cycle CAS Latency

// RAMSEY Burst Mode Constants
#define RAMSEY_BURST_1        0x0000  // Burst Length 1
#define RAMSEY_BURST_2        0x0040  // Burst Length 2
#define RAMSEY_BURST_4        0x0080  // Burst Length 4
#define RAMSEY_BURST_8        0x00C0  // Burst Length 8

#endif // RAMSEY_H