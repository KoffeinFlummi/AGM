if (!hasInterface) exitWith {};


AGM_CrewInfo_timeToHide = -1;


[{_this call AGM_CrewInfo_fnc_onMouseZChanged}] call AGM_Core_fnc_addScrollWheelEventHandler;

if(isNil{AGM_CrewInfo_Visibility}) then {
	AGM_CrewInfo_Visibility=0;
};


[] spawn {

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