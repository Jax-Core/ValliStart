
; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;
[ActionTimer]
@includeModuleVariable=Vars\Volume.inc
Custom0=[!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]#BT_CheckBluetooth#

[Variables]
VolumeHeight=120

[MeasureWin7Audio]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
IfCondition=MeasureWin7Audio < 1
IfTrueAction=[!SetOption SoundIcon ImageName "#@#Icons\Sound0.png"][!UpdateMeter SoundIcon]
IfCondition2=(MeasureWin7Audio > 0) && (MeasureWin7Audio < 33)
IfTrueAction2=[!SetOption SoundIcon ImageName "#@#Icons\Sound1.png"][!UpdateMeter SoundIcon]
IfCondition3=(MeasureWin7Audio > 32) && (MeasureWin7Audio < 81)
IfTrueAction3=[!SetOption SoundIcon ImageName "#@#Icons\Sound2.png"][!UpdateMeter SoundIcon]
IfCondition4=MeasureWin7Audio > 80
IfTrueAction4=[!SetOption SoundIcon ImageName "#@#Icons\Sound.png"][!UpdateMeter SoundIcon]
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

[MediaSubtitle]
Meter=String
X=(25*#Scale#)
Y=(25*#Scale#)r
MeterStyle=RegularText
Text=Media control
FontColor=#Dark_Color#,200

[SoundIcon]
Meter=Image
ImageTint=#Font_Color#
X=(3*#Scale#)r
Y=(20*#Scale#)R
W=(20*#Scale#)
Imagename=
LeftMouseUpAction=[!CommandMeasure "MeasureWin7Audio" "ToggleMute"][!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]
Group=VolumeElements

[VolumeSlider]
Meter=Shape
X=(70*#Scale#)
Y=(8*#Scale#)r
Shape=Line 0,0,[VolumeSliderW],0 | Stroke Color #Border# | StrokeWidth (4*#Scale#) | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,([VolumeSliderW]*[VolumeSliderPercent]/100),0 | Stroke Color #Accent_color# | StrokeWidth (4*#Scale#) | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round
Shape3=Ellipse ([VolumeSliderW]*[VolumeSliderPercent]/100),((3*#Scale#)/2),(8*#Scale#),(8*#Scale#) | Fill Color #Accent_Color# | StrokeWidth 0
Shape4=Line 0,0,[VolumeSliderW],0 | Stroke Color 0,0,0,1 | StrokeWidth (25*#Scale#) | Fill Color 0,0,0,1
MouseScrollUpAction=[!CommandMeasure MeasureWin7Audio "ChangeVolume +#VolumeChangeLevel#"][!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]
MouseScrollDownAction=[!CommandMeasure MeasureWin7Audio "ChangeVolume -#VolumeChangeLevel#"][!UpdateMeasureGroup VolumeElements][!UpdateMeterGroup VolumeElements][!Redraw]
LeftMouseDownAction=[!CommandMeasure Func "InitMultiSlider('#CURRENTSECTION#')"]
SliderProperties=X|VolumeSliderW|1|1|MeasureWin7Audio|VolumeSliderPercent|VolumeElements|[!CommandMeasure $MeasureName$ "SetVolume $DragPercentage$"]|
;SliderProperties: Orientation, W/H, Invert, MeasureName, PercentMeasureName, GroupToUpdate, ActionWhenMouseDrag, ActionWhenMouseUp
DynamicVariables=1
Group=VolumeElements
[VolumesliderW]
Measure=Calc
Formula=((#FixW#-313)*#Scale#)

[VolumeText]
Meter=String
X=(30*#Scale#+[VolumeSliderW])r
Y=((3*#Scale#)/2)r
Text=[MeasureWin7Audio:0]
StringAlign=CenterCenter
DynamicVariables=1
MeterStyle=RegularText
Group=VolumeElements

[VolumeDevice]
MEter=Shape
X=(#scale#*35)r
Y=r
Shape=Rectangle 0,(-#scale#*20),(#scale#*150),(#scale#*40),(#R#*#Scale#),(#R#*#Scale#) | StrokeWidth (#Stroke#*2) | Fill Color #Dark_Color#,(#Alpha#*0.3) | Extend This
This=Stroke Color #BoxBorder#,(#Alpha#*0.5)
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke Color #Font_Color#,(#Alpha#*0.5)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke Color #BoxBorder#,(#Alpha#*0.5)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!SkinCustomMenu]
MiddleMouseUpAction=[!Refresh]

[VolumeDeviceText]
Meter=String
X=(#scale#*150/2)r
Y=r
W=(#Scale#*140)
ClipString=2
Measurename=MeasureWin7Audio
Text=%1
StringAlign=CenterCenter
MeterStyle=RegularText
Group=VolumeElements

[VolumeAnchor]
Meter=String
Y=(10*#Scale#*#Stroke#+(35*#Scale#))r
DynamicVariables=1