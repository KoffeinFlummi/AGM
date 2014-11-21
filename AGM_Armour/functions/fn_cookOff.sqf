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

#define ITERATIONS 3
#define PARTICLECOUNT 3000

// @todo: figure out cook-off time
// @todo: create particle effect and wait for a while.
// @todo: spawn explosion; destroy vehicle.

if ((_this select 0) getVariable ["AGM_Armour_CookingOff", False]) exitWith {};
(_this select 0) setVariable ["AGM_Armour_CookingOff", True];

_this spawn {
  private ["_vehicle", "_positions", "_onTurret"];

  _vehicle = _this select 0;

  _vehicle setFuel 0;

  sleep 0.5 + (random 0.3);

  // Cannon Smoke
  // for "_i" from 0 to 3 do {
  //   _gunBeg = _vehicle selectionPosition getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets" >> "MainTurret" >> "gunBeg");
  //   _gunEnd = _vehicle selectionPosition getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets" >> "MainTurret" >> "gunEnd");
  //   _velocity = (_gunBeg vectorFromTo _gunEnd) vectorMultiply 10;
  //   _velocity = _velocity vectorAdd [(random 3) - 1.5, (random 3) - 1.5, (random 3) - 1.5];
  //   for "_j" from 0 to 3000 do {
  //     drop [
  //       ["\A3\data_f\ParticleEffects\Universal\Universal", 8, 12, 0, 16],
  //       "",
  //       "Billboard",
  //       1,
  //       2.1,
  //       _gunBeg,
  //       _velocity,
  //       1,
  //       0.1285,
  //       0.1,
  //       0.8,
  //       [0.25,0.6,1.1],
  //       [[0.8,0.8,0.8,0.4],[0.8,0.8,0.8,0.3],[0.8,0.8,0.8,0.05],[0.8,0.8,0.8,0.01]],
  //       [2, 1],
  //       0.05,
  //       0.15,
  //       "",
  //       "",
  //       _vehicle
  //     ];
  //   };
  //   sleep 0.03;
  // };

  // Hull & Turret CookOffs
  _positions = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Armour_CookOffLocations");
  _onTurret = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Armour_CookOffOnTurret");
  {
    [_vehicle, _x, _onTurret select _forEachIndex] spawn {
      _vehicle = _this select 0;
      _position = _this select 1;
      _onTurret = _this select 2;
      for "_i" from 0 to ITERATIONS do {
        _positionRotated = [
          - (_position select 0),
          - (_position select 2),
          (_position select 1)
        ];
        // @todo: rotate around center of turret.
        for "_j" from 0 to PARTICLECOUNT do {
          drop [
            ["\A3\data_f\ParticleEffects\Universal\Universal", 32, 10, 1, 16],
            "",
            "Billboard",
            3,
            0.5 * ((8 - _i) / 5),
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
        sleep 0.03;
      };
    };
  } forEach _positions;

  sleep (3 + random 0.5);

  (_this select 0) setVariable ["AGM_Armour_CookingOff", False];
  _vehicle setDamage 1;
};

