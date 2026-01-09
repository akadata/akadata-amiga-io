/*
 * SPDX-License-Identifier: MIT
 * 
 * ZORRO II/III chip register definitions for Amiga
 * Based on Zorro specification documents and Amiga Hardware Reference
 * Addresses: AutoConfig and expansion bus control registers
 */

#ifndef ZORRO_H
#define ZORRO_H

#include "amiga_custom_chips.h"

// ZORRO base addresses (expansion slot registers)
#define ZORRO_BASE            0xE80000  // ZORRO II base address range start
#define ZORRO_END             0xEBFFFF  // ZORRO II base address range end
#define ZORRO3_BASE           0x200000  // ZORRO III base address range start
#define ZORRO3_END            0x9FFFFF  // ZORRO III base address range end

// ZORRO AutoConfig Registers (mapped in expansion address space)
#define ZORRO_START_ADDR      0xE80000  // ZORRO II expansion start address
#define ZORRO_END_ADDR        0xEBFFFF  // ZORRO II expansion end address

// AutoConfig ID Register (at offset 0x00 in expansion card space)
#define ZORRO_ID_OFFSET       0x00      // Card ID register offset
#define ZORRO_ID              0x00      // Card ID register (at card base + 0x00)

// AutoConfig Control/Status Register (at offset 0x02)
#define ZORRO_CS_OFFSET       0x02      // Control/Status register offset
#define ZORRO_CS              0x02      // Control/Status register

// AutoConfig ROM Vector (at offset 0x04)
#define ZORRO_ROM_OFFSET      0x04      // ROM vector offset
#define ZORRO_ROM             0x04      // ROM vector register

// AutoConfig Size Register (at offset 0x06)
#define ZORRO_SIZE_OFFSET     0x06      // Size register offset
#define ZORRO_SIZE            0x06      // Size register

// AutoConfig Memory Start Register (at offset 0x08)
#define ZORRO_MEMSTART_OFFSET 0x08      // Memory start offset
#define ZORRO_MEMSTART        0x08      // Memory start register

// AutoConfig Memory End Register (at offset 0x0A)
#define ZORRO_MEMEND_OFFSET   0x0A      // Memory end offset
#define ZORRO_MEMEND          0x0A      // Memory end register

// AutoConfig Expansion ROM Register (at offset 0x0C)
#define ZORRO_EXPROM_OFFSET   0x0C      // Expansion ROM offset
#define ZORRO_EXPROM          0x0C      // Expansion ROM register

// AutoConfig Control Register (at offset 0x0E)
#define ZORRO_CTRL_OFFSET     0x0E      // Control register offset
#define ZORRO_CTRL            0x0E      // Control register

// ZORRO II/III ID Register bits
#define ZORRO_ID_MANUFACTURER 0xFF00    // Manufacturer ID (bits 15-8)
#define ZORRO_ID_PRODUCT      0x00FF    // Product ID (bits 7-0)

// ZORRO II/III Control/Status Register bits
#define ZORRO_CS_INIT         0x8000    // Initialization bit
#define ZORRO_CS_CONFIG       0x4000    // Configuration bit
#define ZORRO_CS_ENABLED      0x2000    // Enabled bit
#define ZORRO_CS_TYPE         0x1000    // Type bit (0=ZORRO II, 1=ZORRO III)
#define ZORRO_CS_SIZE         0x0F00    // Size field (bits 11-8)
#define ZORRO_CS_FLAGS        0x00FF    // Flags field (bits 7-0)

// ZORRO Size Register bits
#define ZORRO_SIZE_MEMSIZE    0xFF00    // Memory size (in 64KB chunks)
#define ZORRO_SIZE_IOSIZE     0x00FF    // I/O size (in 64KB chunks)

// ZORRO Control Register bits
#define ZORRO_CTRL_RESET      0x8000    // Reset expansion card
#define ZORRO_CTRL_ENABLE     0x4000    // Enable expansion card
#define ZORRO_CTRL_INT2       0x2000    // Interrupt level 2 enable
#define ZORRO_CTRL_INT6       0x1000    // Interrupt level 6 enable
#define ZORRO_CTRL_INT7       0x0800    // Interrupt level 7 enable
#define ZORRO_CTRL_DMA        0x0400    // DMA enable
#define ZORRO_CTRL_BURST      0x0200    // Burst mode enable
#define ZORRO_CTRL_PARITY     0x0100    // Parity check enable
#define ZORRO_CTRL_RESERVED   0x00FF    // Reserved bits

