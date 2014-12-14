/*
 * Author: KoffeinFlummi
 *
 * Deploys the ropes necessary for fast roping.
 *
 * Arguments:
 * 0: The helicopter
 *
 * Return Value:
 * None
 */

#define HELPER "AGM_FastRoping_Helper"
#define ROPELENGTH 35
#define OFFSET 2

_vehicle = _this select 0;

if !(local _vehicle) exitWith {
  [[_vehicle], "AGM_FastRoping_fnc_deployRopes", _vehicle] call AGM_Core_fnc_execRemoteFnc;
};

_ropePositions = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_FastRoping_Positions");
_ropes = [_ropePositions, {[objNull, objNull, objNull]}] call AGM_Core_fnc_map;
_occupied = [_ropePositions, {False}] call AGM_Core_fnc_map;

for "_i" from 0 to ((count _ropes) - 1) do {
  _ropePositions = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_FastRoping_Positions");
  _pos = _ropePositions select _i;

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
  _helper3 setPosATL [
    (getPosATL _helper1) select 0,
    (getPosATL _helper1) select 1,
    ((getPosATL _helper1) select 2) - OFFSET
  ];

  _ropes set [_i, [_rope1, _rope2, _helper2]];
};

_vehicle setVariable ["AGM_RopesDeployed", True, True];
_vehicle setVariable ["AGM_Ropes", _ropes, True];
_vehicle setVariable ["AGM_RopesOccupied", _occupied, True];
