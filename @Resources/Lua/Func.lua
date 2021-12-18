function Initialize()
    local ModuleArray = {}
    local function has_value(tab, val)
        for index, value in ipairs(tab) do
            if value == val then
                return true
            end
        end
    
        return false
    end
    for i = 1, 5 do
        if SKIN:GetVariable('Module'..i) == 'None' then
            SKIN:Bang('!HideMeter', 'Bisector'..(i-1))
        end
        ModuleArray[i] = SKIN:GetVariable('Module'..i)
    end
    if not has_value(ModuleArray, 'Music') then
        SKIN:Bang('[!DisableMeasureGroup Music][!UpdateMeasureGroup Music]')
        print('Disabled all music measures')
    end
end