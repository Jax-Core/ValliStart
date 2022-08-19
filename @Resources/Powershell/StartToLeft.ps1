function Set-TaskbarAlignment {
    Set-ItemProperty -Path "hkcu:\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced"`
    -Name 'TaskbarAl' `
    -Value 0 `
    -Type DWord
}