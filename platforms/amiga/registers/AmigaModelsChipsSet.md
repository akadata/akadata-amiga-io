# Amiga Model / Chipset Matrix

This matrix is the single set of model IDs used in `registers.csv` / `amiga_registers_master.csv`. It captures the chipset mix and Agnus/Denise capability so register availability can be resolved without folklore like “AGA A500.”

| Model ID | Chipset class | Agnus / Alice | Denise / Lisa | Chip RAM limit | Notes |
| --- | --- | --- | --- | --- | --- |
| A1000 | OCS | 8370/8371 (512K) | OCS Denise | 512K (external RAM as pseudo-fast) | Kickstart overlay, baseline OCS |
| A500_OCS | OCS | 8370/8371 (512K) | OCS Denise | 512K (1MB with trapdoor but OCS fetch limits) | Launch A500 configuration |
| A500_FAT_OCS | OCS | 8372A Fat Agnus (1MB) | OCS Denise | 1MB | DMA is OCS; no ECS registers despite 1MB addressing |
| A500_ECS | ECS | 8372B/8375 Fat/Fatter Agnus (2MB) | Super Denise (ECS) | 2MB | Common upgrade path for A500; full ECS feature set |
| A500_PLUS | ECS | 8375 Fatter Agnus | Super Denise (ECS) | 2MB | Shipping ECS A500 variant |
| A600 | ECS | 8375 | Super Denise (ECS) | 2MB | IDE + PCMCIA additions; ECS register set |
| A1200 | AGA | Alice (ECS superset) | Lisa (AGA) | 2MB | AGA fetch/8 bitplanes, 2× CIA clock |
| A2000_OCS | OCS | 8370/8371 (512K) | OCS Denise | 1MB | Early A2000 units |
| A2000_FAT | OCS | 8372A Fat Agnus (1MB) | OCS Denise | 1MB | OCS feature set, 1MB addressing |
| A2000_ECS | ECS | 8372B/8375 | Super Denise (ECS) | 2MB | Full ECS feature set |
| A3000 | ECS | 8372B/8375 | Super Denise (ECS) | 2MB | ECS registers, 2× clock option for CIA disabled in shipping ROMs |
| A4000 | AGA | Alice | Lisa | 8MB (board typically 2MB) | AGA feature set; higher chip RAM map on desktop/tower |
| CDTV | OCS | 8370/8371 | OCS Denise | 1MB | A500-derived OCS platform |
| CD32 | AGA | Alice | Lisa | 2MB | AGA console; Akiko not part of custom register map |

Family to model mapping (used by the `Family` column in the CSV):
- `OCS/ECS/AGA`: all IDs above.
- `ECS/AGA`: A500_ECS, A500_PLUS, A600, A2000_ECS, A3000, A1200, A4000, CD32.
- `AGA`: A1200, A4000, CD32.
- `OCS`: A1000, A500_OCS, A500_FAT_OCS, A2000_OCS, A2000_FAT, CDTV.

Source references: `Hardware/amiga_memory_map.html` (register map), `Hardware/ADCD_2.1/_txt/Hardware_Manual_guide` (register semantics), and chip datasheets in `Hardware/amigadocs/`.
