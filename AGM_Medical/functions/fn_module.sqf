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

private ["_logic", "_units", "_activated"];

if !(isServer) exitWith {};

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(_activated) exitWith {};

AGM_Medical_Module = true;

[_logic, "AGM_Medical_CoefBleeding",                 "CoefBleeding"                ] call AGM_Core_fnc_readNumericParameterFromModule;
[_logic, "AGM_Medical_CoefPain",                     "CoefPain"                    ] call AGM_Core_fnc_readNumericParameterFromModule;
[_logic, "AGM_Medical_MaxUnconsciousnessTime",       "MaxUnconsciousnessTime"      ] call AGM_Core_fnc_readNumericParameterFromModule;

[_logic, "AGM_Medical_AllowNonMedics",               "AllowNonMedics"              ] call AGM_Core_fnc_readBooleanParameterFromModule;
[_logic, "AGM_Medical_PunishNonMedics",              "PunishNonMedics"             ] call AGM_Core_fnc_readBooleanParameterFromModule;
[_logic, "AGM_Medical_RequireDiagnosis",             "RequireDiagnosis"            ] call AGM_Core_fnc_readBooleanParameterFromModule;
[_logic, "AGM_Medical_PreventInstaDeath",            "PreventInstaDeath"           ] call AGM_Core_fnc_readBooleanParameterFromModule;
[_logic, "AGM_Medical_PreventDeathWhileUnconscious", "PreventDeathWhileUnconscious"] call AGM_Core_fnc_readBooleanParameterFromModule;
[_logic, "AGM_Medical_SingleBandage",                "SingleBandage"               ] call AGM_Core_fnc_readBooleanParameterFromModule;
[_logic, "AGM_Medical_AllowChatWhileUnconscious",    "AllowChatWhileUnconscious"   ] call AGM_Core_fnc_readBooleanParameterFromModule;

diag_log text "[AGM]: Medical Module Initialized.";
