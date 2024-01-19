.org 0x08C1A47C
.dw c1a47c_remix8_intro_obj |0x80000000

.org 0x08C5BADC
.dw c5badc_tweezers_remix8_bg | 0x80000000

.org 0x08C5C3A0
.dw c5badc_tweezers_remix8_bg_map_dat | 0x8000000

.org 0x08C5C3A0+4
.dw c5badc_tweezers_remix8_bg_map_rle | 0x8000000

.org 0x08C5C3A0+8
.dw c5badc_tweezers_remix8_bg_map_rle_end - c5badc_tweezers_remix8_bg_map_rle

.org 0x088E8C42 ; palette hot fix
.dw 0x7fff
.org 0x088E8B82 ; palette hot fix (remix 8, wow isn't that funny)
.dw 0x7fff

.org 0x08C5C3A8 ; rle size hot fix
.byte 0x3A ; hahahahahaha stupid hotfix but i've been trying to fix this for
; the past like 6 hours and it just doesn't go away so I GIVE UP!
; if anyone wants to try and fix it well, it has to do something the with the map from 0x600e000 overflowing
; into 0x600f000, this value changes the RLE size to what makes it less broken then
; changes the palette to be make it invisible so that i just camouflage the issue
; that's NOT a good viable solution because if anyone wants to add custom background it would just
; immediately show, even if it's just 0x00 tiles with palette 0

.org 0x088B3004
.import "gfx/RhythmGames/Remix8/8B3004_assembly0.bin"
.org 0x088B300C
.import "gfx/RhythmGames/Remix8/8B300C_assembly1.bin"
.org 0x088B3032
.import "gfx/RhythmGames/Remix8/8B3032_assembly2.bin"
.org 0x088B3082
.import "gfx/RhythmGames/Remix8/8B3082_assembly3.bin"
.org 0x088B30F0
.import "gfx/RhythmGames/Remix8/8B30F0_assembly4.bin"
.org 0x088B3182
.import "gfx/RhythmGames/Remix8/8B3182_assembly5.bin"
.org 0x088B323E
.import "gfx/RhythmGames/Remix8/8B323E_assembly6.bin"