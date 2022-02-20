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

[ImageContainer]
Meter=Shape
Shape=Rectangle 0,0,(#Sec.W#),[Image:H],#Sec.R# | StrokeWidth 0 | Fill LinearGradient This
This=90 | 0,0,0,0 ; 0 | 0,0,0,255 ; 1
DynamicVariables=1

[Image]
Meter=Image
Container=Imagecontainer
ImageName=#@#Images\TourPreview.png
W=#Sec.W#
H=(200*#sec.S#)
PreserveAspectRatio=2
ImageAlpha=175

[Img]
Meter=Image
X=(#Sec.W#/2-[Img:W]/2)
Y=#Sec.P#
W=(100*#Sec.S#)
H=([Img:W])
DynamicVariables=1
ImageName=#SKINSPATH##Sec.arg1#\@Resources\Images\yourMixer.png

[Text]
Meter=String
Text=YourMixer#CRLF#Volume control for Windows
X=(#Sec.W#/2)
Y=(15*#Sec.s#)R
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



; --------------------------------- Section1 --------------------------------- ;

[Section1]
Meter=Shape
X=#Sec.P#
Y=(15*#Sec.S#)R
Shape=Rectangle 0,0,(#Sec.W#-#Sec.P#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Leftmouseupaction=[!WriteKeyvalue Variables Hotkey "(#Hotkey# = 1 ? 0 : 1)" #Sec.SaveLocation#][!SetVariable Hotkey "(#Hotkey# = 1 ? 0 : 1)"][!UpdateMeter *][!Redraw]

[Section1.Icon]
Meter=String
X=(#Sec.P#)r
Y=(100/2*#Sec.S#)r
FontSize=(20*#Sec.S#)
MeterStyle=Sec.String:S | Sec.Icon:S | Section1.Icon:#Hotkey#
[Section1.Icon:0]
FontColor=#Set.Accent_Color#
Text=[\xE8BB]
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section1.Icon:1]
FontColor=#Set.Positive_Color#
Text=[\xE73E]
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section1.Text]
Meter=String
X=(60*#Sec.S#)r
Y=r
W=(#Sec.W#-120*#sec.S#)
FontSize=(10*#Sec.S#)
Text=Use hotkeys to launcher Mixer. #CRLF#You can configure the hotkeys in the settings.
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Sec.String:S

; --------------------------------- Section2 --------------------------------- ;

[Section2]
Meter=Shape
X=#Sec.P#
Y=(15*#Sec.S#)R
Shape=Rectangle 0,0,(#Sec.W#-#Sec.P#*2),(100*#Sec.S#),(#Sec.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Leftmouseupaction=[!WriteKeyvalue Variables Tray "(#Tray# = 1 ? 0 : 1)" #Sec.SaveLocation#][!SetVariable Tray "(#Tray# = 1 ? 0 : 1)"][!UpdateMeter *][!Redraw]

[Section2.Icon]
Meter=String
X=(#Sec.P#)r
Y=(100/2*#Sec.S#)r
FontSize=(20*#Sec.S#)
MeterStyle=Sec.String:S | Sec.Icon:S | Section2.Icon:#Tray#
[Section2.Icon:0]
FontColor=#Set.Accent_Color#
Text=[\xE8BB]
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section2.Icon:1]
FontColor=#Set.Positive_Color#
Text=[\xE73E]
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section2.Text]
Meter=String
X=(60*#Sec.S#)r
Y=r
W=(#Sec.W#-120*#sec.S#)
FontSize=(10*#Sec.S#)
Text=Create a volume tray icon#CRLF#Clicking on the tray icon launches YourMixer
StringAlign=LeftCenter
InlinePattern=#CRLF#.*
InlineSetting=Color | #Set.SubText_Color#
MeterStyle=Sec.String:S

[SubtleText]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#-#Sec.P#)
FontColor=#Set.Subtext_Color#
StringAlign=CenterBottom
Text=Next
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure Func "interactionBox([[#SKINSPATH##sec.arg1#\Core\PatchNote\tour2.inc]])"][!Refresh]
MeterStyle=Sec.String:S

[Esc]
Meter=
