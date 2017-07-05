/*
Name: AGM_Artillery_fnc_rangeTableOpen

Author: Pabst Mirror

Description:
  Opens a dialog that shows the range table for a certian weapon

Parameters:
  0: STRING - Weapon Classname

Returns:
  NONE

Example:
  ["AGM_Artillery_81mm"] call AGM_Artillery_fnc_rangeTableOpen
*/

#define LIST_CHARGE       ((uiNamespace getVariable "AGM_Artillery_RangeTable_Dialog_display") displayCtrl 1501)

_weaponName = _this select 0;

if (dialog) exitWith {};
createDialog "AGM_Artillery_RangeTable_Dialog";
if (isNull (uiNamespace getVariable ["AGM_Artillery_RangeTable_Dialog_display", displayNull])) exitWith {};

//Get Magazine Types
_magazines = getArray (configFile >> "CfgWeapons" >> _weaponName >> "magazines");

//For now just get settings from first mag, all rounds have same flight characteristics:
if ((count _magazines) < 1) exitWith {systemChat "Error: No Magazines for weapon"};
_initSpeed = getNumber (configFile >> "CfgMagazines" >> (_magazines select 0) >> "initSpeed");
_ammoClassname = getText (configFile >> "CfgMagazines" >> (_magazines select 0) >> "ammo");
//still need to pass airFriction to rangeTableChange function
AGM_Artillery_rangeTable_airFriction = getNumber (configFile >> "CfgAmmo" >> _ammoClassname >> "AGM_Artillery_realAirFriction");

//Get Charge Modes
_fireModes = getArray (configFile >> "CfgWeapons" >> _weaponName >> "modes");

_muzzleVelocities = [];
{
  _showToPlayer = getNumber (configFile >> "CfgWeapons" >> _weaponName >> _x >> "showToPlayer");
  if (_showToPlayer == 1) then {
    _artilleryCharge = getNumber (configFile >> "CfgWeapons" >> _weaponName >> _x >> "artilleryCharge");
    LIST_CHARGE lbAdd format ["%1: %2 [%3m/s]", (localize "STR_AGM_Artillery_Charge"), (count _muzzleVelocities), (_initSpeed * _artilleryCharge)];
    LIST_CHARGE lbSetData [(count _muzzleVelocities), str (_artilleryCharge * _initSpeed)];
    _muzzleVelocities pushBack _artilleryCharge;
  };
} forEach _fireModes;

LIST_CHARGE lbSetCurSel 0;
