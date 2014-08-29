// by commy2

_vehicle = vehicle player;

while {true} do {
	_displayType = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_DisplayType");

	if (_displayType == "Strider") then {[_vehicle] call AGM_StriderFix_fnc_displayAzimuth};

	waitUntil {_vehicle != vehicle player};
	_vehicle = vehicle player;
};

