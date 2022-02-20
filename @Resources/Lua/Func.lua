MediaPlayers = { 'AIMP', 'CAD', 'WMP', 'iTunes', 'Winamp', 'WebNowPlaying' }
GlobalInit = 0
GlobalGeneratedProgramList = 0

function Initialize()

    -- --------- change divider visibility and music measure disabilitiy -------- --
    if SKIN:GetVariable('IsPageAccessory') == nil and SKIN:GetVariable('IsBlock') == nil then
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
            if SKIN:GetVariable('Module' .. i) == 'None' then
                SKIN:Bang('!HideMeter', 'Divider' .. (i - 1))
            end
            ModuleArray[i] = SKIN:GetVariable('Module' .. i)
        end
        if has_value(ModuleArray, 'Music') then
            if SKIN:GetVariable('MediaType') == 'Auto' then
                SKIN:Bang('[!Delay 100][!CommandMeasure Func checkMediaAuto()]')
            else
                SKIN:Bang('[!Delay 100][!CommandMeasure Func checkMediaModern()]')
            end
        end
        if has_value(ModuleArray, 'Volume') then
            local deviceList = SKIN:GetMeasure('MeasureDeviceList'):GetStringValue()

            local i = 1
            for name in string.gmatch(deviceList, '{[.%d]*}.{[%x-]*}: ([^\n]*)') do
                local action = '[!CommandMeasure "MeasureWin7Audio" "SetOutPutIndex ' .. i .. '"][!Refresh]'
                if i == 1 then index = '' else index = i end
                SKIN:Bang('!SetOption', 'Rainmeter', 'ContextTitle' .. index, name)
                SKIN:Bang('!SetOption', 'Rainmeter', 'ContextAction' .. index, action)
                i = i + 1
            end
        end
    end
    -- ------------------------------- positioning ------------------------------ --

    pos = SKIN:GetVariable('Position')
    local function positionMenu()
        if pos == 'Custom' then
            SKIN:Bang('!Draggable', '1')
        else
            SKIN:Bang('!Draggable', '0')
        end
        if pos == 'MousePosition' then
            moveX = 0
            moveY = 0
            anchorX = '50%'
            anchorY = '50%'
        elseif pos ~= 'Custom' then
            local posX = string.sub(pos, 2, 2)
            local posY = string.sub(pos, 1, 1)
            local xpad = SKIN:GetVariable('xpad')
            local ypad = SKIN:GetVariable('ypad')
            local saw = SKIN:GetVariable('SCREENAREAWIDTH')
            local sah = SKIN:GetVariable('SCREENAREAHEIGHT')
            moveX = 0
            moveY = 0
            anchorX = 0
            anchorY = 0

            if posX == 'L' then moveX = xpad
            elseif posX == 'C' then
                moveX = (saw / 2)
                anchorX = "50%"
            elseif posX == 'R' then
                moveX = (saw - xpad)
                anchorX = "100%"
            end

            if posY == 'T' then moveY = ypad
            elseif posY == 'C' then
                moveY = (sah / 2)
                anchorY = "50%"
            elseif posY == 'B' then
                moveY = (sah - ypad)
                anchorY = "100%"
            end

            SKIN:Bang('!SetWindowPosition ' .. moveX .. ' ' .. moveY .. ' ' .. anchorX .. ' ' .. anchorY)
        end
    end

    if SKIN:GetVariable('IsPageAccessory') == nil and SKIN:GetVariable('IsBlock') == nil then
        positionMenu()
    elseif SKIN:GetVariable('IsPageAccessory') ~= nil and pos ~= 'MousePosition' then
        positionMenu()
        -- elseif SKIN:GetVariable('IsPageAccessory') ~= nil and pos == 'MousePosition' then
        --     saveLocation()
    end

    -- ------------------------- handle animation toggle ------------------------ --

    if tonumber(SKIN:GetVariable('Animated')) == 1 then
        AniSteps = tonumber(SKIN:GetVariable('AniSteps'))
        TweenInterval = 100 / AniSteps
        AnimationDisplacement = SKIN:GetVariable('AnimationDisplacement')
        AniDir = SKIN:GetVariable('AniDir')
        dofile(SELF:GetOption("ScriptFile"):match("(.*[/\\])") .. "tween.lua")
        subject = {
            TweenNode = 0
        }
        t = tween.new(AniSteps, subject, { TweenNode = 100 }, SKIN:GetVariable('Easetype'))
    end
