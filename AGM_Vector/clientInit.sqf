// by commy2

player setVariable ["AGM_cooldownVector", 0, false];

AGM_isVectorReady = true;
AGM_vectorKey = [false, false];
AGM_vectorConfig = [0, 0];
AGM_vectorSettings = [false, false, false, false];

AGM_Vector_getDistance = compile preprocessFileLineNumbers "\AGM_Vector\scripts\getDistance.sqf";
AGM_Vector_getDirection = compile preprocessFileLineNumbers "\AGM_Vector\scripts\getDirection.sqf";
AGM_Vector_convertDistance = compile preprocessFileLineNumbers "\AGM_Vector\scripts\convertDistance.sqf";
AGM_Vector_convertDegree = compile preprocessFileLineNumbers "\AGM_Vector\scripts\convertDegree.sqf";
AGM_Vector_convertFOS = compile preprocessFileLineNumbers "\AGM_Vector\scripts\convertFOS.sqf";
AGM_Vector_abort = compile preprocessFileLineNumbers "\AGM_Vector\scripts\abort.sqf";
AGM_Vector_config = compile preprocessFileLineNumbers "\AGM_Vector\scripts\config.sqf";
AGM_Vector_settings = compile preprocessFileLineNumbers "\AGM_Vector\scripts\settings.sqf";
AGM_Vector_tabAzimuthKey = compile preprocessFileLineNumbers "\AGM_Vector\scripts\tabAzimuthKey.sqf";
AGM_Vector_tabDistanceKey = compile preprocessFileLineNumbers "\AGM_Vector\scripts\tabDistanceKey.sqf";
AGM_Vector_modeDistance = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeDistance.sqf";
AGM_Vector_modeDistanceAzimuth = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeDistanceAzimuth.sqf";
AGM_Vector_modeDistanceHeight = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeDistanceHeight.sqf";
AGM_Vector_modeAzimuth = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeAzimuth.sqf";
AGM_Vector_modeAzimuthInclination = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeAzimuthInclination.sqf";
AGM_Vector_modeRelativeDistance = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeRelativeDistance.sqf";
AGM_Vector_modeRelativeDistanceHeight = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeRelativeDistanceHeight.sqf";
AGM_Vector_modeRelativeAzimuthDistance = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeRelativeAzimuthDistance.sqf";
AGM_Vector_modeFallOfShort = compile preprocessFileLineNumbers "\AGM_Vector\scripts\modeFallOfShort.sqf";

0 spawn {
	waitUntil {preloadTitleRsc ["AGM_Digit_Preload", "PLAIN"]};
	waitUntil {preloadTitleRsc ["AGM_Debug_Crosshair", "PLAIN"]};
};

