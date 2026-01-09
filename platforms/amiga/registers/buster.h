/*
 * SPDX-License-Identifier: MIT
 * 
 * BUSTER chip register definitions for Amiga
 * Based on Buster specification document and Amiga Hardware Reference
 * Addresses: Memory control registers for A3000/A4000
 */

#ifndef BUSTER_H
#define BUSTER_H

#include "amiga_custom_chips.h"

// BUSTER base address (A3000/A4000 specific)
#define BUSTER_BASE           0xDD0000  // BUSTER chip base address
#define BUSTER_CTRL           0xDD0000  // BUSTER Control Register
#define BUSTER_REVISION       0xDD0002  // BUSTER Revision Register
#define BUSTER_CONFIG         0xDD0004  // BUSTER Configuration Register
#define BUSTER_REFRESH        0xDD0006  // BUSTER Refresh Control Register
#define BUSTER_DRAM_CTRL      0xDD0008  // DRAM Control Register
#define BUSTER_CHIPSEL        0xDD000A  // Chip Select Control Register
#define BUSTER_ID             0xDD000C  // BUSTER Chip ID Register
#define BUSTER_TEST           0xDD000E  // BUSTER Test Register

// BUSTER Control Register bits
#define BUSTER_CTRL_CHIPRST   0x8000  // Chip Reset Control
#define BUSTER_CTRL_MEMRST    0x4000  // Memory Reset Control
#define BUSTER_CTRL_CLKRST    0x2000  // Clock Reset Control
#define BUSTER_CTRL_BUSRST    0x1000  // Bus Reset Control
#define BUSTER_CTRL_CHIPEN    0x0800  // Chip Enable Control
#define BUSTER_CTRL_MEMEN     0x0400  // Memory Enable Control
#define BUSTER_CTRL_CLKEN     0x0200  // Clock Enable Control
#define BUSTER_CTRL_BUSEN     0x0100  // Bus Enable Control
#define BUSTER_CTRL_CHIPSLP   0x0080  // Chip Sleep Control
#define BUSTER_CTRL_MEMSLP    0x0040  // Memory Sleep Control
#define BUSTER_CTRL_CLKSLP    0x0020  // Clock Sleep Control
#define BUSTER_CTRL_BUSSLP    0x0010  // Bus Sleep Control
#define BUSTER_CTRL_CHIPCFG   0x0008  // Chip Configuration
#define BUSTER_CTRL_MEMCFG    0x0004  // Memory Configuration
#define BUSTER_CTRL_CLKCFG    0x0002  // Clock Configuration
#define BUSTER_CTRL_BUSCFG    0x0001  // Bus Configuration

// BUSTER Configuration Register bits
#define BUSTER_CFG_RAMSIZE    0xF000  // RAM Size Configuration (0=512K, 1=1M, 2=2M, 3=4M, 4=8M)
#define BUSTER_CFG_RAMTYPE    0x0F00  // RAM Type Configuration (0=FPM, 1=EDO, 2=SDRAM)
#define BUSTER_CFG_CLKTYPE    0x00F0  // Clock Type Configuration (0=28MHz, 1=28.375MHz, 2=28.636MHz)
#define BUSTER_CFG_BUSWIDTH   0x000F  // Bus Width Configuration (0=8bit, 1=16bit, 2=32bit)

// BUSTER Refresh Control Register bits
#define BUSTER_REF_COUNT      0xFF00  // Refresh Counter Value
#define BUSTER_REF_ENABLE     0x0080  // Refresh Enable
#define BUSTER_REF_MODE       0x0040  // Refresh Mode (0=Normal, 1=Fast)
#define BUSTER_REF_SPEED      0x003F  // Refresh Speed Configuration

// BUSTER DRAM Control Register bits
#define BUSTER_DRAM_CASLAT    0xC000  // CAS Latency (0=2, 1=3, 2=4 cycles)
#define BUSTER_DRAM_RASLAT    0x3000  // RAS Latency (0=2, 1=3, 2=4 cycles)
#define BUSTER_DRAM_PRECHARGE 0x0800  // Precharge Time
#define BUSTER_DRAM_ACTIVATE  0x0400  // Activate Time
#define BUSTER_DRAM_WRITE     0x0200  // Write Recovery Time
#define BUSTER_DRAM_REFRESH   0x0100  // Refresh Cycle Time
#define BUSTER_DRAM_BURST     0x00C0  // Burst Mode (0=1, 1=2, 2=4, 3=8 beats)
#define BUSTER_DRAM_TYPE      0x0020  // DRAM Type (0=FPM, 1=EDO)
#define BUSTER_DRAM_WIDTH     0x0010  // DRAM Width (0=8bit, 1=16bit)
#define BUSTER_DRAM_BANKS     0x000C  // Number of Banks (0=2, 1=4, 2=8)
#define BUSTER_DRAM_PAGESIZE  0x0003  // Page Size (0=256, 1=512, 2=1024, 3=2048)

