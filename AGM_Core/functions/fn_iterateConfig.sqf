/*
	Parameters:
		0: STRING - ConfigName
		1: Code - Code to execute on each config class beneath base class.
			Passed:
				0 - Base config (config of the passed string)
				1 - Addon Config (AGM_Goggles/AGM_Interaction/etc.)
				2 - Key/option config (ShowInThirdPerson, etc.)
	Example:
		["AGM_Core_Default_Keys", {}] call AGM_Core_fnc_iterateConfig;
*/
private ["_config", "_count", "_internalCount", "_configFile", "_addonConfig", "_configName", "_fncEachConfig"];

_fncEachConfig = _this select 1;
_addonConfig = configFile >> (_this select 0);
_count = count _addonConfig;

for "_index" from 0 to (_count - 1) do {
	_config = _addonConfig select _index;
	_internalCount = count _config;
	_configName = configName _config;
	for "_internalIndex" from 0 to (_internalCount - 1) do {
		_configFile = _config select _internalIndex;
		if (isClass _configFile) then {
			[_addonConfig, _config, _configFile] call _fncEachConfig;
		};
	};
};