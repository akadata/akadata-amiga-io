/*
 * SPDX-License-Identifier: MIT
 * 
 * Enhanced AGNUS chip register definitions for Amiga
 * Based on Amiga Hardware Reference Manual and AGNUS specification (390544)
 * Includes all registers from the official specification document
 */

#ifndef ENHANCED_AGNUS_H
#define ENHANCED_AGNUS_H

#include "amiga_custom_chips.h"

// AGNUS base address is 0xDFF000
#ifndef AGNUS_BASE
#define AGNUS_BASE 0xDFF000
#endif

// DMA Control Registers
#ifndef DMACONR
#define DMACONR  (AGNUS_BASE + 0x002)  // Read DMA control / blitter status
#endif
#ifndef DMACON
#define DMACON   (AGNUS_BASE + 0x096)  // Write DMA control (set/clear)
#endif

// Beam Position Registers
#define VPOSR    (AGNUS_BASE + 0x004)  // Read vertical MSB + frame flop
#define VHPOSR   (AGNUS_BASE + 0x006)  // Read vertical/horizontal beam position
#define VPOSW    (AGNUS_BASE + 0x02A)  // Write vertical MSB + frame flop
#define VHPOSW   (AGNUS_BASE + 0x02C)  // Write vertical/horizontal position

// Display Window / Data Fetch
#define DIWSTRT  (AGNUS_BASE + 0x08E)  // Display window start
#define DIWSTOP  (AGNUS_BASE + 0x090)  // Display window stop
#define DDFSTRT  (AGNUS_BASE + 0x092)  // Display data fetch start (horizontal)
#define DDFSTOP  (AGNUS_BASE + 0x094)  // Display data fetch stop (horizontal)

// Copper Registers
#define COPCON   (AGNUS_BASE + 0x02E)  // Copper control (CDANG)
#define COP1LCH  (AGNUS_BASE + 0x080)  // Copper list 1 pointer high
#define COP1LCL  (AGNUS_BASE + 0x082)  // Copper list 1 pointer low
#define COP2LCH  (AGNUS_BASE + 0x084)  // Copper list 2 pointer high
#define COP2LCL  (AGNUS_BASE + 0x086)  // Copper list 2 pointer low
#define COPJMP1  (AGNUS_BASE + 0x088)  // Copper restart 1
#define COPJMP2  (AGNUS_BASE + 0x08A)  // Copper restart 2
#define COPINS   (AGNUS_BASE + 0x08C)  // Copper instruction fetch identify

// Bitplane Pointers (DMA)
#define BPL1PTH  (AGNUS_BASE + 0x0E0)  // Bitplane 1 pointer high
#define BPL1PTL  (AGNUS_BASE + 0x0E2)  // Bitplane 1 pointer low
#define BPL2PTH  (AGNUS_BASE + 0x0E4)  // Bitplane 2 pointer high
#define BPL2PTL  (AGNUS_BASE + 0x0E6)  // Bitplane 2 pointer low
#define BPL3PTH  (AGNUS_BASE + 0x0E8)  // Bitplane 3 pointer high
#define BPL3PTL  (AGNUS_BASE + 0x0EA)  // Bitplane 3 pointer low
#define BPL4PTH  (AGNUS_BASE + 0x0EC)  // Bitplane 4 pointer high
#define BPL4PTL  (AGNUS_BASE + 0x0EE)  // Bitplane 4 pointer low
#define BPL5PTH  (AGNUS_BASE + 0x0F0)  // Bitplane 5 pointer high
#define BPL5PTL  (AGNUS_BASE + 0x0F2)  // Bitplane 5 pointer low
#define BPL6PTH  (AGNUS_BASE + 0x0F4)  // Bitplane 6 pointer high
#define BPL6PTL  (AGNUS_BASE + 0x0F6)  // Bitplane 6 pointer low

// Bitplane Modulo Registers
#define BPL1MOD  (AGNUS_BASE + 0x108)  // Bitplane 1 modulo
#define BPL2MOD  (AGNUS_BASE + 0x10A)  // Bitplane 2 modulo

