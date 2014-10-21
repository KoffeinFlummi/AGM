/*
  Name: AGM_Interaction_fnc_openFriskMenu
  
  Author: jodav
  
  Description:
    Open the select menu with the "personal" items of a frisked unit
    It only shows "handgunWeapon", "uniformItems", "vestItems", "backpackItems" and "assignedItems" because every other item is visible on the character
  
  Parameters: 
    0: Object - player unit
    1: Object - unit

  Returns:
    Nothing
*/


private ["_player", "_unit", "_listedItemClasses", "_allGear"];

_player = _this select 0;
_unit = _this select 1;

_player playMoveNow "AmovPercMstpSlowWrflDnon";

_listedItemClasses = [];

_actions = [localize "STR_AGM_Interaction_FriskMenuHeader", localize "STR_AGM_Interaction_CancelSelection"] call AGM_Interaction_fnc_prepareSelectMenu;

_allGear = [];

if ((handgunWeapon _unit) != "") then {
  _allGear pushBack (handgunWeapon _unit);
};
if (count (uniformItems _unit) > 0) then {
  _allGear = _allGear + (uniformItems _unit);
};
if (count (vestItems _unit) > 0) then {
  _allGear = _allGear + (vestItems _unit);
};
if (count (backpackItems _unit) > 0) then {
  _allGear = _allGear + (backpackItems _unit);
};
if (count (assignedItems _unit) > 0) then {
  _allGear = _allGear + (assignedItems _unit);
};

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
} forEach (_allGear);


[_actions, {call AGM_Interaction_fnc_hideMenu;}, {call AGM_Interaction_fnc_hideMenu;}] call AGM_Interaction_fnc_openSelectMenu;

// don't need an "Ok" Button
ctrlShow [8860, false];