/*
 * SPDX-License-Identifier: MIT
 * 
 * Amiga Model-Specific Definitions
 * Defines register availability and capabilities for different Amiga models
 */

#ifndef AMIGA_MODELS_H
#define AMIGA_MODELS_H

#include "../registers/amiga_custom_chips.h"

// Amiga Model IDs
#define AMIGA_MODEL_A500      0x0001
#define AMIGA_MODEL_A1000     0x0002
#define AMIGA_MODEL_A2000     0x0004
#define AMIGA_MODEL_A500PLUS  0x0008
#define AMIGA_MODEL_A600      0x0010
#define AMIGA_MODEL_A1200     0x0020
#define AMIGA_MODEL_A3000     0x0040
#define AMIGA_MODEL_A4000     0x0080
#define AMIGA_MODEL_CDTV      0x0100
#define AMIGA_MODEL_CD32      0x0200

// Chip Set Identifiers
#define CHIPSET_OCS           0x0001  // Original Chip Set
#define CHIPSET_ECS           0x0002  // Enhanced Chip Set
#define CHIPSET_AGA           0x0004  // Advanced Graphics Architecture

// Memory Sizes (in bytes)
#define A500_CHIP_RAM_SIZE    (512 * 1024)      // 512KB
#define A500_SLOW_RAM_SIZE    (512 * 1024)      // 512KB trapdoor
#define A500_FAST_RAM_SIZE    0                 // None standard

#define A1000_CHIP_RAM_SIZE   (512 * 1024)      // 512KB
#define A1000_FAST_RAM_SIZE   0                 // None standard

#define A2000_CHIP_RAM_SIZE   (1024 * 1024)     // 1MB standard
#define A2000_SLOW_RAM_SIZE   (1536 * 1024)     // 1.5MB trapdoor
#define A2000_FAST_RAM_SIZE   0                 // None standard

#define A500PLUS_CHIP_RAM_SIZE (1024 * 1024)    // 1MB standard
#define A500PLUS_FAST_RAM_SIZE 0                // None standard

#define A600_CHIP_RAM_SIZE    (2 * 1024 * 1024) // 2MB standard
#define A600_SLOW_RAM_SIZE    0                 // None
#define A600_FAST_RAM_SIZE    (8 * 1024 * 1024) // Up to 8MB

#define A1200_CHIP_RAM_SIZE   (2 * 1024 * 1024) // 2MB standard
#define A1200_SLOW_RAM_SIZE   0                 // None
#define A1200_FAST_RAM_SIZE   (8 * 1024 * 1024) // Up to 8MB

#define A3000_CHIP_RAM_SIZE   (2 * 1024 * 1024) // 2MB standard
#define A3000_FAST_RAM_SIZE   (8 * 1024 * 1024) // Up to 8MB

#define A4000_CHIP_RAM_SIZE   (8 * 1024 * 1024) // Up to 8MB standard
#define A4000_FAST_RAM_SIZE   (32 * 1024 * 1024) // Up to 32MB

// Model-Specific Register Availability

// A500 (OCS)
#define A500_HAS_ECS_REGS     0
#define A500_HAS_AGA_REGS     0
#define A500_MAX_BITPLANES    6
#define A500_MAX_SPRITES      8
#define A500_MAX_AUDIO_CHANS  4
#define A500_CHIP_REVISION    0xF8  // Original OCS

// A1000 (OCS)
#define A1000_HAS_ECS_REGS    0
#define A1000_HAS_AGA_REGS    0
#define A1000_MAX_BITPLANES   6
#define A1000_MAX_SPRITES     8
#define A1000_MAX_AUDIO_CHANS 4
#define A1000_CHIP_REVISION   0xFC  // A1000 specific

// A2000 (OCS/ECS)
#define A2000_HAS_ECS_REGS    1  // ECS Agnus available
#define A2000_HAS_AGA_REGS    0
#define A2000_MAX_BITPLANES   6
#define A2000_MAX_SPRITES     8
#define A2000_MAX_AUDIO_CHANS 4
#define A2000_CHIP_REVISION   0xF8  // ECS Agnus

