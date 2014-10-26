/*
* Author: Pabst Mirror
*
* module to handle auto setup and lockpick strength
*
* Argument: from module
*
* Return value:
* none
*/

_this spawn {
	_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
	_units = [_this,1,[],[[]]] call BIS_fnc_param;
	_activated = [_this,2,true,[true]] call BIS_fnc_param;

	sleep 3;	//wait to give keys, so gear assign scripts don't delete it, and allow all setup to complete
	//functionPriority might not make this nessacary
	
	if !(_activated) exitWith {};

	_listOfKeys = [];

	{
		if (_x isKindOf "Car") then {_listOfKeys pushBack ([_x] call AGM_VehicleLock_fnc_getVehiclesKeyName);};
		if (_x isKindOf "Tank") then {_listOfKeys pushBack ([_x] call AGM_VehicleLock_fnc_getVehiclesKeyName);};
		if (_x isKindOf "Helicopter") then {_listOfKeys pushBack ([_x] call AGM_VehicleLock_fnc_getVehiclesKeyName);};
	} forEach _units;

	if ((count _listOfKeys) < 1) exitWith {
		["fn_moduleSync.sqf: no vehicles synced"] call BIS_fnc_error;		
	};

	if (hasInterface) then {
		waitUntil {player == player};
	
		if (player in _units) then {
			{
				player addItem _x;
			} forEach _listOfKeys;
		};
	};
};