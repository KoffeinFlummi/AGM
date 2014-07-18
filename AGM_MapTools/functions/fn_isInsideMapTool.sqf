// by CAA-Picard

#define TEXTURE_WIDTH_IN_M    6205
#define DIST_BOTTOM_TO_CENTER_PERC  -0.32
#define DIST_TOP_TO_CENTER_PERC  0.66
#define DIST_LEFT_TO_CENTER_PERC  0.32

_pos = [_this select 0, _this select 1, 0];
_relPos = _pos vectorDiff [AGM_MapTools_pos select 0, AGM_MapTools_pos select 1, 0];
_dirVector = [sin(AGM_MapTools_angle), cos(AGM_MapTools_angle), 0];

_lambdaLong = _dirVector vectorDotProduct _relPos;
_lambdaTrasAbs = vectorMagnitude (_relPos vectorDiff (_dirVector vectorMultiply _lambdaLong));

hint format ["lL, lT = %1 , %2", _lambdaLong, _lambdaTras];

if (_lambdaLong < DIST_BOTTOM_TO_CENTER_PERC * TEXTURE_WIDTH_IN_M) exitWith {false};
if (_lambdaLong > DIST_TOP_TO_CENTER_PERC * TEXTURE_WIDTH_IN_M) exitWith {false};
if (_lambdaTrasAbs > DIST_LEFT_TO_CENTER_PERC * TEXTURE_WIDTH_IN_M) exitWith {false};

true
