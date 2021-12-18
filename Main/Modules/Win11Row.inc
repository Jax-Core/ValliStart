; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
Win11RowHeight=270
Win11BoxW=(82*#scale#)


[Win11BoxSubtitle]
Meter=String
X=(25*#Scale#)
Y=(25*#Scale#)r
MeterStyle=RegularText
Text=Pinned applications
FontColor=#DarkColor#,200
Container=Container

[Win11BoxStyle]
X=(10*#Scale#+(#Win11BoxW#/2))r
Y=(-#Win11BoxW#/2-(32/2+5)*#Scale#)r
Shape=Rectangle 0,0,#Win11BoxW#,#Win11BoxW#,(#Corner#*5),(#Corner#*5) | StrokeWidth 0 | Extend This
This=Fill Color #DarkColor#,(#Alpha#*0.0)
Container=Container
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #DarkColor#,(#Alpha#*0.3)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #DarkColor#,(#Alpha#*0.0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Win11IconStyle]
X=(#Win11BoxW#/2-32*#Scale#/2)r
Y=(#Win11BoxW#/2-32*#Scale#/2)r
W=(32*#Scale#)
H=(32*#Scale#)
DynamicVariables=1
Container=Container
Group=Pinned
ImagePath=#SKINSPATH#..\CoreData\ValliStart\IconCache\
[Win11TextStyle]
Text=Select a file...
X=(32/2*#Scale#)r
Y=(5*#Scale#)R
W=(#Win11BoxW#)
ClipString=2
StringAlign=Center
FontSize=(9*#Scale#)
Container=Container
Group=Pinned

[Win11Box1]
X=(#scale#*25)
Y=(#scale#*30)r

@includeWin11=#SKINSPATH#..\CoreData\ValliStart\Win11Row.inc

[Win11Anchor]
Meter=String
Y=(60*#Scale#)r
DynamicVariables=1
Container=Container