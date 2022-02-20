[Variables]
@includeModulevars=#SKINSPATH##Skin.Name#\Main\Modules\Vars\#Page.SubpageModule#.inc
Sec.SaveLocation=#SKINSPATH##Skin.Name#\Main\Modules\Vars\#Page.SubpageModule#.inc

[Item1.Shape]
Meter=
[Item1.StringIcon]
Meter=
[Item1.String]
Meter=

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[HotkeysTitle]
Meter=String
Text=#Page.SubpageModule# settings
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Key to send when search bar is clicked
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[SearchKey]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#SearchKey#
MeterStyle=Set.String:S | Set.Value:S