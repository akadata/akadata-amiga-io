/*
 * SPDX-License-Identifier: MIT
 * 
 * Enhanced DENISE chip register definitions for Amiga
 * Based on Amiga Hardware Reference Manual and official documentation
 */

#ifndef ENHANCED_DENISE_H
#define ENHANCED_DENISE_H

#include "amiga_custom_chips.h"

// DENISE base address is 0xDFF000 (same as AGNUS/PAULA)
#ifndef DENISE_BASE
#define DENISE_BASE 0xDFF000
#endif

// Sprite Registers (Position and Control)
#define SPR0POS  (DENISE_BASE + 0x140)  // Sprite 0 position (vertical/horizontal)
#define SPR0CTL  (DENISE_BASE + 0x142)  // Sprite 0 control (attach/vstart/vstop)
#define SPR0DATA (DENISE_BASE + 0x144)  // Sprite 0 data A
#define SPR0DATB (DENISE_BASE + 0x146)  // Sprite 0 data B

#define SPR1POS  (DENISE_BASE + 0x148)  // Sprite 1 position
#define SPR1CTL  (DENISE_BASE + 0x14A)  // Sprite 1 control
#define SPR1DATA (DENISE_BASE + 0x14C)  // Sprite 1 data A
#define SPR1DATB (DENISE_BASE + 0x14E)  // Sprite 1 data B

#define SPR2POS  (DENISE_BASE + 0x150)  // Sprite 2 position
#define SPR2CTL  (DENISE_BASE + 0x152)  // Sprite 2 control
#define SPR2DATA (DENISE_BASE + 0x154)  // Sprite 2 data A
#define SPR2DATB (DENISE_BASE + 0x156)  // Sprite 2 data B

#define SPR3POS  (DENISE_BASE + 0x158)  // Sprite 3 position
#define SPR3CTL  (DENISE_BASE + 0x15A)  // Sprite 3 control
#define SPR3DATA (DENISE_BASE + 0x15C)  // Sprite 3 data A
#define SPR3DATB (DENISE_BASE + 0x15E)  // Sprite 3 data B

#define SPR4POS  (DENISE_BASE + 0x160)  // Sprite 4 position
#define SPR4CTL  (DENISE_BASE + 0x162)  // Sprite 4 control
#define SPR4DATA (DENISE_BASE + 0x164)  // Sprite 4 data A
#define SPR4DATB (DENISE_BASE + 0x166)  // Sprite 4 data B

#define SPR5POS  (DENISE_BASE + 0x168)  // Sprite 5 position
#define SPR5CTL  (DENISE_BASE + 0x16A)  // Sprite 5 control
#define SPR5DATA (DENISE_BASE + 0x16C)  // Sprite 5 data A
#define SPR5DATB (DENISE_BASE + 0x16E)  // Sprite 5 data B

#define SPR6POS  (DENISE_BASE + 0x170)  // Sprite 6 position
#define SPR6CTL  (DENISE_BASE + 0x172)  // Sprite 6 control
#define SPR6DATA (DENISE_BASE + 0x174)  // Sprite 6 data A
#define SPR6DATB (DENISE_BASE + 0x176)  // Sprite 6 data B

#define SPR7POS  (DENISE_BASE + 0x178)  // Sprite 7 position
#define SPR7CTL  (DENISE_BASE + 0x17A)  // Sprite 7 control
#define SPR7DATA (DENISE_BASE + 0x17C)  // Sprite 7 data A
#define SPR7DATB (DENISE_BASE + 0x17E)  // Sprite 7 data B

// Sprite Pointer Registers (DMA)
#define SPR0PTH  (DENISE_BASE + 0x120)  // Sprite 0 pointer high
#define SPR0PTL  (DENISE_BASE + 0x122)  // Sprite 0 pointer low
#define SPR1PTH  (DENISE_BASE + 0x124)  // Sprite 1 pointer high
#define SPR1PTL  (DENISE_BASE + 0x126)  // Sprite 1 pointer low
#define SPR2PTH  (DENISE_BASE + 0x128)  // Sprite 2 pointer high
#define SPR2PTL  (DENISE_BASE + 0x12A)  // Sprite 2 pointer low
#define SPR3PTH  (DENISE_BASE + 0x12C)  // Sprite 3 pointer high
#define SPR3PTL  (DENISE_BASE + 0x12E)  // Sprite 3 pointer low
#define SPR4PTH  (DENISE_BASE + 0x130)  // Sprite 4 pointer high
#define SPR4PTL  (DENISE_BASE + 0x132)  // Sprite 4 pointer low
#define SPR5PTH  (DENISE_BASE + 0x134)  // Sprite 5 pointer high
#define SPR5PTL  (DENISE_BASE + 0x136)  // Sprite 5 pointer low
#define SPR6PTH  (DENISE_BASE + 0x138)  // Sprite 6 pointer high
#define SPR6PTL  (DENISE_BASE + 0x13A)  // Sprite 6 pointer low
#define SPR7PTH  (DENISE_BASE + 0x13C)  // Sprite 7 pointer high
#define SPR7PTL  (DENISE_BASE + 0x13E)  // Sprite 7 pointer low

