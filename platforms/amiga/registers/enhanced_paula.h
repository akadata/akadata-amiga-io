/*
 * SPDX-License-Identifier: MIT
 * 
 * Enhanced PAULA chip register definitions for Amiga
 * Based on Amiga Hardware Reference Manual and official documentation
 */

#ifndef ENHANCED_PAULA_H
#define ENHANCED_PAULA_H

#include "amiga_custom_chips.h"

// PAULA base address is 0xDFF000 (same as AGNUS)
#ifndef PAULA_BASE
#define PAULA_BASE 0xDFF000
#endif

// Audio Channel Registers
#define AUD0LCH  (PAULA_BASE + 0x0A0)  // Audio channel 0 location high
#define AUD0LCL  (PAULA_BASE + 0x0A2)  // Audio channel 0 location low
#define AUD0LEN  (PAULA_BASE + 0x0A4)  // Audio channel 0 length
#define AUD0PER  (PAULA_BASE + 0x0A6)  // Audio channel 0 period
#define AUD0VOL  (PAULA_BASE + 0x0A8)  // Audio channel 0 volume
#define AUD0DAT  (PAULA_BASE + 0x0AA)  // Audio channel 0 data

#define AUD1LCH  (PAULA_BASE + 0x0B0)  // Audio channel 1 location high
#define AUD1LCL  (PAULA_BASE + 0x0B2)  // Audio channel 1 location low
#define AUD1LEN  (PAULA_BASE + 0x0B4)  // Audio channel 1 length
#define AUD1PER  (PAULA_BASE + 0x0B6)  // Audio channel 1 period
#define AUD1VOL  (PAULA_BASE + 0x0B8)  // Audio channel 1 volume
#define AUD1DAT  (PAULA_BASE + 0x0BA)  // Audio channel 1 data

#define AUD2LCH  (PAULA_BASE + 0x0C0)  // Audio channel 2 location high
#define AUD2LCL  (PAULA_BASE + 0x0C2)  // Audio channel 2 location low
#define AUD2LEN  (PAULA_BASE + 0x0C4)  // Audio channel 2 length
#define AUD2PER  (PAULA_BASE + 0x0C6)  // Audio channel 2 period
#define AUD2VOL  (PAULA_BASE + 0x0C8)  // Audio channel 2 volume
#define AUD2DAT  (PAULA_BASE + 0x0CA)  // Audio channel 2 data

#define AUD3LCH  (PAULA_BASE + 0x0D0)  // Audio channel 3 location high
#define AUD3LCL  (PAULA_BASE + 0x0D2)  // Audio channel 3 location low
#define AUD3LEN  (PAULA_BASE + 0x0D4)  // Audio channel 3 length
#define AUD3PER  (PAULA_BASE + 0x0D6)  // Audio channel 3 period
#define AUD3VOL  (PAULA_BASE + 0x0D8)  // Audio channel 3 volume
#define AUD3DAT  (PAULA_BASE + 0x0DA)  // Audio channel 3 data

// Disk DMA Registers
#define DSKDATR  (PAULA_BASE + 0x008)  // Disk data early read (dummy address)
#define DSKBYTR  (PAULA_BASE + 0x01A)  // Disk data byte and status read
#define DSKPTH   (PAULA_BASE + 0x020)  // Disk pointer high
#define DSKPTL   (PAULA_BASE + 0x022)  // Disk pointer low
#define DSKLEN   (PAULA_BASE + 0x024)  // Disk length
#define DSKDAT   (PAULA_BASE + 0x026)  // Disk DMA data write
#define DSKSYNC  (PAULA_BASE + 0x07E)  // Disk sync register

// Serial Port Registers
#define SERDATR  (PAULA_BASE + 0x018)  // Serial port data and status read
#define SERDAT   (PAULA_BASE + 0x030)  // Serial port data and stop bits write
#define SERPER   (PAULA_BASE + 0x032)  // Serial port period and control

