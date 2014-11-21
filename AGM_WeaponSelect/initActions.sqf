// by commy2

private ["_unit", "_fnc_actionThrowCondition", "_fnc_actionThrow", "_id"];

_unit = _this select 0;

_fnc_actionThrowCondition = {
  _muzzle = call AGM_WeaponSelect_fnc_getSelectedGrenade;

  _isInput = inputAction "CycleThrownItems" > 0;
  if !(_isInput isEqualTo (missionNamespace getVariable ["AGM_WeaponSelect_CycleThrownItemsState", false])) then {
    if (_isInput && {_muzzle == ""}) then {
      // @todo select last muzzle to roll over
    };
    AGM_WeaponSelect_CycleThrownItemsState = _isInput;
  };

  if (_muzzle == "") exitWith {true};

  // fix auto muzzle swap after entering or leaving a vehicle
  if (_this select 0 != missionNamespace getVariable ["AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle", objNull]) then {
    [_this select 1, _muzzle] call AGM_WeaponSelect_fnc_setNextGrenadeMuzzle;
    AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle = _this select 0;
  };

  if !([_this select 1] call AGM_Core_fnc_canUseWeapon) exitWith {false};

  _magazines = magazines (_this select 1);

  // check if there is still a magazine
  _result = true;
  with uiNamespace do {
    {
      if (_x in _magazines) exitWith {_result = false};
    } forEach (AGM_WeaponSelect_AllMagazines select (AGM_WeaponSelect_AllMuzzles find _muzzle));
  };

  if (_result) then {
    if (AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag) then {AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = ""} else {AGM_WeaponSelect_CurrentGrenadeMuzzleOther = ""};
    [uiNamespace getVariable "AGM_dlgSoldier", false] call AGM_WeaponSelect_fnc_toggleGrenadeCount;
  };
  _result
};

_fnc_actionThrow = {
  _text = [localize "STR_AGM_WeaponSelect_NoGrenadeSelected", [1,0,0]] call AGM_Core_fnc_stringToColoredText;
  [composeText [lineBreak, _text]] call AGM_Core_fnc_displayTextStructured;
};

_id = [
  _unit,
  format ["<t color=""#FFFFFF"" >%1</t>", localize "STR_AGM_WeaponSelect_ReadyGrenade"],
  "Throw",
  _fnc_actionThrowCondition,
  _fnc_actionThrow,
  {true},
  {[_this select 1] call AGM_WeaponSelect_fnc_selectGrenadeAll},
  2
] call AGM_Core_fnc_addActionMenuEventHandler;

_unit setVariable ["AGM_WeaponSelect_ThrowActionID", _id];
