// by commy2

if (isTouchingGround player) then {
	_animation = switch (currentWeapon player) do {
		case "" : {"AmovPpneMstpSnonWnonDnon"}
		case (primaryWeapon player) : {"AmovPpneMstpSrasWrflDnon"};
		case (secondaryWeapon player) : {"AmovPpneMstpSrasWrflDnon"};
		case (handgunWeapon player) : {"AmovPpneMstpSrasWpstDnon"};
		case (weapons player - [primaryWeapon player, secondaryWeapon player, handgunWeapon player]) : {"AmovPpneMstpSrasWbinDnon"};
		default {"AmovPpneMstpSnonWnonDnon"};
	};
	player playMoveNow _animation;
};
sleep 6;
