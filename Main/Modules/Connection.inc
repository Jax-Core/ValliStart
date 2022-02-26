
; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
ConnectionHeight=205

@includeBT=#@#bluetooth\bluetoothVariables.inc

BTStatus=0
BT_OnBluetoothCheck_On=[!Setvariable BTStatus 1][!UpdateMeter BTStatus]
BT_OnBluetoothCheck_Off=[!Setvariable BTStatus 0][!UpdateMeter BTStatus]
BT_AfterBluetoothToggle=[!Delay 1000]#BT_CheckBluetooth#[!Redraw]

@includeBTM=#@#bluetooth\bluetooth.inc

[WifiName]
Measure=PLUGIN
Plugin=WifiStatus
WiFiInfoType=SSID
Substitute="-1":"Not connected"
OnChangeAction=[!UpdateMeter WifiName1][!Redraw]
UpdateDivider=1
[WifiPercent]
Measure=PLUGIN
Plugin=WifiStatus
WiFiInfoType=QUALITY
Substitute="":""
OnUpdateAction=[!UpdateMeasure Wifistatus]
UpdateDivider=1
[WifiStatus]
Measure=CALC
Formula=(WifiPercent > 0) ? 1 : 0
OnChangeAction=[!UpdateMeter WifiStatus1][!Redraw]
[InternetStatus]
Measure=PLUGIN
Plugin=SysInfo
SysInfoType=INTERNET_CONNECTIVITY
RegExpSubstitute=1
Substitute="^1$":"Connected","^-1$":"Not connected"
IfCondition=InternetStatus = -1
IfTrueAction=[!SetOption InternetStatus1 LeftMouseUpAction """[!CommandMeasure InternetOn "Run"]"""][!UpdateMeter InternetStatus1]
IfFalseAction=[!SetOption InternetStatus1 LeftMouseUpAction """[!CommandMeasure InternetOff "Run"]"""][!UpdateMeter InternetStatus1]
OnChangeAction=[!UpdateMeter InternetName1][!Redraw]
UpdateDivider=1
[InternetOff]
Measure=Plugin
Plugin=RunCommand
Parameter=ipconfig /release
State=Hide
[InternetOn]
Measure=Plugin
Plugin=RunCommand
Parameter=ipconfig /renew
State=Hide

; ---------------------------------------------------------------------------- ;
;                                  Connection                                  ;
; ---------------------------------------------------------------------------- ;

