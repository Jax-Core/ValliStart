; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;



[AppVolumeParent]
Measure=Plugin
Plugin=AppVolume
IgnoreSystemSound=1
ExcludeApp=rainmeter.exe; explorer.exe;

[MeasureMouse]
Measure=Plugin
Plugin=Mouse
; this measure uses the Plugin:Mouse
LeftMouseDragAction=[!CommandMEasure Func "dragMultiSlider($mouseX$)"]
; [!SetVariable SliderX "(Clamp(($MouseX$),(#SliderM#),((#SliderM#)+#SliderW#)))"][!UpdateMeasure SliderPercent][!UpdateMeterGroup VolumeElements][!Redraw]
; actions to be executed when the mouse drags. The first bang gets the mouse value and make sure it's in the slider. The bangs after that updates the required measures and the slider.
LeftMouseUpAction=[!CommandMEasure Func "termMultiSlider()"]
; actions to be executed after the mouse click is lifted. The first bang stops the measure to retrieve information from mouse dragging.
RelativeToSkin=1
RequireDragging=1
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                  MeterStyleS                                 ;
; ---------------------------------------------------------------------------- ;

[ShapeStyle]
Y=r
X=(150*#scale#)
Shape=Line 0,0,(#W#-(150+22+75)*#scale#),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round | Stroke Color #BoxColor#
Shape2=Line 0,0,(#W#-(150+22+75)*#scale#),0 | StrokeWidth 4 | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round | Stroke Color #Accent# | Scale ([AppVolPer#CURRENTSECTION#:]/100 > 0 ? [AppVolPer#CURRENTSECTION#:]/100 : 0), 1, 0, 0
Shape3=Line 0,0,(#W#-(150+22+75)*#scale#),0 | StrokeWidth 10 | Fill Color 0,0,0,1 | Stroke Color 0,0,0,1
Shape4=Ellipse ((#W#-(150+22+75)*#scale#)*[AppVolPer#CURRENTSECTION#:]/100),0,(6*#scale#),(6*#scale#) | StrokeWidth 0 | Fill Color #Accent#
DynamicVariables=1
LeftMouseDownAction=[!CommandMEasure Func "initMultiSlider('#CURRENTSECTION#')"]
Container=Container

[TextStyle]
X=(22*#scale#)
Y=(40*#scale#)r
W=((150-22)*#scale#)
MeasureName=App#CURRENTSECTION#
StringAlign=LeftCenter
Clipstring=1
FontColor=#FontColor#,([App#CURRENTSECTION#:] = -1 ? 150 : 255)
LeftMouseDownAction=[!CommandMeasure App#CURRENTSECTION# "ToggleMute"][!UpdateMeasureGroup UpdateWhenChange][!UpdateMeter *][!Redraw]]
Container=Container
DynamicVariables=1

[VolStyle]
X=(#W#-22*#scale#)
Y=r
W=(75*#scale#)
Text=[App#CURRENTSECTION#]
StringAlign=RightCenter
DynamicVariables=1
Clipstring=1
Container=Container

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
[WinIcon]
ImageName=#@#Images\Orbs\Tune.png
[Start]
Text=Volume Mixer

[Vol1]
Y=(40*#scale#)R

@includeGenerated=#ROOTCONFIGPATH#Main\Accessories\Page\Variants\VolumeMixerCache.inc