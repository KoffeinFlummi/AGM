// by commy2

private ["_vehicle", "_wheels"];

_vehicle = _this select 0;
_wheels = _this select 1;

_wheels = [_wheels, {_vehicle getHitPointDamage _this < 1}] call AGM_Core_fnc_filter;

count _wheels > 0
&& {alive _vehicle}
&& {speed _vehicle == 0}
