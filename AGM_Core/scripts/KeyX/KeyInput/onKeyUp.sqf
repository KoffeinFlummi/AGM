// by commy2

#define TIME_INTERVAL 0.75

_key = _this select 1;

_mods = AGM_KeyX_inputMods select _key;

_state = AGM_KeyX_inputStates select _key;
_lastTime = AGM_KeyX_inputTimes select _key;
_time = time;

_input = "";
_mode = 0;
if (_time < _lastTime + TIME_INTERVAL) then {
	_input = format ["%1 UP", str _key + str _mods];
};

systemChat _input;

AGM_KeyX_inputStates set [_key, 0];

_keyCode = [_key, _mods, _mode];
