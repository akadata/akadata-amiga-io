/*
 * SPDX-License-Identifier: MIT
 * 
 * Amiga Model Identification Header
 * Based on Amiga Hardware Reference Manual and official documentation
 * Defines stable model identification for register/pinmap work
 * Prevents folklore like "AGA A500" by separating chipset from model
 */

#ifndef AMIGA_MODEL_IDENTIFICATION_H
#define AMIGA_MODEL_IDENTIFICATION_H

// ============================================================================
// AMIGA MODEL ENUMERATIONS
// ============================================================================

// Amiga Model Families
typedef enum {
    AMIGA_MODEL_UNKNOWN = 0,
    AMIGA_MODEL_A500,
    AMIGA_MODEL_A500PLUS,
    AMIGA_MODEL_A600,
    AMIGA_MODEL_A1000,
    AMIGA_MODEL_A1200,
    AMIGA_MODEL_A2000,
    AMIGA_MODEL_A3000,
    AMIGA_MODEL_A4000,
    AMIGA_MODEL_CDTV,
    AMIGA_MODEL_CD32,
    AMIGA_MODEL_LAST
} amiga_model_t;

// Chipset Classes
typedef enum {
    CHIPSET_CLASS_UNKNOWN = 0,
    CHIPSET_CLASS_OCS,      // Original Chip Set
    CHIPSET_CLASS_ECS,      // Enhanced Chip Set
    CHIPSET_CLASS_AGA,      // Advanced Graphics Architecture
    CHIPSET_CLASS_LAST
} chipset_class_t;

// Agnus Generations (capability-based classification)
typedef enum {
    AGNUS_GEN_UNKNOWN = 0,
    AGNUS_GEN_OCS,          // OCS Agnus (512KB addressing)
    AGNUS_GEN_FAT,          // Fat Agnus (1MB addressing)
    AGNUS_GEN_ECS,          // ECS Agnus (2MB addressing)
    AGNUS_GEN_LAST
} agnus_generation_t;

// Chip RAM Classes (based on Agnus capability)
typedef enum {
    CHIPRAM_CLASS_UNKNOWN = 0,
    CHIPRAM_CLASS_512K,     // OCS Agnus limitation
    CHIPRAM_CLASS_1M,       // Fat Agnus capability
    CHIPRAM_CLASS_2M,       // ECS Agnus capability
    CHIPRAM_CLASS_8M,       // AGA Alice capability
    CHIPRAM_CLASS_LAST
} chipram_class_t;

// Denise Classes (video chip classification)
typedef enum {
    DENISE_CLASS_UNKNOWN = 0,
    DENISE_CLASS_OCS,       // OCS Denise (baseline A500/A2000)
    DENISE_CLASS_ECS,       // ECS Denise ("Super Denise" - A500+/A600)
    DENISE_CLASS_NONE,      // No Denise (AGA uses Lisa)
    DENISE_CLASS_LAST
} denise_class_t;

// CIA Clock Classes (nominal timing expectations)
typedef enum {
    CIA_CLOCK_CLASS_UNKNOWN = 0,
    CIA_CLOCK_CLASS_1X,     // OCS/ECS nominal CIA timing (~1MHz)
    CIA_CLOCK_CLASS_2X,     // AGA nominal CIA timing (~2MHz)
    CIA_CLOCK_CLASS_LAST
} cia_clock_class_t;

// Region Standards
typedef enum {
    REGION_UNKNOWN = 0,
    REGION_NTSC,            // NTSC timing (60Hz)
    REGION_PAL,             // PAL timing (50Hz)
    REGION_LAST
} region_standard_t;

// ============================================================================
// MODEL IDENTIFICATION STRUCTURE
// ============================================================================