// Pot/Counter Registers
#define POT0DAT  (PAULA_BASE + 0x012)  // Pot counter pair 0 (vertical/horizontal)
#define POT1DAT  (PAULA_BASE + 0x014)  // Pot counter pair 1 (vertical/horizontal)
#define POTGOR   (PAULA_BASE + 0x016)  // Pot pin data read
#define POTGO    (PAULA_BASE + 0x034)  // Pot port data write/start

// Interrupt Control Registers
#define INTENAR  (PAULA_BASE + 0x01C)  // Interrupt enable read
#define INTREQR  (PAULA_BASE + 0x01E)  // Interrupt request read
#define INTENA   (PAULA_BASE + 0x09A)  // Interrupt enable write
#define INTREQ   (PAULA_BASE + 0x09C)  // Interrupt request write

// Audio/Disk Control Register
#define ADKCONR  (PAULA_BASE + 0x010)  // Audio/disk control read
#define ADKCON   (PAULA_BASE + 0x09E)  // Audio/disk control write

// Input Sampling Registers
#define JOY0DAT  (PAULA_BASE + 0x00A)  // Joystick/mouse 0 data (vertical/horizontal)
#define JOY1DAT  (PAULA_BASE + 0x00C)  // Joystick/mouse 1 data (vertical/horizontal)

// Collision Detection
#define CLXDAT   (PAULA_BASE + 0x00E)  // Collision data (read/clear)
#define CLXCON   (PAULA_BASE + 0x098)  // Collision control

// DMA Control (shared with AGNUS)
#define DMACONR  (PAULA_BASE + 0x002)  // Read DMA control / blitter status
#define DMACON   (PAULA_BASE + 0x096)  // Write DMA control (set/clear)

// Audio Control Bits (ADKCON/ADKCONR)
#define ADKF_SETCLR   0x8000  // Set/Clear control bit
#define ADKF_MFMPREC  0x4000  // MFM compatibility mode
#define ADKF_WORDSYNC 0x2000  // Word sync mode
#define ADKF_UARTBRK  0x1000  // UART break set
#define ADKF_MSBSYNC  0x0800  // MSB sync mode
#define ADKF_FAST     0x0400  // Fast serial clock
#define ADKF_PRECOMP0 0x0200  // Precompensation bit 0
#define ADKF_PRECOMP1 0x0100  // Precompensation bit 1
#define ADKF_PRECOMP2 0x0080  // Precompensation bit 2
#define ADKF_SERDCY0  0x0040  // Serial delay bit 0
#define ADKF_SERDCY1  0x0020  // Serial delay bit 1
#define ADKF_CH3PEN   0x0010  // Channel 3 in use for input
#define ADKF_CH2PEN   0x0008  // Channel 2 in use for input
#define ADKF_CH1PEN   0x0004  // Channel 1 in use for input
#define ADKF_CH0PEN   0x0002  // Channel 0 in use for input
#define ADKF_ADLNK    0x0001  // Audio channel linking

// ADKCON bit numbers
#define ADKB_SETCLR   15
#define ADKB_MFMPREC  14
#define ADKB_WORDSYNC 13
#define ADKB_UARTBRK  12
#define ADKB_MSBSYNC  11
#define ADKB_FAST     10
#define ADKB_PRECOMP0 9
#define ADKB_PRECOMP1 8
#define ADKB_PRECOMP2 7
#define ADKB_SERDCY0  6
#define ADKB_SERDCY1  5
#define ADKB_CH3PEN   4
#define ADKB_CH2PEN   3
#define ADKB_CH1PEN   2
#define ADKB_CH0PEN   1
#define ADKB_ADLNK    0

