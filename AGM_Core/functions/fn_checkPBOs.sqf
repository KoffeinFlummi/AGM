/*
 * Author: commy2
 *
 * Used to execute the checkPBOs module without placing the module. Don't use this together with the module.
 *
 * Argument:
 * 0: Mode (Number)
 *   0:	Warn once
 *   1:	Warn permanently
 *   2:	Kick
 *
 * Return value:
 * None.
 */

private ["_mode", "_logic"];

_mode = _this select 0;

_logic = "Logic" createVehicleLocal [0,0,0];
_logic setVariable ["Action", _mode];
[_logic, [], true] call AGM_Core_fnc_moduleCheckPBOs;
deleteVehicle _logic;