typedef struct {
    const char *model_name;         // Human-readable model name
    amiga_model_t model_id;         // Enum identifier
    region_standard_t region_base;  // Base region (PAL/NTSC)
    chipset_class_t chipset_class;  // Overall chipset class
    agnus_generation_t agnus_gen;   // Agnus generation
    chipram_class_t chipram_class;  // Chip RAM addressing class
    denise_class_t denise_class;    // Denise chip class (or NONE for AGA)
    cia_clock_class_t cia_clock_class; // CIA nominal clock class
    uint16_t kickstart_shipped_min; // Minimum KS version shipped with model
    uint16_t kickstart_shipped_max; // Maximum KS version shipped with model
    uint16_t kickstart_supported_min; // Minimum KS version supported (upgrade path)
    uint16_t kickstart_supported_max; // Maximum KS version supported (upgrade path)
    uint32_t flags;                 // Additional flags for special cases
} amiga_model_info_t;

// Model flags
#define MODEL_FLAG_UPGRADE_ONLY     0x0001  // Requires hardware upgrade to reach full capability
#define MODEL_FLAG_CUSTOM_CHIPSET   0x0002  // Custom or special chipset variant
#define MODEL_FLAG_LIMITED_RAM      0x0004  // Limited by board design, not chip capability

// ============================================================================
// MODEL DATABASE
// ============================================================================

