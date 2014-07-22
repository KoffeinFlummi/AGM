// by commy2

_item = _this select 0;
_vehicle = _this select 1;
_className = _this select 2;
_magicMenu = _this select 3;
_attachPoint = "";
_attachPos = [0,0,0];
_loaded = false;
_dummy = objNull;

_size = getNumber(ConfigFile >> "CfgVehicles" >> Typeof(_item) >> "AGM_Size");
if (!_magicMenu) then {
	_attachPoints = _vehicle call AGM_Logistics_fnc_getLoadPoints;
	{
		if ((_x select 4) == _className) exitWith {
			if ([_x select 1, _x select 3] call AGM_Logistics_fnc_remainingSpace >= _size) then {
				_loadedItems = _x select 3;
				_loadedItems set [count _loadedItems, _item];
				_vehicle setVariable [format ["AGM_Load_%1", _className], _loadedItems, true];
				_loaded = true;
				_attachPoint = _x select 0;
				_attachPos = _x select 1;
			};
		};
	} count _attachPoints;
} else {
	_loadedItems = _vehicle getVariable ["AGM_Logistics_loadedItems", []];
	if ([getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Vehicle_Cargo"), _loadedItems] call AGM_Logistics_fnc_remainingSpace >= _size) then {
		_loadedItems set [count _loadedItems, _item];
		_vehicle setVariable ["AGM_Logistics_loadedItems", _loadedItems, true];
		_loaded = true;
		_dummy = AGM_Logistics_loadedItemsDummy;
	};
};

if (_Loaded) then {
	//0 spawn AGM_Logistics_dropItem;
	_item attachTo [_dummy, _attachPos, _attachPoint];
	
	_itemName = getText (configFile >> "CfgVehicles" >> typeOf _item >> "displayName");
	_vehicleName = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");

	[format ["%1 loaded into %2", _itemName, _vehicleName]] call AGM_Core_fnc_displayTextStructured;
};

_item setVariable ["AGM_isUsedBy", objNull, true];
