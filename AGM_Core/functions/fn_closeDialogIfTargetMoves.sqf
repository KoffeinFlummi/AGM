// by commy2

_this spawn {
  _target = _this select 0;
  _ignoreDead = _this select 1;

  if (isNil "_ignoreDead") then {_ignoreDead = false};

  _unit = AGM_player;
  _vehicle = vehicle AGM_player;
  _position = getPosASL _target;

  _fnc_check = [
    {getPosASL _target distanceSqr _position > 1 || {!alive _target && {!_ignoreDead}} || {_vehicle != vehicle AGM_player} || {_unit getVariable ["AGM_isUnconscious", false]}},
    {_target in _vehicle                         || {!alive _target && {!_ignoreDead}} || {_vehicle != vehicle AGM_player} || {_unit getVariable ["AGM_isUnconscious", false]}}
  ] select (_vehicle != AGM_player);

  waitUntil {
    if (call _fnc_check) then {
      closeDialog 0;
      call AGM_Interaction_fnc_hideMenu;
    };
    (isNil "AGM_Interaction_MainButton" && !dialog)
  };
};
