/*
Name: AGM_Artillery_fnc_simulateCalcRangeTableLine

Author: Pabst Mirror

Description:
  Builds a rangeTable line for a certian range, given muzzle velocity and air friction, returns [] if out of range.

Parameters:
  0: NUMBER - Muzzle Velocity
  1: NUMBER - Air Friction
  2: NUMBER - Range To Hit

Returns:
  ARRAY - Range Table Line Data (see return line)

Example:
  [300, -0.0001, 3000] call AGM_Artillery_fnc_simulateCalcRangeTableLine
*/

#define TIME_STEP (1/50)

private ["_startTime", "_muzzleVelocity", "_rangeToHit", "_airFriction", "_vacElevation", "_radicand", "_maxElev", "_minElev", "_error", "_solutionElevation", "_lastTestResult", "_numberOfAttempts", "_lineElevation", "_lineTimeOfFlight", "_lineHeightElevation", "_lineHeightTime", "_lineCrosswindDeg", "_lineHeadwindMeters", "_lineTailWindMeters", "_result"];

_startTime = diag_tickTime;

_muzzleVelocity = _this select 0;
_rangeToHit = _this select 1;
_airFriction = _this select 2;

//Run Binary search for correct elevation
_solution = [_rangeToHit, 0, _muzzleVelocity, _airFriction, TIME_STEP] call AGM_Artillery_fnc_simulateFindSolution;
if (_solution isEqualTo []) exitWith {[]};

//Real Elevation
_lineElevation = _solution select 0;

//Time Of Flight:
_lineTimeOfFlight = _solution select 1;

//Height Adjustment for -100m (another binary search)
_solution = [_rangeToHit, -100, _muzzleVelocity, _airFriction, TIME_STEP] call AGM_Artillery_fnc_simulateFindSolution;
if (_solution isEqualTo []) exitWith {[]};//should never be triggered (lower elevation easier to hit)

_lineHeightElevation = ((_solution select 0) - _lineElevation);
// _lineHeightTime = (_lastTestResult select 1) - _lineTimeOfFlight;

//Compute for 10x and divide to minimize rounding errors

//Crosswind
_lastTestResult = [_lineElevation, _muzzleVelocity, _airFriction, 15, 1, 0, 10, 0, TIME_STEP] call AGM_Artillery_fnc_simulateShot;
_lineCrosswindDeg = (_lastTestResult select 2) / 10;

//Headwind:
_lastTestResult = [_lineElevation, _muzzleVelocity, _airFriction, 15, 1, -10, 0, 0, TIME_STEP] call AGM_Artillery_fnc_simulateShot;
_lineHeadwindMeters = (_rangeToHit - (_lastTestResult select 0)) / 10;

//TailWind:
_lastTestResult = [_lineElevation, _muzzleVelocity, _airFriction, 15, 1, 10, 0, 0, TIME_STEP] call AGM_Artillery_fnc_simulateShot;
_lineTailWindMeters = (_rangeToHit - (_lastTestResult select 0)) / 10;

//Air Temp Dec
_lastTestResult = [_lineElevation, _muzzleVelocity, _airFriction, (15 - 10), 1, 0, 0, 0, TIME_STEP] call AGM_Artillery_fnc_simulateShot;
_lineTempDec = (_rangeToHit - (_lastTestResult select 0)) / 10;

//Air Temp Inc
_lastTestResult = [_lineElevation, _muzzleVelocity, _airFriction, (15 + 10), 1, 0, 0, 0, TIME_STEP] call AGM_Artillery_fnc_simulateShot;
_lineTempInc = (_rangeToHit - (_lastTestResult select 0)) / 10;

//Air Density Dec
_lastTestResult = [_lineElevation, _muzzleVelocity, _airFriction, 15, 0.9, 0, 0, 0, TIME_STEP] call AGM_Artillery_fnc_simulateShot;
_lineAirDensDec = (_rangeToHit - (_lastTestResult select 0)) / 10;

//Air Density Inc
_lastTestResult = [_lineElevation, _muzzleVelocity, _airFriction, 15, 1.1, 0, 0, 0, TIME_STEP] call AGM_Artillery_fnc_simulateShot;
_lineAirDensInc = (_rangeToHit - (_lastTestResult select 0)) / 10;

// systemChat format ["debug: Range %1 - in %2 sec", _rangeToHit, (diag_tickTime - _startTime)];

[_rangeToHit, _lineElevation, _lineHeightElevation, _lineTimeOfFlight, _lineCrosswindDeg, _lineHeadwindMeters, _lineTailWindMeters, _lineTempDec, _lineTempInc, _lineAirDensDec, _lineAirDensInc]
