[Variables]
WinBlock=0
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\@Resources\Shortcuts.inc


[CheckForDataFolder]
MEasure=Plugin
Plugin=PowershellRM
DynamicVariables=1
OnUpdateAction=[!Delay 20][!CommandMeasure CheckForDataFolder "Check-Data"]
ScriptFile=#@#Powershell\CheckData.ps1

[Choose:M]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
GetTarget=0
AllowNonstorageFolder=1
CopyLink=1
GetIcon=1
IconCache=#SKINSPATH#..\CoreData\ValliStart\IconCache\
IconSize=3
ReturnValue=WholePath
FileInitialDirectory=
ImageInitialDirectory=#CurrentPath#IconCache\
DynamicVariables=1
Command1=[!CommandMeasure Script:M "Edit([[$Name$]], [[$Path$]], [[$Ext$]], '#Editing#')"]

[Script:M]
Measure=Script
ScriptFile="#SKINSPATH##Skin.name#\Core\Gen.lua"

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Sec.Edit:S]
OverColor=0,255,50,200
LeaveColor=0,255,50,100
Group=ActionButtonShape | Actions
LeftMouseUpAction=[!SetVariable Editing "#CURRENTSECTION#"][!UpdateMEasure Choose:M][!CommandMeasure Choose:M "ChooseFile 1"]

[Sec.Delete:S]
OverColor=255,0,0,200
LeaveColor=255,0,0,100
Group=ActionButtonShape | Actions
LeftMouseUpAction=[!CommandMeasure Script:M "Remove(0, '#CURRENTSECTION#')"]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[HotkeysTitle]
Meter=String
Text=Main Shortcuts
MeterStyle=Set.String:S | Set.OptionCat:S

[Option1]
Meter=String
Text=#M1#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1]
Meter=Shape
MeterStyle=Set.Div:S
[Option2]
Meter=String
Text=#M2#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:2]
Meter=Shape
MeterStyle=Set.Div:S
[Option3]
Meter=String
Text=#M3#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:3]
Meter=Shape
MeterStyle=Set.Div:S
[Option4]
Meter=String
Text=#M4#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:4]
Meter=Shape
MeterStyle=Set.Div:S
[Option5]
Meter=String
Text=#M5#
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:5]
Meter=Shape
MeterStyle=Set.Div:S
[Option6]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionName:S

[Title2]
Meter=String
Text=Directory tray module shortcuts
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text=Coming soon...
MeterStyle=Set.String:S | Set.OptionName:S

[EditButton1]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Option1:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon1]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S
[EditButton2]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Option2:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon2]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S
[EditButton3]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Option3:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon3]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S
[EditButton4]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Option4:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon4]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S
[EditButton5]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Option5:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon5]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S
[Button6]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=255,0,50,150
LeaveColor=255,0,50,100
Y=([Option6:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Remove(1)"]
[Value6]
Meter=String
Text=Remove...
StringAlign=CenterCenter
X=(150*[Set.S]/2)r
MeterStyle=Set.String:S | Set.Value:S

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


; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R

@includeAdditionalVars=#SKINSPATH##Skin.Name#\@Resources\Shortcuts.inc