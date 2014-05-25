/*
 * Author: KoffeinFlummi
 *
 * Key input handling.
 *
 * Arguments:
 * 0: something
 * 1: key
 * 2: more something
 *
 * Return Values:
 * None
 */

private ["_key"];

_key = _this select 1;

switch true do {
  case (_key == 20) : {[] call AGM_Core_fnc_openInteractionMenu;};
  case (_key == 21) : {[] call AGM_Core_fnc_openSelfMenu;};
  default             {};
};
