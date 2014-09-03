// by commy2

AGM_Core_onScrollWheel = {
	_scroll = _this select 1;

	{
		[_scroll] call _x;
	} forEach ((missionNamespace getVariable ["AGM_EventHandler_ScrollWheel", [-1, [], []]]) select 2);
};
