/*
* Author: Pabst Mirror
*
* Get name of key item for a vehicle
*
* Argument:
* 0: Vehicle (Object)
*
* Return value:
* string
*
* Example: 	[hunter] call AGM_VehicleLock_fnc_getVehiclesKeyName; 		returns "AGM_item_key_west"
*
*/

#define MAX_KEYS 50

private ["_veh","_vehicleConfigSide","_lockType","_keySuffix","_vehKeyRequired"];

_veh = 	[_this, 0, objNull, [objNull]] call bis_fnc_param;

if (isNull _veh) exitWith {
	["fn_getVehiclesKeyName.sqf: null vehicle"] call BIS_fnc_error;		
	"AGM_item_key_null"
};

_vehicleConfigSide = [_veh, true] call bis_fnc_objectSide;
_lockType = _veh getVariable ["AGM_VehicleLock_type", _vehicleConfigSide];
_keySuffix = "null";

switch (typeName _lockType) do {
case ("SIDE"): {
		switch (_lockType) do {
		case (west): 			{_keySuffix = "west"};
		case (east):		 	{_keySuffix = "east"};
		case (resistance): 		{_keySuffix = "indp"};
		case (civilian): 		{_keySuffix = "civ"};
		};
	};
case ("SCALAR"): {
		if ((_lockType >= 0) && (_lockType < MAX_KEYS)) then {
			_keySuffix = str _lockType;
		};
	};
};

if (_keySuffix == "null") then {
	["%1: AGM_VehicleLock_type is bad", _veh] call BIS_fnc_error;
};

_vehKeyRequired = format ["AGM_item_key_%1", _keySuffix];

_vehKeyRequired