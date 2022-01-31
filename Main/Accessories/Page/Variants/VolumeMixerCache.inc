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