// Bitplane Control Registers
#define BPLCON0  (AGNUS_BASE + 0x100)  // Bitplane control 0
#define BPLCON1  (AGNUS_BASE + 0x102)  // Bitplane control 1
#define BPLCON2  (AGNUS_BASE + 0x104)  // Bitplane control 2
#define BPLCON3  (AGNUS_BASE + 0x106)  // Bitplane control 3

// Bitplane Data Registers
#define BPL1DAT  (AGNUS_BASE + 0x110)  // Bitplane 1 data
#define BPL2DAT  (AGNUS_BASE + 0x112)  // Bitplane 2 data
#define BPL3DAT  (AGNUS_BASE + 0x114)  // Bitplane 3 data
#define BPL4DAT  (AGNUS_BASE + 0x116)  // Bitplane 4 data
#define BPL5DAT  (AGNUS_BASE + 0x118)  // Bitplane 5 data
#define BPL6DAT  (AGNUS_BASE + 0x11A)  // Bitplane 6 data

// ECS Beam / Timing Registers
#define HTOTAL   (AGNUS_BASE + 0x1C0)  // Horizontal line count (ECS)
#define HSSTOP   (AGNUS_BASE + 0x1C2)  // HSYNC stop (ECS)
#define HBSTRT   (AGNUS_BASE + 0x1C4)  // HBLANK start (ECS)
#define HBSTOP   (AGNUS_BASE + 0x1C6)  // HBLANK stop (ECS)
#define VTOTAL   (AGNUS_BASE + 0x1C8)  // Vertical line count (ECS)
#define VSSTOP   (AGNUS_BASE + 0x1CA)  // VSYNC stop (ECS)
#define VBSTRT   (AGNUS_BASE + 0x1CC)  // VBLANK start (ECS)
#define VBSTOP   (AGNUS_BASE + 0x1CE)  // VBLANK stop (ECS)
#define BEAMCON0 (AGNUS_BASE + 0x1DC)  // Beam counter control (ECS)
#define HSSTRT   (AGNUS_BASE + 0x1DE)  // HSYNC start (ECS)
#define VSSTRT   (AGNUS_BASE + 0x1E0)  // VSYNC start (ECS)
#define HCENTER  (AGNUS_BASE + 0x1E2)  // Horizontal position for Vsync on interlace (ECS)
#define DIWHIGH  (AGNUS_BASE + 0x1E4)  // Display window upper bits (ECS)

// UHRES (Ultra High Resolution) Registers
#define SPRHSTRT (AGNUS_BASE + 0x1D0)  // UHRES sprite vertical start
#define SPRHSTOP (AGNUS_BASE + 0x1D2)  // UHRES sprite vertical stop
#define BPLHSTRT (AGNUS_BASE + 0x1D4)  // UHRES bitplane vertical start
#define BPLHSTOP (AGNUS_BASE + 0x1D6)  // UHRES bitplane vertical stop
#define HHPOSW   (AGNUS_BASE + 0x1D8)  // DUAL mode hires H beam counter write
#define HHPOSR   (AGNUS_BASE + 0x1DA)  // DUAL mode hires H beam counter read
#define BPLHMOD  (AGNUS_BASE + 0x1E6)  // UHRES bitplane modulo
#define SPRHPTH  (AGNUS_BASE + 0x1E8)  // UHRES sprite pointer high
#define SPRHPTL  (AGNUS_BASE + 0x1EA)  // UHRES sprite pointer low
#define BPLHPTH  (AGNUS_BASE + 0x1EC)  // VRAM (UHRES) bitplane pointer high
#define BPLHPTL  (AGNUS_BASE + 0x1EE)  // VRAM (UHRES) bitplane pointer low

// Blitter Registers
#define BLTCON0  (AGNUS_BASE + 0x040)  // Blitter control 0
#define BLTCON1  (AGNUS_BASE + 0x042)  // Blitter control 1
#define BLTAFWM  (AGNUS_BASE + 0x044)  // First word mask (source A)
#define BLTALWM  (AGNUS_BASE + 0x046)  // Last word mask (source A)

