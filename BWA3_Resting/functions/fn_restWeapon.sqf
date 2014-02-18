/*
 * Author: KoffeinFlummi
 *
 * Rests the player's weapon if possible.
 *
 * Arguments:
 * None
 *
 * Return Values:
 * None
 *
 */

#define RESTEDRECOIL 0.6
#define BIPODRECOIL 0.3
#define MAXDISTANCE 0.8
#define MAXANGLE 10
#define CAMSHAKE [1,0.5,5]

private ["_weaponPos", "_weaponDir", "_checkPosMiddle", "_checkPosLeft", "_checkPosRight", "_checkPosUp", "_checkPosDown"];

if (currentWeapon player == "") exitWith {};

// PREPARE INTERSECTS
_weaponPos = player selectionPosition "Weapon";
_weaponDir = player weaponDirection currentWeapon player;
_checkPosMiddle = [
                    _weaponPos select 0 + MAXDISTANCE * _weaponDir select 0,
                    _weaponPos select 1 + MAXDISTANCE * _weaponDir select 1,
                    _weaponPos select 2 + MAXDISTANCE * _weaponDir select 2
                  ];
_checkPosLeft = [
                    _weaponPos select 0 + MAXDISTANCE * sin (((_weaponDir select 0) atan2 (_weaponDir select 1)) + 360 - MAXANGLE),
                    _weaponPos select 1 + MAXDISTANCE * cos (((_weaponDir select 0) atan2 (_weaponDir select 1)) + 360 - MAXANGLE),
                    _weaponPos select 2 + MAXDISTANCE * _weaponDir select 2
                  ];
_checkPosRight = [
                    _weaponPos select 0 + MAXDISTANCE * sin (((_weaponDir select 0) atan2 (_weaponDir select 1)) + MAXANGLE),
                    _weaponPos select 1 + MAXDISTANCE * cos (((_weaponDir select 0) atan2 (_weaponDir select 1)) + MAXANGLE),
                    _weaponPos select 2 + MAXDISTANCE * _weaponDir select 2
                  ];
_checkPosDown = [
                    _weaponPos select 0 + MAXDISTANCE * _weaponDir select 0,
                    _weaponPos select 1 + MAXDISTANCE * _weaponDir select 1,
                    _weaponPos select 2 + MAXDISTANCE * _weaponDir select 2 - MAXDISTANCE * tan MAXANGLE
                  ];

// CHECK FOR APPROPRIATE SURFACE
if (!(lineIntersects [_weaponPos, _checkPosMiddle, player] or
    lineIntersects [_weaponPos, _checkPosLeft, player] or
    lineIntersects [_weaponPos, _checkPosRight, player] or
    lineIntersects [_weaponPos, _checkPosDown, player]
    ) or (speed player) > 1) exitWith {false};

// REST THE WEAPON
player setUnitRecoilCoefficient (RESTEDRECOIL * (unitRecoilCoefficient player));
addCamShake CAMSHAKE;
// apply different animation for sway etc.
hint "Weapon rested.";

BWA3_weaponRested = true;

// CHECK FOR PLAYER MOVING AWAY
[_weaponPos, _checkPosMiddle, _checkPosLeft, _checkPosRight, _checkPosDown] spawn {
  hint format ["%1", _this];
  _weaponPos = _this select 0;
  _checkPosMiddle = _this select 1;
  _checkPosLeft = _this select 2;
  _checkPosRight = _this select 3;
  _checkPosDown = _this select 4;
  while {BWA3_weaponRested} do {
    if (!(lineIntersects [_weaponPos, _checkPosMiddle, player] or
    lineIntersects [_weaponPos, _checkPosLeft, player] or
    lineIntersects [_weaponPos, _checkPosRight, player] or
    lineIntersects [_weaponPos, _checkPosDown, player]
    ) or speed player > 1 or currentWeapon player == "") then {
      [] call BWA3_Resting_fnc_unRestWeapon;
    };
    sleep 0.3;
  };
};