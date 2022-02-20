; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
@includeModuleVariable=Vars\SearchBar.inc
SearchBarHeight=90

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Searchbar.Shape]
Meter=shape
X=(25*#Scale#)
Y=(25*#scale#)r
Shape=Rectangle 0,0,(#W#-50*#Scale#),(40*#Scale#),(#R#/2) | StrokeWidth 2 | Extend This
This=Stroke color #Border#,#Alpha# | Fill Color #Color#,#Alpha#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke color #BoxBorder# | Fill Color #BoxColor#,#Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke color #Border#,#Alpha# | Fill Color #Color#,#Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["#@#Actions\Nircmd.exe" sendkeypress #SearchKey#]
[Searchbar.StringIcon]
Meter=String
FontFace=Segoe Fluent Icons
Text=[\xe721]
StringAlign=CenterCenter
X=(20*#Scale#)r
Y=(20*#Scale#)r
FontSize=(12*#Scale#)
MeterStyle=regularText
[Searchbar.String]
Meter=String
Text=Type here to search
StringAlign=LeftCenter
FontColor=#DarkColor#
X=(20*#Scale#)r
Y=r
MeterStyle=regularText


[SearchBarAnchor]
Meter=String
Y=(45*#Scale#)r
DynamicVariables=1