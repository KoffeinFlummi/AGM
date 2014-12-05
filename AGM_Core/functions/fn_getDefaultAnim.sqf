// by commy2

private "_unit";

_unit = _this select 0;

format ["AmovP%1M%2S%3W%4Dnon",
  ["erc", "knl", "pne"] select (["STAND", "CROUCH", "PRONE"] find stance _unit) max 0,
  ["stp", "run"] select (speed _unit > 1),
  ["ras", "low"] select weaponLowered _unit,
  ["non", "rfl", "lnr", "pst", "bin"] select (["", primaryWeapon _unit, secondaryWeapon _unit, handgunWeapon _unit, binocular _unit] find currentWeapon _unit) max 0
]
