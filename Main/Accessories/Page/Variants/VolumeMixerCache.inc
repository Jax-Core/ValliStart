[AppVol1]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=1
Substitute=".exe":""
Group=UpdateWhenChange
[AppVolPer1]
Measure=Calc
Formula=Round(AppVol1 * 100)
Group=UpdateWhenChange
Substitute="-100":"Muted"
[Vol1]
Meter=String
MeterStyle=RegularText | TextStyle
[1]
Meter=Shape
MeterStyle=ShapeStyle
[VolPer1]
Meter=String
MeterStyle=RegularText | VolStyle
[AppVol2]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=2
Substitute=".exe":""
Group=UpdateWhenChange
[AppVolPer2]
Measure=Calc
Formula=Round(AppVol2 * 100)
Group=UpdateWhenChange
Substitute="-100":"Muted"
[Vol2]
Meter=String
MeterStyle=RegularText | TextStyle
[2]
Meter=Shape
MeterStyle=ShapeStyle
[VolPer2]
Meter=String
MeterStyle=RegularText | VolStyle
[AppVol3]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=3
Substitute=".exe":""
Group=UpdateWhenChange
[AppVolPer3]
Measure=Calc
Formula=Round(AppVol3 * 100)
Group=UpdateWhenChange
Substitute="-100":"Muted"
[Vol3]
Meter=String
MeterStyle=RegularText | TextStyle
[3]
Meter=Shape
MeterStyle=ShapeStyle
[VolPer3]
Meter=String
MeterStyle=RegularText | VolStyle
