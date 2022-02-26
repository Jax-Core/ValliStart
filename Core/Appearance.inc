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
[Divider05]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Start menu border size

MeterStyle=Set.String:S | Set.OptionName:S
[Divider06]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text=Start menu corner roundness

MeterStyle=Set.String:S | Set.OptionName:S
[Divider07]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
Text=Start menu corner rounding exception list#CRLF#(from top left to bottom right, set 1 to make corner right)

MeterStyle=Set.String:S | Set.OptionName:S
[Header08]
Meter=String
Text=Elements
MeterStyle=Set.String:S | Set.OptionCat:S
[Option09]
Meter=String
Text=Font face

MeterStyle=Set.String:S | Set.OptionName:S
[Divider10]
Meter=Shape
MeterStyle=Set.Div:S
[Option10]
Meter=String
Text=Element corner roundness

MeterStyle=Set.String:S | Set.OptionName:S
[Divider11]
Meter=Shape
MeterStyle=Set.Div:S
[Option11]
Meter=String
Text=Draw divider lines between modules

MeterStyle=Set.String:S | Set.OptionName:S
[Divider12]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Avatar icon path

MeterStyle=Set.String:S | Set.OptionName:S
[Header13]
Meter=String
Text=Background blending
MeterStyle=Set.String:S | Set.OptionCat:S
[Option14]
Meter=String
Text=Use an image as the background

MeterStyle=Set.String:S | Set.OptionName:S
[Divider15]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Background image path
FontColor=#Set.Text_Color#,(#ImageUnderlay# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S
[Divider16]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text=Backgroundd image opacity
FontColor=#Set.Text_Color#,(#ImageUnderlay# = 1 ? 255 : 150)
MeterStyle=Set.String:S | Set.OptionName:S
[Header17]
Meter=String
Text=Fill & Color
MeterStyle=Set.String:S | Set.OptionCat:S
[Option18]
Meter=String
Text=Blur type

MeterStyle=Set.String:S | Set.OptionName:S
[Divider19]
Meter=Shape
MeterStyle=Set.Div:S
[Option19]
Meter=String
Text=Blur rounding size

MeterStyle=Set.String:S | Set.OptionName:S
[Divider20]
Meter=Shape
MeterStyle=Set.Div:S
[Option20]
Meter=String
Text=Panel opacity

MeterStyle=Set.String:S | Set.OptionName:S
[Divider21]
Meter=Shape
MeterStyle=Set.Div:S
[Option21]
Meter=String
Text=Accent color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider22]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Node hover color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider23]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Node color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider24]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text=Background color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider25]
Meter=Shape
MeterStyle=Set.Div:S
[Option25]
Meter=String
Text=Divider color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider26]
Meter=Shape
MeterStyle=Set.Div:S
[Option26]
Meter=String
Text=Font color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider27]
Meter=Shape
MeterStyle=Set.Div:S
[Option27]
Meter=String
Text=Darker color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider28]
Meter=Shape
MeterStyle=Set.Div:S
[Option28]
Meter=String
Text=Box border color

MeterStyle=Set.String:S | Set.OptionName:S
[Divider29]
Meter=Shape
MeterStyle=Set.Div:S
[Option29]
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
[WinB]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|50


Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text=#WinB#

MeterStyle=Set.String:S | Set.Value:S
[WinR]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|100


Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value06]
Meter=String
Text=#WinR#

MeterStyle=Set.String:S | Set.Value:S
[RemoveRoundCorner]
Meter=Shape
MeterStyle=Set.Textbox:S



