// by commy2

_this spawn {
  _target = _this select 0;
  _ignoreDead = _this select 1;

  if (isNil "_ignoreDead") then {_ignoreDead = false};

  _position = getPosASL _target;

  _unit = vehicle AGM_player;
  waitUntil {
    if (getPosASL _target distanceSqr _position > 1 || {!alive _target && {!_ignoreDead}} || {_unit != vehicle AGM_player}) then {
      closeDialog 0;
      call AGM_Interaction_fnc_hideMenu;
    };
    (isNil "AGM_Interaction_MainButton" && !dialog)
  };
};