static const amiga_model_info_t amiga_models[] = {
    // A500 - Base OCS model
    {
        .model_name = "A500",
        .model_id = AMIGA_MODEL_A500,
        .region_base = REGION_NTSC,  // Can be PAL with PAL Agnus
        .chipset_class = CHIPSET_CLASS_OCS,
        .agnus_gen = AGNUS_GEN_OCS,
        .chipram_class = CHIPRAM_CLASS_512K,
        .denise_class = DENISE_CLASS_OCS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x33,  // KS 1.2
        .kickstart_shipped_max = 0x37,  // KS 1.3
        .kickstart_supported_min = 0x33, // KS 1.2
        .kickstart_supported_max = 0x40, // KS 2.04 with upgrades
        .flags = 0
    },

    // A500+ - Full ECS model
    {
        .model_name = "A500+",
        .model_id = AMIGA_MODEL_A500PLUS,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_ECS,
        .agnus_gen = AGNUS_GEN_ECS,
        .chipram_class = CHIPRAM_CLASS_2M,
        .denise_class = DENISE_CLASS_ECS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x40,  // KS 2.04
        .kickstart_shipped_max = 0x40,  // KS 2.04
        .kickstart_supported_min = 0x40, // KS 2.04
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = 0
    },

    // A600 - ECS model
    {
        .model_name = "A600",
        .model_id = AMIGA_MODEL_A600,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_ECS,
        .agnus_gen = AGNUS_GEN_ECS,
        .chipram_class = CHIPRAM_CLASS_2M,
        .denise_class = DENISE_CLASS_ECS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x40,  // KS 2.04
        .kickstart_shipped_max = 0x40,  // KS 2.04
        .kickstart_supported_min = 0x40, // KS 2.04
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = 0
    },

    // A1000 - Original model with custom Agnus/Denise
    {
        .model_name = "A1000",
        .model_id = AMIGA_MODEL_A1000,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_OCS,
        .agnus_gen = AGNUS_GEN_OCS,
        .chipram_class = CHIPRAM_CLASS_512K,
        .denise_class = DENISE_CLASS_OCS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x28,  // KS 1.0
        .kickstart_shipped_max = 0x32,  // KS 1.1
        .kickstart_supported_min = 0x28, // KS 1.0
        .kickstart_supported_max = 0x37, // KS 1.3
        .flags = 0
    },

    // A1200 - AGA model
    {
        .model_name = "A1200",
        .model_id = AMIGA_MODEL_A1200,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_AGA,
        .agnus_gen = AGNUS_GEN_ECS,  // Uses ECS Agnus (Alice)
        .chipram_class = CHIPRAM_CLASS_2M,
        .denise_class = DENISE_CLASS_NONE,  // Uses Lisa, not Denise
        .cia_clock_class = CIA_CLOCK_CLASS_2X,
        .kickstart_shipped_min = 0x64,  // KS 2.0
        .kickstart_shipped_max = 0x7B,  // KS 3.1
        .kickstart_supported_min = 0x64, // KS 2.0
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = 0
    },

    // A2000 - Can be OCS, Part ECS, or Full ECS
    {
        .model_name = "A2000_OCS",
        .model_id = AMIGA_MODEL_A2000,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_OCS,
        .agnus_gen = AGNUS_GEN_OCS,
        .chipram_class = CHIPRAM_CLASS_512K,
        .denise_class = DENISE_CLASS_OCS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x33,  // KS 1.2
        .kickstart_shipped_max = 0x37,  // KS 1.3
        .kickstart_supported_min = 0x33, // KS 1.2
        .kickstart_supported_max = 0x40, // KS 2.04 with upgrades
        .flags = 0
    },

    // A2000 with Fat Agnus (Part ECS - 1MB capability)
    {
        .model_name = "A2000_FAT",
        .model_id = AMIGA_MODEL_A2000,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_OCS,  // Still OCS Denise
        .agnus_gen = AGNUS_GEN_FAT,
        .chipram_class = CHIPRAM_CLASS_1M,
        .denise_class = DENISE_CLASS_OCS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x37,  // KS 1.3
        .kickstart_shipped_max = 0x40,  // KS 2.04
        .kickstart_supported_min = 0x37, // KS 1.3
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = MODEL_FLAG_UPGRADE_ONLY
    },

    // A2000 with ECS Agnus and Denise (Full ECS)
    {
        .model_name = "A2000_ECS",
        .model_id = AMIGA_MODEL_A2000,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_ECS,
        .agnus_gen = AGNUS_GEN_ECS,
        .chipram_class = CHIPRAM_CLASS_2M,
        .denise_class = DENISE_CLASS_ECS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x40,  // KS 2.04
        .kickstart_shipped_max = 0x40,  // KS 2.04
        .kickstart_supported_min = 0x40, // KS 2.04
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = MODEL_FLAG_UPGRADE_ONLY
    },

    // A3000 - ECS/AGA model
    {
        .model_name = "A3000",
        .model_id = AMIGA_MODEL_A3000,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_ECS,
        .agnus_gen = AGNUS_GEN_ECS,
        .chipram_class = CHIPRAM_CLASS_2M,
        .denise_class = DENISE_CLASS_ECS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x37,  // KS 1.3
        .kickstart_shipped_max = 0x40,  // KS 2.04
        .kickstart_supported_min = 0x37, // KS 1.3
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = 0
    },

    // A4000 - AGA model
    {
        .model_name = "A4000",
        .model_id = AMIGA_MODEL_A4000,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_AGA,
        .agnus_gen = AGNUS_GEN_ECS,  // Uses ECS Agnus (Alice)
        .chipram_class = CHIPRAM_CLASS_8M,
        .denise_class = DENISE_CLASS_NONE,  // Uses Lisa, not Denise
        .cia_clock_class = CIA_CLOCK_CLASS_2X,
        .kickstart_shipped_min = 0x64,  // KS 2.0
        .kickstart_shipped_max = 0x7B,  // KS 3.1
        .kickstart_supported_min = 0x64, // KS 2.0
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = 0
    },

    // CDTV - ECS model with CD-ROM
    {
        .model_name = "CDTV",
        .model_id = AMIGA_MODEL_CDTV,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_ECS,
        .agnus_gen = AGNUS_GEN_ECS,
        .chipram_class = CHIPRAM_CLASS_2M,
        .denise_class = DENISE_CLASS_ECS,
        .cia_clock_class = CIA_CLOCK_CLASS_1X,
        .kickstart_shipped_min = 0x40,  // KS 2.04
        .kickstart_shipped_max = 0x40,  // KS 2.04
        .kickstart_supported_min = 0x40, // KS 2.04
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = 0
    },

    // CD32 - AGA model with CD-ROM
    {
        .model_name = "CD32",
        .model_id = AMIGA_MODEL_CD32,
        .region_base = REGION_NTSC,  // Can be PAL
        .chipset_class = CHIPSET_CLASS_AGA,
        .agnus_gen = AGNUS_GEN_ECS,  // Uses ECS Agnus (Alice)
        .chipram_class = CHIPRAM_CLASS_2M,
        .denise_class = DENISE_CLASS_NONE,  // Uses Lisa, not Denise
        .cia_clock_class = CIA_CLOCK_CLASS_2X,
        .kickstart_shipped_min = 0x7B,  // KS 3.1
        .kickstart_shipped_max = 0x7B,  // KS 3.1
        .kickstart_supported_min = 0x7B, // KS 3.1
        .kickstart_supported_max = 0x7B, // KS 3.1
        .flags = 0
    }
};

