; #SingleInstance Force
; #NoTrayIcon
; SetTitleMatchMode, 2
; DetectHiddenWindows, On
; numberkeys := 0


; IniRead, OutputVar, Hotkeys.ini, Variables, Key
; IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH

; Hotkey,%OutputVar%,Button
; Return

; Button:
; Run "%RainmeterPath% "!UpdateMeasure "mToggle" "ValliStart\Main" "
; Unload := 1
; Return

#SingleInstance Force
#NoTrayIcon
Unload := 0

$LWin::
	Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasureGroup "UpdateOnLoad" "ValliStart\Main"""
	Unload := 1
	return

~Esc::
	if (Unload = 1)
		Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasure "Unload" "ValliStart\Main"""
		Unload := 0
	return
return

LWin & F1::
MsgBox, Windows key + F1
return
