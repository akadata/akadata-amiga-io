/*
 * SPDX-License-Identifier: MIT
 * 
 * DENISE chip register definitions for Amiga
 * Based on DENISE specification document and Amiga Hardware Reference Manual
 * Addresses: $DFF000-$DFF1FF (shared with other custom chips)
 */

#ifndef DENISE_H
#define DENISE_H

#include "amiga_custom_chips.h"

// DENISE base address is shared with other custom chips at 0xDFF000
#define DENISE_BASE 0xDFF000

// Bitplane Data Registers
#define BPL1DAT  (DENISE_BASE + 0x110)  // Bitplane 1 data (parallel to serial convert)
#define BPL2DAT  (DENISE_BASE + 0x112)  // Bitplane 2 data (parallel to serial convert)
#define BPL3DAT  (DENISE_BASE + 0x114)  // Bitplane 3 data (parallel to serial convert)
#define BPL4DAT  (DENISE_BASE + 0x116)  // Bitplane 4 data (parallel to serial convert)
#define BPL5DAT  (DENISE_BASE + 0x118)  // Bitplane 5 data (parallel to serial convert)
#define BPL6DAT  (DENISE_BASE + 0x11A)  // Bitplane 6 data (parallel to serial convert)
#define BPL7DAT  (DENISE_BASE + 0x11C)  // Bitplane 7 data (AGA only)
#define BPL8DAT  (DENISE_BASE + 0x11E)  // Bitplane 8 data (AGA only)

// Bitplane Control Registers
#define BPLCON0  (DENISE_BASE + 0x100)  // Bitplane control 0 (miscellaneous control bits)
#define BPLCON1  (DENISE_BASE + 0x102)  // Bitplane control 1 (horizontal scroll control)
#define BPLCON2  (DENISE_BASE + 0x104)  // Bitplane control 2 (video priority control)
#define BPLCON3  (DENISE_BASE + 0x106)  // Bitplane control 3 (enhanced features - ECS/AGA)
#define BPLCON4  (DENISE_BASE + 0x10C)  // Bitplane control 4 (AGA enhanced features)

// Display Window Registers
#define DIWSTRT  (DENISE_BASE + 0x08E)  // Display window start (upper left vertical-horizontal position)
#define DIWSTOP  (DENISE_BASE + 0x090)  // Display window stop (lower right vertical-horizontal position)
#define DDFSTRT  (DENISE_BASE + 0x092)  // Display data fetch start (horizontal position)
#define DDFSTOP  (DENISE_BASE + 0x094)  // Display data fetch stop (horizontal position)

// Sprite Position and Control Registers
#define SPR0POS  (DENISE_BASE + 0x140)  // Sprite 0 vertical-horizontal start position
#define SPR0CTL  (DENISE_BASE + 0x142)  // Sprite 0 vertical stop position and control
#define SPR0DATA (DENISE_BASE + 0x144)  // Sprite 0 image data register A
#define SPR0DATB (DENISE_BASE + 0x146)  // Sprite 0 image data register B

#define SPR1POS  (DENISE_BASE + 0x148)  // Sprite 1 vertical-horizontal start position
#define SPR1CTL  (DENISE_BASE + 0x14A)  // Sprite 1 vertical stop position and control
#define SPR1DATA (DENISE_BASE + 0x14C)  // Sprite 1 image data register A
#define SPR1DATB (DENISE_BASE + 0x14E)  // Sprite 1 image data register B

#define SPR2POS  (DENISE_BASE + 0x150)  // Sprite 2 vertical-horizontal start position
#define SPR2CTL  (DENISE_BASE + 0x152)  // Sprite 2 vertical stop position and control
#define SPR2DATA (DENISE_BASE + 0x154)  // Sprite 2 image data register A
#define SPR2DATB (DENISE_BASE + 0x156)  // Sprite 2 image data register B

#define SPR3POS  (DENISE_BASE + 0x158)  // Sprite 3 vertical-horizontal start position
#define SPR3CTL  (DENISE_BASE + 0x15A)  // Sprite 3 vertical stop position and control
#define SPR3DATA (DENISE_BASE + 0x15C)  // Sprite 3 image data register A
#define SPR3DATB (DENISE_BASE + 0x15E)  // Sprite 3 image data register B

