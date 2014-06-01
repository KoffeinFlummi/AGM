// by commy2

_vehicle = _this select 0;
_magazine = _this select 1;
_weapon = (_this call AGM_Logistics_fnc_getWeaponsOfMagazine) select 0;

if (true) exitWith {hintSilent _magazine};

/* WIP */



_magazine in (magazines player + magazineCargo _vehicle);

_vehicle setAmmo [_weapon, (_vehicle ammo _weapon) + 1];
