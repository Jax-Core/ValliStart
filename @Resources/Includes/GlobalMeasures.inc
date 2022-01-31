
[MeasureTime]
Measure=Time
Format=%#gVar.2412#:%M
UpdateDivider=1
Disabled=#CustomFormat#
[MeasureSec]
Measure=Time
Format=:%S
UpdateDivider=1
Disabled=(#ShowSEc#-1)
Disabled=#CustomFormat#
[MeasureAP]
Measure=Time
Format=%p
UpdateDivider=1
Disabled=#CustomFormat#
[MeasureCustomFormat]
Measure=Time
Format=#CustomTimeFormat#
UpdateDivider=1
Disabled=(1-#CustomFormat#)
; [MeasureDate]
; Measure=Time
; Format=%a, %#b %#d
; UpdateDivider=1
; [MeasureUsername]
; Measure=Plugin
; Plugin=SysInfo
; SysInfoType=USER_NAME


