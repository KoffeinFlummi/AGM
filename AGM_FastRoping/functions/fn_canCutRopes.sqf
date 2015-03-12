/*
  Name: AGM_FastRoping_fnc_canCutRopes
  
  Author: Matthew Graham (JonBons)
  
  Description:
    Checks if a unit can cut ropes
  
  Parameters: 
    0: OBJECT - unit
    1: OBJECT - vehicle
  
  Returns:
    Boolean
  
  Example:
    [player, vehicle] call AGM_FastRoping_fnc_canCutRopes;
*/
private ["_unit", "_vehicle", "_isCrew"];

_unit = _this select 0;
_vehicle = _this select 1;

if (AGM_FastRoping_RequireCrew) then {
  _isCrew = _unit in ([_vehicle, ["driver", "commander", "gunner", "turret"]] call AGM_Core_fnc_getVehicleCrew);
} else {
  _isCrew = false;
};

if (AGM_FastRoping_RequireCrew && {!_isCrew}) exitWith {false};

true
