@echo off
FOR /F "skip=2 tokens=2,*" %%A IN ('reg.exe query "HKLM\SYSTEM\CurrentControlSet\Services\bthserv\Parameters\BluetoothControlPanelTasks" /v "state"') DO set "VAR=%%B"

if %VAR%==0x1 (goto ON)

echo BT_OFF
goto end

:ON
echo BT_ON

:end
exit