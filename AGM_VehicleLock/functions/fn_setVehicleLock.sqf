/*
  Name: AGM_VehicleLock_fnc_setVehicleLock

  Author: Pabst Mirror

  Description:
    Sets a vehicle lock state (MP safe)

  Parameters:
    0: OBJECT - vehicle
    1: BOOL - new lock state

  Returns:
    Nothing

  Example:
    [tank1, false] call AGM_VehicleLock_fnc_setVehicleLock;
*/

private ["_veh","_isLocked","_lockNumber"];

_veh = [_this, 0, objNull, [objNull]] call bis_fnc_param;
_isLocked = [_this, 1, false, [false]] call bis_fnc_param;

if (isNull _veh) exitWith {["AGM_VehicleLock_fnc_setVehicleLock: null vehicle"] call BIS_fnc_error;};

_lockNumber = if (_isLocked) then {2} else {0};

//this will work on people without this mod
[[_veh, _lockNumber], "lock", _veh] call BIS_fnc_MP;
_veh setVariable ["AGM_LockedInventory", _isLocked, true];