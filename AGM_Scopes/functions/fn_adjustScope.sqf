/*
 * Author: KoffeinFlummi
 *
 * Changes the adjustment for the current scope
 *
 * Arguments:
 * 0: Horizontal adjustment
 * 1: Vertical adjustment
 *
 * Return Value:
 * True
 */

private ["_weapons", "_zeroing", "_pitchbankyaw", "_pitch", "_bank", "_yaw", "_hint"];

_weapons = [
  primaryWeapon player,
  secondaryWeapon player,
  handgunWeapon player
];

_zeroing = AGM_Scopes_Adjustment select (_weapons find (currentWeapon player));
_zeroing set [0, (round (((_zeroing select 0) + (_this select 0)) * 10)) / 10];
_zeroing set [1, (round (((_zeroing select 1) + (_this select 1)) * 10)) / 10];

AGM_Scopes_Adjustment set [_weapons find (currentWeapon player), _zeroing];

playSound (["AGM_Scopes_Click_1", "AGM_Scopes_Click_2", "AGM_Scopes_Click_3"] select (floor (random 3)));

// slightly rotate the player if looking through optic
if (cameraView == "GUNNER") then {
  _pitchbankyaw = [player] call AGM_Core_fnc_getPitchBankYaw;
  // these are not exact mil-to-degree conversions, but instead chosen 
  // to minimize the effect of rounding errors
  _pitch = (_pitchbankyaw select 0) + ((_this select 1) * -0.04);
  _bank = _pitchbankyaw select 1;
  _yaw = (_pitchbankyaw select 2) + ((_this select 0) * -0.04);
  [player, _pitch, _bank, _yaw] call AGM_Core_fnc_setPitchBankYaw;
};

_display = uiNamespace getVariable ["AGM_Scopes_ZeroingDisplay", displayNull];
if !(isNull _display) then {
  _vertical = _display displayCtrl 925002;
  _horizontal = _display displayCtrl 925003;
  _vertical ctrlSetText (str (_zeroing select 1));
  _horizontal ctrlSetText (str (_zeroing select 0));
};

true
