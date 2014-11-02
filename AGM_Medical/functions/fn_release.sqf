/*
 * Author: KoffeinFlummi
 *
 * Releases the given unit.
 *
 * Argument:
 * 0: Unit to be released (Object)
 *
 * Return value:
 * none
 */

private ["_unit", "_player"];

_unit = _this select 0;
_player = call AGM_Core_fnc_player;

_player removeWeapon "AGM_FakePrimaryWeapon";
_player setVariable ["AGM_Transporting", objNull, True];
_player setVariable ["AGM_canTreat", true, false];
_unit setVariable ["AGM_isTreatable", True, True];

detach _unit;

_player removeAction (_player getVariable "AGM_Medical_ReleaseID");

// animation was already handled by fnc_loadIntoVehicle
if (vehicle _unit != _unit) exitWith {};

if (vehicle _player == _player) then {
  [_player, "", 2, True] call AGM_Core_fnc_doAnimation;
};
if (_unit getVariable "AGM_isUnconscious") then {
  [_unit, "Unconscious", 2, True] call AGM_Core_fnc_doAnimation;
};
