// by commy2

0 spawn {
	waitUntil {!isNull player};

	[player] call AGM_NoRadio_fnc_muteUnit;
};


/*
0 spawn {
	waitUntil {!isNull player};

	[[player,nil,"AGM_NoVoice"],"bis_fnc_setidentity"] call bis_fnc_mp;
};
*/
