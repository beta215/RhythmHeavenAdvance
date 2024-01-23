_skiprhythmtest equ 0				; Skips the Rhythm Test when you don't have a save file.
_debug equ 0						; Various Debug hacks, unlock everything, etc...
_oamluaconsolemessages equ 1		; Logs OAM loads in RAM (for the gfxLocator.lua script)
_spriteluaconsolemessages equ 1		; Logs Sprite loads in RAM (for the gfxLocator.lua script)
_autoplay equ 0 					; Experimental Autoplay (Only works with A presses) (DOESN'T ALWAYS WORK!)
; If you're looking for the Debug Menu it's actually now in-game.
; (Press L & R when loading into Game Select from the Menu.)

; add more options here for compilation purposes

; example options
; (small guidelines, always put the name of the options in camelcase)
_useJapaneseText equ 0               ; If 1, compiles using the original ROM, not the Atlas one.