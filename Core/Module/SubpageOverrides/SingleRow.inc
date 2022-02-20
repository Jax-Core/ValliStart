[Variables]
@includeModulevars=#SKINSPATH##Skin.Name#\@Resources\Shortcuts.inc
Sec.SaveLocation=#SKINSPATH##Skin.Name#\@Resources\Shortcuts.inc

[Item1.String]
Text=Configuring #Page.SubpageModule#, with #Count# actions.

[Choose:M]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
GetTarget=0
AllowNonstorageFolder=1
CopyLink=1
GetIcon=1
IconCache=#SKINSPATH#..\CoreData\ValliStart\IconCache\
IconSize=3
ReturnValue=WholePath
FileInitialDirectory=
ImageInitialDirectory=#CurrentPath#IconCache\
DynamicVariables=1
Command1=[!UpdateMEasure #CURRENTSECTION#][!CommandMeasure GenPs1 """WriteTo -index "#Editing#" -param1 "$Name$" -param2 "`[`"$Path$`"`]" -param3 "$Name$_$Ext$""""]

[GenLua]
Measure=Script
ScriptFile="#SKINSPATH##Skin.name#\Core\Gen.lua"

[GenPs1]
Measure=Plugin
Plugin=PowershellRM
ScriptFile="#SKINSPATH##Skin.name#\Core\Gen.ps1"

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;
[Action.Shape:S]
X=(20*[Set.S])
Y=(35*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(50*[SEt.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!SetVariable Editing "[&Func:trim('#CURRENTSECTION#', '.Shape','')]"][!UpdateMEasure Choose:M][!CommandMeasure Choose:M "ChooseFile 1"]
DynamicVariables=1
Container=ContentContainer
[Action.String:S]
X=(50*[Set.S]/2)r
Y=(50*[Set.S]/2)r
StringAlign=LeftCenter
Group=DynamicName
DynamicVariables=1
Container=ContentContainer
[Action.GoUP.Shape:S]
X=([ContentContainer:W]-#Set.P#-60*[SEt.S])
Y=(-15*[Set.S])r
Shape=Rectangle 0,0,(30*[Set.S]),(30*[Set.S]),(5*[Set.S]) | StrokeWidth 2 | Extend Stroke
Stroke=Stroke Color 0,0,0,1 | Fill Color #Set.Subtext_Color#,75
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color# | Fill Color #Set.Subtext_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color 0,0,0,1 | Fill Color #Set.Subtext_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure GenPs1 "WriteSwap -index [&Func:trim('#CURRENTSECTIOn#','.GoUP.Shape','')] -dir -1"]
DynamicVariables=1
Container=ContentContainer
[Action.GoUP.StringIcon:S]
X=(30*[Set.S]/2)r
Y=(30*[Set.S]/2)r
StringAlign=CenterCEnter
Text=[\xe5ce]
FontFace=Material Icons Round
Container=ContentContainer
[Action.GoDOWN.Shape:S]
X=(20*[SEt.S])r
Y=(-15*[Set.S])r
Shape=Rectangle 0,0,(30*[Set.S]),(30*[Set.S]),(5*[Set.S]) | StrokeWidth 2 | Extend Stroke
Stroke=Stroke Color 0,0,0,1 | Fill Color #Set.Subtext_Color#,75
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color# | Fill Color #Set.Subtext_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color 0,0,0,1 | Fill Color #Set.Subtext_Color#,75"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure GenPs1 "WriteSwap -index [&Func:trim('#CURRENTSECTIOn#','.GoDOWN.Shape','')] -dir 1"]
DynamicVariables=1
Container=ContentContainer
[Action.GoDOWN.StringIcon:S]
X=(30*[Set.S]/2)r
Y=(30*[Set.S]/2)r
StringAlign=CenterCEnter
Text=[\xe5cf]
FontFace=Material Icons Round
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[1.Shape]
Meter=Shape
MeterStyle=Action.Shape:S
[1.String]
Meter=String
MeterStyle=Set.String:S | Action.String:S
[1.GoUP.Shape]
Meter=Shape
MeterStyle=Action.GoUP.Shape:S
[1.GoUP.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoUP.StringIcon:S
[1.GoDOWN.Shape]
Meter=Shape
MeterStyle=Action.GoDOWN.Shape:S
[1.GoDOWN.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoDOWN.StringIcon:S

[2.Shape]
Meter=Shape
MeterStyle=Action.Shape:S
[2.String]
Meter=String
MeterStyle=Set.String:S | Action.String:S
[2.GoUP.Shape]
Meter=Shape
MeterStyle=Action.GoUP.Shape:S
[2.GoUP.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoUP.StringIcon:S
[2.GoDOWN.Shape]
Meter=Shape
MeterStyle=Action.GoDOWN.Shape:S
[2.GoDOWN.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoDOWN.StringIcon:S

[3.Shape]
Meter=Shape
MeterStyle=Action.Shape:S
[3.String]
Meter=String
MeterStyle=Set.String:S | Action.String:S
[3.GoUP.Shape]
Meter=Shape
MeterStyle=Action.GoUP.Shape:S
[3.GoUP.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoUP.StringIcon:S
[3.GoDOWN.Shape]
Meter=Shape
MeterStyle=Action.GoDOWN.Shape:S
[3.GoDOWN.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoDOWN.StringIcon:S

[4.Shape]
Meter=Shape
MeterStyle=Action.Shape:S
[4.String]
Meter=String
MeterStyle=Set.String:S | Action.String:S
[4.GoUP.Shape]
Meter=Shape
MeterStyle=Action.GoUP.Shape:S
[4.GoUP.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoUP.StringIcon:S
[4.GoDOWN.Shape]
Meter=Shape
MeterStyle=Action.GoDOWN.Shape:S
[4.GoDOWN.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoDOWN.StringIcon:S

[5.Shape]
Meter=Shape
MeterStyle=Action.Shape:S
[5.String]
Meter=String
MeterStyle=Set.String:S | Action.String:S
[5.GoUP.Shape]
Meter=Shape
MeterStyle=Action.GoUP.Shape:S
[5.GoUP.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoUP.StringIcon:S
[5.GoDOWN.Shape]
Meter=Shape
MeterStyle=Action.GoDOWN.Shape:S
[5.GoDOWN.StringIcon]
Meter=String
MeterStyle=Set.String:S | Action.GoDOWN.StringIcon:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;
