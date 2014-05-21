// by commy2

_item = _this select 0;
_vehicle = AGM_Logistics_targetVehicle;

_loadedItems = _vehicle getVariable ["AGM_Logistics_loadedItems", []];
_count = count _loadedItems;

if (_count < getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Vehicle_Cargo")) then {
	detach _item;
	[10, [_item, _vehicle], "AGM_Logistics_loadBoxIntoVehicleCallback", "Loading"] call AGM_Core_fnc_progressBar;
};
