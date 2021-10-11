[Header]
Y=(20*[Set.S]+#Scroll#)

[Option01]
Meter=String
X=r
Text=Choose a module! This will appear at the bottom section of ValliStart.
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Select:S]
X=r
Y=(20*[Set.S])R
W=(650*[Set.S])
H=(150*[Set.S])
ImageName=#@#Images\ValliStartModules\#CURRENTSECTIOn#.png
DynamicVariables=1
ImageAlpha=200
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha "255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha "200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!WriteKeyValue Variables Module "#CURRENTSECTION#" "#SEc.SaveLocation#"][!UpdateMeasure Auto_Refresh:M][!Refresh]
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer
[Selected:S]
Fill=Fill Color 255,255,255,255
ImageAlpha=255
MouseOverAction=
MouseLeaveAction=
LeftMouseUpAction=

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[Weather]
Meter=Image
X=r
Y=(30*[Set.S])R
MeterStyle=Select:S

[Resource]
Meter=Image
MeterStyle=Select:S

[Mon]
Meter=Image
MeterStyle=Select:S

[None]
Meter=Image
MeterStyle=Select:S

