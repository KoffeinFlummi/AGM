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

_vehicle = _this select 0;

_ropePositions = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_FastRoping_Positions");
_ropes = [_ropePositions, {[objNull, objNull, objNull]}] call AGM_Core_fnc_map;
_occupied = [_ropePositions, {False}] call AGM_Core_fnc_map;

for "_i" from 0 to ((count _ropes) - 1) do {
  _ropePositions = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_FastRoping_Positions");
  systemChat (str _ropePositions);
  _pos = _ropePositions select _i;
  systemChat (str _pos);
  _posWorld = _vehicle modelToWorld _pos;
  _helper = HELPER createVehicle [_posWorld select 0, _posWorld select 1, (_posWorld select 2) - 1.5];
  _helper allowDamage False;
  _helper disableCollisionWith _vehicle; // @todo: locality
  _rope1 = ropeCreate [_vehicle, _pos, 1.5, ROPELENGTH * 2, False];
  _rope2 = ropeCreate [_helper, [0,0,0], ROPELENGTH - 1.5, ROPELENGTH * 2, False];
  [_helper, [0,0,0], [0,0,-1]] ropeAttachTo _rope1;
  _ropes set [_i, [_rope1, _rope2, _helper]];
};

_vehicle setVariable ["AGM_RopesDeployed", True, True];
_vehicle setVariable ["AGM_Ropes", _ropes, True];
_vehicle setVariable ["AGM_RopesOccupied", _occupied, True];
