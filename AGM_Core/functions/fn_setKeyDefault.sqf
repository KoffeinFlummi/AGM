/*
 * Author: commy2
 *
 * Set all keys from the 'AGM_Core_Default_Keys' base class that are missing in the current user profile.
 * 
 * Argument:
 * 1: Overwrite existing key binds? (Bool)
 * 
 * Return value:
 * None.
 */

private ["_overwrite", "_saveProfile", "_config", "_count", "_index", "_configFile", "_name", "_key", "_shft", "_ctrl", "_alt", "_keyCode", "_state"];

_overwrite = _this select 0;
_saveProfile = false;

_keys = call AGM_Core_fnc_getAllKeys;
{
	private ["_testValid", "_name"];
	_name = format ["AGM_Key_%1_%2", _x select 2, _x select 1];
	_testValid = profileNamespace getVariable _name;
	if (isNil "_testValid" || {_overwrite}) then {
		profileNamespace setVariable [_name, _x select 0];
		_saveProfile = true;
	};
} count _keys;

_options = call AGM_Core_fnc_getAllOptions;
{
	private ["_state", "_name"];
	_name = format ["%1_%2", _x select 2, _x select 1];
	_state = profileNamespace getVariable _name;

	if (isNil "_state" || {_overwrite}) then {
		profileNamespace setVariable [_name, _x select 0];
		_saveProfile = true;
	};
} count _options;

if (_overwrite) then {
		saveProfileNamespace;
		diag_log text "AGM: Profile settings overwritten.";
} else {
	if (_saveProfile) then {
		saveProfileNamespace;
		diag_log text "AGM: Encountered missing variable in profile namespace. Profile saved.";
	} else {
		diag_log text "AGM: No missing variables encountered in profile namespace.";
	};
};
