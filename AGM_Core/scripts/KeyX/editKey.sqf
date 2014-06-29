// by commy2

#define GRAY [0.25, 0.25, 0.25, 1]
#define WHITE [1, 1, 1, 1]
#define OFFSET_1 100
#define OFFSET_2 200

waitUntil {isNil "AGM_Core_keyNewTemp"};
AGM_Core_keyNewTemp = [];

AGM_Core_keySet = 0;
_index = count AGM_Core_keyNew;

disableSerialization;
_dlgMenuDialog = uiNamespace getVariable "AGM_Core_MenuDialog";
_ctrlMenuDialog = _dlgMenuDialog displayCtrl (OFFSET_2 + (_this select 0));
_action = AGM_Core_keyNames select (_this select 0);

(_dlgMenuDialog displayCtrl 24) ctrlSetText "";
(_dlgMenuDialog displayCtrl 21) ctrlSetTextColor GRAY;
(_dlgMenuDialog displayCtrl 22) ctrlSetTextColor GRAY;
(_dlgMenuDialog displayCtrl 23) ctrlSetTextColor GRAY;

for "_index" from 20 to 26 do {(_dlgMenuDialog displayCtrl _index) ctrlShow true};
for "_index" from 10 to 13 do {(_dlgMenuDialog displayCtrl _index) ctrlEnable false};

_description = ctrlText _ctrlMenuDialog;
//_ctrlMenuDialog ctrlSetText "..";

_ehid_keydown = _dlgMenuDialog displayAddEventHandler ["KeyDown", "_this call AGM_Core_keyInput"];

waitUntil {
	if (count AGM_Core_keyNewTemp > 0) then {
		_key = AGM_Core_keyNewTemp select 0;
		_keyModifier = AGM_Core_keyNewTemp select 1;

		_key = toString (toArray (keyName _key) - [34]);
		(_dlgMenuDialog displayCtrl 24) ctrlSetText _key;

		(_dlgMenuDialog displayCtrl 21) ctrlSetTextColor (if (_keyModifier select 0) then {WHITE} else {GRAY});
		(_dlgMenuDialog displayCtrl 22) ctrlSetTextColor (if (_keyModifier select 1) then {WHITE} else {GRAY});
		(_dlgMenuDialog displayCtrl 23) ctrlSetTextColor (if (_keyModifier select 2) then {WHITE} else {GRAY});
	};
	AGM_Core_keySet != 0 ||
	{!dialog}
};

for "_index" from 10 to 13 do {(_dlgMenuDialog displayCtrl _index) ctrlEnable true};
for "_index" from 20 to 26 do {(_dlgMenuDialog displayCtrl _index) ctrlShow false};

_dlgMenuDialog displayRemoveEventHandler ["KeyDown", _ehid_keydown];

if (AGM_Core_keySet == 1 && {count AGM_Core_keyNewTemp > 0}) then {
	_key = AGM_Core_keyNewTemp select 0;
	_keyModifier = AGM_Core_keyNewTemp select 1;
	_description = str _keyCode + str _keyModifier;//
	_ctrlMenuDialog ctrlSetText _description;

	AGM_Core_keyNew set [_index, [_action, _keyCode]];
} else {
	_ctrlMenuDialog ctrlSetText _description;
};

AGM_Core_keySet = -1;
AGM_Core_keyNewTemp = nil;
