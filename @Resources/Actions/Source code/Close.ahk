#NoTrayIcon

CloseScript(Name)
{
    DetectHiddenWindows On
    SetTitleMatchMode RegEx
    IfWinExist, i)%Name%.* ahk_class AutoHotkey
    {
        Loop {
            WinClose
            WinWaitClose, i)%Name%.* ahk_class AutoHotkey, , 2
            IfWinNotExist
                Break ;No [more] matching windows found
        }
        If ErrorLevel
            return "Unable to close " . Name
        else
            return "Closed " . Name
    }
    else
        return Name . " not found"
}

CloseScript("ValliStart.ahk")
ExitApp