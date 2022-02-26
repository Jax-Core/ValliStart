[LogicLua]
Measure=Script
ScriptFile=#SKINSPATH##Skin.name#\Core\Module\Logic.lua

[ContentContainer]
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-100,[AnchorChecker],0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+100,[AnchorChecker],0))"][!UpdateMeter *][!Redraw]

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;
[Item.Shape:S]
X=(20*[Set.S])
Y=(40*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(50*[SEt.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Item.StringIcon:S]
X=(50*[Set.S]/2)r
Y=(50*[Set.S]/2)r
StringAlign=leftCenter
FontFace=Segoe Fluent Icons
Container=ContentContainer
[Item.String:S]
X=(#Set.P#/2)R
Y=r
StringAlign=LeftCenter
Container=ContentContainer
[Item.Button.Shape:S]
X=([ContentContainer:W]-#Set.P#-30*[SEt.S])
Y=(-15*[Set.S])r
Shape=Rectangle 0,0,(30*[Set.S]),(30*[Set.S]),(5*[Set.S]) | StrokeWidth 0 | Extend Stroke
Stroke=Fill Color #Set.Positive_color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Fill Color #Set.Positive_color#,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Fill Color #Set.Positive_color#,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Item.Button.StringIcon:S]
X=(30*[Set.S]/2)r
Y=(30*[Set.S]/2)r
StringAlign=CenterCEnter
Text=[\xe5ce]
FontFace=Material Icons Round
Container=ContentContainer

[Module.Shape:S]
X=(20*[Set.S])
Y=(40*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),([ContentContainer:W]/4+50*[Set.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Shape2=Line (#Set.P#*0.5),([ContentContainer:W]/4),([ContentContainer:W]-#Set.P#*2),([ContentContainer:W]/4) | STrokeWidth 2 | Extend Stroke
Shape3=Line (([ContentContainer:W]-#Set.P#)/2),([ContentContainer:W]/4+45*[SEt.S]),(([ContentContainer:W]-#Set.P#)/2),([ContentContainer:W]/4+5*[Set.s]) | STrokeWidth 1 | Stroke Color #Set.Subtext_Color#
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Module.Image:S]
X=(10*[Set.S])r
Y=(10*[Set.S])r
W=([ContentContainer:W]-#Set.P#-20*[Set.S])
H=([ContentContainer:W]/4-20*[SEt.S])
ImageName=#SKINSPATH##Skin.Name#\Core\Module\[#[&Func:trim('#CURRENTSECTIOn#','.Image','')]].png
DynamicVariables=1
Container=ContentContainer
LeftMouseUpAction=[!CommandMeasure LogicLua "TakeDrag('#CURRENTSECTION#')"]
LeftMouseDownAction=[!CommandMeasure LogicLua "InitDrag('#CURRENTSECTION#')"]
MiddleMouseUpAction=[!WriteKeyValue Variables [&Func:trim('#CURRENTSECTIOn#','.Image','')] "None" "#SKINSPATh##Skin.Name#\@Resources\Vars.inc"][!SetVariable [&Func:trim('#CURRENTSECTIOn#','.Image','')] "None"][!CommandMeasure LogicLua "CheckIfNone()" "#JaxCore\Main"][!UpdateMeter *][!Redraw][!UpdateMeasure Auto_Refresh:M]
MaskImageName=#SKINSPATH##Skin.Name#\Core\Module\#ModuleMask.png
[Module.String:S]
X=(10*[Set.s])r
Y=(-10*[SEt.s])R
Text=[#[&Func:trim('#CURRENTSECTIOn#','.String','')]]
StringAlign=LeftBottom
Fontsize=(20*[Set.S])
FontWeight=650
Container=ContentContainer
[Module.Button1.Shape:S]
X=(-5*[Set.S])r
Y=(30*[Set.S])r
Shape=Rectangle 0,0,(([ContentContainer:W]-#Set.P#-60*[Set.s])/2),(30*[Set.S]),(5*[Set.S]) | StrokeWidth 2 | Extend Stroke
Stroke=Stroke Color 0,0,0,1 | Fill Color 0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,25 | Fill Color #Set.Subtext_Color#,25"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Stroke Color 0,0,0,1 | Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMEasure Func "window([[#SKINSPATH##Skin.Name#\Core\Window\ValliModule.inc]], '[&Func:trim('#CURRENTSECTIOn#','.Button1.Shape','')]', '1')"]
DynamicVariables=1
Container=ContentContainer
[Module.Button1.String:S]
X=(([ContentContainer:W]-#Set.P#-60*[Set.s])/2/2)r
Y=(30*[Set.S]/2)r
StringAlign=CenterCenter
Text=[\xf1cb]  Change
Inlinepattern=^.
InlineSetting=Face | Segoe Fluent Icons
Inlinepattern2=^.
InlineSetting2=Size  | (10*[Set.S])
Container=ContentContainer
[Module.Button2.Shape:S]
X=(([ContentContainer:W]-#Set.P#-60*[Set.s])/2/2+30*[Set.S])r
Y=(-30*[Set.S]/2)r
LeftMouseUpAction=[!WriteKeyvalue Variables page.subpagemodule "[#[&Func:trim('#CURRENTSECTIOn#','.Button2.Shape','')]]" "#SKINSPATH##Skin.Name#\Core\Modules.inc"][!WriteKeyvalue Variables page.page 2 "#SKINSPATH##Skin.Name#\Core\Modules.inc"][!Refresh]
[Module.Button2.String:S]
Text=[\xe713]  Settings

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Item1.Shape]
Meter=Shape
Y=(30*[Set.S])R
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe946]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=Drag between modules to switch, middle click to set blank
MeterStyle=Set.String:S | Item.String:S

[Item2.Shape]
Meter=Shape
MeterStyle=Item.Shape:S
[Item2.StringIcon]
Meter=String
Text=[\xe719]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item2.String]
Meter=String
Text=Discover more ValliStart 3.0 modules on the gumroad page!
MeterStyle=Set.String:S | Item.String:S
[Item2.Button]
Meter=Shape
MeterStyle=Item.Button.Shape:S
[Item2.Button.StringIcon]
Meter=String
Text=[\xe89e]
LeftMouseUpAction=["https://jaxcore.gumroad.com/"]
MeterStyle=Set.String:S | Item.Button.StringIcon:S

[Module0.Shape]
Meter=Shape
MeterStyle=Module.Shape:S
[Module0.Image]
Meter=Image
MeterStyle=Module.Image:S
[Module0.String]
Meter=String
MEterStyle=Set.String:S | Module.STring:S
[Module0.Button1.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S
[Module0.Button1.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S
[Module0.Button2.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S | Module.Button2.Shape:S
[Module0.Button2.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S | Module.Button2.STring:S

[Module1.Shape]
Meter=Shape
MeterStyle=Module.Shape:S
[Module1.Image]
Meter=Image
MeterStyle=Module.Image:S
[Module1.String]
Meter=String
MEterStyle=Set.String:S | Module.STring:S
[Module1.Button1.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S
[Module1.Button1.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S
[Module1.Button2.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S | Module.Button2.Shape:S
[Module1.Button2.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S | Module.Button2.STring:S


[Module2.Shape]
Meter=Shape
MeterStyle=Module.Shape:S
[Module2.Image]
Meter=Image
MeterStyle=Module.Image:S
[Module2.String]
Meter=String
MEterStyle=Set.String:S | Module.STring:S
[Module2.Button1.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S
[Module2.Button1.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S
[Module2.Button2.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S | Module.Button2.Shape:S
[Module2.Button2.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S | Module.Button2.STring:S


[Module3.Shape]
Meter=Shape
MeterStyle=Module.Shape:S
[Module3.Image]
Meter=Image
MeterStyle=Module.Image:S
[Module3.String]
Meter=String
MEterStyle=Set.String:S | Module.STring:S
[Module3.Button1.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S
[Module3.Button1.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S
[Module3.Button2.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S | Module.Button2.Shape:S
[Module3.Button2.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S | Module.Button2.STring:S


[Module4.Shape]
Meter=Shape
MeterStyle=Module.Shape:S
[Module4.Image]
Meter=Image
MeterStyle=Module.Image:S
[Module4.String]
Meter=String
MEterStyle=Set.String:S | Module.STring:S
[Module4.Button1.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S
[Module4.Button1.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S
[Module4.Button2.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S | Module.Button2.Shape:S
[Module4.Button2.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S | Module.Button2.STring:S


[Module5.Shape]
Meter=Shape
MeterStyle=Module.Shape:S
[Module5.Image]
Meter=Image
MeterStyle=Module.Image:S
[Module5.String]
Meter=String
MEterStyle=Set.String:S | Module.STring:S
[Module5.Button1.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S
[Module5.Button1.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S
[Module5.Button2.Shape]
Meter=Shape
MeterStyle=Module.Button1.Shape:S | Module.Button2.Shape:S
[Module5.Button2.String]
Meter=String
MEterStyle=Set.String:S | Module.Button1.STring:S | Module.Button2.STring:S

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R