/*
 * Author: CAA-Picard
 *
 * Cycle through non explosive grenades.
 * 
 * Argument:
 * None
 * 
 * Return value:
 * None
 */

_uniformMags = getMagazineCargo uniformContainer player;
_vestMags = getMagazineCargo vestContainer player;

// Check which is the next muzzle which the player has magazines for
_nextIndex = (AGM_MuzzlesOthers find AGM_CurrentMuzzleOther);
// If switching grenades from frags, then check the current non frag first
if ((_nextIndex > -1) and AGM_CurrentMuzzleIsFrag) then {_nextIndex = _nextIndex - 1;};

_numberChecked = 0;
_numberOfMagazines = 0;
_firstMagazine = "";
while  {(_numberChecked < count AGM_MuzzlesOthers) and _numberOfMagazines == 0} do {
  _nextIndex = _nextIndex + 1;
  if (_nextIndex >= count AGM_MuzzlesOthers) then {_nextIndex = 0};
  
  // Count if player has any magazines from this muzzle
  _result = (AGM_MuzzlesOthers select _nextIndex) call AGM_GrenadeSelect_fnc_countMagazinesForGrenadeMuzzle;
  _numberOfMagazines = _result select 0;
  _firstMagazine = _result select 1;
  
  _numberChecked = _numberChecked + 1;
};

if (_numberOfMagazines > 0) then {
  // There is a muzzle with magazines --> cycle to it
  AGM_CurrentMuzzleOther = AGM_MuzzlesOthers select _nextIndex;
  [_firstMagazine, _numberOfMagazines] call AGM_GrenadeSelect_fnc_displayGrenadeTypeAndNumber;
  
  // Select the correct muzzle
  AGM_CurrentMuzzleOther call AGM_GrenadeSelect_fnc_setNextGrenadeMuzzle;

  AGM_GrenadeSelectPopUp = false;
} else {
  // There is a no muzzle with magazines --> select nothing
  AGM_CurrentMuzzleOther = "";
  AGM_CurrentMuzzleOther call AGM_GrenadeSelect_fnc_setNextGrenadeMuzzle;
  
  _text = [localize "STR_AGM_GrenadeSelect_NoMiscGrenadeLeft", [1,0,0]] call AGM_Core_fnc_stringToColoredText;
  [composeText [lineBreak, _text]] call AGM_Core_fnc_displayTextStructured;
  
  AGM_GrenadeSelectPopUp = false;
};

AGM_CurrentMuzzleIsFrag = false;
