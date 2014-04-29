// by commy2

private ["_unit", "_vehicle", "_turrets", "_units", "_index"];

_unit = _this select 0;
_vehicle = vehicle _unit;

_turrets = [_vehicle] call BWA3_Core_fnc_getTurrets;

_units = [];
{
	_units set [count _units, _vehicle turretUnit _x];
} forEach _turrets;

_index = _units find _unit;

if (_index == -1) exitWith {[]};

_turrets select _index;
