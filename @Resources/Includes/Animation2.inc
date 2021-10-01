[Rainmeter]
Update=20


[Variables]
TweenTime1=700

[mTween]
Measure=Script
ScriptFile=#@#LuaTween/Main.lua
TweenGroup=Ani
Tween0=Single | Variable | TweenNode1 | 0 | 1 | #TweenTime1#
Optional0=Easing InOutExpo
UpdateDivider=1
DynamicVariables=1

[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | UpdateValues | StartTween | Wait #TweenTime1# | BlurON
ActionList2=BlurOff | ReverseTween | Wait #TweenTime1# | Hide
UpdateValues=[!Setvariable SliderX ([MeasureWin7Audio:0]/100*#SliderW#+#SliderM#)]#BT_CheckBluetooth#[!UpdateMeterGroup VolumeElements][!Redraw]
StartTween=[!CommandMeasure mTween "Restart(0)"]
ReverseTween=[!CommandMeasure mTween "Rewind(0)"]
Show=[!Showfade][!EnableMeasure mTween][!UpdateMeasure mTween]
Hide=[!Hidefade][!DisableMeasure mTween]
BlurON=[!SetVariable ActualBlur #Blur#][!UpdateMeasure FrostedGlass]
BlurOff=[!SetVariable ActualBlur None][!UpdateMeasure FrostedGlass]


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

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Container]
Meter=Shape
Y=((#TweenNode1#-1)*-200*#Scale#)
Group=Ani
DynamicVariables=1
Shape=Rectangle 0,0,#W#,(#H#),(#edge#*#scale#),(#edge#*#scale#) | StrokeWidth 1 | Stroke Color #Border#

