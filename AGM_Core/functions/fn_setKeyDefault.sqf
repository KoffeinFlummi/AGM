/*
 * Author: commy2
 *
 * Set all keys from the 'AGM_Core_Default_Keys' base class that are missing in the current user profile.
 * 
 * Argument:
 * None.
 * 
 * Return value:
 * None.
 */

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;
_saveProfile = false;

for "_index" from 0 to (_count - 1) do {
	_configFile = _config select _index;
	_name = format ["AGM_Key_%1", configName _configFile];
	_key = profileNamespace getVariable _name;

	if (isNil "_key") then {
		_key = getNumber (_configFile >> "Key");
		_shft = getNumber (_configFile >> "Shift") == 1;
		_ctrl = getNumber (_configFile >> "Control") == 1;
		_alt = getNumber (_configFile >> "Alt") == 1;

		_keyCode = [_key, _shft, _ctrl, _alt] call AGM_Core_fnc_convertKeyCode;

		profileNamespace setVariable [_name, _keyCode];
		_saveProfile = true;
	};
};

if (_saveProfile) then {
	saveProfileNamespace;
	diag_log text "AGM: Encountered missing variable in profile namespace. Profile saved.";
} else {
	diag_log text "AGM: No missing variables encountered in profile namespace.";
};
