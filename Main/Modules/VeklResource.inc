; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;
[Variables]
@includeModuleVariable=Vars\VeklResource.inc
VeklResourceHeight=(200+#Pad#)

[MeasurePhysMemTotal]
Measure=PhysicalMemory
Total=1
[MeasurePhysMemUsed]
Measure=PhysicalMemory
UpdateDivider=1
[MeasureRAM]
Measure=Calc
Formula=(MeasurePhysMemUsed / MeasurePhysMemTotal) * 100
UpdateDivider=1
[MeasureCPU]
Measure=Plugin
Plugin=UsageMonitor
Alias=CPU
Index=0
RegExpSubstitute=1
Substitute="^0$":"0.01"
UpdateDivider=1
[MeasureBAT]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent

; ---------------------------------------------------------------------------- ;
;                                  MeterStyles                                 ;
; ---------------------------------------------------------------------------- ;

[VeklResource.StringIcon:S]
X=(#P#*2)
Y=(#P#*2)r
Fontface=Material Icons Round
FontSize=(24*#Scale#)
FontColor=[#[&Func:digit('#CURRENTSECTION#', 14, 16)]Color]
DynamicVariables=1
StringAlign=LeftCenter
[VeklResource.Shape:S]
X=(#P#*2)r
Y=r
Shape=Line 0,0,(#W#-#P#*6),0 | StrokeWidth (6*#Scale#) | Stroke Color #Dark_Color# | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#W#-#P#*6)*[&Measure[&Func:digit('#CURRENTSECTION#', 14, 16)]:]/100),0 | StrokeWidth (6*#Scale#) | Extend Fill | Fill Color 0,0,0,1 | StrokeStartCap Round | StrokeEndCap Round
Fill=Stroke Color [#[&Func:digit('#CURRENTSECTION#', 14, 16)]Color]
UpdateDivider=1
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[VeklResource.Shape]
Meter=Shape
X=#P#
Y=#P#r
Shape=Rectangle 0,0,(#W#-#P#*2),(#VeklResourceHeight#*#Scale#-#Pad#),#R# | StrokeWidth #Stroke# | Extend This
This=Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#
That=Fill Color #Ter_Color#,#Alpha#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke color #Dark_Color# | Fill Color #Ter_Color#,#Alpha#"][!SetOption #CURRENTSECTION# That "Fill Color #Dark_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#"][!SetOption #CURRENTSECTION# That "Fill Color #Ter_Color#,#Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[VeklResource.RAM.StringIcon]
Meter=String
Text=[\xe32b]
MeterStyle=RegularText | VeklResource.StringIcon:S
[VeklResource.RAM.Shape]
Meter=Shape
MeterStyle=VeklResource.Shape:s
[VeklResource.CPU.StringIcon]
Meter=String
Text=[\xe322]
MeterStyle=RegularText | VeklResource.StringIcon:S
[VeklResource.CPU.Shape]
Meter=Shape
MeterStyle=VeklResource.Shape:s
[VeklResource.BAT.StringIcon]
Meter=String
Text=[\xe1a4]
MeterStyle=RegularText | VeklResource.StringIcon:S
[VeklResource.BAT.Shape]
Meter=Shape
MeterStyle=VeklResource.Shape:s

[VeklResourceAnchor]
Meter=String
Y=([VeklResource.Shape:YH]+#P#*#Divider#)
DynamicVariables=1