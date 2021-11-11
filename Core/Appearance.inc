
;================================================================================================================================================================================

[Colsdadsor]
Meter=String
Text=General
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Font Face
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:sdsds]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Skin scale
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:s121241424143s]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Corner roundness
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:sdsdss]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Slide animations
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:sdsds123s]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Start location
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:s123s]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text=Draw strokes
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S190322131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option07]
Meter=String
Text=Orb image
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19w2s0328]
Meter=Shape
MeterStyle=Set.Div:S
[Option08]
Meter=String
Text=Start text
MeterStyle=Set.String:S | Set.OptionName:S


; ;================================================================================================================================================================================

[Padding]
Meter=String
Text=Media
MeterStyle=Set.String:S | Set.OptionCat:S

[Option10]
Meter=String
Text=Retrive and display song thumbnail
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Anim]
Meter=String
Text=Start menu appearance
MeterStyle=Set.String:S | Set.OptionCat:S

[Option20]
Meter=String
Text=Blur type
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1381]
Meter=Shape
MeterStyle=Set.Div:S
[Option21]
Meter=String
Text=Panel opacity
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1382]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Accent Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1383]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Background Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1384]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text=Border Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1385]
Meter=Shape
MeterStyle=Set.Div:S
[Option25]
Meter=String
Text=Font Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1386]
Meter=Shape
MeterStyle=Set.Div:S
[Option26]
Meter=String
Text=Dark Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1387]
Meter=Shape
MeterStyle=Set.Div:S
[Option27]
Meter=String
Text=Box border Color
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1388]
Meter=Shape
MeterStyle=Set.Div:S
[Option28]
Meter=String
Text=Box Color
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Font]
Meter=Shape
MeterStyle=Set.FontBox:S
Type=Txt
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Font#
MeterStyle=Set.String:S | Set.Value:S

[Scale]
Meter=Shape
MeterStyle=Set.TextBox:S
Type=Num|0.5|2
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[Edge]
Meter=Shape
MeterStyle=Set.TextBox:S
Type=Num|0|30
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text=#Edge#
MeterStyle=Set.String:S | Set.Value:S

[Animated]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option04:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Location:]
Meter=Shape
0Act=[!WriteKeyValue Variables Location "Bottom" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Location "Center" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Location "Corner" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Location', 'Center')]+[&Func:returnBool('Location', 'Corner')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Location:0]
Meter=String
Text=Bottom
FontColor=([&Func:returnBool('Location', 'Bottom')] = 1 ? 0 : 255),([&Func:returnBool('Location', 'Bottom')] = 1 ? 0 : 255),([&Func:returnBool('Location', 'Bottom')] = 1 ? 0 : 255)
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

[Stroke]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option06:Y]-#Set.P#+(-20/2+8)*[Set.S])



[Button07]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!CommandMEasure Func "startBox('ValliOrb', '#IconName#')"]
Y=([Option07:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value07]
Meter=String
Text=#IconName#
MeterStyle=Set.String:S | Set.Value:S

[StartText]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option08:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value08]
Meter=String
Text=#StartText#
MeterStyle=Set.String:S | Set.Value:S

[FetchImage]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option10:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Blur:]
Meter=Shape
0Act=[!WriteKeyValue Variables Blur "None" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Blur "Acrylic" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Blur "Blur" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Blur', 'Acrylic')]+[&Func:returnBool('Blur', 'Blur')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option20:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Blur:0]
Meter=String
Text=None
FontColor=([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'None')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Blur:1]
Meter=String
Text=Acrylic
FontColor=([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Acrylic')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Blur:2]
Meter=String
Text=Standard
FontColor=([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255),([&Func:returnBool('Blur', 'Blur')] = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption3_2:S

[Alpha]
Meter=Shape
MeterStyle=Set.TextBox:S
Type=Int|0|255
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value21]
Meter=String
Text=#Alpha#
MeterStyle=Set.String:S | Set.value:S
[Accent]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Color]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Border]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option24:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Fontcolor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option25:Y]-#Set.P#+(-30/2+8)*[Set.S])
[DarkColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option26:Y]-#Set.P#+(-30/2+8)*[Set.S])
[BoxBorder]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option27:Y]-#Set.P#+(-30/2+8)*[Set.S])
[BoxColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option28:Y]-#Set.P#+(-30/2+8)*[Set.S])