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
if (isServer) then {
	if (isNil "AGM_Explosives_List") then {
		AGM_Explosives_List = [];
		publicVariable "AGM_Explosives_List";
	};
	if (isNil "AGM_Explosives_Jammers") then {
		AGM_Explosives_Jammers = [];
		publicVariable "AGM_Explosives_Jammers";
	};
};
if !(hasInterface) exitWith {};
AGM_Explosives_PlacedCount = 0;
AGM_Explosives_Setup = objNull;
AGM_Explosives_CurrentSpeedDial=-1;
AGM_Explosives_Phone_SpeedDial = [];
AGM_Explosives_ShiftDown = false;
AGM_Explosives_pfeh_running = false;
AGM_Explosives_null= [] spawn {
	waitUntil {sleep 0.356;!isNull(findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["MouseZChanged", "(_this select 1) call AGM_Explosives_fnc_HandleScrollWheel"];
	(findDisplay 46) displayAddEventHandler ["KeyDown", "if ((_this select 1) == 42) then {AGM_Explosives_ShiftDown = true;};"];
	(findDisplay 46) displayAddEventHandler ["KeyUp", "AGM_Explosives_ShiftDown = false;"];
	
	player addAction [localize "STR_AGM_Explosives_AttachTo", "cursorTarget call AGM_Explosives_fnc_Place_AttachTo;", nil, 22, false, true, "","!isNull(AGM_Explosives_Setup) AND {cursorTarget isKindOf 'Car'} AND {(cursorTarget distance AGM_Explosives_Setup) < 2.5}"];
	player addAction [localize "STR_AGM_Explosives_Place", "[] spawn AGM_Explosives_fnc_Place_Approve;", nil, 21, false, true, "","!isNull(AGM_Explosives_Setup)"];
	player addAction [localize "STR_AGM_Explosives_Cancel", "call AGM_Explosives_fnc_Place_Cancel;", nil, 20, false, true, "","!isNull(AGM_Explosives_Setup)"];

	player SetVariable ["AGM_Clacker", [], true];
	player addEventHandler ["Killed", {
		call AGM_Explosives_fnc_Place_Cancel;
	}];
	player addEventHandler ["Respawn", {
		AGM_Explosives_PlacedCount = 0;
		AGM_Explosives_CurrentSpeedDial=-1;
		AGM_Explosives_Phone_SpeedDial = [];
		player setVariable ["AGM_Clacker", [], true];
	}];

	player addEventHandler ["Take", {
		if ((_this select 2) == "AGM_Clacker") then {
			private ["_clacker1"];
			_clacker1 = (_this select 1) getVariable ["AGM_Clacker", []];
			(_this select 0) SetVariable ["AGM_Clacker", ((_this select 0) getVariable ["AGM_Clacker", []]) + _clacker1, true];
			if !("AGM_Clacker" in items (_this select 1)) then {
				(_this select 1) setVariable ["AGM_Clacker", [], true];
			};
		};
		if (isClass (configFile >> "CfgVehicles" >> (_this select 2)) and {getNumber(configFile >> "CfgVehicles" >> (_this select 2) >> "AGM_JammerRange") > 0}) then {
			[(_this select 0),unitBackpack (_this select 0)] call AGM_Explosives_fnc_JammerInit;
		};
	}];
	player addEventHandler ["Put", {
		if ((_this select 2) == "AGM_Clacker") then {
			private ["_clacker1"];
			_clacker1 = (_this select 0) getVariable ["AGM_Clacker", []];
			(_this select 1) SetVariable ["AGM_Clacker", ((_this select 1) getVariable ["AGM_Clacker", []]) + _clacker1, true];
			if !("AGM_Clacker" in items (_this select 0)) then {
				(_this select 0) setVariable ["AGM_Clacker", [], true];
			};
		};
		if (isClass (configFile >> "CfgVehicles" >> (_this select 2)) and {getNumber(configFile >> "CfgVehicles" >> (_this select 2) >> "AGM_JammerRange") > 0}) then {
			{
				if ((_x select 0) == (_this select 0)) exitWith	{
					_x set [0, (_this select 1)];
				};
			} count AGM_Explosives_Jammers;
			publicVariable "AGM_Explosives_Jammers";
		};
	}];
};