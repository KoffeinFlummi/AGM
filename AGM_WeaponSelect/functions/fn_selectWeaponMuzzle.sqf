/*
 * Author: commy2
 *
 * The player will select the specified weapon and change to the first additional muzzle. E.g. the grenade launcher of a assault rifle.
 * 
 * Argument:
 * 0: A weapon (String)
 * 
 * Return value:
 * None.
 */

private ["_weapon", "_muzzles", "_count", "_index", "_muzzle"];

_weapon = _this select 0;
if (_weapon == "") exitWith {};
if (player getVariable ["AGM_Unconscious", false]) exitWith {};

_muzzles = [_weapon] call AGM_WeaponSelect_fnc_getWeaponMuzzles;

if (currentWeapon player != _weapon) exitWith {
	if (count _muzzles > 1) then {
		player selectWeapon (_muzzles select 1);
	};
};

_count = count _muzzles;
_index = (_muzzles find currentMuzzle player) + 1;
if (_index > _count - 1) then {_index = 1};

_muzzle = _muzzles select _index;

_index = 0;
while {
	_index < 100 && {currentMuzzle player != _muzzle}
} do {
	player action ["SwitchWeapon", vehicle player, vehicle player, _index];
	_index = _index + 1;
};