// Blitter Pointer Registers
#define BLTCPTH  (AGNUS_BASE + 0x048)  // Source C pointer high
#define BLTCPTL  (AGNUS_BASE + 0x04A)  // Source C pointer low
#define BLTBPTH  (AGNUS_BASE + 0x04C)  // Source B pointer high
#define BLTBPTL  (AGNUS_BASE + 0x04E)  // Source B pointer low
#define BLTAPTH  (AGNUS_BASE + 0x050)  // Source A pointer high
#define BLTAPTL  (AGNUS_BASE + 0x052)  // Source A pointer low
#define BLTDPTH  (AGNUS_BASE + 0x054)  // Destination D pointer high
#define BLTDPTL  (AGNUS_BASE + 0x056)  // Destination D pointer low

// Blitter Size and Control Registers
#define BLTSIZE  (AGNUS_BASE + 0x058)  // Start and size (width/height)
#define BLTCON0L (AGNUS_BASE + 0x05A)  // Lower 8 bits of BLTCON0 (minterms)
#define BLTSIZV  (AGNUS_BASE + 0x05C)  // Vertical size (15-bit height)
#define BLTSIZH  (AGNUS_BASE + 0x05E)  // Horizontal size/start (11-bit width)

// Blitter Modulo Registers
#define BLTCMOD  (AGNUS_BASE + 0x060)  // Modulo source C
#define BLTBMOD  (AGNUS_BASE + 0x062)  // Modulo source B
#define BLTAMOD  (AGNUS_BASE + 0x064)  // Modulo source A
#define BLTDMOD  (AGNUS_BASE + 0x066)  // Modulo destination D

// Blitter Data Registers
#define BLTCDAT  (AGNUS_BASE + 0x070)  // Source C data
#define BLTBDAT  (AGNUS_BASE + 0x072)  // Source B data
#define BLTADAT  (AGNUS_BASE + 0x074)  // Source A data

// Blitter Early Read (Dummy Address)
#define BLTDDAT  (AGNUS_BASE + 0x000)  // Blitter destination early read (dummy address)

// Sprite Pointers (DMA)
#define SPR0PTH  (AGNUS_BASE + 0x120)  // Sprite 0 pointer high
#define SPR0PTL  (AGNUS_BASE + 0x122)  // Sprite 0 pointer low
#define SPR1PTH  (AGNUS_BASE + 0x124)  // Sprite 1 pointer high
#define SPR1PTL  (AGNUS_BASE + 0x126)  // Sprite 1 pointer low
#define SPR2PTH  (AGNUS_BASE + 0x128)  // Sprite 2 pointer high
#define SPR2PTL  (AGNUS_BASE + 0x12A)  // Sprite 2 pointer low
#define SPR3PTH  (AGNUS_BASE + 0x12C)  // Sprite 3 pointer high
#define SPR3PTL  (AGNUS_BASE + 0x12E)  // Sprite 3 pointer low
#define SPR4PTH  (AGNUS_BASE + 0x130)  // Sprite 4 pointer high
#define SPR4PTL  (AGNUS_BASE + 0x132)  // Sprite 4 pointer low
#define SPR5PTH  (AGNUS_BASE + 0x134)  // Sprite 5 pointer high
#define SPR5PTL  (AGNUS_BASE + 0x136)  // Sprite 5 pointer low
#define SPR6PTH  (AGNUS_BASE + 0x138)  // Sprite 6 pointer high
#define SPR6PTL  (AGNUS_BASE + 0x13A)  // Sprite 6 pointer low
#define SPR7PTH  (AGNUS_BASE + 0x13C)  // Sprite 7 pointer high
#define SPR7PTL  (AGNUS_BASE + 0x13E)  // Sprite 7 pointer low

// UHRES Bitplane and Sprite Registers (AGA)
#define BPLHPTH  (AGNUS_BASE + 0x1EC)  // UHRES bitplane pointer high
#define BPLHPTL  (AGNUS_BASE + 0x1EE)  // UHRES bitplane pointer low
#define SPRHPTH  (AGNUS_BASE + 0x1E8)  // UHRES sprite pointer high
#define SPRHPTL  (AGNUS_BASE + 0x1EA)  // UHRES sprite pointer low
#define BPLHMOD  (AGNUS_BASE + 0x1E6)  // UHRES bitplane modulo
#define SPRHSTRT (AGNUS_BASE + 0x1D0)  // UHRES sprite vertical start
#define SPRHSTOP (AGNUS_BASE + 0x1D2)  // UHRES sprite vertical stop
#define BPLHSTRT (AGNUS_BASE + 0x1D4)  // UHRES bitplane vertical start
#define BPLHSTOP (AGNUS_BASE + 0x1D6)  // UHRES bitplane vertical stop
#define HHPOSW   (AGNUS_BASE + 0x1D8)  // DUAL mode hires H beam counter write
#define HHPOSR   (AGNUS_BASE + 0x1DA)  // DUAL mode hires H beam counter read

