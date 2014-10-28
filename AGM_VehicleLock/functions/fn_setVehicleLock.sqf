/*
* Author: Pabst Mirror
*
* sets a vehicle lock state (MP safe)
*
* Argument:
* 0: Vehicle (Object)
* 1: Lock State (Bool)
*
* Return value:
* none
*/

//sets a vehicle lock state, can be run anywhere and it will run where vehicle is local

private ["_veh","_lockState"];

_veh = [_this, 0, objNull, [objNull]] call bis_fnc_param;
_lockState = [_this, 1, false, [false]] call bis_fnc_param;

if (isNull _veh) exitWith {};

if (local _veh) then {
  if (_lockState) then {
    _veh lock 2;
    _veh setVariable ["AGM_LockedInventory", true, true];
  } else {
    _veh lock 0;
    _veh setVariable ["AGM_LockedInventory", false, true];
  };
} else {//run where vehicle is local
  [_this, "AGM_VehicleLock_fnc_setVehicleLock", _veh] call BIS_fnc_MP;
};