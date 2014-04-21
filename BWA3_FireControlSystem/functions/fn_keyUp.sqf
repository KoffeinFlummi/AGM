/*
 * Author: KoffeinFlummi
 *
 * Calculates the offsets for all weapons needed to hit the current target.
 *
 * Arguments:
 * none
 *
 * Return Value:
 * none
 */

if ((_this select 1) != 15) exitWith {false};
if (player != gunner (vehicle player)) exitWith {};

_vehicle = vehicle player;
_magazines = magazines _vehicle;

_distance = [5, 5000, 0] call BWA3_Core_fnc_getTargetDistance; // maximum distance: 5000m, 5m precision
_angleTarget = asin ((_vehicle weaponDirection (currentWeapon _vehicle)) select 2);

_FCSMagazines = [];
_FCSOffsets = [];

/*
for "_i" from 0 to (count _magazines - 1) do {
  _magazineType = _magazines select _i;
  if !(_magazineType in _FCSMagazines) then {
    _FCSMagazines = _FCSMagazines + [_magazineType];
    _ammoType = getText (configFile >> "CfgMagazines" >> _magazineType >> "ammo");

    _angleTarget = asin (vehicle player weaponDirection currentWeapon vehicle player select 2);
    _maxElev        = getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets" >> "MainTurret" >> "maxElev");
    _initSpeed      = getNumber (configFile >> "CfgMagazines" >> _magazineType >> "initSpeed");
    _airFriction    = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "airFriction");
    _timeToLive     = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "timeToLive");
    _simulationStep = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "simulationStep");

    _offset = [_distance, _angleTarget, _maxElev, _initSpeed, _airFriction, _timeToLive, _simulationStep] call BWA3_FCS_fnc_getAngle;
    _FCSOffsets = _FCSOffsets + [_offset];
  };
};
*/

_magazineType   = currentMagazine _vehicle;
_ammoType       = getText   (configFile >> "CfgMagazines" >> _magazineType >> "ammo");
_maxElev        = getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets" >> "MainTurret" >> "maxElev");
_initSpeed      = getNumber (configFile >> "CfgMagazines" >> _magazineType >> "initSpeed");
_airFriction    = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "airFriction");
_timeToLive     = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "timeToLive");
_simulationStep = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "simulationStep");

_offset = [_distance, _angleTarget, _maxElev, _initSpeed, _airFriction, _timeToLive, _simulationStep] call BWA3_FCS_fnc_getAngle;

_FCSMagazines = _FCSMagazines + [_magazineType];
_FCSOffsets = _FCSOffsets + [_offset];

_vehicle setVariable ["BWA3_FCSMagazines", _FCSMagazines, true];
_vehicle setVariable ["BWA3_FCSOffsets", _FCSOffsets, true];

hintSilent format ["Zeroed To: %1", _distance];

true