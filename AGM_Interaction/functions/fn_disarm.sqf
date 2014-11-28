/*
Author: CAA-Picard

Description:
Disarm the player

Arguments:
0: The local unit being disarmed
1: The unit doing the disarming

Return value:
None
*/

private ["_unit", "_guard", "_allGear", "_wh"];

_unit = _this select 0;
_guard = _this select 1;

_allGear = [
  (headgear _unit),
  (goggles _unit),
  (uniform _unit),
  (uniformItems _unit),
  (vest _unit),
  (vestItems _unit),
  (backpack _unit),
  (backpackItems _unit),
  (primaryWeapon _unit),
  (primaryWeaponItems _unit),
  (primaryWeaponMagazine _unit),
  (secondaryWeapon _unit),
  (secondaryWeaponItems _unit),
  (secondaryWeaponMagazine _unit),
  (handgunWeapon _unit),
  (handgunItems _unit),
  (handgunMagazine _unit),
  (assignedItems _unit),
  (binocular _unit)
];

// Make the unit drop it's backpack
_unit addBackpack "Bag_Base";
 removeBackpack _unit;

// Remove the uniform items
removeUniform _unit;
_unit forceAddUniform (_allGear select 2);

// Remove the vest and all it's content
removeVest _unit;

// Remove the rest of the stuff
removeAllWeapons _unit;
removeAllAssignedItems _unit;


_wh = createVehicle ["WeaponHolderSimulated", [0,0,0], [], 0, "CAN_COLLIDE"];

// Store vest and vest items
if (_allGear select 4 != "") then {
  _wh addItemCargoGlobal [_allGear select 4,1];
  {
    _wh addItemCargoGlobal [_x,1];
  }forEach (_allGear select 5);
};

// Store main weapon and accesories
if (_allGear select 8 != "") then {
  _wh addItemCargoGlobal [_allGear select 8,1];
  {
    if (_x != "") then {
      _wh addItemCargoGlobal [_x,1];
    };
  }forEach (_allGear select 9);
  {
    if (_x != "") then {
      _wh addItemCargoGlobal [_x,1];
    };
  }forEach (_allGear select 10);
};

// Store secondary weapon and accesories
if (_allGear select 11 != "") then {
  _wh addItemCargoGlobal [_allGear select 11,1];
  {
    if (_x != "") then {
      _wh addItemCargoGlobal [_x,1];
    };
  }forEach (_allGear select 12);
  {
    if (_x != "") then {
      _wh addItemCargoGlobal [_x,1];
    };
  }forEach (_allGear select 13);
};

// Store pistol and accesories
if (_allGear select 14 != "") then {
  _wh addItemCargoGlobal [_allGear select 14,1];
  {
    if (_x != "") then {
      _wh addItemCargoGlobal [_x,1];
    };
  }forEach (_allGear select 15);
  {
    if (_x != "") then {
      _wh addItemCargoGlobal [_x,1];
    };
  }forEach (_allGear select 16);
};

// Store uniform items
{
  _wh addItemCargoGlobal [_x,1];
}forEach (_allGear select 3);

// Store assigned items
{
  _wh addItemCargoGlobal [_x,1];
}forEach (_allGear select 17);

_wh setPos getPos _unit;
