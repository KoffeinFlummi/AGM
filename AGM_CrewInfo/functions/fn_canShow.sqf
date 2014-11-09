/*
	Author: aeroson
	
	Description:
	
	Parameters: 
		None
	
	Returns:
		true if CrewInfo can be shown, false otherwise
*/

private["_player", "_profileNamespaceDoShow"];


_player = call AGM_Core_fnc_player;

// AGM_CrewInfo_Visibility -1 force NO, 0 doesnt care, 1 force YES
_profileNamespaceDoShow = profileNamespace getVariable ["CrewInfo_ShowVehicleCrewInfo", false];

AGM_CrewInfo_timeToHide > time &&
{vehicle _player != _player} &&
{
	(AGM_CrewInfo_Visibility==1) ||
	(AGM_CrewInfo_Visibility!=-1 && _profileNamespaceDoShow)
} &&
{!(vehicle _player isKindOf "ParachuteBase")};
