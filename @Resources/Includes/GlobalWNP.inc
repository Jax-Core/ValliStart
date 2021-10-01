[mHide]
Measure=calc
DynamicVariables=1
ifcondition=(mState = 0)
iftrueaction=[!HideMeterGroup Music][!SetOption MonitorsBisecotr Y "476*#Scale#"][!UpdateMeter *][!Redraw]
IfFalseAction=[!ShowMeterGroup Music][!SetOption MonitorsBisecotr Y "((474+150)*#Scale#)"][!UpdateMeter *][!Redraw]
UpdateDivider=2

[mCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
DefaultPath=#@#Images\Default.png
CoverPath=#@#Images\Cover.png
OnChangeAction=[!SetOption MainC Path "[#CURRENTSECTION#]"][!UpdateMeter MusicImg][!Redraw]
UpdateDivider=(#Animated# = 2 ? 50 : 1)
Disabled=(1-#FetchImage#)

[mState]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
IfCondition=mState = 1
IfTrueAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw]
IfCondition2=mState = 2
IfTrueAction2=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw]
IfCondition3=mState = 0
IfTrueAction3=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw]
IfConditionMode=0
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
DynamicVariables=1
UpdateDivider=(#Animated# = 2 ? 50 : 1)

[mArtist]
Measure=Plugin
Plugin=WebNowPlaying
OnchangeAction=[!UpdateMeasureGroup Music][!UpdateMeter *][!Redraw]
PlayerType=Artist
Substitute="":"Fetching..."
UpdateDivider=(#Animated# = 2 ? 50 : 1)

[mTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
OnChangeAction=[!UpdateMeter *][!Redraw]
Substitute="":"Fetching..."
UpdateDivider=(#Animated# = 2 ? 50 : 1)

[mProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=(#Animated# = 2 ? 50 : 1)

[mCurrentPosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position
UpdateDivider=(#Animated# = 2 ? 50 : 1)

[mLength]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration
UpdateDivider=(#Animated# = 2 ? 50 : 1)

[mHeart]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Rating
IfCondition=mHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"]
UpdateDivider=(#Animated# = 2 ? 50 : 1)