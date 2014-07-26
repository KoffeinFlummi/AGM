// by commy2

private ["_unit", "_anim", "_index"];

_unit = _this select 0;

_anim = toArray animationState _unit;
_index = _anim find 95;
_index != -1 && {count _anim > _index + 2} && {_anim select _index + 1 == 97} && {_anim select _index + 2 != 105}	// find "_a" but not "_ai"
