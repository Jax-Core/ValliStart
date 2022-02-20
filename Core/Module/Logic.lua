function InitDrag(handler)
    Module1Index = handler:gsub('.Image',''):gsub('Module','')
end

function TakeDrag(handler)
    Module2Index = handler:gsub('.Image',''):gsub('Module','')
    local module1Name = SKIN:GetVariable('Module'..Module1Index)
    local module2Name = SKIN:GetVariable('Module'..Module2Index)
    local saveLocation = SKIN:GetVariable('SKINSPATH')..'ValliStart\\@Resources\\Vars.inc'
    if module1Name == module2Name then
        print('Same module')
    else
        SKIN:Bang('[!WriteKeyvalue Variables Module'..Module1Index..' '..module2Name..' '..saveLocation..'][!WriteKeyvalue Variables Module'..Module2Index..' '..module1Name..' '..saveLocation..']')
        SKIN:Bang('[!SetVariable Module'..Module1Index..' '..module2Name..'][!SetVariable Module'..Module2Index..' '..module1Name..'][!UpdateMeter *][!Redraw][!UpdateMeasure Auto_Refresh:M]')
    end
end

function InitDragApps(handler)
    HotApp1Index = handler:gsub('.Shape',''):gsub('HotApp','')
end

function TakeDragApps(handler)
    HotApp2Index = handler:gsub('.Shape',''):gsub('HotApp','')
    local HotApp1Name = SKIN:GetVariable('HotApp'..HotApp1Index)
    local HotApp2Name = SKIN:GetVariable('HotApp'..HotApp2Index)
    local HotApp1Bool = SKIN:GetVariable('HotApp'..HotApp1Index..'Bool')
    local HotApp2Bool = SKIN:GetVariable('HotApp'..HotApp2Index..'Bool')
    local HotApp1Actual = SKIN:GetVariable('HotApp'..HotApp1Index..'Actual')
    local HotApp2Actual = SKIN:GetVariable('HotApp'..HotApp2Index..'Actual')
    local saveLocation = SKIN:GetVariable('SKINSPATH')..'ValliStart\\@Resources\\Vars.inc'
    local saveLocationBool = SKIN:GetVariable('SKINSPATH')..'ValliStart\\@Resources\\HotApps.inc'
    local bang = ''
    if HotApp1Name == HotApp2Name then
        if HotApp1Bool == '1' then
            bang = bang .. '[!WriteKeyvalue Variables HotApp'..HotApp1Index..' None '..saveLocation..']'
            bang = bang .. '[!WriteKeyvalue Variables HotApp'..HotApp1Index..'Bool 0 '..saveLocationBool..']'
            bang = bang .. '[!SetVariable HotApp'..HotApp1Index..' None]'
            bang = bang .. '[!SetVariable HotApp'..HotApp1Index..'Bool 0]'
        else
            bang = bang .. '[!WriteKeyvalue Variables HotApp'..HotApp1Index..' '..HotApp1Actual..' '..saveLocation..']'
            bang = bang .. '[!WriteKeyvalue Variables HotApp'..HotApp1Index..'Bool 1 '..saveLocationBool..']'
            bang = bang .. '[!SetVariable HotApp'..HotApp1Index..' '..HotApp1Actual..']'
            bang = bang .. '[!SetVariable HotApp'..HotApp1Index..'Bool 1]'
        end
    else
        bang = bang .. '[!WriteKeyvalue Variables HotApp'..HotApp1Index..' '..HotApp2Name..' '..saveLocation..'][!WriteKeyvalue Variables HotApp'..HotApp2Index..' '..HotApp1Name..' '..saveLocation..']'
        bang = bang .. '[!WriteKeyvalue Variables HotApp'..HotApp1Index..'Bool '..HotApp2Bool..' '..saveLocationBool..'][!WriteKeyvalue Variables HotApp'..HotApp2Index..'Bool '..HotApp1Bool..' '..saveLocationBool..']'
        bang = bang .. '[!WriteKeyvalue Variables HotApp'..HotApp1Index..'Actual '..HotApp2Actual..' '..saveLocationBool..'][!WriteKeyvalue Variables HotApp'..HotApp2Index..'Actual '..HotApp1Actual..' '..saveLocationBool..']'
        bang = bang .. '[!SetVariable HotApp'..HotApp1Index..' '..HotApp2Name..'][!SetVariable HotApp'..HotApp2Index..' '..HotApp1Name..']'
        bang = bang .. '[!SetVariable HotApp'..HotApp1Index..'Bool '..HotApp2Bool..'][!SetVariable HotApp'..HotApp2Index..'Bool '..HotApp1Bool..']'
        bang = bang .. '[!SetVariable HotApp'..HotApp1Index..'Actual '..HotApp2Actual..'][!SetVariable HotApp'..HotApp2Index..'Actual '..HotApp1Actual..']'
    end
    bang = bang .. '[!UpdateMeter *][!Redraw][!UpdateMeasure Auto_Refresh:M]'
    SKIN:Bang(bang)
end