end

function valliMoveMouse(xpos, ypos)
    local isOff = SKIN:GetMeasure('mToggle'):GetValue()
    if isOff ~= 0 then
        if tonumber(SKIN:GetVariable('Animated')) == 1 then
            moveX = xpos
            moveY = ypos
            anchorX = '50%'
            anchorY = '50%'
        else
            SKIN:Bang('[!SetWindowPosition ' .. xpos .. ' ' .. ypos .. ' 50% 50%]')
        end
    end
end

function saveLocation()
    moveX = tonumber(SKIN:GetX())
    moveY = tonumber(SKIN:GetY())
    anchorX = 0
    anchorY = 0
end

function initActions(type, reset)
    if reset == 1 then
        GlobalInit = 0
        do return end
    end
    if tonumber(SKIN:GetVariable('BackgroundMod')) == 1 and SKIN:GetVariable('IsPageAccessory') == nil then
        if type == 1 and GlobalInit == 0 then
            SKIN:Bang('[!ActivateConfig "ValliStart\\Main\\Accessories\\Unload"]')
        elseif type == -1 and GlobalInit == 0 then
            SKIN:Bang('[!DeactivateConfig "ValliStart\\Main\\Accessories\\Unload"]')
        end
    else
        if type == -1 and SKIN:GetVariable('IsPageAccessory') ~= nil then
            if tonumber(SKIN:GetVariable('BackgroundMod')) == 1 then
                SKIN:Bang('[!DeactivateConfig "ValliStart\\Main\\Accessories\\Unload"]')
            end
            SKIN:Bang('[!CommandMeasure Func "initActions(2, 1)" "ValliStart\\Main"][!DeactivateConfig]')
        end
    end
end

function tweenAnimation(dir)
    if dir == 'in' then
        local complete = t:update(1)
    else
        local complete = t:update(-1)
    end
    resultantTN = subject.TweenNode
    if resultantTN > 100 then resultantTN = 100 elseif resultantTN < 0 then resultantTN = 0 end
    local bang = '[!SetTransparency ' .. (resultantTN / 100 * 255) .. ']'
    if AniDir == 'Left' then
        bang = bang .. '[!SetWindowPosition ' .. moveX + (resultantTN / 100 - 1) * AnimationDisplacement .. ' ' .. moveY .. ' ' .. anchorX .. ' ' .. anchorY .. ']'
    elseif AniDir == 'Right' then
        bang = bang .. '[!SetWindowPosition ' .. moveX + (1 - resultantTN / 100) * AnimationDisplacement .. ' ' .. moveY .. ' ' .. anchorX .. ' ' .. anchorY .. ']'
    elseif AniDir == 'Top' then
        bang = bang .. '[!SetWindowPosition ' .. moveX .. ' ' .. moveY + (resultantTN / 100 - 1) * AnimationDisplacement .. ' ' .. anchorX .. ' ' .. anchorY .. ']'
    elseif AniDir == 'Bottom' then
        bang = bang .. '[!SetWindowPosition ' .. moveX .. ' ' .. moveY + (1 - resultantTN / 100) * AnimationDisplacement .. ' ' .. anchorX .. ' ' .. anchorY .. ']'
    end
    bang = bang .. '[!UpdateMeasure ActionTimer]'
    SKIN:Bang(bang)
end

