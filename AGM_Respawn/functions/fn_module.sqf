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

[_logic, "AGM_Respawn_BodyRemoveTimer",              "BodyRemoveTimer"             ] call AGM_Core_fnc_readNumericParameterFromModule;

[_logic, "AGM_Respawn_SavePreDeathGear",             "SavePreDeathGear"            ] call AGM_Core_fnc_readBooleanParameterFromModule;
[_logic, "AGM_Respawn_RemoveDeadBodies",             "RemoveDeadBodies"            ] call AGM_Core_fnc_readBooleanParameterFromModule;

if (isMultiplayer && {isServer} && {AGM_Respawn_RemoveDeadBodies > 0}) then {
	["AGM_RemoveDisconnectedPlayer", "onPlayerDisconnected", {call AGM_Respawn_fnc_removeDisconnectedPlayer}, [true]] call BIS_fnc_addStackedEventHandler; 
};

diag_log text "[AGM]: Respawn Module Initialized.";

