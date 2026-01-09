// SPDX-License-Identifier: MIT
// BLITTER chip register definitions for Amiga
// Based on Amiga Hardware Reference Manual (ADCD 2.1)

#ifndef BLITTER_H
#define BLITTER_H

// BLITTER base address is 0xDFF000
#ifndef BLITTER_BASE
#define BLITTER_BASE 0xDFF000
#endif

// Blitter Control Registers
#ifndef BLTCON0
#define BLTCON0  (BLITTER_BASE + 0x040)  // Blitter control 0
#endif
#ifndef BLTCON1
#define BLTCON1  (BLITTER_BASE + 0x042)  // Blitter control 1
#endif
#ifndef BLTAFWM
#define BLTAFWM  (BLITTER_BASE + 0x044)  // First word mask (source A)
#endif
#ifndef BLTALWM
#define BLTALWM  (BLITTER_BASE + 0x046)  // Last word mask (source A)
#endif

// Blitter Pointer Registers
#ifndef BLTCPTH
#define BLTCPTH  (BLITTER_BASE + 0x048)  // Source C pointer high
#endif
#ifndef BLTCPTL
#define BLTCPTL  (BLITTER_BASE + 0x04A)  // Source C pointer low
#endif
#ifndef BLTBPTH
#define BLTBPTH  (BLITTER_BASE + 0x04C)  // Source B pointer high
#endif
#ifndef BLTBPTL
#define BLTBPTL  (BLITTER_BASE + 0x04E)  // Source B pointer low
#endif
#ifndef BLTAPTH
#define BLTAPTH  (BLITTER_BASE + 0x050)  // Source A pointer high
#endif
#ifndef BLTAPTL
#define BLTAPTL  (BLITTER_BASE + 0x052)  // Source A pointer low
#endif
#ifndef BLTDPTH
#define BLTDPTH  (BLITTER_BASE + 0x054)  // Destination D pointer high
#endif
#ifndef BLTDPTL
#define BLTDPTL  (BLITTER_BASE + 0x056)  // Destination D pointer low
#endif

// Blitter Size and Control Registers
#ifndef BLTSIZE
#define BLTSIZE  (BLITTER_BASE + 0x058)  // Start and size (width/height)
#endif
#ifndef BLTCON0L
#define BLTCON0L (BLITTER_BASE + 0x05A)  // Lower 8 bits of BLTCON0 (minterms)
#endif
#ifndef BLTSIZV
#define BLTSIZV  (BLITTER_BASE + 0x05C)  // Vertical size (15-bit height)
#endif
#ifndef BLTSIZH
#define BLTSIZH  (BLITTER_BASE + 0x05E)  // Horizontal size/start (11-bit width)
#endif

// Blitter Modulo Registers
#ifndef BLTCMOD
#define BLTCMOD  (BLITTER_BASE + 0x060)  // Modulo source C
#endif
#ifndef BLTBMOD
#define BLTBMOD  (BLITTER_BASE + 0x062)  // Modulo source B
#endif
#ifndef BLTAMOD
#define BLTAMOD  (BLITTER_BASE + 0x064)  // Modulo source A
#endif
#ifndef BLTDMOD
#define BLTDMOD  (BLITTER_BASE + 0x066)  // Modulo destination D
#endif

// Blitter Data Registers
#ifndef BLTCDAT
#define BLTCDAT  (BLITTER_BASE + 0x070)  // Source C data
#endif
#ifndef BLTBDAT
#define BLTBDAT  (BLITTER_BASE + 0x072)  // Source B data
#endif
#ifndef BLTADAT
#define BLTADAT  (BLITTER_BASE + 0x074)  // Source A data
#endif

// Blitter Early Read (Dummy Address)
#ifndef BLTDDAT
#define BLTDDAT  (BLITTER_BASE + 0x000)  // Blitter destination early read (dummy address)
#endif

// Blitter Control 0 (BLTCON0) bits
#ifndef BLTCON0_USEA
#define BLTCON0_USEA    0x0001  // Use A channel
#endif
#ifndef BLTCON0_USEB
#define BLTCON0_USEB    0x0002  // Use B channel
#endif
#ifndef BLTCON0_USEC
#define BLTCON0_USEC    0x0004  // Use C channel
#endif
#ifndef BLTCON0_USED
#define BLTCON0_USED    0x0008  // Use D channel
#endif
#ifndef BLTCON0_SOLID
#define BLTCON0_SOLID   0x0010  // Solid pixels
#endif
#ifndef BLTCON0_DRAW
#define BLTCON0_DRAW    0x0020  // Draw line
#endif
#ifndef BLTCON0_LNPAF
#define BLTCON0_LNPAF   0x0040  // Line draw pattern fill
#endif
#ifndef BLTCON0_A_TO_D
#define BLTCON0_A_TO_D  0x0080  // A to D mode
#endif
#ifndef BLTCON0_DESC
#define BLTCON0_DESC    0x0100  // Descending mode
#endif
#ifndef BLTCON0_FCMASK
#define BLTCON0_FCMASK  0x0200  // Fill carry mask
#endif
#ifndef BLTCON0_SHIFT0
#define BLTCON0_SHIFT0  0x0400  // Shift value bit 0
#endif
#ifndef BLTCON0_SHIFT1
#define BLTCON0_SHIFT1  0x0800  // Shift value bit 1
#endif
#ifndef BLTCON0_SHIFT2
#define BLTCON0_SHIFT2  0x1000  // Shift value bit 2
#endif
#ifndef BLTCON0_SHIFT3
#define BLTCON0_SHIFT3  0x2000  // Shift value bit 3
#endif
#ifndef BLTCON0_SHIFT4
#define BLTCON0_SHIFT4  0x4000  // Shift value bit 4
#endif

