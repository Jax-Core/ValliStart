[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Showfade | Custom0
ActionList2=Hidefade
Showfade=[!FadeDuration 100][!SHowFade][!CommandMeasure Func "initActions(1)"]
HideFade=[!HideFade][!CommandMeasure Func "initActions(-1)"]


; ---------------------------------------------------------------------------- ;
;                                     Load                                     ;
; ---------------------------------------------------------------------------- ;

[ACTIONLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Execute 1"]
Disabled=1
Group=NUOL

[ACTIONUNLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Execute 2"]
Disabled=1
Group=NUOL

[ImportAnimated]
Measure=String
OnUpdateAction=[!SetVariable ActualBlur #Blur#][!UpdateMeasure FrostedGlass]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Container]
Meter=Shape
Y=#TweenNode1#
DynamicVariables=1
Shape=Rectangle 0,0,#W#,(#H#),(#R#*#scale#),(#R#*#scale#) | StrokeWidth 1 | Stroke Color #Border#

