// by commy2

terminate (missionNamespace getVariable ["AGM_Medical_AITask", scriptNull]);

AGM_Medical_AITask = _this spawn {
  _medic = _this select 0;
  _patient = _this select 1;

  // goto position patient
  waitUntil {
    _medic doMove getPosASL _patient;

    sleep 1;
    _medic distanceSqr _patient < 5
  };

  // halt
  doStop _medic;

  // treat everything
  while {true} do {
    _items = items _medic;

    _isDone = switch (true) do {
      case (damage _patient > 0 && {"AGM_Bandage" in _items}): {
        [_medic, _patient, "bandage", "All"] call AGM_Medical_fnc_treat;
        systemChat "give bandage";
        false
      };

      case (_patient getVariable ["AGM_Pain", 0] > 0 && {"AGM_Morphine" in _items}): {
        [_medic, _patient, "morphine"] call AGM_Medical_fnc_treat;
        systemChat "give morphine";
        false
      };

      case (_patient getVariable ["AGM_isUnconscious", false] && {"AGM_Epipen" in _items}): {
        [_medic, _patient, "epipen"] call AGM_Medical_fnc_treat;
        systemChat "give epipen";
        false
      };

      case (_patient getVariable ["AGM_Blood", 1] < 1 && {"AGM_Bloodbag" in _items}): {
        [_medic, _patient, "bloodbag"] call AGM_Medical_fnc_treat;
        systemChat "give bloodbag";
        false
      };
    };

    sleep 5;

    if (_isDone) exitWith {};
  };

  // continue walking freely
  _medic doMove getPosASL _medic;
};
