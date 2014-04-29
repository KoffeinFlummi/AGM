// by commy2

private ["_weapon", "_muzzles"];

_weapon = _this select 0;

_muzzles = getArray (configFile >> "CfgWeapons" >> _weapon >> "muzzles");

if ("this" in _muzzles) then {
	_muzzles set [_muzzles find "this", _weapon];
};
_muzzles
