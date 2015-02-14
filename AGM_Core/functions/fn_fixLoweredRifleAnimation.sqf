// by commy2

private "_unit";

_unit = _this select 0;

if (currentWeapon _unit != "" && {currentWeapon _unit == primaryWeapon _unit} && {weaponLowered _unit} && {stance _unit == "STAND"} && {(vehicle _unit) == _unit}) then {
  [_unit, "amovpercmstpsraswrfldnon", 0] call AGM_Core_fnc_doAnimation;
};