// ZORRO III Extended Registers (when TYPE bit is set)
#define ZORRO3_EXT_START      0x10      // Extended start address offset
#define ZORRO3_EXT_END        0x14      // Extended end address offset
#define ZORRO3_EXT_CTRL       0x18      // Extended control offset
#define ZORRO3_EXT_STATUS     0x1C      // Extended status offset

// ZORRO III Extended Control Register bits
#define ZORRO3_CTRL_32BIT     0x8000    // 32-bit mode
#define ZORRO3_CTRL_BIGEND    0x4000    // Big endian mode
#define ZORRO3_CTRL_BYTEWIDE  0x2000    // Byte-wide access
#define ZORRO3_CTRL_WORDWIDE  0x1000    // Word-wide access
#define ZORRO3_CTRL_CACHEABLE 0x0800    // Cacheable memory
#define ZORRO3_CTRL_FAST      0x0400    // Fast memory
#define ZORRO3_CTRL_BLITPRI   0x0200    // Blitter priority
#define ZORRO3_CTRL_NOINT     0x0100    // No interrupt capability

// ZORRO III Extended Status Register bits
#define ZORRO3_STAT_PRESENT   0x8000    // Card present
#define ZORRO3_STAT_32BIT     0x4000    // 32-bit capable
#define ZORRO3_STAT_BIGEND    0x2000    // Big endian capable
#define ZORRO3_STAT_BYTEWIDE  0x1000    // Byte-wide capable
#define ZORRO3_STAT_WORDWIDE  0x0800    // Word-wide capable
#define ZORRO3_STAT_CACHEABLE 0x0400    // Cacheable capable
#define ZORRO3_STAT_FAST      0x0200    // Fast memory capable
#define ZORRO3_STAT_BLITPRI   0x0100    // Blitter priority capable

// Common manufacturer IDs
#define ZORRO_MANUF_COMMODORE 0x0200    // Commodore International
#define ZORRO_MANUF_KUPKE     0x0400    // Klaus Kupke
#define ZORRO_MANUF_CARDCO    0x0800    // The Card Co.
#define ZORRO_MANUF_PROGRESSIVE 0x0A00  // Progressive Peripherals
#define ZORRO_MANUF_MACROSYSTEMS 0x0C00 // MacroSystems
#define ZORRO_MANUF_UWE_NIEKESKAMP 0x0E00 // Uwe Niekeskamp
#define ZORRO_MANUF_BYTEBOX     0x1000  // Bytebox
#define ZORRO_MANUF_MICROBOTICS   0x1200  // Microbotics
#define ZORRO_MANUF_SUPRA         0x1400  // Supra
#define ZORRO_MANUF_ROCTEC        0x1600  // ROC-Tec
#define ZORRO_MANUF_KUPKE2        0x1800  // Klaus Kupke (alt)
#define ZORRO_MANUF_ASDG          0x1A00  // ASDG
#define ZORRO_MANUF_BSC           0x1C00  // BSC
#define ZORRO_MANUF_HARMS         0x1E00  // Harms
#define ZORRO_MANUF_VECTOR        0x2000  // Vector
#define ZORRO_MANUF_IMPACT        0x2200  // Impact
#define ZORRO_MANUF_DIGITAL       0x2400  // Digital
#define ZORRO_MANUF_PHOENIX       0x2600  // Phoenix
#define ZORRO_MANUF_REALISTIC     0x2800  // Realistic
#define ZORRO_MANUF_ADVANCED      0x2A00  // Advanced
#define ZORRO_MANUF_COMSPEC       0x2C00  // ComSpec
#define ZORRO_MANUF_BYTEKRAFT     0x2E00  // ByteKraft
#define ZORRO_MANUF_GREATVALLEY   0x3000  // Great Valley Products
#define ZORRO_MANUF_VALLEY        0x3200  // Valley
#define ZORRO_MANUF_KUPKE3        0x3400  // Klaus Kupke (alt2)
#define ZORRO_MANUF_TEKMAG        0x3600  // Tekmag
#define ZORRO_MANUF_ASDG2         0x3800  // ASDG (alt)
#define ZORRO_MANUF_BSC2          0x3A00  // BSC (alt)
#define ZORRO_MANUF_HARMS2        0x3C00  // Harms (alt)
#define ZORRO_MANUF_VECTOR2       0x3E00  // Vector (alt)

