/*
 * Author: commy2
 *
 * The player will select the specified weapon or will change to the next firing mode if the weapon was already selected.
 * 
 * Argument:
 * 0: A weapon (String)
 * 
 * Return value:
 * None.
 */

private ["_weapon", "_muzzles", "_modes", "_count", "_index", "_muzzle", "_mode"];

_weapon = _this select 0;
if (_weapon == "") exitWith {};
if !(player getVariable ["AGM_CanTreat", true]) exitWith {};

if (currentWeapon player != _weapon) exitWith {
	player selectWeapon _weapon;
};

_muzzles = [_weapon] call AGM_WeaponSelect_fnc_getWeaponMuzzles;	
_modes = [_weapon] call AGM_WeaponSelect_fnc_getWeaponModes;

_count = count _modes;
_index = (_modes find currentWeaponMode player) + 1;
if (_index > _count - 1) then {_index = 0};

_muzzle = _muzzles select 0;
_mode = _modes select _index;

_index = 0;
while {
	_index < 100 && {currentMuzzle player != _muzzle || {currentWeaponMode player != _mode}}
} do {
	player action ["SwitchWeapon", vehicle player, vehicle player, _index];
	_index = _index + 1;
};
