/*
Name: AGM_Attach_fnc_vehicleCanDetach

Author: Pabst Mirror

Description:
  Tests if the unit can detach from the vehicle

Parameters:
  0: OBJECT - unit doing the detaching (usualy the player)
  1: OBJECT - vehicle that it will be attached to (player or vehicle)

Returns:
  BOOL

Example:
  [player, tank] call AGM_Attach_fnc_vehicleCanDetach
*/
private ["_unit", "_attachToVehicle", "_attachToPointName", "_modelPosition", "_worldPos", "_unitPos", "_minDistance"];

_unit = _this select 0;
_attachToVehicle = _this select 1;

_attachedObjects = _attachToVehicle getVariable ["AGM_AttachedObjects", []];

//Scan if unit is within range (using 2d distance)
_unitPos = getPos _unit;
_unitPos set [2,0];
_minDistance = 1000;
{
  _objectPos = getPos _x;
  _objectPos set [2, 0];
  _minDistance = _minDistance min (_objectPos distance _unitPos);
} forEach _attachedObjects;

canStand _unit && {alive _attachToVehicle} && {_minDistance < 2.4}
