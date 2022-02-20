function Update {
    $editingModule = $RmAPI.VariableStr('Page.SubpageModule')
    $skinsPath = $RmAPI.VariableStr('SKINSPATH')
    $coreDataDir = "$($skinsPath.Replace('Skins\',''))CoreData\"
    $global:file1 = "$coreDataDir"+"ValliStart\$editingModule.inc"
    $global:file2 = "$skinsPath"+"ValliStart\@Resources\Shortcuts.inc"
    $global:editingSectionPrefix = $RmAPI.VariableStr('EditingSectionPrefix')+'Box'
    $global:editingPrefix = $RmAPI.VariableStr('EditingPrefix')
    $global:editingCount = $RmAPI.VariableStr('Count')
}

# ---------------------------------------------------------------------------- #
#                                   Functions                                  #
# ---------------------------------------------------------------------------- #

function Get-IniContent ($filePath) {
    $ini = [ordered]@{}
    if (![System.IO.File]::Exists($filePath)) {
        throw "$filePath invalid"
    }
    # $section = ';ItIsNotAFuckingSection;'
    # $ini.Add($section, [ordered]@{})

    foreach ($line in [System.IO.File]::ReadLines($filePath)) {
        if ($line -match "^\s*\[(.+?)\]\s*$") {
            $section = $matches[1]
            $secDup = 1
            while ($ini.Keys -contains $section) {
                $section = $section + '||ps' + $secDup
            }
            $ini.Add($section, [ordered]@{})
        }
        elseif ($line -match "^\s*;.*$") {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $matches[1]
        }
        elseif ($line -match "^\s*(.+?)\s*=\s*(.+?)$") {
            $key, $value = $matches[1..2]
            $ini[$section][$key] = $value
        }
        else {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $line
        }
    }

    return $ini
}

function Set-IniContent($ini, $filePath) {
    $str = @()

    foreach ($section in $ini.GetEnumerator()) {
        if ($section -ne ';ItIsNotAFuckingSection;') {
            $str += "[" + ($section.Key -replace '\|\|ps\d+$', '') + "]"
        }
        foreach ($keyvaluepair in $section.Value.GetEnumerator()) {
            if ($keyvaluepair.Key -match "^;NotSection\d+$") {
                $str += $keyvaluepair.Value
            }
            else {
                $str += $keyvaluepair.Key + "=" + $keyvaluepair.Value
            }
        }
    }

    $finalStr = $str -join [System.Environment]::NewLine

    $finalStr | Out-File -filePath $filePath -Force -Encoding unicode
}

# ---------------------------------------------------------------------------- #
#                                    Actions                                   #
# ---------------------------------------------------------------------------- #

function WriteTo {
    param(
        [Parameter()]
        [int]$index,
        [Parameter()]
        $param1,
        [Parameter()]
        $param2,
        [Parameter()]
        $param3
    )
    $Ini = Get-IniContent -filePath $file1

    $Ini["$global:editingSectionPrefix$index"]["LeftMouseUpAction"] = $param2
    $Ini["$global:editingSectionPrefix$($index)Icon"]["ImageName"] = "`"$param3.png`""
    if ($global:editingPrefix -match 'W') {
        $Ini["$global:editingSectionPrefix$($index)Text"]["Text"] = $param1
    }

    Set-IniContent -ini $Ini -filePath $file1

    $RmAPI.Bang("[!WriteKeyValue Variables $editingPrefix$index `"`"`"$param1`"`"`" `"$file2`"][!SetVariable $editingPrefix$index `"`"`"$param1`"`"`"][!Updatemetergroup DynamicName][!redraw][!UpdateMEasure Auto_Refresh:M]")
}

