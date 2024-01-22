.align 4
disclamer_bg:
.import "gfx/Disclamer/disclamer_bg.cdat"

.align 4
disclamer_bg_pal:
.import "gfx/Disclamer/disclamer_bg.agp"

.align 4
disclamer_bg_map_dat:
.import "gfx/Disclamer/disclamer_bg_map.dat"

.align 4
disclamer_bg_map_rle:
.import "gfx/Disclamer/disclamer_bg_map.rle"
disclamer_bg_map_rle_end:

.align 4
disclamer_bg_gfx:
.dw disclamer_bg | 0x80000000

.align 4
disclamer_bg_map:
.dw disclamer_bg_map_dat
.dw disclamer_bg_map_rle
.dw disclamer_bg_map_rle_end - disclamer_bg_map_rle
.dw 0x00000000

struct disclamer_gfx_table
	; BG Tileset
	.dw disclamer_bg_gfx
	.dw 0x06000000
	.dw 0xFFFFFFFF

	; BG Map
	.dw disclamer_bg_map
	.dw 0x0600E800
	.dw 0xFFFFFFFF
	
	; OBJ Tileset
	.dw disclamer_bg_gfx
	.dw 0x06010000
	.dw 0xFFFFFFFF
	
	; BG Palette
	.dw disclamer_bg_pal
	.dw 0x03004B64
	.dw 0x20
	
	; OBJ Palette
	.dw disclamer_bg_pal
	.dw 0x03004D64
	.dw 0x20
endstruct

.notice tohex(disclamer_gfx_table)