// Color Palette Registers
#define COLOR00  (DENISE_BASE + 0x180)  // Color 00 (background/border)
#define COLOR01  (DENISE_BASE + 0x182)  // Color 01
#define COLOR02  (DENISE_BASE + 0x184)  // Color 02
#define COLOR03  (DENISE_BASE + 0x186)  // Color 03
#define COLOR04  (DENISE_BASE + 0x188)  // Color 04
#define COLOR05  (DENISE_BASE + 0x18A)  // Color 05
#define COLOR06  (DENISE_BASE + 0x18C)  // Color 06
#define COLOR07  (DENISE_BASE + 0x18E)  // Color 07
#define COLOR08  (DENISE_BASE + 0x190)  // Color 08
#define COLOR09  (DENISE_BASE + 0x192)  // Color 09
#define COLOR10  (DENISE_BASE + 0x194)  // Color 10
#define COLOR11  (DENISE_BASE + 0x196)  // Color 11
#define COLOR12  (DENISE_BASE + 0x198)  // Color 12
#define COLOR13  (DENISE_BASE + 0x19A)  // Color 13
#define COLOR14  (DENISE_BASE + 0x19C)  // Color 14
#define COLOR15  (DENISE_BASE + 0x19E)  // Color 15
#define COLOR16  (DENISE_BASE + 0x1A0)  // Color 16
#define COLOR17  (DENISE_BASE + 0x1A2)  // Color 17 (sprite 0/1 color 1)
#define COLOR18  (DENISE_BASE + 0x1A4)  // Color 18 (sprite 0/1 color 2)
#define COLOR19  (DENISE_BASE + 0x1A6)  // Color 19 (sprite 0/1 color 3)
#define COLOR20  (DENISE_BASE + 0x1A8)  // Color 20
#define COLOR21  (DENISE_BASE + 0x1AA)  // Color 21 (sprite 2/3 color 1)
#define COLOR22  (DENISE_BASE + 0x1AC)  // Color 22 (sprite 2/3 color 2)
#define COLOR23  (DENISE_BASE + 0x1AE)  // Color 23 (sprite 2/3 color 3)
#define COLOR24  (DENISE_BASE + 0x1B0)  // Color 24
#define COLOR25  (DENISE_BASE + 0x1B2)  // Color 25 (sprite 4/5 color 1)
#define COLOR26  (DENISE_BASE + 0x1B4)  // Color 26 (sprite 4/5 color 2)
#define COLOR27  (DENISE_BASE + 0x1B6)  // Color 27 (sprite 4/5 color 3)
#define COLOR28  (DENISE_BASE + 0x1B8)  // Color 28
#define COLOR29  (DENISE_BASE + 0x1BA)  // Color 29 (sprite 6/7 color 1)
#define COLOR30  (DENISE_BASE + 0x1BC)  // Color 30 (sprite 6/7 color 2)
#define COLOR31  (DENISE_BASE + 0x1BE)  // Color 31 (sprite 6/7 color 3)

// Enhanced AGA Color Registers
#define BPLCON4  (DENISE_BASE + 0x10C)  // Bitplane control 4 (AGA)
#define CLXCON2  (DENISE_BASE + 0x10E)  // Extended collision control (AGA)

// Denise ID Register (Read-only)
#define DENISEID (DENISE_BASE + 0x07C)  // Denise chip revision level

// Sprite Control Register Bits (SPRxCTL)
#define SPRCTL_ATTACH  0x0080  // Attach to next sprite
#define SPRCTL_VSTRT0  0x0001  // Vertical start bit 0
#define SPRCTL_VSTRT1  0x0002  // Vertical start bit 1
#define SPRCTL_VSTRT2  0x0004  // Vertical start bit 2
#define SPRCTL_VSTRT3  0x0008  // Vertical start bit 3
#define SPRCTL_VSTRT4  0x0010  // Vertical start bit 4
#define SPRCTL_VSTRT5  0x0020  // Vertical start bit 5
#define SPRCTL_VSTRT6  0x0040  // Vertical start bit 6
#define SPRCTL_VSTOP0  0x0100  // Vertical stop bit 0
#define SPRCTL_VSTOP1  0x0200  // Vertical stop bit 1
#define SPRCTL_VSTOP2  0x0400  // Vertical stop bit 2
#define SPRCTL_VSTOP3  0x0800  // Vertical stop bit 3
#define SPRCTL_VSTOP4  0x1000  // Vertical stop bit 4
#define SPRCTL_VSTOP5  0x2000  // Vertical stop bit 5
#define SPRCTL_VSTOP6  0x4000  // Vertical stop bit 6

