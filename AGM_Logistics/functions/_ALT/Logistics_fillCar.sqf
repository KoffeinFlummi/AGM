// by commy2

_canister = player getVariable "AGM_Logistics_carryingObject";
_fuelCanister = _canister getVariable "AGM_Logistics_amountFuel";
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
_canister setVariable ["AGM_Logistics_amountFuel", _rest, false];

_target setFuel (_fuel / _capacity);
