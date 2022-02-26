; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
@includeModuleVariable=Vars\VeklBarHeader.inc
VeklBarHeaderHeight=(50+#Pad#)

[MeasureTime]
Measure=Time
Format=%#gVar.2412# %M
UpdateDivider=1
Disabled=#CustomFormat#
[MeasureSec]
Measure=Time
Format=%S
UpdateDivider=1
Disabled=(#ShowSEc#-1)
Disabled=#CustomFormat#
[MeasureAP]
Measure=Time
Format=%p
UpdateDivider=1
Disabled=#CustomFormat#
[MeasureCustomFormat]
Measure=Time
Format=#CustomTimeFormat#
UpdateDivider=1
Disabled=(1-#CustomFormat#)

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[VeklHeader.Bg.Shape]
Meter=Shape
X=#P#
Y=#P#r
Shape=Rectangle 0,0,(#W#-#P#*2),(50*#Scale#),#R# | StrokeWidth #Stroke# | Extend This
This=Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#
That=Fill Color #Ter_Color#,#Alpha#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke color #Dark_Color# | Fill Color #Ter_Color#,#Alpha#"][!SetOption #CURRENTSECTION# That "Fill Color #Dark_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#"][!SetOption #CURRENTSECTION# That "Fill Color #Ter_Color#,#Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Date]
Meter=String
X=((#W#-#P#*2)/2)r
Y=(50/2*#scale#)r
StringAlign=CenterCenter
FontSize=(#scale#*15)
FontWeight=500
MeasureName=MeasureTime
MeasureName2=MeasureSec
MeasureName3=MeasureAP
MeasureName4=MeasureCustomFormat
MeterStyle=RegularText | Date:#CustomFormat#:#gVar.2412#:#ShowSec#
InlinePattern=A|P|M
InlineSetting=Size | (#Scale#*10)
FontColor=#Dark_Color#
UpdateDivider=1
LeftMouseUpAction=["#@#Actions\Nircmd.exe" sendkeypress LWin+Alt+D]
[Date:0:H:0]
Text=%1
[Date:0:I:0]
Text=%1  %3
[Date:0:H:1]
Text=%1 %2
[Date:0:I:1]
Text=%1 %2  %3
[Date:1:H:0]
Text=%4
[Date:1:I:0]
Text=%4
[Date:1:H:1]
Text=%4
[Date:1:I:1]
Text=%4

[GenericHeaderAnchor]
Meter=String
Y=(50/2*#scale#+#P#*#Divider#)r
DynamicVariables=1