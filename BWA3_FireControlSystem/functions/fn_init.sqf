BWA3_FCSEnabled = true;
BWA3_FCSTime = -1;
BWA3_FCSPosition = [0,0,0];

0 spawn {
  waituntil {!isNull (findDisplay 46)};
  (findDisplay 46) displayAddEventHandler ["KeyUp", {_this call BWA3_FCS_fnc_keyUp;}];
  (findDisplay 46) displayAddEventHandler ["KeyDown", {_this call BWA3_FCS_fnc_keyDown;}];
};