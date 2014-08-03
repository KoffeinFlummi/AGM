/*
	Name: AGM_Explosives_fnc_initialiseUnit
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Initialises a unit for explosive usage.
	
	Parameters:
		0: Object - Unit
	
	Returns:
		None
	
	Example:
		[player] call AGM_Explosives_fnc_initialiseUnit;
*/
private "_unit";
_unit = _this select 0;

_unit addAction [localize "STR_AGM_Explosives_AttachTo", "cursorTarget call AGM_Explosives_fnc_Place_AttachTo;", nil, 22, false, true, "","AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup) AND (cursorTarget isKindOf 'Car') AND (cursorTarget distance AGM_Explosives_Setup) < 2.5}"];
_unit addAction [localize "STR_AGM_Explosives_PlaceAction", "[] spawn AGM_Explosives_fnc_Place_Approve;", nil, 21, false, true, "","AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup)}"];
_unit addAction [localize "STR_AGM_Explosives_CancelAction", "call AGM_Explosives_fnc_Place_Cancel;", nil, 20, false, true, "","AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup)}"];

_unit SetVariable ["AGM_Clacker", [], true];
_unit addEventHandler ["Killed", {
	call AGM_Explosives_fnc_Place_Cancel;
}];
_unit addEventHandler ["Respawn", {
	[(_this select 0)] call AGM_Explosives_fnc_initialiseUnit;
	//diag_log "AGM: explosive respawn handling.";
}];

_unit addEventHandler ["Take", {
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
_unit addEventHandler ["Put", {
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