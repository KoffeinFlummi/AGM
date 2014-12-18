/*
 * Author: commy2
 *
 * Called from respawn eventhandler. Resets all public object namespace variables that are added via AGM_Core_fnc_setVariableJIP.
 *
 * Argument:
 * 0: Object (Object)
 *
 * Return value:
 * Nothing.
 */

private ["_unit", "_respawnVariables"];

_unit = _this select 0;

_respawnVariables = _unit getVariable ["AGM_respawnVariables", []];

// yes those
_respawnVariables pushBack "AGM_PersistentFunctions";

{
  _unit setVariable [_x, _unit getVariable _x, true];
} forEach _respawnVariables;
