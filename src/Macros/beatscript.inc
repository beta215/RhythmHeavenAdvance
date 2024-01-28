/* 
*   taken and adapted from https://github.com/arthurtilly/rhythmtengoku/
*/

/* ------------------------ Types ------------------------ */


; Read/Write Target Types
.definelabel INT8,  0
.definelabel INT16, 1
.definelabel INT32, 2
.definelabel FUNC,  3

; Time Value Types
.definelabel REALTIME, 0
.definelabel TO_TEMPO, 1

; Marking Criteria Flags
.definelabel CHECK_AVERAGE_MISSES, 0x100
.definelabel OVERRIDE_COMMENTS,    0x80
.definelabel CHECK_AVERAGE_HITS,   0x1

.definelabel END_OF_CRITERIA, NULL


/* ------------------------ Common ------------------------ */

; Beatscript Gameplay Scene Definitions
.macro define_gameplay_scene, name, sub_name, entrypoint
struct sub_name
    /* Init Func   */ .word 0x08016ec5,    	NULL
    /* Paused Func */ .word 0x08016ffd, 	NULL
    /* Update Func */ .word 0x08017001,     NULL
    /* End Func    */ .word 0x080177f1,		NULL
    /* Beatscript  */ .word entrypoint
endstruct

struct name
    /* Init Func   */ .word 0x0801d86d, sub_name
    /* Update Func */ .word 0x0801d8d9, NULL
    /* End Func    */ .word NULL,       NULL
    /* Memory      */ .dh 0x05BC
endstruct
.endmacro

/* ------------------------ Command Macros ------------------------ */

.macro beatscript_cmd, id, arg1, arg2, arg3
    .word (((id) & 0xff) | ((arg1) << 8))
    .word (arg2)
    .word (arg3)
.endmacro

.macro rest, time
    beatscript_cmd 0x00, 0, 0, time
.endmacro

.macro stop
    beatscript_cmd 0x01, 0, 0, 0
.endmacro

.macro scene_run, function, arg
    beatscript_cmd 0x02, 0, function, arg
.endmacro

.macro run, function, arg
    beatscript_cmd 0x03, 0, function, arg
.endmacro

.macro run2, function, arg1, arg2
    beatscript_cmd 0x04, arg1, function, arg2
.endmacro

.macro set_int, type, address, value
    beatscript_cmd 0x05, type, address, value
.endmacro

.macro add_int, type, address, value
    beatscript_cmd 0x06, type, address, value
.endmacro

.macro set_bit, type, address, bit
    beatscript_cmd 0x07, type, address, bit
.endmacro

.macro clear_bit, type, address, bit
    beatscript_cmd 0x08, type, address, bit
.endmacro

.macro scene_set_int, type, offset, value
    beatscript_cmd 0x09, type, offset, value
.endmacro

.macro scene_add_int, type, offset, value
    beatscript_cmd 0x0A, type, offset, value
.endmacro

.macro scene_set_bit, type, offset, bit
    beatscript_cmd 0x0B, type, offset, bit
.endmacro

.macro scene_clear_bit, type, offset, bit
    beatscript_cmd 0x0C, type, offset, bit
.endmacro

.macro call, script
    beatscript_cmd 0x0D, 0, script, 0
.endmacro

.macro return
    beatscript_cmd 0x0E, 0, 0, 0
.endmacro

.macro goto, script
    beatscript_cmd 0x0F, 0, script, 0
.endmacro

.macro loop_start
    beatscript_cmd 0x10, 0, 0, 0
.endmacro

.macro loop_end
    beatscript_cmd 0x11, 0, 0, 0
.endmacro

.macro if_eq, type, address, value
    beatscript_cmd 0x12, type, address, value
.endmacro

.macro if_neq, type, address, value
    beatscript_cmd 0x13, type, address, value
.endmacro

.macro else
    beatscript_cmd 0x14, 0, 0, 0
.endmacro

.macro end_if
    beatscript_cmd 0x15, 0, 0, 0
.endmacro

.macro if_set, address, bit
    beatscript_cmd 0x16, 0, address, bit
.endmacro

.macro if_clear, address, bit
    beatscript_cmd 0x17, 0, address, bit
.endmacro

