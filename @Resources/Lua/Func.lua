function startDrop(variant, PosX, PosY)
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Main\\Accessories\\Drop.ini'
	-- local MyMeter = SKIN:GetMeter(handler)
	local scale = tonumber(SKIN:GetVariable('Scale'))
	-- if scalemeasure ~= nil then scale = scalemeasure:GetValue() else scale = tonumber(SKIN:GetVariable('Sec.S')) end
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.name', skin, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
	-- if arg1 then SKIN:Bang('!WriteKeyvalue', 'Variables', 'arg1', arg1, File) end
	SKIN:Bang('!Activateconfig', 'ValliStart\\Main\\Accessories', 'Drop.ini')
	SKIN:Bang('!Move', PosX, PosY, 'ValliStart\\Main\\Accessories')
end

function CheckFullScreen()
    local MyMeasure = SKIN:GetMeasure('MeasureIsFullScreen')
    local mString = MyMeasure:GetStringValue()
    local mNum = MyMeasure:GetValue()
    if mString:match('Rainmeter%.exe') then
        mBool = 1
    else
        mBool = 0
    end
    local check = (mNum .. mBool)
    if string.match(check, '10') then
        SKIN:Bang('!Hide')
    else
        SKIN:Bang('!Show')
    end
end