// A500+ (ECS)
#define A500PLUS_HAS_ECS_REGS 1
#define A500PLUS_HAS_AGA_REGS 0
#define A500PLUS_MAX_BITPLANES 6
#define A500PLUS_MAX_SPRITES  8
#define A500PLUS_MAX_AUDIO_CHANS 4
#define A500PLUS_CHIP_REVISION 0xF8  // ECS

// A600 (ECS)
#define A600_HAS_ECS_REGS     1
#define A600_HAS_AGA_REGS     0
#define A600_MAX_BITPLANES    6
#define A600_MAX_SPRITES      8
#define A600_MAX_AUDIO_CHANS  4
#define A600_CHIP_REVISION    0xF8  // ECS

// A1200 (AGA)
#define A1200_HAS_ECS_REGS    1
#define A1200_HAS_AGA_REGS    1
#define A1200_MAX_BITPLANES   8
#define A1200_MAX_SPRITES     8
#define A1200_MAX_AUDIO_CHANS 4
#define A1200_CHIP_REVISION   0xFB  // AGA Agnus

// A3000 (ECS/AGA)
#define A3000_HAS_ECS_REGS    1
#define A3000_HAS_AGA_REGS    1  // Some variants
#define A3000_MAX_BITPLANES   8  // With AGA
#define A3000_MAX_SPRITES     8
#define A3000_MAX_AUDIO_CHANS 4
#define A3000_CHIP_REVISION   0xFB  // AGA Agnus

// A4000 (AGA)
#define A4000_HAS_ECS_REGS    1
#define A4000_HAS_AGA_REGS    1
#define A4000_MAX_BITPLANES   8
#define A4000_MAX_SPRITES     8
#define A4000_MAX_AUDIO_CHANS 4
#define A4000_CHIP_REVISION   0xFB  // AGA Agnus

// Model-Specific Register Definitions

// A500/A2000 OCS Registers
#if defined(CONFIG_A500) || defined(CONFIG_A2000)
#define HAS_VARBEAMEN         0  // No variable beam counters
#define HAS_DUAL              0  // No dual mode
#define HAS_SUPER_HIREZ      0  // No super hires
#define MAX_HORIZ_RES        640  // Max horizontal resolution
#define MAX_VERT_RES         512  // Max vertical resolution
#endif

// A600/A1200 ECS Registers
#if defined(CONFIG_A600) || defined(CONFIG_A1200)
#define HAS_VARBEAMEN         1  // Variable beam counters available
#define HAS_DUAL              1  // Dual mode available
#define HAS_SUPER_HIREZ      1  // Super hires available
#define MAX_HORIZ_RES        1280 // Max horizontal resolution
#define MAX_VERT_RES         512  // Max vertical resolution
#endif

// A4000 AGA Registers
#if defined(CONFIG_A4000)
#define HAS_VARBEAMEN         1  // Variable beam counters available
#define HAS_DUAL              1  // Dual mode available
#define HAS_SUPER_HIREZ      1  // Super hires available
#define HAS_ULTRA_HIREZ      1  // Ultra hires available
#define MAX_HORIZ_RES        2560 // Max horizontal resolution
#define MAX_VERT_RES         1024 // Max vertical resolution
#endif

// Video Mode Capabilities by Model
#define A500_VIDEO_MODES      (VIDEO_MODE_LORES | VIDEO_MODE_HIRES | VIDEO_MODE_NTSC | VIDEO_MODE_PAL | VIDEO_MODE_INTERLACE)
#define A600_VIDEO_MODES      (A500_VIDEO_MODES | VIDEO_MODE_SUPER)
#define A1200_VIDEO_MODES     (A600_VIDEO_MODES | VIDEO_MODE_UHRES)
#define A4000_VIDEO_MODES     (A1200_VIDEO_MODES)

// Audio Capabilities by Model
#define A500_AUDIO_CAPS       (AUDIO_CHANNEL_8BIT | AUDIO_CHANNEL_PCM | AUDIO_CHANNEL_MOD)
#define A1200_AUDIO_CAPS      (A500_AUDIO_CAPS | AUDIO_CHANNEL_14BIT)  // With specific configurations
#define A4000_AUDIO_CAPS      (A1200_AUDIO_CAPS)

