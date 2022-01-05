; ---------------------------------------------------------------------------- ;
;                                      Gru                                     ;
; ---------------------------------------------------------------------------- ;
[Variables]
PlayerType=Modern
NowPlayingMedia=Modern

[stateModern]
Measure=Plugin
Plugin=MediaPlayer.dll
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaModern()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

; ---------------------------------------------------------------------------- ;
;                                    Minions                                   ;
; ---------------------------------------------------------------------------- ;

; ------------------------------------ modern ------------------------------------ ;

[modernPlayer]
Measure=String
String=MediaPlayerDLL
UpdateDivider=-1
Group=Music | modern
DynamicVariables=1


[modernCover]
Measure=Plugin
Plugin=MediaPlayer.dll
PlayerType=Cover
Substitute="":"#@#Images\Default.png"
UpdateDivider=1
Group=Music | modern
DynamicVariables=1


[modernArtist]
Measure=Plugin
Plugin=MediaPlayer.dll
PlayerType=Artist
UpdateDivider=1
Group=Music | modern
DynamicVariables=1


[modernTrack]
Measure=Plugin
Plugin=MediaPlayer.dll
PlayerType=Title
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
UpdateDivider=1
Group=Music | modern
DynamicVariables=1


[modernProgress]
Measure=Plugin
Plugin=MediaPlayer.dll
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | modern
DynamicVariables=1


[modernCurrentPosition]
Measure=Plugin
Plugin=MediaPlayer.dll
PlayerType=Position
UpdateDivider=1
Group=Music | modern
DynamicVariables=1


[modernLength]
Measure=Plugin
Plugin=MediaPlayer.dll
PlayerType=Duration
UpdateDivider=1
Group=Music | modern
DynamicVariables=1


; [modernRepeat]
; Measure=Plugin
; Plugin=MediaPlayer.dll
; PlayerType=Repeat
; IfCondition=modernRepeat = 1
; IfTrueAction=[!SetOption Repeat MeterStyle Repeat1][!UpdateMeter Repeat][!Redraw]
; IfCondition2=modernRepeat = 2
; IfTrueAction2=[!SetOption Repeat MeterStyle Repeat2][!UpdateMeter Repeat][!Redraw]
; IfCondition3=modernRepeat = 0
; IfTrueAction3=[!SetOption Repeat MeterStyle Repeat0][!UpdateMeter Repeat][!Redraw]
; UpdateDivider=1
; Group=Music | modern


; [modernShuffle]
; Measure=Plugin
; Plugin=MediaPlayer.dll
; PlayerType=Shuffle
; IfCondition=modernShuffle = 0
; IfTrueAction=[!SetOption Shuffle MeterStyle "Shuffle0"][!UpdateMeter Shuffle][!Redraw]
; IfFalseAction=[!SetOption Shuffle MeterStyle "Shuffle1"][!UpdateMeter Shuffle][!Redraw]
; UpdateDivider=1
; Group=Music | modern
; DynamicVariables=1


[modernHeart]
Measure=Plugin
Plugin=MediaPlayer.dll
PlayerType=Rating
IfCondition=modernHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"][!UpdateMeter Heart][!Redraw]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"][!UpdateMeter Heart][!Redraw]
UpdateDivider=1
Group=Music | modern
DynamicVariables=1