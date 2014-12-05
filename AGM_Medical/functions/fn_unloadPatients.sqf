/*
 * Author: KoffeinFlummi
 *
 * Unloads the wounded units from the vehicle.
 *
 * Arguments:
 * 0: The unit that does the unloading
 * 1: The vehicle
 *
 * Return Value:
 * -
 */

 private ["_unit", "_vehicle", "_pos"];

_unit = _this select 0;
_vehicle = _this select 1;

{
  if (_x getVariable ["AGM_isUnconscious", False]) then {
    _pos = [
      (getPos _unit select 0) + (random 2) - 1,
      (getPos _unit select 1) + (random 2) - 1,
      0
    ];
    // messy, but who cares?
    [[_x, _vehicle, _unit, _pos], "{moveOut (_this select 0); unassignVehicle (_this select 0); waitUntil {vehicle (_this select 0) == (_this select 0)}; (_this select 0) setPosATL (_this select 3); [(_this select 0), 'Unconscious', 2, True] call AGM_Core_fnc_doAnimation;}", _x] call AGM_Core_fnc_execRemoteFnc;
    _x setVariable ["AGM_OriginalAnim", "AmovPpneMstpSnonWnonDnon", True];
  };
} forEach crew _vehicle;