// Enhanced Register Availability Macros
#define MODEL_HAS_ECS_FEATURES(model) \
    (((model) == AMIGA_MODEL_A2000) || \
     ((model) == AMIGA_MODEL_A500PLUS) || \
     ((model) == AMIGA_MODEL_A600) || \
     ((model) == AMIGA_MODEL_A1200) || \
     ((model) == AMIGA_MODEL_A3000) || \
     ((model) == AMIGA_MODEL_A4000))

#define MODEL_HAS_AGA_FEATURES(model) \
    (((model) == AMIGA_MODEL_A1200) || \
     ((model) == AMIGA_MODEL_A3000) || \
     ((model) == AMIGA_MODEL_A4000))

#define MODEL_MAX_BITPLANES(model) \
    (((model) == AMIGA_MODEL_A500) ? 6 : \
     ((model) == AMIGA_MODEL_A1000) ? 6 : \
     ((model) == AMIGA_MODEL_A2000) ? 6 : \
     ((model) == AMIGA_MODEL_A500PLUS) ? 6 : \
     ((model) == AMIGA_MODEL_A600) ? 6 : \
     ((model) == AMIGA_MODEL_A1200) ? 8 : \
     ((model) == AMIGA_MODEL_A3000) ? 8 : \
     ((model) == AMIGA_MODEL_A4000) ? 8 : 6)

#define MODEL_CHIP_RAM_SIZE(model) \
    (((model) == AMIGA_MODEL_A500) ? A500_CHIP_RAM_SIZE : \
     ((model) == AMIGA_MODEL_A1000) ? A1000_CHIP_RAM_SIZE : \
     ((model) == AMIGA_MODEL_A2000) ? A2000_CHIP_RAM_SIZE : \
     ((model) == AMIGA_MODEL_A500PLUS) ? A500PLUS_CHIP_RAM_SIZE : \
     ((model) == AMIGA_MODEL_A600) ? A600_CHIP_RAM_SIZE : \
     ((model) == AMIGA_MODEL_A1200) ? A1200_CHIP_RAM_SIZE : \
     ((model) == AMIGA_MODEL_A3000) ? A3000_CHIP_RAM_SIZE : \
     ((model) == AMIGA_MODEL_A4000) ? A4000_CHIP_RAM_SIZE : 0)

// Model-specific register access functions
static inline int model_supports_register(uint16_t model_id, uint32_t reg_addr) {
    // Check if register is in custom chip range
    if (reg_addr < CUSTOM_CHIP_START || reg_addr > CUSTOM_CHIP_END) {
        return 0;
    }
    
    // Check model-specific register availability
    switch (model_id) {
        case AMIGA_MODEL_A500:
        case AMIGA_MODEL_A1000:
        case AMIGA_MODEL_A2000:
            // OCS models - no ECS or AGA registers
            if (reg_addr >= 0xDFF1C0 && reg_addr <= 0xDFF1FF) {  // ECS registers
                return 0;
            }
            if (reg_addr == BPLCON3 || reg_addr == BPLCON4 || reg_addr == CLXCON2) {  // AGA registers
                return 0;
            }
            break;
            
        case AMIGA_MODEL_A500PLUS:
        case AMIGA_MODEL_A600:
            // ECS models - have ECS registers but not AGA color registers
            if (reg_addr == BPLCON4 || reg_addr == CLXCON2) {  // AGA registers
                return 0;
            }
            break;
            
        case AMIGA_MODEL_A1200:
        case AMIGA_MODEL_A3000:
        case AMIGA_MODEL_A4000:
            // AGA models - have all registers
            break;
    }
    
    return 1;  // Register is supported by this model
}

// Model identification functions
static inline uint16_t get_chipset_features(uint16_t model_id) {
    uint16_t features = 0;
    
    if (MODEL_HAS_ECS_FEATURES(model_id)) {
        features |= CHIPSET_ECS;
    }
    
    if (MODEL_HAS_AGA_FEATURES(model_id)) {
        features |= CHIPSET_AGA;
    } else {
        features |= CHIPSET_OCS;  // Default to OCS if not AGA
    }
    
    return features;
}

// Common model detection macro
#define IS_AGA_MODEL(model) (MODEL_HAS_AGA_FEATURES(model))
#define IS_ECS_MODEL(model) (MODEL_HAS_ECS_FEATURES(model))
#define IS_OCS_MODEL(model) (!IS_ECS_MODEL(model))

#endif // AMIGA_MODELS_H