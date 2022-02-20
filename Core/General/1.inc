[Variables]
@includeVars=#SKINSPATH##Skin.Name#\Main\Accessories\Unload\Vars.inc
@includeWeatherVars=#SKINSPATH##Skin.Name#\Main\Modules\Vars\Weather.inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\Main\Accessories\Unload\Vars.inc

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Sec.DirButton:S]
X=((26+5)*[Set.S])r
Y=r
Shape=Rectangle 0,0,26,26,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Shape2=Path Arrow | StrokeWidth (2*[Set.S]) | StrokeStartCap Round | StrokeEndCap Round | Fill Color 0,0,0,1 | Stroke Color #Set.Text_Color# | Scale [Set.S],[Set.S],0,0 | Extend Rotation
Arrow=8,6 | LineTo 18,12 | LineTo 8,18
OverColor=[&Func:returnBool('AniDir', '#CURRENTSECTION#', '#Set.Accent_Color#', '#Set.Text_Color#')],200
LeaveColor=[&Func:returnBool('AniDir', '#CURRENTSECTION#', '#Set.Accent_Color#', '#Set.Text_Color#')],150
LeftMouseUpAction=[!WriteKeyValue Variables AniDir "#CURRENTSECTION#" #Sec.SaveLocation#][!UpdateMeasure Auto_Refresh:M][!Refresh]
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
DynamicVariables=1
Hidden=(#Animated# = 1 ? 0 : 1)

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[HotkeysTitle]
Meter=String
Text=Activation
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
X=r
Text=Customize how to activate ValliStart
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3121238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Type to search when menu is active
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Time]
Meter=String
Text=Time format
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Time format
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2238]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Show seconds
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:23123]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Custom format
FontColor=#Set.Text_Color#,(105+150*#CustomFormat#)
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[HotkeysTitle3]
Meter=String
Text=Animation
MeterStyle=Set.String:S | Set.OptionCat:S
[Option31]
Meter=String
Text=Slide animations
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S132]
Meter=Shape
MeterStyle=Set.Div:S
[Option32]
Meter=String
Text=Animation easing type
FontColor=#Set.Text_Color#,(#Animated# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1342]
Meter=Shape
MeterStyle=Set.Div:S
[Option33]
Meter=String
Text=Animation direction
FontColor=#Set.Text_Color#,(#Animated# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S21342]
Meter=Shape
MeterStyle=Set.Div:S
[Option34]
Meter=String
Text=Animation steps
FontColor=#Set.Text_Color#,(#Animated# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[S12313]
Meter=String
Text=Background modification
MeterStyle=Set.String:S | Set.OptionCat:S

[Option40]
Meter=String
Text=Modify launched background
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:8]
Meter=Shape
MeterStyle=Set.Div:S
[Option41]
Meter=String
Text=Background blur
FontColor=#Set.Text_Color#,(#BackgroundMod# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option42]
Meter=String
Text=Background color
FontColor=#Set.Text_Color#,(#BackgroundMod# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
Act=[!WriteKeyvalue Variables page.page 2 "#SKINSPATH##Skin.Name#\Core\General.inc"][!Refresh]
[Value01]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S
[Value02]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Open
MeterStyle=Set.String:S | Set.Value:S


[TypeToSearch]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[CustomFormat:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('CustomFormat', '1')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables CustomFormat "0" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables CustomFormat "1" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[CustomFormat:0]
Meter=String
Text=Time
FontColor=[&Func:returnBool('CustomFormat', '1', '#Set.Text_Color#', '#Set.Pri_color#')]
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[CustomFormat:1]
Meter=String
Text=Custom
FontColor=[&Func:returnBool('CustomFormat', '1', '#Set.Pri_color#', '#Set.Text_Color#')]
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S

[ShowSec]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])

[CustomTimeFormat]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#CustomFOrmat#)
[Value13]
Meter=String
Text=#CustomTimeFormat#
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#CustomFOrmat#)

[Animated]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option31:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Easetype]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option32:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startSide('Ease')"]
Hidden=(#Animated# = 1 ? 0 : 1)
[Value32]
Meter=String
Text=#Easetype#
MeterStyle=Set.String:S | Set.Value:S
Hidden=(#Animated# = 1 ? 0 : 1)
[Left]
Meter=Shape
X=(#Set.W#-#Set.L#-#Set.P#*2-((26*4+5*3)*[Set.S]))
Y=([Option33:Y]-#Set.P#+(-26/2+8)*[Set.S])
MeterStyle=Sec.DirButton:S
[Right]
Meter=Shape
Rotation=Rotate 180
MeterStyle=Sec.DirButton:S
[Top]
Meter=Shape
Rotation=Rotate 90
MeterStyle=Sec.DirButton:S
[Bottom]
Meter=Shape
Rotation=Rotate 270
MeterStyle=Sec.DirButton:S
[AniSteps]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|10|40
Y=([Option34:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(#Animated# = 1 ? 0 : 1)
[Value34]
Meter=String
Text=#AniSteps#
MeterStyle=Set.String:S | Set.Value:S
Hidden=(#Animated# = 1 ? 0 : 1)

[BackgroundMod]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option40:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Blur:]
Meter=Shape
0Act=[!WriteKeyValue Variables Blur "None" "#Sec.SaveLocation2#"]
1Act=[!WriteKeyValue Variables Blur "Acrylic" "#Sec.SaveLocation2#"]
2Act=[!WriteKeyValue Variables Blur "Blur" "#Sec.SaveLocation2#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Blur', 'Acrylic')]+[&Func:returnBool('Blur', 'Blur')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option41:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#BackgroundMod#)
[Blur:0]
Meter=String
Text=None
FontColor=[&Func:returnBool('Blur', 'None', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S
Hidden=(1-#BackgroundMod#)
[Blur:1]
Meter=String
Text=Acrylic
FontColor=[&Func:returnBool('Blur', 'Acrylic', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S
Hidden=(1-#BackgroundMod#)
[Blur:2]
Meter=String
Text=Standard
FontColor=[&Func:returnBool('Blur', 'Blur', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Hidden=(1-#BackgroundMod#)
[Solid]
Meter=Shape
MeterStyle=Set.ColorPacity:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#Color" "FileName=#Sec.SaveLocation2#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
SaveLocation=#Sec.SaveLocation2#
Y=([Option42:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
Hidden=(1-#BackgroundMod#)
[Value41]
Meter=String
Text=#SolidOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
Hidden=(1-#BackgroundMod#)

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[Input2:M]
Measure=Plugin
Plugin=InputText
SolidColor=#Set.Pri_Color#
FontColor=#Set.Text_Color#
FontFace=Poppins
FontSize=(10*[Set.S])
StringAlign=LeftCenter
W=((150-10)*[Set.S])
H=((30-10)*[Set.S])
DynamicVariables=1
DefaultValue="[##Editing#]"
Command1=[!WriteKeyValue Variables "#Editing#" """$UserInput$""" "#Sec.SaveLocation2#"][!Refresh]

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R