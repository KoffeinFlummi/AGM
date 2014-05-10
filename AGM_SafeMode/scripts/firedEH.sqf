// by commy2

_time = time;
AGM_allowSafeMode set [0, false];
AGM_allowSafeMode set [1, _time];
_time spawn {
	sleep 0.5;
	if (AGM_allowSafeMode select 1 == _this) then {
		AGM_allowSafeMode set [0, true];
	};
};
