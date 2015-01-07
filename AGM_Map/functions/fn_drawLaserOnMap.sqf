/*
Name: AGM_Map_fnc_drawLaserOnMap

Author: Pabst Mirror

Description:
  Checks if there is a valid laser target, and shows it on the map.

Parameters:
  0: CONTROL - The map - ((findDisplay 12) displayCtrl 51)

Returns:
  Nothing

Example:
  called from "Draw" event, setup in clientInit.sqf
*/

#define LASER_MARKER_SIZE 24

private ["_laserTarget", "_turretIndex", "_weapons"];

_laserTarget = objNull;
if ((!isNull (getConnectedUAV AGM_player)) && {[AGM_Player] call AGM_Core_fnc_getUavControlPosition == "GUNNER"}) then {
  if ((getConnectedUAV AGM_player) getVariable ["AGM_showLaserTarget", (AGM_Map_showLaserTargetTo >= 1)]) then {
    _laserTarget = laserTarget (getConnectedUAV AGM_player);
  };
} else {
  if (AGM_player == (vehicle AGM_player)) then {
    if (AGM_player getVariable ["AGM_showLaserTarget", (AGM_Map_showLaserTargetTo >= 2)]) then {
      _laserTarget = laserTarget AGM_player;
    };
  } else {
    _turretIndex = [AGM_Player] call AGM_Core_fnc_getTurretIndex;
    _weapons = (vehicle AGM_player) weaponsTurret _turretIndex;  //Check if player is in turret that has laser
    if ("Laserdesignator_mounted" in ((vehicle AGM_player) weaponsTurret _turretIndex)) then {
      if ((vehicle AGM_player) getVariable ["AGM_showLaserTarget", (AGM_Map_showLaserTargetTo >= 1)]) then {
        _laserTarget = laserTarget (vehicle AGM_player);
      };
    };
  };
};

if (!isNull _laserTarget) then {
  (_this select 0) drawIcon [
  "\A3\ui_f\data\igui\rscingameui\rscoptics\laser_designator_iconLaserOn.paa",
  [1,0,0,1],
  (getPos _laserTarget),
  LASER_MARKER_SIZE, LASER_MARKER_SIZE,
  ((getDir _laserTarget) + 90),
  "", 1, 0.04, "TahomaB", "right"];
};
