// SPDX-License-Identifier: MIT
// Amiga Model-Specific Register Definitions
// Defines registers and capabilities for different Amiga models
// A500, A600, A1200, A2000, A3000, A4000

#ifndef AMIGA_MODELS_H
#define AMIGA_MODELS_H

#include "amiga_custom_chips.h"

// ============================================================================
// AMIGA MODEL IDENTIFICATION
// ============================================================================

// Model IDs
#define AMIGA_MODEL_A500    0x0001
#define AMIGA_MODEL_A1000   0x0002
#define AMIGA_MODEL_A2000   0x0004
#define AMIGA_MODEL_A3000   0x0008
#define AMIGA_MODEL_A500PLUS 0x0010
#define AMIGA_MODEL_A600    0x0020
#define AMIGA_MODEL_A1200   0x0040
#define AMIGA_MODEL_A4000   0x0080
#define AMIGA_MODEL_CDTV    0x0100
#define AMIGA_MODEL_CD32    0x0200

// Model families
#define AMIGA_FAMILY_OCS    (AMIGA_MODEL_A500 | AMIGA_MODEL_A1000 | AMIGA_MODEL_A2000)
#define AMIGA_FAMILY_ECS    (AMIGA_MODEL_A500PLUS | AMIGA_MODEL_A600 | AMIGA_MODEL_A1200)
#define AMIGA_FAMILY_AGA    (AMIGA_MODEL_A4000)
#define AMIGA_FAMILY_CDTV   (AMIGA_MODEL_CDTV)
#define AMIGA_FAMILY_CD32   (AMIGA_MODEL_CD32)

// ============================================================================
// A500 SPECIFIC DEFINITIONS
// ============================================================================

// A500 has OCS (Original Chip Set) chips
#define A500_CHIP_RAM_SIZE      (512 * 1024)    // Standard 512KB Chip RAM
#define A500_CHIP_RAM_MAX_SIZE  (1024 * 1024)   // With trapdoor expansion
#define A500_SLOW_RAM_SIZE      (512 * 1024)    // Trapdoor slow RAM (optional)

// A500-specific register availability
#define A500_HAS_AGNUS          1
#define A500_HAS_PAULA          1
#define A500_HAS_DENISE         1
#define A500_HAS_BLITTER        1
#define A500_HAS_CIAA           1
#define A500_HAS_CIAB           1
#define A500_HAS_ECS_FEATURES   0  // No ECS features
#define A500_HAS_AGA_FEATURES   0  // No AGA features

// A500-specific memory map
#define A500_CHIP_RAM_START     0x00000000
#define A500_CHIP_RAM_END       0x0007FFFF
#define A500_SLOW_RAM_START     0x00C00000
#define A500_SLOW_RAM_END       0x00D7FFFF

// ============================================================================
// A600 SPECIFIC DEFINITIONS
// ============================================================================

// A600 has ECS (Enhanced Chip Set) chips
#define A600_CHIP_RAM_SIZE      (2 * 1024 * 1024)   // Standard 2MB Chip RAM
#define A600_FAST_RAM_SIZE      (8 * 1024 * 1024)   // Up to 8MB Fast RAM

// A600-specific register availability
#define A600_HAS_AGNUS          1
#define A600_HAS_PAULA          1
#define A600_HAS_DENISE         1
#define A600_HAS_BLITTER        1
#define A600_HAS_CIAA           1
#define A600_HAS_CIAB           1
#define A600_HAS_ECS_FEATURES   1  // Has ECS features
#define A600_HAS_AGA_FEATURES   0  // No AGA features

// A600-specific registers (ECS additions)
#define A600_HAS_HTOTAL         1
#define A600_HAS_HSSTOP         1
#define A600_HAS_HBSTRT         1
#define A600_HAS_HBSTOP         1
#define A600_HAS_VTOTAL         1
#define A600_HAS_VSSTOP         1
#define A600_HAS_VBSTRT         1
#define A600_HAS_VBSTOP         1
#define A600_HAS_BEAMCON0       1
#define A600_HAS_HSSTRT         1
#define A600_HAS_VSSTRT         1
#define A600_HAS_HCENTER        1
#define A600_HAS_DIWHIGH        1

// A600-specific memory map
#define A600_CHIP_RAM_START     0x00000000
#define A600_CHIP_RAM_END       0x001FFFFF
#define A600_FAST_RAM_START     0x00200000
#define A600_FAST_RAM_END       0x009FFFFF
#define A600_IDE_START          0x00DA0000  // IDE controller
#define A600_IDE_END            0x00DA3FFF

// ============================================================================
// A1200 SPECIFIC DEFINITIONS
// ============================================================================

// A1200 has ECS (Enhanced Chip Set) chips
#define A1200_CHIP_RAM_SIZE     (2 * 1024 * 1024)   // Standard 2MB Chip RAM
#define A1200_FAST_RAM_SIZE     (8 * 1024 * 1024)   // Up to 8MB Fast RAM

