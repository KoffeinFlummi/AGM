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
