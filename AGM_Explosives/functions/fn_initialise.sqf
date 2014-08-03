/*
	Name: AGM_Explosives_fnc_Initialise
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Initialises explosive behaviour.
	
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
	/*
		All Jammer code is disabled for now.
	if (isNil "AGM_Explosives_Jammers") then {
		AGM_Explosives_Jammers = [];
		publicVariable "AGM_Explosives_Jammers";
	};
	*/
};
if !(hasInterface) exitWith {};
AGM_Explosives_PlacedCount = 0;
AGM_Explosives_Setup = objNull;
//AGM_Explosives_CurrentSpeedDial=-1;
//AGM_Explosives_Phone_SpeedDial = [];
AGM_Explosives_ShiftDown = false;
AGM_Explosives_pfeh_running = false;
AGM_Explosives_null= [] spawn {
	waitUntil {sleep 0.356;!isNull(findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["MouseZChanged", "(_this select 1) call AGM_Explosives_fnc_HandleScrollWheel"];
	(findDisplay 46) displayAddEventHandler ["KeyDown", "if ((_this select 1) == 42) then {AGM_Explosives_ShiftDown = true;};"];
	(findDisplay 46) displayAddEventHandler ["KeyUp", "AGM_Explosives_ShiftDown = false;"];
	player addEventHandler ["Respawn", {
		[(_this select 0)] call AGM_Explosives_fnc_initialiseUnit;
	}];
	player addEventHandler ["Killed", {
		call AGM_Explosives_fnc_Place_Cancel;
	}];
	player addEventHandler ["Take", {
		private ["_item", "_getter", "_giver"];
		_item = _this select 2;
		_getter = _this select 0;
		_giver = _this select 1;
		if (_item == "AGM_Clacker") then {
			private ["_clackerItems"];
			_clackerItems = _giver getVariable ["AGM_Clacker", []];
			_getter SetVariable ["AGM_Clacker", (_getter getVariable ["AGM_Clacker", []]) + _clackerItems, true];
			if !("AGM_Clacker" in items _giver) then {
				_giver setVariable ["AGM_Clacker", [], true];
			};
		};
		/*
			Explosive Jammer code
		if (isClass (configFile >> "CfgVehicles" >> (_this select 2)) and {getNumber(configFile >> "CfgVehicles" >> (_this select 2) >> "AGM_JammerRange") > 0}) then {
			[(_this select 0),unitBackpack (_this select 0)] call AGM_Explosives_fnc_JammerInit;
		};
		*/
	}];
	player addEventHandler ["Put", {
		private ["_item", "_getter", "_giver"];
		_item = _this select 2;
		_getter = _this select 1;
		_giver = _this select 0;
		if (_item == "AGM_Clacker") then {
			private ["_clackerItems"];
			_clackerItems = _giver getVariable ["AGM_Clacker", []];
			_getter SetVariable ["AGM_Clacker", (_getter getVariable ["AGM_Clacker", []]) + _clackerItems, true];
			if !("AGM_Clacker" in items _giver) then {
				_giver setVariable ["AGM_Clacker", [], true];
			};
		};
		/*
			Explosive Jammer code
		if (isClass (configFile >> "CfgVehicles" >> (_this select 2)) and {getNumber(configFile >> "CfgVehicles" >> (_this select 2) >> "AGM_JammerRange") > 0}) then {
			{
				if ((_x select 0) == (_this select 0)) exitWith	{
					_x set [0, (_this select 1)];
				};
			} count AGM_Explosives_Jammers;
			publicVariable "AGM_Explosives_Jammers";
		};
		*/
	}];
	[player] call AGM_Explosives_fnc_initialiseUnit;
};