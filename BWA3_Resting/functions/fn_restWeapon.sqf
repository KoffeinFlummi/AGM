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
#define MAXDISTANCE 0.7
#define MAXANGLE 5
#define CAMSHAKE [1,0.5,5]

private ["_weaponPos", "_checkPosMiddle", "_checkPosLeft", "_checkPosRight", "_checkPosUp", "_checkPosDown"];

// PREPARE INTERSECTS
_weaponPos = player selectionPosition "Weapon";
_checkPosMiddle = [
                    (_weaponPos select 0 + MAXDISTANCE * sin (getDir player)),
                    (_weaponPos select 1 + MAXDISTANCE * cos (getDir player)),
                    (_weaponPos select 2)
                  ];
_checkPosLeft = [
                    (_weaponPos select 0 + MAXDISTANCE * sin ((getDir player - MAXANGLE) % 360)),
                    (_weaponPos select 1 + MAXDISTANCE * cos ((getDir player - MAXANGLE) % 360)),
                    (_weaponPos select 2)
                  ];
_checkPosRight = [
                    (_weaponPos select 0 + MAXDISTANCE * sin ((getDir player + MAXANGLE) % 360)),
                    (_weaponPos select 1 + MAXDISTANCE * cos ((getDir player + MAXANGLE) % 360)),
                    (_weaponPos select 2)
                  ];
_checkPosUp = [
                    (_weaponPos select 0 + MAXDISTANCE * sin (getDir player)),
                    (_weaponPos select 1 + MAXDISTANCE * cos (getDir player)),
                    (_weaponPos select 2 + MAXDISTANCE * tan MAXANGLE)
                  ];
_checkPosDown = [
                    (_weaponPos select 0 + MAXDISTANCE * sin (getDir player)),
                    (_weaponPos select 1 + MAXDISTANCE * cos (getDir player)),
                    (_weaponPos select 2 - MAXDISTANCE * tan MAXANGLE)
                  ];

// CHECK FOR APPROPRIATE SURFACE
if !(lineIntersects [_weaponPos, _checkPosMiddle, player] or
    lineIntersects [_weaponPos, _checkPosLeft, player] or
    lineIntersects [_weaponPos, _checkPosRight, player] or
    lineIntersects [_weaponPos, _checkPosUp, player] or
    lineIntersects [_weaponPos, _checkPosDown, player]
    ) exitWith {false};

// REST THE Weapon
player setUnitRecoilCoefficient BWA3_weaponRested;
addCamShake CAMSHAKE;
// apply different animation for sway etc.
hint "Weapon rested."
BWA3_weaponRested = true;

0 spawn {
  while {BWA3_weaponRested} do {
    if !(lineIntersects [_weaponPos, _checkPosMiddle, player] or
    lineIntersects [_weaponPos, _checkPosLeft, player] or
    lineIntersects [_weaponPos, _checkPosRight, player] or
    lineIntersects [_weaponPos, _checkPosUp, player] or
    lineIntersects [_weaponPos, _checkPosDown, player]
    ) then {
      [] call BWA3_Resting_fnc_unRestWeapon.sqf;
    };
    sleep 0.3;
  };
};