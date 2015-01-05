// by commy2

addMissionEventHandler ["Draw3D", {
	call AGM_Laserpointer_fnc_onDraw;
}];

0 spawn {
	sleep 1;
	AGM_Laserpointer_nearUnits = [AGM_player];

	while {true} do {
		sleep 5;
		_nearUnits = nearestObjects [AGM_player, ["CAManBase"], 50];

		if (count _nearUnits > 10) then {
			_nearUnits resize 10;
		};

		AGM_Laserpointer_nearUnits = _nearUnits;
	};
};