// A1200-specific register availability
#define A1200_HAS_AGNUS         1
#define A1200_HAS_PAULA         1
#define A1200_HAS_DENISE        1
#define A1200_HAS_BLITTER       1
#define A1200_HAS_CIAA          1
#define A1200_HAS_CIAB          1
#define A1200_HAS_ECS_FEATURES  1  // Has ECS features
#define A1200_HAS_AGA_FEATURES  0  // No AGA features

// A1200-specific registers (ECS additions)
#define A1200_HAS_HTOTAL        1
#define A1200_HAS_HSSTOP        1
#define A1200_HAS_HBSTRT        1
#define A1200_HAS_HBSTOP        1
#define A1200_HAS_VTOTAL        1
#define A1200_HAS_VSSTOP        1
#define A1200_HAS_VBSTRT        1
#define A1200_HAS_VBSTOP        1
#define A1200_HAS_BEAMCON0      1
#define A1200_HAS_HSSTRT        1
#define A1200_HAS_VSSTRT        1
#define A1200_HAS_HCENTER       1
#define A1200_HAS_DIWHIGH       1

// A1200-specific memory map
#define A1200_CHIP_RAM_START    0x00000000
#define A1200_CHIP_RAM_END      0x001FFFFF
#define A1200_FAST_RAM_START    0x00200000
#define A1200_FAST_RAM_END      0x009FFFFF
#define A1200_IDE_START         0x00DA0000  // IDE controller
#define A1200_IDE_END           0x00DA3FFF
#define A1200_CLOCK_START       0x00D80000  // Clock port
#define A1200_CLOCK_END         0x00D8FFFF

// ============================================================================
// A2000 SPECIFIC DEFINITIONS
// ============================================================================

// A2000 has OCS (Original Chip Set) chips
#define A2000_CHIP_RAM_SIZE     (1024 * 1024)       // Standard 1MB Chip RAM
#define A2000_EXPANSION_SIZE    (8 * 1024 * 1024)   // Expansion space

// A2000-specific register availability
#define A2000_HAS_AGNUS         1
#define A2000_HAS_PAULA         1
#define A2000_HAS_DENISE        1
#define A2000_HAS_BLITTER       1
#define A2000_HAS_CIAA          1
#define A2000_HAS_CIAB          1
#define A2000_HAS_ECS_FEATURES  0  // No ECS features initially
#define A2000_HAS_AGA_FEATURES  0  // No AGA features

// A2000-specific memory map
#define A2000_CHIP_RAM_START    0x00000000
#define A2000_CHIP_RAM_END      0x000FFFFF
#define A2000_ZORROII_START     0x00200000
#define A2000_ZORROII_END       0x009FFFFF

// ============================================================================
// A3000 SPECIFIC DEFINITIONS
// ============================================================================

// A3000 has ECS (Enhanced Chip Set) chips
#define A3000_CHIP_RAM_SIZE     (2 * 1024 * 1024)   // Standard 2MB Chip RAM
#define A3000_FAST_RAM_SIZE     (8 * 1024 * 1024)   // Up to 8MB Fast RAM

// A3000-specific register availability
#define A3000_HAS_AGNUS         1
#define A3000_HAS_PAULA         1
#define A3000_HAS_DENISE        1
#define A3000_HAS_BLITTER       1
#define A3000_HAS_CIAA          1
#define A3000_HAS_CIAB          1
#define A3000_HAS_ECS_FEATURES  1  // Has ECS features
#define A3000_HAS_AGA_FEATURES  0  // No AGA features

// A3000-specific registers (ECS additions)
#define A3000_HAS_HTOTAL        1
#define A3000_HAS_HSSTOP        1
#define A3000_HAS_HBSTRT        1
#define A3000_HAS_HBSTOP        1
#define A3000_HAS_VTOTAL        1
#define A3000_HAS_VSSTOP        1
#define A3000_HAS_VBSTRT        1
#define A3000_HAS_VBSTOP        1
#define A3000_HAS_BEAMCON0      1
#define A3000_HAS_HSSTRT        1
#define A3000_HAS_VSSTRT        1
#define A3000_HAS_HCENTER       1
#define A3000_HAS_DIWHIGH       1

// A3000-specific memory map
#define A3000_CHIP_RAM_START    0x00000000
#define A3000_CHIP_RAM_END      0x001FFFFF
#define A3000_FAST_RAM_START    0x00200000
#define A3000_FAST_RAM_END      0x009FFFFF
#define A3000_SCSI_START        0x00DD0000  // SCSI controller
#define A3000_SCSI_END          0x00DDFFFF

// ============================================================================
// A4000 SPECIFIC DEFINITIONS
// ============================================================================

