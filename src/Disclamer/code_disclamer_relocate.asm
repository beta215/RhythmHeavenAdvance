.align 4
disclamer_scene_render_anim:
	push {lr}
	; sub sp, 0x14
	; ldr r0, =0x03005380
	; ldr r0, [r0]
	; ldr r1, =0x08932444
	; mov r2, 0x98
	; str r2, [sp]
	; mov r3, 0x0
	; str r3, [sp, 0x4]
	; mov r2, 0x1
	; str r2, [sp, 0x8]
	; str r3, [sp, 0xc]
	; str r3, [sp, 0x10]
	; mov r2, 0xf
	; mov r3, 0x78
	; bl 0x0804d160
	; add sp, 0x14
	pop {r0}
	bx r0
.pool

.align 4
disclamer_scene_stop:
	ldr r1, =0x03004498 ; 0x03004498 = 0
	mov r0, 0x1
	strb r0, [r1]
	bx lr
.pool

.align 4
disclamer_scene_init_gfx3:
	push {lr}
	sub sp, 0x8
	mov r0, 0x1
	bl 0x08007324
	mov r0, 0xc
	bl 0x0800c3a4
	add r1, r0, 0x0
	lsl r1, r1, 0x18
	lsr r1, r1, 0x18
	ldr r3, =0x7fff
	ldr r0, =disclamer_bg_pal
	str r0, [sp]
	ldr r0, =0x03004b64
	str r0, [sp, 0x4]
	mov r0, 0x0
	mov r2, 0x1
	bl 0x08002018
	ldr r1, =(0x0800bd04 + 1)
	mov r2, 0x0
	bl 0x08005d38
	add sp, 0x8
	pop {r0}
	bx r0
.pool

.align 4
disclamer_scene_init_gfx2:
	push {lr}
	mov r0, 0x0
	bl 0x0800c604
	bl 0x0800c3b8
	lsl r0, r0, 0x10
	lsr r0, r0, 0x10
	ldr r1, =disclamer_gfx_table
	mov r2, 0x80
	lsl r2, r2, 0x6
	bl 0x08002ee0
	ldr r1, =(disclamer_scene_init_gfx3 + 1)
	mov r2, 0x0
	bl 0x08005d38
	pop {r0}
	bx r0

.pool

.align 4
disclamer_scene_init_gfx1:
	push {lr}
	sub sp, 0xc ; allocates 12 bytes in stack
	bl 0x0800c3b8 ; get_current_mem_id()
	lsl r0, r0, 0x10
	lsr r0, r0, 0x10
	ldr r1, =(disclamer_scene_init_gfx2 + 1) ; disclamer_scene_init_gfx2
	mov r2, 0x0 ; args 
	mov r3, 0x2 ; delay
	bl 0x0800856c ; schedule_function_call();
	bl 0x0800e0ec ; scene_show_obj_layer();
	mov r0, 0x0
	str r0, [sp]
	mov r0, 0x1d
	str r0, [sp, 0x4]
	mov r0, 0x1
	str r0, [sp, 0x8]
	mov r1, 0x1
	mov r2, 0x0
	mov r3, 0x0
	bl 0x0800e0a0
	add sp, 0xc
	pop {r0}
	bx r0

.align 4	
disclamer_scene_start:
	push {lr} ; set up stack
	mov r0, 0x1
	bl 0x0801d860 ; func_0801d860(TRUE);
	ldr r1, =0x03004498
	mov r0, 0x0
	strb r0, [r1] ; 0x03004498 = FALSE; // disable A+B+START+SELECT
	bl disclamer_scene_init_gfx1 ; disclamer_scene_init_gfx1();
	ldr r0, =0x030046a4
	ldr r1, [r0]
	mov r0, 0x0
	str r0, [r1]
	ldr r0, =0x012C
	str r0, [r1, 0x4]
	
	ldr r1,=0x03007BD0
	mov r0,0x69
	strb r0,[r1]
	
	ldr r0,=disclamer_text ; please don't sell bootlegs
	ldr r1,=0x03007BB0
copy_loop:
	ldrb r2, [r0]
	strb r2, [r1]
	add r0, r0, 0x1
	add r1, r1, 0x1
	cmp r2, 0x00
	bne copy_loop
	
	pop {r0}
	bx r0
.pool

.align 4	
disclamer_scene_update:
	push {r4-r6, lr}
	ldr r4, =0x030046a4
	ldr r6, =0xe007B11
	ldr r1, [r4]
	
	ldrb r5,[r6]
	cmp r5, 0x69
	bne @@forcedToWatch
	
	ldr r0, [r1]
	cmp r0, 0x0
	beq branch_0801e0f2
	ldr r0, =0x03004afc
	ldrh r0, [r0]
	cmp r0, 0x0
	bne branch_0801e0e6
	
@@forcedToWatch:
	ldr r0, [r1, 0x4]
	sub r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x0
	bne branch_0801e0f2
branch_0801e0e6:
	mov r2,0x69
	strb r2,[r6]
	
	mov r0, 0x0
	bl 0x0800bd04
	ldr r1, [r4]
	mov r0, 0x0
	str r0, [r1]
branch_0801e0f2:
	pop {r4-r6}
	pop {r0}
	bx r0
.pool


.pool