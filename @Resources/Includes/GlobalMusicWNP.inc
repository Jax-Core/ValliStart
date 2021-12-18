[mHide]
Measure=calc
DynamicVariables=1
ifcondition=(mState = 0)
iftrueaction=[!HideMeterGroup Music][!UpdateMeter *][!Redraw]
IfFalseAction=[!ShowMeterGroup Music][!UpdateMeter *][!Redraw]
UpdateDivider=2
Group=Music

[mCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
DefaultPath=#@#Images\Default.png
CoverPath=#@#Images\Cover.png
OnChangeAction=[!SetOption MainC Path "[#CURRENTSECTION#]"][!UpdateMeter MusicImg][!Redraw]
UpdateDivider=1
Disabled=(1-#FetchImage#)
Group=Music

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
UpdateDivider=1
Group=Music

[mArtist]
Measure=Plugin
Plugin=WebNowPlaying
OnchangeAction=[!UpdateMeasureGroup Music][!UpdateMeter *][!Redraw]
PlayerType=Artist
Substitute="":"Fetching..."
UpdateDivider=1
Group=Music

[mTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
OnChangeAction=[!UpdateMeter *][!Redraw]
Substitute="":"Fetching..."
UpdateDivider=1
Group=Music

[mProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music

[mCurrentPosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position
UpdateDivider=1
Group=Music

[mLength]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration
UpdateDivider=1
Group=Music

[mHeart]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Rating
IfCondition=mHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"]
UpdateDivider=1
Group=Music