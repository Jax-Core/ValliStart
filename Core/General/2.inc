[Variables]
WinBlock=0


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
Text=Override the start button#CRLF#- You can edit the button's location by turning on edit mode below#CRLF#- Hitbox will not sync with taskbar if it's set to autohide, though it still works.
FontColor=#Set.Text_Color#,(255-150*(1-#ReplaceWin#))
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:81231212]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Start button blocker mode
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
FontColor=(#ReplaceWin# = 0 ? 0 : 255),(#ReplaceWin# = 0 ? 0 : 255),(#ReplaceWin# = 0 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_0:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 0 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!Refresh "#Skin.Name#\Main"]
[ReplaceWin:1]
Meter=String
Text=Replace Start
FontColor=(#ReplaceWin# = 1 ? 0 : 255),(#ReplaceWin# = 1 ? 0 : 255),(#ReplaceWin# = 1 ? 0 : 255)
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
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Mode:1]
Meter=String
Text=Functional
FontColor=(#Mode# = 1 ? 0 : 255),(#Mode# = 1 ? 0 : 255),(#Mode# = 1 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_0:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 1 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '0Act')][!Refresh][!Refresh "#Skin.Name#\WinBlock"]
[Mode:2]
Meter=String
Text=Edit
FontColor=(#Mode# = 2 ? 0 : 255),(#Mode# = 2 ? 0 : 255),(#Mode# = 2 ? 0 : 255)
MeterStyle=Set.String:S | Set.PickOption_1:S
LeftMouseUpAction=[!WriteKeyValue Variables [&Func:GroupVar('#CURRENTSECTION#')] 2 "#Sec.SaveLocation#"][&Func:GroupVar('#CURRENTSECTION#', '1Act')][!Refresh][!Refresh "#Skin.Name#\WinBlock"]


[Button10]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Header:Y]-#Set.P#+(-20/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
Act=[!WriteKeyvalue Variables page.page 1 "#SKINSPATH##Skin.Name#\Core\General.inc"][!Refresh]
[Value10]
Meter=String
Text=[\xe31b]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S
[Value101]
Meter=String
Text=Return
X=(5*[Set.S])R
Y=r
MeterStyle=Set.String:S | Set.Value:S

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini


; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R