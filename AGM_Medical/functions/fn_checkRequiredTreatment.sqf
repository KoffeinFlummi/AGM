private ["_patient"];

_patient = _this;

if (damage _patient > 0) exitWith {
  "bandage"
};

if (_patient getVariable ["AGM_Pain", 0] > 0) exitWith {
  "morphine"
};

if (_patient getVariable ["AGM_isUnconscious", false]) exitWith {
  "epipen"
};

if (_patient getVariable ["AGM_Blood", 1] < 1) exitWith {
  "bloodbag"
};

false