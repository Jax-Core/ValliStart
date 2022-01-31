[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | Custom0 | Repeat In,4,10 | BlurOn
ActionList2=BlurOff | Repeat Out,4,10 | Hide
In=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#-10),0,100))"][!UpdateMeter Container][!UpdateMeasure ActionTimer][!Redraw]
Out=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#+10),0,100))"][!UpdateMeter Container][!UpdateMeasure ActionTimer][!Redraw]
Show=[!CommandMeasure Func "initActions(1)"][!Show][!SetVariable TweenNode1 100][!UpdateMeasure ActionTimer]
Hide=[!Hide]
BlurON=[!SetVariable ActualBlur #Blur#][!UpdateMeasure FrostedGlass][!UpdateMeasure ActionTimer]
BlurOff=[!SetVariable ActualBlur None][!UpdateMeasure FrostedGlass][!UpdateMeasure ActionTimer][!CommandMeasure Func "initActions(-1)"]


; ---------------------------------------------------------------------------- ;
;                                     Load                                     ;
; ---------------------------------------------------------------------------- ;

[ACTIONLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"]
Disabled=1
Group=NUOL

[ACTIONUNLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Stop 1"][!CommandMeasure ActionTimer "Execute 2"]
Disabled=1
Group=NUOL
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Container]
Meter=Shape
Y=#TweenNode1#
DynamicVariables=1
Shape=Rectangle 0,0,#W#,(#H#),(#edge#*#scale#),(#edge#*#scale#) | StrokeWidth 1 | Stroke Color #Border# | Fill Color 255,255,255,(255*(100-#TweenNode1#)/100)
MeterStyle=#Location#:BackgroundS

