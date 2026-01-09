# Amiga Model Timing Specifications

This document provides comprehensive timing information for different Amiga models based on the hardware documentation.

## A500 Timing Specifications

### Video Timings (NTSC)
- Horizontal frequency: 15.734 kHz
- Vertical frequency: 59.94 Hz
- Total horizontal lines: 262/263 (interlaced)
- Visible lines: 200 (non-interlaced), 400 (interlaced)
- Display width: 320 pixels (lores), 640 pixels (hires)
- Pixel clock: 7.09379 MHz (lores), 14.18758 MHz (hires)
- Memory access cycles per line: 227.5 (NTSC), 228 (PAL equivalent)

### Video Timings (PAL)
- Horizontal frequency: 15.625 kHz
- Vertical frequency: 49.92 Hz
- Total horizontal lines: 312/313 (interlaced)
- Visible lines: 256 (non-interlaced), 512 (interlaced)
- Display width: 320 pixels (lores), 640 pixels (hires)
- Pixel clock: 7.09375 MHz (lores), 14.1875 MHz (hires)
- Memory access cycles per line: 228

## A600 Timing Specifications

### ECS Enhanced Features
- Supports variable beam counters (ECS)
- Enhanced horizontal/vertical timing registers
- Additional bitplane capabilities up to 8 bitplanes (AGA)
- Higher resolution modes available

### Video Timings (PAL)
- Horizontal frequency: 15.625 kHz
- Vertical frequency: 49.92 Hz
- Total horizontal lines: 312/313
- Visible lines: 256-512 (variable)
- Display width: 320-1280 pixels (variable)
- Pixel clock: 7.09375 MHz (lores), 14.1875 MHz (hires), 28.375 MHz (shres)

## A1200 Timing Specifications

### AGA (Advanced Graphics Architecture) Features
- 256-color capability from 4096-color palette
- Up to 8 bitplanes
- Super Hires mode (1280x400/512)
- Enhanced sprite capabilities

### Video Timings (PAL)
- Horizontal frequency: 15.625 kHz
- Vertical frequency: 49.92 Hz
- Total horizontal lines: 312/313
- Visible lines: 256-512 (variable)
- Display width: 320-1280 pixels (variable)
- Pixel clock: 7.09375 MHz (lores), 14.1875 MHz (hires), 28.375 MHz (shres)

## A2000 Timing Specifications

### Video Timings (NTSC)
- Horizontal frequency: 15.734 kHz
- Vertical frequency: 59.94 Hz
- Total horizontal lines: 262/263
- Visible lines: 200/400 (interlaced)
- Display width: 320/640 pixels
- Pixel clock: 7.09379 MHz (lores), 14.18758 MHz (hires)

### Video Timings (PAL)
- Horizontal frequency: 15.625 kHz
- Vertical frequency: 49.92 Hz
- Total horizontal lines: 312/313
- Visible lines: 256/512 (interlaced)
- Display width: 320/640 pixels
- Pixel clock: 7.09375 MHz (lores), 14.1875 MHz (hires)

## A3000 Timing Specifications

### ECS Features
- Enhanced Chip Set (ECS)
- Variable beam counters
- Extended vertical/horizontal timing registers
- Support for higher resolution modes

### Video Timings (PAL)
- Horizontal frequency: 15.625 kHz
- Vertical frequency: 49.92 Hz
- Total horizontal lines: 312/313
- Visible lines: 256-512 (variable)
- Display width: 320-1280 pixels (variable)
- Pixel clock: 7.09375 MHz (lores), 14.1875 MHz (hires)

## A4000 Timing Specifications

### AGA Features
- Advanced Graphics Architecture
- 256-color capability from 16.8M color palette
- Up to 8 bitplanes
- Super Hires mode support
- Enhanced blitter capabilities

### Video Timings (PAL)
- Horizontal frequency: 15.625 kHz
- Vertical frequency: 49.92 Hz
- Total horizontal lines: 312/313
- Visible lines: 256-512 (variable)
- Display width: 320-1280 pixels (variable)
- Pixel clock: 7.09375 MHz (lores), 14.1875 MHz (hires), 28.375 MHz (shres)

### Video Timings (NTSC)
- Horizontal frequency: 15.734 kHz
- Vertical frequency: 59.94 Hz
- Total horizontal lines: 262/263
- Visible lines: 200-400 (variable)
- Display width: 320-1280 pixels (variable)
- Pixel clock: 7.09379 MHz (lores), 14.18758 MHz (hires), 28.375 MHz (shres)

## Memory Access Timing

### Chip RAM Access
- Cycle time: 280 ns (3.57 MHz effective)
- Every 2nd cycle available for CPU (odd cycles)
- DMA channels use even cycles
- Refresh cycles steal additional cycles

### Fast RAM Access
- Available on A600/A1200/A4000
- Typically 32-bit wide, 60-80 ns access time
- Uses AutoConfig for detection

### Memory Bandwidth Allocation
- CPU gets odd cycles when DMA not active
- Audio DMA: 1 cycle every 2-4 samples
- Disk DMA: 1-2 cycles per word transfer
- Bitplane DMA: Variable based on display mode
- Sprite DMA: 1-2 cycles per sprite per line
- Blitter DMA: Variable, can hog CPU cycles

## DMA Timing Constraints

### Audio Channel Timing
- Each audio channel requires 1 DMA cycle per sample period
- Sample rates determined by period register values
- Minimum period: 124 (3.547 kHz), Maximum: 65535 (0.108 Hz)

### Disk DMA Timing
- Requires 1 cycle per word during data transfer
- Sync pattern matching can interrupt transfers
- Typically uses 1-2 cycles per word transferred

### Video DMA Timing
- Bitplane DMA: Variable based on number of bitplanes and width
- Sprite DMA: Occurs during horizontal blank
- Copper DMA: Uses odd cycles, doesn't conflict with video

## Interrupt Timing

### Vertical Blank Interrupt
- Occurs at start of vertical blank period
- Timing varies slightly between models and video modes
- Used for synchronization in most applications

### Raster Interrupt
- Programmable interrupt at specific scan line
- Useful for split-screen effects and dynamic register updates
- Must account for pipeline delays in copper programs

### Copper Timing
- Operates on odd cycles only
- 2 cycles per instruction (4 memory cycles)
- Can be synchronized to specific beam positions