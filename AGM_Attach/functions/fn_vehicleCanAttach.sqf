/*
Name: AGM_Attach_fnc_vehicleCanAttach

Author: Pabst Mirror

Description:
  Tests if the unit can attach to the vehicle

Parameters:
  0: OBJECT - unit doing the attaching (usualy the player)
  1: OBJECT - vehicle that it will be attached to (player or vehicle)

Returns:
  BOOL

Example:
  [player, tank] call AGM_Attach_fnc_vehicleCanAttach
*/
private ["_unit", "_attachToVehicle"];

_unit = _this select 0;
_attachToVehicle = _this select 1;

canStand _unit && {alive _attachToVehicle}
