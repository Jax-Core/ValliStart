[Choose:M]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
GetTarget=0
AllowNonstorageFolder=1
GetIcon=0
ReturnValue=WholePath
FileInitialDirectory=
ImageInitialDirectory=#CurrentPath#IconCache\
DynamicVariables=1
Command1=[!WriteKeyvalue Variables Sound0 "$Path$" "#Sec.SaveLocatioN#"][!Refresh]
Command2=[!WriteKeyvalue Variables Sound1 "$Path$" "#Sec.SaveLocatioN#"][!Refresh]


[HotkeysTitle]
Meter=String
Text=Hotkeys
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
X=r
Text=Override the Start Menu (uses Win key as hotkey)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Activation Hotkey
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:8]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Type to search when menu is active
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

[S]
Meter=String
Text=Configuration
MeterStyle=Set.String:S | Set.OptionCat:S

[Option21]
Meter=String
Text=Pinned shortcuts directory
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S190322131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Orb image
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19w2s0328]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Start text
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Sound]
Meter=String
Text=Sound
MeterStyle=Set.String:S | Set.OptionCat:S

[Option31]
Meter=String
Text=Start sound
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238]
Meter=Shape
MeterStyle=Set.Div:S
[Option32]
Meter=String
Text=Close sound
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3123812342131]
Meter=Shape
MeterStyle=Set.Div:S
[Option33]
Meter=String
Text=Remove sounds
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================


[ReplaceWin]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option01:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Button02]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startSide('Hotkey')"]
[Value02]
Meter=String
Text=#KeyInString#
MeterStyle=Set.String:S | Set.Value:S

[TypeToSearch]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])


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
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#WeatherLocation#
MeterStyle=Set.String:S | Set.Value:S

[WeatherUnits]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value14]
Meter=String
Text=#WeatherUnits#
MeterStyle=Set.String:S | Set.Value:S

[Button21]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!CommandMeasure CheckForDataFolder "Check-Data"]["#SKINSPATH#..\CoreData\ValliStart"]
Y=([Option21:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value21]
Meter=String
Text=Open
MeterStyle=Set.String:S | Set.Value:S
[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\CheckData.ps1

[Button22]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!CommandMEasure Func "startBox('ValliOrb', '#IconName#')"]
Y=([Option22:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value22]
Meter=String
Text=#IconName#
MeterStyle=Set.String:S | Set.Value:S

[StartText]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value23]
Meter=String
Text=#StartText#
MeterStyle=Set.String:S | Set.Value:S

[Sound0]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,60,250,150
LeaveColor=0,60,250,50
Y=([Option31:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Choose:M "ChooseFile 1"]
[Value31]
Meter=String
Text=Select
MeterStyle=Set.String:S | Set.Value:S

[Sound1]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=0,60,250,150
LeaveColor=0,60,250,50
Y=([Option32:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Choose:M "ChooseFile 2"]
[Value32]
Meter=String
Text=Select
MeterStyle=Set.String:S | Set.Value:S

[Remove]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option33:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=255,0,0,150
LeaveColor=255,0,0,50
Act=[!WriteKeyvalue Variables Sound0 "" "#Sec.SaveLocatioN#"][!WriteKeyvalue Variables Sound1 "" "#Sec.SaveLocatioN#"][!Refresh]
[Value33]
Meter=String
Text=Remove
MeterStyle=Set.String:S | Set.Value:S


@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini