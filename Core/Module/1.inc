[DefaultStartActions]
Custom1=[!SetOption [##page.editing#] MeterStyle "Select:S | Selected:S"][!UpdateMEter [##page.editing#]][!Redraw]

[Cat]
Meter=String
X=r
Text=Select a module for #page.editing#
MeterStyle=Set.String:S | Set.OptionCat:S

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Select:S]
X=r
Y=(20*[Set.S])R
W=(600*[Set.S])
H=(150*[Set.S])
ImageName=#SKINSPATH##Skin.Name#\Core\Module\#CURRENTSECTIOn#.png
DynamicVariables=1
ImageAlpha=150
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha "255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha "150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!WriteKeyValue Variables #page.editing# "#CURRENTSECTION#" "#SEc.SaveLocation#"][!UpdateMeasure Auto_Refresh:M][!WriteKeyvalue Variables page.page 0 "#SKINSPATH##Skin.Name#\Core\Modules.inc"][!Refresh]
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer
[Selected:S]
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

[Connection]
Meter=Image
MeterStyle=Select:S

[Music]
Meter=Image
MeterStyle=Select:S

[Mon]
Meter=Image
MeterStyle=Select:S

[None]
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