/*
Name: AGM_Artillery_fnc_rangerFinderStart

Author: Pabst Mirror

Description:
  Called when mortar range key is pressed.
  If key is held long enough, when released a firing solution is calculated and saved to mortar.

Parameters:
  0: OBJECT - Mortar Vehicle

Returns:
  NONE

Example:
  [theMortar] call AGM_Artillery_fnc_rangerFinderStart
  called from AGM_Core_Default_Keys
*/

#define MIN_TIME_TABDOWN 0.3

_this spawn {
  private ["_mortarVeh", "_timeStart"];

  _mortarVeh = _this select 0;

  _timeStart = time;

  waitUntil {
    (!AGM_Artillery_rangefinderKeyDown) || {(vehicle AGM_player) != _mortarVeh}
  };

  if ((vehicle AGM_player) != _mortarVeh) exitWith {};  //player not in mortar
  if (!(_mortarVeh getVariable ["AGM_Artillery_rangefinderEnabled", false])) exitWith {};  //should never get here without it set true
  if ((isNil "AGM_Artillery_currentWeaponSettings") || {(count AGM_Artillery_currentWeaponSettings) != 6}) exitWith {};  //if weaponSettings isn't valid
  if ((time - _timeStart) < MIN_TIME_TABDOWN) exitWith {}; //only update on 'long' presses of TAB

  [_mortarVeh,
  true,
  (AGM_Artillery_currentWeaponSettings select 1),
  (AGM_Artillery_currentWeaponSettings select 2),
  (AGM_Artillery_currentWeaponSettings select 3),
  (AGM_Artillery_currentWeaponSettings select 4),
  (AGM_Artillery_currentWeaponSettings select 5)] spawn AGM_Artillery_fnc_createFiringSolution;
};
