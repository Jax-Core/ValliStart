#SingleInstance Force
#NoTrayIcon
IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, Variable, ..\Vars.inc, Variables, ReplaceWin
IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH

if (Variable = 0)
{
	Hotkey,%OutputVar%,Button
	Return
}
else
{
	HotKey,$LWin,Button
	HotKey,LWin & F1,DisabledWin
	Return
}

Button:
Run "%RainmeterPath% "!UpdateMeasure "mToggle" "ValliStart\Main" "
Return

DisabledWin:
MsgBox, Windows key + F1
Return
