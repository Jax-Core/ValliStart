
[MeasureTime]
Measure=Time
Format=%#gVar.2412#:%M
UpdateDivider=1
[MeasureSec]
Measure=Time
Format=:%S
UpdateDivider=1
Disabled=(#ShowSEc#-1)
[MeasureAP]
Measure=Time
Format=%p
UpdateDivider=1
; [MeasureDate]
; Measure=Time
; Format=%a, %#b %#d
; UpdateDivider=1
; [MeasureUsername]
; Measure=Plugin
; Plugin=SysInfo
; SysInfoType=USER_NAME



[MeasureWin7Audio]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
OnChangeAction=[!Setvariable SliderX ([MeasureWin7Audio:0]/100*#SliderW#+#SliderM#)][!UpdateMeterGroup VolumeElements][!Redraw]
IfCondition=MeasureWin7Audio < 1
IfTrueAction=[!SetOption SoundIcon ImageName "#@#Icons\Sound0.png"][!UpdateMeter SoundIcon]
IfCondition2=(MeasureWin7Audio > 0) && (MeasureWin7Audio < 33)
IfTrueAction2=[!SetOption SoundIcon ImageName "#@#Icons\Sound1.png"][!UpdateMeter SoundIcon]
IfCondition3=(MeasureWin7Audio > 32) && (MeasureWin7Audio < 81)
IfTrueAction3=[!SetOption SoundIcon ImageName "#@#Icons\Sound2.png"][!UpdateMeter SoundIcon]
IfCondition4=MeasureWin7Audio > 80
IfTrueAction4=[!SetOption SoundIcon ImageName "#@#Icons\Sound.png"][!UpdateMeter SoundIcon]
UpdateDivider=1

[SliderPercent]
Measure=Calc
Formula=((#SliderX#-(#SliderM#))*100/(((#SliderM#)+#SliderW#)-(#SliderM#)))
OnUpdateAction=[!CommandMeasure "MeasureWin7Audio" "SetVolume [#CURRENTSECTION#]"][!UpdateMeasure MeasureWin7Audio]
DynamicVariables=1
Disabled=1
Group=NUOL

[MeasureMouse]
Measure=Plugin
Plugin=Mouse
; this measure uses the Plugin:Mouse
LeftMouseDragAction=[!SetVariable SliderX "(Clamp(($MouseX$),(#SliderM#),((#SliderM#)+#SliderW#)))"][!UpdateMeasure SliderPercent][!UpdateMeterGroup VolumeElements][!Redraw]
; actions to be executed when the mouse drags. The first bang gets the mouse value and make sure it's in the slider. The bangs after that updates the required measures and the slider.
LeftMouseUpAction=[!CommandMeasure MeasureMouse "Stop"]
; actions to be executed after the mouse click is lifted. The first bang stops the measure to retrieve information from mouse dragging.
RelativeToSkin=1
RequireDragging=1
DynamicVariables=1