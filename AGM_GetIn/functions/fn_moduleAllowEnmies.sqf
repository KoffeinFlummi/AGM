/*
Name: AGM_GetIn_fnc_moduleAllowEnmies

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
private ["_logic","_units"];

_logic = [_this, 0, objNull, [objNull]] call BIS_fnc_param;
_units = [_this, 1, [], [[]]] call BIS_fnc_param;

if (isServer) then {
  [_logic, "AGM_GetIn_canBoardEnemyVehicle", "CanBoardHostileVehicle"] call AGM_Core_fnc_readNumericParameterFromModule;
};
