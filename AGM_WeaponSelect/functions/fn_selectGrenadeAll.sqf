/*
 * Author: CAA-Picard, commy2
 *
 * Cycle through all grenades.
 *
 * Argument:
 * None
 *
 * Return value:
 * None
 */

private ["_player", "_nextMuzzle"];

_player = _this select 0;

_nextMuzzle = ["All"] call AGM_WeaponSelect_fnc_findNextGrenadeMuzzle;

if (_nextMuzzle != "") then {


  private ["_magazines", "_magazine", "_count", "_return"];
  _magazines = AGM_WeaponSelect_AllMagazines select (AGM_WeaponSelect_AllMuzzles find _nextMuzzle);
  reverse _magazines;

  _magazine = "";
  _count = {_return = _x in _magazines; if (_return) then {_magazine = _x}; _return} count magazines _player;

  // There is a muzzle with magazines --> cycle to it
  [_player, _nextMuzzle] call AGM_WeaponSelect_fnc_setNextGrenadeMuzzle;

  [_magazine, _count] call AGM_WeaponSelect_fnc_displayGrenadeTypeAndNumber;

  [uiNamespace getVariable "AGM_dlgSoldier", true] call AGM_WeaponSelect_fnc_toggleGrenadeCount;
} else {
  // There is a no muzzle with magazines --> select nothing
  AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = ""; AGM_WeaponSelect_CurrentGrenadeMuzzleOther = "";

  _text = [localize "STR_AGM_WeaponSelect_NoGrenadesLeft", [1,0,0]] call AGM_Core_fnc_stringToColoredText;
  [composeText [lineBreak, _text]] call AGM_Core_fnc_displayTextStructured;

  [uiNamespace getVariable "AGM_dlgSoldier", false] call AGM_WeaponSelect_fnc_toggleGrenadeCount;
};

if (_nextMuzzle in AGM_WeaponSelect_FragMuzzles) then {
  AGM_WeaponSelect_CurrentGrenadeMuzzleFrag = _nextMuzzle;
  AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag = true;
} else {
  AGM_WeaponSelect_CurrentGrenadeMuzzleOther = _nextMuzzle;
  AGM_WeaponSelect_CurrentGrenadeMuzzleIsFrag = false;
};
