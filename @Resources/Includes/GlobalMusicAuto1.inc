; ; ---------------------------------------------------------------------------- ;
; ;                                      Gru                                     ;
; ; ---------------------------------------------------------------------------- ;

[stateAIMP]
Measure=NowPlaying
PlayerName=AIMP
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateCAD]
Measure=NowPlaying
PlayerName=CAD
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWMP]
Measure=NowPlaying
PlayerName=WMP
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateiTunes]
Measure=NowPlaying
PlayerName=iTunes
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWinamp]
Measure=NowPlaying
PlayerName=Winamp
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWebNowPlaying]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

; ; ---------------------------------------------------------------------------- ;
; ;                                    Minions                                   ;
; ; ---------------------------------------------------------------------------- ;

; ; ------------------------------------ NP ------------------------------------ ;

[npPlayer]
Measure=String
String=#NowPlayingMedia#
UpdateDivider=-1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npCover]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Cover
Substitute="":"#@#Images\Default.png"
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npArtist]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Artist
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npTrack]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Title
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npProgress]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npCurrentPosition]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Position
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npLength]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Duration
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

; [npRepeat]
; Measure=NowPlaying
; PlayerName=[state#NowPlayingMedia#]
; PlayerType=Repeat
; IfCondition=npRepeat = 1
; IfTrueAction=[!SetOption Repeat MeterStyle Repeat1][!UpdateMeter Repeat][!Redraw]
; IfCondition2=npRepeat = 2
; IfTrueAction2=[!SetOption Repeat MeterStyle Repeat2][!UpdateMeter Repeat][!Redraw]
; IfCondition3=npRepeat = 0
; IfTrueAction3=[!SetOption Repeat MeterStyle Repeat0][!UpdateMeter Repeat][!Redraw]
; UpdateDivider=1
; Group=Music | NP
; Disabled=1

; [npShuffle]
; Measure=NowPlaying
; PlayerName=[state#NowPlayingMedia#]
; PlayerType=Shuffle
; IfCondition=npShuffle = 0
; IfTrueAction=[!SetOption Shuffle MeterStyle "Shuffle0"][!UpdateMeter Shuffle][!Redraw]
; IfFalseAction=[!SetOption Shuffle MeterStyle "Shuffle1"][!UpdateMeter Shuffle][!Redraw]
; UpdateDivider=1
; Group=Music | NP
; DynamicVariables=1
; Disabled=1

[npHeart]
Measure=NowPlaying
PlayerName=[state#NowPlayingMedia#]
PlayerType=Rating
IfCondition=npHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"][!UpdateMeter Heart][!Redraw]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"][!UpdateMeter Heart][!Redraw]
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

; ------------------------------------ WNP ----------------------------------- ;

[wnpPlayer]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Player
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
DefaultPath=#@#Images\Default.png
CoverPath=#@#Images\Cover.png
; OnChangeAction=[!SetOption MainC Path "[#CURRENTSECTION#]"][!UpdateMeter MusicImg][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpCurrentPosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpLength]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration
UpdateDivider=1
Group=Music | WNP
Disabled=1

; [wnpRepeat]
; Measure=Plugin
; Plugin=WebNowPlaying
; PlayerType=Repeat
; IfCondition=wnpRepeat = 1
; IfTrueAction=[!SetOption Repeat MeterStyle Repeat1][!UpdateMeter Repeat][!Redraw]
; IfCondition2=wnpRepeat = 2
; IfTrueAction2=[!SetOption Repeat MeterStyle Repeat2][!UpdateMeter Repeat][!Redraw]
; IfCondition3=wnpRepeat = 0
; IfTrueAction3=[!SetOption Repeat MeterStyle Repeat0][!UpdateMeter Repeat][!Redraw]
; UpdateDivider=1
; Group=Music | WNP
; Disabled=1

; [wnpShuffle]
; Measure=Plugin
; Plugin=WebNowPlaying
; PlayerType=Shuffle
; IfCondition=wnpShuffle = 0
; IfTrueAction=[!SetOption Shuffle MeterStyle "Shuffle0"][!UpdateMeter Shuffle][!Redraw]
; IfFalseAction=[!SetOption Shuffle MeterStyle "Shuffle1"][!UpdateMeter Shuffle][!Redraw]
; UpdateDivider=1
; Group=Music | WNP
; Disabled=1

[wnpHeart]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Rating
IfCondition=wnpHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"][!UpdateMeter Heart][!Redraw]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"][!UpdateMeter Heart][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1