/*
Name: AGM_GetIn_fnc_moduleAllowEnemies

Author: Pabst Mirror

Description:
  Function for setup module. Sets AGM_GetIn_canBoardEnemyVehicle, which allows the getIn interaction to force a moveIn on a hostile vehicle

Parameters:
  0: OBJECT - logic
  1: ARRAY - synced objects

Returns:
  Nothing

Example:
  called from module
*/
private ["_logic", "_units", "_activated"];

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(_activated) exitWith {};

if (isServer) then {
  [_logic, "AGM_GetIn_canBoardEnemyVehicle", "CanBoardHostileVehicle"] call AGM_Core_fnc_readBooleanParameterFromModule;
};
