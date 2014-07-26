/*
 * Author: commy2
 *
 * Disables key input. ESC can still be pressed to open the menu.
 *
 * Argument:
 * 0: True to disable key inputs, false to re-enable them (Bool)
 * 1: Allow Zeus and Team Switch? (Optional; default: no)
 *
 * Return value:
 * Nothing
 */

if (_this select 0) then {
  if (count _this > 1 and {_this select 1}) then {
    if (isNil "AGM_Core_disableUserInput_ehid") then {
      AGM_Core_disableUserInput_ehid = [];
      AGM_Core_disableUserInput_ehid set [0, findDisplay 46 displayAddEventHandler ["KeyDown", {(_this select 1 > 1) and (inputAction "TeamSwitch" == 0) and (inputAction "CuratorInterface" == 0)}]];
      AGM_Core_disableUserInput_ehid set [1, findDisplay 46 displayAddEventHandler ["KeyUp", {(_this select 1 > 1) and (inputAction "TeamSwitch" == 0) and (inputAction "CuratorInterface" == 0)}]];
    };
  } else {
    if (isNil "AGM_Core_disableUserInput_ehid") then {
      AGM_Core_disableUserInput_ehid = [];
      AGM_Core_disableUserInput_ehid set [0, findDisplay 46 displayAddEventHandler ["KeyDown", {_this select 1 > 1}]];
      AGM_Core_disableUserInput_ehid set [1, findDisplay 46 displayAddEventHandler ["KeyUp", {_this select 1 > 1}]];
    };
  };
} else {
  if (!isNil "AGM_Core_disableUserInput_ehid") then {
    findDisplay 46 displayRemoveEventHandler ["KeyDown", AGM_Core_disableUserInput_ehid select 0];
    findDisplay 46 displayRemoveEventHandler ["KeyUp", AGM_Core_disableUserInput_ehid select 1];
    AGM_Core_disableUserInput_ehid = nil;
  };
};
