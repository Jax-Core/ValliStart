; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
VeklBigHeaderHeight=(149*#scale#+#Pad#)

[MeasureTime]
Measure=Time
Format=%#gVar.2412#%M
UpdateDivider=1

[MeasureDate]
Measure=Time
Format=%D
UpdateDivider=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[VeklHeader.Bg.Shape]
Meter=Shape
X=#P#
Y=#P#r
Shape=Rectangle 0,0,(#W#-#P#*2),(120*#Scale#),#R# | StrokeWidth 0 | Fill Color 0,0,0,1

[Date]
Meter=String
X=((#W#-#P#*2)/2)r
Y=(120/2*#scale#)r
StringAlign=CenterCenter
FontSize=(#scale#*72)
FontWeight=650
UpdateDivider=1
MeterStyle=RegularText
MeasureName=MeasureTime
InlinePattern=^..
InlineSetting=Color | #Accent_Color#

[GenericHeaderAnchor]
Meter=String
Y=([Date:YH]+#P#*#Divider#)
DynamicVariables=1