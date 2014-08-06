// by commy2 and CAA-Picard

if (!hasInterface) exitWith {};

AGM_Interaction_isOpeningDoor = false;
AGM_Dancing = false;

addMissionEventHandler ["Draw3D", {
  if !(profileNamespace getVariable ["AGM_showPlayerNames", true]) exitWith {};

  if (profileNamespace getVariable ["AGM_showPlayerNamesOnlyOnCursor", true]) then {

    _target = effectiveCommander cursorTarget;
    if (!isNull _target && {side group _target == playerSide}) then {
      _distance = player distance _target;
      _alpha = ((1 - 0.2 * (_distance - AGM_Interaction_PlayerNamesViewDistance)) min 1) * AGM_Interaction_PlayerNamesMaxAlpha;
      [_target, _alpha, _distance * 0.026] call AGM_Interaction_fnc_drawNameTagIcon;
    };

  } else {

    _pos = positionCameraToWorld [0, 0, 0];
    _vecy = (positionCameraToWorld [0, 0, 1]) vectorDiff _pos;

    _targets = _pos nearObjects ["Man", AGM_Interaction_PlayerNamesViewDistance + 5];
    {
      _target = effectiveCommander _x;
      if (!isNull _target && {side group _target == playerSide} && _target != player) then {
        _distance = _pos vectorDistance (getPos _target);

        _relPos = (visiblePosition _target) vectorDiff _pos;
        _projDist = _relPos vectorDistance (_vecy vectorMultiply (_relPos vectorDotProduct _vecy));

        _alpha = ((1 - 0.2 * (_distance - AGM_Interaction_PlayerNamesViewDistance)) min (1 - 0.15 * (_projDist * 5 - _distance - 3)) min 1) * AGM_Interaction_PlayerNamesMaxAlpha;

        [_target, _alpha, _distance * 0.026] call AGM_Interaction_fnc_drawNameTagIcon;
      };
    } forEach _targets;

  };
}];