// Interrupt Bits
#define INTF_SETCLR   0x8000  // Set/Clear control bit
#define INTF_INTEN    0x4000  // Master interrupt enable
#define INTF_EXTER    0x2000  // External interrupt
#define INTF_DSKBLK   0x1000  // Disk block done
#define INTF_RASTER   0x0800  // Raster beam
#define INTF_AUD3     0x0400  // Audio channel 3
#define INTF_AUD2     0x0200  // Audio channel 2
#define INTF_AUD1     0x0100  // Audio channel 1
#define INTF_AUD0     0x0080  // Audio channel 0
#define INTF_BLIT     0x0040  // Blitter done
#define INTF_SPRITE   0x0020  // Sprite overflow/duplicate
#define INTF_COPPER   0x0010  // Copper
#define INTF_VERTB    0x0008  // Vertical blank
#define INTF_PORTS    0x0004  // I/O ports and timers
#define INTF_SOFTWARE 0x0002  // Software interrupt
#define INTF_DSKSYNC  0x0001  // Disk sync

// INTF bit numbers
#define INTB_SETCLR   15
#define INTB_INTEN    14
#define INTB_EXTER    13
#define INTB_DSKBLK   12
#define INTB_RASTER   11
#define INTB_AUD3     10
#define INTB_AUD2     9
#define INTB_AUD1     8
#define INTB_AUD0     7
#define INTB_BLIT     6
#define INTB_SPRITE   5
#define INTB_COPPER   4
#define INTB_VERTB    3
#define INTB_PORTS    2
#define INTB_SOFTWARE 1
#define INTB_DSKSYNC  0

// Audio Channel Control Bits
#define AUDxPER_PERIOD_MASK 0xFFFF  // Full 16-bit period value

// Audio Volume Control (AUDxVOL)
#define AUDVOL_VOLUME_MASK 0x007F  // Volume mask (7 bits)
#define AUDVOL_VOLUME_MAX  0x0040  // Maximum volume (64 in signed 7-bit)

// Disk Length (DSKLEN)
#define DSKLEN_DMAEN      0x8000  // Disk DMA enable bit
#define DSKLEN_WRITE      0x4000  // Write mode (0=read, 1=write)
#define DSKLEN_LENGTH_MASK 0x3FFF  // Length mask (14 bits)

// Serial Period Control (SERPER)
#define SERPER_LONG       0x8000  // Long serial word (9 bits)
#define SERPER_RATE_MASK  0x7FFF  // Serial rate mask

// Pot Counter Control (POTGO)
#define POTGO_START       0x8000  // Start pot counters

// Collision Control (CLXCON)
#define CLXCON_SPRITE_EN_MASK 0x00FF  // Sprite enable mask (bits 0-7)
#define CLXCON_PLANE_EN_MASK  0xFF00  // Bitplane enable mask (bits 8-15)