function goToPage(variant)
    GlobalInit = 1
    local saveLocation = SKIN:GetVariable('ROOTCONFIGPATH') .. 'Main\\Accessories\\Page\\Main.ini'
    local pageW = SKIN:GetW()
    local pageH = SKIN:GetH()
    local scale = SKIN:GetVariable('Scale')
    if variant == "ProgramList" and GlobalGeneratedProgramList == 0 then
        local function DIV(a, b)
            return (a - a % b) / b
        end

        local rows = DIV((pageH - 65 * scale), (47 * scale))
        SKIN:Bang('[!CommandMeasure FuncPS "GenerateProgramList -rows ' .. rows .. '"]')

        GlobalGeneratedProgramList = 1
    else
        if variant == "DownloadsList" then
            local function DIV(a, b)
                return (a - a % b) / b
            end

            local rows = DIV((pageH - 65 * scale), (47 * scale))
            SKIN:Bang('[!CommandMeasure FuncPS "GenerateDownloadsList -rows ' .. rows .. '"]')
        end
    end

    SKIN:Bang('[!WriteKeyValue Variables W ' .. pageW .. ' "' .. saveLocation .. '"][!WriteKeyValue Variables H ' .. pageH .. ' "' .. saveLocation .. '"][!WriteKeyValue Variables Sec.Variant ' .. variant .. ' "' .. saveLocation .. '"][!Activateconfig "ValliStart\\Main\\Accessories\\Page"]')
    if pos == 'MousePosition' then
        SKIN:Bang('[!Move ' .. SKIN:GetX() .. ' ' .. SKIN:GetY() .. ' "ValliStart\\Main\\Accessories\\Page"][!CommandMeasure Func "saveLocation()" "ValliStart\\Main\\Accessories\\Page"]')
    end
end

function LaunchPopup(posX, posY, variant)
    posX = posX + SKIN:GetX()
    posY = posY + SKIN:GetY()
    local saveLocation = SKIN:GetVariable('ROOTCONFIGPATH') .. 'Main\\Accessories\\Popup\\Main.ini'
    SKIN:Bang('[!WriteKeyValue Variables Sec.LastX ' .. posX .. ' "' .. saveLocation .. '"][!WriteKeyValue Variables Sec.LastY ' .. posY .. ' "' .. saveLocation .. '"][!WriteKeyValue Variables Sec.Variant ' .. variant .. ' "' .. saveLocation .. '"][!WriteKeyValue Variables Sec.Variant ' .. variant .. ' "' .. saveLocation .. '"][!ZPos 1][!DisableMeasure mToggle][!Activateconfig "ValliStart\\Main\\Accessories\\Popup"]')
end

-- function initMultiSlider(index)
--     local AppVolPer = SKIN:GetMeasure('AppVolPer'..index):GetValue()
--     GlobalMixerVolumeIndex = index
--     SKIN:Bang('[!SetOption AppVolPer'..index..' Formula '..AppVolPer..'][!CommandMeasure MeasureMouse "Start"]')
-- end
-- function dragMultiSlider(posX)
--     local function round(num, idp)
--         assert(tonumber(num), 'Round expects a number.')
--         local mult = 10 ^ (idp or 0)
--         if num >= 0 then
--             return math.floor(num * mult + 0.5) / mult
--         else
--             return math.ceil(num * mult - 0.5) / mult
--         end
--     end
--     local function clamp(num, lower, upper)
--         assert(num and lower and upper, 'error: Clamp(num, lower, upper)')
--         return math.max(lower, math.min(upper, num))
--     end
--     local index = GlobalMixerVolumeIndex
--     local globalW = SKIN:GetVariable('W')
--     local scale = SKIN:GetVariable('scale')
--     local SliderX = SKIN:GetMeter(index):GetX()
--     local SliderW = globalW - (150+22+75) * scale
--     local rawPer = ((posX-SliderX)*100/(((SliderX)+SliderW)-(SliderX)))
--     local resultantPer = round(clamp(rawPer, 0, 100), 0)
--     SKIN:Bang('[!SetOption AppVolPer'..index..' Formula '..resultantPer..'][!CommandMeasure AppVol'..index..' "SetVolume '..resultantPer..'"][!UpdateMeter *][!UpdateMeasureGroup UpdateWhenChange][!Redraw]')
-- end

