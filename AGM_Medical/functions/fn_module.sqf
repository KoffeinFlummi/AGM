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

["AGM_Medical_CoefBleeding",                parseNumber (_logic getVariable "CoefBleeding")]                          call AGM_Core_fnc_setParameter;
["AGM_Medical_CoefPain",                    parseNumber (_logic getVariable "CoefPain")]                              call AGM_Core_fnc_setParameter;
["AGM_Medical_MaxUnconsciousnessTime",      parseNumber (_logic getVariable "MaxUnconsciousnessTime")]                call AGM_Core_fnc_setParameter;
["AGM_Medical_AllowNonMedics",              if (_logic getVariable "AllowNonMedics") then {1} else {0}]               call AGM_Core_fnc_setParameter;
["AGM_Medical_PunishNonMedics",             if (_logic getVariable "PunishNonMedics") then {1} else {0}]              call AGM_Core_fnc_setParameter;
["AGM_Medical_RequireDiagnosis",            if (_logic getVariable "RequireDiagnosis") then {1} else {0}]             call AGM_Core_fnc_setParameter;
["AGM_Medical_PreventInstaDeath",           if (_logic getVariable "PreventInstaDeath") then {1} else {0}]            call AGM_Core_fnc_setParameter;
["AGM_Medical_PreventDeathWhileUnconscious",if (_logic getVariable "PreventDeathWhileUnconscious") then {1} else {0}] call AGM_Core_fnc_setParameter;
["AGM_Medical_SingleBandage",               if (_logic getVariable "SingleBandage") then {1} else {0}]                call AGM_Core_fnc_setParameter;

diag_log text "[AGM]: Medical Module Initialized.";