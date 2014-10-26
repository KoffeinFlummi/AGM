/*
* Author: Pabst Mirror
*
* Checks if user has a valid key for the vehicle
*
* Argument:
* 0: User (Object)
* 1: Vehicle (Object)
*
* Return value:
* bool
*/

private ["_unit","_veh","_vehKeyRequired"];


_unit = [_this, 0, objNull, [objNull]] call bis_fnc_param;
_veh = 	[_this, 1, objNull, [objNull]] call bis_fnc_param;

if (isNull _unit) exitWith {false};
if (isNull _veh) exitWith {false};

if ("AGM_item_key_master" in (items _unit)) exitWith {
	true
};

_vehKeyRequired = [_veh] call AGM_VehicleLock_fnc_getVehiclesKeyName;

(_vehKeyRequired in (items _unit))