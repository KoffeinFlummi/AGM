/*
	Name: AGM_VehicleLock_fnc_moduleSync
	
	Author: Pabst Mirror
	
	Description:
		Function for sync module.  Assigns keys for all synced vehicles to any players that are synced.
	
	Parameters:
		0: OBJECT - logic
		1: ARRAY - synced objects
	
	Returns:
		Nothing
	
	Example:
		called from module
*/
_this spawn {
<<<<<<< HEAD
  private ["_logic","_syncedObjects","_listOfVehicles"];

  _logic = [_this, 0, objNull, [objNull]] call BIS_fnc_param;
  _syncedObjects = [_this, 1, [], [[]]] call BIS_fnc_param;

  if (hasInterface) then {
    waitUntil {player == player};
    sleep 3;
    waitUntil {
      sleep 1;
      (alive player)
    };

    _listOfVehicles = []; {
      if ((_x isKindOf "Car") || (_x isKindOf "Tank") || (_x isKindOf "Helicopter")) then {
        _listOfVehicles pushBack _x;
      };
    } forEach _syncedObjects;

    if ((count _listOfVehicles) == 0) exitWith {
      ["AGM_VehicleLock_fnc_moduleSync: no valid vehicles synced"] call BIS_fnc_error;
    };

    if (player in _syncedObjects) then {
      {
        if (!([player, _x] call AGM_VehicleLock_fnc_hasKeyForVehicle)) then {
          [player, _x, true] call AGM_VehicleLock_fnc_addKeyForVehicle;
        };
      } forEach _listOfVehicles;
=======
  private ["_logic","_activated","_listOfKeys","_keyName"];

  _logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
  _units = [_this,1,[],[[]]] call BIS_fnc_param;
  _activated = [_this,2,true,[true]] call BIS_fnc_param;

  sleep 3;  //wait to give keys, so gear assign scripts don't delete it, and allow all setup to complete
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
>>>>>>> origin/master
    };
  };
};