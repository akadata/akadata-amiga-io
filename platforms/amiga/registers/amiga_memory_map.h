// SPDX-License-Identifier: MIT
// Comprehensive Amiga Memory Map and Register Definitions
// Based on Amiga Hardware Reference Manual and HTML documentation
// For use with Raspberry Pi connected to Amiga via PISTORM board
// Consolidated header that includes all existing register definitions
// and adds missing memory map regions

#ifndef AMIGA_MEMORY_MAP_H
#define AMIGA_MEMORY_MAP_H

// Include all existing register headers to maintain compatibility
#include "amiga_custom_chips.h"
#include "agnus.h"
#include "paula.h"
#include "blitter.h"
#include "denise.h"
#include "cia.h"
#include "amiga_models.h"

// ============================================================================
// ADDITIONAL MEMORY MAP REGIONS (not covered in existing headers)
// ============================================================================

// Chip RAM regions
#define CHIP_RAM_START        0x00000000  // Start of Chip RAM
#define CHIP_RAM_512K_END     0x0007FFFF  // End of first 512KB (Agnus)
#define CHIP_RAM_1M_END       0x000FFFFF  // End of 1MB (Fat Agnus)
#define CHIP_RAM_2M_END       0x001FFFFF  // End of 2MB (Big Fat Agnus/Alice)

// Fast RAM regions (Zorro 2)
#define FAST_RAM_LOWER_START  0x00200000  // Lower AutoConfig Zorro 2 Fast RAM
#define FAST_RAM_LOWER_END    0x005FFFFF  // End of lower Fast RAM (4MB)
#define FAST_RAM_UPPER_START  0x00600000  // Upper AutoConfig Zorro 2 Fast RAM
#define FAST_RAM_UPPER_END    0x009FFFFF  // End of upper Fast RAM (4MB)

// IO Expansion regions
#define IO_EXPANSION_START    0x00A00000  // Zorro 2 IO expansion
#define IO_EXPANSION_END      0x00A7FFFF  // End of IO expansion

// Additional CIA registers region
#define CIA_REGION_START      0x00BF0000  // CIA registers start
#define CIA_REGION_END        0x00BFFFFF  // CIA registers end (64KB)

// Custom chip registers region
#define CUSTOM_CHIP_START     0x00DFC000  // Custom chip registers start
#define CUSTOM_CHIP_END       0x00DFFFFF  // Custom chip registers end (16KB)

// ROM regions
#define ROM_EXPANSION_START   0x00E00000  // ROM expansion
#define ROM_EXPANSION_END     0x00E7FFFF  // End of ROM expansion
#define ROM_KICKSTART_START   0x00F80000  // Kickstart ROM start
#define ROM_KICKSTART_END     0x00FFFFFF  // Kickstart ROM end

// Zorro 3 regions
#define Z3_CHIP_START         0x01000000  // Zorro 3 Chip RAM expansion
#define Z3_CHIP_END           0x017FFFFF  // End of Z3 Chip RAM (8MB)

// Trapdoor Slow RAM (A500)
#define TRAPDOOR_SLOW_START   0x00C00000  // A500 "Trapdoor" Slow RAM start
#define TRAPDOOR_SLOW_END     0x00D7FFFF  // End of trapdoor slow RAM (1.5MB)

// A1200 Clock Port
#define A1200_CLOCK_START     0x00D80000  // A1200 Clock Port start
#define A1200_CLOCK_END       0x00D8FFFF  // End of A1200 Clock Port (64KB)

// IDE Controller (A600/A1200)
#define IDE_CONTROLLER_START  0x00DA0000  // A600/A1200 IDE controller start
#define IDE_CONTROLLER_END    0x00DA3FFF  // End of IDE controller (16KB)

// RealTimeClock
#define RT_CLOCK_START        0x00DC0000  // RealTimeClock start
#define RT_CLOCK_END          0x00DCFFFF  // End of RTC (64KB)

// A3000 SCSI / A4000 IDE / A1200 DMA
#define SCSI_IDE_DMA_START    0x00DD0000  // SCSI/IDE/DMA controller start
#define SCSI_IDE_DMA_END      0x00DDFFFF  // End of controller (64KB)

// Motherboard Resources (A3000/A4000)
#define MOTHERBOARD_RES_START 0x00DE0000  // Motherboard resources start
#define MOTHERBOARD_RES_END   0x00DEFFFF  // End of motherboard resources (64KB)

// CDTV/CD32 Extended ROM
#define CDTV_ROM_START        0x00F00000  // CDTV/CD32 Extended ROM start
#define CDTV_ROM_END          0x00F7FFFF  // End of CDTV ROM (512KB)

// ============================================================================
// UHRES (Ultra High Resolution) Register Addresses (from HTML docs)
// ============================================================================

