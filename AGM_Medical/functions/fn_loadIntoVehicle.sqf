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

_unit = objNull;
if isNull (player getVariable "AGM_Carrying") then {
  _unit = player getVariable "AGM_Dragging";
  player setVariable ["AGM_Dragging", objNull, false];
} else {
  _unit = player getVariable "AGM_Carrying";
  player setVariable ["AGM_Carrying", objNull, false];
};

detach _unit;

//[_unit, format ["{_this playMoveNow '%1'}", ((configfile >> 'CfgMovesMaleSdr' >> 'States' >> animationState _unit >> 'interpolateTo') call BIS_fnc_getCfgData) select 0], 2] call AGM_Core_fnc_execRemoteFnc;

[_unit, _vehicle, player] spawn {
  [-2, {
    _unit = _this select 0;
    _vehicle = _this select 1;
    _player = _this select 2;
    if (local _unit) then {
      _unit moveInCargo _vehicle;
      _unit setVariable ["AGM_OriginalAnim", animationState _unit, true];
    };
  }, _this] call CBA_fnc_globalExecute;
  [player, "", 2] call AGM_Core_fnc_doAnimation;
  sleep 0.2; // make sure unit is in vehicle before changing anim
  [_unit, (((configFile >> "CfgMovesMaleSdr" >> "States" >> animationState _unit >> "interpolateTo") call BIS_fnc_getCfgData) select 0), 1] call AGM_Core_fnc_doAnimation;
};

player removeWeapon "AGM_FakePrimaryWeapon";

player setVariable ["AGM_CanTreat", true, false];
_unit setVariable ["AGM_Treatable", true, true];
