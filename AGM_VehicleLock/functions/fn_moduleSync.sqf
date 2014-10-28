/*
* Author: Pabst Mirror
*
* sync module (sync with vehicles and players and players will get keys for those vehicles)
*
* Argument: from module
*
* Return value:
* none
*/

_this spawn {
	private ["_logic","_activated","_listOfKeys","_keyName"];

	_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
	_units = [_this,1,[],[[]]] call BIS_fnc_param;
	_activated = [_this,2,true,[true]] call BIS_fnc_param;

	sleep 3;	//wait to give keys, so gear assign scripts don't delete it, and allow all setup to complete
	//functionPriority might not make this nessacary
	
	if !(_activated) exitWith {};

	_listOfKeys = [];

	{
		if ((_x isKindOf "Car") || (_x isKindOf "Tank") || (_x isKindOf "Helicopter"))  then {
			_keyName = [_x] call AGM_VehicleLock_fnc_getVehiclesKeyName;
			if (!(_keyName in _listOfKeys)) then {
				_listOfKeys pushBack _keyName;
			};
		};
	} forEach _units;

	if ((count _listOfKeys) == 0) exitWith {
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