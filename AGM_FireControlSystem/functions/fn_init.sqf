AGM_FCSEnabled = true;
AGM_FCSTime = -1;
AGM_FCSPosition = [0,0,0];

0 spawn {
  waituntil {!isNull (findDisplay 46)};
  (findDisplay 46) displayAddEventHandler ["KeyUp", {_this call AGM_FCS_fnc_keyUp;}];
  (findDisplay 46) displayAddEventHandler ["KeyDown", {_this call AGM_FCS_fnc_keyDown;}];
};