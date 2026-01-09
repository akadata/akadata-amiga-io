/*
 * SPDX-License-Identifier: MIT
 * 
 * Main Amiga Register Definitions Header
 * Includes all custom chip register definitions for PISTORM project
 */

#ifndef AMIGA_REGISTERS_H
#define AMIGA_REGISTERS_H

// Include all individual chip headers
#include "agnus.h"
#include "denise.h"
#include "paula.h"
#include "cia.h"
#include "blitter.h"

// Include model identification header
#include "amiga_model_identification.h"

// Include memory map definitions
#include "amiga_memory_map.h"

// Common register access macros
#define CUSTOM_CHIP_BASE 0xDFF000
#define CIAA_BASE        0xBFE001
#define CIAB_BASE        0xBFD000

// Register access functions (for PISTORM interface)
extern uint16_t pistorm_read_register(uint32_t addr);
extern void pistorm_write_register(uint32_t addr, uint16_t value);
extern uint8_t pistorm_read_register_byte(uint32_t addr, int high_byte);
extern void pistorm_write_register_byte(uint32_t addr, uint8_t value, int high_byte);

// Model-specific register availability checks
extern int model_has_ecs_features(amiga_model_t model);
extern int model_has_aga_features(amiga_model_t model);
extern int model_supports_uhres(amiga_model_t model);

// Common bit manipulation macros
#define SET_BIT(reg, bit)     ((reg) |= (1 << (bit)))
#define CLEAR_BIT(reg, bit)   ((reg) &= ~(1 << (bit)))
#define TOGGLE_BIT(reg, bit)  ((reg) ^= (1 << (bit)))
#define CHECK_BIT(reg, bit)   (((reg) >> (bit)) & 1)

// DMA control convenience macros
#define ENABLE_DMA_CHANNEL(dma_mask)   pistorm_write_register(DMACON, (dma_mask) | DMAF_SETCLR)
#define DISABLE_DMA_CHANNEL(dma_mask)  pistorm_write_register(DMACON, (dma_mask))
#define ENABLE_ALL_DMA()              pistorm_write_register(DMACON, DMAF_ALL | DMAF_SETCLR)
#define DISABLE_ALL_DMA()             pistorm_write_register(DMACON, DMAF_ALL)

// Interrupt control convenience macros
#define ENABLE_INTERRUPT(int_mask)     pistorm_write_register(INTENA, (int_mask) | INTF_SETCLR)
#define DISABLE_INTERRUPT(int_mask)    pistorm_write_register(INTENA, (int_mask))
#define CLEAR_INTERRUPT(int_mask)      pistorm_write_register(INTREQ, (int_mask))
#define REQUEST_INTERRUPT(int_mask)    pistorm_write_register(INTREQ, (int_mask) | INTF_SETCLR)

// Audio channel convenience macros
#define SET_AUDIO0_PERIOD(period) pistorm_write_register(AUD0PER, (period))
#define SET_AUDIO1_PERIOD(period) pistorm_write_register(AUD1PER, (period))
#define SET_AUDIO2_PERIOD(period) pistorm_write_register(AUD2PER, (period))
#define SET_AUDIO3_PERIOD(period) pistorm_write_register(AUD3PER, (period))

#define SET_AUDIO0_VOLUME(vol) pistorm_write_register(AUD0VOL, (vol))
#define SET_AUDIO1_VOLUME(vol) pistorm_write_register(AUD1VOL, (vol))
#define SET_AUDIO2_VOLUME(vol) pistorm_write_register(AUD2VOL, (vol))
#define SET_AUDIO3_VOLUME(vol) pistorm_write_register(AUD3VOL, (vol))

#define SET_AUDIO0_LEN(len) pistorm_write_register(AUD0LEN, (len))
#define SET_AUDIO1_LEN(len) pistorm_write_register(AUD1LEN, (len))
#define SET_AUDIO2_LEN(len) pistorm_write_register(AUD2LEN, (len))
#define SET_AUDIO3_LEN(len) pistorm_write_register(AUD3LEN, (len))

