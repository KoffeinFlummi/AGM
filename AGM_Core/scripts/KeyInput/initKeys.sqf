// by commy2

hint str time;

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;

_header = "_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode; _vehicle = vehicle player; _isInput = false;";

_prefix = "if (AGM_Core_keyStates select floor _keyCode) exitWith {false};";

_onKeyDown = _header + _prefix;
_onKeyUp = _header;

for "_index" from 0 to (_count - 1) do {
	_configFile = _config select _index;

	_keyName = configName _configFile;
	_condition = getText (_configFile >> "condition");
	if (_condition == "") then {_condition = "true";};
	_statement = getText (_configFile >> "statement");

	if (_statement != "") then {
		_entry = format ["if (_keyCode == profileNamespace getVariable 'AGM_Key_%1' && {%2}) then {%3; _isInput = true;};", _keyName, _condition, _statement];
		_onKeyDown = _onKeyDown + _entry;
	};

	_condition = getText (_configFile >> "conditionUp");
	if (_condition == "") then {_condition = "true";};
	_statement = getText (_configFile >> "statementUp");

	if (_statement != "") then {
		_entry = format ["if (_keyCode == profileNamespace getVariable 'AGM_Key_%1' && {%2}) then {%3; _isInput = true;};", _keyName, _condition, _statement];
		_onKeyUp = _onKeyUp + _entry;
	};
};

_repeat = "if (!_isInput && {_keyCode % 1 > 0}) exitWith {[false, floor _keyCode, false, false, false] call AGM_Core_onKeyDown};";
_repeatUp = "if (!_isInput && {_keyCode % 1 > 0}) exitWith {[false, floor _keyCode, false, false, false] call AGM_Core_onKeyUp};";
_return = "_isInput";

_halt = "AGM_Core_keyStates set [floor _keyCode, true];";
_haltUp = "AGM_Core_keyStates set [floor _keyCode, false];";

_onKeyDown = _onKeyDown + _repeat + _halt + _return;
_onKeyUp = _onKeyUp + _repeatUp + _haltUp;

AGM_Core_onKeyDown = compile _onKeyDown;
AGM_Core_onKeyUp = compile _onKeyUp;