// Common product IDs
#define ZORRO_PROD_RAM          0x01    // Generic RAM expansion
#define ZORRO_PROD_FAST_RAM     0x02    // Fast RAM expansion
#define ZORRO_PROD_ROM          0x03    // ROM expansion
#define ZORRO_PROD_IO           0x04    // I/O expansion
#define ZORRO_PROD_BLITTER      0x05    // Blitter accelerator
#define ZORRO_PROD_VIDEO        0x06    // Video accelerator
#define ZORRO_PROD_AUDIO        0x07    // Audio accelerator
#define ZORRO_PROD_NET          0x08    // Network adapter
#define ZORRO_PROD_SCSI         0x09    // SCSI controller
#define ZORRO_PROD_IDE          0x0A    // IDE controller
#define ZORRO_PROD_SERIAL       0x0B    // Serial port
#define ZORRO_PROD_PARALLEL     0x0C    // Parallel port
#define ZORRO_PROD_KEYBOARD     0x0D    // Keyboard adapter
#define ZORRO_PROD_MOUSE        0x0E    // Mouse adapter
#define ZORRO_PROD_TIMER        0x0F    // Timer expansion
#define ZORRO_PROD_CLOCK        0x10    // Clock/calendar
#define ZORRO_PROD_MATH         0x11    // Math coprocessor
#define ZORRO_PROD_RAM_Z3       0x12    // Zorro III RAM expansion
#define ZORRO_PROD_FAST_RAM_Z3  0x13    // Zorro III Fast RAM
#define ZORRO_PROD_SCSI_Z3      0x14    // Zorro III SCSI controller

// ZORRO Size Constants (in 64KB chunks)
#define ZORRO_SIZE_64KB       0x0001    // 64KB
#define ZORRO_SIZE_128KB      0x0002    // 128KB
#define ZORRO_SIZE_256KB      0x0004    // 256KB
#define ZORRO_SIZE_512KB      0x0008    // 512KB
#define ZORRO_SIZE_1MB        0x0010    // 1MB
#define ZORRO_SIZE_2MB        0x0020    // 2MB
#define ZORRO_SIZE_4MB        0x0040    // 4MB
#define ZORRO_SIZE_8MB        0x0080    // 8MB
#define ZORRO_SIZE_16MB       0x0100    // 16MB
#define ZORRO_SIZE_32MB       0x0200    // 32MB
#define ZORRO_SIZE_64MB       0x0400    // 64MB
#define ZORRO_SIZE_128MB      0x0800    // 128MB
#define ZORRO_SIZE_256MB      0x1000    // 256MB
#define ZORRO_SIZE_512MB      0x2000    // 512MB
#define ZORRO_SIZE_1GB        0x4000    // 1GB
#define ZORRO_SIZE_2GB        0x8000    // 2GB

// ZORRO-specific functions
extern uint16_t zorro_read_register(uint32_t addr);
extern void zorro_write_register(uint32_t addr, uint16_t value);
extern uint16_t zorro_read_autoconfig(uint32_t card_base, uint8_t offset);
extern void zorro_write_autoconfig(uint32_t card_base, uint8_t offset, uint16_t value);
extern int zorro_probe_card(uint32_t base_addr);
extern uint16_t zorro_get_card_id(uint32_t base_addr);
extern uint16_t zorro_get_card_size(uint32_t base_addr);
extern uint16_t zorro_get_card_control(uint32_t base_addr);
extern void zorro_reset_card(uint32_t base_addr);
extern void zorro_enable_card(uint32_t base_addr);
extern void zorro_disable_card(uint32_t base_addr);
extern int zorro_is_zorro3(uint32_t base_addr);
extern uint32_t zorro_get_memory_start(uint32_t base_addr);
extern uint32_t zorro_get_memory_end(uint32_t base_addr);
extern uint32_t zorro_get_expansion_rom(uint32_t base_addr);

// ZORRO expansion slot management
extern int zorro_init_slots(void);
extern void zorro_cleanup_slots(void);
extern int zorro_assign_slot(uint32_t base_addr, uint16_t card_id, uint16_t size);
extern void zorro_free_slot(uint32_t base_addr);
extern int zorro_detect_cards(void);

#endif // ZORRO_H