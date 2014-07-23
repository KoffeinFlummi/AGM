AGM_CurrentMuzzleIsFrag = true;
AGM_CurrentMuzzleFrag = "";
AGM_CurrentMuzzleOther = "";
AGM_LastGrenadeThrowTime = -1000;
AGM_GrenadeSelectPopUp = false;

// Collect frag and other muzzles separately
AGM_MuzzlesFrags = [];
AGM_MuzzlesOthers = [];
_throwMuzzleNames = getArray (configfile >> "CfgWeapons" >> "Throw" >> "muzzles");
{
  _muzzleName = _x;
  _magazines = getArray (configFile >> "CfgWeapons" >> "Throw" >> _muzzleName >> "magazines" );
  _magazine = _magazines select 0;
  
  _ammo = getText (configfile >> "CfgMagazines" >> _magazine >> "ammo");
  _explosive = getNumber(configfile >> "CfgAmmo" >> _ammo >> "explosive");
  
  if (_explosive == 0) then {
    AGM_MuzzlesOthers = AGM_MuzzlesOthers + [_muzzleName];
  } else {
    AGM_MuzzlesFrags = AGM_MuzzlesFrags + [_muzzleName];
  };  
} forEach _throwMuzzleNames;

"" call AGM_GrenadeSelect_fnc_setNextGrenadeMuzzle;