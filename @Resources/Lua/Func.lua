function Initialize()

    -- --------- change divider visibility and music measure disabilitiy -------- --

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

    -- ------------------------------- positioning ------------------------------ --
    
    local pos = SKIN:GetVariable('Position')
    if pos == 'Custom' then
        SKIN:Bang('!Draggable', '1')
    elseif pos == 'MousePosition' then
        SKIN:Bang('[!SetWindowPosition 50% 50% 50% 50%]')
    else
        local posX = string.sub(pos, 2, 2)
        local posY = string.sub(pos, 1, 1)
        local pad = SKIN:GetVariable('ScreenPadding')
        local saw = SKIN:GetVariable('SCREENAREAWIDTH')
        local sah = SKIN:GetVariable('SCREENAREAHEIGHT')
        local moveX = 0
        local moveY = 0
        local anchorX = 0
        local anchorY = 0
        
        if posX == 'L' then moveX = pad
        elseif posX == 'C' then
            moveX = (saw/2)
            anchorX = "50%"
        elseif posX == 'R' then
            moveX = (saw-pad)
            anchorX = "100%"
        end
        
        if posY == 'T' then moveY = pad
        elseif posY == 'C' then
            moveY = (sah/2)
            anchorY = "50%"
        elseif posY == 'B' then
            moveY = (sah-pad)
            anchorY = "100%"
        end

        SKIN:Bang('!SetWindowPosition '..moveX..' '..moveY..' '..anchorX..' '..anchorY)
    end
    SKIN:Bang('[!CommandMeasure Func valliMoveMouse(1,1) ValliStart\\Main]')
end

function valliMoveMouse(xpos, ypos)
    local isOff = SKIN:GetMeasure('mToggle'):GetValue()
    if isOff ~= 0 then
        SKIN:Bang('[!SetWindowPosition '..xpos..' '..ypos..' 50% 50%]')
    end
end