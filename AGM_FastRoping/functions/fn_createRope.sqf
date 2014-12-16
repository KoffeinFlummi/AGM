/*
 * Author: KoffeinFlummi
 *
 * Creates a rope for the vehicle at the given position.
 *
 * Arguments:
 * 0: Vehicle
 * 1: Position
 * 2: Spawn bottom part of rope in place? (Default: False)
 *
 * Return Value:
 * Array:
 *   0: rope 1
 *   1: rope 2
 *   2-4: helper objects
 *
 * __/X <- helper 1
 *    | <- rope 1
 *    |
 *    X <- helper 2; attached to player
 *    |
 *    | <- rope 2
 *    |
 *    X <- helper 3
 */

#define HELPER "AGM_FastRoping_Helper"
#define ROPELENGTH 35
#define OFFSET 2

private ["_vehicle", "_position", "_inPlace", "_helper1", "_helper2", "_helper3", "_rope1", "_rope2"];

_vehicle = _this select 0;
_position = _this select 1;
_inPlace = False;
if (count _this > 2 and {_this select 2}) then {
  _inPlace = True;
};

_helper1 = HELPER createVehicle [0,0,0];
_helper1 allowDamage False;
_helper1 setPosATL [
  (getPosATL _vehicle) select 0,
  (getPosATL _vehicle) select 1,
  ((getPosATL _vehicle) select 2) - OFFSET * 2
];

_helper2 = HELPER createVehicle [0,0,0];
_helper2 allowDamage False;
_helper2 setPosATL (getPosATL _helper1);

_helper3 = HELPER createVehicle [0,0,0];
_helper3 allowDamage False;
_helper3 setPosATL (getPosATL _helper1);

_rope1 = ropeCreate [_helper1, [0,0,0], _helper2, [0,0,0], OFFSET];
_rope2 = ropeCreate [_helper2, [0,0,0], _helper3, [0,0,0], ROPELENGTH - OFFSET];

_helper1 attachTo [_vehicle, _pos];
_helper2 setPosATL [
  (getPosATL _helper1) select 0,
  (getPosATL _helper1) select 1,
  ((getPosATL _helper1) select 2) - OFFSET
];
if (_inPlace) then {
  _building = (getPosATL _helper1 select 2) - (getPos _helper1 select 2);
  _helper3 setPosATL [
    (getPosATL _helper1) select 0,
    (getPosATL _helper1) select 1,
    (((getPosATL _helper1) select 2) - ROPELENGTH) max _building
  ];
} else {
  _helper3 setPosATL [
    (getPosATL _helper1) select 0,
    (getPosATL _helper1) select 1,
    ((getPosATL _helper1) select 2) - OFFSET
  ];
};

[_rope1, _rope2, _helper1, _helper2, _helper3]