// Additional AGA registers
#define BPLHDT   (AGNUS_BASE + 0x07A)  // UHRES bitplane data identifier
#define SPRHDT   (AGNUS_BASE + 0x078)  // UHRES sprite data identifier
#define BPLHPTR  (AGNUS_BASE + 0x1EC)  // UHRES bitplane pointer (high)
#define SPRHPTR  (AGNUS_BASE + 0x1E8)  // UHRES sprite pointer (high)

// Fetch Mode Register (AGA)
#define FMODE    (AGNUS_BASE + 0x1FC)  // Fetch mode register

// No Operation Register
#define NOOP     (AGNUS_BASE + 0x1FE)  // No operation/NULL (Copper NOP instruction)

// Refresh
#define REFPTR   (AGNUS_BASE + 0x028)  // DRAM refresh pointer (test use only)

// Strobe Registers
#define STREQU   (AGNUS_BASE + 0x038)  // Strobe for horiz sync with VB and EQU
#define STRVBL   (AGNUS_BASE + 0x03A)  // Strobe for horiz sync with VB
#define STRHOR   (AGNUS_BASE + 0x03C)  // Strobe for horiz sync
#define STRLONG  (AGNUS_BASE + 0x03E)  // Strobe for identification of long horiz line

// DMA Control Bits (DMACON/DMACONR)
#define DMAF_SETCLR   0x8000  // Set/Clear control bit
#define DMAF_AUDIO    0x000F  // Mask for AUD0..AUD3
#define DMAF_AUD0     0x0001  // Audio channel 0 enable
#define DMAF_AUD1     0x0002  // Audio channel 1 enable
#define DMAF_AUD2     0x0004  // Audio channel 2 enable
#define DMAF_AUD3     0x0008  // Audio channel 3 enable
#define DMAF_DISK     0x0010  // Disk DMA enable
#define DMAF_SPRITE   0x0020  // Sprite DMA enable
#define DMAF_BLITTER  0x0040  // Blitter DMA enable
#define DMAF_COPPER   0x0080  // Copper DMA enable
#define DMAF_RASTER   0x0100  // Raster DMA enable
#define DMAF_MASTER   0x0200  // Master DMA enable
#define DMAF_BLITHOG  0x0400  // Blitter hog CPU (priority)
#define DMAF_ALL      0x01FF  // All DMA channels

// DMACONR specific bits
#define DMAF_BLTDONE  0x4000  // Blitter done
#define DMAF_BLTNZERO 0x2000  // Blitter not zero (busy)

// Bit numbers for DMACON operations
#define DMAB_AUD0     0
#define DMAB_AUD1     1
#define DMAB_AUD2     2
#define DMAB_AUD3     3
#define DMAB_DISK     4
#define DMAB_SPRITE   5
#define DMAB_BLITTER  6
#define DMAB_COPPER   7
#define DMAB_RASTER   8
#define DMAB_MASTER   9
#define DMAB_BLITHOG  10
#define DMAB_BLTNZERO 13
#define DMAB_BLTDONE  14
#define DMAB_SETCLR   15

// BPLCON0 register bits
#define BPLCON0_HIRES     0x8000  // High resolution mode
#define BPLCON0_BPU2      0x4000  // Bitplane use bit 2
#define BPLCON0_BPU1      0x2000  // Bitplane use bit 1
#define BPLCON0_BPU0      0x1000  // Bitplane use bit 0
#define BPLCON0_HOMOD     0x0800  // Hold and modify mode
#define BPLCON0_DBLPF     0x0400  // Double playfield
#define BPLCON0_COLOR     0x0200  // Color enable
#define BPLCON0_GAUD      0x0100  // Genlock audio enable
#define BPLCON0_UHRES     0x0080  // Ultra high resolution
#define BPLCON0_SHRES     0x0040  // Super high resolution
#define BPLCON0_BPEN      0x0020  // Bitplane enable
#define BPLCON0_LACE      0x0010  // Interlace enable
#define BPLCON0_LPEN      0x0008  // Light pen enable
#define BPLCON0_ESY       0x0004  // External sync enable
#define BPLCON0_EVB       0x0002  // Even field/vertical blank bit
#define BPLCON0_DIS       0x0001  // Display disable

