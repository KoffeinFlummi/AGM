// by commy2

private ["_unit", "_chance"];

_unit = _this select 0;
_chance = _this select 1;

if (random 1 < _chance) then {
	_unit setCaptive 1;
	_unit playMoveNow "AmovPercMstpSsurWnonDnon";
};
