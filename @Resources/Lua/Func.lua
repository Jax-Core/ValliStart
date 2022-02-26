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
        local function find_value(tab, val)
            for index, value in ipairs(tab) do
                if value:find(val) then
                    return true
                end
            end

            return false
        end

        for i = 1, 6 do
            if SKIN:GetVariable('Module' .. i) == 'None' then
                if i ~= 0 then
                    SKIN:Bang('!HideMeter', 'Divider' .. (i - 1))
                end
            end
            ModuleArray[i] = SKIN:GetVariable('Module' .. i-1)
        end
        if find_value(ModuleArray, 'Music') then
            PlayerProperty = PipeToTable(SKIN:GetVariable('PlayerProperties'))
            PlayPauseMeterStyle = SKIN:GetVariable('PlayPauseMeterStyle')
            if PlayPauseMeterStyle == nil then PlayPauseMeterStyle = '' end

            if SKIN:GetVariable('MediaType') == 'Auto' then
                SKIN:Bang('[!Delay 100][!CommandMeasure Func checkMediaAuto()]')
            else
                SKIN:Bang('[!Delay 100][!CommandMeasure Func checkMediaModern()]')
            end
        end
        if find_value(ModuleArray, 'Volume') then
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
            MoveX = 0
            MoveY = 0
            AnchorX = '50%'
            AnchorY = '50%'
        elseif pos ~= 'Custom' then
            local posX = string.sub(pos, 2, 2)
            local posY = string.sub(pos, 1, 1)
            local xpad = SKIN:GetVariable('xpad')
            local ypad = SKIN:GetVariable('ypad')
            local MonitorIndex = SKIN:GetVariable('MonitorIndex')
            local taskbar = SKIN:GetVariable('PreserveTaskbarSpace')
            local sax =SKIN:GetVariable('SCREENAREAX@'..MonitorIndex)
            local say = SKIN:GetVariable('SCREENAREAY@'..MonitorIndex)
            local saw = SKIN:GetVariable('SCREENAREAWIDTH@'..MonitorIndex)
            local sah = SKIN:GetVariable('SCREENAREAHEIGHT@'..MonitorIndex)
            MoveX = 0
            MoveY = 0
            AnchorX = 0
            AnchorY = 0

            if posX == 'L' then MoveX = sax + xpad
            elseif posX == 'C' then
                MoveX = (sax + saw/2)
                AnchorX = "50%"
            elseif posX == 'R' then
                MoveX = (sax + saw - xpad)
                AnchorX = "100%"
            end

            if posY == 'T' then MoveY = say + ypad
            elseif posY == 'C' then
                MoveY = (say + sah/2)
                AnchorY = "50%"
            elseif posY == 'B' then
                MoveY = (say + sah - ypad - taskbar * 40)
                AnchorY = "100%"
            end

            SKIN:Bang('!SetWindowPosition ' .. MoveX .. ' ' .. MoveY .. ' ' .. AnchorX .. ' ' .. AnchorY)
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
            MoveX = xpos
            MoveY = ypos
            AnchorX = '50%'
            AnchorY = '50%'
        else
            SKIN:Bang('[!SetWindowPosition ' .. xpos .. ' ' .. ypos .. ' 50% 50%]')
        end
    end
end

function saveLocation()
    MoveX = tonumber(SKIN:GetX())
    MoveY = tonumber(SKIN:GetY())
    AnchorX = 0
    AnchorY = 0
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
        bang = bang .. '[!SetWindowPosition ' .. MoveX + (resultantTN / 100 - 1) * AnimationDisplacement .. ' ' .. MoveY .. ' ' .. AnchorX .. ' ' .. AnchorY .. ']'
    elseif AniDir == 'Right' then
        bang = bang .. '[!SetWindowPosition ' .. MoveX + (1 - resultantTN / 100) * AnimationDisplacement .. ' ' .. MoveY .. ' ' .. AnchorX .. ' ' .. AnchorY .. ']'
    elseif AniDir == 'Top' then
        bang = bang .. '[!SetWindowPosition ' .. MoveX .. ' ' .. MoveY + (resultantTN / 100 - 1) * AnimationDisplacement .. ' ' .. AnchorX .. ' ' .. AnchorY .. ']'
    elseif AniDir == 'Bottom' then
        bang = bang .. '[!SetWindowPosition ' .. MoveX .. ' ' .. MoveY + (1 - resultantTN / 100) * AnimationDisplacement .. ' ' .. AnchorX .. ' ' .. AnchorY .. ']'
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