// BPLCON1 register bits (horizontal scroll)
#define BPLCON1_HSCROLL_MASK 0x000F  // Horizontal scroll mask (4 bits)
#define BPLCON1_HSCROLL_SHIFT 0      // Horizontal scroll shift amount

// BPLCON2 register bits (priority control)
#define BPLCON2_PF2PRI    0x40      // Playfield 2 priority over playfield 1
#define BPLCON2_PF2P2     0x20      // Playfield 2 priority bit 2
#define BPLCON2_PF2P1     0x10      // Playfield 2 priority bit 1
#define BPLCON2_PF2P0     0x08      // Playfield 2 priority bit 0
#define BPLCON2_PF1P2     0x04      // Playfield 1 priority bit 2
#define BPLCON2_PF1P1     0x02      // Playfield 1 priority bit 1
#define BPLCON2_PF1P0     0x01      // Playfield 1 priority bit 0

// BPLCON3 register bits (enhanced features)
#define BPLCON3_EXTBLKEN  0x80      // External blank enable
#define BPLCON3_BRDNTRAN  0x40      // Border not transparent
#define BPLCON3_BRDBLNK   0x20      // Border blank
#define BPLCON3_SPRES1    0x10      // Sprite resolution bit 1
#define BPLCON3_SPRES0    0x08      // Sprite resolution bit 0
#define BPLCON3_PIXE1     0x04      // Pixel clock enable bit 1
#define BPLCON3_PIXE0     0x02      // Pixel clock enable bit 0
#define BPLCON3_COLORON   0x01      // Color on

// BEAMCON0 register bits (ECS)
#define BEAMCON0_VARVBLANK 0x8000  // Variable VBLANK enable
#define BEAMCON0_VARHSYNC  0x4000  // Variable HSYNC enable
#define BEAMCON0_VARVSYNC  0x2000  // Variable VSYNC enable
#define BEAMCON0_VARBEAMEN 0x1000  // Variable beam counter enable
#define BEAMCON0_CSAOE     0x0800  // Composite sync active when output enabled
#define BEAMCON0_CSAE      0x0400  // Composite sync active enable
#define BEAMCON0_DBLRST    0x0200  // Double resolution pointer chain reset
#define BEAMCON0_MFPTR     0x0100  // Master pointer chain reset
#define BEAMCON0_HBOE      0x0080  // HBLANK output enable
#define BEAMCON0_VBOE      0x0040  // VBLANK output enable
#define BEAMCON0_CSOE      0x0020  // Composite sync output enable
#define BEAMCON0_HSYE      0x0010  // HSYNC output enable
#define BEAMCON0_VSYE      0x0008  // VSYNC output enable
#define BEAMCON0_BLKE      0x0004  // Blank output enable
#define BEAMCON0_DIS      0x0002   // Display disable
#define BEAMCON0_PAL      0x0001   // PAL mode

// Blitter Control 0 (BLTCON0) bits
#define BLTCON0_USEA      0x0001  // Use A channel
#define BLTCON0_USEB      0x0002  // Use B channel
#define BLTCON0_USEC      0x0004  // Use C channel
#define BLTCON0_USED      0x0008  // Use D channel
#define BLTCON0_SOLID     0x0010  // Solid pixels
#define BLTCON0_DRAW      0x0020  // Draw line
#define BLTCON0_LNPAF     0x0040  // Line draw pattern fill
#define BLTCON0_A_TO_D    0x0080  // A to D mode
#define BLTCON0_DESC      0x0100  // Descending mode
#define BLTCON0_FCMASK    0x0200  // Fill carry mask
#define BLTCON0_SHIFT0    0x0400  // Shift value bit 0
#define BLTCON0_SHIFT1    0x0800  // Shift value bit 1
#define BLTCON0_SHIFT2    0x1000  // Shift value bit 2
#define BLTCON0_SHIFT3    0x2000  // Shift value bit 3
#define BLTCON0_SHIFT4    0x4000  // Shift value bit 4

