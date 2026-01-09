/*
 * SPDX-License-Identifier: MIT
 * 
 * Enhanced Amiga Custom Chip Register Definitions
 * Comprehensive header that includes all enhanced register definitions
 * for AGNUS, PAULA, DENISE, and CIA chips
 */

#ifndef ENHANCED_AMIGA_CUSTOM_CHIPS_H
#define ENHANCED_AMIGA_CUSTOM_CHIPS_H

// Include all enhanced register headers
#include "enhanced_agnus.h"
#include "enhanced_paula.h"
#include "enhanced_denise.h"
#include "enhanced_cia.h"

// Additional common definitions for enhanced functionality

// Enhanced Chip Identification
#define AMIGA_CHIPSET_OCS    0x0001  // Original Chip Set
#define AMIGA_CHIPSET_ECS    0x0002  // Enhanced Chip Set
#define AMIGA_CHIPSET_AGA    0x0004  // Advanced Graphics Architecture (AGA)
#define AMIGA_CHIPSET_ALL    0xFFFF  // All chipsets

// Chip Revision Information
#define CHIP_REV_A1000      0xFC    // A1000 chip revision
#define CHIP_REV_A500       0xF8    // A500 chip revision
#define CHIP_REV_A2000      0xF8    // A2000 chip revision
#define CHIP_REV_A3000      0xFA    // A3000 chip revision
#define CHIP_REV_A4000      0xFB    // A4000 chip revision
#define CHIP_REV_A1200      0xFC    // A1200 chip revision
#define CHIP_REV_A600       0xFD    // A600 chip revision

// Memory Configuration Types
#define MEM_CONFIG_CHIP_512K  0x0001  // 512KB Chip RAM
#define MEM_CONFIG_CHIP_1M    0x0002  // 1MB Chip RAM
#define MEM_CONFIG_CHIP_2M    0x0004  // 2MB Chip RAM
#define MEM_CONFIG_CHIP_8M    0x0008  // 8MB Chip RAM (A4000)
#define MEM_CONFIG_FAST_1M    0x0010  // 1MB Fast RAM
#define MEM_CONFIG_FAST_8M    0x0020  // 8MB Fast RAM
#define MEM_CONFIG_SLOW_512K  0x0040  // 512KB Slow RAM
#define MEM_CONFIG_SLOW_1M    0x0080  // 1MB Slow RAM

// Video Mode Capabilities
#define VIDEO_MODE_LORES      0x0001  // Low resolution (320 pixels)
#define VIDEO_MODE_HIRES      0x0002  // High resolution (640 pixels)
#define VIDEO_MODE_SUPER      0x0004  // Super high resolution (1280 pixels)
#define VIDEO_MODE_UHRES      0x0008  // Ultra high resolution (1280+ pixels)
#define VIDEO_MODE_NTSC       0x0010  // NTSC timing
#define VIDEO_MODE_PAL        0x0020  // PAL timing
#define VIDEO_MODE_INTERLACE  0x0040  // Interlaced mode
#define VIDEO_MODE_NONINTERLACE 0x0080  // Non-interlaced mode

// Audio Channel Capabilities
#define AUDIO_CHANNEL_4BIT    0x0001  // 4-bit audio
#define AUDIO_CHANNEL_8BIT    0x0002  // 8-bit audio
#define AUDIO_CHANNEL_14BIT   0x0004  // 14-bit audio (AGA)
#define AUDIO_CHANNEL_PCM     0x0008  // PCM mode
#define AUDIO_CHANNEL_MOD     0x0010  // Modulation mode

// Enhanced DMA Capabilities
#define DMA_CHANNEL_AUDIO     0x000F  // Audio DMA channels (0-3)
#define DMA_CHANNEL_DISK      0x0010  // Disk DMA
#define DMA_CHANNEL_SPRITE    0x0020  // Sprite DMA
#define DMA_CHANNEL_BLITTER   0x0040  // Blitter DMA
#define DMA_CHANNEL_COPPER    0x0080  // Copper DMA
#define DMA_CHANNEL_RASTER    0x0100  // Raster DMA
#define DMA_CHANNEL_MASTER    0x0200  // Master DMA enable
#define DMA_CHANNEL_BLITHOG   0x0400  // Blitter hog CPU
#define DMA_CHANNEL_ALL       0x01FF  // All DMA channels

// Enhanced Interrupt Capabilities
#define INT_LEVEL_1         0x0001  // Level 1 interrupt (software)
#define INT_LEVEL_2         0x0004  // Level 2 interrupt (ports/timers)
#define INT_LEVEL_3         0x0008  // Level 3 interrupt (VBLANK)
#define INT_LEVEL_4         0x0010  // Level 4 interrupt (copper)
#define INT_LEVEL_5         0x0020  // Level 5 interrupt (sprite/duplicate)
#define INT_LEVEL_6         0x0040  // Level 6 interrupt (blitter)
#define INT_LEVEL_7         0x0080  // Level 7 interrupt (audio ports 0-3)
#define INT_LEVEL_8         0x0800  // Level 8 interrupt (raster)
#define INT_LEVEL_9         0x1000  // Level 9 interrupt (disk block)
#define INT_LEVEL_10        0x2000  // Level 10 interrupt (external)
#define INT_LEVEL_11        0x4000  // Level 11 interrupt (master enable)

