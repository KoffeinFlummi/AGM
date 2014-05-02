// by commy2

AGM_Logistics_carryItem = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\carryItem.sqf";
AGM_Logistics_dropItem = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\dropItem.sqf";
AGM_Logistics_carryJerryCan = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\carryJerryCan.sqf";
AGM_Logistics_dropJerryCan = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\dropJerryCan.sqf";

AGM_Logistics_fillCar = compile preprocessFileLineNumbers "\AGM_Logistics\functions\Logistics_fillCar.sqf";
AGM_Logistics_refillCanister = compile preprocessFileLineNumbers "\AGM_Logistics\functions\Logistics_refillCanister.sqf";
AGM_Logistics_checkCanister = compile preprocessFileLineNumbers "\AGM_Logistics\functions\Logistics_checkCanister.sqf";
AGM_Logistics_checkCanisterCarry = compile preprocessFileLineNumbers "\AGM_Logistics\functions\Logistics_checkCanisterCarry.sqf";

AGM_Logistics_transportCanister = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\Logistics_transportCanister.sqf";
AGM_Logistics_isCarrying = false;

0 spawn {
	sleep 0.1;

	player addAction ["Create Canister", {
		_canister = "Land_CanisterFuel_F" createVehicle (position player);

		_canister addAction [
			"Take Canister",
			{_this spawn AGM_Logistics_transportCanister},
			_this,
			1.5,
			false,
			true,
			"",
			"!AGM_Logistics_isCarrying && {!(_target getVariable 'AGM_Logistics_isCarrying')} && {_this distance _target < 2}"
		];

		_canister addAction [
			"Check fuel amount",
			{_this call AGM_Logistics_checkCanister},
			_this,
			1.5,
			false,
			true,
			"",
			"!(_target getVariable 'AGM_Logistics_isCarrying') && {_this distance _target < 2}"
		];

		_canister setVariable ["AGM_Logistics_amountFuel", 20, true];
		_canister setVariable ["AGM_Logistics_isCarrying", false, true];
	}];
};
