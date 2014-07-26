// by commy2

private ["_vehicle", "_wheels", "_spareWheel"];

_vehicle = _this select 0;
_wheels = _this select 1;

_wheels = [_wheels, {floor (3 * (_vehicle getHitPointDamage _this)) > 0}] call AGM_Core_fnc_filter;

_spareWheel = [player] call AGM_Repair_fnc_getNearestWheel;

count _wheels > 0
&& {alive _vehicle}
&& {speed _vehicle == 0}
&& {!isNull _spareWheel}
