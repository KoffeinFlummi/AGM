// by commy2

_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode;
_vehicle = vehicle player;
_isInput = false;

if (player != _vehicle) exitWith {_isInput};

if (_keyCode == profileNamespace getVariable "AGM_Key_selectPistol") then {
	[handgunWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode;
	_isInput = true;
};
if (_keyCode == profileNamespace getVariable "AGM_Key_selectRifle") then {
	[primaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode;
	_isInput = true;
};
if (_keyCode == profileNamespace getVariable "AGM_Key_selectLauncher") then {
	[secondaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode;
	_isInput = true;
};
if (_keyCode == profileNamespace getVariable "AGM_Key_selectPistolMuzzle") then {
	[handgunWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle;
	_isInput = true;
};
if (_keyCode == profileNamespace getVariable "AGM_Key_selectRifleMuzzle") then {
	[primaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle;
	_isInput = true;
};
if (_keyCode == profileNamespace getVariable "AGM_Key_selectLauncherMuzzle") then {
	[secondaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle;
	_isInput = true;
};
if (_keyCode == profileNamespace getVariable "AGM_Key_selectBinocular") then {
	_weapons = weapons player - [handgunWeapon player] - [primaryWeapon player] - [secondaryWeapon player];
	_binocular = (
		if (count _weapons == 1) then {_weapons select 0} else {""}
	);
	[_binocular] call AGM_WeaponSelect_fnc_selectWeaponMode;
	_isInput = true;
};
if (_keyCode == profileNamespace getVariable "AGM_Key_holsterWeapon") then {
	player action ["SwitchWeapon", _vehicle, _vehicle, 99];
	_isInput = true;
};
_isInput
