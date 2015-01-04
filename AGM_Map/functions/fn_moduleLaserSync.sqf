/*
Name: AGM_Map_fnc_moduleLaserSync

Author: Pabst Mirror

Description:
  Function for laser sync module.  Any vehicles or players synced with have "AGM_showLaserTarget" set true.  Also handles the parameter.

Parameters:
  0: OBJECT - logic
  1: ARRAY - synced objects (only objects at mission start)

Returns:
  Nothing

Example:
  called from module
*/

private ["_logic","_syncedObjects"];

_logic = [_this, 0, objNull, [objNull]] call BIS_fnc_param;
_syncedObjects = [_this, 1, [], [[]]] call BIS_fnc_param;

if (!isServer) exitWith {};

[_logic, "AGM_Map_showLaserTargetTo", "showLaserTargetTo"] call AGM_Core_fnc_readNumericParameterFromModule;

{
  _vehicle = _x;
  if (_x isKindOf "CAManBase") then {
    _vehicle = vehicle _x;
  };
  _vehicle setVariable ["AGM_showLaserTarget", true, true];
} forEach _syncedObjects;
