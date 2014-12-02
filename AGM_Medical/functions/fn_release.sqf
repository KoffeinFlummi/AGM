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

private ["_unit"];

_unit = _this select 0;

AGM_player removeWeapon "AGM_FakePrimaryWeapon";
AGM_player setVariable ["AGM_Transporting", objNull, True];
AGM_player setVariable ["AGM_canTreat", true, false];
_unit setVariable ["AGM_isTreatable", True, True];

detach _unit;

AGM_player removeAction (AGM_player getVariable "AGM_Medical_ReleaseID");

// animation was already handled by fnc_loadIntoVehicle
if (vehicle _unit != _unit) exitWith {};

if (vehicle AGM_player == AGM_player) then {
  [AGM_player, "", 2, True] call AGM_Core_fnc_doAnimation;
};
if (_unit getVariable "AGM_isUnconscious") then {
  [_unit, "Unconscious", 2, True] call AGM_Core_fnc_doAnimation;
};
