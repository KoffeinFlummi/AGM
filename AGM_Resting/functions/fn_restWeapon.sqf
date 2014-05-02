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
#define MAXDISTANCE 1
#define MAXANGLE 15
#define MAXHEIGHT 0.45
#define CAMSHAKE [1,0.5,5]

private ["_weaponPos", "_weaponDir", "_checkPosMiddle", "_checkPosLeft", "_checkPosRight", "_checkPosUp", "_checkPosDown"];

if (currentWeapon player != primaryWeapon player or vehicle player != player) exitWith {};

// PREPARE INTERSECTS
AGM_Resting_checkIntersection = {
  _weaponPos = ATLtoASL (player modelToWorld (player selectionPosition "RightHand"));
  _weaponDir = player weaponDirection (currentWeapon player);
  _weaponPosDown = [
                      _weaponPos select 0,
                      _weaponPos select 1,
                      (_weaponPos select 2) - MAXHEIGHT
                    ];
  _checkPosMiddle = [
                      (_weaponPos select 0) + MAXDISTANCE * (_weaponDir select 0),
                      (_weaponPos select 1) + MAXDISTANCE * (_weaponDir select 1),
                      (_weaponPos select 2) + MAXDISTANCE * (_weaponDir select 2)
                    ];
  _checkPosLeft = [
                      (_weaponPos select 0) + MAXDISTANCE * sin (((_weaponDir select 0) atan2 (_weaponDir select 1)) + 360 - MAXANGLE),
                      (_weaponPos select 1) + MAXDISTANCE * cos (((_weaponDir select 0) atan2 (_weaponDir select 1)) + 360 - MAXANGLE),
                      (_weaponPos select 2) + MAXDISTANCE * (_weaponDir select 2)
                    ];
  _checkPosRight = [
                      (_weaponPos select 0) + MAXDISTANCE * sin (((_weaponDir select 0) atan2 (_weaponDir select 1)) + MAXANGLE),
                      (_weaponPos select 1) + MAXDISTANCE * cos (((_weaponDir select 0) atan2 (_weaponDir select 1)) + MAXANGLE),
                      (_weaponPos select 2) + MAXDISTANCE * (_weaponDir select 2)
                    ];
  _checkPosDown = [
                      (_weaponPos select 0) + MAXDISTANCE * (_weaponDir select 0),
                      (_weaponPos select 1) + MAXDISTANCE * (_weaponDir select 1),
                      (_weaponPos select 2) + MAXDISTANCE * (_weaponDir select 2) - MAXHEIGHT
                    ];

  /* UNCOMMENT THIS FOR DEBUGGING
  weaponPos = ASLtoATL _weaponPos;
  weaponPosDown = ASLtoATL _weaponPosDown;
  checkPosMiddle = ASLtoATL _checkPosMiddle;
  checkPosLeft = ASLtoATL _checkPosLeft;
  checkPosRight = ASLtoATL _checkPosRight;
  checkPosDown = ASLtoATL _checkPosDown;

  onEachFrame {
    drawLine3D [weaponPos, checkPosMiddle, [1,0,0,1]];
    drawLine3D [weaponPos, checkPosLeft, [1,0,0,1]];
    drawLine3D [weaponPos, checkPosRight, [1,0,0,1]];
    drawLine3D [weaponPosDown, checkPosDown, [1,0,0,1]];
  };
  */

  if ((lineIntersects [_weaponPos, _checkPosMiddle] or
      lineIntersects [_weaponPos, _checkPosLeft] or
      lineIntersects [_weaponPos, _checkPosRight] or
      lineIntersects [_weaponPosDown, _checkPosDown] or
      terrainIntersectASL [_weaponPosDown, _checkPosDown]
      ) and (speed player) < 1 and currentWeapon player == primaryWeapon player and vehicle player == player) then {
    true
  } else {
    false
  };
};

// CHECK FOR APPROPRIATE SURFACE
if (call AGM_Resting_checkIntersection) then {
  AGM_weaponRested = true;
  AGM_restedPosition = getPos player;

  // REST THE WEAPON
  addCamShake CAMSHAKE;
  if (getNumber(configFile >> "CfgWeapons" >> (currentWeapon player) >> "AGM_Bipod") == 1 and (stance player) == "PRONE") then {
    player setUnitRecoilCoefficient (BIPODRECOIL * (unitRecoilCoefficient player));
    player switchMove format ["%1_bwa3_deploy", (animationState player)];
    ["Bipod deployed.", false] spawn AGM_Hint_displayText;
  } else {
    player setUnitRecoilCoefficient (RESTEDRECOIL * (unitRecoilCoefficient player));
    player switchMove format ["%1_bwa3_rested", (animationState player)];
    ["Weapon rested.", false] spawn AGM_Hint_displayText;
  };

  // CHECK FOR PLAYER MOVING AWAY, CHANGING WEAPONS ETC
  0 spawn {
    while {AGM_weaponRested} do {
      if (!(call AGM_Resting_checkIntersection) or (getPos player) distance AGM_restedPosition > 1) then {
        [] call AGM_Resting_fnc_unRestWeapon;
      };
      sleep 0.3;
    };
  };
};
