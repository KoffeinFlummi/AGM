/*
	Name: AGM_Logistics_fnc_loadItem
	
	Author: 
		commy2
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters: 
		0: OBJECT - Item to load
		1: OBJECT - Vehicle to load into
		2: ARRAY
			0: String of variable name
			1: index within variable
	
	Returns:
		NOTHING
	
	Example:
		[AGM_Interaction_Target, AGM_Logistics_targetVehicle, ["AGM_Load_MidLoad", 1]] spawn AGM_Logistics_fnc_loadItem;
*/
_vehicle = _this select 0;
_item = (_vehicle getVariable ((_this select 1) select 0)) select ((_this select 1) select 1);

if (!isNull(_item)) then {
	[10, [_vehicle, _item, (_this select 1) select 0], "AGM_Logistics_fnc_unloadItemCallback", "Unloading ..."] call AGM_Core_fnc_progressBar;
};