[Rainmeter]
MouseScrollUpAction=[!CommandMeasure mPath "IndexUp"][!UpdateMeasure mPath][!UpdateMeasureGroup Children][!UpdateMeter *][!Redraw]
MouseScrollDownAction=[!CommandMeasure mPath "IndexDown"][!UpdateMeasure mPath][!UpdateMeasureGroup Children][!UpdateMeter *][!Redraw]

[Variables]
IconSize=Medium

; ---------------------------------------------------------------------------- ;
;                                  MeterStyles                                 ;
; ---------------------------------------------------------------------------- ;

[Icon:Style]
X=(22*#Scale#)
Y=(5*#scale#)r
W=(32*#Scale#)
H=(32*#Scale#)
AntiAlias=1
MeasureName=m#CURRENTSECTION#
Container=Container
Group=List
Hidden=1

[Index:Style]
SolidColor=0,0,0,1
X=(17*#scale#)
Y=(26*#scale#)r
DynamicVariables=1
Shape=Rectangle 0,0,(#W#-17*2*#Scale#),((32+10)*#Scale#),(#Edge#/2) | StrokeWidth (#Stroke#*2) | Extend Fill
Fill=Stroke Color 0,0,0,1 | Fill Color 0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #BoxBorder# | Fill Color #BoxColor#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 0,0,0,1 | Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=Container
LeftMouseUpAction=[!CommandMeasure "mIndex#CurrentSection#Name" "Open"]
RightMouseUpAction=[!CommandMeasure "mIndex#CurrentSection#Name" "ContextMenu"]
Group=List
Hidden=1

[Name:Style]
X=(5*#Scale#)R
Y=(32/2*#scale#)r
Text=%1
StringAlign=LeftCenter
Container=Container
MeasureName=m#CURRENTSECTION#
Group=List
Hidden=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
[WinIcon]
ImageName=#@#Images\Orbs\Tiles.png
[Start]
Text=Program list

[OpenFolder]
Meter=String
X=(#W#-22*#Scale#)
Y=r
StringAlign=Right
FontSize=(#scale#*20)
Text=[\xe2c7]
FontColor=#FontColor#,150
LeftMouseUpAction=["C:\ProgramData\Microsoft\Windows\Start Menu\Programs"]
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor "#FontColor#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor "#FontColor#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Fontface=Material Icons Round
Container=Container
AntiAlias=1

[1]
Y=(20*#Scale#)R

@includeGenerated=#ROOTCONFIGPATH#Main\Accessories\Page\Variants\ProgramListCache.inc