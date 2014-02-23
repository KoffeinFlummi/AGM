// by commy2

private ["_weapon", "_muzzles", "_count", "_index", "_muzzle"];

_weapon = _this select 0;

_muzzles = [_weapon] call BWA3_QuickSelect_getWeaponMuzzles;	

_count = count _muzzles;
_index = (_muzzles find currentMuzzle player) + 1;
if (_index > _count - 1) then {_index = 1};

_muzzle = _muzzles select _index;

_index = 0;
while {
	currentMuzzle player != _muzzle
} do {
	player action ["SwitchWeapon", vehicle player, vehicle player, _index];
	_index = _index + 1;
};hint str _i;
