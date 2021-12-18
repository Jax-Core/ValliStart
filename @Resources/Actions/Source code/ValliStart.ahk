#SingleInstance Force
#NoTrayIcon
IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, Variable, ..\Vars.inc, Variables, ReplaceWin
IniRead, Position, ..\Vars.inc, Variables, Position
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
    if (Position = "MousePosition")
    {
        MouseGetPos, xpos, ypos 
        Run "%RainmeterPath%" [!CommandMeasure Func valliMoveMouse(%xpos%`,%ypos%) ValliStart\Main]
    }
    Run "%RainmeterPath%" [!UpdateMeasure mToggle ValliStart\Main]
Return

DisabledWin:
    MsgBox, Windows key + F1
Return