// Collision Data (CLXDAT) - collision bits
#define CLXDAT_SPR0_SPR1    0x0001  // Sprite 0 vs Sprite 1
#define CLXDAT_SPR0_SPR2    0x0002  // Sprite 0 vs Sprite 2
#define CLXDAT_SPR0_SPR3    0x0004  // Sprite 0 vs Sprite 3
#define CLXDAT_SPR0_SPR4    0x0008  // Sprite 0 vs Sprite 4
#define CLXDAT_SPR0_SPR5    0x0010  // Sprite 0 vs Sprite 5
#define CLXDAT_SPR0_SPR6    0x0020  // Sprite 0 vs Sprite 6
#define CLXDAT_SPR0_SPR7    0x0040  // Sprite 0 vs Sprite 7
#define CLXDAT_SPR1_SPR2    0x0080  // Sprite 1 vs Sprite 2
#define CLXDAT_SPR1_SPR3    0x0100  // Sprite 1 vs Sprite 3
#define CLXDAT_SPR1_SPR4    0x0200  // Sprite 1 vs Sprite 4
#define CLXDAT_SPR1_SPR5    0x0400  // Sprite 1 vs Sprite 5
#define CLXDAT_SPR1_SPR6    0x0800  // Sprite 1 vs Sprite 6
#define CLXDAT_SPR1_SPR7    0x1000  // Sprite 1 vs Sprite 7
#define CLXDAT_SPR2_SPR3    0x2000  // Sprite 2 vs Sprite 3
#define CLXDAT_SPR2_SPR4    0x4000  // Sprite 2 vs Sprite 4
#define CLXDAT_SPR2_SPR5    0x8000  // Sprite 2 vs Sprite 5
#define CLXDAT_SPR3_SPR4    0x0001  // Sprite 3 vs Sprite 4 (shifted)
#define CLXDAT_SPR3_SPR5    0x0002  // Sprite 3 vs Sprite 5 (shifted)
#define CLXDAT_SPR3_SPR6    0x0004  // Sprite 3 vs Sprite 6 (shifted)
#define CLXDAT_SPR3_SPR7    0x0008  // Sprite 3 vs Sprite 7 (shifted)
#define CLXDAT_SPR4_SPR5    0x0010  // Sprite 4 vs Sprite 5 (shifted)
#define CLXDAT_SPR4_SPR6    0x0020  // Sprite 4 vs Sprite 6 (shifted)
#define CLXDAT_SPR4_SPR7    0x0040  // Sprite 4 vs Sprite 7 (shifted)
#define CLXDAT_SPR5_SPR6    0x0080  // Sprite 5 vs Sprite 6 (shifted)
#define CLXDAT_SPR5_SPR7    0x0100  // Sprite 5 vs Sprite 7 (shifted)
#define CLXDAT_SPR6_SPR7    0x0200  // Sprite 6 vs Sprite 7 (shifted)

// Bitplane vs Sprite collision bits
#define CLXDAT_BPL0_SPR0    0x0001  // Bitplane 0 vs Sprite 0
#define CLXDAT_BPL0_SPR1    0x0002  // Bitplane 0 vs Sprite 1
#define CLXDAT_BPL0_SPR2    0x0004  // Bitplane 0 vs Sprite 2
#define CLXDAT_BPL0_SPR3    0x0008  // Bitplane 0 vs Sprite 3
#define CLXDAT_BPL0_SPR4    0x0010  // Bitplane 0 vs Sprite 4
#define CLXDAT_BPL0_SPR5    0x0020  // Bitplane 0 vs Sprite 5
#define CLXDAT_BPL0_SPR6    0x0040  // Bitplane 0 vs Sprite 6
#define CLXDAT_BPL0_SPR7    0x0080  // Bitplane 0 vs Sprite 7
#define CLXDAT_BPL1_SPR0    0x0100  // Bitplane 1 vs Sprite 0
#define CLXDAT_BPL1_SPR1    0x0200  // Bitplane 1 vs Sprite 1
#define CLXDAT_BPL1_SPR2    0x0400  // Bitplane 1 vs Sprite 2
#define CLXDAT_BPL1_SPR3    0x0800  // Bitplane 1 vs Sprite 3
#define CLXDAT_BPL1_SPR4    0x1000  // Bitplane 1 vs Sprite 4
#define CLXDAT_BPL1_SPR5    0x2000  // Bitplane 1 vs Sprite 5
#define CLXDAT_BPL1_SPR6    0x4000  // Bitplane 1 vs Sprite 6
#define CLXDAT_BPL1_SPR7    0x8000  // Bitplane 1 vs Sprite 7

