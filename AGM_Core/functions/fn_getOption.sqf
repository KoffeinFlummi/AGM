private ["_addon", "_option", "_value"];
_addon = _this select 0;
_option = _this select 1;
_value = profileNamespace getVariable format ["%1_%2", _addon, _option];
if (isNil "_value") then {
	_value = getNumber(configFile >> "AGM_Core_Options" >> _addon >> _option >> "default") == 1;
};
_value