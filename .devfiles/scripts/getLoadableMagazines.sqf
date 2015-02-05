// by commy2

private ["_vehicle", "_weapons", "_magazines"];

_vehicle = _this select 0;

_weapons = weapons _vehicle;

_magazines = [];
{
	_magazines = _magazines + getArray (configfile >> "CfgWeapons" >> _x >> "AGM_Magazines");
} forEach _weapons;

{
	//if !(_x in (magazines player + magazineCargo _vehicle)) then {
	if !(_x in magazines player) then {
		_magazines = _magazines - [_x];
	};
} forEach _magazines;

_magazines
