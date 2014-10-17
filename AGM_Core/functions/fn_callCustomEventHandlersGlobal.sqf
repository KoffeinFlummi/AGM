/*
 * Author: commy2
 *
 * Execute all custom event script assigned to this object on every machine.
 *
 * Argument:
 * 0: Object the event handlers are assigned to (Object)
 * 1: Name of the event (String)
 *
 * Return value:
 * None.
 */

[_this, "AGM_Core_fnc_callCustomEventHandlers", 2] call AGM_core_fnc_execRemoteFnc;
