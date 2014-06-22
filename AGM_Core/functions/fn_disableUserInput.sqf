/*
 * Author: commy2
 *
 * Disables key input. ESC can still be pressed to open the menu.
 * 
 * Argument:
 * 0: True to disable key inputs, false to re-enable them (Bool)
 * 
 * Return value:
 * Nothing
 */

if (_this select 0) then {
	if (isNil "AGM_Core_disableUserInput_ehid") then {
		AGM_Core_disableUserInput_ehid = findDisplay 46 displayAddEventHandler ["KeyDown", {_this select 1 > 1}];
	};
} else {
	if (!isNil "AGM_Core_disableUserInput_ehid") then {
		findDisplay 46 displayRemoveEventHandler ["KeyDown", AGM_Core_disableUserInput_ehid];
		AGM_Core_disableUserInput_ehid = nil;
	};
};
