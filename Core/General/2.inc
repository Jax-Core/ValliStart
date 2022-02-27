[Variables]
@includeWinBlockVars=#SKINSPATH##Skin.Name#\WinBlock\Vars\Winblock.inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\WinBlock\Vars\Winblock.inc
WinBlock=0

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Auto_Refresh:M]
OnUpdateAction=[!Refresh "#Skin.Name#\Main"][!Refresh "ValliStart\WinBlock"]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[HotkeysTitle]
Meter=String
Text=Activation mode
MeterStyle=Set.String:S | Set.OptionCat:S

[HeaderImage]
Meter=Image
X=r
Y=(20*[Set.S])R
W=([ContentContainer:W]-30*[Set.S])
H=([ContentContainer:W]/(13/3))
ImageName=#SKINSPATH##Skin.Name#\Core\General\Resource#ReplaceWin#.png
DynamicVariables=1
ImageAlpha=255
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer
[Option01]
Meter=String
Y=(40*[Set.S])R
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
[Option03]
Meter=String
Text=Override the start button#CRLF#- This button is just an overlay, it does not follow the taskbar#CRLF#- To edit the position of the blocker, turn on edit mode below#CRLF#- To use the blocker after editing, turn on functional mode
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#))
MeterStyle=Set.String:S | Set.OptionName:S

[BlockerTitle]
Meter=String
Text=WinBlock settings
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Win block behavior
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:81231212]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Win block width
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Win block height
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:8]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Win block hovered color
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
Text=#KeyInString#
Hidden=#ReplaceWin#
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
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])
Hidden=(1-#ReplaceWin#)
[WinBlock0]
Leftmouseupaction=[!ActivateConfig "#Skin.Name#\WinBlock"][!Refresh "#Skin.Name#\Main"][!Refresh]
[WinBlock1]
Leftmouseupaction=[!DeactivateConfig "#Skin.Name#\WinBlock"][!Refresh "#Skin.Name#\Main"][!Refresh]

[Mode:]
Meter=Shape
SecVar=Mode
MeterStyle=Set.Pick:S
Shape2=Rectangle ([#[&Func:GroupVar('#CURRENTSECTION#')]] = 1 ? 0 : (150*[Set.S])),0,(150*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color 255,255,255 | StrokeWidth 0 |
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
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
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#WinBlock#)
SaveLocation=#Sec.SaveLocation2#
[Value12]
Meter=String
Text=#W# px
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#WinBlock#)

[H]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#WinBlock#)
SaveLocation=#Sec.SaveLocation2#
[Value13]
Meter=String
Text=#H# px
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#WinBlock#)

[Over]
Meter=Shape
MeterStyle=Set.ColorPacity:S
SaveLocation=#Sec.SaveLocation2#
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
Hidden=(1-#WinBlock#)
[Value14]
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