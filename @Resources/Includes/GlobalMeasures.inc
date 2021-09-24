
[MeasureTime]
Measure=Time
Format=%H:%M
[MeasureSec]
Measure=Time
Format=:%S
[MeasureDate]
Measure=Time
Format=%a, %#b %#d
[MeasureUsername]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1



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

[SliderPercent]
Measure=Calc
Formula=((#SliderX#-(#SliderM#))*100/(((#SliderM#)+#SliderW#)-(#SliderM#)))
OnUpdateAction=[!CommandMeasure "MeasureWin7Audio" "SetVolume [#CURRENTSECTION#]"][!UpdateMeasure MeasureWin7Audio]
DynamicVariables=1
Disabled=1
Group=NUOL
UpdateDivider=-1

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


[WifiName]
Measure=PLUGIN
Plugin=WifiStatus
WiFiInfoType=SSID
Substitute="-1":"Not connected"
[WifiPercent]
Measure=PLUGIN
Plugin=WifiStatus
WiFiInfoType=QUALITY
Substitute="":""
OnUpdateAction=[!UpdateMeasure Wifistatus]
[WifiStatus]
Measure=CALC
Formula=(WifiPercent > 0) ? 1 : 0
UpdateDivider=-1
OnChangeAction=[!UpdateMeter WifiStatus1][!Redraw]
[InternetStatus]
Measure=PLUGIN
Plugin=SysInfo
SysInfoType=INTERNET_CONNECTIVITY
RegExpSubstitute=1
Substitute="^1$":"Connected","^-1$":"Not connected"
IfCondition=InternetStatus = -1
IfTrueAction=[!SetOption InternetStatus1 LeftMouseUpAction """[!CommandMeasure InternetOn "Run"]"""][!UpdateMeter InternetStatus1]
IfFalseAction=[!SetOption InternetStatus1 LeftMouseUpAction """[!CommandMeasure InternetOff "Run"]"""][!UpdateMeter InternetStatus1]
[InternetOff]
Measure=Plugin
Plugin=RunCommand
Parameter=ipconfig /release
State=Hide
[InternetOn]
Measure=Plugin
Plugin=RunCommand
Parameter=ipconfig /renew
State=Hide

; [MainC]
; Measure=Plugin
; Plugin=Chameleon
; Type=File
; Path=#@#Images\Default.png
; Format=Dec
; UpdateDivider=1
; [AVG]
; Measure=Plugin
; Plugin=Chameleon
; Parent=MainC
; Color=Average
; UpdateDivider=1