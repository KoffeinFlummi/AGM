/*
 * Author: KoffeinFlummi
 *
 * Handles key input for weapon resting.
 *
 * Arguments:
 * 0: something
 * 1: dik code
 * 2: something
 * 3: more something
 * 
 * Return Values:
 * None 
 *
 */

if (player getVariable "AGM_Unconscious") exitWith {false};

_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode;
_vehicle = vehicle player;
_isInput = false;

if (_keyCode == profileNamespace getVariable "AGM_Key_restWeapon") then {
	if (AGM_weaponRested) then {
		[] call AGM_Resting_fnc_unRestWeapon;
	} else {
		[] call AGM_Resting_fnc_restWeapon;
	};
	_isInput = true;
};
_isInput
