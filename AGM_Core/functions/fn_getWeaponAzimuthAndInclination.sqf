/*
 * Author: commy2
 *
 * Get players weapon direction and slope
 * 
 * Argument:
 * 0: Weapon name (String)
 * 
 * Return value:
 * 0: Azimuth (Number)
 * 1: Inclination or 'slope' (Number)
 */

private ["_weapon", "_direction", "_azimuth", "_inclination"];

_weapon = _this select 0;

_direction = AGM_player weaponDirection _weapon;

_azimuth = (_direction select 0) atan2 (_direction select 1);
_inclination = asin (_direction select 2);

if (_azimuth < 0) then {_azimuth = _azimuth + 360};

[_azimuth, _inclination]
