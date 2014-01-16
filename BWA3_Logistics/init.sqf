
BWA3_isCarrying = false;

BWA3_transportCanister = {
	if (stance player != "STAND") then {
		player playMove "amovpercmstpsnonwnondnon";
		waitUntil {animationState player == "amovpercmstpsnonwnondnon"};
	};

	BWA3_isCarrying = true;

	_canister = _this select 0;
	_canister setVariable ["BWA3_isCarrying", true, true];
	_canister attachTo [player, [0.01,0,-0.19], "RightHand"];
	_canister setDir 273;

	player setVariable ["BWA3_carryingObject", _canister, false];

	player forceWalk true;
	_dropAction = player addAction ["Drop canister", {BWA3_isCarrying = false}, _this, 1.5, false, true, "", "true"];
	_fillAction = player addAction ["Fill car", {_this spawn BWA3_fillCar}, _this, 1.5, false, true, "", "cursorTarget isKindOf 'Car' && {cursorTarget distance _this < 3}"];
	_refillAction = player addAction ["Refill canister", {_this spawn BWA3_refillCanister}, _this, 1.5, false, true, "", "cursorTarget isKindOf 'Car' && {cursorTarget distance _this < 3}"];
	_checkAction = player addAction ["Check fuel amount", {_this spawn BWA3_checkCanisterCarry}, _this, 1.5, false, true, "", "true"];

	waitUntil {
		!BWA3_isCarrying ||
		{stance player != "STAND"} ||
		{currentWeapon player != ""} ||
		{!(alive player)}
	};

	BWA3_isCarrying = false;

	detach _canister;
	_canister setVariable ["BWA3_isCarrying", false, true];
	player forceWalk false;
	player removeAction _dropAction;
	player removeAction _fillAction;
	player removeAction _refillAction;
	player removeAction _checkAction;
};

player addAction ["Create Canister", {
	_canister = "Land_CanisterFuel_F" createVehicle (position player);
	_canister addAction ["Take Canister", {_this spawn BWA3_transportCanister}, _this, 1.5, false, true, "", "currentWeapon _this == '' && {_this distance _target < 2} && {!BWA3_isCarrying} && {!(_target getVariable 'BWA3_isCarrying')}"];
	_canister addAction ["Check fuel amount", {_this spawn BWA3_checkCanister}, _this, 1.5, false, true, "", "_this distance _target < 2 && {!(_target getVariable 'BWA3_isCarrying')}"];
	_canister setVariable ["BWA3_amountFuel", 20, true];
	_canister setVariable ["BWA3_isCarrying", false, true];
}];

BWA3_fillCar = {
	_canister = player getVariable "BWA3_carryingObject";
	_fuelCanister = _canister getVariable "BWA3_amountFuel";
	if (_fuelCanister == 0) exitWith {hintSilent "Canister is Empty!"};

	_target = cursorTarget;
	_capacity = getNumber (configFile >> "CfgVehicles" >> typeOf _target >> "fuelCapacity");
	_name = getText (configfile >> "CfgVehicles" >> typeOf _target >> "displayName");

	_fuel = fuel _target;
	if (_fuel == 1) exitWith {hintSilent (_name + " is already Full!")};
	_fuel = _fuel * _capacity;
	_fuel = _fuel + _fuelCanister;

	_rest = _fuel - _capacity;
	if (_rest < 0) then {_rest = 0};
	_canister setVariable ["BWA3_amountFuel", _rest, false];

	_target setFuel (_fuel / _capacity);
};

BWA3_refillCanister = {
	_canister = player getVariable "BWA3_carryingObject";
	_fuelCanister = _canister getVariable "BWA3_amountFuel";
	if (_fuelCanister == 20) exitWith {hintSilent "Canister is already Full!"};

	_target = cursorTarget;
	_capacity = getNumber (configFile >> "CfgVehicles" >> typeOf _target >> "fuelCapacity");
	_name = getText (configfile >> "CfgVehicles" >> typeOf _target >> "displayName");

	_fuel = fuel _target;
	if (_fuel == 0) exitWith {hintSilent (_name + " is Empty!")};
	_fuel = _fuel * _capacity;

	_refill = 20;
	if (_fuel < 20 - _fuelCanister) then {
		_refill = _fuel;
		_fuel = 0;
	} else {
		_fuel = _fuel - (20 - _fuelCanister);
	};

	_canister setVariable ["BWA3_amountFuel", _refill, false];

	_target setFuel (_fuel / _capacity);
};

BWA3_checkCanister = {
	_canister = _this select 0;
	_fuel = _canister getVariable "BWA3_amountFuel";

	_fuel = round (2 * _fuel);
	_message = (switch (_fuel) do {
		case 0 : {"Canister is Empty!"};
		case 40 : {"Canister is Full!"};
		default {"Canister has about " + str(_fuel / 2) + "l"};
	});
	hintSilent _message;
};

BWA3_checkCanisterCarry = {
	_canister = player getVariable "BWA3_carryingObject";
	_fuel = _canister getVariable "BWA3_amountFuel";

	_fuel = round (2 * _fuel);
	_message = (switch (_fuel) do {
		case 0 : {"Canister is Empty!"};
		case 40 : {"Canister is Full!"};
		default {"Canister has about " + str(_fuel / 2) + "l"};
	});
	hintSilent _message;
};
