// by commy2

if (isDedicated) exitWith {};

AGM_Hearing_firedNearEH = compile preprocessFileLineNumbers "\AGM_Hearing\scripts\firedNearEH.sqf";

player addEventHandler ["firedNear", _this call AGM_Hearing_firedNearEH];
