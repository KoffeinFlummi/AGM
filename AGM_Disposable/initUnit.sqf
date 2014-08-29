// by commy2

_unit = _this select 0;

// @todo respawn?
_actionID = [_unit, "LockTarget", {getNumber (configFile >> "CfgWeapons" >> currentWeapon player >> "AGM_lockTargetMode") == 1}, {call AGM_Disposable_fnc_lockTarget}] call AGM_Core_fnc_addActionEventHandler;

_unit setVariable ["AGM_Disposable_LockTargetActionID", _actionID, false];

