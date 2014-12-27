/*
Name: AGM_Artillery_fnc_mapCompOpen

Author: Pabst Mirror

Description:
  Handles opening the map computer dialog.  Fills the charge display

Parameters:
  NONE

Returns:
  STRING - Formatted number

Example:
  Called from the Mortars UserActions (action menu)
*/

private ["_mortarVeh", "_weaponName", "_fireModes", "_magazines", "_magazineClassname", "_ammoMaxSpeed", "_ammoClassname", "_ammoAirfriction", "_muzzleVelocities", "_showToPlayer", "_artilleryCharge", "_currentFireMode", "_currentChargeMode"];

#define MAP_CHARGE_LISTBOX (((uiNamespace getVariable ["AGM_Artillery_MapComputer_Dialog", displayNull])) displayCtrl 233232)

AGM_Artillery_COMPUTER_chargeRangeArray = [];

if (dialog) exitWith {systemChat "Error: Dialog Open?"};
createDialog "AGM_Artillery_MapComputer_Dialog";
if (isNull (uiNamespace getVariable ["AGM_Artillery_MapComputer_Dialog", displayNull])) exitWith {};

_mortarVeh = (vehicle AGM_player);
_weaponName = currentWeapon _mortarVeh;
_fireModes = getArray (configFile >> "CfgWeapons" >> _weaponName >> "modes");

//Get Magazine Types
_magazines = getArray (configFile >> "CfgWeapons" >> _weaponName >> "magazines");

//For now just get settings from first mag, all rounds have same flight charactoristics:
if ((count _magazines) < 1) exitWith {systemChat "Error: No Magazines for weapon"};
_magazineClassname = _magazines select 0;
_ammoMaxSpeed = getNumber (configFile >> "CfgMagazines" >> (_magazineClassname) >> "initSpeed");
_ammoClassname = getText (configFile >> "CfgMagazines" >> (_magazineClassname) >> "ammo");
_ammoAirfriction = getNumber (configFile >> "CfgMagazines" >> (_ammoClassname) >> "AGM_Artillery_realAirFriction");

_muzzleVelocities = [];
{
  _showToPlayer = getNumber (configFile >> "CfgWeapons" >> _weaponName >> _x >> "showToPlayer");
  if (_showToPlayer == 1) then {
    _artilleryCharge = getNumber (configFile >> "CfgWeapons" >> _weaponName >> _x >> "artilleryCharge");
    MAP_CHARGE_LISTBOX lbAdd format ["%1: %2 [%3m/s]", (localize "STR_AGM_Artillery_Charge"), (count _muzzleVelocities), (_artilleryCharge * _ammoMaxSpeed)];
    MAP_CHARGE_LISTBOX lbSetData [(count _muzzleVelocities), str (_artilleryCharge * _ammoMaxSpeed)];
    _muzzleVelocities pushBack (_artilleryCharge * _ammoMaxSpeed);
  };
} forEach _fireModes;

_currentFireMode = (weaponState [_mortarVeh, [0]]) select 2;
_currentChargeMode = _fireModes find _currentFireMode;

MAP_CHARGE_LISTBOX lbSetCurSel _currentChargeMode;
