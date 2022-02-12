[Variables]
[Header01]
Meter=String
Text=Dimensions
MeterStyle=Set.String:S | Set.OptionCat:S
[Option02]
Meter=String
Text=Skin scale

MeterStyle=Set.String:S | Set.OptionName:S
[Divider03]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Start menu Width

MeterStyle=Set.String:S | Set.OptionName:S
[Divider04]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Minium menu height

MeterStyle=Set.String:S | Set.OptionName:S
[Header05]
Meter=String
Text=Selections
MeterStyle=Set.String:S | Set.OptionCat:S
[Option06]
Meter=String
Text=Font face

MeterStyle=Set.String:S | Set.OptionName:S
[Divider07]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
Text=Corner roundness

MeterStyle=Set.String:S | Set.OptionName:S
[Divider08]
Meter=Shape
MeterStyle=Set.Div:S
[Option08]
Meter=String
Text=Draw divider lines between modules

MeterStyle=Set.String:S | Set.OptionName:S
[Divider09]
Meter=Shape
MeterStyle=Set.Div:S
[Option09]
Meter=String
Text=Show start orb icon

MeterStyle=Set.String:S | Set.OptionName:S
[Divider10]
Meter=Shape
MeterStyle=Set.Div:S
[Option10]
Meter=String
Text=Start orb icon image
FontColor=#Set.Text_Color#,(#StartIconBool# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S
[Divider11]
Meter=Shape
MeterStyle=Set.Div:S
[Option11]
Meter=String
Text=Show start text

MeterStyle=Set.String:S | Set.OptionName:S
[Divider12]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Start text
FontColor=#Set.Text_Color#,(#StartTextBool# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S
[Header13]
Meter=String
Text=Fill and coloring
MeterStyle=Set.String:S | Set.OptionCat:S
[Option14]
Meter=String
Text=Blur type

MeterStyle=Set.String:S | Set.OptionName:S
[Divider15]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Blur rounding size

MeterStyle=Set.String:S | Set.OptionName:S
[Divider16]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text=Panel opacity

MeterStyle=Set.String:S | Set.OptionName:S
[Divider17]
Meter=Shape
MeterStyle=Set.Div:S
[Option17]
Meter=String
Text=Accent color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider18]
Meter=Shape
MeterStyle=Set.Div:S
[Option18]
Meter=String
Text=Node hover color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider19]
Meter=Shape
MeterStyle=Set.Div:S
[Option19]
Meter=String
Text=Node color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider20]
Meter=Shape
MeterStyle=Set.Div:S
[Option20]
Meter=String
Text=Background color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider21]
Meter=Shape
MeterStyle=Set.Div:S
[Option21]
Meter=String
Text=Divider color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider22]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Font color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider23]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Darker color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider24]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text=Box border color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider25]
Meter=Shape
MeterStyle=Set.Div:S
[Option25]
Meter=String
Text=Box color

MeterStyle=Set.String:S | Set.OptionName:S
[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0.5|2


Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Scale#

MeterStyle=Set.String:S | Set.Value:S
[FixW]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|100|#SCREENAREAWIDTH#


Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#FixW#

MeterStyle=Set.String:S | Set.Value:S
[MinH]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|#SCREENAREAHEIGHT#


Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text=#MinH#

MeterStyle=Set.String:S | Set.Value:S
[Font]
Meter=Shape
MeterStyle=Set.Textbox:S



Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value06]
Meter=String
Text=#Font#

MeterStyle=Set.String:S | Set.Value:S
[R]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|100


Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#R#

MeterStyle=Set.String:S | Set.Value:S
[Stroke]
Meter=Shape
MeterStyle=Set.Bool:S


