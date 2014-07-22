// by commy2

_box = _this select 0;
_weapon = currentWeapon player;

AGM_isCarryingItem = true;

_animationCarry = "";
_animationDrop = "";

switch (_weapon) do {
	case (handgunWeapon player) : {
		_animationCarry = "AcinPknlMstpSnonWpstDnon";
		_animationDrop = "AmovPknlMstpSrasWpstDnon";
	};
	case (primaryWeapon player) : {
		_animationCarry = "AcinPknlMstpSrasWrflDnon";
		_animationDrop = "AmovPknlMstpSrasWrflDnon";
	};
	default {
		_animationCarry = "AcinPknlMstpSnonWnonDnon";
		_animationDrop = "AmovPknlMstpSnonWnonDnon";
	};
};

player playMoveNow _animationCarry;
waitUntil {animationState player == _animationCarry};

_box attachTo [player, [0, 1.1, 0.092]];
_box setDir 90;

player setVariable ["AGM_Logisitcs_carriedItem", _box, false];

waitUntil {
	!AGM_isCarryingItem ||
	{currentWeapon player != _weapon} ||
	{!alive player}
};

AGM_isCarryingItem = false;

detach _box;

player setVariable ["AGM_Logisitcs_carriedItem", nil, false];

player playMoveNow _animationDrop;
waitUntil {animationState player == _animationDrop};
