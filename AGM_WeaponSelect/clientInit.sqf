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
