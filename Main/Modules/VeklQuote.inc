; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Variables]
VeklQuoteHeight=(100+#Pad#)
Prev=1
SwitchTime=60
Get=.*<item>.*<title>(.*)</title>.*<description>"(.*)"</description>

[MeasureNext]
Measure=Calc
Formula=#Prev#+1>4? 1:(#Prev#+1)
DynamicVariables=1
UpdateDivider=1
Group=VeklQuote

[MeasurePrev]
Measure=Calc
Formula=#Prev#-1<1? 4:(#Prev#-1)
DynamicVariables=1
UpdateDivider=1
Group=VeklQuote

[MeasureSite] 
Measure=Plugin 
Plugin=WebParser
URL=http://feeds.feedburner.com/brainyquote/QUOTEBR
RegExp=(?siU).*<title>(.*)</title>.*<link>(.*)</link>.*<description>(.*)</description>.*<pubDate>(.*)</pubDate>#Get##Get##Get##Get#
UpdateRate=43200
UpdateDivider=1
FinishAction=[!UpdateMeasureGroup VeklQuote][!UpdateMeterGroup VeklQuote][!redraw]
; 43200 seconds equals 12 hours
; 86400 seconds equals 1 day

[MeasureLink]
Measure=Plugin
Plugin=Webparser
URL=[MeasureSite]
StringIndex=2
UpdateDivider=1

[MeasureAuthor1] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=5
IfCondition=#prev# > 4
IfTrueAction=[!setvariable prev 1][!UpdateMeasureGroup VeklQuote][!UpdateMeterGroup VeklQuote][!redraw]
IfCondition2=#prev# <= 0
IfTrueAction2=[!setvariable prev 4][!UpdateMeasureGroup VeklQuote][!UpdateMeterGroup VeklQuote][!redraw]
DynamicVariables=1
UpdateDivider=1
Group=VeklQuote

[MeasureQuote1]
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
StringIndex=6

[MeasureAuthor2] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=7

[MeasureQuote2] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=8

[MeasureAuthor3] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=9

[MeasureQuote3] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=10

[MeasureAuthor4] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=11

[MeasureQuote4] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=12


; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[VeklQuote.Shape]
Meter=Shape
X=#P#
Y=#P#r
Shape=Rectangle 0,0,(#W#-#P#*2),(100*#Scale#),#R# | StrokeWidth #Stroke# | Extend This
This=Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#
That=Fill Color #Ter_Color#,#Alpha#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke color #Dark_Color# | Fill Color #Ter_Color#,#Alpha#"][!SetOption #CURRENTSECTION# That "Fill Color #Dark_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke color #Ter_Color# | Fill Color #Sec_Color#,#Alpha#"][!SetOption #CURRENTSECTION# That "Fill Color #Ter_Color#,#Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseScrollUpAction=[!SetVariable Prev [MeasurePrev]][!UpdateMeasureGroup VeklQuote][!UpdateMeterGroup VeklQuote][!redraw]
MouseScrollDownAction=[!SetVariable Prev [MeasureNext]][!UpdateMeasureGroup VeklQuote][!UpdateMeterGroup VeklQuote][!redraw]

[VeklQuote.String]
Meter=String
X=((#W#-#P#*2)/2)r
Y=(100/2*#scale#)r
W=(#W#-#P#*4)
ClipString=2
MeasureName=MeasureAuthor#prev#
MeasureName2=MeasureQuote#prev#
Text=%1#CRlf#%2
InlinePattern=.*#CRLF#
InlineSetting=Color | #dark_Color#
InlinePattern2=.*#CRLF#
InlineSetting2=Size | (10*#Scale#)
FontSize=(12*#scale#)
DynamicVariables=1
StringAlign=CenterCenter
MeterStyle=RegularText
Group=VeklQuote

[VeklQuoteHeader]
Meter=String
Y=(100/2*#scale#+#P#*#Divider#)r
DynamicVariables=1