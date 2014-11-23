0 spawn {
	waitUntil {!isNull player};

	[[player,nil,"AGM_NoVoice"],"bis_fnc_setidentity"] call bis_fnc_mp;
};
