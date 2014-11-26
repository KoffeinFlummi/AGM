/*
	Author: aeroson
	
	Description:
		Might be called several times a second
	
	Parameters: 
		None
	
	Returns:
		true if CrewInfo can be shown, false otherwise
*/

private["_player"];


_player = AGM_player;

// AGM_CrewInfo_Visibility -1 force NO, 0 doesnt care, 1 force YES

AGM_CrewInfo_timeToHide > time &&
{vehicle _player != _player} &&
{
	(AGM_CrewInfo_Visibility==1) ||
	(AGM_CrewInfo_Visibility!=-1 && profileNamespace getVariable ["AGM_CrewInfo_ShowVehicleCrewInfo", false])
} &&
{!(vehicle _player isKindOf "ParachuteBase")};
