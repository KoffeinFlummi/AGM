// by commy2

private ["_unit", "_anim", "_stance"];

_unit = _this select 0;
_anim = toLower (animationState _unit);

// stance is broken for some animations.
_stance = stance _unit;
if (_anim find "ppne" == 4) then {
  _stance = "PRONE";
};
if (_anim find "pknl" == 4) then {
  _stance = "CROUCH";
};
if (_anim find "perc" == 4) then {
  _stance = "STAND";
};

format ["AmovP%1M%2S%3W%4Dnon",
  ["erc", "knl", "pne"] select (["STAND", "CROUCH", "PRONE"] find _stance) max 0,
  ["stp", "run"] select (speed _unit > 1),
  ["ras", "low"] select weaponLowered _unit,
  ["non", "rfl", "lnr", "pst", "bin"] select (["", primaryWeapon _unit, secondaryWeapon _unit, handgunWeapon _unit, binocular _unit] find currentWeapon _unit) max 0
]