#define SET_AUDIO0_POINTER(addr) do { \
    pistorm_write_register(AUD0LCH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(AUD0LCL, (addr) & 0xFFFF); \
} while(0)
#define SET_AUDIO1_POINTER(addr) do { \
    pistorm_write_register(AUD1LCH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(AUD1LCL, (addr) & 0xFFFF); \
} while(0)
#define SET_AUDIO2_POINTER(addr) do { \
    pistorm_write_register(AUD2LCH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(AUD2LCL, (addr) & 0xFFFF); \
} while(0)
#define SET_AUDIO3_POINTER(addr) do { \
    pistorm_write_register(AUD3LCH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(AUD3LCL, (addr) & 0xFFFF); \
} while(0)

// Sprite control convenience macros
#define SET_SPRITE0_POSITION(hpos, vpos) pistorm_write_register(SPR0POS, ((vpos) << 8) | (hpos))
#define SET_SPRITE1_POSITION(hpos, vpos) pistorm_write_register(SPR1POS, ((vpos) << 8) | (hpos))
#define SET_SPRITE2_POSITION(hpos, vpos) pistorm_write_register(SPR2POS, ((vpos) << 8) | (hpos))
#define SET_SPRITE3_POSITION(hpos, vpos) pistorm_write_register(SPR3POS, ((vpos) << 8) | (hpos))
#define SET_SPRITE4_POSITION(hpos, vpos) pistorm_write_register(SPR4POS, ((vpos) << 8) | (hpos))
#define SET_SPRITE5_POSITION(hpos, vpos) pistorm_write_register(SPR5POS, ((vpos) << 8) | (hpos))
#define SET_SPRITE6_POSITION(hpos, vpos) pistorm_write_register(SPR6POS, ((vpos) << 8) | (hpos))
#define SET_SPRITE7_POSITION(hpos, vpos) pistorm_write_register(SPR7POS, ((vpos) << 8) | (hpos))

#define SET_SPRITE0_CONTROL(vstop) pistorm_write_register(SPR0CTL, (vstop))
#define SET_SPRITE1_CONTROL(vstop) pistorm_write_register(SPR1CTL, (vstop))
#define SET_SPRITE2_CONTROL(vstop) pistorm_write_register(SPR2CTL, (vstop))
#define SET_SPRITE3_CONTROL(vstop) pistorm_write_register(SPR3CTL, (vstop))
#define SET_SPRITE4_CONTROL(vstop) pistorm_write_register(SPR4CTL, (vstop))
#define SET_SPRITE5_CONTROL(vstop) pistorm_write_register(SPR5CTL, (vstop))
#define SET_SPRITE6_CONTROL(vstop) pistorm_write_register(SPR6CTL, (vstop))
#define SET_SPRITE7_CONTROL(vstop) pistorm_write_register(SPR7CTL, (vstop))

