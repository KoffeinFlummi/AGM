// by commy2

private ["_unit", "_launcher"];

_unit = _this select 0;

// add earplugs if the soldier has a rocket launcher
_launcher = secondaryWeapon _unit;

if (_launcher != "") exitWith {
  _unit addItem "AGM_EarBuds";
};

// otherwise add earplugs if the soldier has a big rifle
private ["_magazine", "_ammo"];

_magazine = primaryWeaponMagazine _unit select 0;

if (isNil "_magazine") exitWith {};

_ammo = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");

if (getNumber (configFile >> "CfgAmmo" >> _ammo >> "audiblefire") > 8) then {
  _unit addItem "AGM_EarBuds";
};
