#SingleInstance Force ; Allow only one running instance of script.
#NoTrayIcon
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.


OnMessage(16687, "RainmeterWindowMessage")

RainmeterWindowMessage(wParam, lParam) { 
     sleep, 2000
     ExitApp
}

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




   