// Sprite Position Register Bits (SPRxPOS)
#define SPRPOS_HSTRT0  0x0001  // Horizontal start bit 0
#define SPRPOS_HSTRT1  0x0002  // Horizontal start bit 1
#define SPRPOS_HSTRT2  0x0004  // Horizontal start bit 2
#define SPRPOS_HSTRT3  0x0008  // Horizontal start bit 3
#define SPRPOS_HSTRT4  0x0010  // Horizontal start bit 4
#define SPRPOS_HSTRT5  0x0020  // Horizontal start bit 5
#define SPRPOS_HSTRT6  0x0040  // Horizontal start bit 6
#define SPRPOS_HSTRT7  0x0080  // Horizontal start bit 7
#define SPRPOS_HSTRT8  0x0100  // Horizontal start bit 8
#define SPRPOS_VSTRT0  0x0200  // Vertical start bit 0 (continued)
#define SPRPOS_VSTRT1  0x0400  // Vertical start bit 1 (continued)
#define SPRPOS_VSTRT2  0x0800  // Vertical start bit 2 (continued)
#define SPRPOS_VSTRT3  0x1000  // Vertical start bit 3 (continued)
#define SPRPOS_VSTRT4  0x2000  // Vertical start bit 4 (continued)
#define SPRPOS_VSTRT5  0x4000  // Vertical start bit 5 (continued)
#define SPRPOS_VSTRT6  0x8000  // Vertical start bit 6 (continued)

// BPLCON2 register bits (Priority and Video Control)
#define BPLCON2_PF2PRI   0x40    // Playfield 2 priority over playfield 1
#define BPLCON2_PF2P2    0x20    // Playfield 2 priority bit 2
#define BPLCON2_PF2P1    0x10    // Playfield 2 priority bit 1
#define BPLCON2_PF2P0    0x08    // Playfield 2 priority bit 0
#define BPLCON2_PF1P2    0x04    // Playfield 1 priority bit 2
#define BPLCON2_PF1P1    0x02    // Playfield 1 priority bit 1
#define BPLCON2_PF1P0    0x01    // Playfield 1 priority bit 0

// BPLCON3 register bits (Enhanced Features)
#define BPLCON3_EXTBLKEN 0x80    // External blank enable
#define BPLCON3_BRDNTRAN 0x40    // Border not transparent
#define BPLCON3_BRDBLNK  0x20    // Border blank
#define BPLCON3_SPRES1   0x10    // Sprite resolution bit 1
#define BPLCON3_SPRES0   0x08    // Sprite resolution bit 0
#define BPLCON3_PIXE1    0x04    // Pixel clock enable bit 1
#define BPLCON3_PIXE0    0x02    // Pixel clock enable bit 0
#define BPLCON3_COLORON  0x01    // Color on

// BPLCON4 register bits (AGA Enhanced Features)
#define BPLCON4_SPOV0    0x0001  // Sprite pointer override bit 0
#define BPLCON4_SPOV1    0x0002  // Sprite pointer override bit 1
#define BPLCON4_SPOV2    0x0004  // Sprite pointer override bit 2
#define BPLCON4_SPOV3    0x0008  // Sprite pointer override bit 3
#define BPLCON4_BPOV0    0x0010  // Bitplane pointer override bit 0
#define BPLCON4_BPOV1    0x0020  // Bitplane pointer override bit 1
#define BPLCON4_BPOV2    0x0040  // Bitplane pointer override bit 2
#define BPLCON4_BPOV3    0x0080  // Bitplane pointer override bit 3

// CLXCON register bits (Collision Control)
#define CLXCON_SPR0EN    0x0001  // Sprite 0 enable
#define CLXCON_SPR1EN    0x0002  // Sprite 1 enable
#define CLXCON_SPR2EN    0x0004  // Sprite 2 enable
#define CLXCON_SPR3EN    0x0008  // Sprite 3 enable
#define CLXCON_SPR4EN    0x0010  // Sprite 4 enable
#define CLXCON_SPR5EN    0x0020  // Sprite 5 enable
#define CLXCON_SPR6EN    0x0040  // Sprite 6 enable
#define CLXCON_SPR7EN    0x0080  // Sprite 7 enable
#define CLXCON_BPL0EN    0x0100  // Bitplane 0 enable
#define CLXCON_BPL1EN    0x0200  // Bitplane 1 enable
#define CLXCON_BPL2EN    0x0400  // Bitplane 2 enable
#define CLXCON_BPL3EN    0x0800  // Bitplane 3 enable
#define CLXCON_BPL4EN    0x1000  // Bitplane 4 enable
#define CLXCON_BPL5EN    0x2000  // Bitplane 5 enable
#define CLXCON_BPL6EN    0x4000  // Bitplane 6 enable
#define CLXCON_BPL7EN    0x8000  // Bitplane 7 enable

