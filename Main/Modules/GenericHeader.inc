; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
@includeModuleVariable=Vars\GenericHeader.inc
GenericHeaderHeight=65

[MeasureTime]
Measure=Time
Format=%#gVar.2412#:%M
UpdateDivider=1
Disabled=#CustomFormat#
[MeasureSec]
Measure=Time
Format=:%S
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

[WinIcon]
Meter=Image
ImageTint=#Font_Color#
X=(22*#Scale#)
Y=(22*#Scale#)
W=(#scale#*25)
H=(#scale#*25)
ImageName=#@#Images\Orbs\#IconName#.png
LeftMouseUpAction=["#@#Actions\Nircmd.exe" sendkeypress LWin]
Hidden=(1-#StartIconBool#)

[Start]
Meter=String
X=(25*#Scale#+43*#Scale#*#StartIconBool#)
Y=(20*#Scale#)
Text=#StartText#
FontSize=(#scale#*15)
FontWeight=500
MeterStyle=RegularText
Hidden=(1-#StartTextBool#)

[Date]
Meter=String
X=(#W#-25*#Scale#)
Y=r
StringAlign=Right
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
Text=%1%2
[Date:0:I:1]
Text=%1%2  %3
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
Y=(45*#Scale#)r
DynamicVariables=1