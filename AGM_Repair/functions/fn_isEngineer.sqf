private ["_unit"];

_unit = _this select 0;

if (getNumber(configFile >> "CfgVehicles" >> typeOf _unit >> "attendant") == 1 or _unit getVariable ["AGM_IsEngineer", false]) exitWith {
  true
};
false