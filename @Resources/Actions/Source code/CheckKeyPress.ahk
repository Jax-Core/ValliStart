#SingleInstance Force ; Allow only one running instance of script.
#NoTrayIcon
SendMode Input ; Recommended for new scripts due to its superior speed and reliability.
; SetWorkingDir %A_ScriptDir% ; Ensures a consistent starting directory.

IniRead, OutputVar, Hotkeys.ini, Variables, Key2

; OnMessage(16687, ExitApp)

Loop,
{
   Input, Var, B L1 V
   setkeydelay, 0
   send, %OutputVar%
   sleep, 50
   send, %Var%
   ExitApp
}
Return