#define SPR4POS  (DENISE_BASE + 0x160)  // Sprite 4 vertical-horizontal start position
#define SPR4CTL  (DENISE_BASE + 0x162)  // Sprite 4 vertical stop position and control
#define SPR4DATA (DENISE_BASE + 0x164)  // Sprite 4 image data register A
#define SPR4DATB (DENISE_BASE + 0x166)  // Sprite 4 image data register B

#define SPR5POS  (DENISE_BASE + 0x168)  // Sprite 5 vertical-horizontal start position
#define SPR5CTL  (DENISE_BASE + 0x16A)  // Sprite 5 vertical stop position and control
#define SPR5DATA (DENISE_BASE + 0x16C)  // Sprite 5 image data register A
#define SPR5DATB (DENISE_BASE + 0x16E)  // Sprite 5 image data register B

#define SPR6POS  (DENISE_BASE + 0x170)  // Sprite 6 vertical-horizontal start position
#define SPR6CTL  (DENISE_BASE + 0x172)  // Sprite 6 vertical stop position and control
#define SPR6DATA (DENISE_BASE + 0x174)  // Sprite 6 image data register A
#define SPR6DATB (DENISE_BASE + 0x176)  // Sprite 6 image data register B

#define SPR7POS  (DENISE_BASE + 0x178)  // Sprite 7 vertical-horizontal start position
#define SPR7CTL  (DENISE_BASE + 0x17A)  // Sprite 7 vertical stop position and control
#define SPR7DATA (DENISE_BASE + 0x17C)  // Sprite 7 image data register A
#define SPR7DATB (DENISE_BASE + 0x17E)  // Sprite 7 image data register B

// Color Palette Registers
#define COLOR00  (DENISE_BASE + 0x180)  // Color 00 (background/borders)
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

// Collision Detection Registers
#define CLXCON   (DENISE_BASE + 0x098)  // Collision control register
#define CLXDAT   (DENISE_BASE + 0x00E)  // Collision data register (read and clear)

// Denise ID Register
#define DENISEID (DENISE_BASE + 0x07C)  // Denise chip revision level (read-only)

// UHRES (Ultra High Resolution) Registers (ECS/AGA)
#define DIWHIGH  (DENISE_BASE + 0x1E4)  // Display window upper bits for start/stop

// BPLCON0 register bits
#define BPLCON0_HIRES      0x8000  // High resolution mode
#define BPLCON0_BPU2       0x4000  // Bitplane use code bit 2
#define BPLCON0_BPU1       0x2000  // Bitplane use code bit 1
#define BPLCON0_BPU0       0x1000  // Bitplane use code bit 0
#define BPLCON0_HOMOD      0x0800  // Hold and modify mode
#define BPLCON0_DBLPF      0x0400  // Double playfield
#define BPLCON0_COLOR      0x0200  // Color enable (composite video)
#define BPLCON0_GAUD       0x0100  // Genlock audio enable
#define BPLCON0_UHRES      0x0080  // Ultra high resolution
#define BPLCON0_SHRES      0x0040  // Super high resolution
#define BPLCON0_RESERVED   0x0020  // Reserved
#define BPLCON0_LACE       0x0010  // Interlace enable
#define BPLCON0_LPEN       0x0008  // Light pen enable
#define BPLCON0_ESY        0x0004  // External sync enable
#define BPLCON0_EVB        0x0002  // Even field/vertical blank bit
#define BPLCON0_DEN        0x0001  // Display enable

// BPLCON1 register bits (horizontal scroll)
#define BPLCON1_HSCROLL_MASK 0x000F  // Horizontal scroll mask (4 bits)
#define BPLCON1_HSCROLL_SHIFT 0      // Horizontal scroll shift amount

// BPLCON2 register bits (priority control)
#define BPLCON2_PF2PRI     0x40      // Playfield 2 priority over playfield 1
#define BPLCON2_PF2P2      0x20      // Playfield 2 priority bit 2
#define BPLCON2_PF2P1      0x10      // Playfield 2 priority bit 1
#define BPLCON2_PF2P0      0x08      // Playfield 2 priority bit 0
#define BPLCON2_PF1P2      0x04      // Playfield 1 priority bit 2
#define BPLCON2_PF1P1      0x02      // Playfield 1 priority bit 1
#define BPLCON2_PF1P0      0x01      // Playfield 1 priority bit 0

