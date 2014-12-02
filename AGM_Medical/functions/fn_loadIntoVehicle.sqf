/*
 * Author: KoffeinFlummi
 *
 * Loads the carried/dragged unit into a vehicle for transport.
 *
 * Arguments:
 * 0: The vehicle
 *
 * Return Value:
 * -
 */

private ["_unit", "_vehicle"];

_vehicle = _this select 0;
_unit = AGM_player getVariable "AGM_Transporting";

if ((count _this < 2) and {!(local _unit)}) exitWith {
  [[_this select 0, AGM_player], "AGM_Medical_fnc_loadIntoVehicle", _unit] call AGM_Core_fnc_execRemoteFnc;
};

if (count _this > 1) then {
  AGM_player = _this select 1;
  _unit = AGM_player getVariable "AGM_Transporting";
};

AGM_player setVariable ["AGM_Transporting", objNull, True];

detach _unit;
_unit moveInCargo _vehicle;

[AGM_player, "", 2, True] call AGM_Core_fnc_doAnimation;
_unit spawn {
  sleep 0.5;
  _unit setVariable ["AGM_OriginalAnim", animationState _unit, True];
  [
    _unit,
    ((configFile >> "CfgMovesMaleSdr" >> "States" >> animationState _unit >> "interpolateTo") call BIS_fnc_getCfgData) select 0,
    2,
    True
  ] call AGM_Core_fnc_doAnimation;
};

AGM_player removeWeapon "AGM_FakePrimaryWeapon";
AGM_player setVariable ["AGM_canTreat", True, True];
_unit setVariable ["AGM_isTreatable", True, True];
