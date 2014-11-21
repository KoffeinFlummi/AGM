// by commy2

// request marker data for JIP
if (isMultiplayer && {!isServer}) then {
  _logic = createGroup sideLogic createUnit ["Logic", [0,0,0], [], 0, "NONE"];
  [_logic, "AGM_Markers_fnc_sendMarkersJIP", 1] call AGM_Core_fnc_execRemoteFnc;
};


//constantly wait for RscDisplayChannel to be open, and then buffer it's text in a variable
missionNamespace setVariable ["AGM_Markers_currentChatChannel", ""];
[] spawn {
  while {true} do {
    if (!isNull (findDisplay 63)) then {
      missionNamespace setVariable ["AGM_Markers_currentChatChannel", ctrlText ((findDisplay 63) displayCtrl 101)];
    };
    uiSleep 1;  //needed for while loops in pre-breifing, can't sleep or waitUntil
  };
};
