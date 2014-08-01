/*
 * Author: KoffeinFlummi, jodav, CAA-Picard
 *
 * Initializes the respawn module.
 *
 * Arguments:
 * Whatever the module provides. (I dunno.)
 *
 * Return Value:
 * None 
 */
if !(isServer) exitWith {};

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(_activated) exitWith {};

AGM_Respawn_Module = true;

["AGM_Respawn_SavePreDeathGear", if (_logic getVariable "SavePreDeathGear") then {1} else {0}] call AGM_Core_fnc_setParameter;
["AGM_Respawn_RemoveDeadBodies", if (_logic getVariable "RemoveDeadBodies") then {1} else {0}] call AGM_Core_fnc_setParameter;

// It's already a number
["AGM_Respawn_BodyRemoveTimer",  _logic getVariable "BodyRemoveTimer"] call AGM_Core_fnc_setParameter;

diag_log text "[AGM]: Respawn Module Initialized.";
