/*
 * Author: KoffeinFlummi
 *
 * Initializes the check-PBOs module.
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

AGM_Version_checkMode = parseNumber (_logic getVariable "Action");

diag_log text "AGM: Check-PBOs Module Initialized.";
