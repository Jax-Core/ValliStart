[Variables]
; SaveLocation="#@#Includes\Window.ini"
; SaveKey=Fill

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Manage panel]
Meter=String
Y=(#Sec.P#)
LeftMouseUpAction=[!Manage][!DeactivateConfig]
MeterStyle=String:S
[Div:1]
Meter=Shape
MeterStyle=Div:S
[Settings panel]
Meter=String
LeftMouseUpAction=[!Manage Settings][!DeactivateConfig]
MeterStyle=String:S
[Div:2]
Meter=Shape
MeterStyle=Div:S
[Logs]
Meter=String
LeftMouseUpAction=[!About Logs][!DeactivateConfig]
MeterStyle=String:S
[Div:3]
Meter=Shape
MeterStyle=Div:S
[Skin data]
Meter=String
LeftMouseUpAction=[!About Skins][!DeactivateConfig]
MeterStyle=String:S
[Div:4]
Meter=Shape
MeterStyle=Div:S
[Plugin list]
Meter=String
LeftMouseUpAction=[!About Plugins][!DeactivateConfig]
MeterStyle=String:S


; [LogoutIconH]
; Meter=shape
; X=(#W#-(56+40*3)*#Scale#)
; MeterStyle=ShutdownIconH
; [LogoutIcon]
; Meter=Image
; ImageTint=#FontColor#
; X=(#W#-(50+40*3)*#Scale#)
; Imagename=#@#Icons\Logout.png
; LeftMouseUpAction=%systemroot%\system32\shutdown.exe -l -t 00
; ToolTipText=Logout
; MeterStyle=ShutdownIcon
; [SleepIconH]
; Meter=shape
; X=(#W#-(56+40*2)*#Scale#)
; MeterStyle=ShutdownIconH
; [SleepIcon]
; Meter=Image
; ImageTint=#FontColor#
; X=(#W#-(50+40*2)*#Scale#)
; Imagename=#@#Icons\Sleep.png
; LeftMouseUpAction=%windir%\System32\rundll32.exe powrprof.dll,SetSuspendState
; ToolTipText=Hibernate
; MeterStyle=ShutdownIcon
; [RestartIconH]
; Meter=shape
; X=(#W#-(56+40)*#Scale#)
; MeterStyle=ShutdownIconH
; [RestartIcon]
; Meter=Image
; ImageTint=#FontColor#
; X=(#W#-(50+40)*#Scale#)
; Imagename=#@#Icons\Restart.png
; LeftMouseUpAction=%systemroot%\system32\shutdown.exe -r -t 00
; ToolTipText=Restart
; MeterStyle=ShutdownIcon
; [ShutdownIconH]
; Meter=shape
; X=(#W#-56*#Scale#)
; Y=(812*#Scale#)
; Shape=Rectangle 0,0,(36*#Scale#),(36*#Scale#),(#Corner#*5),(#Corner#*5) | StrokeWidth 0 | Extend this
; This=Fill Color 0,0,0,1
; Container=Container
; MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #FontColor#,25"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; [ShutdownIcon]
; Meter=Image
; ImageTint=#FontColor#
; X=(#W#-50*#Scale#)
; Y=(818*#Scale#)
; W=(24*#Scale#)
; Container=Container
; Hidden=1
; Group=PowerOptions
; Imagename=#@#Icons\Shutdown.png
; LeftMouseUpAction=%systemroot%\system32\shutdown.exe -s -t 00
; ToolTipText=Shutdown