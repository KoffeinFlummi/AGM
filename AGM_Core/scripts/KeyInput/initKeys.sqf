// by commy2

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;

_header = "_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode; _keyIndex = floor _keyCode; if (_keyIndex == 0) exitWith {false}; _time = time; _vehicle = vehicle player; _isInput = false;";
_headerUp = "_keyCode = _this select 1; _keyIndex = _keyCode; if (_keyIndex == 0) exitWith {false}; _time = time; _vehicle = vehicle player;";

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
	if (_condition == "") then {_condition = "true"};

	_statement = getText (_configFile >> "statement");

	_exceptions = getArray (_configFile >> "exceptions");
	_canInteract = format ["%1 call AGM_Core_canInteract", _exceptions];

	if (_statement != "") then {
		_entry = format ["if (_keyCode == profileNamespace getVariable 'AGM_Key_%1' && {%2} && {%4}) then {%3; _isInput = true;};", _keyName, _condition, _statement, _canInteract];
		_onKeyDown = _onKeyDown + _entry;
	};

	_condition = getText (_configFile >> "conditionUp");
	if (_condition == "") then {_condition = "true"};

	_statement = getText (_configFile >> "statementUp");

	if (_statement != "") then {
		_entry = format ["if (_keyCode == floor (profileNamespace getVariable 'AGM_Key_%1') && {%2}) then {%3; _isInput = true;};", _keyName, _condition, _statement];
		_onKeyUp = _onKeyUp + _entry;
	};
};

_halt = "AGM_Core_keyStates set [_keyIndex, (AGM_Core_keyStates select _keyIndex) + 1]; AGM_Core_keyTimes set [_keyIndex, _time];";
_haltUp = "AGM_Core_keyStates set [_keyIndex, 0];";

_return = "_isInput";

_repeat = format ["if (!_isInput && {_keyCode mod 1 > 0} && {_keyCode mod 1 < 0.85}) exitWith {_keyCode = _keyIndex; %1};", _onKeyDown + _return];
_repeatUp = format ["if (!_isInput && {_keyCode mod 1 > 0} && {_keyCode mod 1 < 0.85}) exitWith {_keyCode = _keyIndex; %1};", _onKeyUp];

_onKeyDown = _header + _handleDoubleTap + _handleHold + _onKeyDown + _halt + _repeat + _return;
_onKeyUp = _headerUp + _onKeyUp + _haltUp + _repeatUp;	//_headerUp + _handleHoldUp + _onKeyUp + _haltUp + _repeatUp;

AGM_Core_onKeyDown = compileFinal _onKeyDown;
AGM_Core_onKeyUp = compileFinal _onKeyUp;
