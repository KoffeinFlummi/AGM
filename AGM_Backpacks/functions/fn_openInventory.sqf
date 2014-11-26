// by bux, edited by commy2

private ["_target", "_isBackpack", "_isLocked"];

_target = _this select 1;

_isBackpack = [_target] call AGM_Backpacks_fnc_isBackpack;
_isLocked = _target getVariable ["AGM_LockedInventory", false];

if (_isBackpack) then {
  // target is a backpack
  private "_unit";
  _unit = [_target] call AGM_Backpacks_fnc_getBackpackAssignedUnit;

  if (!alive _unit || {_unit getVariable ["AGM_isUnconscious", false]}) exitWith {false};

  if (_isLocked) then {
    // target is a locked backpack
    [format [localize "STR_AGM_Backpacks_BackpackLocked", name _unit]] call AGM_Core_fnc_displayTextStructured;
    true
  } else {
    // target is a not-locked backpack
    if (_unit getVariable ["AGM_LockedInventory", false]) then {
      [localize "STR_AGM_Backpacks_InventoryLocked"] call AGM_Core_fnc_displayTextStructured;
      true
    } else {
      false
    }
  }
} else {
  // target is not a backpack
  if (_isLocked) then {
    [localize "STR_AGM_Backpacks_InventoryLocked"] call AGM_Core_fnc_displayTextStructured;
    true
  } else {
    false
  }
}