// BPLCON3 register bits (ECS/AGA features)
#define BPLCON3_EXTBLKEN   0x80      // External blank enable
#define BPLCON3_BRDNTRAN   0x40      // Border not transparent
#define BPLCON3_BRDBLNK    0x20      // Border blank
#define BPLCON3_SPRES1     0x10      // Sprite resolution bit 1
#define BPLCON3_SPRES0     0x08      // Sprite resolution bit 0
#define BPLCON3_PIXE1      0x04      // Pixel clock enable bit 1
#define BPLCON3_PIXE0      0x02      // Pixel clock enable bit 0
#define BPLCON3_COLORON    0x01      // Color on

// BPLCON4 register bits (AGA features)
#define BPLCON4_SPOV0      0x0001    // Sprite pointer override bit 0
#define BPLCON4_SPOV1      0x0002    // Sprite pointer override bit 1
#define BPLCON4_SPOV2      0x0004    // Sprite pointer override bit 2
#define BPLCON4_SPOV3      0x0008    // Sprite pointer override bit 3
#define BPLCON4_BPOV0      0x0010    // Bitplane pointer override bit 0
#define BPLCON4_BPOV1      0x0020    // Bitplane pointer override bit 1
#define BPLCON4_BPOV2      0x0040    // Bitplane pointer override bit 2
#define BPLCON4_BPOV3      0x0080    // Bitplane pointer override bit 3

// CLXCON register bits (collision control)
#define CLXCON_SPR0EN      0x0001    // Sprite 0 enable
#define CLXCON_SPR1EN      0x0002    // Sprite 1 enable
#define CLXCON_SPR2EN      0x0004    // Sprite 2 enable
#define CLXCON_SPR3EN      0x0008    // Sprite 3 enable
#define CLXCON_SPR4EN      0x0010    // Sprite 4 enable
#define CLXCON_SPR5EN      0x0020    // Sprite 5 enable
#define CLXCON_SPR6EN      0x0040    // Sprite 6 enable
#define CLXCON_SPR7EN      0x0080    // Sprite 7 enable
#define CLXCON_BPL0EN      0x0100    // Bitplane 0 enable
#define CLXCON_BPL1EN      0x0200    // Bitplane 1 enable
#define CLXCON_BPL2EN      0x0400    // Bitplane 2 enable
#define CLXCON_BPL3EN      0x0800    // Bitplane 3 enable
#define CLXCON_BPL4EN      0x1000    // Bitplane 4 enable
#define CLXCON_BPL5EN      0x2000    // Bitplane 5 enable
#define CLXCON_BPL6EN      0x4000    // Bitplane 6 enable (AGA)
#define CLXCON_BPL7EN      0x8000    // Bitplane 7 enable (AGA)

