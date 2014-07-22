// by commy2

private ["_vehicle", "_wheels"];

_vehicle = _this select 0;
_wheels = _this select 1;

_wheels = [_wheels, {floor (3 * (_vehicle getHitPointDamage _this)) > 0}] call AGM_Core_fnc_filter;

count _wheels > 0
