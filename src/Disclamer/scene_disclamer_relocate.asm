; Script
script script_scene_disclamer
	set_tempo 120
	pause_scene
	
	rest 12
	rest 48
	run 0x0801DFAD,0 ; disclamer_scene_render_anim
	scene_set_int INT8, 0, TRUE
	pause_scene
	
	fade_music_out TO_TEMPO, 48
    fade_screen_out 12, BLACK
    rest 12
    rest 12
    stop
	
; Local Scene
struct sub_scene_disclamer
	/* Start  */ .word 0x801E09D,	0 ; disclamer_scene_start
    /* Paused */ .word NULL,		0
    /* Active */ .word 0x801E0C9,	0 ; disclamer_scene_update
    /* Stop   */ .word 0x801DFDD,	0 ; disclamer_scene_stop
    /* Script */ .word script_scene_disclamer
endstruct

; RIQ Disclamer Scene
struct scene_disclamer
    /* Start  */ .word 0x0801d86d, 	sub_scene_disclamer
    /* Update */ .word 0x0801d8d9, 	0
    /* Stop   */ .word NULL,   		0
    /* Memory */ .word 0x8
endstruct