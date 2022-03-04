[Variables]
@includeWinBlockVars=#SKINSPATH##Skin.Name#\WinBlock\Vars\Winblock.inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\WinBlock\Vars\Winblock.inc
WinBlock=0

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Activationps1]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#SKINSPATh##Skin.name#\Core\Activation.ps1

[Auto_Refresh:M]
OnUpdateAction=[!Refresh "#Skin.Name#\Main"][!Refresh "ValliStart\WinBlock"]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[HotkeysTitle]
Meter=String
Text=Activation mode
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=How should ValliStart behave?
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Activation Hotkey
FontColor=#Set.Text_Color#,(255-150*#ReplaceWin#)
MeterStyle=Set.String:S | Set.OptionName:S

[BlockerTitle]
Meter=String
Text=On screen start button
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#))
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text=Override the start button
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#))
MeterStyle=Set.String:S | Set.OptionName:S
[Div:dbe71b]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Create pseudo start button
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#))
MeterStyle=Set.String:S | Set.OptionName:S
[Div:12bb3d]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Pseudo start orb name
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#))
MeterStyle=Set.String:S | Set.OptionName:S
[Div:385472]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Pseudo start orb directory to put the orb images
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#))
MeterStyle=Set.String:S | Set.OptionName:S
[Div:72af54]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text=Guide on how to remove & replace the start button
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#))
MeterStyle=Set.String:S | Set.OptionName:S

[Blocker2Title]
Meter=String
Text=Legacy win block style
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#*#WinBlock#))
MeterStyle=Set.String:S | Set.OptionCat:S
[Option20]
Meter=String
Text=Display WinBlock element (legacy)
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#*#WinBlock#))
MeterStyle=Set.String:S | Set.OptionName:S
[Div:259c88]
Meter=Shape
MeterStyle=Set.Div:S
[Option21]
Meter=String
Text=Win block behavior
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#*#WinBlock#))
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:81231212]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Win block width
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#*#WinBlock#))
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text=Win block height
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#*#WinBlock#))
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:8]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text=Win block hovered color
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#*#WinBlock#))
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;
[ReplaceWin:]
Meter=Shape
SecVar=ReplaceWin
MeterStyle=Set.Pick:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[ReplaceWin:0]
Meter=String
Text=Separate module
FontColor=[&Func:returnBool('ReplaceWin', '0', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption_0:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 0 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!Refresh "#Skin.Name#\Main"]
[ReplaceWin:1]
Meter=String
Text=Replace Start
FontColor=[&Func:returnBool('ReplaceWin', '1', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption_1:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 1 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!Refresh "#Skin.Name#\Main"]

[Button02]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startSide('Hotkey')"]
Hidden=#ReplaceWin#
[Value02]
Meter=String
Text=[&Func:returnBool('ReplaceWin', '1', 'Win', '#KeyInString#')]
FontColor=[&Func:returnBool('ReplaceWin', '1', '#set.Subtext_color#', '#Set.text_Color#')]
MeterStyle=Set.String:S | Set.Value:S

[ActiveChecker2]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#Skin.Name#\WinBlock
IfCondition=ActiveChecker2 = 1
Disabled=(1-#ReplaceWin#)
IfTrueAction=[!SetVariable WinBlock 1][!UpdateMeter WinBlock][!Redraw]

[WinBlock]
Meter=Shape
MeterStyle=Set.Bool:S | WinBlock#WinBlock#
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])
Hidden=(1-#ReplaceWin#)
[WinBlock0]
Leftmouseupaction=[!ActivateConfig "#Skin.Name#\WinBlock"][!Refresh "#Skin.Name#\Main"][!Refresh]
[WinBlock1]
Leftmouseupaction=[!DeactivateConfig "#Skin.Name#\WinBlock"][!Refresh "#Skin.Name#\Main"][!Refresh]

[Button12]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
LeftMouseUpAction=[!CommandMeasure Activationps1 "CoreData"]["#SKINSPATH#..\CoreData\Vallistart\"]
Hidden=(1-#ReplaceWin#)
[Icon12]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#ReplaceWin#)
[Value12]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Create
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#ReplaceWin#)

[OrbImageName]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#ReplaceWin#)
SaveLocation=#Sec.SaveLocation2#
[Value13]
Meter=String
Text=#OrbImageName#
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#ReplaceWin#)

[Button14]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
LeaveColor=#Set.Sec_Color#
LeftMouseUpAction=["#SKINSPATH##Skin.Name#\@Resources\Images\StartOrbs\"]
Hidden=(1-#ReplaceWin#)
[Icon14]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#ReplaceWin#)
[Value14]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Open
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#ReplaceWin#)

[Button15]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
OverColor=#Set.Positive_color#,150
LeaveColor=#Set.Positive_color#,50
LeftMouseUpAction=["https://github.com/Jax-Core/ValliStart/blob/main/README.md#replacing-the-native-windows-button-and-key"]
Hidden=(1-#ReplaceWin#)
[Icon15]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#ReplaceWin#)
[Value15]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Github
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#ReplaceWin#)

[WinblockDisplay]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option20:Y]-#Set.P#+(-20/2+8)*[Set.S])
Hidden=(1-#WinBlock#)
SaveLocation=#Sec.SaveLocation2#

[Mode:]
Meter=Shape
SecVar=Mode
MeterStyle=Set.Pick:S
Shape2=Rectangle ([#[&Func:GroupVar('#CURRENTSECTION#')]] = 1 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color 255,255,255 | StrokeWidth 0 |
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#WinBlock#)
[Mode:1]
Meter=String
Text=Functional
FontColor=[&Func:returnBool('Mode', '1', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption_0:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 1 "#Sec.SaveLocation2#"][&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!Refresh "#Skin.Name#\WinBlock"]
Hidden=(1-#WinBlock#)
[Mode:2]
Meter=String
Text=Edit
FontColor=[&Func:returnBool('Mode', '2', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption_1:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 2 "#Sec.SaveLocation2#"][&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!Refresh "#Skin.Name#\WinBlock"]
Hidden=(1-#WinBlock#)

[W]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#WinBlock#)
SaveLocation=#Sec.SaveLocation2#
[Value22]
Meter=String
Text=#W# px
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#WinBlock#)

[H]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#WinBlock#)
SaveLocation=#Sec.SaveLocation2#
[Value23]
Meter=String
Text=#H# px
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#WinBlock#)

[Over]
Meter=Shape
MeterStyle=Set.ColorPacity:S
SaveLocation=#Sec.SaveLocation2#
Y=([Option24:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
Hidden=(1-#WinBlock#)
[Value24]
Meter=String
Text=#OverOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
Hidden=(1-#WinBlock#)

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini


; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R