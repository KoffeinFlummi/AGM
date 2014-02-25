// by commy2

BWA3_Logistics_fillCar = compile preProcessFileLineNumbers "\BWA3_Logistics\functions\Logistics_fillCar.sqf";
BWA3_Logistics_refillCanister = compile preProcessFileLineNumbers "\BWA3_Logistics\functions\Logistics_refillCanister.sqf";
BWA3_Logistics_checkCanister = compile preProcessFileLineNumbers "\BWA3_Logistics\functions\Logistics_checkCanister.sqf";
BWA3_Logistics_checkCanisterCarry = compile preProcessFileLineNumbers "\BWA3_Logistics\functions\Logistics_checkCanisterCarry.sqf";

BWA3_Logistics_transportCanister = compile preProcessFileLineNumbers "\BWA3_Logistics\scripts\Logistics_transportCanister.sqf";
BWA3_Logistics_isCarrying = false;

0 spawn {
	sleep 0.1;

	player addAction ["Create Canister", {
		_canister = "Land_CanisterFuel_F" createVehicle (position player);

		_canister addAction [
			"Take Canister",
			{_this spawn BWA3_Logistics_transportCanister},
			_this,
			1.5,
			false,
			true,
			"",
			"!BWA3_Logistics_isCarrying && {!(_target getVariable 'BWA3_Logistics_isCarrying')} && {_this distance _target < 2}"
		];

		_canister addAction [
			"Check fuel amount",
			{_this call BWA3_Logistics_checkCanister},
			_this,
			1.5,
			false,
			true,
			"",
			"!(_target getVariable 'BWA3_Logistics_isCarrying') && {_this distance _target < 2}"
		];

		_canister setVariable ["BWA3_Logistics_amountFuel", 20, true];
		_canister setVariable ["BWA3_Logistics_isCarrying", false, true];
	}];
};
