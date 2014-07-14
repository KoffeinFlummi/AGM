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
if !(isServer) exitWith {};

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(_activated) exitWith {};

AGM_Medical_Module = true;

["AGM_Medical_CoefBleeding",                parseNumber (_logic getVariable "CoefBleeding")]   call AGM_Core_fnc_setParameter;
["AGM_Medical_CoefPain",                    parseNumber (_logic getVariable "CoefPain")]       call AGM_Core_fnc_setParameter;
["AGM_Medical_AllowNonMedics",              _logic getVariable "AllowNonMedics"]               call AGM_Core_fnc_setParameter;
["AGM_Medical_PunishNonMedics",             _logic getVariable "PunishNonMedics"]              call AGM_Core_fnc_setParameter;
["AGM_Medical_RequireDiagnosis",            _logic getVariable "RequireDiagnosis"]             call AGM_Core_fnc_setParameter;
["AGM_Medical_PreventInstaDeath",           _logic getVariable "PreventInstaDeath"]            call AGM_Core_fnc_setParameter;
["AGM_Medical_PreventDeathWhileUnconscious",_logic getVariable "PreventDeathWhileUnconscious"] call AGM_Core_fnc_setParameter;

diag_log text "AGM: Medical Module Initialized.";