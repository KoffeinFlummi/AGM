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

if ((_this select 0) getVariable ["AGM_Armour_CookingOff", False]) exitWith {};
(_this select 0) setVariable ["AGM_Armour_CookingOff", True];

_this spawn {
  private ["_vehicle", "_positions", "_onTurret"];

  _vehicle = _this select 0;
  _positions = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Armour_CookOffLocations");
  _onTurret = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Armour_CookOffOnTurret");

  // this shit is busy being on fire, can't go driving around all over the place
  _vehicle setFuel 0;

  sleep 0.5 + (random 0.3);

  // Smoke out of cannon and hatches
  _smokeMain = "#particlesource" createVehicleLocal [0,0,0];
  _smokeMain setParticleClass "BigDestructionSmoke";
  _smokeMain attachTo [_vehicle, _vehicle worldToModel [getPos _vehicle select 0,getPos _vehicle select 1,4]];
  _smokeBarrel = "#particlesource" createVehicleLocal [0,0,0];
  _smokeBarrel setParticleClass "MediumDestructionSmoke";
  _smokeBarrel attachTo [_vehicle, _vehicle selectionPosition (getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets" >> "MainTurret" >> "gunBeg"))];

  sleep 3 + (random 2);

  // CookOffs
  {
    [_vehicle, _x, _onTurret select _forEachIndex] spawn {
      private ["_vehicle", "_position", "_onTurret", "_positionRotated"];
      _vehicle = _this select 0;
      _position = _this select 1;
      _onTurret = _this select 2;
      for "_i" from 0 to COOKOFF_ITERATIONS do {
        _positionRotated = [
          - (_position select 0),
          - (_position select 2),
          (_position select 1)
        ];
        // @todo: rotate around center of turret.
        for "_j" from 0 to COOKOFF_PARTICLECOUNT do {
          drop [
            ["\A3\data_f\ParticleEffects\Universal\Universal", 32, 10, 1, 16],
            "",
            "Billboard",
            3,
            0.25 * ((8 - _i) / 6),
            [
              (_positionRotated select 0) + (random 0.5) - 0.25,
              (_positionRotated select 1) + (random 0.5) - 0.25,
              (_positionRotated select 2) + (random 0.8)
            ],
            [(random 3) - 1.5, (random 3) - 1.5, 15],
            0,
            0.05,
            0.04,
            0.02,
            [0.5,0.1],
            [[1,0.8,0.8,-80],[1,0.8,0.8,-80],[0,0,0,0]],
            [1],
            0.2,
            0.3,
            "",
            "",
            _vehicle
          ];
        };
        sleep 0.015;
      };
    };
  } forEach _positions;

  sleep (4 + random 1);

  deleteVehicle _smokeMain;
  deleteVehicle _smokeBarrel;

  (_this select 0) setVariable ["AGM_Armour_CookingOff", False];
  _vehicle setDamage 1;
};

