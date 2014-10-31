// by commy2

#define OFFSET_1 100
#define OFFSET_2 200

closeDialog 0;
createDialog "AGM_Core_OptionsMenu_Dialog";

AGM_Core_keyNew = [];
AGM_Core_keySet = -1;
AGM_Core_keySave = 0;
AGM_Core_keyNames = [];
AGM_Core_MenuPage = 0;
AGM_Core_OptionNames = [];
AGM_Core_OptionNamesNew = [];
AGM_Core_OptionStatesNew = [];

disableSerialization;
_dlgMenuDialog = uiNamespace getVariable "AGM_Core_MenuDialog";

_ehid_keydown = _dlgMenuDialog displayAddEventHandler ["KeyDown", "_this select 1 > 1"];
_ehid_keyup = _dlgMenuDialog displayAddEventHandler ["KeyUp", "_this select 1 > 1"];

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;

_countPages = ceil (_count / 20) + 1;
(_dlgMenuDialog displayCtrl 14) ctrlSetText format ["%1/%2", AGM_Core_MenuPage + 1, _countPages];

for "_index" from 0 to (_count - 1 min 19) do {
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

_dlgMenuDialog displayRemoveEventHandler ["KeyDown", _ehid_keydown];
_dlgMenuDialog displayRemoveEventHandler ["KeyUp", _ehid_keyup];

if (AGM_Core_keySave == 1) then {
  _count0 = count AGM_Core_keyNew;

  for "_index" from 0 to (_count0 - 1) do {
    _key = AGM_Core_keyNew select _index;
    _keyName = _key select 0;
    _keyCode = _key select 1;

    profileNamespace setVariable [format ["AGM_Key_%1", _keyName], _keyCode];
  };

  _count1 = count AGM_Core_OptionNamesNew;

  for "_index" from 0 to (_count1 - 1) do {
    _name = AGM_Core_OptionNamesNew select _index;
    _state = AGM_Core_OptionStatesNew select _index;

    profileNamespace setVariable [_name, _state];
  };

  if (_count0 > 0 || {_count1 > 0}) then {
    saveProfileNamespace;
    [localize "STR_AGM_Core_ProfileSaved"] call AGM_Core_fnc_displayTextStructured;
  } else {
    [localize "STR_AGM_Core_ProfileNotSaved"] call AGM_Core_fnc_displayTextStructured;
  };
} else {
  [localize "STR_AGM_Core_ProfileNotSaved"] call AGM_Core_fnc_displayTextStructured;
};

AGM_Core_keyNewTemp = nil;
AGM_Core_keyNames = nil;
AGM_Core_MenuPage = nil;
AGM_Core_OptionNames = nil;
AGM_Core_OptionNamesNew = nil;
AGM_Core_OptionStatesNew = nil;
