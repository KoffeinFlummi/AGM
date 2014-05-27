// by commy2

#define OFFSET_1 100
#define OFFSET_2 200

closeDialog 0;
createDialog "AGM_Core_OptionsMenu_Dialog";

AGM_Core_keyNew = [];
AGM_Core_keySet = -1;
AGM_Core_keySave = 0;
AGM_Core_keyNames = [];

disableSerialization;
_dlgMenuDialog = uiNamespace getVariable "AGM_Core_MenuDialog";

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;

for "_index" from 0 to (_count - 1) do {
	_configFile = _config select _index;
	_keyName = configName _configFile;
	_displayName = getText (_configFile >> "displayName");
	_isDisabled = getNumber (_configFile >> "disabled") == 1;

	_keyCode = profileNamespace getVariable format ["AGM_Key_%1", _keyName];
	_description = [_keyCode] call AGM_Core_fnc_revertKeyCodeLocalized;

	_control1 = _dlgMenuDialog displayCtrl (OFFSET_1 + _index);
	_control2 = _dlgMenuDialog displayCtrl (OFFSET_2 + _index);

	_control1 ctrlSetText _displayName;
	_control2 ctrlSetText _description;

	_control1 ctrlShow true;
	_control2 ctrlShow true;

	AGM_Core_keyNames set [_index, _keyName];
};

for "_index" from _count to 19 do {
	_control1 = _dlgMenuDialog displayCtrl (OFFSET_1 + _index);
	_control2 = _dlgMenuDialog displayCtrl (OFFSET_2 + _index);

	_control1 ctrlShow false;
	_control2 ctrlShow false;
};

waitUntil {!dialog};

if (AGM_Core_keySave == 1) then {
	_count = count AGM_Core_keyNew;

	for "_a" from 0 to (_count - 1) do {
		_key = AGM_Core_keyNew select _a;
		_keyName = _key select 0;
		_keyCode = _key select 1;

		profileNamespace setVariable [format ["AGM_Key_%1", _keyName], _keyCode];
	};

	if (_count > 0) then {
		saveProfileNamespace;
		[localize "STR_AGM_Core_ProfileSaved", false] call AGM_Core_fnc_displayText;
	} else {
		[localize "STR_AGM_Core_ProfileNotSaved", false] call AGM_Core_fnc_displayText;
	};
};

AGM_Core_keyNewTemp = nil;
AGM_Core_keyNames = nil;
