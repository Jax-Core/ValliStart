mediaPlayers = {'AIMP', 'CAD', 'WMP', 'iTunes', 'Winamp', 'WebNowPlaying'}
-- mediaPlayers = {'CAD', 'WebNowPlaying'}

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
    if has_value(ModuleArray, 'Music') then
        if SKIN:GetVariable('MediaType') == 'Auto' then 
            SKIN:Bang('[!Delay 100][!CommandMeasure Func checkMediaAuto()]') 
        else
            SKIN:Bang('[!Delay 100][!CommandMeasure Func checkMediaModern()]') 
        end
    end

    -- ------------------------------- positioning ------------------------------ --
    
    local pos = SKIN:GetVariable('Position')
    if pos == 'Custom' then
        SKIN:Bang('!Draggable', '1')
    elseif pos == 'MousePosition' then
        moveX = 0
        moveY = 0
        -- moveX = (saw/2)
        -- moveY = (sah/2)
        anchorX = '50%'
        anchorY = '50%'
    else
        local posX = string.sub(pos, 2, 2)
        local posY = string.sub(pos, 1, 1)
        local pad = SKIN:GetVariable('ScreenPadding')
        local saw = SKIN:GetVariable('SCREENAREAWIDTH')
        local sah = SKIN:GetVariable('SCREENAREAHEIGHT')
        moveX = 0
        moveY = 0
        anchorX = 0
        anchorY = 0
        
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

    -- ------------------------- handle animation toggle ------------------------ --

    if tonumber(SKIN:GetVariable('Animated')) == 2 then
        AniSteps = tonumber(SKIN:GetVariable('AniSteps'))
        TweenInterval = 100 / AniSteps
        ScreenPadding = SKIN:GetVariable('ScreenPadding')
        AniDir = SKIN:GetVariable('AniDir')
        dofile(SELF:GetOption("ScriptFile"):match("(.*[/\\])") .. "tween.lua")
        subject = {
            TweenNode = 0
        }
        t = tween.new(AniSteps, subject, {TweenNode=100}, SKIN:GetVariable('Easetype'))
    end
end

function valliMoveMouse(xpos, ypos)
    local isOff = SKIN:GetMeasure('mToggle'):GetValue()
    if isOff ~= 0 then
        if tonumber(SKIN:GetVariable('Animated')) == 2 then
            moveX = xpos
            moveY = ypos
            anchorX = '50%'
            anchorY = '50%'
        else
            SKIN:Bang('[!SetWindowPosition '..xpos..' '..ypos..' 50% 50%]')
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
    local bang = '[!SetVariable TweenNode1 '..resultantTN..'][!SetTransparency '..(resultantTN / 100 * 255)..']'
    if AniDir == 'Left' then
        bang = bang..'[!SetWindowPosition '..moveX + (resultantTN / 100 - 1) * ScreenPadding..' '..moveY..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Right' then
        bang = bang..'[!SetWindowPosition '..moveX + (1 - resultantTN / 100) * ScreenPadding..' '..moveY..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Top' then
        bang = bang..'[!SetWindowPosition '..moveX..' '..moveY + (resultantTN / 100 - 1) * ScreenPadding..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Bottom' then
        bang = bang..'[!SetWindowPosition '..moveX..' '..moveY + (1 - resultantTN / 100) * ScreenPadding..' '..anchorX..' '..anchorY..']'
    end
    bang = bang..'[!UpdateMeasure ActionTimer]'
    SKIN:Bang(bang)
end

-- -------------------------------------------------------------------------- --
--                                    Media                                   --
-- -------------------------------------------------------------------------- --

function checkMediaAuto()
    currentPlayer = nil
    for i = 1, 6 do
        if SKIN:GetMeasure('state'..mediaPlayers[i]):GetValue() == 1 then
            currentPlayer = mediaPlayers[i]
            break
        end
    end
    if currentPlayer == nil then
        for i = 1, 6 do
            if SKIN:GetMeasure('state'..mediaPlayers[i]):GetValue() == 2 then
                currentPlayer = mediaPlayers[i]
                break
            end
        end
    end
    if currentPlayer == nil then currentPlayer = SKIN:GetVariable('NowPlayingMedia') end

    checkingPlayer = currentPlayer

    checkingPlayerState = SKIN:GetMeasure('state'..checkingPlayer):GetValue()

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
        
    SKIN:Bang('[!SetVariable NowPlayingMedia '..checkingPlayer..']')
    SKIN:Bang('[!UpdateMeasureGroup Music]')

    if checkingPlayerState == 1 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Pause"][!UpdateMeter PlayPause]')
    elseif checkingPlayerState == 2 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
    elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
    end

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
    elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption PlayPause MeterStyle "Play"][!UpdateMeter PlayPause]')
    end

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
		return(ReturnStringT)
	  else
		return(ReturnStringF)
	end
end

function returnCenterString(MinimumWidth)
    if MinimumWidth <= SKIN:GetW() then
        return 'Center'
    else
        return 'Left'
    end
end