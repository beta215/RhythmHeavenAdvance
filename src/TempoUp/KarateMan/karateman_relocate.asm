.align 4
karateman_extra_tiles:
.import "gfx/RhythmGames/TempoUp/KarateMan/karateman_extra_tiles.cdat"

.align 4
karate_man_graphics:
.dw karateman_extra_tiles | 0x80000000

.align 4
karate_man_tempoup_gfx_table:

.dw 0x08bdcfc8
.dw 0x06008000
.dw 0xffffffff

.dw 0x08be0ce8
.dw 0x0600E000
.dw 0x00000500

.dw 0x08bdc938
.dw 0x06000000
.dw 0xffffffff

.dw 0x08be08e0
.dw 0x0600e800
.dw 0xffffffff

.dw karate_man_graphics | 0x8000000 ; ###### SPRITES ######
.dw 0x06010000
.dw 0xffffffff

.dw 0x088ad004
.dw 0x03004b64
.dw 0x00000200

.dw 0x088ad004
.dw 0x03004d64
.dw 0x00000140

.dw 0x00000000 ; ######   END   ######
.dw 0x00000000
.dw 0x00000000

.align 4
karate_gfx_tables:
.dw 0x089df0e0
.dw 0x089df074
.dw 0x089df0e0
.dw 0x089df140
.dw karate_man_tempoup_gfx_table | 0x8000000

.include "src/TempoUp/KarateMan/karate_man.bs"