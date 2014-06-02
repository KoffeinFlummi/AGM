/*
 * Author: KoffeinFlummi
 *
 * Checks if the mission has the wind set to automatic, and if so, changes that.
 *
 * Arguments:
 * none
 *
 * Return Value:
 * none
 */

if !(isServer) exitWith {};

0 spawn {
  _windDir = windDir;
  _windDirSum = 0;
  for "_i" from 1 to 5 do {
    _windDirOld = _windDir;
    _windDir = windDir;
    _windDirSum = _windDirSum + abs (_windDir - _windDirOld);
    sleep 1;
  };

  if (_windDirSum > 10) then {
    setWind [(wind select 0), (wind select 1), true];
  };
};