// ============================================================================
// MODEL IDENTIFICATION MACROS
// ============================================================================

// Get model info by ID
#define GET_MODEL_INFO(model_id) (&amiga_models[model_id])

// Check chipset class
#define IS_OCS_MODEL(model_id) (amiga_models[model_id].chipset_class == CHIPSET_CLASS_OCS)
#define IS_ECS_MODEL(model_id) (amiga_models[model_id].chipset_class == CHIPSET_CLASS_ECS)
#define IS_AGA_MODEL(model_id) (amiga_models[model_id].chipset_class == CHIPSET_CLASS_AGA)

// Check Agnus generation
#define HAS_OCS_AGNUS(model_id) (amiga_models[model_id].agnus_gen == AGNUS_GEN_OCS)
#define HAS_FAT_AGNUS(model_id) (amiga_models[model_id].agnus_gen == AGNUS_GEN_FAT)
#define HAS_ECS_AGNUS(model_id) (amiga_models[model_id].agnus_gen == AGNUS_GEN_ECS)

// Check Denise class
#define HAS_DENISE_CHIP(model_id) (amiga_models[model_id].denise_class != DENISE_CLASS_NONE)
#define HAS_SUPER_DENISE(model_id) (amiga_models[model_id].denise_class == DENISE_CLASS_ECS)

// Check CIA clock class
#define IS_CIA_1X_TIMING(model_id) (amiga_models[model_id].cia_clock_class == CIA_CLOCK_CLASS_1X)
#define IS_CIA_2X_TIMING(model_id) (amiga_models[model_id].cia_clock_class == CIA_CLOCK_CLASS_2X)

// Check Chip RAM class
#define SUPPORTS_512K_CHIPRAM(model_id) (amiga_models[model_id].chipram_class >= CHIPRAM_CLASS_512K)
#define SUPPORTS_1M_CHIPRAM(model_id) (amiga_models[model_id].chipram_class >= CHIPRAM_CLASS_1M)
#define SUPPORTS_2M_CHIPRAM(model_id) (amiga_models[model_id].chipram_class >= CHIPRAM_CLASS_2M)
#define SUPPORTS_8M_CHIPRAM(model_id) (amiga_models[model_id].chipram_class >= CHIPRAM_CLASS_8M)

// Check Kickstart support
#define MODEL_SHIPS_WITH_KS1X(model_id) (amiga_models[model_id].kickstart_shipped_max < 0x40)
#define MODEL_SHIPS_WITH_KS2X(model_id) (amiga_models[model_id].kickstart_shipped_min >= 0x40 && amiga_models[model_id].kickstart_shipped_max < 0x64)
#define MODEL_SHIPS_WITH_KS3X(model_id) (amiga_models[model_id].kickstart_shipped_min >= 0x64)

// ============================================================================
// TIMING CONSTANTS
// ============================================================================

// CIA Clock Rates (nominal)
#define CIA_CLOCK_RATE_1X_NTSC  1000000  // ~1MHz nominal for OCS/ECS NTSC
#define CIA_CLOCK_RATE_1X_PAL   1000000  // ~1MHz nominal for OCS/ECS PAL
#define CIA_CLOCK_RATE_2X_NTSC  2000000  // ~2MHz nominal for AGA NTSC
#define CIA_CLOCK_RATE_2X_PAL   2000000  // ~2MHz nominal for AGA PAL