// BUSTER Chip Select Control Register bits
#define BUSTER_CS_CHIP0       0x8000  // Chip Select 0 Enable
#define BUSTER_CS_CHIP1       0x4000  // Chip Select 1 Enable
#define BUSTER_CS_CHIP2       0x2000  // Chip Select 2 Enable
#define BUSTER_CS_CHIP3       0x1000  // Chip Select 3 Enable
#define BUSTER_CS_FAST0       0x0800  // Fast RAM 0 Enable
#define BUSTER_CS_FAST1       0x0400  // Fast RAM 1 Enable
#define BUSTER_CS_FAST2       0x0200  // Fast RAM 2 Enable
#define BUSTER_CS_FAST3       0x0100  // Fast RAM 3 Enable
#define BUSTER_CS_SLOW0       0x0080  // Slow RAM 0 Enable
#define BUSTER_CS_SLOW1       0x0040  // Slow RAM 1 Enable
#define BUSTER_CS_SLOW2       0x0020  // Slow RAM 2 Enable
#define BUSTER_CS_SLOW3       0x0010  // Slow RAM 3 Enable
#define BUSTER_CS_ROM0        0x0008  // ROM 0 Enable
#define BUSTER_CS_ROM1        0x0004  // ROM 1 Enable
#define BUSTER_CS_ROM2        0x0002  // ROM 2 Enable
#define BUSTER_CS_ROM3        0x0001  // ROM 3 Enable

// BUSTER ID Register bits
#define BUSTER_ID_MANUFACTURER 0xFF00  // Manufacturer ID
#define BUSTER_ID_PART_NUMBER  0x00FF  // Part Number

// BUSTER Revision Register bits
#define BUSTER_REV_MAJOR       0xF0    // Major Revision
#define BUSTER_REV_MINOR       0x0F    // Minor Revision

// BUSTER Test Register bits
#define BUSTER_TEST_PATTERN    0xFF00  // Test Pattern
#define BUSTER_TEST_ENABLE     0x0080  // Test Enable
#define BUSTER_TEST_MODE       0x0040  // Test Mode
#define BUSTER_TEST_LOOP       0x0020  // Test Loop
#define BUSTER_TEST_ERROR      0x0010  // Test Error Indicator
#define BUSTER_TEST_PASS       0x0008  // Test Pass Indicator
#define BUSTER_TEST_FAIL       0x0004  // Test Fail Indicator
#define BUSTER_TEST_DONE       0x0002  // Test Done Indicator
#define BUSTER_TEST_START      0x0001  // Test Start Control

// BUSTER-specific functions
extern uint16_t buster_read_register(uint32_t addr);
extern void buster_write_register(uint32_t addr, uint16_t value);
extern void buster_set_memory_config(uint16_t config);
extern uint16_t buster_get_memory_config(void);
extern void buster_set_refresh_rate(uint16_t rate);
extern uint16_t buster_get_refresh_rate(void);
extern void buster_set_dram_timing(uint16_t timing);
extern uint16_t buster_get_dram_timing(void);
extern void buster_set_chip_select(uint16_t cs_mask);
extern uint16_t buster_get_chip_select(void);
extern void buster_reset(void);
extern uint16_t buster_get_revision(void);
extern uint16_t buster_get_id(void);
extern void buster_run_self_test(void);
extern uint16_t buster_get_test_result(void);

// BUSTER Memory Size Constants
#define BUSTER_MEM_512K       0x0000  // 512KB Memory
#define BUSTER_MEM_1M         0x1000  // 1MB Memory
#define BUSTER_MEM_2M         0x2000  // 2MB Memory
#define BUSTER_MEM_4M         0x3000  // 4MB Memory
#define BUSTER_MEM_8M         0x4000  // 8MB Memory
#define BUSTER_MEM_16M        0x5000  // 16MB Memory
#define BUSTER_MEM_32M        0x6000  // 32MB Memory
#define BUSTER_MEM_64M        0x7000  // 64MB Memory
#define BUSTER_MEM_128M       0x8000  // 128MB Memory
#define BUSTER_MEM_256M       0x9000  // 256MB Memory

// BUSTER Memory Type Constants
#define BUSTER_TYPE_FPM       0x0000  // Fast Page Mode DRAM
#define BUSTER_TYPE_EDO       0x0100  // Extended Data Out DRAM
#define BUSTER_TYPE_SDRAM     0x0200  // Synchronous DRAM

// BUSTER Clock Type Constants
#define BUSTER_CLK_28MHZ      0x0000  // 28.000 MHz Clock
#define BUSTER_CLK_PAL        0x0010  // 28.375 MHz Clock (PAL)
#define BUSTER_CLK_NTSC       0x0020  // 28.636 MHz Clock (NTSC)

// BUSTER Bus Width Constants
#define BUSTER_BUS_8BIT       0x0000  // 8-bit Bus Width
#define BUSTER_BUS_16BIT      0x0001  // 16-bit Bus Width
#define BUSTER_BUS_32BIT      0x0002  // 32-bit Bus Width

// BUSTER CAS Latency Constants
#define BUSTER_CAS_2CYCLES    0x0000  // 2-cycle CAS Latency
#define BUSTER_CAS_3CYCLES    0x4000  // 3-cycle CAS Latency
#define BUSTER_CAS_4CYCLES    0x8000  // 4-cycle CAS Latency

// BUSTER Burst Mode Constants
#define BUSTER_BURST_1        0x0000  // Burst Length 1
#define BUSTER_BURST_2        0x0040  // Burst Length 2
#define BUSTER_BURST_4        0x0080  // Burst Length 4
#define BUSTER_BURST_8        0x00C0  // Burst Length 8

#endif // BUSTER_H