/*
Name: AGM_Attach_fnc_vehicleGetAttachPoint

Author: Pabst Mirror

Description:
  Gets a attach point for a vehicle (in model space cords).  Will check the config for AGM_AttachPoint_X first.
  Otherwise it finds a solution using lineIntersectsWith.

Parameters:
  0: OBJECT - vehicle
  1: STRING - placement point name (right, left, back)

Returns:
  Nothing

Example:
called from module
*/
private ["_vehicle", "_attachPointLocation", "_config", "_returnAttachPoint", "_bbox", "_driverPos", "_posX", "_minHeight", "_maxHeight", "_curHeight", "_position0", "_position1", "_posZ", "_minBack", "_maxBack", "_curBack"];

_vehicle = _this select 0;
_attachPointLocation = _this select 1;

_config = configFile >> "CfgVehicles" >> (typeOf _vehicle);

_returnAttachPoint = getArray (_config >> format ["AGM_AttachPoint_%1", _attachPointLocation]);
if ((count _returnAttachPoint) == 0) then {
  //Find the location on the model using intersections
  _bbox = boundingBoxReal _vehicle;
  if (_attachPointLocation in ["left", "right"]) then {
    _driverPos = _vehicle selectionPosition (getText (_config >> "memoryPointsGetInDriver"));
    _posX = if (_attachPointLocation == "right") then {
      0.425 * (abs (_driverPos select 0))
    } else {
      -0.425 * (abs (_driverPos select 0))
    };
    _minHeight = (_bbox select 0) select 2;
    _maxHeight = (_bbox select 1) select 2;
    _curHeight = _maxHeight;
    _position0 = _vehicle modeltoWorld [_posX, (_driverPos select 1), (_maxHeight + 0.05)];

    while {_curHeight > _minHeight} do {
      _position1 = _vehicle modelToWorld [_posX, (_driverPos select 1), (_curHeight)];
      if (_vehicle in lineIntersectsWith [(ATLToASL _position0), (ATLToASL _position1), player]) exitWith {};
      _curHeight = _curHeight - 0.01;
    };
    _curHeight = _curHeight + 0.025;  
	//Raise up a little so it's not sunk into the hull
    //sometimes it's too much, but better then hidden

    _returnAttachPoint = [_posX, (_driverPos select 1), _curHeight];
  };

  if (_attachPointLocation == "rear") then {
    _posZ = ((_bbox select 0) select 2) + 0.75;
    _minBack = (_bbox select 0) select 1;
    _maxBack = (_bbox select 1) select 1;
    _curBack = _minBack;
    _position0 = _vehicle modeltoWorld [0, (_minBack - 0.05), _posZ];
    while {_curBack < _maxBack} do {
      _position1 = _vehicle modelToWorld [0, _curBack, _posZ];
      if (_vehicle in lineIntersectsWith [(ATLToASL _position0), (ATLToASL _position1), player]) exitWith {};
      _curBack = _curBack + 0.01;
    };
    _curBack = _curBack - 0.1;
    _returnAttachPoint = [0, _curBack, _posZ];
  };
};

_returnAttachPoint
