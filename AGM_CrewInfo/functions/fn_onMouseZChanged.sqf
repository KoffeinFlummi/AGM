/*
	Author: aeroson
	
	Description:
		Callback for mouse wheel change
	
	Parameters: 
		None
	
	Returns:
		Nothing
*/

private["_player"];

_player = AGM_player;

if(vehicle _player != _player && {!(vehicle _player isKindOf "ParachuteBase")}) then {
	
	if(AGM_CrewInfo_timeToHide < time) then {
		AGM_CrewInfo_timeToHide = time + 1;
	} else {
		AGM_CrewInfo_timeToHide = AGM_CrewInfo_timeToHide + 0.5;
	};
	if(call AGM_CrewInfo_fnc_canShow) then {
		call AGM_CrewInfo_fnc_doShow;
	};

} else {

	AGM_CrewInfo_timeToHide = -1;

};