[ConnectionsSubititle]
Meter=String
X=(25*#Scale#)
Y=(25*#Scale#)r
MeterStyle=RegularText
Text=Connections and Network
FontColor=#Dark_Color#,200

[WifiIcon]
Meter=Image
X=(3*#Scale#)r
ImageTint=#Font_Color#
Y=(20*#Scale#)R
W=(20*#Scale#)
Imagename=#@#Icons\Wifi.png
Group=VolumeElements
[WifiText]
Meter=String
X=(25*#Scale#)R
Y=(8*#Scale#)r
StringAlign=LeftCenter
Text=Wi-Fi
MeterStyle=RegularText
[WifiStatus1]
Meter=Shape
X=(#W#-85*#Scale#)
Y=r
Shape=Rectangle 0,(-13*#Scale#),(53*#Scale#),(26*#Scale#),(13*#Scale#),(13*#Scale#) | Fill Color 0,0,0,0 | StrokeWidth (1.3-[WifiStatus:0]*1.3) | Extend tHis 
Shape2=Rectangle 0,(-14*#Scale#),(55*#Scale#),(28*#Scale#),(14*#Scale#),(14*#Scale#) | Fill Color Accent_Color,([WifiStatus:0]*255) | StrokeWidth 0 | Extend tHis 
shape3=Ellipse (15*#Scale#+[WifiStatus:0]*25*#Scale#),0,(7*#Scale#+[WifiStatus:0]*#Scale#),(7*#Scale#+[WifiStatus:0]*#Scale#) | StrokeWidth 0 | Fill Color #Font_Color#
This=Stroke Color #Dark_Color#
dat=4,9 | LineTo 8,13 | LineTo 15,5
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke Color #Font_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke Color #Dark_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
LeftMouseUpAction=["ms-availablenetworks:"]
[WifiName1]
Meter=String
X=(#W#-95*#Scale#)
Y=r
StringAlign=RightCenter
MeasureName=WifiName
Text=%1
FontSize=(10*#Scale#)
FontColor=#Dark_Color#
MeterStyle=RegularText

[BTIcon]
Meter=Image
ImageTint=#Font_Color#
X=[WifiIcon:X]
Y=(35*#Scale#)r
W=(20*#Scale#)
Imagename=#@#Icons\Bluetooth.png
Group=VolumeElements
[BTText]
Meter=String
X=(25*#Scale#)R
Y=(8*#Scale#)r
StringAlign=LeftCenter
Text=Bluetooth
MeterStyle=RegularText
[BTStatus]
Meter=Shape
X=(#W#-85*#Scale#)
Y=r
Shape=Rectangle 0,(-13*#Scale#),(53*#Scale#),(26*#Scale#),(13*#Scale#),(13*#Scale#) | Fill Color 0,0,0,0 | StrokeWidth (1.3-#BTStatus#*1.3) | Extend tHis 
Shape2=Rectangle 0,(-14*#Scale#),(55*#Scale#),(28*#Scale#),(14*#Scale#),(14*#Scale#) | Fill Color Accent_Color,(#BTStatus#*255) | StrokeWidth 0 | Extend tHis 
shape3=Ellipse (15*#Scale#+#BTStatus#*25*#Scale#),0,(7*#Scale#+#BTStatus#*#Scale#),(7*#Scale#+#BTStatus#*#Scale#) | StrokeWidth 0 | Fill Color #Font_Color#
This=Stroke Color #Dark_Color#
dat=4,9 | LineTo 8,13 | LineTo 15,5
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke Color #Font_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke Color #Dark_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
LeftMouseUpAction=#BT_ToggleBluetooth#
MiddleMouseUpAction=["Ms-settings:bluetooth"]
[BTname]
Meter=String
X=(#W#-95*#Scale#)
Y=r
StringAlign=RightCenter
Text=
FontSize=(10*#Scale#)
FontColor=#Dark_Color#
MeterStyle=RegularText

[InternetIcon]
Meter=Image
ImageTint=#Font_Color#
X=[WifiIcon:X]
Y=(35*#Scale#)r
W=(20*#Scale#)
Imagename=#@#Icons\Ethernet-1.png
Group=VolumeElements
[InternetText]
Meter=String
X=(25*#Scale#)R
Y=(8*#Scale#)r
StringAlign=LeftCenter
Text=Internet
MeterStyle=RegularText
[InternetStatus1]
Meter=Shape
X=(#W#-85*#Scale#)
Y=r
Shape=Rectangle 0,(-13*#Scale#),(53*#Scale#),(26*#Scale#),(13*#Scale#),(13*#Scale#) | Fill Color 0,0,0,0 | StrokeWidth (1.3-[InternetStatus:0]*1.3) | Extend tHis 
Shape2=Rectangle 0,(-14*#Scale#),(55*#Scale#),(28*#Scale#),(14*#Scale#),(14*#Scale#) | Fill Color Accent_Color,([InternetStatus:0]*255) | StrokeWidth 0 | Extend tHis 
shape3=Ellipse (40*#Scale#),0,(8*#Scale#),(8*#Scale#) | StrokeWidth 0 | Fill Color #Font_Color#,([InternetStatus:0]*255)
shape4=Ellipse (15*#Scale#),0,(8*#Scale#),(8*#Scale#) | StrokeWidth 0 | Fill Color #Font_Color#,([InternetStatus:0]*(-1)*255)
This=Stroke Color #Dark_Color#
dat=4,9 | LineTo 8,13 | LineTo 15,5
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke Color #Font_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke Color #Dark_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
LeftMouseUpAction=
[InternetName1]
Meter=String
X=(#W#-95*#Scale#)
Y=r
StringAlign=RightCenter
MeasureName=InternetStatus
Text=%1
FontSize=(10*#Scale#)
FontColor=#Dark_Color#
MeterStyle=RegularText

[ConnectionAnchor]
Meter=String
Y=(10*#Scale#*#Stroke#+(35*#Scale#))r
DynamicVariables=1