// by commy2

player action ["SwitchWeapon", vehicle player, vehicle player, 99];

//if (stance player != "STAND") then {
	player playMove "amovpercmstpsnonwnondnon";
	waitUntil {animationState player == "amovpercmstpsnonwnondnon"};
//};

BWA3_Logistics_isCarrying = true;

_canister = _this select 0;
_canister setVariable ["BWA3_Logistics_isCarrying", true, true];
_canister attachTo [player, [0.01,0,-0.19], "RightHand"];
_canister setDir 273;

player setVariable ["BWA3_Logistics_carryingObject", _canister, false];

player forceWalk true;
_dropAction = player addAction ["Drop canister", {BWA3_Logistics_isCarrying = false}, _this, 1.5, false, true, "", "true"];
_fillAction = player addAction ["Fill car", {_this call BWA3_Logistics_fillCar}, _this, 1.5, false, true, "", "cursorTarget isKindOf 'Car' && {cursorTarget distance _this < 3}"];
_refillAction = player addAction ["Refill canister", {_this call BWA3_Logistics_refillCanister}, _this, 1.5, false, true, "", "cursorTarget isKindOf 'Car' && {cursorTarget distance _this < 3}"];
_checkAction = player addAction ["Check fuel amount", {_this call BWA3_Logistics_checkCanisterCarry}, _this, 1.5, false, true, "", "true"];

waitUntil {
	!BWA3_Logistics_isCarrying ||
	{stance player != "STAND"} ||
	{currentWeapon player != ""} ||
	{!(alive player)}
};

BWA3_Logistics_isCarrying = false;

detach _canister;
_canister setVariable ["BWA3_Logistics_isCarrying", false, true];
player forceWalk false;
player removeAction _dropAction;
player removeAction _fillAction;
player removeAction _refillAction;
player removeAction _checkAction;
