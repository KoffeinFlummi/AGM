/*
Name: AGM_Attach_fnc_vehicleCanDetach

Author: Pabst Mirror

Description:
  Tests if the unit can detach from the vehicle at the given point
  
Parameters:
  0: OBJECT - unit doing the attaching (usualy the player)
  1: OBJECT - vehicle that it will be attached to (player or vehicle)
  2: STRING - placement point name (self, right, left, back)

Returns:
  BOOL

Example:
  [player, tank, "rear"] call AGM_Attach_fnc_vehicleCanDetach
*/
private ["_unit", "_attachToVehicle", "_attachToPointName", "_modelPosition", "_worldPos", "_unitPos", "_2dDistance"];

_unit = _this select 0;
_attachToVehicle = _this select 1;
_attachToPointName = _this select 2;

_modelPosition = [_attachToVehicle, _attachToPointName] call AGM_Attach_fnc_vehicleGetAttachPoint;
_worldPos = _attachToVehicle modelToWorld _modelPosition;
_unitPos = getPos _unit;

//Just look at the "2d" distance
_worldPos set [2, 0];
_unitPos set [2, 0];
_2dDistance = _worldPos distance _unitPos;

canStand _unit && {alive _attachToVehicle} && {_attachToVehicle getVariable [(format ["AGM_AttachedItemName_%1", _attachToPointName]), ""] != ""} && {_2dDistance < 2.3}
