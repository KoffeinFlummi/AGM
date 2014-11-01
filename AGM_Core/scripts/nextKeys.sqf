// by commy2

#define OFFSET_1 100
#define OFFSET_2 200
#define OFFSET_3 300
#define OFFSET_4 400
#define OFFSET_5 500

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;

_countPages = ceil (_count / 20) + 1;

AGM_Core_MenuPage = AGM_Core_MenuPage + ([-1, 1] select _this);

if (AGM_Core_MenuPage == - 1) then {AGM_Core_MenuPage = _countPages - 1};
if (AGM_Core_MenuPage > _countPages - 1) then {AGM_Core_MenuPage = 0};

disableSerialization;
_dlgMenuDialog = uiNamespace getVariable "AGM_Core_MenuDialog";

(_dlgMenuDialog displayCtrl 14) ctrlSetText format ["%1/%2", AGM_Core_MenuPage + 1, _countPages];

if (AGM_Core_MenuPage == _countPages - 1) then {
  for "_index" from OFFSET_1 to (OFFSET_1 + 19) do {(_dlgMenuDialog displayCtrl _index) ctrlShow false};
  for "_index" from OFFSET_2 to (OFFSET_2 + 19) do {(_dlgMenuDialog displayCtrl _index) ctrlShow false};

  _config = configFile >> "AGM_Core_Options";
  _count = count _config;

  _offset = 0;

  for "_index" from 0 to (_count - 1 min 19) do {
    _configFile = _config select _index + _offset;
    _configName = configName _configFile;
    _displayName = getText (_configFile >> "displayName");
    _state = profileNamespace getVariable format ["AGM_%1", _configName];

    _control1 = _dlgMenuDialog displayCtrl (OFFSET_3 + _index);
    _control2 = _dlgMenuDialog displayCtrl (OFFSET_4 + _index);
    _control3 = _dlgMenuDialog displayCtrl (OFFSET_5 + _index);

    _control1 ctrlSetText format ["\AGM_Core\UI\box_%1checked_ca.paa", ["un", ""] select _state];
    _control2 ctrlSetText _displayName;

    _control1 ctrlShow true;
    _control2 ctrlShow true;
    _control3 ctrlShow true;

    AGM_Core_OptionNames set [_index, _configName];
  };

  for "_index" from _count to (_count + 19) do {
    _control1 = _dlgMenuDialog displayCtrl (OFFSET_3 + _index);
    _control2 = _dlgMenuDialog displayCtrl (OFFSET_4 + _index);
    _control3 = _dlgMenuDialog displayCtrl (OFFSET_5 + _index);

    _control1 ctrlShow false;
    _control2 ctrlShow false;
    _control3 ctrlShow false;
  };

} else {
  for "_index" from OFFSET_3 to (OFFSET_3 + 19) do {(_dlgMenuDialog displayCtrl _index) ctrlShow false};
  for "_index" from OFFSET_4 to (OFFSET_4 + 19) do {(_dlgMenuDialog displayCtrl _index) ctrlShow false};
  for "_index" from OFFSET_5 to (OFFSET_5 + 19) do {(_dlgMenuDialog displayCtrl _index) ctrlShow false};

  _offset = 20 * AGM_Core_MenuPage;
  if (AGM_Core_MenuPage == _countPages - 2) then {
    _count = (_count - 1) % 20 + 1;
  };

  _updateNames = [];
  _updateKeys = [];
  {
    _keyName = _x select 0;
    _keyInput = _x select 1;

    _index = _updateNames find _keyName;
    if (_index == -1) then {_index = count _updateKeys};

    _updateNames set [_index, _keyName];
    _updateKeys set [_index, _keyInput];
  } forEach AGM_Core_keyNew;

  for "_index" from 0 to (_count - 1 min 19) do {
    _configFile = _config select _index + _offset;
    _keyName = configName _configFile;
    _displayName = getText (_configFile >> "displayName");
    _isDisabled = getNumber (_configFile >> "disabled") == 1;

    _indexUpdate = _updateNames find _keyName;
    _keyCode = if (_indexUpdate == -1) then {
      profileNamespace getVariable format ["AGM_Key_%1", _keyName];
    } else {
      _updateKeys select _indexUpdate;
    };

    _description = [_keyCode] call AGM_Core_fnc_revertKeyCodeLocalized;

    _control1 = _dlgMenuDialog displayCtrl (OFFSET_1 + _index);
    _control2 = _dlgMenuDialog displayCtrl (OFFSET_2 + _index);

    _control1 ctrlSetText _displayName;
    _control2 ctrlSetText _description;

    _control1 ctrlShow true;
    _control2 ctrlShow true;

    AGM_Core_keyNames set [_index, _keyName];
  };

  for "_index" from _count to (_count + 19) do {
    _control1 = _dlgMenuDialog displayCtrl (OFFSET_1 + _index);
    _control2 = _dlgMenuDialog displayCtrl (OFFSET_2 + _index);

    _control1 ctrlShow false;
    _control2 ctrlShow false;
  };

  AGM_Core_keySet = -1;
};
