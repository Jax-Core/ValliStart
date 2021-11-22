[Variables]
@includeVars=#SKINSPATH##Skin.Name#\Main\Accessories\Unload\Vars.inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\Main\Accessories\Unload\Vars.inc

[HotkeysTitle]
Meter=String
Text=Activation & shortcuts
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
X=r
Text=Customize how to activate ValliStart
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Configure shortcuts
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3121238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Type to search when menu is active
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:238]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Start menu location
MeterStyle=Set.String:S | Set.OptionName:S
;================================================================================================================================================================================

[Time]
Meter=String
Text=Time & weather
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Time format: 24(H) 12(I)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:238]
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
Text=Weather location
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:23124125158]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Unit (Metric/Imperial)
MeterStyle=Set.String:S | Set.OptionName:S


;================================================================================================================================================================================

[S12313]
Meter=String
Text=Background modification
FontColor=#Set.Text_Color#,100
MeterStyle=Set.String:S | Set.OptionCat:S

[Option30]
Meter=String
Text=This option had been temporarily disabled along with the showing hidden taskbar feature to preserve performance. You can downgrade the version via the rollback button on the info page.
W=(#Set.W#-#Set.P#*3-#Set.L#)
ClipString=2
FontColor=#Set.Accent_color#
MeterStyle=Set.String:S | Set.OptionName:S
[Option31]
Meter=String
Text=Background blur
FontColor=#Set.Text_Color#,100
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option32]
Meter=String
Text=Background color
FontColor=#Set.Text_Color#,100
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
X=(5*[Set.S])R
Y=r
Text=Open
MeterStyle=Set.String:S | Set.Value:S

[Location:]
Meter=Shape
0Act=[!WriteKeyValue Variables Location "Custom" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Location "Center" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Location "Corner" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Location', 'Center')]+[&Func:returnBool('Location', 'Corner')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Location:0]
Meter=String
Text=Custom
FontColor=([&Func:returnBool('Location', 'Custom')] = 1 ? 0 : 255),([&Func:returnBool('Location', 'Custom')] = 1 ? 0 : 255),([&Func:returnBool('Location', 'Custom')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Location:1]
Meter=String
Text=Center
FontColor=([&Func:returnBool('Location', 'Center')] = 1 ? 0 : 255),([&Func:returnBool('Location', 'Center')] = 1 ? 0 : 255),([&Func:returnBool('Location', 'Center')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Location:2]
Meter=String
Text=Corner
FontColor=([&Func:returnBool('Location', 'Corner')] = 1 ? 0 : 255),([&Func:returnBool('Location', 'Corner')] = 1 ? 0 : 255),([&Func:returnBool('Location', 'Corner')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S


[TypeToSearch]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Button03]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
Act=[!WriteKeyvalue Variables page.page 3 "#SKINSPATH##Skin.Name#\Core\General.inc"][!Refresh]
[Value03]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S
[Value031]
Meter=String
X=(5*[Set.S])R
Y=r
Text=Open
MeterStyle=Set.String:S | Set.Value:S

[2412:]
Meter=Shape
Shape2=Rectangle ([&Func:returnBool('2412', 'H')] = 0 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0 |
0Act=[!WriteKeyValue Variables 2412 "I" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables 2412 "H" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[2412:0]
Meter=String
Text=12-Hour
FontColor=([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 0 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_0:S
[2412:1]
Meter=String
Text=24-hour
FontColor=([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255),([&Func:returnBool('2412', 'H')] = 1 ? 0 : 255)
LeftMouseUpAction=[&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Set.String:S | Set.PickOption_1:S
[ShowSec]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])

[WeatherLocation]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#WeatherLocation#
MeterStyle=Set.String:S | Set.Value:S

[WeatherUnits]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value14]
Meter=String
Text=#WeatherUnits#
MeterStyle=Set.String:S | Set.Value:S

; [Blur:]
; Meter=Shape
; 0Act=[!WriteKeyValue Variables Blur "None" "#Sec.SaveLocation2#"]
; 1Act=[!WriteKeyValue Variables Blur "Acrylic" "#Sec.SaveLocation2#"]
; 2Act=[!WriteKeyValue Variables Blur "Blur" "#Sec.SaveLocation2#"]
; MeterStyle=Set.Pick3:S
; Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Blur', 'Acrylic')]+[&Func:returnBool('Blur', 'Blur')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
; Y=([Option31:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Blur:0]
; Meter=String
; Text=None
; FontColor=([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255)
; MeterStyle=Set.String:S | Set.PickOption3_0:S
; [Blur:1]
; Meter=String
; Text=Acrylic
; FontColor=([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255)
; MeterStyle=Set.String:S | Set.PickOption3_1:S
; [Blur:2]
; Meter=String
; Text=Standard
; FontColor=([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255)
; MeterStyle=Set.String:S | Set.PickOption3_2:S
; [Solid]
; Meter=Shape
; MeterStyle=Set.ColorPacity:S
; LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#Color" "FileName=#Sec.SaveLocation2#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
; RightMOuseUpAction=[!SetVariable Editing "#CURRENTSECTION#Opacity"][!SetOption Input2:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input2:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input2:M "ExecuteBatch 1"]
; Y=([Option32:Y]-#Set.P#+(-30/2+8)*[Set.S])
; Type=Num|1|255
; [Value32]
; Meter=String
; Text=#SolidOpacity#
; MeterStyle=Set.String:S | Set.Pacity:S

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