// Blitter Control 1 (BLTCON1) bits
#define BLTCON1_BBUSY     0x8000  // Blitter busy (read-only)
#define BLTCON1_FIRST     0x0002  // First word flag
#define BLTCON1_FILL      0x0004  // Fill mode
#define BLTCON1_E_LINE    0x0008  // End of line
#define BLTCON1_SIGN      0x0010  // Sign bit (line draw)
#define BLTCON1_ADI       0x0020  // A channel direction increment
#define BLTCON1_BDI       0x0040  // B channel direction increment
#define BLTCON1_CDI       0x0080  // C channel direction increment
#define BLTCON1_DDI       0x0100  // D channel direction increment
#define BLTCON1_ASH0      0x0200  // A shift bit 0
#define BLTCON1_ASH1      0x0400  // A shift bit 1
#define BLTCON1_ASH2      0x0800  // A shift bit 2
#define BLTCON1_BSH0      0x1000  // B shift bit 0
#define BLTCON1_BSH1      0x2000  // B shift bit 1
#define BLTCON1_BSH2      0x4000  // B shift bit 2

// Copper Control (COPCON) bits
#define COPCON_COPPER_DISABLE 0x0002  // Copper disable bit

// Lightpen enable bit in BPLCON0
#define BPLCON0_LPEN      0x0008  // Light pen enable

// Bitplane data register addresses for AGA (8 bitplanes)
#define BPL7PTH  (AGNUS_BASE + 0x0F8)  // Bitplane 7 pointer high (AGA)
#define BPL7PTL  (AGNUS_BASE + 0x0FA)  // Bitplane 7 pointer low (AGA)
#define BPL8PTH  (AGNUS_BASE + 0x0FC)  // Bitplane 8 pointer high (AGA)
#define BPL8PTL  (AGNUS_BASE + 0x0FE)  // Bitplane 8 pointer low (AGA)
#define BPL7DAT  (AGNUS_BASE + 0x11C)  // Bitplane 7 data (AGA)
#define BPL8DAT  (AGNUS_BASE + 0x11E)  // Bitplane 8 data (AGA)

// Additional AGA registers
#define BPLCON4  (AGNUS_BASE + 0x10C)  // Bitplane control 4 (AGA)
#define CLXCON2  (AGNUS_BASE + 0x10E)  // Extended collision control (AGA)

// BPLCON4 register bits (AGA)
#define BPLCON4_SPOV0     0x0001  // Sprite pointer override bit 0
#define BPLCON4_SPOV1     0x0002  // Sprite pointer override bit 1
#define BPLCON4_SPOV2     0x0004  // Sprite pointer override bit 2
#define BPLCON4_SPOV3     0x0008  // Sprite pointer override bit 3
#define BPLCON4_BPOV0     0x0010  // Bitplane pointer override bit 0
#define BPLCON4_BPOV1     0x0020  // Bitplane pointer override bit 1
#define BPLCON4_BPOV2     0x0040  // Bitplane pointer override bit 2
#define BPLCON4_BPOV3     0x0080  // Bitplane pointer override bit 3

// FMODE register bits (AGA)
#define FMODE_BURST       0x8000  // Fast page mode burst enable
#define FMODE_ESM         0x4000  // Extended shift mode
#define FMODE_ECS         0x2000  // ECS compatibility mode
#define FMODE_ERSY        0x1000  // External resync
#define FMODE_TEN         0x0800  // Timer enable
#define FMODE_LATE        0x0400  // Late address timing
#define FMODE_INVSE       0x0200  // Invert serial clock enable
#define FMODE_INVSO       0x0100  // Invert serial clock out
#define FMODE_THREE        0x0080  // Three voice mode
#define FMODE_SCH0         0x0040  // Serial clock high bit 0
#define FMODE_SCH1         0x0020  // Serial clock high bit 1
#define FMODE_SCH2         0x0010  // Serial clock high bit 2
#define FMODE_SCH3         0x0008  // Serial clock high bit 3
#define FMODE_SCH4         0x0004  // Serial clock high bit 4
#define FMODE_SCH5         0x0002  // Serial clock high bit 5
#define FMODE_SCH6         0x0001  // Serial clock high bit 6

#endif // ENHANCED_AGNUS_H