// CLXDAT register bits (collision data)
#define CLXDAT_SPR0_SPR1   0x0001    // Sprite 0 vs Sprite 1
#define CLXDAT_SPR0_SPR2   0x0002    // Sprite 0 vs Sprite 2
#define CLXDAT_SPR0_SPR3   0x0004    // Sprite 0 vs Sprite 3
#define CLXDAT_SPR0_SPR4   0x0008    // Sprite 0 vs Sprite 4
#define CLXDAT_SPR0_SPR5   0x0010    // Sprite 0 vs Sprite 5
#define CLXDAT_SPR0_SPR6   0x0020    // Sprite 0 vs Sprite 6
#define CLXDAT_SPR0_SPR7   0x0040    // Sprite 0 vs Sprite 7
#define CLXDAT_SPR1_SPR2   0x0080    // Sprite 1 vs Sprite 2
#define CLXDAT_SPR1_SPR3   0x0100    // Sprite 1 vs Sprite 3
#define CLXDAT_SPR1_SPR4   0x0200    // Sprite 1 vs Sprite 4
#define CLXDAT_SPR1_SPR5   0x0400    // Sprite 1 vs Sprite 5
#define CLXDAT_SPR1_SPR6   0x0800    // Sprite 1 vs Sprite 6
#define CLXDAT_SPR1_SPR7   0x1000    // Sprite 1 vs Sprite 7
#define CLXDAT_SPR2_SPR3   0x2000    // Sprite 2 vs Sprite 3
#define CLXDAT_SPR2_SPR4   0x4000    // Sprite 2 vs Sprite 4
#define CLXDAT_SPR2_SPR5   0x8000    // Sprite 2 vs Sprite 5
#define CLXDAT_SPR3_SPR4   0x0001    // Sprite 3 vs Sprite 4 (shifted)
#define CLXDAT_SPR3_SPR5   0x0002    // Sprite 3 vs Sprite 5 (shifted)
#define CLXDAT_SPR3_SPR6   0x0004    // Sprite 3 vs Sprite 6 (shifted)
#define CLXDAT_SPR3_SPR7   0x0008    // Sprite 3 vs Sprite 7 (shifted)
#define CLXDAT_SPR4_SPR5   0x0010    // Sprite 4 vs Sprite 5 (shifted)
#define CLXDAT_SPR4_SPR6   0x0020    // Sprite 4 vs Sprite 6 (shifted)
#define CLXDAT_SPR4_SPR7   0x0040    // Sprite 4 vs Sprite 7 (shifted)
#define CLXDAT_SPR5_SPR6   0x0080    // Sprite 5 vs Sprite 6 (shifted)
#define CLXDAT_SPR5_SPR7   0x0100    // Sprite 5 vs Sprite 7 (shifted)
#define CLXDAT_SPR6_SPR7   0x0200    // Sprite 6 vs Sprite 7 (shifted)

// Bitplane vs Sprite collision bits
#define CLXDAT_BPL0_SPR0   0x0001    // Bitplane 0 vs Sprite 0
#define CLXDAT_BPL0_SPR1   0x0002    // Bitplane 0 vs Sprite 1
#define CLXDAT_BPL0_SPR2   0x0004    // Bitplane 0 vs Sprite 2
#define CLXDAT_BPL0_SPR3   0x0008    // Bitplane 0 vs Sprite 3
#define CLXDAT_BPL0_SPR4   0x0010    // Bitplane 0 vs Sprite 4
#define CLXDAT_BPL0_SPR5   0x0020    // Bitplane 0 vs Sprite 5
#define CLXDAT_BPL0_SPR6   0x0040    // Bitplane 0 vs Sprite 6
#define CLXDAT_BPL0_SPR7   0x0080    // Bitplane 0 vs Sprite 7
#define CLXDAT_BPL1_SPR0   0x0100    // Bitplane 1 vs Sprite 0
#define CLXDAT_BPL1_SPR1   0x0200    // Bitplane 1 vs Sprite 1
#define CLXDAT_BPL1_SPR2   0x0400    // Bitplane 1 vs Sprite 2
#define CLXDAT_BPL1_SPR3   0x0800    // Bitplane 1 vs Sprite 3
#define CLXDAT_BPL1_SPR4   0x1000    // Bitplane 1 vs Sprite 4
#define CLXDAT_BPL1_SPR5   0x2000    // Bitplane 1 vs Sprite 5
#define CLXDAT_BPL1_SPR6   0x4000    // Bitplane 1 vs Sprite 6
#define CLXDAT_BPL1_SPR7   0x8000    // Bitplane 1 vs Sprite 7

