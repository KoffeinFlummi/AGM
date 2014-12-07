/*
  Name: AGM_Attach_fnc_Place_Approve

  Author(s):
    Pabst Mirror (based on Explosive attach by Garth de Wet (LH))

  Description:
    Approves placement of the lightObject, releases the placement object for it to settle in a location

  Parameters:
    Nothing

  Returns:
    Nothing

  Example:
    call AGM_Attach_fnc_Place_Approve;
*/
if (AGM_Attach_pfeh_running) then {
  ["AGM_Attach_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
  AGM_Attach_pfeh_running = false;
};

_setupObject = AGM_Attach_SetupObject;
_setupClassname = typeOf _setupObject;
_itemClassname = AGM_Attach_SetupPlacmentItem;
_placementText = AGM_Attach_SetupPlacmentText;
_attachToVehicle = AGM_Attach_SetupAttachVehicle;

AGM_Attach_SetupPlacmentItem = "";
AGM_Attach_SetupPlacmentText = "";
AGM_Attach_SetupObject = objNull;
AGM_Attach_SetupAttachVehicle = objNull;
AGM_Attach_placer forceWalk false;
AGM_Attach_placer = objNull;

_player = AGM_player;
[_player, "DefaultAction", _player getVariable ["AGM_Attach_Place", -1]] call AGM_Core_fnc_removeActionEventHandler;
[_player, "MenuBack", _player getVariable ["AGM_Attach_Cancel", -1]] call AGM_Core_fnc_removeActionEventHandler;
call AGM_Interaction_fnc_hideMouseHint;

//A player can release the attachObject with it floating in mid-air.
//This will use lineIntersectsWith to scan towards the center of the vehicle to find a collision
//ArmA's collision detection is of couse terrible and often misses collisions (difference between what we see and collision LOD)
//So it does multiple scans at slighly different angles
//This is VERY computationaly intensive, but doesn't happen that often.

_position0 = getPosAtl _setupObject;
_closeInRatio = 1;
_offset = _attachToVehicle worldToModel _position0;
_keepGoingCloser = true;
while {_keepGoingCloser} do {
  _closeInRatio = _closeInRatio - 0.004;
  if (_closeInRatio <= 0) exitWith {};
  {
    _pos0temp = _position0 vectorAdd _x;
    {
      _position1 = [(_offset select 0) * _closeInRatio, (_offset select 1) * _closeInRatio, (_offset select 2)];
      _position1 = _attachToVehicle modelToWorld _position1;
      _position1 = _position1 vectorAdd _x;
      //Uncomment to see the lazor show, and see how the scanning works:
      // drawLine3D [_pos0temp, _position1, [1,0,0,1]];
      if (_attachToVehicle in lineIntersectsWith [(ATLToASL _pos0temp), (ATLToASL _position1), player, _setupObject]) exitWith {_keepGoingCloser = false};
    } forEach [[0,0,0], [0,0,0.075], [0,0,-0.075], [0,0.075,0], [0,-0.075,0], [0.075,0,0], [-.075,0,0]];
  } forEach [[0,0,0], [0,0,0.075], [0,0,-0.075]];
};
//Move it out slightly, for visability sake (better to look a little funny than be embedded//sunk in the hull)
_closeInRatio = (_closeInRatio + 0.006) min 1;

//Delete Local Placement Object
deleteVehicle _setupObject;

//Create New 'real' Object
_attachedObject = _setupClassname createVehicle (getPos _player);
_attachedObject attachTo [_attachToVehicle, [(_offset select 0) * _closeInRatio, (_offset select 1) * _closeInRatio, (_offset select 2)]];

//Remove Item from inventory
_player removeItem _itemClassname;

//Add Object to AGM_AttachedObjects and AGM_AttachedItemNames
_currentObjects = _attachToVehicle getVariable ["AGM_AttachedObjects", []];
_currentObjects pushBack _attachedObject;
_attachToVehicle setVariable ["AGM_AttachedObjects", _currentObjects, true];
_currentItemNames = _attachToVehicle getVariable ["AGM_AttachedItemNames", []];
_currentItemNames pushBack _itemClassname;
_attachToVehicle setVariable ["AGM_AttachedItemNames", _currentItemNames, true];

[_placementText] call AGM_Core_fnc_displayTextStructured;
