/*
    Name: AGM_Interaction_fnc_openFriskMenu
    
    Author: jodav
    
    Description:
        Open the select menu with the "personal" items of a frisked unit
        It only shows "handgunWeapon", "uniformItems", "vestItems", "backpackItems" and "assignedItems" because every other item is visible on the character
    
    Parameters: 
        0: Object - unit

    Returns:
        Nothing
*/


private ["_unit", "_listedItemClasses"];

_unit = _this select 0;

_listedItemClasses = [];

_actions = [localize "$STR_AGM_Interaction_FriskMenuHeader", localize "$STR_AGM_Interaction_CancelSelection"] call AGM_Interaction_fnc_prepareSelectMenu;

// Handgun
// Uniform Items
// Vest Items
// Backpack Items
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
} forEach ((handgunWeapon _unit) + (uniformItems _unit) + (vestItems _unit) + (backpackItems _unit) + (assignedItems _unit));


[_actions, {call AGM_Interaction_fnc_hideMenu;}, {call AGM_Interaction_fnc_hideMenu;}] call AGM_Interaction_fnc_openSelectMenu;

// don't need an "Ok" Button
ctrlShow [8860, false];