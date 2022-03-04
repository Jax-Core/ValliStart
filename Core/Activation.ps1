
# $Startpath = $env:APPDATA

function CoreData {
    $skinsPath = $RmAPI.VariableStr('SKINSPATh')
    $Dir = "$($skinsPath.Replace('Skins\',''))CoreData\ValliStart\"
    $RainmeterExe = $RmAPI.VariableStr('PROGRAMPATH')
    $ResourceFolder = "$($skinsPath)ValliStart\@Resources\"
    $OrbImageName = $RmAPI.VariableStr('OrbImageName')

    Remove-Item "$($RainmeterExe)Rainmeter.exe"

    $WScriptShell = New-Object -ComObject WScript.Shell
    $Shortcut = $WScriptShell.CreateShortcut($Dir + "\ValliStart.lnk")
    $Shortcut.TargetPath = $RainmeterExe + "Rainmeter.exe"
    $Shortcut.Arguments = '!UpdateMeasure valliActionReceiver "ValliStart\Winblock"'
    $shortcut.IconLocation = $ResourceFolder + "Images\StartOrbs\$OrbImageName.ico"
    $Shortcut.Save()
}