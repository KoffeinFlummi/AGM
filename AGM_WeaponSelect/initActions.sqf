// by commy2

private ["_unit", "_fnc_actionThrowCondition", "_fnc_actionThrow", "_id"];

_unit = _this select 0;

_fnc_actionThrowCondition = {
  _muzzle = call AGM_WeaponSelect_fnc_getSelectedGrenade;

  _isInput = inputAction "CycleThrownItems" > 0;
  if !(_isInput isEqualTo (missionNamespace getVariable ["AGM_WeaponSelect_CycleThrownItemsState", false])) then {
    if (_isInput && {_muzzle == ""}) then {
      [_this select 1] spawn AGM_WeaponSelect_fnc_selectGrenadeAll;
    };
    AGM_WeaponSelect_CycleThrownItemsState = _isInput;
  };

  if !([_this select 1] call AGM_Core_fnc_canUseWeapon) exitWith {false};

  if (_muzzle == "") exitWith {["All"] call AGM_WeaponSelect_fnc_findNextGrenadeMagazine != ""};

  // fix auto muzzle swap after entering or leaving a vehicle
  if (_this select 0 != missionNamespace getVariable ["AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle", objNull]) then {
    [_this select 1, _muzzle] call AGM_WeaponSelect_fnc_setNextGrenadeMuzzle;
    AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle = _this select 0;
  };

  if ((_this select 1) ammo _muzzle == 0) exitWith {
    if (AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag) then {AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = ""} else {AGM_WeaponSelect_CurrentGrenadeMuzzleOther = ""};
    [uiNamespace getVariable "AGM_dlgSoldier", false] call AGM_WeaponSelect_fnc_toggleGrenadeCount;
    true
  };
  false
};

_fnc_actionThrow = {
  _text = [localize "STR_AGM_WeaponSelect_NoGrenadeSelected", [1,0,0]] call AGM_Core_fnc_stringToColoredText;
  [composeText [lineBreak, _text]] call AGM_Core_fnc_displayTextStructured;
};

/*_id = [
  _unit,
  format ["<t color=""#FFFFFF"" >%1</t>", localize "STR_AGM_WeaponSelect_ReadyGrenade"],
  "Throw",
  _fnc_actionThrowCondition,
  _fnc_actionThrow,
  {true},
  {[_this select 1] call AGM_WeaponSelect_fnc_selectGrenadeAll},
  2
] call AGM_Core_fnc_addActionMenuEventHandler;*/

_id = [
  _unit,
  "Throw",
  _fnc_actionThrowCondition,
  _fnc_actionThrow
] call AGM_Core_fnc_addActionEventHandler;

_unit setVariable ["AGM_WeaponSelect_ThrowActionID", _id];
