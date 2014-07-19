/*
	Name: AGM_Logistics_fnc_hasLoadedItems
	
	Author: 
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters: 
		0: OBJECT - vehicle to check for loaded items
	
	Returns:
		BOOLEAN
	
	Example:
		_vehicleLoaded = [_truck] call AGM_Logistics_fnc_hasLoadedItems;
*/
_result = false;
_vehicle = _this select 0;

if (isClass (configFile >> "CfgVehicles" >> typeOf(_vehicle) >> "AGM_Load")) then {
	_attachPoints = (_vehicle) call AGM_Logistics_fnc_getLoadPoints;
	{
		if (count (_x select 3) > 0) exitWith {
			_result = true;
		};
	} count _attachPoints;
} else {
	_result = (count (_vehicle getVariable ["AGM_Logistics_loadedItems", []])) > 0;
};

_result