-- function termMultiSlider()
--     local index = GlobalMixerVolumeIndex
--     SKIN:Bang('[!SetOption AppVolPer'..index..' Formula "Round(AppVol'..index..' * 100)"][!CommandMeasure MeasureMouse "Stop"][!UpdateMeter *][!UpdateMeasureGroup UpdateWhenChange][!Redraw]')
-- end
-- -------------------------------------------------------------------------- --
--                                    Media                                   --
-- -------------------------------------------------------------------------- --

function checkMediaAuto()
    currentPlayer = nil
    for i = 1, 6 do
        if SKIN:GetMeasure('state' .. MediaPlayers[i]):GetValue() == 1 then
            currentPlayer = MediaPlayers[i]
            break
        end
    end
    if currentPlayer == nil then
        for i = 1, 6 do
            if SKIN:GetMeasure('state' .. MediaPlayers[i]):GetValue() == 2 then
                currentPlayer = MediaPlayers[i]
                break
            end
        end
    end
    if currentPlayer == nil then currentPlayer = SKIN:GetVariable('NowPlayingMedia') end

    checkingPlayer = currentPlayer

    checkingPlayerState = SKIN:GetMeasure('state' .. checkingPlayer):GetValue()

    -- print(checkingPlayer, checkingPlayerState)
    if checkingPlayerState ~= 0 then
        if checkingPlayer == 'WebNowPlaying' then
            SKIN:Bang('[!EnableMeasureGroup WNP][!DisableMeasureGroup NP]')
            SKIN:Bang('[!SetVariable PlayerType WNP]')

            if SKIN:GetVariable('FetchImage') == 0 then
                SKIN:Bang('[!DisableMeasure wnpCover]')
            end
        else
            SKIN:Bang('[!EnableMeasureGroup NP][!DisableMeasureGroup WNP]')
            SKIN:Bang('[!SetVariable PlayerType NP]')

            if SKIN:GetVariable('FetchImage') == 0 then
                SKIN:Bang('[!DisableMeasure npCover]')
            end
        end
    else
        SKIN:Bang('[!DisableMeasureGroup NP][!DisableMeasureGroup WNP]')
    end

    SKIN:Bang('[!SetVariable NowPlayingMedia ' .. checkingPlayer .. ']')
    SKIN:Bang('[!UpdateMeasureGroup Music]')

    if checkingPlayerState == 1 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Pause"][!UpdateMeter PlayPause]')
    elseif checkingPlayerState == 2 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
    elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]') end

    if checkingPlayerState == 0 then
        SKIN:Bang('[!HideMeterGroup Music]')
    else
        SKIN:Bang('[!ShowMeterGroup Music]')
    end

    SKIN:Bang('[!UpdateMeter *][!Redraw]')
end

function checkMediaModern()

    checkingPlayerState = SKIN:GetMeasure('stateModern'):GetValue()

    if SKIN:GetVariable('FetchImage') == 0 then
        SKIN:Bang('[!DisableMeasure modernCover]')
    end

    SKIN:Bang('[!UpdateMeasureGroup Music]')

    if checkingPlayerState == 1 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Pause"][!UpdateMeter PlayPause]')
    elseif checkingPlayerState == 2 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
    elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]') end

    if checkingPlayerState == 0 then
        SKIN:Bang('[!HideMeterGroup Music]')
    else
        SKIN:Bang('[!ShowMeterGroup Music]')
    end

    SKIN:Bang('[!UpdateMeter *][!Redraw]')
end

-- -------------------------------------------------------------------------- --
--                                    Util                                    --
-- -------------------------------------------------------------------------- --

function returnBool(Variable, Match, ReturnStringT, ReturnStringF)

    local Var = SKIN:GetVariable(Variable)

    local ReturnStringT = ReturnStringT or '1'
    local ReturnStringF = ReturnStringF or '0'
    if Var == Match then
        return (ReturnStringT)
    else
        return (ReturnStringF)
    end
end

function returnCenterString(MinimumWidth)
    if MinimumWidth <= SKIN:GetW() then
        return 'Center'
    else
        return 'Left'
    end
end
