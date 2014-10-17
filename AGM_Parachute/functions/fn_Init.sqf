/*
	Name: AGM_Parachute_fnc_init
	
	Author: Garth de Wet (LH)
	
	Description:
		Auto called by Arma.
		Initialises the parachute system.
	
	Parameters: 
	
	Returns:
		Nothing
	
	Example:
		call AGM_Parachute_fnc_init;
*/
[] spawn {
	AGM_Parachuting_PFH = false;
	while {true} do {
		sleep 1;
		// I believe this doesn't work for Zeus.
		// vehicle _player
		if (!AGM_Parachuting_PFH && {(vehicle (call AGM_Core_fnc_player)) isKindOf "ParachuteBase"}) then {
			AGM_Parachuting_PFH = true;
			["AGM_ParachuteFix", "OnEachFrame", {call AGM_Parachute_fnc_onEachFrame;}] call BIS_fnc_addStackedEventHandler;
		};
	};
};