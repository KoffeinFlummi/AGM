AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag = true;
AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = "";
AGM_WeaponSelect_CurrentGrenadeMuzzleOther = "";

// Collect frag and other muzzles separately
AGM_WeaponSelect_FragMuzzles = [];
AGM_WeaponSelect_NonFragMuzzles = [];
_throwMuzzleNames = getArray (configfile >> "CfgWeapons" >> "Throw" >> "muzzles");
{
  _muzzleName = _x;
  _magazines = getArray (configFile >> "CfgWeapons" >> "Throw" >> _muzzleName >> "magazines" );
  _magazine = _magazines select 0;
  
  _ammo = getText (configfile >> "CfgMagazines" >> _magazine >> "ammo");
  _explosive = getNumber(configfile >> "CfgAmmo" >> _ammo >> "explosive");
  
  if (_explosive == 0) then {
    AGM_WeaponSelect_NonFragMuzzles = AGM_WeaponSelect_NonFragMuzzles + [_muzzleName];
  } else {
    AGM_WeaponSelect_FragMuzzles = AGM_WeaponSelect_FragMuzzles + [_muzzleName];
  };  
} forEach _throwMuzzleNames;

// don't throw no nades if none selected!
_condition = {
  _magazines = magazines (call AGM_Core_fnc_player);
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
