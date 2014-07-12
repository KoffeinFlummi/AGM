/*
* Author: marc_book
* Doesn't have any function now.
* Coming soon.
*
* the config entry you were looking for is 'engineer' - commy2
*
*/
private ["_unit"];

_unit = _this select 0;

if (getNumber(configFile >> "CfgVehicles" >> typeOf _unit >> "engineer") == 1 or _unit getVariable ["AGM_IsEngineer", false]) exitWith {
  true
};
false