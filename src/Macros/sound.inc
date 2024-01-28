/* ------------------------ Types ------------------------ */

; Music/Sound Players
.definelabel MUSIC_PLAYER_0,        0
.definelabel MUSIC_PLAYER_1,        1
.definelabel MUSIC_PLAYER_2,        2
.definelabel SFX_PLAYER_0,          3
.definelabel SFX_PLAYER_1,          4
.definelabel SFX_PLAYER_2,          5
.definelabel SFX_PLAYER_3,          6
.definelabel SFX_PLAYER_4,          7
.definelabel SFX_PLAYER_5,          8
.definelabel SFX_PLAYER_6,          9
.definelabel SFX_PLAYER_7,          10
.definelabel SFX_PLAYER_8,          11
.definelabel SFX_PLAYER_9,          12
.definelabel DEFAULT_SOUND_PLAYER,  255

; PSG Tone Duty
.definelabel PSG_TONE_DUTY_12_5,	0
.definelabel PSG_TONE_DUTY_25,		1
.definelabel PSG_TONE_DUTY_50,		2
.definelabel PSG_TONE_DUTY_75,		3

; PSG Noise Duty
.definelabel PSG_NOISE_COUNTER_15,	0
.definelabel PSG_NOISE_COUNTER_7,	1

; Instrument Type
.definelabel INSTRUMENT_PCM_ALIGNED,	'A'
.definelabel INSTRUMENT_PCM_FIXED,		'F'
.definelabel INSTRUMENT_PSG,          	'P'
.definelabel INSTRUMENT_PSG_ALT,     	'Q'
.definelabel INSTRUMENT_SUB_RHYTHM,  	'R'
.definelabel INSTRUMENT_SUB_SPLIT,	    'S'

; PSG Channels
.definelabel PSG_PULSE_CHANNEL_1,		0
.definelabel PSG_PULSE_CHANNEL_2,		1
.definelabel PSG_WAVE_CHANNEL,         	2
.definelabel PSG_NOISE_CHANNEL,     	3

; Music Tracks
.definelabel MIDI_TRACK_0,  (1 << 0)
.definelabel MIDI_TRACK_1,  (1 << 1)
.definelabel MIDI_TRACK_2,  (1 << 2)
.definelabel MIDI_TRACK_3,  (1 << 3)
.definelabel MIDI_TRACK_4,  (1 << 4)
.definelabel MIDI_TRACK_5,  (1 << 5)
.definelabel MIDI_TRACK_6,  (1 << 6)
.definelabel MIDI_TRACK_7,  (1 << 7)
.definelabel MIDI_TRACK_8,  (1 << 8)
.definelabel MIDI_TRACK_9,  (1 << 9)
.definelabel MIDI_TRACK_10, (1 << 10)
.definelabel MIDI_TRACK_11, (1 << 11)
.definelabel MIDI_TRACK_12, (1 << 12)
.definelabel MIDI_TRACK_13, (1 << 13)
.definelabel MIDI_TRACK_14, (1 << 14)
.definelabel MIDI_TRACK_15, (1 << 15)

/* ------------------------ Funcs ------------------------ */

.macro songheader, name, midiSequence, soundPlayer, soundBank, volume, priority, unk8, songNum
	glabel name
	.dw midiSequence
	.dw (soundPlayer & 0x1F) | ((soundBank & 0x3FF) << 5) | ((volume & 0x7F) << 15) | ((priority & 0x3FF) << 22)
	.dw unk8
	.dw 0
	.dw songNum
.endmacro

.macro instrumentpcm, name, type, key, fastRead, panning, sample, initial, sustain, attack, decay, fade, release
	glabel name
	.byte type
	.byte ((fastRead & 1) << 7) | key
	.dh panning
	.dw sample
	.dw initial
	.dw sustain
	.dw attack
	.dw decay
	.dw fade
	.dw release
.endmacro

.macro instrumentpsg, name, type, key, panning, wavetable, initial, sustain, attack, decay, fade, release, channel, length, sweep, dutyTone, dutyNoise
	glabel name
	.byte type
	.byte key
	.dh panning
	.dw wavetable
	.dw initial
	.dw sustain
	.dw attack
	.dw decay
	.dw fade
	.dw release
	; .dw ((channel & 0x03) << 30) | ((length & 0xFF) << 22) | ((sweep & 0x7F) << 15) | ((dutyTone & 0x03) << 13) | (dutyNoise & 0x1FFF)
	.dw ((dutyNoise & 0x1FFF) << 19) | ((dutyTone & 0x03) << 17) | ((sweep & 0x7F) << 10) | ((length & 0xFF) << 2) | (channel & 0x02)
.endmacro

.macro sampledata, name, length, sampleRate, pitch, loopStart, loopEnd, sample
	glabel name
	.dw length
	.dw sampleRate
	.dw pitch
	.dw loopStart
	.dw loopEnd
	.dw sample
.endmacro

.macro floattoq16, float
	
.endmacro