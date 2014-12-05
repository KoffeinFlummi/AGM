// by commy2, handle AI

0 spawn {
  while {true} do {
    sleep 10;

    _allGroups = [allGroups, {local _this}] call AGM_Core_fnc_filter;

    _fnc_needsMedic = {
      damage _this > 0
      || {_this getVariable ["AGM_Pain", 0] > 0}
      || {_this getVariable ["AGM_isUnconscious", false]}
      || {_this getVariable ["AGM_Blood", 1] < 1}
    };

    {
      {
        if (_x call _fnc_needsMedic) then {
          [_x] call AGM_Medical_fnc_aiInitTask;
        };
      } forEach units _x
    } forEach _allGroups;
  };
};
