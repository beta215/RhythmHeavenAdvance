
/* ------------------------ Beatscript Labels: Marching Orders ------------------------ */

.definelabel marching_orders_engine, 0x089e5518
.definelabel marching_orders_prologue_engine, 0x089EB6BC

.definelabel s_jingle_march_seqData, 0x08A9DA94
.definelabel s_guntai1_seqdata, 0x08A9DA94
.definelabel s_guntai2_seqdata, 0x08A9DA94
.definelabel s_guntai_foot1_seqdata, 0x08A9DA94
.definelabel s_guntai_foot2_seqdata, 0x08A9DA94
.definelabel s_guntai_v_migi_muke1_seqdata, 0x08A9DA94
.definelabel s_guntai_v_migi_seqdata, 0x08A9DA94
.definelabel s_guntai_v_ka_seqdata, 0x08A9DA94
.definelabel s_guntai_v_hidari_muke1_seqdata, 0x08A9DA94
.definelabel s_guntai_v_hidari_seqdata, 0x08A9DA94
.definelabel s_guntai_v_zentai1_seqdata, 0x08A9DA94
.definelabel s_guntai_v_susume_seqdata, 0x08A9DA94
.definelabel s_guntai_v_es_seqdata, 0x08A9DA94
.definelabel s_guntai_v_tomare_seqdata, 0x08A9DA94
.definelabel s_guntai_v_yoh_seqdata, 0x08A9DA94

.definelabel EVENT_00,          0x00
.definelabel EVENT_01,          0x01
.definelabel EVENT_02,          0x02
.definelabel EVENT_03,          0x03
.definelabel EVENT_04,          0x04
.definelabel PLAY_VOICE_SFX,    0x05

.definelabel CUE_STEP,          0x00
.definelabel CUE_TURN_LEFT,     0x01
.definelabel CUE_TURN_RIGHT,    0x02
.definelabel CUE_HALT,          0x03

.definelabel SHOUT_START,           0
.definelabel SHOUT_STOP,            1
.definelabel SHOUT_TURN,            2
.definelabel VOICE_ATTENTION,       3
.definelabel VOICE_MARCH,           4
.definelabel VOICE_HALT,            5
.definelabel VOICE_RIGHT_FACE,      6
.definelabel VOICE_RIGHT_FACE_F,    7
.definelabel VOICE_TURN_RIGHT,      8
.definelabel VOICE_LEFT_FACE,       9
.definelabel VOICE_LEFT_FACE_F,     10
.definelabel VOICE_TURN_LEFT,       11


.macro load_marching_orders
    load_game marching_orders_engine, 0
.endmacro

.macro load_marching_space_rabbits
    load_game marching_orders_engine, 1
.endmacro

.macro load_marching_orders_2_unused
    load_game marching_orders_engine, 2
.endmacro

.macro load_marching_orders_2
    load_game marching_orders_engine, 3
.endmacro


/* ---------------- Game Engine Events ---------------- */


.macro marching_orders_event, event, args
    game_event marching_orders_engine, event, args
.endmacro


.macro marching_orders_event00, args
    marching_orders_event EVENT_00, args
.endmacro

.macro marching_orders_event01, args
    marching_orders_event EVENT_01, args
.endmacro

.macro marching_orders_event02, args
    marching_orders_event EVENT_02, args
.endmacro

.macro marching_orders_event03, args
    marching_orders_event EVENT_03, args
.endmacro

.macro marching_orders_event04, args
    marching_orders_event EVENT_04, args
.endmacro

.macro marching_orders_play_voice_sfx, id
    marching_orders_event PLAY_VOICE_SFX, id
.endmacro
