; Import all the data inside the ROM.

.org 0x08D34940

; Graphics Relocate

.include "gfx/Font/font_relocate.asm"
.include "gfx/RhythmGames/RatRace/ratrace_relocate.asm"
.include "gfx/RhythmGames/NightWalk/nightwalk_relocate.asm"
.include "gfx/RhythmGames/KarateMan/karateman_relocate.asm"
.include "gfx/RhythmGames/TempoUp/KarateMan/karateman_relocate.asm"
.include "gfx/RhythmGames/TheClappyTrio/clappy_relocate.asm"
.include "gfx/RhythmGames/TheSnappyTrio/snappy_relocate.asm"
.include "gfx/RhythmGames/Polyrhythm/polyrhythm_relocate.asm"
.include "gfx/RhythmGames/BouncyRoad/bouncy_relocate.asm"
.include "gfx/RhythmGames/ResultScreen/result_relocate.asm"
.include "gfx/RhythmGames/PowerCalligraphy/power_relocate.asm"
.include "gfx/RhythmGames/BunnyHop/bunnyhop_relocate.asm"
.include "gfx/RhythmGames/SamuraiSlice/slice_relocate.asm"
.include "gfx/RhythmGames/TapTrial/tap_relocate.asm"
.include "gfx/RhythmGames/MarchingOrders/marching_relocate.asm"
.include "gfx/RhythmGames/MarchingOrders2/marching2_relocate.asm"
.include "gfx/RhythmGames/SneakySpirits/sneaky_relocate.asm"
.include "gfx/RhythmGames/QuizShow/quizshow_relocate.asm"
.include "gfx/RhythmGames/RhythmTweezers/tweezers_relocate.asm"
.include "gfx/RhythmGames/NinjaBodyguard/bodyguard_relocate.asm"
.include "gfx/RhythmGames/NinjaReincarnate/descendant_relocate.asm"
.include "gfx/RhythmGames/TheBonDance/bondance_relocate.asm"
.include "gfx/RhythmGames/TheBonOdori/bonodori_relocate.asm"
.include "gfx/RhythmGames/TossTeam/tossteam_relocate.asm"
.include "gfx/RhythmGames/TramPauline/tramp_relocate.asm"
.include "gfx/RhythmGames/SickBeats/sickbeats_relocate.asm"
.include "gfx/RhythmGames/Showtime/showtime_relocate.asm"
.include "gfx/RhythmGames/Fireworks/fireworks_relocate.asm"
.include "gfx/RhythmGames/WizardWaltz/wizard_relocate.asm"
.include "gfx/RhythmGames/RAPMEN/rapmen_relocate.asm"
.include "gfx/RhythmGames/RAPWOMEN/rapwomen_relocate.asm"
.include "gfx/RhythmGames/Remix1/remix1_relocate.asm"
.include "gfx/RhythmGames/Remix2/remix2_relocate.asm"
.include "gfx/RhythmGames/Remix3/remix3_relocate.asm"
.include "gfx/RhythmGames/Remix4/remix4_relocate.asm"
.include "gfx/RhythmGames/Remix5/remix5_relocate.asm"
.include "gfx/RhythmGames/Remix6/remix6_relocate.asm"
.include "gfx/RhythmGames/Remix7/remix7_relocate.asm"
.include "gfx/RhythmGames/Remix8/remix8_relocate.asm"
.include "gfx/RhythmGames/SpaceDance/spacedance_relocate.asm"
.include "gfx/RhythmGames/CosmicDance/cosmicdance_relocate.asm"
.include "gfx/RhythmGames/Spaceball/spaceball_relocate.asm"
.include "gfx/HealthSafety/healthsafety_relocate.asm"
.include "gfx/Studio/studio_relocate.asm"
.include "gfx/MainMenu/mainmenu_relocate.asm"
.include "gfx/MedalCorner/medalcorner_relocate.asm"
.include "gfx/RhythmToys/rhythmtoys_relocate.asm"
.include "gfx/EndlessGames/endlessgames_relocate.asm"
.include "gfx/EndlessGames/MrUpbeat/upbeat_relocate.asm"
.include "gfx/EndlessGames/MannequinFactory/slapface_relocate.asm"
.include "gfx/DrumLessons/drumlessons_relocate.asm"
.include "gfx/RhythmArchives/archives_relocate.asm"
.include "gfx/GameSelect/gameselect_relocate.asm"
.include "gfx/RhythmTest/rtest_relocate.asm"
.include "gfx/Options/options_relocate.asm"
.include "gfx/Common/common_relocate.asm"
.include "gfx/Perfect/perfect_relocate.asm"
.include "gfx/Results/results_relocate.asm"
.include "gfx/Disclamer/disclamer_relocate.asm"

; SFX Relocate

.include "sfx/DrumLessons/drumlessons_relocate.asm"
;
;
; .include "sfx/TempoUp/RhythmTweezers/tweezers_relocate.asm"
; .include "sfx/SpaceDance/space_relocate.asm"

.include "src/TempoUp/KarateMan/karateman_relocate.asm"

.include "src/Disclamer/scene_disclamer_relocate.asm" ; move this somewhere

.include "src/DebugMenu/debugmenu_relocate.asm" ; move this somewhere