// by commy2 and CAA-Picard

if (!hasInterface) exitWith {};

AGM_Interaction_isOpeningDoor = false;
AGM_Dancing = false;

// restore global fire teams for JIP
{
  _team = _x getVariable ["AGM_assignedFireTeam", ""];
  if (_team != "") then {_x assignTeam _team};
} forEach allUnits;


player addEventHandler ["InventoryOpened", {
  
  private ["_curTarget", "_inventory", "_override"];
  
  _curTarget = cursorTarget;
  _inventory = (_this select 1);
  _override = false;
  
  if ((_curTarget == _inventory) && (_inventory getVariable ["AGM_LockedInventory", false]) && (alive _inventory)) then {
    // a box or similar
    _override = true;
    [(localize "STR_AGM_Interaction_InventoryLocked")] call AGM_Core_fnc_displayTextStructured;
  };
  
  if ((backpackContainer _curTarget == _inventory) && ((backpackContainer _curTarget) getVariable ["AGM_LockedInventory", false]) && (alive _curTarget) && !(_curTarget getVariable ['AGM_Unconscious', false])) then {
    // a unit's backpack
    _override = true;
    [format [(localize "STR_AGM_Interaction_BackpackLocked"), name _curTarget]] call AGM_Core_fnc_displayTextStructured;
  };
  
  _override
}];