// Bitplane vs Bitplane collision bits
#define CLXDAT_BPL0_BPL1   0x0001    // Bitplane 0 vs Bitplane 1
#define CLXDAT_BPL0_BPL2   0x0002    // Bitplane 0 vs Bitplane 2
#define CLXDAT_BPL0_BPL3   0x0004    // Bitplane 0 vs Bitplane 3
#define CLXDAT_BPL0_BPL4   0x0008    // Bitplane 0 vs Bitplane 4
#define CLXDAT_BPL0_BPL5   0x0010    // Bitplane 0 vs Bitplane 5
#define CLXDAT_BPL0_BPL6   0x0020    // Bitplane 0 vs Bitplane 6
#define CLXDAT_BPL1_BPL2   0x0040    // Bitplane 1 vs Bitplane 2
#define CLXDAT_BPL1_BPL3   0x0080    // Bitplane 1 vs Bitplane 3
#define CLXDAT_BPL1_BPL4   0x0100    // Bitplane 1 vs Bitplane 4
#define CLXDAT_BPL1_BPL5   0x0200    // Bitplane 1 vs Bitplane 5
#define CLXDAT_BPL1_BPL6   0x0400    // Bitplane 1 vs Bitplane 6
#define CLXDAT_BPL2_BPL3   0x0800    // Bitplane 2 vs Bitplane 3
#define CLXDAT_BPL2_BPL4   0x1000    // Bitplane 2 vs Bitplane 4
#define CLXDAT_BPL2_BPL5   0x2000    // Bitplane 2 vs Bitplane 5
#define CLXDAT_BPL2_BPL6   0x4000    // Bitplane 2 vs Bitplane 6
#define CLXDAT_BPL3_BPL4   0x8000    // Bitplane 3 vs Bitplane 4

// Sprite control register bits
#define SPRCTL_ATTACH      0x0080    // Attach to next sprite
#define SPRCTL_VSTRT7      0x0040    // Vertical start bit 7
#define SPRCTL_VSTRT6      0x0020    // Vertical start bit 6
#define SPRCTL_VSTRT5      0x0010    // Vertical start bit 5
#define SPRCTL_VSTRT4      0x0008    // Vertical start bit 4
#define SPRCTL_VSTRT3      0x0004    // Vertical start bit 3
#define SPRCTL_VSTRT2      0x0002    // Vertical start bit 2
#define SPRCTL_VSTRT1      0x0001    // Vertical start bit 1
#define SPRCTL_VSTOP7      0x8000    // Vertical stop bit 7
#define SPRCTL_VSTOP6      0x4000    // Vertical stop bit 6
#define SPRCTL_VSTOP5      0x2000    // Vertical stop bit 5
#define SPRCTL_VSTOP4      0x1000    // Vertical stop bit 4
#define SPRCTL_VSTOP3      0x0800    // Vertical stop bit 3
#define SPRCTL_VSTOP2      0x0400    // Vertical stop bit 2
#define SPRCTL_VSTOP1      0x0200    // Vertical stop bit 1
#define SPRCTL_VSTOP0      0x0100    // Vertical stop bit 0

// Color register format
#define COLOR_RGB_MASK     0x0FFF    // RGB color mask (12 bits: 4R+4G+4B)
#define COLOR_RED_MASK     0x0F00    // Red component mask
#define COLOR_GREEN_MASK   0x00F0    // Green component mask
#define COLOR_BLUE_MASK    0x000F    // Blue component mask
#define COLOR_RED_SHIFT    8         // Red component shift
#define COLOR_GREEN_SHIFT  4         // Green component shift
#define COLOR_BLUE_SHIFT   0         // Blue component shift

// Denise revision levels
#define DENISE_REVISION_A1000  0xFC    // A1000 revision level
#define DENISE_REVISION_OCS    0xF8    // Original Chip Set revision
#define DENISE_REVISION_ECS    0xF8    // Enhanced Chip Set revision
#define DENISE_REVISION_AGA    0xFB    // Advanced Graphics Architecture revision

// Function prototypes for DENISE register access
extern uint16_t denise_read_register(uint32_t addr);
extern void denise_write_register(uint32_t addr, uint16_t value);
extern void denise_set_color(uint8_t color_num, uint16_t color_value);
extern uint16_t denise_get_color(uint8_t color_num);
extern void denise_set_bplcon0(uint16_t value);
extern void denise_set_bplcon1(uint16_t value);
extern void denise_set_bplcon2(uint16_t value);
extern void denise_set_sprite_position(int sprite_num, uint16_t hpos, uint16_t vpos);
extern void denise_set_sprite_control(int sprite_num, uint16_t control);
extern uint16_t denise_get_collision_data(void);
extern void denise_clear_collision_data(void);
extern void denise_set_collision_control(uint16_t mask);

#endif // DENISE_H