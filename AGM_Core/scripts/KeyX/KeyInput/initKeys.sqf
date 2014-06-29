// by commy2

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;

_header = "_vehicle = vehicle player; _isInput = false;";

_onKeyDown = (preprocessFileLineNumbers "\AGM_Core\scripts\KeyX\onKeyDown.sqf") + _header;
_onKeyUp = (preprocessFileLineNumbers "\AGM_Core\scripts\KeyX\onKeyUp.sqf") + _header;

/*
sync here

_keyCode ([_key, _mods, _mode])

_mode No.
	0: normal
	1: hold
	2: double tab
*/

for "_index" from 0 to (_count - 1) do {
	_configFile = _config select _index;

	_keyName = configName _configFile;
	_condition = getText (_configFile >> "condition");
	if (_condition == "") then {_condition = "true";};
	_statement = getText (_configFile >> "statement");

	if (_statement != "") then {
		_entry = format ["if (_keyCode isEqualTo (profileNamespace getVariable 'AGM_Key_%1') && {%2}) then {%3; _isInput = true;};", _keyName, _condition, _statement];
		_onKeyDown = _onKeyDown + _entry;
	};

	_condition = getText (_configFile >> "conditionUp");
	if (_condition == "") then {_condition = "true";};
	_statement = getText (_configFile >> "statementUp");

	if (_statement != "") then {
		_entry = format ["if (_keyCode isEqualTo (profileNamespace getVariable 'AGM_Key_%1') && {%2}) then {%3; _isInput = true;};", _keyName, _condition, _statement];
		_onKeyUp = _onKeyUp + _entry;
	};
};

_return = "_isInput";

_onKeyDown = _onKeyDown + _return;
_onKeyUp = _onKeyUp;

AGM_Core_onKeyDown = compileFinal _onKeyDown;
AGM_Core_onKeyUp = compileFinal _onKeyUp;
