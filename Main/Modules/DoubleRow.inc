; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
DoubleRowHeight=290
BoxW=(100*#scale#)
CenterBool=


[DoubleBoxSubtitle]
Meter=String
X=(#W# >= 600 ? (#W#/2) : (25*#Scale#))
Y=(25*#Scale#)r
MeterStyle=RegularText
Text=Pinned applications
FontColor=#Dark_Color#,200
StringAlign=[&Func:returnCenterString(600)]Center
DynamicVariables=1

[BoxStyle]
X=(10*#Scale#+#BoxW#-(#BoxW#/2-48*#Scale#/2))r
Y=(-#BoxW#/2+48*#Scale#/2)r
Shape=Rectangle 0,0,#BoxW#,#BoxW#,(#R#*#Scale#),(#R#*#Scale#) | StrokeWidth (#Stroke#*2) | Fill Color #Dark_Color#,(#Alpha#*0.3) | Extend This
This=Stroke Color #BoxBorder#,(#Alpha#*0.5)
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke Color #Font_Color#,(#Alpha#*0.5)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke Color #BoxBorder#,(#Alpha#*0.5)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[BoxNewRowStyle]
X=(#W# >= 600 ? ((#W#)/2-(#BoxW#*5+10*4*#scale#)/2) : (25*#Scale#))
Y=(#BoxW#/2+(48/2+10)*#Scale#)r
[IconStyle]
X=(#BoxW#/2-48*#Scale#/2)r
Y=(#BoxW#/2-48*#Scale#/2)r
W=(48*#Scale#)
DynamicVariables=1
Group=Pinned
ImagePath=#SKINSPATH#..\CoreData\ValliStart\IconCache\

[DoubleBox1]
X=(#W# >= 600 ? ((#W#)/2-(#BoxW#*5+10*4*#scale#)/2) : (25*#Scale#))
Y=(#scale#*30)r

@includeDoubleRow=#SKINSPATH#..\CoreData\ValliStart\DoubleRow.inc

[DoubleRowAnchor]
Meter=String
Y=(100*#Scale#)r
DynamicVariables=1