function WriteSwap($index, $dir) {
    $swapIndex = $index + $dir
    if ($swapIndex -in 1..$global:editingCount) {
        $Ini = Get-IniContent -filePath $file1

        $Ini["$global:editingSectionPrefix$index"]["LeftMouseUpAction"],$Ini["$global:editingSectionPrefix$($index)Icon"]["ImageName"],$Ini["$global:editingSectionPrefix$swapIndex"]["LeftMouseUpAction"],$Ini["$global:editingSectionPrefix$($swapIndex)Icon"]["ImageName"] = $Ini["$global:editingSectionPrefix$swapIndex"]["LeftMouseUpAction"],$Ini["$global:editingSectionPrefix$($swapIndex)Icon"]["ImageName"],$Ini["$global:editingSectionPrefix$index"]["LeftMouseUpAction"],$Ini["$global:editingSectionPrefix$($index)Icon"]["ImageName"]
        if ($global:editingPrefix -match 'W') {
            $Ini["$global:editingSectionPrefix$($index)Text"]["Text"],$Ini["$global:editingSectionPrefix$($swapIndex)Text"]["Text"] = $Ini["$global:editingSectionPrefix$($swapIndex)Text"]["Text"],$Ini["$global:editingSectionPrefix$($index)Text"]["Text"]
        }

        Set-IniContent -ini $Ini -filePath $file1

        $RmAPI.Bang("[!WriteKeyValue Variables $editingPrefix$index `"`"`"$($RmAPI.VariableStr("$editingPrefix$swapIndex"))`"`"`" `"$file2`"][!WriteKeyValue Variables $editingPrefix$swapIndex `"`"`"$($RmAPI.VariableStr("$editingPrefix$index"))`"`"`" `"$file2`"]")
        $RmAPI.Bang("[!SetVariable $editingPrefix$index `"`"`"$($RmAPI.VariableStr("$editingPrefix$swapIndex"))`"`"`"][!SetVariable $editingPrefix$swapIndex `"`"`"$($RmAPI.VariableStr("$editingPrefix$index"))`"`"`"][!Updatemetergroup DynamicName][!Redraw][!UpdateMEasure Auto_Refresh:M]")
    }
}

# function WriteHotkey {
#     param(
#         [Parameter()]
#         $SecNum,
#         [Parameter()]
#         $hotkey,
#         [Parameter()]
#         $hotkeyString
#     )
    
#     # $Ini = Get-IniContent -filePath $file3
#     $global:arrayKeyS[$SecNum-1] = $hotkeyString
#     $global:arrayKey[$SecNum-1] = $hotkey

#     Set-IniContent -ini $Ini -filePath $file3
#     WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)

#     # $RmAPI.Bang('[!UpdateMeasure Auto_Refresh:M "#JaxCore\Main"][!Refresh "#JaxCore\Main"]')
# }

# function WriteAdd {
#     $global:t++

#     $global:arrayName.Add("Blank action")
#     $global:arrayAction.Add("[!Log `"This is a blank action`"]")
#     $global:arrayIcon.Add("folder_png")
#     $global:arrayKey.Add("")
#     $global:arrayKeyS.Add("Edit Hotkey")
    
#     WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)
# }

# function WriteRemove {
#     param(
#         [Parameter()]
#         $startingIndex
#     )
    
#     for ($i=$startingIndex;$i -le ($global:t-1);$i++) {
#         $RmAPI.Log("$($global:arrayName[$i-1]) -> $($global:arrayName[$i])")
#         $global:arrayName[$i-1] = $global:arrayName[$i]
#         $global:arrayAction[$i-1] = $global:arrayAction[$i]
#         $global:arrayIcon[$i-1] =  $global:arrayIcon[$i]
#         $global:arrayKey[$i-1] = $global:arrayKey[$i]
#         $global:arrayKeyS[$i-1] = $global:arrayKeyS[$i]
#     }
#     $global:t = $global:t - 1
#     WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)
#     $RmAPI.Bang('[!Refresh]')
# }

# function WriteSwap {
#     param(
#         [Parameter()]
#         $i1,
#         [Parameter()]
#         $i2
#     )

#     $i1--
#     $i2--
    
#     $RmAPI.Log("$($global:arrayName[$i1]) <-> $($global:arrayName[$i2])")
#     $global:arrayName[$i1], $global:arrayAction[$i1], $global:arrayIcon[$i1], $global:arrayKey[$i1], $global:arrayKeyS[$i1], $global:arrayName[$i2], $global:arrayAction[$i2], $global:arrayIcon[$i2], $global:arrayKey[$i2], $global:arrayKeyS[$i2] = $global:arrayName[$i2], $global:arrayAction[$i2], $global:arrayIcon[$i2], $global:arrayKey[$i2], $global:arrayKeyS[$i2], $global:arrayName[$i1], $global:arrayAction[$i1], $global:arrayIcon[$i1], $global:arrayKey[$i1], $global:arrayKeyS[$i1]
#     WriteAll -arg1 $global:t -arg2 ($global:t+1) -arg3 ($global:t+2)
#     $RmAPI.Bang('[!Refresh]')
# }