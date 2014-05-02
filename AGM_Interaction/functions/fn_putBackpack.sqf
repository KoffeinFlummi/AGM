/*
 * Author: KoffeinFlummi
 *
 * Puts a backpack previously carried ventrally on the ground.
 *
 * Arguments:
 * 0: Unit (Object)
 *
 * Return Values:
 * none
 */

_unit = _this select 0;
_backpack = _unit getVariable ["BWA3_Backpack", objNull];

if (isNull _backpack) exitWith {};

detach _backpack;
_backpack setPosATL [((getPos _unit select 0) + random 5), ((getPos _unit select 1) + random 5), 0];

_unit setVariable ["BWA3_Backpack", objNull, true];