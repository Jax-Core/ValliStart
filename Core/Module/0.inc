

[Cat]
Meter=String
X=r
Text=Customize what to show under pinned shortcuts.
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
X=r
Text=Select a slot to choose between modules
MeterStyle=Set.String:S | Set.OptionName:S
[Option02]
Meter=String
X=r
Text=Click if you don't have music module selected
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:31238]
Meter=Shape
MeterStyle=Set.Div:S
; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Select:S]
X=r
Y=(20*[Set.S])R
W=([ContentContainer:W]-#Set.P#)
H=([ContentContainer:W]/4)
ImageName=#SKINSPATH##Skin.Name#\Core\Module\[##CURRENTSECTIOn#].png
DynamicVariables=1
ImageAlpha=200
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha "255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha "200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!WriteKeyvalue Variables page.page 1 "#SKINSPATH##Skin.Name#\Core\Modules.inc"][!WriteKeyvalue Variables page.editing #CURRENTSECTION# "#SKINSPATH##Skin.Name#\Core\Modules.inc"][!Refresh]
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[Module1]
Meter=Image
X=r
Y=(30*[Set.S])R
MeterStyle=Select:S

[Module2]
Meter=Image
MeterStyle=Select:S

[Module3]
Meter=Image
MeterStyle=Select:S

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Button02]
Meter=Shape
MeterStyle=Set.Button:S
Act=[!WriteKeyValue Variables Player "" "#Sec.SaveLocation#"][!WriteKeyValue Variables NPName "" "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]
Y=([Option02:Y]-[ContentContainer:Y]+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=[\xe440]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
MeterStyle=Set.String:S | Set.Value:S