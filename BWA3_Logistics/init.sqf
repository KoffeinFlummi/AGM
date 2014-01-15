BWA3_isCarrying = false;

BWA3_transportCanister = {
	if (stance player != "STAND") then {
		player playMove "amovpercmstpsnonwnondnon";
		waitUntil {animationState player == "amovpercmstpsnonwnondnon"};
	};

	BWA3_isCarrying = true;

	_canister = _this select 0;
	_canister attachTo [player, [0.01,0,-0.19], "RightHand"];
	_canister setDir 273;

	player forceWalk true;
	_dropAction = player addAction ["Drop Canister", {BWA3_isCarrying = false}, _this, 1.5, false, true, "", "true"];
	_refillAction = player addAction ["Refill Canister", {_this spawn BWA3_refillCanister}, _this, 1.5, false, true, "", "cursorTarget isKindOf 'Car' && {cursorTarget distance _this < 2}"];

	waitUntil {
		!BWA3_isCarrying ||
		{stance player != "STAND"} ||
		{currentWeapon player != ""}
	};

	BWA3_isCarrying = false;

	detach _canister;
	player forceWalk false;
	player removeAction _dropAction;
	player removeAction _refillAction;
};

player addAction ["Create Canister", {
	_canister = "Land_CanisterFuel_F" createVehicle (position player);
	_canister addAction ["Take Canister", {_this spawn BWA3_transportCanister}, _this, 1.5, false, true, "", "currentWeapon _this == '' && {_this distance _target < 3} && {!BWA3_isCarrying}"];
}];

BWA3_refillCanister = {
	cursorTarget setFuel 1;
};
