/*
 * Author: KoffeinFlummi
 *
 * Unloads the wounded units from the vehicle.
 *
 * Arguments:
 * 0: The vehicle
 *
 * Return Value:
 * -
 */

 private ["_vehicle", "_player", "_pos"];

_vehicle = _this select 0;
_player = call AGM_Core_fnc_player;

{
  if (_x getVariable "AGM_isUnconscious") then {
    _pos = [
      (getPos _player select 0) + (random 2) - 1,
      (getPos _player select 1) + (random 2) - 1,
      0
    ];
    // messy, but who cares?
    [[_x, _vehicle, _player, _pos], "moveOut (_this select 0); waitUntil {vehicle (_this select 0) == (_this select 0)}; (_this select 0) setPosATL (_this select 3); [(_this select 0), 'Unconscious', 2, True] call AGM_Core_fnc_doAnimation;", _x] call AGM_Core_fnc_execRemoteFnc;
    _x setVariable ["AGM_OriginalAnim", "AmovPpneMstpSnonWnonDnon", True];
  };
} forEach crew _vehicle;
