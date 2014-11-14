/*
Name: AGM_InventoryInteraction_fnc_handleSelChangeInvList

Author: CorruptedHeart and Pabst Mirror

Description:
	Handles the 3 player inventory listBoxs selection changing event.  Attemps to figure out the configPath of what was selected.

Parameters:
	0: ARRAY - ctrl event
	1: BOOL - was double click
	
Returns:
	BOOL - handeled, always false

Example:
	internal use
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

private ["_idc", "_selectedIndex", "_wasDoubleClick", "_settingDoubleClick", "_player", "_lbDataString", "_class", "_foundClass", "_itemsInContainer", "_uniqueWeaponsArray", "_uniqueItemsArray", "_item", "_mouseY"];

_idc = ctrlIDC ((_this select 0) select 0);
_selectedIndex = (_this select 0) select 1;
_wasDoubleClick = _this select 1;

//Ignore if clicktype is different than user setting (where's the xor command?)
_settingDoubleClick = (profileNamespace getVariable ["AGM_InvInteractDoubleClick", false]);
if ((_wasDoubleClick || _settingDoubleClick) && !(_wasDoubleClick && _settingDoubleClick)) exitWith {};

_player = call AGM_Core_fnc_player;

_lbDataString = lbData [_idc, _selectedIndex];
_foundClass = false;

_class = configFile >> "CfgMagazines" >> _lbDataString;
if (_lbDataString == "") then {
	_itemsInContainer = switch (_idc) do {
	case IDC_CONTAINER_UNIFORM: {uniformItems _player};
	case IDC_CONTAINER_BACKPACK: {backpackItems _player};
	case IDC_CONTAINER_VEST: {vestItems _player};
		default {[]};
	};

	//From best I can tell, weapons are always listed before items, but otherwise we can trust the order
	_uniqueWeaponsArray = [];
	_uniqueItemsArray = [];
	{
		if (_x in (weapons _player)) then {
			if !(_x in _uniqueWeaponsArray) then {_uniqueWeaponsArray pushBack _x;};
		} else {
			if !(_x in _uniqueItemsArray) then {_uniqueItemsArray pushBack _x;};
		};
	} forEach _itemsInContainer;

	if (_selectedIndex < (count (_uniqueWeaponsArray + _uniqueItemsArray))) then {
		_item = ((_uniqueWeaponsArray + _uniqueItemsArray) select _selectedIndex);
		if (_item == "") exitwith {};
		switch (true) do {
		case (isClass (configFile >> "CfgWeapons" >> _item)): {_class = configFile >> "CfgWeapons" >> _item;};
		case (isClass (configFile >> "CfgGlasses" >> _item)): {_class = configFile >> "CfgGlasses" >> _item;};
		};
	};
};

if (isClass _class) then {
	//With a mouse click, the upEvent will trigger first, giving mouse position
	_mouseUpEvent = missionNamespace getVariable ["AGM_InventoryInteraction_mouseUpEvent", [0, 0, 0]];
	_mousePos = if ((diag_tickTime - (_mouseUpEvent select 0)) < 0.2) then {
		_mouseUpEvent select [1, 2]
	} else {//Selection Changed without a mouse click preceding, (keyboard arrow), just use old Y position
		(ctrlPosition (DISPLAY_INVENTORY displayCtrl IDC_ACTION_CONTROLGROUP)) select [0, 2]
	};
	[_class, _mousePos, _idc] call AGM_InventoryInteraction_fnc_openItemInfoBox;
} else {
	[] call AGM_InventoryInteraction_fnc_closeItemInfoBox;
};

false
