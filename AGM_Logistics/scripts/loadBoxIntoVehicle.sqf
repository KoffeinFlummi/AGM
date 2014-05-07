// by commy2

_item = _this select 0;
_vehicle = AGM_Logistics_targetVehicle;

_loadedItems = _vehicle getVariable ["AGM_Logistics_loadedItems", []];

_count = count _loadedItems;

if (_count < getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Vehicle_Cargo")) then {
	_loadedItems set [_count, _item];
	_vehicle setVariable ["AGM_Logistics_loadedItems", _loadedItems, true];

	_itemName = getText (configFile >> "CfgVehicles" >> typeOf _item >> "displayName");
	_vehicleName = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");
	[format ["%1 loaded into %2", _itemName, _vehicleName], true] call AGM_Core_fnc_displayText;
};
