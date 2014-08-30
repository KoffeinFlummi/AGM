/*
 * Author: KoffeinFlummi
 * 
 * Checks if a unit is diagnosed and if that's even necessary.
 *
 * Arguments:
 * 0: Unit to be treated.
 *
 * Return Value:
 * Is unit diagnosed? (Bool)
 */

private ["_unit"];

_unit = _this select 0;

if (AGM_Medical_RequireDiagnosis == 0) exitWith {true};
if !(_unit getVariable "AGM_Unconscious") exitWith {true};

(_unit getVariable ["AGM_Diagnosed", true])
