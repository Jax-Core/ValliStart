@echo off
FOR /F "skip=2 tokens=2,*" %%A IN ('reg.exe query "HKLM\SYSTEM\CurrentControlSet\Services\bthserv\Parameters\BluetoothControlPanelTasks" /v "state"') DO set "VAR=%%B"

if %VAR%==0x1 (goto ON)

Powershell.exe -executionpolicy unrestricted -windowstyle hidden -File ".\bluetooth.ps1" -BluetoothStatus On
echo BTT_ON
goto end

:ON
echo BTT_OFF
Powershell.exe -executionpolicy unrestricted -windowstyle hidden -File ".\bluetooth.ps1" -BluetoothStatus Off

:end