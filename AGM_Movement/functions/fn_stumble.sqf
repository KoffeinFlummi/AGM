// by commy2

private "_script_handle";

_script_handle = _this spawn {
	if (isTouchingGround player) then {
		_animation = switch (currentWeapon player) do {
			case "" : {"AmovPpneMstpSnonWnonDnon"};
			case (primaryWeapon player) : {"AmovPpneMstpSrasWrflDnon"};
			case (secondaryWeapon player) : {"AmovPpneMstpSrasWrflDnon"};
			case (handgunWeapon player) : {"AmovPpneMstpSrasWpstDnon"};
			case (player call AGM_Core_fnc_getBinocular) : {"AmovPpneMstpSrasWbinDnon"};
			default {"AmovPpneMstpSnonWnonDnon"};
		};
		player playMoveNow _animation;
	};
	sleep 6;
};
_script_handle
