// by commy2

#define GRAY [0.25, 0.25, 0.25, 1]
#define WHITE [1, 1, 1, 1]
#define OFFSET_1 100
#define OFFSET_2 200

waitUntil {isNil "BWA3_Core_keyNewTemp"};
BWA3_Core_keyNewTemp = [];

BWA3_Core_keySet = 0;
_index = count BWA3_Core_keyNew;

disableSerialization;
_dlgMenuDialog = uiNamespace getVariable "BWA3_Core_MenuDialog";
_ctrlMenuDialog = _dlgMenuDialog displayCtrl (OFFSET_2 + (_this select 0));
_action = BWA3_Core_keyNames select (_this select 0);

(_dlgMenuDialog displayCtrl 24) ctrlSetText "";
(_dlgMenuDialog displayCtrl 21) ctrlSetTextColor GRAY;
(_dlgMenuDialog displayCtrl 22) ctrlSetTextColor GRAY;
(_dlgMenuDialog displayCtrl 23) ctrlSetTextColor GRAY;

for '_a' from 20 to 26 do {(_dlgMenuDialog displayCtrl _a) ctrlShow true};

_description = ctrlText _ctrlMenuDialog;
//_ctrlMenuDialog ctrlSetText "..";

_ehid_keydown = _dlgMenuDialog displayAddEventHandler ["KeyDown", "_this call BWA3_Core_keyInput"];

waitUntil {
	if (count BWA3_Core_keyNewTemp > 0) then {
		_key = BWA3_Core_keyNewTemp select 0;
		_keyModifier = BWA3_Core_keyNewTemp select 1;

		_key = toString (toArray (keyName _key) - [34]);
		(_dlgMenuDialog displayCtrl 24) ctrlSetText _key;

		(_dlgMenuDialog displayCtrl 21) ctrlSetTextColor (if (_keyModifier select 0) then {WHITE} else {GRAY});
		(_dlgMenuDialog displayCtrl 22) ctrlSetTextColor (if (_keyModifier select 1) then {WHITE} else {GRAY});
		(_dlgMenuDialog displayCtrl 23) ctrlSetTextColor (if (_keyModifier select 2) then {WHITE} else {GRAY});
	};
	BWA3_Core_keySet != 0 ||
	{!dialog}
};

for '_a' from 20 to 26 do {(_dlgMenuDialog displayCtrl _a) ctrlShow false};

_dlgMenuDialog displayRemoveEventHandler ["KeyDown", _ehid_keydown];

if (BWA3_Core_keySet == 1 && {count BWA3_Core_keyNewTemp > 0}) then {
	_keyCode = BWA3_Core_keyNewTemp select 2;
	_description = [_keyCode] call BWA3_Core_fnc_revertKeyCodeLocalized;
	_ctrlMenuDialog ctrlSetText _description;

	BWA3_Core_keyNew set [_index, [_action, _keyCode]];
} else {
	_ctrlMenuDialog ctrlSetText _description;
};

BWA3_Core_keySet = -1;
BWA3_Core_keyNewTemp = nil;
