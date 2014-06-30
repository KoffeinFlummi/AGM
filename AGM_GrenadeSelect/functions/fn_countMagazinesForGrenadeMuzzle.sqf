/*
 * Author: CAA-Picard
 *
 * Count how many grenade magazines the player has on the uniform and vest.
 * 
 * Argument:
 * 0: Muzzle name
 * 
 * Return value:
 * 0: Number of magazines
 * 1: First magazine name
 */

 _muzzle = _this;
 
_uniformMags = getMagazineCargo uniformContainer player;
_vestMags = getMagazineCargo vestContainer player;

_numberOfMagazines = 0;
_magazineClasses = getArray (configFile >> "CfgWeapons" >> "Throw" >> _muzzle >> "magazines" );
_firstMagazine = _magazineClasses select 0;
{
  _indexInUniform = (_uniformMags select 0) find _x;
  if (_indexInUniform > -1) then {
    _numberOfMagazines = _numberOfMagazines + ((_uniformMags select 1) select _indexInUniform);
    _firstMagazine = _x;
  };
  _indexInVest = (_vestMags select 0) find _x;  
  if (_indexInVest > -1) then {
    _numberOfMagazines = _numberOfMagazines + ((_vestMags select 1) select _indexInVest);
    _firstMagazine = _x;
  };
} forEach _magazineClasses;

[_numberOfMagazines, _firstMagazine]