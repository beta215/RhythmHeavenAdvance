/* ------------------------ Types ------------------------ */

.definelabel SCREEN_WIDTH, 240
.definelabel SCREEN_HEIGHT, 160
.definelabel SCREEN_CENTER_X, (SCREEN_WIDTH / 2)
.definelabel SCREEN_CENTER_Y, (SCREEN_HEIGHT / 2)

; Booleans
.definelabel BG_LAYER_0, 0
.definelabel BG_LAYER_1, 1
.definelabel BG_LAYER_2, 2
.definelabel BG_LAYER_3, 3

.definelabel COMPRESSED_GFX_SOURCE, -1
.definelabel FUNCTION_GFX_SOURCE, -1


/* ------------------------ Funcs ------------------------ */

.macro BG_TILESET_BASE, offset
	.dw VRamBase + offset
.endmacro

.macro BG_MAP_BASE, offset
	.dw VRamBase + offset
.endmacro

.macro OBJ_TILESET_BASE, offset
	.dw VRamBase + 0x10000 + offset
.endmacro


.macro GET_BG_TILESET_ADDR, tileset, ofs
	.dw VRamBase + ((tileset) << 14) + (ofs)
.endmacro

.macro GET_BG_MAP_ADDR, map, x, y
	.dw ((VRAMBase) + ((map) << 10) + (x) + ((y) << 5))
.endmacro

.macro BG_PALETTE_BUFFER, p
	.dw 0x03004b64 + (p * 0x10)
.endmacro

.macro OBJ_PALETTE_BUFFER, p
	.dw 0x03004d64 + (p * 0x10)
.endmacro

.macro END_OF_GRAPHICS_TABLE
	.dw NULL
	.dw NULL
	.dw 0
.endmacro