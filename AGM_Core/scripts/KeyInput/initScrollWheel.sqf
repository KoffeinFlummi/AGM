// by commy2

AGM_Core_ScrollWheelFrame = diag_frameno;

AGM_Core_onScrollWheel = {
  _scroll = _this select 1;

  if (AGM_Core_ScrollWheelFrame == diag_frameno) exitWith {};
  AGM_Core_ScrollWheelFrame = diag_frameno;

  {
    [_scroll] call _x;
  } count ((missionNamespace getVariable ["AGM_EventHandler_ScrollWheel", [-1, [], []]]) select 2);
};
