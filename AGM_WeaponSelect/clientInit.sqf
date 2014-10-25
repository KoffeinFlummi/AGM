// by CAA-Picard, commy2

AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag = true;
AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = "";
AGM_WeaponSelect_CurrentGrenadeMuzzleOther = "";

// Collect frag and other muzzles separately
AGM_WeaponSelect_FragMuzzles = [];
AGM_WeaponSelect_NonFragMuzzles = [];
AGM_WeaponSelect_AllMuzzles = [];
_throwMuzzleNames = getArray (configfile >> "CfgWeapons" >> "Throw" >> "muzzles");
{
  _muzzleName = _x;
  _magazines = getArray (configFile >> "CfgWeapons" >> "Throw" >> _muzzleName >> "magazines" );
  _magazine = _magazines select 0;
  
  _ammo = getText (configfile >> "CfgMagazines" >> _magazine >> "ammo");
  _explosive = getNumber(configfile >> "CfgAmmo" >> _ammo >> "explosive");
  
  if (_explosive == 0) then {
    AGM_WeaponSelect_NonFragMuzzles pushBack _muzzleName;
  } else {
    AGM_WeaponSelect_FragMuzzles pushBack _muzzleName;
  };
  AGM_WeaponSelect_AllMuzzles pushBack _muzzleName;
} forEach _throwMuzzleNames;

// don't throw no nades if none selected!
_condition = {
  _magazines = magazines (_this select 1);
  _muzzle = [AGM_WeaponSelect_CurrentGrenadeMuzzleOther, AGM_WeaponSelect_CurrentGrenadeMuzzleFrag] select AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag;

  if (_muzzle == "") exitWith {true};

  _result = true;
  {
    if (_x in _magazines) exitWith {_result = false};
  } forEach getArray (configFile >> "CfgWeapons" >> "Throw" >> _muzzle >> "magazines");

  if (_result) then {
    if (AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag) then {AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = ""} else {AGM_WeaponSelect_CurrentGrenadeMuzzleOther = ""};
  };
  _result
};

_statement = {
  [localize "STR_AGM_WeaponSelect_NoGrenadeSelected"] call AGM_Core_fnc_displayTextStructured;
};

[player, "Throw", _condition, _statement] call AGM_Core_fnc_addActionEventHandler;
[player, "CycleThrownItems", {true}, {[_this select 1] call AGM_WeaponSelect_fnc_selectGrenadeAll}] call AGM_Core_fnc_addActionEventHandler;
