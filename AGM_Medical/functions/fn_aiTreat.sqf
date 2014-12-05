// by commy2

if (!isNull ((_this select 0) getVariable ["AGM_Medical_AITask", scriptNull])) exitWith {};
//terminate ((_this select 0) getVariable ["AGM_Medical_AITask", scriptNull]);

private "_scriptHandle";
_scriptHandle = _this spawn {
  _medic = _this select 0;
  _patient = _this select 1;

  while {true} do {
    // wait until ready again
    waitUntil {
      // exit if dead
      if (!alive _medic || {!alive _patient}) exitWith {};

      sleep 0.15;
      _medic getVariable ["AGM_canTreat", true]
    };

    if (_medic distanceSqr _patient > 5) then {
      _doMoveLoop = _this spawn {
        while {true} do {
          (_this select 0) doMove getPosASL (_this select 1);
          sleep 5;
        };
      };

      waitUntil {
        // exit if dead
        if (!alive _medic || {!alive _patient}) exitWith {};

        sleep 0.15;
        getPosASL _medic distanceSqr getPosASL _patient < 4
      };

      terminate _doMoveLoop;
    };

    // exit if dead
    if (!alive _medic || {!alive _patient}) exitWith {};

    // halt
    doStop _medic;

    // treat everything
    _items = items _medic;

    _isDone = switch (true) do {
      case (damage _patient > 0 && {"AGM_Bandage" in _items}): {
        [_medic, _patient, "bandage", "All"] call AGM_Medical_fnc_treat;
        false
      };

      case (_patient getVariable ["AGM_Pain", 0] > 0 && {"AGM_Morphine" in _items}): {
        [_medic, _patient, "morphine"] call AGM_Medical_fnc_treat;
        false
      };

      case (_patient getVariable ["AGM_isUnconscious", false] && {"AGM_Epipen" in _items}): {
        [_medic, _patient, "epipen"] call AGM_Medical_fnc_treat;
        false
      };

      case (_patient getVariable ["AGM_Blood", 1] < 1 && {"AGM_Bloodbag" in _items}): {
        [_medic, _patient, "bloodbag"] call AGM_Medical_fnc_treat;
        false
      };
    };

    if (_isDone) exitWith {};
  };

  // continue walking freely
  _medic doMove getPosASL _medic;
};

(_this select 0) setVariable ["AGM_Medical_AITask", _scriptHandle];
