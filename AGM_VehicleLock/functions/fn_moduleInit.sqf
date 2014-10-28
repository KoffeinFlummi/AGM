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

#define MAX_KEYS 50

private ["_logic","_activated","_autoSetup","_setLockState","_keysInInventory","_vehiclesToSetupKeys","_index","_lock","_keyClassName"];

_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
_units = [_this,1,[],[[]]] call BIS_fnc_param;
_activated = [_this,2,false,[true]] call BIS_fnc_param;

if !(_activated) exitWith {};

if (isServer) then {
	[_logic, "AGM_VEHICLELOCK_defaultLockpickStrength", "LockpickStrength"] call AGM_Core_fnc_readNumericParameterFromModule;
};

_autoSetup = 		_logic getVariable ["InitType", 0];
_setLockState = 	_logic getVariable ["SetLockState", 0];
_keysInInventory = 	_logic getVariable ["KeysInInventory", 0];

if (isServer) then {
	if (_autoSetup == 1) then {
		//shuffle vehicles and assign random keyNumbers for each vehicle
		_vehiclesToSetupKeys = vehicles call BIS_fnc_arrayShuffle;
		{
			_index = _forEachIndex % MAX_KEYS;
			_x setVariable ["AGM_VehicleLock_type", _index, true];
		} forEach _vehiclesToSetupKeys;
		// AGM_VEHICLELOCK_uniqueKeyCount = (count _vehiclesToSetupKeys);
	};

	{
		//set lock state
		_lock = switch (_setLockState) do {
		case (0): {(locked _x) in [2, 3]};
		case (1): {true};
		case (2): {false};
		};
		[_x, _lock] call AGM_VehicleLock_fnc_setVehicleLock;
		
		//put keys into vehicles
		if (_keysInInventory > 0) then {
			_keyClassName = [_x] call AGM_VehicleLock_fnc_getVehiclesKeyName;
			[_x, _keyClassName, _keysInInventory] spawn {
				//delay so gear assigns don't conflict
				sleep 3;
				(_this select 0) addItemCargoGlobal [(_this select 1), (_this select 2)];
			};
		};
	} forEach vehicles;
};

