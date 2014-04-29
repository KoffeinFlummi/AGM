// by commy2

#define FORBIDDEN_KEYS [42, 54, 29, 157, 56, 184, 0, 183, 197, 1]

_key = _this select 1;
_shft = _this select 2;
_ctrl = _this select 3;
_alt =_this select 4;

if (_key in FORBIDDEN_KEYS) exitWith {true};

_keyCode = [_key, _shft, _ctrl, _alt] call BWA3_Core_fnc_convertKeyCode;

BWA3_Core_keyNewTemp = [_key, [_shft, _ctrl, _alt], _keyCode];
true
