/*
Name: AGM_Artillery_fnc_getPosFromMapCords

Author: Pabst Mirror

Description:
  Converts numbers into nicely formated strings.
  Uses dumb, brute force.
  CBA has CBA_fnc_mapGridToPos, but it throws errors on some islands

Parameters:
  0: STRING - Grid Cords (needs to match the world's grid cords length) Usualy Numbers, but can be anything on some islands

Returns:
  ARRAY - Position (height always 0)

Example:
  ["030050"] call AGM_Artillery_fnc_getPosFromMapCords = [3050,5050,0] //stratis
  ["Dc65"] call AGM_Artillery_fnc_getPosFromMapCords = [6500,7300,0] //Sarhani (["DC", "65"] call CBA_fnc_mapGridToPos = error)
*/

private ["_worldMapGridLength", "_inputString", "_inputStringLen", "_yString", "_xString", "_stepX", "_stepY", "_found", "_xPos", "_yPos"];

_worldMapGridLength = count (toArray (mapGridPosition [0,0,0]));
if (_worldMapGridLength == 0) exitWith {
  ["Bad mapGridPosition in %1", worldName] call bis_fnc_error;
  [0,0,0]
};

_inputString = [_this, 0, "", [""]] call bis_fnc_param;
_inputStringLen = count (toArray (_inputString));

if (_inputStringLen != _worldMapGridLength) exitWith {
  ["Map Cords Length Does Not Match World %1", worldName] call bis_fnc_error;
  [0,0,0]
};

_yString = _inputString select [(_worldMapGridLength / 2), (_worldMapGridLength / 2)];
_xString = _inputString select [0, (_worldMapGridLength / 2)];

_stepX = getNumber (configfile >> "cfgworlds" >> worldName >> "grid" >> "Zoom1" >> "stepX");
_stepY = getNumber (configfile >> "cfgworlds" >> worldName >> "grid" >> "Zoom1" >> "stepY");
if ((_stepX == 0) || (_stepY == 0)) exitWith {
  ["Bad step in %1", worldName] call bis_fnc_error;
  [0,0,0]
};

_found = false;
_xPos = _stepX / 2;
while {!_found} do {
  if (((mapGridPosition [_xPos, 0]) select [0, (_worldMapGridLength / 2)]) == _xString) then {
    _found = true;
  } else {
    _xPos = _xPos + abs (_stepX);
  };
};
_found = false;
_yPos = _stepY / 2;
while {!_found} do {
  if (((mapGridPosition [0, _yPos]) select [(_worldMapGridLength / 2), (_worldMapGridLength / 2)]) == _yString) then {
    _found = true;
  } else {
    _yPos = _yPos + abs (_stepY);
  };
};

[_xPos, _yPos, 0]