// Bitplane vs Bitplane collision bits
#define CLXDAT_BPL0_BPL1    0x0001  // Bitplane 0 vs Bitplane 1
#define CLXDAT_BPL0_BPL2    0x0002  // Bitplane 0 vs Bitplane 2
#define CLXDAT_BPL0_BPL3    0x0004  // Bitplane 0 vs Bitplane 3
#define CLXDAT_BPL0_BPL4    0x0008  // Bitplane 0 vs Bitplane 4
#define CLXDAT_BPL0_BPL5    0x0010  // Bitplane 0 vs Bitplane 5
#define CLXDAT_BPL0_BPL6    0x0020  // Bitplane 0 vs Bitplane 6
#define CLXDAT_BPL1_BPL2    0x0040  // Bitplane 1 vs Bitplane 2
#define CLXDAT_BPL1_BPL3    0x0080  // Bitplane 1 vs Bitplane 3
#define CLXDAT_BPL1_BPL4    0x0100  // Bitplane 1 vs Bitplane 4
#define CLXDAT_BPL1_BPL5    0x0200  // Bitplane 1 vs Bitplane 5
#define CLXDAT_BPL1_BPL6    0x0400  // Bitplane 1 vs Bitplane 6
#define CLXDAT_BPL2_BPL3    0x0800  // Bitplane 2 vs Bitplane 3
#define CLXDAT_BPL2_BPL4    0x1000  // Bitplane 2 vs Bitplane 4
#define CLXDAT_BPL2_BPL5    0x2000  // Bitplane 2 vs Bitplane 5
#define CLXDAT_BPL2_BPL6    0x4000  // Bitplane 2 vs Bitplane 6
#define CLXDAT_BPL3_BPL4    0x8000  // Bitplane 3 vs Bitplane 4

// Serial Port Status Bits (in SERDATR)
#define SERDATR_RBF         0x8000  // Receive buffer full
#define SERDATR_TBE         0x4000  // Transmit buffer empty
#define SERDATR_TSRE        0x2000  // Transmit shift register empty
#define SERDATR_RXD         0x1000  // Receive data bit
#define SERDATR_STP         0x0800  // Stop bit
#define SERDATR_DBON        0x0400  // Data bit 7 (on)
#define SERDATR_DB7         0x0200  // Data bit 7
#define SERDATR_DB6         0x0100  // Data bit 6
#define SERDATR_DB5         0x0080  // Data bit 5
#define SERDATR_DB4         0x0040  // Data bit 4
#define SERDATR_DB3         0x0020  // Data bit 3
#define SERDATR_DB2         0x0010  // Data bit 2
#define SERDATR_DB1         0x0008  // Data bit 1
#define SERDATR_DB0         0x0004  // Data bit 0
#define SERDATR_OVRUN       0x0002  // Overrun error
#define SERDATR_RBUF_MSK    0x00FF  // Receive buffer mask

// Disk Status Bits (in DSKBYTR)
#define DSKBYTR_DSKBYT      0x8000  // Disk byte ready
#define DSKBYTR_DMAON       0x4000  // DMA on
#define DSKBYTR_WR          0x2000  // Write mode
#define DSKBYTR_WRE         0x1000  // Write error
#define DSKBYTR_RD          0x0800  // Read mode
#define DSKBYTR_RDY         0x0400  // Ready
#define DSKBYTR_WRPRO       0x0200  // Write protect
#define DSKBYTR_CHNG        0x0100  // Disk change
#define DSKBYTR_INDEX       0x0080  // Index hole
#define DSKBYTR_TRACK0      0x0040  // Track 0
#define DSKBYTR_PROT        0x0020  // Protected
#define DSKBYTR_MFMT        0x0010  // MFM format
#define DSKBYTR_DSKSYNC     0x0008  // Disk sync match
#define DSKBYTR_OVRUN       0x0004  // Overrun
#define DSKBYTR_CLKEN       0x0002  // Clock enable
#define DSKBYTR_MTRON       0x0001  // Motor on

// Pot Counter Status (in POTGOR)
#define POTGOR_POT0DAT      0x00FF  // Pot counter 0 data mask
#define POTGOR_POT1DAT      0xFF00  // Pot counter 1 data mask

// Joystick/Mouse Data (in JOY0DAT/JOY1DAT)
#define JOYDAT_VERT_MASK    0xFF00  // Vertical counter mask
#define JOYDAT_HORZ_MASK    0x00FF  // Horizontal counter mask
#define JOYDAT_VERT_SHIFT   8       // Vertical counter shift
#define JOYDAT_HORZ_SHIFT   0       // Horizontal counter shift

#endif // ENHANCED_PAULA_H