// Blitter Control 1 (BLTCON1) bits
#ifndef BLTCON1_BBUSY
#define BLTCON1_BBUSY   0x0001  // Blitter busy (read-only)
#endif
#ifndef BLTCON1_FIRST
#define BLTCON1_FIRST   0x0002  // First word flag
#endif
#ifndef BLTCON1_FILL
#define BLTCON1_FILL    0x0004  // Fill mode
#endif
#ifndef BLTCON1_E_LINE
#define BLTCON1_E_LINE  0x0008  // End of line
#endif
#ifndef BLTCON1_SIGN
#define BLTCON1_SIGN    0x0010  // Sign bit (line draw)
#endif
#ifndef BLTCON1_ADI
#define BLTCON1_ADI     0x0020  // A channel direction increment
#endif
#ifndef BLTCON1_BDI
#define BLTCON1_BDI     0x0040  // B channel direction increment
#endif
#ifndef BLTCON1_CDI
#define BLTCON1_CDI     0x0080  // C channel direction increment
#endif
#ifndef BLTCON1_DDI
#define BLTCON1_DDI     0x0100  // D channel direction increment
#endif
#ifndef BLTCON1_ASH0
#define BLTCON1_ASH0    0x0200  // A shift bit 0
#endif
#ifndef BLTCON1_ASH1
#define BLTCON1_ASH1    0x0400  // A shift bit 1
#endif
#ifndef BLTCON1_ASH2
#define BLTCON1_ASH2    0x0800  // A shift bit 2
#endif
#ifndef BLTCON1_BSH0
#define BLTCON1_BSH0    0x1000  // B shift bit 0
#endif
#ifndef BLTCON1_BSH1
#define BLTCON1_BSH1    0x2000  // B shift bit 1
#endif
#ifndef BLTCON1_BSH2
#define BLTCON1_BSH2    0x4000  // B shift bit 2
#endif

// Blitter Size Register Masks
#ifndef BLTSIZE_HEIGHT_MASK
#define BLTSIZE_HEIGHT_MASK 0xFF00  // Height mask (upper 8 bits)
#endif
#ifndef BLTSIZE_WIDTH_MASK
#define BLTSIZE_WIDTH_MASK  0x001F  // Width mask (lower 5 bits)
#endif
#ifndef BLTSIZE_HSTART_MASK
#define BLTSIZE_HSTART_MASK 0x00E0  // Horizontal start mask (bits 5-7)
#endif

// Blitter Status (from DMACONR)
#ifndef DMACONR_BLTDONE
#define DMACONR_BLTDONE   0x4000  // Blitter done
#endif
#ifndef DMACONR_BLTNZERO
#define DMACONR_BLTNZERO  0x2000  // Blitter not zero (busy)
#endif

// Blitter Priority (from DMACON)
#ifndef DMACON_BLTPRI
#define DMACON_BLTPRI     0x0800  // Blitter priority (nasty)
#endif

// Common blitter operations
#ifndef BLT_CLEAR
#define BLT_CLEAR         0x00  // Clear (0)
#endif
#ifndef BLT_NAND
#define BLT_NAND          0x78  // Not AND
#endif
#ifndef BLT_AND
#define BLT_AND           0x88  // AND
#endif
#ifndef BLT_NOR
#define BLT_NOR           0x28  // Not OR
#endif
#ifndef BLT_OR
#define BLT_OR            0xd8  // OR
#endif
#ifndef BLT_XOR
#define BLT_XOR           0x68  // XOR
#endif
#ifndef BLT_EQUIV
#define BLT_EQUIV         0x98  // Equivalent (XNOR)
#endif
#ifndef BLT_NOTA
#define BLT_NOTA          0x50  // NOT A
#endif
#ifndef BLT_NOTB
#define BLT_NOTB          0x38  // NOT B
#endif
#ifndef BLT_A
#define BLT_A             0xc0  // A
#endif
#ifndef BLT_B
#define BLT_B             0xf0  // B
#endif
#ifndef BLT_SET
#define BLT_SET           0xff  // Set (1)
#endif

#endif // BLITTER_H