// These may not be in existing headers, so defining them here if needed
#ifndef SPRHSTRT
#define SPRHSTRT (CUSTOM_BASE + 0x1D0)  // UHRES sprite vertical start
#endif
#ifndef SPRHSTOP
#define SPRHSTOP (CUSTOM_BASE + 0x1D2)  // UHRES sprite vertical stop
#endif
#ifndef BPLHSTRT
#define BPLHSTRT (CUSTOM_BASE + 0x1D4)  // UHRES bitplane vertical start
#endif
#ifndef BPLHSTOP
#define BPLHSTOP (CUSTOM_BASE + 0x1D6)  // UHRES bitplane vertical stop
#endif
#ifndef HHPOSW
#define HHPOSW   (CUSTOM_BASE + 0x1D8)  // DUAL mode hires H beam counter write
#endif
#ifndef HHPOSR
#define HHPOSR   (CUSTOM_BASE + 0x1DA)  // DUAL mode hires H beam counter read
#endif
#ifndef BPLHMOD
#define BPLHMOD  (CUSTOM_BASE + 0x1E6)  // UHRES bitplane modulo
#endif
#ifndef SPRHPTH
#define SPRHPTH  (CUSTOM_BASE + 0x1E8)  // UHRES sprite pointer high
#endif
#ifndef SPRHPTL
#define SPRHPTL  (CUSTOM_BASE + 0x1EA)  // UHRES sprite pointer low
#endif
#ifndef BPLHPTH
#define BPLHPTH  (CUSTOM_BASE + 0x1EC)  // UHRES bitplane pointer high
#endif
#ifndef BPLHPTL
#define BPLHPTL  (CUSTOM_BASE + 0x1EE)  // UHRES bitplane pointer low
#endif
#ifndef SPRHDAT
#define SPRHDAT  (CUSTOM_BASE + 0x078)  // UHRES sprite data identifier
#endif
#ifndef BPLHDAT
#define BPLHDAT  (CUSTOM_BASE + 0x07A)  // UHRES bitplane data identifier
#endif

// Fetch Mode Register (AGA) - may not be in existing headers
#ifndef FMODE
#define FMODE    (CUSTOM_BASE + 0x1FC)  // Fetch mode register
#endif

// No Operation Register
#ifndef NOOP
#define NOOP     (CUSTOM_BASE + 0x1FE)  // No operation/NULL (Copper NOP instruction)
#endif

// Additional ECS Beam / Timing Registers (if not defined elsewhere)
#ifndef HCENTER
#define HCENTER  (CUSTOM_BASE + 0x1E2)  // Horizontal position for Vsync on interlace (ECS)
#endif
#ifndef DIWHIGH
#define DIWHIGH  (CUSTOM_BASE + 0x1E4)  // Display window upper bits (ECS)
#endif

// ============================================================================
// MODEL-SPECIFIC DEFINITIONS
// ============================================================================

// A500-specific definitions
#define A500_MODEL_ID         0x00
#define A500_CHIP_RAM_SIZE    (512 * 1024)   // 512KB standard
#define A500_EXTENDED_CHIP_RAM_SIZE (1024 * 1024) // With trapdoor expansion

// A1200-specific definitions
#define A1200_MODEL_ID        0x01
#define A1200_FAST_RAM_SIZE   (8 * 1024 * 1024)  // Up to 8MB Fast RAM

// A4000-specific definitions
#define A4000_MODEL_ID        0x02
#define A4000_CHIP_RAM_SIZE   (8 * 1024 * 1024)  // Up to 8MB Chip RAM

// Common model identification
#define IS_A500(model_id)     ((model_id) == A500_MODEL_ID)
#define IS_A1200(model_id)    ((model_id) == A1200_MODEL_ID)
#define IS_A4000(model_id)    ((model_id) == A4000_MODEL_ID)

// ============================================================================
// COMMON MACROS FOR REGISTER ACCESS
// ============================================================================

// Macro to check if an address is in custom chip range
#define IS_CUSTOM_CHIP_ADDR(addr) (((addr) >= CUSTOM_CHIP_START) && ((addr) <= CUSTOM_CHIP_END))

// Macro to check if an address is in CIA range
#define IS_CIA_ADDR(addr) (((addr) >= CIA_REGION_START) && ((addr) <= CIA_REGION_END))

// Macro to check if an address is in Chip RAM
#define IS_CHIP_RAM_ADDR(addr) (((addr) >= CHIP_RAM_START) && ((addr) <= CHIP_RAM_2M_END))

// Macro to get offset within custom chip space
#define CUSTOM_OFFSET(addr) ((addr) - CUSTOM_CHIP_START)

// Macro to get offset within CIA space
#define CIA_OFFSET(addr) ((addr) - CIA_REGION_START)

#endif // AMIGA_MEMORY_MAP_H