// A4000 has AGA (Advanced Graphics Architecture) chips
#define A4000_CHIP_RAM_SIZE     (8 * 1024 * 1024)   // Up to 8MB Chip RAM
#define A4000_FAST_RAM_SIZE     (32 * 1024 * 1024)  // Up to 32MB Fast RAM

// A4000-specific register availability
#define A4000_HAS_AGNUS         1
#define A4000_HAS_PAULA         1
#define A4000_HAS_DENISE        1  // Actually Alice, but compatible
#define A4000_HAS_BLITTER       1
#define A4000_HAS_CIAA          1
#define A4000_HAS_CIAB          1
#define A4000_HAS_ECS_FEATURES  1  // Has ECS features
#define A4000_HAS_AGA_FEATURES  1  // Has AGA features

// A4000-specific registers (AGA additions)
#define A4000_HAS_HTOTAL        1
#define A4000_HAS_HSSTOP        1
#define A4000_HAS_HBSTRT        1
#define A4000_HAS_HBSTOP        1
#define A4000_HAS_VTOTAL        1
#define A4000_HAS_VSSTOP        1
#define A4000_HAS_VBSTRT        1
#define A4000_HAS_VBSTOP        1
#define A4000_HAS_BEAMCON0      1
#define A4000_HAS_HSSTRT        1
#define A4000_HAS_VSSTRT        1
#define A4000_HAS_HCENTER       1
#define A4000_HAS_DIWHIGH       1
#define A4000_HAS_BPLCON3       1  // AGA-specific register
#define A4000_HAS_BPLCON4       1  // AGA-specific register
#define A4000_HAS_CLXCON2       1  // AGA-specific register
#define A4000_HAS_DENISEID      1  // Denise/Alice revision register

// A4000-specific memory map
#define A4000_CHIP_RAM_START    0x00000000
#define A4000_CHIP_RAM_END      0x007FFFFF
#define A4000_FAST_RAM_START    0x04000000
#define A4000_FAST_RAM_END      0x06FFFFFF
#define A4000_IDE_START         0x00DD0000  // IDE controller
#define A4000_IDE_END           0x00DDFFFF

// ============================================================================
// FEATURE DETECTION MACROS
// ============================================================================

// Check if current system has ECS features
#ifndef HAS_ECS_FEATURES
#define HAS_ECS_FEATURES (defined(A4000_HAS_ECS_FEATURES) || defined(A3000_HAS_ECS_FEATURES) || \
                         defined(A1200_HAS_ECS_FEATURES) || defined(A600_HAS_ECS_FEATURES))
#endif

// Check if current system has AGA features
#ifndef HAS_AGA_FEATURES
#define HAS_AGA_FEATURES (defined(A4000_HAS_AGA_FEATURES))
#endif

// Check for specific register availability based on model
#ifndef HAS_BPLCON3
#define HAS_BPLCON3 (A4000_HAS_AGA_FEATURES || A1200_HAS_ECS_FEATURES || A600_HAS_ECS_FEATURES)
#endif

#ifndef HAS_BPLCON4
#define HAS_BPLCON4 (A4000_HAS_AGA_FEATURES)
#endif

#ifndef HAS_CLXCON2
#define HAS_CLXCON2 (A4000_HAS_AGA_FEATURES)
#endif

#ifndef HAS_DENISEID
#define HAS_DENISEID (A4000_HAS_AGA_FEATURES || A3000_HAS_ECS_FEATURES)
#endif

// ============================================================================
// MODEL-SPECIFIC REGISTER ACCESS
// ============================================================================

// Macro to conditionally define registers based on model support
#define IF_MODEL_SUPPORTS_A4000(reg_def) \
    A4000_HAS_##reg_def

#define IF_MODEL_SUPPORTS_A3000(reg_def) \
    A3000_HAS_##reg_def

#define IF_MODEL_SUPPORTS_A1200(reg_def) \
    A1200_HAS_##reg_def

#define IF_MODEL_SUPPORTS_A600(reg_def) \
    A600_HAS_##reg_def

#define IF_MODEL_SUPPORTS_A500(reg_def) \
    A500_HAS_##reg_def

// Runtime model detection (when needed)
typedef enum {
    AMIGA_UNKNOWN = 0,
    AMIGA_A500,
    AMIGA_A1000,
    AMIGA_A2000,
    AMIGA_A500PLUS,
    AMIGA_A600,
    AMIGA_A1200,
    AMIGA_A4000,
    AMIGA_CDTV,
    AMIGA_CD32
} amiga_model_t;

// Function to detect Amiga model based on chip features
static inline amiga_model_t detect_amiga_model(void) {
    // This would typically read from chip registers to determine model
    // For now, return a generic value
    return AMIGA_UNKNOWN;
}

// Model-specific initialization
static inline void init_for_model(amiga_model_t model) {
    // Initialize registers based on detected model
    // This would contain model-specific setup code
}

#endif // AMIGA_MODELS_H