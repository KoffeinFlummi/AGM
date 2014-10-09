/*
 * Author: jodav
 *
 * Initializes the SwitchUnits module.
 *
 * Arguments:
 * Whatever the module provides.
 *
 * Return Value:
 * None
 */
if !(isServer) exitWith {};

_logic = _this select 0;
_activated = _this select 2;

if !(_activated) exitWith {};

AGM_SwitchUnits_Module = true;

[_logic, "AGM_SwitchUnits_EnableSwitchUnits", "EnableSwitchUnits"] call AGM_Core_fnc_readBooleanParameterFromModule;
[_logic, "AGM_SwitchUnits_SwitchUnitsAllowedForSide", "SwitchUnitsAllowedForSide"] call AGM_Core_fnc_readNumericParameterFromModule;

diag_log text "[AGM]: SwitchUnits Module Initialized.";
