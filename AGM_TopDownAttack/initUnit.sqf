// by commy2

_unit = _this select 0;

// @todo respawn?
_actionID = [_unit, "LockTarget", {getNumber (configFile >> "CfgWeapons" >> currentWeapon player >> "AGM_lockTargetMode") == 1}, {call AGM_TopDownAttack_fnc_lockTarget}] call AGM_Core_fnc_addActionEventHandler;

_unit setVariable ["AGM_TopDownAttack_LockTargetActionID", _actionID, false];
