function GenerateProgramList {
    param (
    [int]$rows = 1
    )
    $SaveLocation = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))Main\Accessories\Page\Variants\ProgramListCache.inc"
    
    for (($i = 1); ($i -le $rows) ; $i++) {
        $fileContent += @"

[$($i)]
Meter=Shape
MeterStyle=Index:Style
[Index$($i)Icon]
Meter=Image
MeterStyle=Icon:Style
[Index$($i)Name]
Meter=String
MeterStyle=RegularText | Name:Style

"@

    }

    $fileContent += @"
[mPath]
Measure=Plugin
Plugin=FileView
Path="C:\ProgramData\Microsoft\Windows\Start Menu\Programs"
Count=$rows
ShowFolder=0
ShowDotDot=0
FinishAction=[!ShowMeterGroup List][!UpdateMeter *][!Redraw]
[mFileCount]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileCount
Group=Children

"@

    for (($i = 1); ($i -le $rows) ; $i++) {
        $fileContent += @"
[mIndex$($i)Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=$($i)
Group=Children
RegexpSubstitute=1
Substitute="\..*$":""
[mIndex$($i)Icon]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=Icon
IconSize=#IconSize#
Index=$($i)
Group=Children

"@
    }

    $fileContent | Out-File -FilePath $SaveLocation -Encoding unicode
}

function GenerateDownloadsList {
    param (
    [int]$rows = 1
    )
    $SaveLocation = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))Main\Accessories\Page\Variants\DownloadsListCache.inc"
    
    for (($i = 1); ($i -le $rows) ; $i++) {
        $fileContent += @"

[$($i)]
Meter=Shape
MeterStyle=Index:Style
[Index$($i)Icon]
Meter=Image
MeterStyle=Icon:Style
[Index$($i)Name]
Meter=String
MeterStyle=RegularText | Name:Style

"@

    }

    $fileContent += @"
[mPath]
Measure=Plugin
Plugin=FileView
Path="%USERPROFILE%\Downloads"
Count=$rows
ShowDotDot=0
SortType=Date
ShowFile=1
ShowFolder=0
ShowSystem=0
ShowHidden=0
SortAscending=0
FinishAction=[!UpdateMeasureGroup Children][!ShowMeterGroup List][!UpdateMeter *][!Redraw]

[mFileCount]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileCount
Group=Children
[mFolderSize]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FolderSize
Group=Children
[mFolderSizeCalc]
Measure=Calc
Formula=mFolderSize/1048576
DynamicVariables=1
Group=Children

"@

    for (($i = 1); ($i -le $rows) ; $i++) {
        $fileContent += @"
[mIndex$($i)Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=$($i)
Group=Children
RegexpSubstitute=1
Substitute="\..*$":""
[mIndex$($i)Icon]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=Icon
IconSize=#IconSize#
Index=$($i)
Group=Children

"@
    }

    $fileContent | Out-File -FilePath $SaveLocation -Encoding unicode
}