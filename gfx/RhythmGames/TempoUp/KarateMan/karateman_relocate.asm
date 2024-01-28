.align 4
karateman_tempo_up_obj:
.import "gfx/RhythmGames/TempoUp/KarateMan/karateman_tempo_up_obj.cdat"

.align 4
karate_man_graphics:
.dw karateman_tempo_up_obj | 0x80000000

.align 4
karate_man_tempo_up_gfx_table:
	.dw 0x08bdcfc8
	BG_TILESET_BASE(0x8000)
	.dw COMPRESSED_GFX_SOURCE

	.dw 0x08be0ce8
	BG_MAP_BASE(0xE000)
	.dw COMPRESSED_GFX_SOURCE

	.dw 0x08bdc938
	BG_TILESET_BASE(0)
	.dw COMPRESSED_GFX_SOURCE

	.dw 0x08be08e0
	BG_MAP_BASE(0xE800)
	.dw COMPRESSED_GFX_SOURCE

	.dw karate_man_graphics | 0x8000000 ; ###### SPRITES ######
	OBJ_TILESET_BASE(0)
	.dw COMPRESSED_GFX_SOURCE

	.dw 0x088ad004
	BG_PALETTE_BUFFER(0)
	.dw 0x200

	.dw 0x088ad004
	OBJ_PALETTE_BUFFER(0)
	.dw 0x140
END_OF_GRAPHICS_TABLE

.align 4
karate_man_gfx_tables:
.dw 0x089df0e0
.dw 0x089df074
.dw 0x089df0e0
.dw 0x089df140
.dw karate_man_tempo_up_gfx_table