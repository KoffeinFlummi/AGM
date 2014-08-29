// by commy2

#define FORBIDDEN_KEYS [42, 54, 29, 157, 56, 184, 0, 183, 197, 1]

_key = _this select 1;
_shft = _this select 2;
_ctrl = _this select 3;
_alt =_this select 4;

if (_key in FORBIDDEN_KEYS) exitWith {true};

_keyCode = [_key, _shft, _ctrl, _alt] call AGM_Core_fnc_convertKeyCode;

_keyIndex = floor _keyCode;
_time = time;

if (_time < (AGM_Core_keyTimes select _keyIndex) + 0.5 && {_keyIndex == _keyCode}) then {_keyCode = _keyIndex + 0.8};
if (AGM_Core_keyStates select _keyIndex > 1) exitWith {true};
if (AGM_Core_keyStates select _keyIndex > 0 && {_keyIndex == _keyCode}) then {_keyCode = _keyIndex + 0.9};

AGM_Core_keyStates set [_keyIndex, (AGM_Core_keyStates select _keyIndex) + 1];
AGM_Core_keyTimes set [_keyIndex, _time];

AGM_Core_keyNewTemp = [_key, [_shft, _ctrl, _alt], _keyCode];
true
