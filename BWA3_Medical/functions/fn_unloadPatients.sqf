/*
 * Author: KoffeinFlummi
 *
 * Unloads the wounded units from the vehicle.
 *
 * Arguments:
 * 0: The vehicle
 *
 * Return Value:
 * -
 */

 private ["_unit", "_vehicle"];

_vehicle = _this select 0;

{
  if (_x getVariable "BWA3_Unconscious") then {
    _x setPosATL [(getPos player select 0) + (random 2) - 1, (getPos player select 1) + (random 2) - 1, 0];
    [-2, {
      _this switchMove "Unconscious";
    }, _x] call CBA_fnc_globalExecute;
  };
} forEach crew _vehicle;