[] spawn {
	AGM_Parachuting_PFH = false;
	while {true} do {
		sleep 5;
		if (!AGM_Parachuting_PFH && {(vehicle player) isKindOf "ParachuteBase"}) then {
			AGM_Parachuting_PFH = true;
			["AGM_ParachuteFix", "OnEachFrame", {call AGM_Parachute_fnc_onEachFrame;}] call BIS_fnc_addStackedEventHandler;
		};
	};
};