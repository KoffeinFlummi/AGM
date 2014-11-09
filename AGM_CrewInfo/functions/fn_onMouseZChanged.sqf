/*
	Author: aeroson
	
	Description:
	
	Parameters: 
		None
	
	Returns:
		Nothing
*/

private["_player"];

_player = call AGM_Core_fnc_player;

if(vehicle _player != _player && {!(vehicle _player isKindOf "ParachuteBase")}) then {
	
	if(AGM_CrewInfo_timeToHide < time) then {
		AGM_CrewInfo_timeToHide = time + 1;
	} else {
		AGM_CrewInfo_timeToHide = AGM_CrewInfo_timeToHide + 0.5;
	};
	call AGM_CrewInfo_fnc_doShow;

} else {

	AGM_CrewInfo_timeToHide = -1;

};