// CPU Clock Rates
#define CPU_CLOCK_RATE_NTSC     7093790  // NTSC: ~7.09 MHz
#define CPU_CLOCK_RATE_PAL      7093790  // PAL: ~7.09 MHz (same as NTSC)
#define CPU_CLOCK_RATE_AGA_NTSC 14187580 // AGA NTSC: ~14.19 MHz (double)
#define CPU_CLOCK_RATE_AGA_PAL  14187580 // AGA PAL: ~14.19 MHz (double)

// System Clock Rates (for custom chips)
#define SYSTEM_CLOCK_RATE_NTSC  28636360 // NTSC: ~28.64 MHz
#define SYSTEM_CLOCK_RATE_PAL   28375160 // PAL: ~28.38 MHz
#define SYSTEM_CLOCK_RATE_AGA_NTSC 28636360 // AGA NTSC: ~28.64 MHz
#define SYSTEM_CLOCK_RATE_AGA_PAL  28375160 // AGA PAL: ~28.38 MHz

// Frame Rates
#define FRAME_RATE_NTSC         59.94    // NTSC: ~59.94 Hz
#define FRAME_RATE_PAL          49.92    // PAL: ~49.92 Hz

// Scanline Counts
#define SCANLINES_NTSC          262      // NTSC: 262/263 lines
#define SCANLINES_PAL           312      // PAL: 312/313 lines

// ============================================================================
// MODEL-SPECIFIC REGISTER AVAILABILITY
// ============================================================================

// Check if model has specific registers
#define MODEL_HAS_ECS_REGS(model_id) (IS_ECS_MODEL(model_id) || IS_AGA_MODEL(model_id))
#define MODEL_HAS_AGA_REGS(model_id) (IS_AGA_MODEL(model_id))
#define MODEL_HAS_SUPER_DENISE_REGS(model_id) (HAS_SUPER_DENISE(model_id) || IS_AGA_MODEL(model_id))

// ECS-specific registers availability
#define MODEL_HAS_HTOTAL(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_HSSTOP(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_HBSTRT(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_HBSTOP(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_VTOTAL(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_VSSTOP(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_VBSTRT(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_VBSTOP(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_BEAMCON0(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_HSSTRT(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_VSSTRT(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_HCENTER(model_id) MODEL_HAS_ECS_REGS(model_id)
#define MODEL_HAS_DIWHIGH(model_id) MODEL_HAS_ECS_REGS(model_id)

// AGA-specific registers availability
#define MODEL_HAS_BPLCON4(model_id) MODEL_HAS_AGA_REGS(model_id)
#define MODEL_HAS_FMODE(model_id) MODEL_HAS_AGA_REGS(model_id)
#define MODEL_HAS_DENISEID(model_id) (HAS_DENISE_CHIP(model_id))

// Bitplane count availability
#define MODEL_MAX_BITPLANES(model_id) (IS_AGA_MODEL(model_id) ? 8 : (IS_ECS_MODEL(model_id) ? 6 : 6))

// Sprite count availability
#define MODEL_MAX_SPRITES(model_id) 8  // All models support 8 sprites

// Audio channel count availability
#define MODEL_AUDIO_CHANNELS(model_id) 4  // All models have 4 audio channels

// ============================================================================
// HELPER FUNCTIONS
// ============================================================================

// Find model by name
static inline amiga_model_t find_model_by_name(const char *name) {
    for (int i = 0; i < sizeof(amiga_models)/sizeof(amiga_models[0]); i++) {
        if (amiga_models[i].model_name && 
            strcmp(amiga_models[i].model_name, name) == 0) {
            return amiga_models[i].model_id;
        }
    }
    return AMIGA_MODEL_UNKNOWN;
}

// Get model info by name
static inline const amiga_model_info_t* get_model_info_by_name(const char *name) {
    amiga_model_t model = find_model_by_name(name);
    if (model != AMIGA_MODEL_UNKNOWN) {
        return &amiga_models[model];
    }
    return NULL;
}

