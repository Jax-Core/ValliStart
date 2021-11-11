function Initialize()
    saveLocation = SKIN:GetVariable('Sec.SaveLocation2')
    includeFile = SKIN:GetVariable('SKINSPATH')..'..\\CoreData\\ValliStart\\Include.inc'
end

-- -------------------------------------------------------------------------- --
--                                   Lua WKV                                  --
-- -------------------------------------------------------------------------- --
function WriteKeyValue(section, key, value, filePath)
    filePath = filePath:gsub('^%s-(.+)%s-$', '%1')
    if not filePath:lower():match('^%w%:.*') then
        filePath = SKIN:GetVariable('CURRENTPATH') .. filePath
    end
    local file=assert(io.open(filePath, 'r'), 'File path invalid!')
    file:close()
    local content = ReadIni(filePath)
    if table.contains(content.SectionOrder, section, 'value') then
        if table.contains(content.KeyOrder[section], key, 'value') then
            content.INI[section][key] = value
        else
            table.insert(content.KeyOrder[section], key)
            content.INI[section][key] = value
        end
    else
        table.insert(content.SectionOrder, section)
        content.INI[section] = {}
        content.KeyOrder[section]={}
        table.insert(content.KeyOrder[section], key)
        content.INI[section][key] = value
    end
    WriteIni(content, filePath)
end

function ReadIni(inputfile)
    local file = assert(io.open(inputfile, 'r'), 'Unable to open ' .. inputfile)
    local tbl, section = {}
    local sectionReadOrder, keyReadOrder = {}, {}
    local num = 0
    for line in file:lines() do
        num = num + 1
        if not line:match('^%s-;') then
            local key, command = line:match('^([^=]+)=(.+)')
            if line:match('^%s-%[.+') then
                section = line:match('^%s-%[([^%]]+)')
                if not tbl[section] then
                    tbl[section]={}
                    table.insert(sectionReadOrder, section)
                    if not keyReadOrder[section] then keyReadOrder[section]={} end
                end
            elseif key and command and section then
                tbl[section][key:match('^%s*(%S*)%s*$')] = command:match('^%s*(.-)%s*$')
                table.insert(keyReadOrder[section], key)
            elseif #line > 0 and section and not key or command then
                print(num .. ': Invalid property or value.')
            end
        end
    end
    file:close()

    local finalTable={}
    finalTable.INI=tbl
    finalTable.SectionOrder=sectionReadOrder
    finalTable.KeyOrder=keyReadOrder
    return finalTable
end

function WriteIni(intable, outfile)
    local outTable = {}
    for _, v in ipairs(intable.SectionOrder) do
        table.insert(outTable, '['..v..']')
        for _, V in ipairs(intable.KeyOrder[v]) do
            table.insert(outTable, V..'=' .. intable.INI[v][V])
        end
    end
    local file = io.open(outfile, 'w')
    file:write(table.concat(outTable, '\n'))
    file:close()
end

function table.contains(table, value, type)
    if type == "key" then
        for k, _ in pairs(table) do
            if value == k then return true end
        end
    elseif type == "value" then
        for _, v in pairs(table) do
            if value == v then return true end
        end
    end
end

-- -------------------------------------------------------------------------- --
--                                  Functions                                 --
-- -------------------------------------------------------------------------- --

function Edit(name, path, ext, editingHandle)
    editingIndex = editingHandle:gsub('^EditButton', '')
    SKIN:Bang('!WriteKeyValue', 'Variables', 'M'..editingIndex, name, saveLocation)
    WriteKeyValue('Box'..editingIndex, 'LeftMouseUpAction', '["'..path..'"]', includeFile)
    WriteKeyValue('Box'..editingIndex..'Icon', 'ImageName', name..'_'..ext, includeFile)
    SKIN:Bang('!UpdateMEasure', 'Auto_Refresh:M')
    SKIN:Bang('!Refresh')
end

function Remove(initSelection, editingHandle)
    if toggleDelete == nil then toggleDelete = 0 end
    if initSelection == 1 and toggleDelete == 0 then
        toggleDelete = 1
        SKIN:Bang('!SetOptionGroup', 'ActionButton', 'Text', '[\\xF78A]')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'MeterStyle', 'Set.RectButton:S | Sec.Delete:S')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'Fill', 'Fill Color 255,0,0,100')
        SKIN:Bang('!UpdateMeterGroup', 'Actions')
        SKIN:Bang('!Redraw')
    elseif initSelection == 1 and toggleDelete == 1 then
        toggleDelete = 0
        SKIN:Bang('!SetOptionGroup', 'ActionButton', 'Text', '[\\xE70F]')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'MeterStyle', 'Set.RectButton:S | Sec.Edit:S')
        SKIN:Bang('!SetOptionGroup', 'ActionButtonShape', 'Fill', 'Fill Color 0,255,50,100')
        SKIN:Bang('!UpdateMeterGroup', 'Actions')
        SKIN:Bang('!Redraw')
    elseif initSelection == 0 then
        editingIndex = editingHandle:gsub('^EditButton', '')
        SKIN:Bang('!WriteKeyValue', 'Variables', 'M'..editingIndex, 'Select a file...', saveLocation)
        WriteKeyValue('Box'..editingIndex, 'LeftMouseUpAction', '[]', includeFile)
        WriteKeyValue('Box'..editingIndex..'Icon', 'ImageName', '', includeFile)
        SKIN:Bang('!UpdateMEasure', 'Auto_Refresh:M')
        SKIN:Bang('!Refresh')
    end
end