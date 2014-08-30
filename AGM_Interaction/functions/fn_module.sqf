/*
 * Author: CAA-Picard
 *
 * Initializes the interaction module.
 *
 * Arguments:
 * Whatever the module provides.
 *
 * Return Value:
 * None
 */
if !(isServer) exitWith {};

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(_activated) exitWith {};

AGM_Interaction_Module = true;

[_logic, "AGM_Interaction_PlayerNamesViewDistance",  "PlayerNamesViewDistance"     ] call AGM_Core_fnc_readNumericParameterFromModule;

diag_log text "[AGM]: Interaction Module Initialized.";