#define SET_SPRITE0_POINTER(addr) do { \
    pistorm_write_register(SPR0PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(SPR0PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_SPRITE1_POINTER(addr) do { \
    pistorm_write_register(SPR1PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(SPR1PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_SPRITE2_POINTER(addr) do { \
    pistorm_write_register(SPR2PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(SPR2PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_SPRITE3_POINTER(addr) do { \
    pistorm_write_register(SPR3PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(SPR3PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_SPRITE4_POINTER(addr) do { \
    pistorm_write_register(SPR4PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(SPR4PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_SPRITE5_POINTER(addr) do { \
    pistorm_write_register(SPR5PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(SPR5PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_SPRITE6_POINTER(addr) do { \
    pistorm_write_register(SPR6PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(SPR6PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_SPRITE7_POINTER(addr) do { \
    pistorm_write_register(SPR7PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(SPR7PTL, (addr) & 0xFFFF); \
} while(0)

// Bitplane control convenience macros
#define SET_BITPLANE0_POINTER(addr) do { \
    pistorm_write_register(BPL0PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL0PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_BITPLANE1_POINTER(addr) do { \
    pistorm_write_register(BPL1PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL1PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_BITPLANE2_POINTER(addr) do { \
    pistorm_write_register(BPL2PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL2PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_BITPLANE3_POINTER(addr) do { \
    pistorm_write_register(BPL3PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL3PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_BITPLANE4_POINTER(addr) do { \
    pistorm_write_register(BPL4PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL4PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_BITPLANE5_POINTER(addr) do { \
    pistorm_write_register(BPL5PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL5PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_BITPLANE6_POINTER(addr) do { \
    pistorm_write_register(BPL6PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL6PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_BITPLANE7_POINTER(addr) do { \
    pistorm_write_register(BPL7PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL7PTL, (addr) & 0xFFFF); \
} while(0)
#define SET_BITPLANE8_POINTER(addr) do { \
    pistorm_write_register(BPL8PTH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(BPL8PTL, (addr) & 0xFFFF); \
} while(0)

#define SET_BITPLANE_MODULO(odd_mod, even_mod) do { \
    pistorm_write_register(BPL1MOD, (odd_mod)); \
    pistorm_write_register(BPL2MOD, (even_mod)); \
} while(0)

// Color register convenience macros
#define SET_COLOR00(color) pistorm_write_register(COLOR00, (color))
#define SET_COLOR01(color) pistorm_write_register(COLOR01, (color))
#define SET_COLOR02(color) pistorm_write_register(COLOR02, (color))
#define SET_COLOR03(color) pistorm_write_register(COLOR03, (color))
#define SET_COLOR04(color) pistorm_write_register(COLOR04, (color))
#define SET_COLOR05(color) pistorm_write_register(COLOR05, (color))
#define SET_COLOR06(color) pistorm_write_register(COLOR06, (color))
#define SET_COLOR07(color) pistorm_write_register(COLOR07, (color))
#define SET_COLOR08(color) pistorm_write_register(COLOR08, (color))
#define SET_COLOR09(color) pistorm_write_register(COLOR09, (color))
#define SET_COLOR10(color) pistorm_write_register(COLOR10, (color))
#define SET_COLOR11(color) pistorm_write_register(COLOR11, (color))
#define SET_COLOR12(color) pistorm_write_register(COLOR12, (color))
#define SET_COLOR13(color) pistorm_write_register(COLOR13, (color))
#define SET_COLOR14(color) pistorm_write_register(COLOR14, (color))
#define SET_COLOR15(color) pistorm_write_register(COLOR15, (color))
#define SET_COLOR16(color) pistorm_write_register(COLOR16, (color))
#define SET_COLOR17(color) pistorm_write_register(COLOR17, (color))
#define SET_COLOR18(color) pistorm_write_register(COLOR18, (color))
#define SET_COLOR19(color) pistorm_write_register(COLOR19, (color))
#define SET_COLOR20(color) pistorm_write_register(COLOR20, (color))
#define SET_COLOR21(color) pistorm_write_register(COLOR21, (color))
#define SET_COLOR22(color) pistorm_write_register(COLOR22, (color))
#define SET_COLOR23(color) pistorm_write_register(COLOR23, (color))
#define SET_COLOR24(color) pistorm_write_register(COLOR24, (color))
#define SET_COLOR25(color) pistorm_write_register(COLOR25, (color))
#define SET_COLOR26(color) pistorm_write_register(COLOR26, (color))
#define SET_COLOR27(color) pistorm_write_register(COLOR27, (color))
#define SET_COLOR28(color) pistorm_write_register(COLOR28, (color))
#define SET_COLOR29(color) pistorm_write_register(COLOR29, (color))
#define SET_COLOR30(color) pistorm_write_register(COLOR30, (color))
#define SET_COLOR31(color) pistorm_write_register(COLOR31, (color))

// Copper control convenience macros
#define SET_COPPER_LIST1_POINTER(addr) do { \
    pistorm_write_register(COP1LCH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(COP1LCL, (addr) & 0xFFFF); \
} while(0)

#define SET_COPPER_LIST2_POINTER(addr) do { \
    pistorm_write_register(COP2LCH, ((addr) >> 16) & 0x7F); \
    pistorm_write_register(COP2LCL, (addr) & 0xFFFF); \
} while(0)

#define RESTART_COPPER1() pistorm_write_register(COPJMP1, 0)
#define RESTART_COPPER2() pistorm_write_register(COPJMP2, 0)

// Blitter control convenience macros
#define START_BLITTER(width, height) pistorm_write_register(BLTSIZE, ((height) << 6) | ((width) & 0x3F))

// Display window control convenience macros
#define SET_DISPLAY_WINDOW(start, stop) do { \
    pistorm_write_register(DIWSTRT, (start)); \
    pistorm_write_register(DIWSTOP, (stop)); \
} while(0)

#define SET_DISPLAY_FETCH(start, stop) do { \
    pistorm_write_register(DDFSTRT, (start)); \
    pistorm_write_register(DDFSTOP, (stop)); \
} while(0)

#endif // AMIGA_REGISTERS_H