; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
[ImageContainer]
Hidden=1
[Image]
Hidden=1

[Title]
Meter=String
Text="v2.97 change logs"
MeterStyle=Sec.String:S | Style.Title:S

[Description.1]
Meter=String
Text="- Uses global variables instead of ones saved in ValliStart."
MeterStyle=Sec.String:S | Style.Description:S
; [Link.1]
; Meter=String
; Text="https://jax-core.github.io/"
; LeftMouseUpAction=["https://jax-core.github.io/"]
; MeterStyle=Sec.String:S | Style.Link:S

[Description.2]
Meter=String
Text="- Fixed Weather module"
MeterStyle=Sec.String:S | Style.Description:S

[Title2]
Meter=String
Text="ValliStart 3.0 announcement"
Y=(20*[Set.S])R
MeterStyle=Sec.String:S | Style.Title:S

[Description.4]
Meter=String
Text="ValliStart 3.0 will be releasing next month, refining all features and adding more modules and functionalities. Join the Discord server for development and beta test updates!"
MeterStyle=Sec.String:S | Style.Description:S

; [Description.5]
; Meter=String
; Text="- Added Scrollbar and a few bug fixes"
; MeterStyle=Sec.String:S | Style.Description:S

; [Description.6]
; Meter=String
; Y=(#Sec.P#*2)R
; Text="Happy Holidays everyone! This is the biggest update Core has ever received, if you liked it consider leaving a star on the DeviantArt post!"
; MeterStyle=Sec.String:S | Style.Description:S


[DA:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#*2+#Sec.P#*0.5)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
LeftMouseUpAction=[!Deactivateconfig]
meterStyle=BottomBox:S | FalseStyleDesk
[DA:String]
Meter=String
StringAlign=CenterCenter
Text=Got it!
MeterStyle=Sec.String:S | BottomText:S
[DiscordServer:]
Meter=Shape
ColorLeave=88, 101, 242,150
ColorOver=88, 101, 242
LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
meterStyle=BottomBox:S | FalseStyleDesk
[DiscordServer:String]
Meter=String
StringAlign=CenterCenter
Text=Join the Discord
MeterStyle=Sec.String:S | BottomText:S