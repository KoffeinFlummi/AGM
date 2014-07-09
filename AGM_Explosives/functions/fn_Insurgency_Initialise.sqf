/*
	Name: AGM_Explosives_fnc_Initialise
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Initialises the Insurgency mod.
	
	Parameters:
		None
	
	Returns:
		None
	
	Example:
		None
*/
if (isServer) then
{
	if (isNil "AGM_Explosives_Explosives") then
	{
		AGM_Explosives_Explosives = [];
		publicVariable "AGM_Explosives_Explosives";
	};
	if (isNil "AGM_Explosives_Jammers") then
	{
		AGM_Explosives_Jammers = [];
		publicVariable "AGM_Explosives_Jammers";
	};
};
if !(hasInterface) exitWith {};
AGM_Explosives_IED_YourCount = 0;
AGM_Explosives_Setup = objNull;
AGM_Explosives_CurrentSpeedDial=-1;
AGM_Explosives_Phone_SpeedDial = [];
AGM_Explosives_IED_Creation = [["",""],["",""],["",""],["",""]];
AGM_Explosives_ShiftDown = false;
AGM_Explosives_null=[] spawn {
	waitUntil {sleep 0.1;player == player };
	AGM_Explosives_Insurgency_InventoryHandle = [] spawn {
		waitUntil {sleep 0.5;!isNull(findDisplay 46)};
		(findDisplay 46) displayAddEventHandler ["MouseZChanged", "(_this select 1) call AGM_Explosives_fnc_HandleScrollWheel"];
		(findDisplay 46) displayAddEventHandler ["KeyDown", "if ((_this select 1) == 42) then {AGM_Explosives_ShiftDown = true;};"];
		(findDisplay 46) displayAddEventHandler ["KeyUp", "AGM_Explosives_ShiftDown = false;"];
		while {true} do
		{
			waitUntil {sleep 0.1;!(isNull (findDisplay 602))};
			((findDisplay 602) displayCtrl 633) ctrlAddEventHandler ["LBDblClick", "_this call AGM_Explosives_fnc_HandleClick"];
			((findDisplay 602) displayCtrl 619) ctrlAddEventHandler ["LBDblClick", "_this call AGM_Explosives_fnc_HandleClick"];
			((findDisplay 602) displayCtrl 638) ctrlAddEventHandler ["LBDblClick", "_this call AGM_Explosives_fnc_HandleClick"];
			waitUntil {sleep 0.5;isNull (findDisplay 602)};
		};
	};

	player AddAction [localize "STR_AGM_Explosives_INSURGENCY_SuicideVest_Detonate", "player call AGM_Explosives_fnc_DetonateVest;", nil, -25, false, true, "", "(_this == _target) AND {getNumber(ConfigFile >> 'CfgWeapons' >> (vest _target) >> 'AGM_Explosives_SuicideVest') == 1}"];
	
	player addAction [localize "STR_AGM_Explosives_INSURGENCY_IED_AttachTo", "cursorTarget call AGM_Explosives_fnc_Place_AttachTo;", nil, 22, false, true, "","!isNull(AGM_Explosives_Setup) AND {cursorTarget isKindOf 'Car'} AND {(cursorTarget distance AGM_Explosives_Setup) < 2.5}"];
	player addAction [localize "STR_AGM_Explosives_INSURGENCY_IED_Place", "[] spawn AGM_Explosives_fnc_Place_Approve;", nil, 21, false, true, "","!isNull(AGM_Explosives_Setup)"];
	player addAction [localize "STR_AGM_Explosives_INSURGENCY_IED_Cancel", "call AGM_Explosives_fnc_Place_Cancel;", nil, 20, false, true, "","!isNull(AGM_Explosives_Setup)"];
	
	player addAction [localize "STR_AGM_Explosives_INSURGENCY_IED_deadman_Release", "[player,(player getVariable 'AGM_Explosives_Deadman'), true, true] call AGM_Explosives_fnc_DetonateExplosive;player setVariable ['AGM_Explosives_Deadman', [],true];", nil, 20, false, true, "","player call AGM_Explosives_fnc_IED_DeadManCheck"];
	
	player addAction [localize "STR_A3_IEDJammer_TurnOn", {(unitBackpack player) setVariable ["AGM_Explosives_JammerEnabled", true, true];}, nil, -15, false, true, "","(_this == _target) and {((isClass (configFile >> 'CfgVehicles' >> (backpack player)) and {getNumber(configFile >> 'CfgVehicles' >> (backpack player) >> 'AGM_Explosives_JammerRange') > 0})) and !((unitBackpack player) getVariable [""AGM_Explosives_JammerEnabled"", false])}"];
	player addAction [localize "STR_A3_IEDJammer_TurnOff", {(unitBackpack player) setVariable ["AGM_Explosives_JammerEnabled", false, true];}, nil, -15, false, true, "","(_this == _target) and {((isClass (configFile >> 'CfgVehicles' >> (backpack player)) and {getNumber(configFile >> 'CfgVehicles' >> (backpack player) >> 'AGM_Explosives_JammerRange') > 0})) and ((unitBackpack player) getVariable [""AGM_Explosives_JammerEnabled"", false])}"];

	player SetVariable ["AGM_Explosives_Clacker", [], true];
	player addEventHandler ["Killed", {
		if ((_this select 0) call AGM_Explosives_fnc_IED_DeadManCheck) then
		{
			[(_this select 0),((_this select 0) getVariable "AGM_Explosives_Deadman"), true, true] call AGM_Explosives_fnc_DetonateExplosive;
		};
		AGM_Explosives_Setup = objNull;
		AGM_Explosives_IED_Creation = [["",""],["",""],["",""],["",""]];
	}];
	player addEventHandler ["Respawn", {
		AGM_Explosives_IED_YourCount = 0;
		AGM_Explosives_CurrentSpeedDial=-1;
		AGM_Explosives_Phone_SpeedDial = [];
		player setVariable ["AGM_Explosives_Clacker", [], true];
	}];

	player addEventHandler ["Take", {
		if ((_this select 2) == "AGM_Explosives_IED_ClackerTriggerComponent") then
		{
			private ["_clacker1"];
			_clacker1 = (_this select 1) getVariable ["AGM_Explosives_Clacker", []];
			(_this select 0) SetVariable ["AGM_Explosives_Clacker", ((_this select 0) getVariable ["AGM_Explosives_Clacker", []]) + _clacker1, true];
			if !("AGM_Explosives_IED_ClackerTriggerComponent" in items (_this select 1)) then
			{
				(_this select 1) setVariable ["AGM_Explosives_Clacker", [], true];
			};
		};
		if (isClass (configFile >> "CfgVehicles" >> (_this select 2)) and {getNumber(configFile >> "CfgVehicles" >> (_this select 2) >> "AGM_Explosives_JammerRange") > 0}) then
		{
			[(_this select 0),unitBackpack (_this select 0)] call AGM_Explosives_fnc_JammerInit;
		};
	}];
	player addEventHandler ["Put", {
		if ((_this select 2) == "AGM_Explosives_IED_ClackerTriggerComponent") then
		{
			private ["_clacker1"];
			_clacker1 = (_this select 0) getVariable ["AGM_Explosives_Clacker", []];
			(_this select 1) SetVariable ["AGM_Explosives_Clacker", ((_this select 1) getVariable ["AGM_Explosives_Clacker", []]) + _clacker1, true];
			if !("AGM_Explosives_IED_ClackerTriggerComponent" in items (_this select 0)) then
			{
				(_this select 0) setVariable ["AGM_Explosives_Clacker", [], true];
			};
		};
		if (isClass (configFile >> "CfgVehicles" >> (_this select 2)) and {getNumber(configFile >> "CfgVehicles" >> (_this select 2) >> "AGM_Explosives_JammerRange") > 0}) then
		{
			{
				if ((_x select 0) == (_this select 0)) exitWith
				{
					_x set [0, (_this select 1)];
				};
			} count AGM_Explosives_Jammers;
			publicVariable "AGM_Explosives_Jammers";
		};
	}];
};