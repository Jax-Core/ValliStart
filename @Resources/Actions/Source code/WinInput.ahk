#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.uytu
#SingleInstance Force ; Allow only one running instance of script.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

Loop,
   {
        Input, Var, L1 V
        setkeydelay, 0
        send, {esc}
        send, {LWin down}
        sleep,10
        send, {LWin up}
        sleep, 10 
        send, %Var%
        ExitApp
   }