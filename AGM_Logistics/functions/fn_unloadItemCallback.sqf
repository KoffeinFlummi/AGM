// by commy2
_vehicle = _this select 0;
_item = _this select 1;
_itemHolder = _this select 2;

_loadedItems = _vehicle getVariable [_itemHolder, []];
_loadedItems = _loadedItems - [_item];
_vehicle setVariable [_itemHolder, _loadedItems, true];

player allowDamage false;
detach _item;
_item setVehiclePosition [getPosASL player, [], 2];
player allowDamage true;

_itemName = getText (configFile >> "CfgVehicles" >> typeOf _item >> "displayName");
_vehicleName = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");
[format ["unloaded %1 from %2", _itemName, _vehicleName], true] call AGM_Core_fnc_displayText;
