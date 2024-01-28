/* ------------------------ Types ------------------------ */

.definelabel NULL, 0

; Booleans
.definelabel FALSE, 0
.definelabel TRUE,  1

; RGB555 Colors
.definelabel BLACK, 0x0000
.definelabel WHITE, 0x7FFF

.definelabel PaletteRAMBase, 0x05000000
.definelabel VRAMBase, 0x06000000

/* ------------------------ Common ------------------------ */

.macro glabel,value
	.align 4 ; maybe?
	value:
.endmacro

.macro script,label
    glabel label
.endmacro

.macro struct, label
    glabel label
.endmacro

.macro endstruct
    .align 4
.endmacro

.macro text, label
    glabel label
.endmacro

.macro endtext
    .align 4
.endmacro