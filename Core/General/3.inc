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
Hidden=1
LeftMouseUpAction=[!SetVariable Editing "#CURRENTSECTION#"][!UpdateMEasure Choose:M][!CommandMeasure Choose:M "ChooseFile 1"]

[Sec.Delete:S]
OverColor=255,0,0,200
LeaveColor=255,0,0,100
Group=ActionButtonShape | Actions
LeftMouseUpAction=[!CommandMeasure Script:M "Remove(0, '#CURRENTSECTION#')"]

[Sec.EditText:S]
Hidden=1
[Sec.EditDiv:S]
Hidden=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[HotkeysTitle]
Meter=String
Text=Main Shortcuts
MeterStyle=Set.String:S | Set.OptionCat:S

[Edit1]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:1]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit2]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:2]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit3]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:3]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit4]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:4]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit5]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:5]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit6]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:6]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit7]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:7]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit8]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:8]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit9]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:9]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit10]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:10]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit11]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:11]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Edit12]
Meter=String
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S
[Set.Div:12]
Meter=Shape
MeterStyle=Set.Div:S | Sec.EditDiv:S
[Option6]
Meter=String
Text=
MeterStyle=Set.String:S | Set.OptionName:S | Sec.EditText:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[EditButton1]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit1:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon1]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton2]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit2:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon2]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton3]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit3:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon3]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton4]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit4:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon4]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton5]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit5:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon5]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton6]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit6:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon6]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton7]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit7:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon7]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton8]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit8:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon8]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton9]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit9:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon9]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton10]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit10:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon10]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton11]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon11]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S

[EditButton12]
Meter=Shape
MeterStyle=Set.RectButton:S | Sec.Edit:S
Y=([Edit12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[EditIcon12]
Meter=String
FontFace=Segoe MDL2 Assets
X=(-15*[Set.S])R
Y=(-15*[Set.S])R
StringAlign=CenterCenter
Text=[\xE70F]
Group=ActionButton | Actions
MeterStyle=Set.String:S | Set.Value:S | Sec.EditText:S



[RemoveButton]
Meter=Shape
MeterStyle=Set.Button:S
OverColor=255,0,50,150
LeaveColor=255,0,50,100
Y=([Option6:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Script:M "Remove(1)"]
[RemoveButtonText]
Meter=String
Text=Remove...
StringAlign=CenterCenter
X=(150*[Set.S]/2)r
MeterStyle=Set.String:S | Set.Value:S

[ReturnButton]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Header:Y]-#Set.P#+(-20/2+8)*[Set.S])
OverColor=#Set.Accent_color#,150
LeaveColor=#Set.Accent_color#,50
Act=[!WriteKeyvalue Variables page.page 1 "#SKINSPATH##Skin.Name#\Core\General.inc"][!Refresh]
[ReturnTextIcon]
Meter=String
Text=[\xe31b]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S
[ReturnText]
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