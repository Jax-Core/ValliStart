[Variables]
@includeMusicVars=#SKINSPATH##Skin.Name#\Main\Modules\Vars\Music.inc
Sec.SaveLocation2=#SKINSPATH##Skin.Name#\Main\Modules\Vars\Music.inc

[Mediatype:]
0Act=[!WriteKeyValue Variables MediaType "Auto" "#Sec.SaveLocation2#"]
1Act=[!WriteKeyValue Variables MediaType "Modern" "#Sec.SaveLocation2#"]

[FetchImage]
SaveLocation=#Sec.SaveLocation2#