Y=([Option07:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#RemoveRoundCorner#

MeterStyle=Set.String:S | Set.Value:S
[Font]
Meter=Shape
MeterStyle=Set.Textbox:S



Y=([Option09:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value09]
Meter=String
Text=#Font#

MeterStyle=Set.String:S | Set.Value:S
[R]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|100


Y=([Option10:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value10]
Meter=String
Text=#R#

MeterStyle=Set.String:S | Set.Value:S
[Stroke]
Meter=Shape
MeterStyle=Set.Bool:S


Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Button12]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
Act=[!CommandMEasure Func "interactionBox([[#SKINSPATH##Skin.Name#\Core\InteractionBox\ValliAvatarIcon.inc]])"]

[Icon12]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])

MeterStyle=Set.String:S | Set.Value:S
[Value12]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=[&Func:trim('#AvatarPath#','^.*\','')]

MeterStyle=Set.String:S | Set.Value:S
[ImageUnderlay]
Meter=Shape
MeterStyle=Set.Bool:S


Y=([Option14:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Button15]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
Act=[!CommandMEasure Func "interactionBox([[#SKINSPATH##Skin.Name#\Core\InteractionBox\ValliImageUnderlay.inc]])"]
Hidden=(1-#ImageUnderlay#)
[Icon15]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
Hidden=(1-#ImageUnderlay#)
MeterStyle=Set.String:S | Set.Value:S
[Value15]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=[&Func:trim('#ImageUnderlayPath#','^.*\','')]
Hidden=(1-#ImageUnderlay#)
MeterStyle=Set.String:S | Set.Value:S
[ImageUnderlayAlpha]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|1|255
Hidden=(1-#ImageUnderlay#)

Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value16]
Meter=String
Text=#ImageUnderlayAlpha#
Hidden=(1-#ImageUnderlay#)
MeterStyle=Set.String:S | Set.Value:S
[Blur:]
Meter=Shape
0Act=[!WriteKeyValue Variables Blur "None" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Blur "Acrylic" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Blur "Blur" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Blur', 'Acrylic')]+[&Func:returnBool('Blur', 'Blur')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option18:Y]-#Set.P#+(-30/2+8)*[Set.S])

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
Y=([Option19:Y]-#Set.P#+(-30/2+8)*[Set.S])

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


Y=([Option20:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value20]
Meter=String
Text=#Alpha#

MeterStyle=Set.String:S | Set.Value:S
[Accent_Color]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])

[AccentNodeHover]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])

[AccentNode]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Pri_color]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option24:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Border]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option25:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Font_Color]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option26:Y]-#Set.P#+(-30/2+8)*[Set.S])

[Dark_Color]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option27:Y]-#Set.P#+(-30/2+8)*[Set.S])

[BoxBorder]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option28:Y]-#Set.P#+(-30/2+8)*[Set.S])

[BoxColor]
Meter=Shape
MeterStyle=Set.Color:S
LeftMouseUpAction=["#@#Addons\RainRGB4.exe" "VarName=#CURRENTSECTION#" "FileName=#Sec.SaveLocation#" "RefreshConfig=#CURRENTCONFIG# | #Skin.Name#\Main"]
Y=([Option29:Y]-#Set.P#+(-30/2+8)*[Set.S])




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
;[Start menu border size]
;Type=String
;Limit=Num|0|50
;Variable=WinB
;[Start menu corner roundness]
;Type=String
;Variable=WinR
;Limit=Num|0|100
;[Start menu corner rounding exception list#CRLF#(from top left to bottom right, set 1 to make corner right)]
;Type=String
;Variable=RemoveRoundCorner
;
;[Elements]
;Type=Header
;[Font face]
;Type=String
;Variable=Font
;[Element corner roundness]
;Type=String
;Variable=R
;Limit=Num|0|100
;[Draw divider lines between modules]
;Type=Bool
;Variable=Stroke
;[Avatar icon path]
;Type=Button
;Icon=e895
;String=[&Func:trim('#AvatarPath#','^.*\','')]
;Act=[!CommandMEasure Func "interactionBox([[#SKINSPATH##Skin.Name#\Core\InteractionBox\ValliAvatarIcon.inc]])"]
;
;[Background blending]
;Type=Header
;[Use an image as the background]
;Type=Bool
;Variable=ImageUnderlay
;[Background image path]
;Type=Button
;Icon=e895
;String=[&Func:trim('#ImageUnderlayPath#','^.*\','')]
;Act=[!CommandMEasure Func "interactionBox([[#SKINSPATH##Skin.Name#\Core\InteractionBox\ValliImageUnderlay.inc]])"]
;Hidden=!ImageUnderlay
;[Backgroundd image opacity]
;Type=String
;Limit=Num|1|255
;Variable=ImageUnderlayAlpha
;Hidden=!ImageUnderlay
;
;[Fill & Color]
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
;Variable=Accent_Color
;[Node hover color]
;Type=Color
;Variable=AccentNodeHover
;[Node color]
;Type=Color
;Variable=AccentNode
;[Background color]
;Type=Color
;Variable=Pri_Color
;[Divider color]
;Type=Color
;Variable=Border
;[Font color]
;Type=Color
;Variable=Font_Color
;[Darker color]
;Type=Color
;Variable=Dark_Color
;[Box border color]
;Type=Color
;Variable=BoxBorder
;[Box color]
;Type=Color
;Variable=BoxColor