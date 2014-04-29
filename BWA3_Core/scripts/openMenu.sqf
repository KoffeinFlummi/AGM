// by commy2

#define OFFSET_1 100
#define OFFSET_2 200

closeDialog 0;
createDialog "BWA3_Core_OptionsMenu_Dialog";

BWA3_Core_keyNew = [];
BWA3_Core_keySet = -1;
BWA3_Core_keySave = 0;
BWA3_Core_keyNames = [];

disableSerialization;
_dlgMenuDialog = uiNamespace getVariable "BWA3_Core_MenuDialog";

_config = configFile >> "BWA3_Core_Default_Keys";
_count = count _config;

for "_index" from 0 to (_count - 1) do {
	_configFile = _config select _index;
	_keyName = configName _configFile;
	_displayName = getText (_configFile >> "displayName");
	_isDisabled = getNumber (_configFile >> "disabled") == 1;

	_keyCode = profileNamespace getVariable format ["BWA3_Key_%1", _keyName];
	_description = [_keyCode] call BWA3_Core_fnc_revertKeyCodeLocalized;

	_control1 = _dlgMenuDialog displayCtrl (OFFSET_1 + _index);
	_control2 = _dlgMenuDialog displayCtrl (OFFSET_2 + _index);

	_control1 ctrlSetText _displayName;
	_control2 ctrlSetText _description;

	BWA3_Core_keyNames set [_index, _keyName];
};

waitUntil {!dialog};

if (BWA3_Core_keySave == 1) then {
	_count = count BWA3_Core_keyNew;

	for "_a" from 0 to (_count - 1) do {
		_key = BWA3_Core_keyNew select _a;
		_keyName = _key select 0;
		_keyCode = _key select 1;

		profileNamespace setVariable [format ["BWA3_Key_%1", _keyName], _keyCode];
	};

	if (_count > 0) then {
		saveProfileNamespace;
		["Profile saved", false] call BWA3_Core_fnc_displayText;
	} else {
		["Profile not saved", false] call BWA3_Core_fnc_displayText;
	};
};

BWA3_Core_keyNewTemp = nil;
BWA3_Core_keyNames = nil;
