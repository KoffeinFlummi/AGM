// by commy2 and CAA-Picard

if (!hasInterface) exitWith {};

AGM_Interaction_isOpeningDoor = false;
AGM_Dancing = false;
AGM_Interaction_ShowNamesTime = -10;

addMissionEventHandler ["Draw3D", {
  if !(profileNamespace getVariable ["AGM_showPlayerNames", true]) exitWith {};

  if (profileNamespace getVariable ["AGM_showPlayerNamesOnlyOnCursor", true]) then {

    _target = cursorTarget;
    _target = if (_target in allUnitsUAV) then {objNull} else {effectiveCommander _target};

    if (!isNull _target && {side group _target == playerSide} && {_target != player}) then {
      _distance = player distance _target;
      _alpha = ((1 - 0.2 * (_distance - AGM_Interaction_PlayerNamesViewDistance)) min 1) * AGM_Interaction_PlayerNamesMaxAlpha;
      if (AGM_Interaction_ShownNamesOnKeypress > 0) then {
        _alpha = _alpha min (1 - (time - AGM_Interaction_ShowNamesTime - 1));
      };
      [_target, _alpha, _distance * 0.026] call AGM_Interaction_fnc_drawNameTagIcon;
    };

  } else {

    _pos = positionCameraToWorld [0, 0, 0];
    _targets = _pos nearObjects ["Man", AGM_Interaction_PlayerNamesViewDistance + 5];

    if (!surfaceIsWater _pos) then {
      _pos = ATLtoASL _pos;
    };
    _pos2 = positionCameraToWorld [0, 0, 1];
    if (!surfaceIsWater _pos2) then {
      _pos2 = ATLtoASL _pos2;
    };
    _vecy = _pos2 vectorDiff _pos;

    {
      _target = if (_x in allUnitsUAV) then {objNull} else {effectiveCommander _x};

      if (!isNull _target && {side group _target == playerSide} && {_target != player}) then {
        _relPos = (visiblePositionASL _target) vectorDiff _pos;
        _distance = vectorMagnitude _relPos;
        _projDist = _relPos vectorDistance (_vecy vectorMultiply (_relPos vectorDotProduct _vecy));

        _alpha = ((1 - 0.2 * (_distance - AGM_Interaction_PlayerNamesViewDistance)) min (1 - 0.15 * (_projDist * 5 - _distance - 3)) min 1) * AGM_Interaction_PlayerNamesMaxAlpha;
        if (AGM_Interaction_ShownNamesOnKeypress > 0) then {
          _alpha = _alpha min (1 - (time - AGM_Interaction_ShowNamesTime - 1));
        };
        [_target, _alpha, _distance * 0.026] call AGM_Interaction_fnc_drawNameTagIcon;
      };
    } forEach _targets;

  };
}];
