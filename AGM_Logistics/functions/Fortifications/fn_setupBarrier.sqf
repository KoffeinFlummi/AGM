// by Garth de Wet (LH), edited by commy2

_this spawn {
	_unit = _this select 0;

	AGM_Fortifications_placer = _unit;

	AGM_Fortifications_Setup = "Land_Razorwire_F" createVehicleLocal [0, 0, -10000];

	AGM_Fortifications_Setup enableSimulationGlobal false;
	
	_unit forceWalk true;
	AGM_Fortifications_TweakedAngle = 180;

	["AGM_Fortifications_Placement", "OnEachFrame", {
		if (AGM_Fortifications_placer != player) exitWith {
			call AGM_Fortifications_fnc_setupCancel;
		};
		AGM_Fortifications_pfeh_running = true;

		_pos = (ASLtoATL eyePos player) vectorAdd (positionCameraToWorld [0, 0, 4] vectorDiff positionCameraToWorld [0, 0, 0]);
		_pos set [2, 0];

		if (getPosATL player distance _pos < 2 || {!alive player} || {player != vehicle player}) exitWith {
			call AGM_Fortifications_fnc_setupCancel;
		};

		AGM_Fortifications_Setup setPosATL _pos;

		if (AGM_Modifier == 0) then {
			AGM_Fortifications_Setup setDir (AGM_Fortifications_TweakedAngle + getDir player);
		};
	}] call BIS_fnc_addStackedEventHandler;

	[localize "STR_AGM_Fortifications_PlaceAction", localize "STR_AGM_Fortifications_CancelAction", localize "STR_AGM_Fortifications_ScrollAction"] call AGM_Interaction_fnc_showMouseHint;
	_unit setVariable ["AGM_Fortifications_Place", [_unit, "DefaultAction", {AGM_Fortifications_pfeh_running && {!isNull AGM_Fortifications_Setup}}, {call AGM_Fortifications_fnc_setupApprove}] call AGM_Core_fnc_AddActionEventHandler];
	_unit setVariable ["AGM_Fortifications_Cancel", [_unit, "MenuBack", {AGM_Fortifications_pfeh_running && {!isNull AGM_Fortifications_Setup}}, {call AGM_Fortifications_fnc_setupCancel}] call AGM_Core_fnc_AddActionEventHandler];
};
