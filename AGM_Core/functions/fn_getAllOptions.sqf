private ["_options"];
_options = [];
["AGM_Core_Options", {
	private ["_value", "_optionName", "_addonName"];
	_addonName = configName (_this select 1);
	_optionName = configName (_this select 2);
	
	_options set [count _options, [[_addonName, _optionName] call AGM_Core_fnc_getOption,_optionName,_addonName]];
}] call AGM_Core_fnc_iterateConfig;

//[[Value (default or saved), optionConfigName, addonConfigName]]
_options