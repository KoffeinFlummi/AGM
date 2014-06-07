/*
 * Author: KoffeinFlummi
 *
 * Initializes the medical module.
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

AGM_Medical_Module = true;

AGM_Medical_CoefBleeding                 = parseNumber (_logic getVariable "CoefBleeding");
AGM_Medical_CoefPain                     = parseNumber (_logic getVariable "CoefPain");
AGM_Medical_AllowNonMedics               = _logic getVariable "AllowNonMedics";
AGM_Medical_PunishNonMedics              = _logic getVariable "PunishNonMedics";
AGM_Medical_RequireDiagnosis             = _logic getVariable "RequireDiagnosis";
AGM_Medical_PreventInstaDeath            = _logic getVariable "PreventInstaDeath";
AGM_Medical_PreventDeathWhileUnconscious = _logic getVariable "PreventDeathWhileUnconscious";

diag_log text "AGM: Medical Module Initialized.";