/*
Name: AGM_Artillery_fnc_createFiringSolution

Author: Pabst Mirror

Description:
  Converts numbers into nicely formated strings.

Parameters:
  0: OBJECT - Mortar Vehicle
  1: BOOL   - Program the solution in (setVariable) or just return it
  2: STRING - Magazine Classname
  3: NUMBER - Charage Number

  (4: ARRAY - position of target)
  OR
  (4: NUMBER - rotation in degrees
   5: NUMBER: Horizontal Distance (meters)
   6: NUMBER: Height Difference (meters) - "VERTICAL INTERVAL")
   
Returns:
  ARRAY - [
    solutionElevation (NUMBER - Degrees),
    solutionTime (NUMBER - Second)
  ]

Example:
  [theMortar, true, "shell", 2, [444, 444, 0]] call AGM_Artillery_fnc_createFiringSolution;
*/

#define TIME_STEP (1/50)

private ["_mortarVeh", "_programSolution", "_magazineClassname", "_chargeNumber", "_rotationDegrees", "_horizontalDistance", "_heightDiff", "_targetPosition", "_mortarPos", "_tubeWeaponName", "_fireModes", "_artilleryCharge", "_ammoMaxSpeed", "_ammoClassname", "_ammoAirfriction", "_muzzleVelocity", "_findSolution", "_solutionElevation", "_solutionTime"];

if ((!isNil "AGM_Artillery_computingSolution") && {AGM_Artillery_computingSolution}) exitWith {systemChat "Already Computing Solution";};

AGM_Artillery_computingSolution = true;

_mortarVeh = _this select 0;
_programSolution = _this select 1;  //program it in, or just return data
_magazineClassname = _this select 2;
_chargeNumber = _this select 3;

_rotationDegrees = -1;
_horizontalDistance = -1;
_heightDiff = -1;

if ((typeName (_this select 4)) == "ARRAY") then {
  _targetPosition = _this select 4;
  _mortarPos = getPos _mortarVeh;
  _rotationDegrees = [_mortarPos, _targetPosition] call BIS_fnc_dirTo;
  _heightDiff = ((ATLToASL _targetPosition) select 2) - ((ATLToASL _mortarPos) select 2);
  _mortarPos set [2, 0];
  _targetPosition set [2, 0];
  _horizontalDistance = _mortarPos vectorDistance _targetPosition;
} else {
  _rotationDegrees = _this select 4;
  _horizontalDistance = _this select 5;
  _heightDiff = _this select 6;
};

_tubeWeaponName = if ((typeName _mortarVeh) == "OBJECT") then {  //it's a vehicle object
  currentWeapon _mortarVeh;
} else {  //it's a weaponName string
  _programSolution = false;
  _mortarVeh;
};
_fireModes = getArray (configFile >> "CfgWeapons" >> _tubeWeaponName >> "modes");
if (_chargeNumber > ((count _fireModes) - 1)) exitWith {systemChat "Error: Bad Fire Mode";};
_artilleryCharge = getNumber (configFile >> "CfgWeapons" >> _tubeWeaponName >> (_fireModes select _chargeNumber) >> "artilleryCharge");
_ammoMaxSpeed = getNumber (configFile >> "CfgMagazines" >> (_magazineClassname) >> "initSpeed");
_ammoClassname = getText (configFile >> "CfgMagazines" >> (_magazineClassname) >> "ammo");
_ammoAirfriction = getNumber (configFile >> "CfgAmmo" >> _ammoClassname >> "AGM_Artillery_realAirFriction");

//Muzzle Velocity is from 2 configs: weapon's artilleryCharge  and ammo's initSpeed
_muzzleVelocity = _artilleryCharge * _ammoMaxSpeed;

//compute the solution
_findSolution = [_horizontalDistance, _heightDiff, _muzzleVelocity, _ammoAirfriction, TIME_STEP] call AGM_Artillery_fnc_simulateFindSolution;

_solutionElevation = -1;
_solutionTime = -1;
if ((count _findSolution) > 0) then {
  _solutionElevation = _findSolution select 0;
  _solutionTime = _findSolution select 1;
};

if (_programSolution) then {
  _mortarVeh setVariable ["AGM_Artillery_targetHorziontalDistance", _horizontalDistance, true];
  _mortarVeh setVariable ["AGM_Artillery_targetHeightDiff", _heightDiff, true];
  _mortarVeh setVariable ["AGM_Artillery_targetAzimuth", _rotationDegrees, true];
  _mortarVeh setVariable ["AGM_Artillery_solutionCharge", _chargeNumber, true];
  _mortarVeh setVariable ["AGM_Artillery_solutionElev", _solutionElevation, true];
  _mortarVeh setVariable ["AGM_Artillery_solutionTime", _solutionTime, true];
};

AGM_Artillery_computingSolution = false;

[_solutionElevation, _solutionTime]