// Validate if a model supports a specific chipset class
static inline int model_supports_chipset_class(amiga_model_t model, chipset_class_t class) {
    if (model >= AMIGA_MODEL_LAST) return 0;
    return (amiga_models[model].chipset_class == class);
}

// Validate if a model supports specific Agnus generation
static inline int model_supports_agnus_gen(amiga_model_t model, agnus_generation_t gen) {
    if (model >= AMIGA_MODEL_LAST) return 0;
    return (amiga_models[model].agnus_gen == gen);
}

// Validate if a model supports specific Denise class
static inline int model_supports_denise_class(amiga_model_t model, denise_class_t class) {
    if (model >= AMIGA_MODEL_LAST) return 0;
    return (amiga_models[model].denise_class == class);
}

// Validate if a model supports specific CIA clock class
static inline int model_supports_cia_clock_class(amiga_model_t model, cia_clock_class_t class) {
    if (model >= AMIGA_MODEL_LAST) return 0;
    return (amiga_models[model].cia_clock_class == class);
}

// Get nominal CIA clock rate for a model
static inline uint32_t get_cia_clock_rate(amiga_model_t model) {
    if (model >= AMIGA_MODEL_LAST) return CIA_CLOCK_RATE_1X_NTSC;
    
    const amiga_model_info_t *info = &amiga_models[model];
    if (info->cia_clock_class == CIA_CLOCK_CLASS_2X) {
        return (info->region_base == REGION_PAL) ? CIA_CLOCK_RATE_2X_PAL : CIA_CLOCK_RATE_2X_NTSC;
    } else {
        return (info->region_base == REGION_PAL) ? CIA_CLOCK_RATE_1X_PAL : CIA_CLOCK_RATE_1X_NTSC;
    }
}

// Get CPU clock rate for a model
static inline uint32_t get_cpu_clock_rate(amiga_model_t model) {
    if (model >= AMIGA_MODEL_LAST) return CPU_CLOCK_RATE_NTSC;
    
    const amiga_model_info_t *info = &amiga_models[model];
    if (info->chipset_class == CHIPSET_CLASS_AGA) {
        return (info->region_base == REGION_PAL) ? CPU_CLOCK_RATE_AGA_PAL : CPU_CLOCK_RATE_AGA_NTSC;
    } else {
        return (info->region_base == REGION_PAL) ? CPU_CLOCK_RATE_PAL : CPU_CLOCK_RATE_NTSC;
    }
}

// Get system clock rate for a model
static inline uint32_t get_system_clock_rate(amiga_model_t model) {
    if (model >= AMIGA_MODEL_LAST) return SYSTEM_CLOCK_RATE_NTSC;
    
    const amiga_model_info_t *info = &amiga_models[model];
    if (info->chipset_class == CHIPSET_CLASS_AGA) {
        return (info->region_base == REGION_PAL) ? SYSTEM_CLOCK_RATE_AGA_PAL : SYSTEM_CLOCK_RATE_AGA_NTSC;
    } else {
        return (info->region_base == REGION_PAL) ? SYSTEM_CLOCK_RATE_PAL : SYSTEM_CLOCK_RATE_NTSC;
    }
}

// Get frame rate for a model
static inline float get_frame_rate(amiga_model_t model) {
    if (model >= AMIGA_MODEL_LAST) return FRAME_RATE_NTSC;
    
    const amiga_model_info_t *info = &amiga_models[model];
    return (info->region_base == REGION_PAL) ? FRAME_RATE_PAL : FRAME_RATE_NTSC;
}

// Get scanline count for a model
static inline int get_scanline_count(amiga_model_t model) {
    if (model >= AMIGA_MODEL_LAST) return SCANLINES_NTSC;
    
    const amiga_model_info_t *info = &amiga_models[model];
    return (info->region_base == REGION_PAL) ? SCANLINES_PAL : SCANLINES_NTSC;
}

#endif // AMIGA_MODEL_IDENTIFICATION_H