// by commy2

// don't throw no nades if none selected!
if (isNil "AGM_WeaponSelect_actionThrowCondition") then {
  AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle = objNull;
  AGM_WeaponSelect_NextGrenadeMagazineName = "";

  AGM_WeaponSelect_actionThrowCondition = {
    _muzzle = call AGM_WeaponSelect_fnc_getSelectedGrenade;

    _magazines = magazines (_this select 1);

    // get next mag for updated action name.
    _nextMagazine = "";

    _index = AGM_WeaponSelect_AllMuzzles find _muzzle;

    scopeName "SearchMain";

    for "_index" from (_index + 1) to (count AGM_WeaponSelect_AllMuzzles - 1) do {
      {
        if (_x in (AGM_WeaponSelect_AllMagazines select _index)) exitWith {_nextMagazine = _x; breakTo "SearchMain"};
      } count _magazines;
    };

    if (_nextMagazine == "") then {
      for "_index" from 0 to (_index - 1) do {
        {
          if (_x in (AGM_WeaponSelect_AllMagazines select _index)) exitWith {_nextMagazine = _x; breakTo "SearchMain"};
        } count _magazines;
      };
    };

    if (_nextMagazine != AGM_WeaponSelect_NextGrenadeMagazineName) then {
      _string = getText (configFile >> "CfgMagazines" >> _nextMagazine >> "displayNameShort");
      if (_string == "") then {_string = getText (configFile >> "CfgMagazines" >> _nextMagazine >> "displayName")};

      (_this select 1) setUserActionText [(_this select 1) getVariable ["AGM_WeaponSelect_actionCycleThrownItems_ID", -1], format [localize "STR_AGM_WeaponSelect_TakeGrenade", _string]];
      AGM_WeaponSelect_NextGrenadeMagazineName = _nextMagazine;
    };

    if (_muzzle == "" && {_nextMagazine == ""}) exitWith {false};
    if (_muzzle == "") exitWith {true};

    // fix auto muzzle swap after entering or leaving a vehicle
    if (_this select 0 != AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle) then {
      [_this select 1, _muzzle] call AGM_WeaponSelect_fnc_setNextGrenadeMuzzle;
      AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle = _this select 0;
    };

    if !([_this select 1] call AGM_Core_fnc_canUseWeapon) exitWith {false};

    // check if there is still a magazine
    _result = true;
    with uiNamespace do {
      {
        if (_x in _magazines) exitWith {_result = false};
      } forEach (AGM_WeaponSelect_AllMagazines select (AGM_WeaponSelect_AllMuzzles find _muzzle)); // getArray (configFile >> "CfgWeapons" >> "Throw" >> _muzzle >> "magazines");
    };

    if (_result) then {
      if (AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag) then {AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = ""} else {AGM_WeaponSelect_CurrentGrenadeMuzzleOther = ""};
      [uiNamespace getVariable "AGM_dlgSoldier", false] call AGM_WeaponSelect_fnc_toggleGrenadeCount;
    };
    _result
  };

  AGM_WeaponSelect_actionThrow = {
    _text = [localize "STR_AGM_WeaponSelect_NoGrenadeSelected", [1,0,0]] call AGM_Core_fnc_stringToColoredText;
    [composeText [lineBreak, _text]] call AGM_Core_fnc_displayTextStructured;
  };
};

//[_this select 0, "Throw", AGM_WeaponSelect_actionThrowCondition, AGM_WeaponSelect_actionThrow] call AGM_Core_fnc_addActionEventHandler;
//[_this select 0, "CycleThrownItems", {[_this select 1] call AGM_Core_fnc_canUseWeapon}, {[_this select 1] call AGM_WeaponSelect_fnc_selectGrenadeAll}] call AGM_Core_fnc_addActionEventHandler;
[
  _this select 0,
  format ["<t color=""#FFFF00"" >%1</t>", localize "STR_AGM_WeaponSelect_TakeNextGrenade"],
  "Throw",
  AGM_WeaponSelect_actionThrowCondition,
  AGM_WeaponSelect_actionThrow,
  {true},
  {[_this select 1] call AGM_WeaponSelect_fnc_selectGrenadeAll},
  10
] call AGM_Core_fnc_addActionMenuEventHandler;

_id = [
  _this select 0,
  localize "STR_AGM_WeaponSelect_TakeNextGrenade",
  "CycleThrownItems",
  {[_this select 1] call AGM_Core_fnc_canUseWeapon && {AGM_WeaponSelect_NextGrenadeMagazineName != ""}},
  {[_this select 1] call AGM_WeaponSelect_fnc_selectGrenadeAll},
  {true},
  {[_this select 1] call AGM_WeaponSelect_fnc_selectGrenadeAll},
  0
] call AGM_Core_fnc_addActionMenuEventHandler;

// save actual add action id
(_this select 0) setVariable ["AGM_WeaponSelect_actionCycleThrownItems_ID", ((_this select 0) getVariable "AGM_ActionMenu_CycleThrownItems") select 2 select _id select 0];
