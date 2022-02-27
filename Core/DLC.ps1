

function debug {
    param(
        [Parameter()]
        [string]
        $message
    )

    $RmAPI.Bang("[!Log `"`"`"" + $message + "`"`"`" Debug]")
}

function Update {
    $editingModule = $RmAPI.VariableStr('Page.SubpageModule')
    $skinsPath = $RmAPI.VariableStr('SKINSPATH')
    $DLCDir = "$($skinsPath.Replace('Skins\',''))CoreData\DLC\"
    $skinName = $RmAPI.VariableStr('Skin.Name')

    $fileInstalledDLCs = "$($skinsPath)$skinName\@Resources\InstalledDLCs.inc"
    $file1 = "$($skinsPath)$skinName\Core\DLC\Includer.inc"
    $file2 = "$($skinsPath)$skinName\Core\Layout\Includer.inc"

    $arr = @(Get-ChildItem $DLCDir | Foreach-Object -Process {[System.IO.Path]::GetFileNameWithoutExtension($_)})
    if ($arr.Length -eq 0) {
        $file1content += @"

[Item1.Shape]
Meter=Shape
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe854]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=You don't have any DLCs installed! If you've purchased it and unsure how to install, read the guide on the gumroad page!
MeterStyle=Set.String:S | Item.String:S

"@
        $file2content = ""
        $file1content | Out-File -FilePath $file1 -Encoding unicode
        $file2content | Out-File -FilePath $file2 -Encoding unicode
        $file2content | Out-File -FilePath $fileInstalledDLCs -Encoding unicode
    }


    for ($i = 1; $i -le $arr.Length; $i++) {
        if ([string]::IsNullOrEmpty($RmAPI.VariableStr($arr[$i-1]))) {


            for ($i = 1; $i -le $arr.Length; $i++) {
                $iName = $arr[$i-1]
                debug $iName
                
                $RmAPI.Bang("[!WriteKeyValue Variables $iName $(-join ((48..57) + (97..122) | Get-Random -Count 32 | % {[char]$_})) `"`"`"$fileInstalledDLCs`"`"`"]")
                Expand-Archive -Path "$DLCDir$iName.zip" -DestinationPath "$($skinsPath)$skinName\" -Force -Verbose

                $file1content += @"

[$iName.Shape]
Meter=Shape
MeterStyle=Item.Shape:S
[$iName.StringIcon]
Meter=String
Text=[\xf091]
MeterStyle=Set.String:S | Item.StringIcon:S
[$iName.String]
Meter=String
Text=$iName - $skinName
MeterStyle=Set.String:S | Item.String:S

"@
                $file2content += @"

[$iName.Shape]
Meter=Shape
MeterStyle=Module.Shape:S
[$iName.Image]
Meter=Image
MeterStyle=Module.Image:S
[$iName.String]
Meter=String
MEterStyle=Set.String:S | Module.STring:S
[$iName.Description.String]
Meter=String
Text=Default layout for the $iName DLC
MEterStyle=Set.String:S | Module.Description.STring:S

"@
                $file1content | Out-File -FilePath $file1 -Encoding unicode
                $file2content | Out-File -FilePath $file2 -Encoding unicode
            }

            
        break
        }
    }

    $RmAPI.Bang("[!Delay 1000][!WriteKeyvalue Variables page.page 1 `"$($skinsPath)$skinName\Core\DLC.inc`"][!Refresh]")
}