
; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;
[ActionTimer]
Custom0=[!Setvariable SliderX ([MeasureWin7Audio:0]/100*#SliderW#+#SliderM#)]#BT_CheckBluetooth#[!UpdateMeterGroup VolumeElements][!Redraw]

[Variables]
VolumeHeight=120
SliderM=(70*#Scale#)
SliderX=#SliderM#
SliderW=((#FixW#-313)*#Scale#)
SliderH=(3*#Scale#)

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

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[MediaSubtitle]
Meter=String
X=(25*#Scale#)
Y=(25*#Scale#)r
MeterStyle=RegularText
Text=Media control
FontColor=#DarkColor#,200
Container=Container

[SoundIcon]
Meter=Image
ImageTint=#FontColor#
X=(3*#Scale#)r
Y=(20*#Scale#)R
W=(20*#Scale#)
Container=Container
Imagename=
LeftMouseUpAction=[!CommandMeasure "MeasureWin7Audio" "ToggleMute"][!UpdateMeasure MeasureWin7Audio][!Redraw]
Group=VolumeElements

[VolumeSlider]
Meter=Shape
X=#SliderM#
Y=(8*#Scale#)r
Shape=Rectangle 0,0,#SliderW#,#SliderH#,(#Corner#),(#Corner#) | Fill Color #Border# | StrokeWidth 0
Shape2=Rectangle 0,0,(#SliderX#-#SliderM#),#SliderH#,(#Corner#),(#Corner#) | Fill Color #Accent# | StrokeWidth 0
Shape3=Ellipse (#SliderX#-#SliderM#),(#SliderH#/2),(8*#Scale#),(8*#Scale#) | Fill Color #Accent# | StrokeWidth 0
Shape4=Rectangle 0,(-#SliderH#*3),#SliderW#,(#SliderH#*6) | Fill Color 0,0,0,1 | StrokeWidth 0
LeftMouseDownAction=[!CommandMeasure MeasureMouse "Start"]
DynamicVariables=1
Container=Container
Group=VolumeElements

[VolumeText]
Meter=String
X=(30*#Scale#+#SliderW#)r
Y=(#SliderH#/2)r
Text=[MeasureWin7Audio:0]
StringAlign=CenterCenter
DynamicVariables=1
MeterStyle=RegularText
Container=Container
Group=VolumeElements

[VolumeDevice]
MEter=Shape
X=(#scale#*35)r
Y=r
Shape=Rectangle 0,(-#scale#*20),(#scale#*150),(#scale#*40),(#Corner#*5),(#Corner#*5) | StrokeWidth (#Stroke#*2) | Fill Color #DarkColor#,(#Alpha#*0.3) | Extend This
This=Stroke Color #BoxBorder#,(#Alpha#*0.5)
Container=Container
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke Color #FontColor#,(#Alpha#*0.5)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke Color #BoxBorder#,(#Alpha#*0.5)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseDownAction=[!CommandMeasure "MeasureWin7Audio" "TogglePrevious"][!UpdateMeasure MeasureWin7Audio][!Redraw]
RightMouseDownAction=[!CommandMeasure "MeasureWin7Audio" "ToggleNext"][!UpdateMeasure MeasureWin7Audio][!Redraw]
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
Container=Container
Group=VolumeElements

[VolumeAnchor]
Meter=String
Y=(10*#Scale#*#Stroke#+(35*#Scale#))r
DynamicVariables=1
Container=Container