// CLXCON2 register bits (Extended Collision Control - AGA)
#define CLXCON2_BPL8EN   0x0001  // Bitplane 8 enable
#define CLXCON2_BPL9EN   0x0002  // Bitplane 9 enable
#define CLXCON2_BPL10EN  0x0004  // Bitplane 10 enable
#define CLXCON2_BPL11EN  0x0008  // Bitplane 11 enable

// Color Register Format
#define COLOR_RGB_MASK   0x0FFF  // RGB color mask (12 bits: 4R+4G+4B)
#define COLOR_RED_MASK   0x0F00  // Red component mask
#define COLOR_GREEN_MASK 0x00F0  // Green component mask
#define COLOR_BLUE_MASK  0x000F  // Blue component mask
#define COLOR_RED_SHIFT  8       // Red component shift
#define COLOR_GREEN_SHIFT 4      // Green component shift
#define COLOR_BLUE_SHIFT 0       // Blue component shift

// Sprite Data Format
#define SPRITEDATA_MASK  0xFFFF  // Full 16-bit sprite data word
#define SPRITEDATA_EVEN  0xAAAA  // Even bits mask (sprite data A)
#define SPRITEDATA_ODD   0x5555  // Odd bits mask (sprite data B)

// Denise Revision Levels
#define DENISE_REVISION_A1000  0xFC  // A1000 revision level
#define DENISE_REVISION_OCS    0xF8  // Original Chip Set revision
#define DENISE_REVISION_ECS    0xF8  // Enhanced Chip Set revision
#define DENISE_REVISION_AGA    0xF8  // Advanced Graphics Architecture revision

// Sprite Priority Combinations
#define SPRITE_PRIORITY_LOWEST  0x00  // Lowest priority
#define SPRITE_PRIORITY_LOW     0x01  // Low priority
#define SPRITE_PRIORITY_MED     0x02  // Medium priority
#define SPRITE_PRIORITY_HIGH    0x03  // High priority
#define SPRITE_PRIORITY_HIGHEST 0x04  // Highest priority

// Playfield Priority Combinations
#define PF1_PRI_NORMAL    0x00  // Normal priority
#define PF1_PRI_HIGH      0x01  // High priority
#define PF1_PRI_HIGHER    0x02  // Higher priority
#define PF1_PRI_HIGHEST   0x03  // Highest priority
#define PF2_PRI_NORMAL    0x00  // Normal priority
#define PF2_PRI_HIGH      0x08  // High priority
#define PF2_PRI_HIGHER    0x10  // Higher priority
#define PF2_PRI_HIGHEST   0x18  // Highest priority

// Sprite Attachment Combinations
#define SPRITE_ATTACH_NONE    0x00  // No attachment
#define SPRITE_ATTACH_NEXT    0x80  // Attach to next sprite

// Sprite Vertical Start/Stop Value Combinations
#define SPRITE_VSTART_MIN   0x00  // Minimum vertical start
#define SPRITE_VSTART_MAX   0x7F  // Maximum vertical start (7 bits)
#define SPRITE_VSTOP_MIN    0x00  // Minimum vertical stop
#define SPRITE_VSTOP_MAX    0x7F  // Maximum vertical stop (7 bits)

// Sprite Horizontal Start Value Combinations
#define SPRITE_HSTART_MIN   0x00  // Minimum horizontal start
#define SPRITE_HSTART_MAX   0x01FF  // Maximum horizontal start (9 bits)

// Color Depth Modes
#define COLOR_DEPTH_2BIT    2     // 2-bit color depth (4 colors)
#define COLOR_DEPTH_4BIT    4     // 4-bit color depth (16 colors)
#define COLOR_DEPTH_6BIT    6     // 6-bit color depth (64 colors)
#define COLOR_DEPTH_8BIT    8     // 8-bit color depth (256 colors)
#define COLOR_DEPTH_12BIT   12    // 12-bit color depth (4096 colors - AGA)

// Sprite Modes
#define SPRITE_MODE_NORMAL  0     // Normal sprite mode
#define SPRITE_MODE_DUAL    1     // Dual sprite mode
#define SPRITE_MODE_QUAD    2     // Quad sprite mode (AGA)

// Sprite Resolution Modes
#define SPRITE_RES_LORES    0x00  // Low resolution (140ns)
#define SPRITE_RES_HIRES    0x08  // High resolution (70ns)
#define SPRITE_RES_SUPER    0x10  // Super high resolution (35ns - AGA)

#endif // ENHANCED_DENISE_H