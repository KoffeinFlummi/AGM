// by commy2

#define TIME_INTERVAL_MOD 0.1

_time = time;

_mods = [];

_mods set [0, AGM_KeyX_inputStates select 42 == 1 && {_time < (AGM_KeyX_inputTimes select 42) + TIME_INTERVAL_MOD}];
_mods set [1, AGM_KeyX_inputStates select 54 == 1 && {_time < (AGM_KeyX_inputTimes select 54) + TIME_INTERVAL_MOD}];
_mods set [2, AGM_KeyX_inputStates select 29 == 1 && {_time < (AGM_KeyX_inputTimes select 29) + TIME_INTERVAL_MOD}];
_mods set [3, AGM_KeyX_inputStates select 157 == 1 && {_time < (AGM_KeyX_inputTimes select 157) + TIME_INTERVAL_MOD}];
_mods set [4, AGM_KeyX_inputStates select 56 == 1 && {_time < (AGM_KeyX_inputTimes select 56) + TIME_INTERVAL_MOD}];
_mods set [5, AGM_KeyX_inputStates select 184 == 1 && {_time < (AGM_KeyX_inputTimes select 184) + TIME_INTERVAL_MOD}];
_mods set [6, AGM_KeyX_inputStates select 220 == 1 && {_time < (AGM_KeyX_inputTimes select 220) + TIME_INTERVAL_MOD}];
_mods set [7, AGM_KeyX_inputStates select 219 == 1 && {_time < (AGM_KeyX_inputTimes select 219) + TIME_INTERVAL_MOD}];

_mods