// Enhanced Bitplane Capabilities
#define BITPLANE_COUNT_0      0x00  // No bitplanes
#define BITPLANE_COUNT_1      0x01  // 1 bitplane
#define BITPLANE_COUNT_2      0x02  // 2 bitplanes
#define BITPLANE_COUNT_3      0x03  // 3 bitplanes
#define BITPLANE_COUNT_4      0x04  // 4 bitplanes
#define BITPLANE_COUNT_5      0x05  // 5 bitplanes
#define BITPLANE_COUNT_6      0x06  // 6 bitplanes
#define BITPLANE_COUNT_7      0x07  // 7 bitplanes (AGA)
#define BITPLANE_COUNT_8      0x08  // 8 bitplanes (AGA)

// Enhanced Sprite Capabilities
#define SPRITE_COUNT_0        0x00  // No sprites
#define SPRITE_COUNT_1        0x01  // 1 sprite
#define SPRITE_COUNT_2        0x02  // 2 sprites
#define SPRITE_COUNT_3        0x03  // 3 sprites
#define SPRITE_COUNT_4        0x04  // 4 sprites
#define SPRITE_COUNT_5        0x05  // 5 sprites
#define SPRITE_COUNT_6        0x06  // 6 sprites
#define SPRITE_COUNT_7        0x07  // 7 sprites
#define SPRITE_COUNT_8        0x08  // 8 sprites

// Enhanced Color Capabilities
#define COLOR_DEPTH_4         0x04  // 4-bit color (16 colors)
#define COLOR_DEPTH_6         0x06  // 6-bit color (64 colors)
#define COLOR_DEPTH_8         0x08  // 8-bit color (256 colors)
#define COLOR_DEPTH_12        0x0C  // 12-bit color (4096 colors - AGA)

// Enhanced Audio Capabilities
#define AUDIO_FREQ_3547HZ     0x00E1  // ~3.5 kHz (period 227)
#define AUDIO_FREQ_7094HZ     0x0070  // ~7.1 kHz (period 112) 
#define AUDIO_FREQ_1419HZ     0x0038  // ~14.2 kHz (period 56)
#define AUDIO_FREQ_2837HZ     0x001C  // ~28.4 kHz (period 28)

// Enhanced Video Timing Modes
#define TIMING_NTSC           0x0001  // NTSC timing
#define TIMING_PAL            0x0002  // PAL timing
#define TIMING_NTSC_HIRES     0x0003  // NTSC HiRes timing
#define TIMING_PAL_HIRES      0x0004  // PAL HiRes timing
#define TIMING_VARIABLE       0x0008  // Variable timing (ECS/AGA)

// Enhanced Blitter Modes
#define BLITTER_MODE_NORMAL   0x0000  // Normal blitting
#define BLITTER_MODE_LINE     0x0001  // Line drawing
#define BLITTER_MODE_FILL     0x0002  // Area filling
#define BLITTER_MODE_AGA      0x0004  // AGA enhanced mode

// Enhanced Copper Modes
#define COPPER_MODE_NORMAL    0x0000  // Normal copper operation
#define COPPER_MODE_DANGEROUS 0x0001  // Dangerous mode (full register access)

// Enhanced Collision Detection Modes
#define COLLISION_MODE_NORMAL 0x0000  // Normal collision detection
#define COLLISION_MODE_AGA    0x0001  // AGA extended collision detection

// Common register access macros
#define CUSTOM_CHIP_READ(addr) (*(volatile uint16_t *)(addr))
#define CUSTOM_CHIP_WRITE(addr, val) (*(volatile uint16_t *)(addr) = (val))

// Safe register access macros with bounds checking
#define SAFE_CUSTOM_READ(addr) \
    (((addr) >= CUSTOM_CHIP_START && (addr) <= CUSTOM_CHIP_END) ? \
     CUSTOM_CHIP_READ(addr) : 0)

#define SAFE_CUSTOM_WRITE(addr, val) \
    do { \
        if ((addr) >= CUSTOM_CHIP_START && (addr) <= CUSTOM_CHIP_END) { \
            CUSTOM_CHIP_WRITE((addr), (val)); \
        } \
    } while(0)

// Enhanced register access functions (for systems that need special handling)
static inline uint16_t enhanced_custom_read(uint32_t addr) {
    if (addr >= CUSTOM_CHIP_START && addr <= CUSTOM_CHIP_END) {
        return CUSTOM_CHIP_READ(addr);
    }
    return 0;
}

static inline void enhanced_custom_write(uint32_t addr, uint16_t val) {
    if (addr >= CUSTOM_CHIP_START && addr <= CUSTOM_CHIP_END) {
        CUSTOM_CHIP_WRITE(addr, val);
    }
}

// Function prototypes for enhanced register access
extern int init_enhanced_registers(void);
extern void cleanup_enhanced_registers(void);
extern uint16_t read_register_safe(uint32_t addr);
extern void write_register_safe(uint32_t addr, uint16_t val);
extern int validate_register_access(uint32_t addr, int is_write);

#endif // ENHANCED_AMIGA_CUSTOM_CHIPS_H