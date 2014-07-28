/*
 * Author: KoffeinFlummi, jodav
 *
 * Initializes the respawn module.
 *
 * Arguments:
 * Whatever the module provides. (I dunno.)
 *
 * Return Value:
 * None 
 */

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(_activated) exitWith {};

AGM_Respawn_Module = true;

AGM_Respawn_SavePreDeathGear = _logic getVariable "SavePreDeathGear";

// It's already a number
AGM_Respawn_BodyRemoveTimer = _logic getVariable "BodyRemoveTimer";

diag_log text "AGM: Respawn Module Initialized.";
