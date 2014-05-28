/*
 * Author: KoffeinFlummi
 *
 * Handles deafness due to large-caliber weapons going off near the player.
 *
 * Arguments:
 * -> FiredNear Event Handler
 *
 * Return Value:
 * none
 */

_unit = _this select 0;
_firer = _this select 1;
_distance = (_this select 2) max 1;
_weapon = _this select 3;
_muzzle = _this select 4;
_mode = _this select 5;
_ammo = _this select 6;

if (_weapon in ["Throw", "Put"]) exitWith {};
if (player != vehicle player and !([player] call AGM_Core_fnc_isTurnedOut)) exitWith {};

_loudness = (getNumber (configFile >> "CfgAmmo" >> _ammo >> "audibleFire")) / 64;
_strength = _loudness - (_loudness/50 * _distance); // linear drop off

if (_strength < 0.01) exitWith {};

_strength spawn {
  sleep 0.2;
  [_this] call AGM_Hearing_fnc_earRinging;
};
