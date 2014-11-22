/*
 * Author: KoffeinFlummi
 *
 * Start a cook-off in the given vehicle.
 *
 * Arguments:
 * 0: Vehicle
 *
 * Return Value:
 * Boom.
 */

#define SMOKE_ITERATIONS 6
#define SMOKE_PARTICLECOUNT 3000
#define COOKOFF_ITERATIONS 6
#define COOKOFF_PARTICLECOUNT 3000

if ((_this select 0) getVariable ["AGM_Armour_isCookingOff", False]) exitWith {};

if (count _this < 2) then {
  [_this + [True], "AGM_Armour_fnc_cookOff"] call AGM_Core_fnc_execRemoteFnc;
} else {
  if (local (_this select 0)) exitWith {};
};

(_this select 0) setVariable ["AGM_Armour_isCookingOff", True];

_this spawn {
  private ["_vehicle", "_positions", "_onTurret"];

  _vehicle = _this select 0;
  _positions = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Armour_CookOffLocations");
  _onTurret = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Armour_CookOffOnTurret");

  sleep 0.5 + (random 0.3);

  // Smoke out of cannon and hatches
  _smokeBarrel = "#particlesource" createVehicleLocal [0,0,0];
  _smokeBarrel setParticleClass "MediumDestructionSmoke";
  _smokeBarrel attachTo [_vehicle, _vehicle selectionPosition (getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets" >> "MainTurret" >> "gunBeg"))];

  _smokes = [];
  {
    _position = [
      - (_x select 0),
      - (_x select 2),
      (_x select 1)
    ];
    _smoke = "#particlesource" createVehicleLocal [0,0,0];
    _smoke setParticleClass "ObjectDestructionSmoke1_2Smallx";
    _smoke attachTo [_vehicle, _position];
    _smokes pushBack _smoke;
  } forEach _positions;

  sleep 3 + (random 2);

  // this shit is busy being on fire, can't go driving around all over the place
  if (local _vehicle) then {
    _vehicle setFuel 0;
  };

  // CookOffs
  _fires = [];
  {
    _position = [
      - (_x select 0),
      - (_x select 2),
      (_x select 1)
    ];
    _fire = "#particlesource" createVehicleLocal [0,0,0];
    _fire setParticleClass "AGM_CookOff";
    _fire attachTo [_vehicle, _position];
    _fires pushBack _fire;
  } forEach _positions;

  sleep (4 + random 1);

  deleteVehicle _smokeBarrel;
  [_smokes, {deleteVehicle _this}] call AGM_Core_fnc_map;
  [_fires, {deleteVehicle _this}] call AGM_Core_fnc_map;

  (_this select 0) setVariable ["AGM_Armour_isCookingOff", False];
  if (local _vehicle) then {
    _vehicle setDamage 1;
  };
};

