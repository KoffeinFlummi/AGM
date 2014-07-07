private ["_keys"];
_keys = [];
["AGM_Core_Default_Keys", {
	private ["_keyCode", "_keyName", "_addonName"];
	_addonName = configName (_this select 1);
	_keyName = configName (_this select 2);
	
	_keyCode = profileNamespace getVariable format ["AGM_Key_%1_%2", _addonName, _keyName];
	if (isNil "_keyCode") then {
		_key = getNumber (_configFile >> "Key");
		_shft = getNumber (_configFile >> "Shift") == 1;
		_ctrl = getNumber (_configFile >> "Control") == 1;
		_alt = getNumber (_configFile >> "Alt") == 1;

		_keyCode = [_key, _shft, _ctrl, _alt] call AGM_Core_fnc_convertKeyCode;
	};
	
	_keys set [count _keys, [_keyCode,_keyName,_addonName]];
}] call AGM_Core_fnc_iterateConfig;

//[[KeyCode (default or saved), keyConfigName, addonConfigName]]
_keys