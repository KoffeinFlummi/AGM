// by commy2

_config = configFile >> "AGM_Core_Default_Keys";
_count = count _config;

_header = "_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode; _vehicle = vehicle player; _isInput = false;";
_menu = "if (_keyCode == 198.2 && {!dialog}) then {0 spawn AGM_Core_openMenu};";

_onKeyDown = _header;
_onKeyUp = _header + _menu;

for "_index" from 0 to (_count - 1) do {
	_configFile = _config select _index;

	_keyName = configName _configFile;
	_condition = getText (_configFile >> "condition");
	_statement = getText (_configFile >> "statement");

	if (_statement != "") then {
		_entry = format ["if (_keyCode == profileNamespace getVariable 'AGM_Key_%1' && {%2}) then {%3; _isInput = true;};", _keyName, _condition, _statement];
		_onKeyDown = _onKeyDown + _entry;
	};

	_condition = getText (_configFile >> "conditionUp");
	_statement = getText (_configFile >> "statementUp");

	if (_statement != "") then {
		_entry = format ["if (_keyCode == profileNamespace getVariable 'AGM_Key_%1' && {%2}) then {%3; _isInput = true;};", _keyName, _condition, _statement];
		_onKeyUp = _onKeyUp + _entry;
	};
};

_return = "_isInput";

_onKeyDown = _onKeyDown + _return;
_onKeyUp = _onKeyUp + _return;

AGM_Core_onKeyDown = compileFinal _onKeyDown;
AGM_Core_onKeyUp = compileFinal _onKeyUp;

(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call AGM_Core_onKeyDown"];
(findDisplay 46) displayAddEventHandler ["KeyUp", "_this call AGM_Core_onKeyUp"];