function InitMultiSlider(handlerName)
    local handler = SKIN:GetMeter(handlerName)
    local handlerP = PipeToTable(handler:GetOption('SliderProperties'))
    S_Ori = handlerP[1]
    if S_Ori == 'X' then
        S_Pos = handler:GetX()
    else
        S_Pos = handler:GetY()
    end
    S_Dim = SKIN:GetMeasure(handlerP[2]):GetValue()
    S_Dim = S_Dim
    S_Inv = handlerP[3] -- Invert?
    S_DrB = handlerP[4] -- Drag action yes no?
    S_Mea = handlerP[5] -- Measure name
    S_PMe = handlerP[6] -- Percentage measure name
    S_GNa = handlerP[7] -- Group name
    S_DrA = handlerP[8] -- Drag action
    S_UpA = handlerP[9] -- Up action
    -- print(S_Ori, S_Pos, S_Dim, S_Inv, S_DrB, S_Mea, S_PMe, S_GNa, S_DrA, S_UpA)
    local SliderPercent = SKIN:GetMeasure(S_Mea):GetValue()
    if S_DrA ~= nil then S_DrA = S_DrA:gsub('%$MeasureName%$', S_Mea) end
    if S_UpA ~= nil then S_UpA = S_UpA:gsub('%$MeasureName%$', S_Mea) end
    SKIN:Bang('[!SetOption '..S_PMe..' Formula '..SliderPercent..'][!CommandMeasure MeasureMouse "Start"]')
end
function DragMultiSlider(posX)
    local function round(num, idp)
        assert(tonumber(num), 'Round expects a number.')
        local mult = 10 ^ (idp or 0)
        if num >= 0 then
            return math.floor(num * mult + 0.5) / mult
        else
            return math.ceil(num * mult - 0.5) / mult
        end
    end
    local function clamp(num, lower, upper)
        assert(num and lower and upper, 'error: Clamp(num, lower, upper)')
        return math.max(lower, math.min(upper, num))
    end
    local rawPer = ((posX-S_Pos)*100/(((S_Pos)+S_Dim)-(S_Pos)))
    S_ReP = round(clamp(rawPer, 0, 100), 0)
    local bang = ''
    if S_DrB == '1' then
        bang = S_DrA:gsub('%$DragPercentage%$', S_ReP)
    end
    SKIN:Bang(bang..'[!SetOption '..S_PMe..' Formula '..S_ReP..'][!UpdateMeasureGroup '..S_GNa..'][!UpdateMeterGroup '..S_GNa..'][!Redraw]')
end

function TermMultiSlider()
    local bang = ''
    if S_UpA ~= '' and S_UpA ~= nil then
        bang = S_UpA:gsub('%$DragPercentage%$', S_ReP)
    end
    SKIN:Bang('[!CommandMeasure MeasureMouse "Stop"][!SetOption '..S_PMe..' Formula "'..S_Mea..'"]'..bang..'[!UpdateMeasureGroup '..S_GNa..'][!UpdateMeterGroup '..S_GNa..'][!Redraw]')
end

function FormatSeconds(measureName)
    local secondsArg = SKIN:GetMeasure(measureName):GetValue()
    local date = os.date("!%X", secondsArg):gsub('00%:(.*)', '%1')

	return date
