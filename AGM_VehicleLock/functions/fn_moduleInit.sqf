/*
	Name: AGM_VehicleLock_fnc_moduleInit
	
	Author: Pabst Mirror
	
	Description:
		Function for setup module.  Sets default lockpick strength, auto handout keys, and default lock state.
	
	Parameters:
		0: OBJECT - logic
		1: ARRAY - synced objects
	
	Returns:
		Nothing
	
	Example:
		called from module
*/
private ["_logic","_sideKeysAssignment","_setLockState","_lock","_giveSideKey","_keyClassName"];

<<<<<<< HEAD
_this spawn {
=======
#define MAX_KEYS 50

private ["_logic","_activated","_autoSetup","_setLockState","_keysInInventory","_vehiclesToSetupKeys","_index","_lock","_keyClassName"];

_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
_units = [_this,1,[],[[]]] call BIS_fnc_param;
_activated = [_this,2,false,[true]] call BIS_fnc_param;

if !(_activated) exitWith {};

if (isServer) then {
  [_logic, "AGM_VEHICLELOCK_defaultLockpickStrength", "LockpickStrength"] call AGM_Core_fnc_readNumericParameterFromModule;
};

_autoSetup =    _logic getVariable ["InitType", 0];
_setLockState =   _logic getVariable ["SetLockState", 0];
_keysInInventory =  _logic getVariable ["KeysInInventory", 0];

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
>>>>>>> origin/master

  _logic = [_this, 0, objNull, [objNull]] call BIS_fnc_param;
  _units = [_this, 1, [], [[]]] call BIS_fnc_param;

  _sideKeysAssignment = _logic getVariable["SideKeysAssignment", 0];
  _setLockState = _logic getVariable["SetLockState", 0];

  if (isServer) then {
    [_logic, "AGM_VEHICLELOCK_defaultLockpickStrength", "LockpickStrength"] call AGM_Core_fnc_readNumericParameterFromModule;

    { //set lock state
      _lock =
        switch (_setLockState) do {
          case (0): {(locked _x) in [2, 3]};
          case (1):{true};
          case (2):{false};
        };
        [_x, _lock]
        call AGM_VehicleLock_fnc_setVehicleLock;
    }
    forEach vehicles;
  };

  if (hasInterface) then {
    waitUntil {player == player};
    sleep 3;
    waitUntil {
      sleep 1;
      (alive player)
    };

    _giveSideKey =
      switch (_sideKeysAssignment) do {
        case (0): {false};
        case (1): {(leader player) == player};
        case (2): {true};
      };

      if (_giveSideKey) then {
        _keyClassName = switch (playerside) do {
            case (west): {"AGM_item_key_west"};
            case (east): {"AGM_item_key_east"};
            case (resistance): {"AGM_item_key_indp"};
            case (civilian): {"AGM_item_key_civ"};
            default {""};
          };
          if (_keyClassName != "") then {
            player addItem _keyClassName;
          };
      };
  };
};
