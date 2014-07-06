/*
 * Author: CAA-Picard
 *
 * Throw current grenade type.
 *
 * Argument:
 * None
 *
 * Return value:
 * None
 */

 if ((time - AGM_LastGrenadeThrowTime) < 1) exitWith {};
 AGM_LastGrenadeThrowTime = time;

_muzzle = if (AGM_CurrentMuzzleIsFrag) then {AGM_CurrentMuzzleFrag} else {AGM_CurrentMuzzleOther};

// Check if a muzzle is selected
if (_muzzle == "") exitWith {
  _text = [localize "STR_AGM_GrenadeSelect_NoGrenadeSelected", [1,1,1]] call AGM_Core_fnc_stringToColoredText;
  [composeText [lineBreak, _text]] call AGM_Core_fnc_displayTextStructured;
};

// Check if there is enough ammo
_result = _muzzle call AGM_GrenadeSelect_fnc_countMagazinesForGrenadeMuzzle;
_numberOfMagazines = _result select 0;
_firstMagazine = _result select 1;

if (_numberOfMagazines > 0) then {
  // Raise weapon if necesary, forceWeaponFire doesn't work with weapon lowered
  if ((currentWeapon player != "") and (weaponLowered player)) then {
    player action ["WEAPONINHAND", player];
  };
  player forceWeaponFire [_muzzle,_muzzle];
};

if (AGM_GrenadeSelectPopUp) exitWith {};

// Show how many grenades of the current muzzle remain
[_muzzle] spawn {
  _thrownMuzzle = _this select 0;

  AGM_GrenadeSelectPopUp = true;
  sleep 1;

  // Only show if player has not cycled grenades since last throw
  _currentMuzzle = if (AGM_CurrentMuzzleIsFrag) then {AGM_CurrentMuzzleFrag} else {AGM_CurrentMuzzleOther};
  if (_thrownMuzzle == _currentMuzzle) then {
    _result = _thrownMuzzle call AGM_GrenadeSelect_fnc_countMagazinesForGrenadeMuzzle;
    _numberOfMagazines = _result select 0;
    _firstMagazine = _result select 1;
    [_firstMagazine, _numberOfMagazines] call AGM_GrenadeSelect_fnc_displayGrenadeTypeAndNumber;
  };
  AGM_GrenadeSelectPopUp = false;
};