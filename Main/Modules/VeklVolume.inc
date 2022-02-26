
; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;
[ActionTimer]
@includeModuleVariable=Vars\VeklVolume.inc
Custom0=[!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]#BT_CheckBluetooth#

[Variables]
VeklVolumeHeight=(60+25)

[MeasureWin7Audio]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
IfCondition=MeasureWin7Audio < 0
iftrueaction=[!SetOption VeklVolume.R.Volume.StringIcon Text "[\xe04f]"][!UpdateMeter VeklVolume.R.Volume.StringIcon]
IfCondition2=(MeasureWin7Audio = 0)
IfTrueAction2=[!SetOption VeklVolume.R.Volume.StringIcon Text "[\xe04e]"][!UpdateMeter VeklVolume.R.Volume.StringIcon]
IfCondition3=(MeasureWin7Audio > 0) && (MeasureWin7Audio < 60)
IfTrueAction3=[!SetOption VeklVolume.R.Volume.StringIcon Text "[\xe04d]"][!UpdateMeter VeklVolume.R.Volume.StringIcon]
IfCondition4=(MeasureWin7Audio >= 60)
IfTrueAction4=[!SetOption VeklVolume.R.Volume.StringIcon Text "[\xe050]"][!UpdateMeter VeklVolume.R.Volume.StringIcon]
UpdateDivider=1
Group=VolumeElements

[VolumeSliderPercent]
Measure=Calc
Formula=MeasureWin7Audio
DynamicVariables=1
Group=VolumeElements

[MeasureMouse]
Measure=Plugin


[MeasureAudio]
Measure=Plugin
Plugin=AudioLevel
Port=Output
[MeasureDeviceList]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=DeviceList

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[VeklVolume.L.Bg.Shape]
Meter=Shape
X=#P#
Y=#P#r
Shape=Rectangle 0,0,(60*#scale#),(60*#Scale#),#R# | StrokeWidth #Stroke# | Extend This
This=Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke color #Dark_Color# | Fill Color #Ter_Color#,#Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[VeklVolume.L.Button]
Meter=String
FontFace=Material Icons Round
Text=[\xf01f]
X=(30*#Scale#)r
Y=(30*#Scale#)r
FontSize=(20*#Scale#)
MeterStyle=RegularText
StringAlign=CenterCenter
LeftMouseUpAction=[!SkinCustomMenu]

[VeklVolume.R.Bg.Shape]
Meter=Shape
X=(30*#scale#+#P#)r
Y=(-30*#Scale#)r
Shape=Rectangle 0,0,[VolumeSliderW],(60*#scale#),#R# | StrokeWidth #Stroke# | Extend This
Shape2=Rectangle 0,0,[VolumeSliderW],(60*#scale#),#R# | StrokeWidth #Stroke# | Extend That
Shape3=Rectangle 0,0,([VolumeSliderW]*[VolumeSliderPercent]/100),(60*#scale#) | StrokeWidth 0
Shape4=Combine Shape2 | Intersect Shape3
This=Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#
That=Fill Color #Ter_Color#,#Alpha#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke color #Dark_Color# | Fill Color #Ter_Color#,#Alpha#"][!SetOption #CURRENTSECTION# That "Fill Color #Dark_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#"][!SetOption #CURRENTSECTION# That "Fill Color #Ter_Color#,#Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseScrollUpAction=[!CommandMeasure MeasureWin7Audio "ChangeVolume +#VolumeChangeLevel#"][!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]
MouseScrollDownAction=[!CommandMeasure MeasureWin7Audio "ChangeVolume -#VolumeChangeLevel#"][!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]
LeftMouseDownAction=[!CommandMeasure Func "InitMultiSlider('#CURRENTSECTION#')"]
SliderProperties=X|VolumeSliderW|1|1|MeasureWin7Audio|VolumeSliderPercent|VolumeElements|[!CommandMeasure $MeasureName$ "SetVolume $DragPercentage$"]|
Group=VolumeElements
DynamicVariables=1
[VolumesliderW]
Measure=Calc
Formula=(#W#-3*#P#-60*#Scale#)

[VeklVolume.R.Volume.StringIcon]
Meter=String
FontFace=Material Icons Round
Text=[\xe050]
X=(30*#Scale#)r
Y=(30*#Scale#)r
FontSize=(16*#Scale#)
MeterStyle=RegularText
StringAlign=CenterCenter
LeftMouseUpAction=[!CommandMeasure "MeasureWin7Audio" "ToggleMute"][!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]
Group=VolumeElements

[VeklVolume.R.Volume.String]
Meter=String
X=(#P#)r
Y=r
Text=[MeasureWin7Audio:0]%
StringAlign=LeftCenter
DynamicVariables=1
MeterStyle=RegularText
Group=VolumeElements


; [VolumeSlider]
; Meter=Shape
; X=(70*#Scale#)
; Y=(8*#Scale#)r
; Shape=Rectangle 0,0,[VolumeSliderW],(3*#Scale#),(#R#) | Fill Color #Border# | StrokeWidth 0
; Shape2=Rectangle 0,0,([VolumeSliderW]*[VolumeSliderPercent]/100),(3*#Scale#),(#R#) | Fill Color Accent_Color | StrokeWidth 0
; Shape3=Ellipse ([VolumeSliderW]*[VolumeSliderPercent]/100),((3*#Scale#)/2),(8*#Scale#),(8*#Scale#) | Fill Color Accent_Color | StrokeWidth 0
; Shape4=Rectangle 0,(-(3*#Scale#)*3),[VolumeSliderW],((3*#Scale#)*6) | Fill Color 0,0,0,1 | StrokeWidth 0
; MouseScrollUpAction=[!CommandMeasure MeasureWin7Audio "ChangeVolume +#VolumeChangeLevel#"][!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]
; MouseScrollDownAction=[!CommandMeasure MeasureWin7Audio "ChangeVolume -#VolumeChangeLevel#"][!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]
; LeftMouseDownAction=[!CommandMeasure Func "InitMultiSlider('#CURRENTSECTION#')"]
; SliderProperties=X|VolumeSliderW|1|1|MeasureWin7Audio|VolumeSliderPercent|VolumeElements|[!CommandMeasure $MeasureName$ "SetVolume $DragPercentage$"]|
; ;SliderProperties: Orientation, W/H, Invert, MeasureName, PercentMeasureName, GroupToUpdate, ActionWhenMouseDrag, ActionWhenMouseUp
; DynamicVariables=1
; Group=VolumeElements
; [VolumesliderW]
; Measure=Calc
; Formula=((#FixW#-313)*#Scale#)

[VeklVolumeAnchor]
Meter=String
Y=(30*#scale#+#P#*#Divider#)r
DynamicVariables=1