.macro switch, type, address
    beatscript_cmd 0x1A, type, 0, address
.endmacro

.macro end_switch
    beatscript_cmd 0x1B, 0, 0, 0
.endmacro

.macro case, value
    beatscript_cmd 0x1C, 0, 0, value
.endmacro

.macro break
    beatscript_cmd 0x1D, 0, 0, 0
.endmacro

.macro scene_if_eq, type, offset, value
    beatscript_cmd 0x21, type, offset, value
.endmacro

.macro scene_if_neq, type, offset, value
    beatscript_cmd 0x22, type, offset, value
.endmacro

.macro scene_switch, type, offset
    beatscript_cmd 0x23, type, 0, offset
.endmacro

.macro play_music_in, player, music
    beatscript_cmd 0x28, 0, player, music
.endmacro

.macro play_music, music
    play_music_in DEFAULT_SOUND_PLAYER, music
.endmacro

.macro play_sfx, sound
    beatscript_cmd 0x29, 0, 0, sound
.endmacro

.macro fade_music_in, toTempo, time
    beatscript_cmd 0x35, toTempo, 0, time
.endmacro

.macro fade_music_out, toTempo, time
    beatscript_cmd 0x36, toTempo, 0, time
.endmacro

.macro fade_sfx_out, sound, time
    beatscript_cmd 0x38, 0, sound, time
.endmacro

.macro load_graphics, address
    beatscript_cmd 0x39, 0, address, 0
.endmacro

.macro add_music_in, player, music
    beatscript_cmd 0x3A, 0, player, music
.endmacro

.macro add_music, music
    add_music_in DEFAULT_SOUND_PLAYER, music
.endmacro

.macro set_speed, speed
    beatscript_cmd 0x3C, 0, 0, speed
.endmacro

.macro set_music_pitch_s, pitch
    beatscript_cmd 0x3D, 0, 0, pitch
.endmacro

.macro set_music_pitch, pitch
    beatscript_cmd 0x3E, 0, 0, pitch
.endmacro

.macro mod_lcd_blend, reverse, controls, toTempo, time
    beatscript_cmd 0x3F, reverse, controls, ((toTempo << 31) | (time & 0x7FFFFFFF))
.endmacro

.macro mod_lcd_blend_to, controls, toTempo, time
    mod_lcd_blend 0, controls, toTempo, time
.endmacro

.macro mod_lcd_blend_from, controls, toTempo, time
    mod_lcd_blend 1, controls, toTempo, time
.endmacro

.macro task_load_graphics, address, limit
    beatscript_cmd 0x47, 0, address, limit
.endmacro

.macro set_backdrop, arg1, arg2, arg3
    beatscript_cmd 0x48, arg1, arg2, arg3
.endmacro

.macro set_video_mode, mode
    beatscript_cmd 0x49, 0, mode, 0
.endmacro

.macro fade_screen, reverse, time, color
    beatscript_cmd 0x4A, reverse, time, color
.endmacro

.macro fade_screen_in, time, color
    fade_screen 0, time, color
.endmacro

.macro fade_screen_out, time, color
    fade_screen 1, time, color
.endmacro

.macro mod_tempo, tempo, time
    beatscript_cmd 0x4C, 0, tempo, time
.endmacro

.macro mod_music_pitch, pitch, time
    beatscript_cmd 0x4E, 0, pitch, time
.endmacro

.macro default
    beatscript_cmd 0x4F, 0, 0, 0
.endmacro

.macro mod_music_volume, volume, time
    beatscript_cmd 0x50, 0, volume, time
.endmacro

.macro dma_set, tileCount, src, dest
    beatscript_cmd 0xA6, tileCount, src, dest
.endmacro

.macro set_speed_to_music, music
    beatscript_cmd 0xA7, 0, 0, music
.endmacro

.macro set_music_track_volume, tracks, volume
    beatscript_cmd 0xAC, tracks, volume, 0
.endmacro

.macro mute_music_track, tracks
    set_music_track_volume tracks, 0
.endmacro

.macro reset_music_track_volumes
    set_music_track_volume 0, 0
.endmacro

.macro mod_music_track_volume, tracks, volume, time
    beatscript_cmd 0xAD, tracks, volume, time
.endmacro

