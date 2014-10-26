/*
* Author: Pabst Mirror
*
* handles lockpick functionality
*
* Argument:
* 0: User (Object)
* 1: Vehicle (Object)
* 2: function type (String)
*
* Return value:
* bool
*/


//this function handles 3 commands
//	canLockpick: true if _unit can lockpick _veh
//	startLockpick: starts the process
//	finishLockpick: on completions, opens the lock

#define NO_DEFAULT_LOCKPICK_TIME	10

private ["_unit","_veh","_funcType","_defaultStr","_vehLockpickStrenth","_returnValue"];

_unit = [_this, 0, objNull, [objNull]] call bis_fnc_param;
_veh = 	[_this, 1, objNull, [objNull]] call bis_fnc_param;
_funcType = [_this, 2, "", [""]] call bis_fnc_param;

if (isNull _unit) exitWith {false};
if (!alive _unit) exitWith {false};
if (isNull _veh) exitWith {false};
if (!("AGM_item_key_lockpick" in (items _unit))) exitWith {false};

_defaultStr = if (isNil "AGM_VEHICLELOCK_defaultLockpickStrength") then {NO_DEFAULT_LOCKPICK_TIME} else {AGM_VEHICLELOCK_defaultLockpickStrength};
_vehLockpickStrenth = _veh getVariable ["agm_vehicleLock_pickStr", _defaultStr];
if (typeName _vehLockpickStrenth != "SCALAR") exitWith {systemChat format ["%1 - agm_vehicleLock_pickStr invalid", _veh]; false};

if (_vehLockpickStrenth == -1) exitWith {false};

_returnValue = false;
switch (_funcType) do {
case ("canLockpick"): {
		_returnValue = true;
	};
case ("startLockpick"): {
		[_vehLockpickStrenth, [_unit, _veh, "finishLockpick"], "AGM_VehicleLock_fnc_lockpick", "Picking Lock"] call AGM_Core_fnc_progressBar;
	};
case ("finishLockpick"): {
		[_veh, false] call AGM_VehicleLock_fnc_setVehicleLock;
	};
};

_returnValue;