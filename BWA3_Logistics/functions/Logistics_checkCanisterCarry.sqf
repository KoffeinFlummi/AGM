// by commy2

_canister = player getVariable "BWA3_Logistics_carryingObject";
_fuel = _canister getVariable "BWA3_Logistics_amountFuel";

_fuel = round (2 * _fuel);
_message = (
	switch (_fuel) do {
		case 0 : {"Canister is Empty!"};
		case 40 : {"Canister is Full!"};
		default {"Canister has about " + str(_fuel / 2) + "l"};
	}
);
hintSilent _message;