.macro play_sfx_sp, sound, volume, pitch
    beatscript_cmd 0xAE, volume, pitch, sound
.endmacro

.macro increase_speed, multiplier, time
    beatscript_cmd 0xAF, 0, multiplier, time
.endmacro

.macro call_result
    beatscript_cmd 0xB0, 0, 0, 0
.endmacro

.macro rest_reset
    beatscript_cmd 0xB1, 0, 0, 0
.endmacro

.macro play_sfx_synced, sound, baseBPM, volume, pitch
    beatscript_cmd 0xB2, baseBPM, ((volume & 0xFFFF) | (pitch << 16)), sound
.endmacro


/* ------------------------ Extension Macros (Beatscript) ------------------------ */


; [SCENE] Set Tempo
.macro set_tempo, bpm
	run 0x0800BDF9, bpm
.endmacro


; [SCENE] Set Music Key
.macro set_music_key, key
    run scene_set_music_key, key
.endmacro


; [SCENE] Set Music Volume
.macro set_music_volume, volume
    run 0x0800C0D9, volume
.endmacro


; [SCENE] Pause Scene
.macro pause_scene
    run 0x0800BD05, TRUE
.endmacro

; [SCENE] Unpause Scene
.macro unpause_scene
    run set_pause_beatscript_scene, FALSE
.endmacro


; [SCENE] Get Random Value
.macro get_random, range
    run agb_random, range
.endmacro


; [GENERAL] Switch Statement with Random Value
.macro switch_random, type, range
    get_random range
    switch type, FUNCTION_RESULT
.endmacro

/* ------------------------ Extension Macros (Rhythm Tengoku) ------------------------ */


; [RIQ] Enable Pause Menu
.macro enable_pause_menu, enable
    run 0x0801db05, enable
.endmacro


; [RIQ] Enable Play Inputs
.macro enable_play_inputs, enable
    run 0x080173C5, enable
.endmacro


; [RIQ] Print Text (Standard Printer)
.macro print_text_s, text
    run gameplay_display_text, text
.endmacro

.macro clear_text_s
    print_text_s NULL
.endmacro


; [RIQ] Set Results Header Text
.macro set_results_header, text
    run 0x08019311, text
.endmacro


; [RIQ] Import Marking Criteria
.macro import_marking_criteria, list
    run 0x08019305, list
.endmacro


; [RIQ] Enable Input Assessment
.macro assess_inputs, enable
    run 0x08019325, enable
.endmacro


; [RIQ] Set Current Marking Criteria
.macro set_marking_criteria, id
    run 0x08017909, id
.endmacro


; [RIQ] Forgive Some Misses
.macro forgive_x_misses, total
    run 0x080177DD, total
.endmacro


; [RIQ] Start Perfect Campaign
.macro start_perfect_campaign
    run 0x08017605, 0
.endmacro


; [RIQ] Enable Input Assessment for Perfect Campaign
.macro assess_perfect_inputs, enable
    run 0x08017649, enable
.endmacro


; [RIQ] Set Current Game Engine
.macro load_game, engine, version
    run2 0x08017189, version, engine
.endmacro


; [RIQ] Run Game Engine Event
.macro game_event, engine, event, args
    run 0x08017381, args
    run2 0x0801738D, event, engine
.endmacro


; [RIQ] Run Game Common Event
.macro common_event, event, arg
    run2 0x08017349, event, arg
.endmacro

; Play Beat Animations
.macro beat_anim
    common_event 0, 0
.endmacro

; Print Special Text/Sprite
.macro print_text_f, arg
    common_event 1, arg
.endmacro

.macro clear_text_f
    print_text_f 0
.endmacro

; Initialise Tutorial
.macro init_tutorial, skipDest
    common_event 2, skipDest
.endmacro

.macro stop_tutorial
    init_tutorial NULL
.endmacro


; [RIQ] Spawn Cue
.macro spawn_cue, cueID
    run 0x080179F5, cueID
.endmacro


; [RIQ] Set Screen Fade-In Time
.macro set_game_fade_in_time, time
    run 0x08017569, time
.endmacro

; ------------ RANDOM FUNCTIONS

.definelabel stop_all_soundplayers, 0x08002839
.definelabel beatscript_disable_loops, 0x0800BCE5