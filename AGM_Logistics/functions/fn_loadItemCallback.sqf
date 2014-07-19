// by commy2

_item = _this select 0;
_vehicle = _this select 1;
_className = _this select 2;

_size = getNumber(ConfigFile >> "CfgVehicles" >> Typeof(_item) >> "AGM_Size");
_attachPoints = _vehicle call AGM_Logistics_fnc_getLoadPoints;
{
	if ((_x select 4) == _className) exitWith {
		if ([_x select 1, _x select 3] call AGM_Logistics_fnc_remainingSpace >= _size) then {
			_loadedItems = _x select 3;
			_loadedItems set [count _loadedItems, _item];
			_vehicle setVariable [format ["AGM_Load_%1", _className], _loadedItems, true];
			
			0 spawn AGM_Logistics_dropItem;//
			_item attachTo [_vehicle, _x select 2, _x select 0];
			//_item attachTo [AGM_Logistics_loadedItemsDummy, [0, 0, 0]];

			_itemName = getText (configFile >> "CfgVehicles" >> typeOf _item >> "displayName");
			_vehicleName = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");

			[format ["%1 loaded into %2", _itemName, _vehicleName], true] call AGM_Core_fnc_displayText;
		};
	};
} count _attachPoints;

/*
if (_count < getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Vehicle_Cargo")) then {
	_loadedItems set [_count, _item];
	_vehicle setVariable ["AGM_Logistics_loadedItems", _loadedItems, true];

	0 spawn AGM_Logistics_dropItem;//
	_item attachTo [AGM_Logistics_loadedItemsDummy, [0, 0, 0]];

	_itemName = getText (configFile >> "CfgVehicles" >> typeOf _item >> "displayName");
	_vehicleName = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");

	[format ["%1 loaded into %2", _itemName, _vehicleName], true] call AGM_Core_fnc_displayText;
};
*/