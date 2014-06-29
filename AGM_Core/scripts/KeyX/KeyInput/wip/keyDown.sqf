// by commy2

#define TIME_INTERVAL 0.75

_key = _this select 1;

_mods = call AGM_KeyX_fnc_getMods;

_state = AGM_KeyX_inputStates select _key;
_lastTime = AGM_KeyX_inputTimes select _key;
_lastTimeNoHold = AGM_KeyX_inputTimesNoHold select _key;
_time = time;

_input = "";
if (_time < _lastTime + TIME_INTERVAL) then {
	if (_state == 0) then {
		if (_time < _lastTimeNoHold + TIME_INTERVAL) then {
			AGM_KeyX_inputTimesNoHold set [_key, 0];
			_input = format ["%1 x2", _key];
		} else {
			AGM_KeyX_inputTimesNoHold set [_key, _time];
			//AGM_KeyX_inputMods set [_key, _mods];
			_input = str _key + str _mods;
		};
	} else {
		AGM_KeyX_inputTimesNoHold set [_key, 0];
		_input = format ["%1 Hold", str _key + str _mods];
	};
} else {
	AGM_KeyX_inputTimesNoHold set [_key, _time];
	AGM_KeyX_inputMods set [_key, _mods];
	_input = str _key + str _mods;
};

systemChat _input;

AGM_KeyX_inputStates set [_key, 1];
AGM_KeyX_inputTimes set [_key, _time];

false
