
if (!hasInterface) exitWith {};



AGM_CrewInfo_timeToHide = -1;



[{_this call AGM_CrewInfo_fnc_onMouseZChanged}] call AGM_Core_fnc_addScrollWheelEventHandler;


[] spawn {
/*
	waitUntil{
		!isNil{AGM_fnc_CrewInfo_canShow} &&
		!isNil{AGM_fnc_CrewInfo_doShow}
	};*/

	while {true} do {

		waitUntil {
			sleep 1;
			call AGM_CrewInfo_fnc_canShow;
		};

		while {call AGM_CrewInfo_fnc_canShow} do {
			call AGM_CrewInfo_fnc_doShow;
			sleep 0.1;
		};

		AGM_CrewInfo_timeToHide = -1;

	};

};

