// commy 2

_vehicle = AGM_Interaction_Target;

_loadedItems = _vehicle getVariable ["AGM_Logistics_loadedItems", []];

_count = count _loadedItems;

if (_count == 0) exitWith {};

[10, [_vehicle], "AGM_Logistics_unloadBoxCallback", "Unloading"] call AGM_Core_fnc_progressBar;
