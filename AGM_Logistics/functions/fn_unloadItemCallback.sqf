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
_position = getPosASL _item;
_position set [2, 0];
_item setPosASL [-1000, -1000, 0];
_item setPosATL _position;
player reveal _item;
[_item, "{_this setVectorUp (surfaceNormal getPosASL _this)}", _item] call AGM_Core_fnc_execRemoteFnc;
player allowDamage true;

_itemName = getText (configFile >> "CfgVehicles" >> typeOf _item >> "displayName");
_vehicleName = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");
[format ["unloaded %1 from %2", _itemName, _vehicleName]] call AGM_Core_fnc_displayTextStructured;
