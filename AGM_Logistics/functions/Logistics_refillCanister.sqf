// by commy2

_canister = player getVariable "AGM_Logistics_carryingObject";
_fuelCanister = _canister getVariable "AGM_Logistics_amountFuel";
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

_canister setVariable ["AGM_Logistics_amountFuel", _refill, false];

_target setFuel (_fuel / _capacity);