end
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

    local bang = ''
    if checkingPlayerState ~= 0 then
        -- ----------------------------- sets the player ---------------------------- --
        local isW = ''
        local ntW = 'W'
        if checkingPlayer == 'WebNowPlaying' then
            isW = 'W'
            ntW = ''
        end
        bang = bang .. '[!EnableMeasureGroup '..isW..'NP][!DisableMeasureGroup '..ntW..'NP]'
        bang = bang .. '[!SetVariable PlayerType '..isW..'NP]'

        -- ----------------------- apply media player settings ---------------------- --
        if SKIN:GetVariable('FetchImage') == 0 then
            bang = bang .. '[!DisableMeasure '..isW..'npCover]'
        end
        local propertyList = {'Shuffle', 'Repeat', 'Heart' ,'Prog'}
        for i = 1, 4 do
            if PlayerProperty[i] == '0' then
                bang = bang .. '[!DisableMeasureGroup '..propertyList[i]..']'
            end
        end
    else
        -- ------------ if the player is not active, disable all measures ----------- --
        bang = bang .. '[!DisableMeasureGroup NP][!DisableMeasureGroup WNP]'
    end

    bang = bang .. '[!SetVariable NowPlayingMedia ' .. checkingPlayer .. ']'
    bang = bang .. '[!UpdateMeasureGroup Music]'

    if checkingPlayerState == 1 then bang = bang .. '[!SetOptionGroup CtrlPlayPause MeterStyle "'..PlayPauseMeterStyle..'Pause"][!UpdateMeterGroup CtrlPlayPause]'
    elseif checkingPlayerState == 2 then bang = bang .. '[!SetOptionGroup CtrlPlayPause MeterStyle "'..PlayPauseMeterStyle..'Play"][!UpdateMeterGroup CtrlPlayPause]'
    elseif checkingPlayerState == 0 then bang = bang .. '[!SetOptionGroup CtrlPlayPause MeterStyle "'..PlayPauseMeterStyle..'Play"][!UpdateMeterGroup CtrlPlayPause]' end

    if checkingPlayerState == 0 and PlayerProperty[5] == 0 then
        bang = bang .. '[!HideMeterGroup Music]'
    else
        bang = bang .. '[!ShowMeterGroup Music]'
    end

    bang = bang .. '[!UpdateMeter *][!Redraw]'
    SKIN:Bang(bang)
end

function checkMediaModern()
    local bang = ''

    checkingPlayerState = SKIN:GetMeasure('stateModern'):GetValue()

    if SKIN:GetVariable('FetchImage') == 0 then
        bang = bang .. '[!DisableMeasure modernCover]'
    end
    local propertyList = {'Shuffle', 'Repeat', 'Heart' ,'Prog'}
    for i = 1, 4 do
        if PlayerProperty[i] == '0' then
            bang = bang .. '[!DisableMeasureGroup '..propertyList[i]..']'
        end
    end

    bang = bang .. '[!UpdateMeasureGroup Music]'

    if checkingPlayerState == 1 then bang = bang .. '[!SetOptionGroup CtrlPlayPause MeterStyle "'..PlayPauseMeterStyle..'Pause"][!UpdateMeterGroup CtrlPlayPause]'
    elseif checkingPlayerState == 2 then bang = bang .. '[!SetOptionGroup CtrlPlayPause MeterStyle "'..PlayPauseMeterStyle..'Play"][!UpdateMeterGroup CtrlPlayPause]'
    elseif checkingPlayerState == 0 then bang = bang .. '[!SetOptionGroup CtrlPlayPause MeterStyle "'..PlayPauseMeterStyle..'Play"][!UpdateMeterGroup CtrlPlayPause]' end

    if checkingPlayerState == 0 then
        bang = bang .. '[!HideMeterGroup Music]'
    else
        bang = bang .. '[!ShowMeterGroup Music]'
    end

    bang = bang .. '[!UpdateMeter *][!Redraw]'
    SKIN:Bang(bang)
end

-- -------------------------------------------------------------------------- --
--                                    Util                                    --
-- -------------------------------------------------------------------------- --


function PipeToTable(str)
    local o = {}
    for m in str:gmatch('[^%|]+') do
        table.insert(o, m)
    end
    return o
end

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

function trim(Text, Match, Replace)
	return Text:gsub(Match, Replace)
end

function digit(Text, Digit, Digit2)
    Digit2 = Digit2 or Digit
    return Text:sub(Digit, Digit2)
end

function returnCenterString(MinimumWidth)
    if MinimumWidth <= SKIN:GetW() then
        return 'Center'
    else
        return 'Left'
    end
end
