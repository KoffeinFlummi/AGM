// by commy2

#define ANIM_CARRY "AmovPercMstpSnonWnonDnon"

_jerryCan = _this select 0;

AGM_isCarryingItem = true;

player action ["SwitchWeapon", vehicle player, vehicle player, 99];

player playMove ANIM_CARRY;
waitUntil {animationState player == ANIM_CARRY};

_jerryCan attachTo [player, [0.01,0,-0.19], "RightHand"];
_jerryCan setDir 273;

player forceWalk true;
player setVariable ["AGM_Logisitcs_carriedItem", _jerryCan, false];

waitUntil {
	!AGM_isCarryingItem ||
	{stance player != "STAND"} ||
	{currentWeapon player != ""} ||
	{!alive player}
};

AGM_isCarryingItem = false;

detach _jerryCan;

player forceWalk false;
player setVariable ["AGM_Logisitcs_carriedItem", nil, false];
