

function debug {
    param(
        [Parameter()]
        [string]
        $message
    )

    $RmAPI.Bang("[!Log `"`"`"" + $message + "`"`"`" Debug]")
}
function check-update {
    $editingModule = $RmAPI.VariableStr('Page.SubpageModule')
    $skinsPath = $RmAPI.VariableStr('SKINSPATH')
    $skinName = $RmAPI.VariableStr('Skin.Name')
    $DLCDir = "$($skinsPath.Replace('Skins\',''))CoreData\$skinName\DLC\"
    $skinDir = "$($skinsPath)$skinName"

    $fileInstalledDLCs = "$skinDir\@Resources\InstalledDLCs.inc"
    $file1 = "$skinDir\Core\DLC\Includer.inc"
    $file2 = "$skinDir\Core\Layout\Includer.inc"
    $file3 = "$skinDir\Core\Window\ValliModule\4.inc"

    $arr = @(Get-ChildItem $DLCDir -filter *.zip | Foreach-Object -Process {[System.IO.Path]::GetFileNameWithoutExtension($_)})
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
        $file3content += @"

[Item2.Shape]
Meter=Shape
MeterStyle=Item.Shape:S
[Item2.StringIcon]
Meter=String
Text=[\xe719]
MeterStyle=Sec.String:S | Item.StringIcon:S
[Item2.String]
Meter=String
Text=You seem to not have any DLCs installed, discover them on my gumroad page!
MeterStyle=Sec.String:S | Item.String:S
[Item2.Button]
Meter=Shape
MeterStyle=Item.Button.Shape:S
[Item2.Button.StringIcon]
Meter=String
Text=[\xe89e]
LeftMouseUpAction=["https://jaxcore.gumroad.com/"]
MeterStyle=Sec.String:S | Item.Button.StringIcon:S

"@
        $file2content = ""
        $file1content | Out-File -FilePath $file1 -Encoding unicode
        $file2content | Out-File -FilePath $file2 -Encoding unicode
        $file3content | Out-File -FilePath $file3 -Encoding unicode
        $file2content | Out-File -FilePath $fileInstalledDLCs -Encoding unicode
    }


    for ($i = 1; $i -le $arr.Length; $i++) {
        if ([string]::IsNullOrEmpty($RmAPI.VariableStr($arr[$i-1]))) {


            for ($i = 1; $i -le $arr.Length; $i++) {
                $iName = $arr[$i-1]
                debug $iName
                
                $RmAPI.Bang("[!WriteKeyValue Variables $iName $(-join ((48..57) + (97..122) | Get-Random -Count 32 | % {[char]$_})) `"`"`"$fileInstalledDLCs`"`"`"]")
                Expand-Archive -Path "$DLCDir$iName.zip" -DestinationPath "$skinDir\" -Force -Verbose

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
                $file3content += @"

[$iName.Div]
Meter=Shape
X=#Sec.P#
Y=(#Sec.P#)R
Shape=Line 0,0,(#W#-#Sec.P#*2),0 | StrokeWidth 4 | Fill Color #Set.Pri_Color#,0 | Stroke LinearGradient This
This=0 | #Set.Text_Color#,25 ; 0.0 | #Set.Text_Color#,0 ; 0.5 | #Set.Text_Color#,25 ; 1.0
DynamicVariables=1
Container=ContentContainer

[$iName.String]
Meter=String
Text=$iName - $skinName
FontColor=#Set.Subtext_Color#
X=(#W#/2)
Y=r
DynamicVariables=1
InlineSetting=CharacterSpacing | 2 | 2
StringAlign=CenterCenter
MeterStyle=Sec.String:S

"@
                $moduleNames = @(Get-ChildItem "$skinDir\Core\Module" | Where-Object { $_.Name -match "^$iName" } | Foreach-Object -Process {[System.IO.Path]::GetFileNameWithoutExtension($_)})
                for ($j = 1; $j -le $moduleNames.Length; $j++) {
                    $mo = $j % 3
                    $file3content += @"
                
[$($moduleNames[$j-1]).Shape]
Meter=Shape
"@
                    if ($mo -eq 1) {
                        $file3content += @"

X=(#SEc.P#)
Y=(#Sec.P#*2)r
"@
                    }
                    $file3content += @"

MeterStyle=DLC.Shape:S
[$($moduleNames[$j-1]).Image]
Meter=Image
MeterStyle=DLC.Image:S
[$($moduleNames[$j-1]).String]
Meter=String
MEterStyle=Sec.String:S | DLC.STring:S
"@
                }

                $file3content += @"
                
[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R

"@
                $file1content | Out-File -FilePath $file1 -Encoding unicode
                $file2content | Out-File -FilePath $file2 -Encoding unicode
                $file3content | Out-File -FilePath $file3 -Encoding unicode
            }

            
        break
        }
    }

    $RmAPI.Bang("[!Delay 1000][!WriteKeyvalue Variables page.page 1 `"$skinDir\Core\DLC.inc`"][!Refresh]")
}

function moveDLC($path) {
    $skinsPath = $RmAPI.VariableStr('SKINSPATH')
    $skinName = $RmAPI.VariableStr('Skin.Name')
    $DLCDir = "$($skinsPath.Replace('Skins\',''))CoreData\$skinName\DLC\"
    $skinDir = "$($skinsPath)$skinName"
    debug $path
    Move-Item -Path $path -Destination $DLCDir
    $RmAPI.Bang("[!Delay 500][!WriteKeyvalue Variables page.page 0 `"$skinDir\Core\DLC.inc`"][!Refresh]")
}