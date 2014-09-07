/*
    Name: AGM_Interaction_fnc_openFriskMenu
    
    Author: jodav
    
    Description:
        Open the select menu with the "personal" items of a frisked unit
        It shows only uniformItems, vestItems, backpackItems, assignedItems because every other item is visible on the character
    
    Parameters: 
        0: Object - unit

    Returns:
        Nothing
*/


private ["_unit", "_listedItemClasses", "_allGear", "_actions", "_uniformitems", "_vestitems", "_backpackitems", "_assigneditems"];

_unit = _this select 0;

_listedItemClasses = [];

_allGear = [_unit] call AGM_Respawn_fnc_getAllGear;

// localize this
_actions = ["Iventory of frisked person", "Cancel"] call AGM_Interaction_fnc_prepareSelectMenu;

_uniformitems = _allGear select 3;
_vestitems = _allGear select 5;
_backpackitems = _allGear select 7;
_assigneditems = _allGear select 17;

// Uniform Items
{
    if (!(_x in _listedItemClasses)) then {
        _item = configFile >> "CfgMagazines" >> _x;
        if (isNil "_item" || str _item == "") then {
            _item = configFile >> "CfgWeapons" >> _x;
        };
        _actions = [_actions, getText(_item >> "displayName"), getText(_item >> "picture"), _x] call AGM_Interaction_fnc_addSelectableItem;
        _listedItemClasses pushBack _x;
    };
}foreach _uniformitems;

// Vest Items
{
    if (!(_x in _listedItemClasses)) then {
        _item = configFile >> "CfgMagazines" >> _x;
        if (isNil "_item" || str _item == "") then {
            _item = configFile >> "CfgWeapons" >> _x;
        };
        _actions = [_actions, getText(_item >> "displayName"), getText(_item >> "picture"), _x] call AGM_Interaction_fnc_addSelectableItem;
        _listedItemClasses pushBack _x;
    };
}foreach _vestitems;

// Backpack Items
{
    if (!(_x in _listedItemClasses)) then {
        _item = configFile >> "CfgMagazines" >> _x;
        if (isNil "_item" || str _item == "") then {
            _item = configFile >> "CfgWeapons" >> _x;
        };
        _actions = [_actions, getText(_item >> "displayName"), getText(_item >> "picture"), _x] call AGM_Interaction_fnc_addSelectableItem;
        _listedItemClasses pushBack _x;
    };
} foreach _backpackitems;

// Assigned Items
{
    if (!(_x in _listedItemClasses)) then {
        _item = configFile >> "CfgMagazines" >> _x;
        if (isNil "_item" || str _item == "") then {
            _item = configFile >> "CfgWeapons" >> _x;
        };
        _actions = [_actions, getText(_item >> "displayName"), getText(_item >> "picture"), _x] call AGM_Interaction_fnc_addSelectableItem;
        _listedItemClasses pushBack _x;
    };
} forEach _assignedItems;

[_actions, {call AGM_Interaction_fnc_hideMenu;}, {call AGM_Interaction_fnc_hideMenu;}] call AGM_Interaction_fnc_openSelectMenu;

// don't need an "Ok" Button
ctrlShow [8860, false];