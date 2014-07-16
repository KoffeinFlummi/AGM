// by commy2

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;

_header = "_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode; _keyIndex = floor _keyCode; if (_keyIndex == 0) exitWith {false}; _time = time; _vehicle = vehicle player; _isInput = false;";

_handleDoubleTap = "if (_time < (AGM_Core_keyTimes select _keyIndex) + 0.5 && {_keyIndex == _keyCode}) then {_keyCode = _keyIndex + 0.8};";
_handleHold = "if (AGM_Core_keyStates select _keyIndex > 1) exitWith {false}; if (AGM_Core_keyStates select _keyIndex > 0) then {_keyCode = _keyIndex + 0.9};";
_handleHoldUp = "if (AGM_Core_keyStates select _keyIndex > 1) then {_keyCode = _keyIndex + 0.9};";

_debug = "if (!isNil 'AGM_Debug') then {systemChat (str _keyCode + ' ' + str (AGM_Core_keyStates select _keyIndex))};";

_onKeyDown = "" + _debug;
_onKeyUp = "" + _debug;

for "_index" from 0 to (_count - 1) do {
	_configFile = _config select _index;

	_keyName = configName _configFile;
	_condition = getText (_configFile >> "condition");
	if (_condition == "") then {_condition = "true";}else{
		_condition = "_vehicle = vehicle player;" + _condition;
		missionNamespace setVariable [format["AGM_autogen_%1_condition",configName _configFile],compile _condition];
		_condition = format["call AGM_autogen_%1_condition", configName _configFile];
	};
	_statement = getText (_configFile >> "statement");

	if (_statement != "") then {
		_statement = "_vehicle = vehicle player;" + _statement;
		missionNamespace setVariable [format["AGM_autogen_%1_statement",configName _configFile],compile _statement];
		_entry = format ["if (_keyCode == profileNamespace getVariable 'AGM_Key_%1' && {%2}) then {call AGM_autogen_%3_statement;_isInput = true;};", _keyName,_condition, configName _configFile];
		_onKeyDown = _onKeyDown + _entry;
	};

	_condition = getText (_configFile >> "conditionUp");
	if (_condition == "") then {_condition = "true";}else{
		_condition = "_vehicle = vehicle player;" + _condition;
		missionNamespace setVariable [format["AGM_autogen_%1_conditionUp",configName _configFile],compile _condition];
		_condition = format["call AGM_autogen_%1_conditionUp", configName _configFile];
	};
	_statement = getText (_configFile >> "statementUp");

	if (_statement != "") then {
		_statement = "_vehicle = vehicle player;" + _statement;
		missionNamespace setVariable [format["AGM_autogen_%1_statementUp",configName _configFile],compile _statement];
		_entry = format ["if (_keyCode == profileNamespace getVariable 'AGM_Key_%1' && {%2}) then {call AGM_autogen_%3_statementUp; _isInput = true;};", _keyName, _condition, configName _configFile];
		_onKeyUp = _onKeyUp + _entry;
	};
};

_halt = "AGM_Core_keyStates set [_keyIndex, (AGM_Core_keyStates select _keyIndex) + 1]; AGM_Core_keyTimes set [_keyIndex, _time];";
_haltUp = "AGM_Core_keyStates set [_keyIndex, 0];";

_return = "_isInput";

_repeat = format ["if (!_isInput && {_keyCode mod 1 > 0} && {_keyCode mod 1 < 0.85}) exitWith {_keyCode = _keyIndex; %1};", _onKeyDown + _return];
_repeatUp = format ["if (!_isInput && {_keyCode mod 1 > 0} && {_keyCode mod 1 < 0.85}) exitWith {_keyCode = _keyIndex; %1};", _onKeyUp];

_onKeyDown = _header + _handleDoubleTap + _handleHold + _onKeyDown + _halt + _repeat + _return;
_onKeyUp = _header + _handleHoldUp + _onKeyUp + _haltUp + _repeatUp;

AGM_Core_onKeyDown = compile _onKeyDown;
AGM_Core_onKeyUp = compile _onKeyUp;
