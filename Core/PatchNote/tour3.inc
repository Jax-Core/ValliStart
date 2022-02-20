[Variables]
Sec.W=(500*#Sec.S#)
Sec.H=(700*#Sec.S#)
AniDir=Bottom
Sec.SaveLocation=#SKINSPATH##Sec.arg1#\@Resources\vars.inc
@includeMixerVariables=#SKINSPATH##Sec.arg1#\@Resources\vars.inc
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#SCREENAREAHEIGHT#/2)
[anchorX]
Formula=50
[anchorY]
Formula=50

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

; ---------------------------------------------------------------------------- ;
;                                  MeterStyles                                 ;
; ---------------------------------------------------------------------------- ;

[Sec.Icon:S]
FontFace=Segoe MDL2 Assets
X=(26/2*#Sec.S#)r
Y=(26/2*#Sec.S#)r
StringAlign=LeftCenter
FontSize=(10*#Sec.S#)
Text=[\xEA1F]
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[B2]
Meter=Shape
Shape=Rectangle 0,0,(#Sec.W#),(#Sec.H#),#Set.R# | StrokeWidth 0 | Fill Color #Set.Pri_color#
DynamicVariables=1
[Img2]
Meter=Image
W=(#Sec.w#)
H=(#sec.H#)
DynamicVariables=1
PreserveAspectRatio=2
Container=B2
ImageAlpha=50
ImageName=#SKINSPATH##Sec.arg1#\@Resources\Images\tour3.png


[Text2]
Meter=String
Text=8 built in styles#CRLF#With diverse layouts and dimensions
X=(#Sec.W#/2)
Y=(#Sec.H#/2)
FontSize=(20*#Sec.S#)
InlinePattern=.*#CRLF#
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 1.0 | #Set.Accent_Color_2# ; 0.0
INlinePattern2=#CRLF#.*
InlineSetting2=Size | (10*#Sec.S#)
INlinePattern3=#CRLF#.*
InlineSetting3=Color | 160,155,145
INlinePattern4=#CRLF#.*
InlineSetting4=Weight | 400
StringAlign=Center
MeterStyle=Sec.String:S
FontWeight=650




[SubtleText]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#-#Sec.P#)
FontColor=#Set.Subtext_Color#
StringAlign=CenterBottom
Text=Next
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure Func "interactionBox([[#SKINSPATH##sec.arg1#\Core\PatchNote\tour4.inc]])"][!Refresh]
MeterStyle=Sec.String:S

[Esc]
Meter=
