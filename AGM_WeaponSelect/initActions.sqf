// by commy2

// don't throw no nades if none selected!
if (isNil "AGM_WeaponSelect_actionThrowCondition") then {
  AGM_WeaponSelect_actionThrowCondition = {
    _muzzle = [AGM_WeaponSelect_CurrentGrenadeMuzzleOther, AGM_WeaponSelect_CurrentGrenadeMuzzleFrag] select AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag;

    if (_muzzle == "") exitWith {true};

    // fix auto muzzle swap after entering or leaving a vehicle
    if (_this select 0 != missionNamespace getVariable ["AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle", objNull]) then {
      [_this select 1, _muzzle] call AGM_WeaponSelect_fnc_setNextGrenadeMuzzle;
      AGM_WeaponSelect_CurrentGrenadeMuzzleVehicle = _this select 0;
    };

    if !([_this select 1] call AGM_Core_fnc_canUseWeapon) exitWith {false};

    _magazines = magazines (_this select 1);

    _result = true;
    {
      if (_x in _magazines) exitWith {_result = false};
    } forEach getArray (configFile >> "CfgWeapons" >> "Throw" >> _muzzle >> "magazines");

    if (_result) then {
      if (AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag) then {AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = ""} else {AGM_WeaponSelect_CurrentGrenadeMuzzleOther = ""};
    };
    _result
  };

  AGM_WeaponSelect_actionThrow = {
    _text = [localize "STR_AGM_WeaponSelect_NoGrenadeSelected", [1,0,0]] call AGM_Core_fnc_stringToColoredText;
    [composeText [lineBreak, _text]] call AGM_Core_fnc_displayTextStructured;
  };
};

[_this select 0, "Throw", AGM_WeaponSelect_actionThrowCondition, AGM_WeaponSelect_actionThrow] call AGM_Core_fnc_addActionEventHandler;
[_this select 0, "CycleThrownItems", {[_this select 1] call AGM_Core_fnc_canUseWeapon}, {[_this select 1] call AGM_WeaponSelect_fnc_selectGrenadeAll}] call AGM_Core_fnc_addActionEventHandler;