Y=([Option08:Y]-#Set.P#+(-20/2+8)*[Set.S])
[StartIconBool]
Meter=Shape
MeterStyle=Set.Bool:S


Y=([Option09:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Button10]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option10:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
Act=[!CommandMEasure Func "interactionBox([[#SKINSPATH##Skin.Name#\Core\InteractionBox\ValliOrb.inc]], '#IconName#')"]
Hidden=(1-#StartIconBool#)
[Icon10]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
Hidden=(1-#StartIconBool#)
MeterStyle=Set.String:S | Set.Value:S
[Value10]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=#IconName#
Hidden=(1-#StartIconBool#)
MeterStyle=Set.String:S | Set.Value:S
[StartTextBool]
Meter=Shape
MeterStyle=Set.Bool:S


Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])
[StartText]
Meter=Shape
MeterStyle=Set.Textbox:S

Hidden=(1-#StartTextBool#)

Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#StartText#
Hidden=(1-#StartTextBool#)
MeterStyle=Set.String:S | Set.Value:S
[Blur:]
Meter=Shape
0Act=[!WriteKeyValue Variables Blur "None" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Blur "Acrylic" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Blur "Blur" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Blur', 'Acrylic')]+[&Func:returnBool('Blur', 'Blur')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Blur:0]
Meter=String
Text=None
FontColor=[&Func:returnBool('Blur', 'None', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S

[Blur:1]
Meter=String
Text=Acrylic
FontColor=[&Func:returnBool('Blur', 'Acrylic', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S

[Blur:2]
Meter=String
Text=Standard
FontColor=[&Func:returnBool('Blur', 'Blur', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Hidden=

[BlurCorner:]
Meter=Shape
0Act=[!WriteKeyValue Variables BlurCorner "None" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables BlurCorner "RoundSmall" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables BlurCorner "Round" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('BlurCorner', 'RoundSmall')]+[&Func:returnBool('BlurCorner', 'Round')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])

[BlurCorner:0]
Meter=String
Text=None
FontColor=[&Func:returnBool('BlurCorner', 'None', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S

[BlurCorner:1]
Meter=String
Text=Small
FontColor=[&Func:returnBool('BlurCorner', 'RoundSmall', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S

[BlurCorner:2]
Meter=String
Text=Standard
FontColor=[&Func:returnBool('BlurCorner', 'Round', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S
Hidden=

[Alpha]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|255


Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value16]
Meter=String
Text=#Alpha#

MeterStyle=Set.String:S | Set.Value:S
[Accent]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option17:Y]-#Set.P#+(-30/2+8)*[Set.S])

[AccentNodeHover]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option18:Y]-#Set.P#+(-30/2+8)*[Set.S])

[AccentNode]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option19:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Color]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option20:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Border]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])

[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])

[DarkColor]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])

[BoxBorder]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option24:Y]-#Set.P#+(-30/2+8)*[Set.S])

[BoxColor]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option25:Y]-#Set.P#+(-30/2+8)*[Set.S])




;
;[Dimensions]
;Type=Header
;[Skin scale]
;Type=String
;Variable=Scale
;Limit=Num|0.5|2
;[Start menu Width]
;Type=String
;Variable=FixW
;Limit=Num|100|#SCREENAREAWIDTH#
;[Minium menu height]
;Type=String
;Variable=MinH
;Limit=Num|0|#SCREENAREAHEIGHT#
;
;[Selections]
;Type=Header
;[Font face]
;Type=String
;Variable=Font
;[Corner roundness]
;Type=String
;Variable=R
;Limit=Num|0|100
;[Draw divider lines between modules]
;Type=Bool
;Variable=Stroke
;[Show start orb icon]
;Type=Bool
;Variable=StartIconBool
;[Start orb icon image]
;Type=Button
;Icon=e895
;String=#IconName#
;Act=[!CommandMEasure Func "interactionBox([[#SKINSPATH##Skin.Name#\Core\InteractionBox\ValliOrb.inc]], '#IconName#')"]
;Hidden=!StartIconBool
;[Show start text]
;Type=Bool
;Variable=StartTextBool
;[Start text]
;Type=String
;Variable=StartText
;Hidden=!StartTextBool
;
;[Fill and coloring]
;Type=Header
;[Blur type]
;Type=Switch
;Variable=Blur
;Limit=3
;String=None|Acrylic|Standard
;StringSet=None|Acrylic|Blur
;[Blur rounding size]
;Type=Switch
;Variable=BlurCorner
;Limit=3
;String=None|Small|Standard
;StringSet=None|RoundSmall|Round
;[Panel opacity]
;Type=String
;Variable=Alpha
;Limit=Int|0|255
;[Accent color]
;Type=Color
;Variable=Accent
;[Node hover color]
;Type=Color
;Variable=AccentNodeHover
;[Node color]
;Type=Color
;Variable=AccentNode
;[Background color]
;Type=Color
;Variable=Color
;[Divider color]
;Type=Color
;Variable=Border
;[Font color]
;Type=Color
;Variable=FontColor
;[Darker color]
;Type=Color
;Variable=DarkColor
;[Box border color]
;Type=Color
;Variable=BoxBorder
;[Box color]
;Type=Color
;Variable=BoxColor