
/* ------------------------ Beatscript Labels: Karate Man ------------------------ */

; Game Engine
.definelabel karate_man_engine, 0x089df044

; Game Events
.definelabel RESET_BG_FACE,     		0x00
.definelabel START_SERIOUS_NEXT_HIT,    0x01
.definelabel STOP_SERIOUS_NEXT_HIT,     0x02
.definelabel PRINT_TEXTBOX,             0x03
.definelabel WAIT_AT_TEXTBOX,           0x04
.definelabel ENABLE_FLOW_METER,         0x05
.definelabel START_TUTORIAL_LOOP,       0x06
.definelabel EXIT_LOOP_IF_ALL_HIT,      0x07
.definelabel USE_THE_FACE,              0x08

; Cues
.definelabel CUE_POT,           0x00
.definelabel CUE_SOCCER_BALL,   0x01
.definelabel CUE_POT_STRICT,    0x02
.definelabel CUE_ROCK,          0x04
.definelabel CUE_BOMB,          0x05
.definelabel CUE_LIGHT_BULB,    0x08

; Load Game: Karate Man
.macro load_karate_man
    load_game karate_man_engine, 0 ; karate_man_engine 
.endmacro

; Load Game: Karate Man (Unused Faces)
.macro load_karate_man_unused
    load_game karate_man_engine, 1 ; karate_man_engine 
.endmacro

; Load Game: Karate Man (Start with Serious Mode Active)
.macro load_karate_man_serious
    load_game karate_man_engine, 2 ; karate_man_engine 
.endmacro

; Load Game: Karate Man 2
.macro load_karate_man_2
    load_game karate_man_engine, 3 ; karate_man_engine 
.endmacro

; Load Game: Karate Man (Tempo Up!)
.macro load_karate_man_tempo_up
    load_game karate_man_engine, 4 ; karate_man_engine 
.endmacro


/* ---------------- Game Engine Events ---------------- */


; Run Game Event
.macro karate_man_event, event, args
    game_event 0x089df044, event, args
.endmacro


; [Event 0x00] Reset BG Face
.macro karate_man_reset_bg_face, noArgs
    karate_man_event RESET_BG_FACE, noArgs
.endmacro

; [Event 0x01] Start "Serious Mode" on Next Hit
.macro karate_man_start_serious_next_hit
    karate_man_event START_SERIOUS_NEXT_HIT, 0
.endmacro

; [Event 0x02] Finish "Serious Mode" on Next Hit
.macro karate_man_stop_serious_next_hit
    karate_man_event STOP_SERIOUS_NEXT_HIT, 0
.endmacro

; [Event 0x03] Print Textbox
.macro karate_man_print_textbox, string
    karate_man_event PRINT_TEXTBOX, string
.endmacro

; [Event 0x04] Wait at Textbox for Player Input
.macro karate_man_wait_at_textbox
    karate_man_event WAIT_AT_TEXTBOX, 0
.endmacro

; [Event 0x05] Enable Flow Meter
.macro karate_man_enable_flow, enable
    karate_man_event ENABLE_FLOW_METER, enable
.endmacro

; [Event 0x06] Start Tutorial Loop (set required inputs to pass)
.macro karate_man_start_tutorial_loop, totalCues
    karate_man_event START_TUTORIAL_LOOP, totalCues
.endmacro

; [Event 0x07] Proceed With Tutorial if All Hit
.macro karate_man_exit_loop_if_all_hit, noArgs
    karate_man_event EXIT_LOOP_IF_ALL_HIT, noArgs
.endmacro

; [Event 0x08] Use The Face
.macro karate_man_use_the_face, use
    karate_man_event USE_THE_FACE, use
.endmacro