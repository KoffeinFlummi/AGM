// by commy2

private "_unit";
_unit = _this select 0;

if ([_unit] call AGM_Core_fnc_isPlayer || {_unit getVariable ["AGM_isUnconscious", false]}) then {
  private ["_units", "_medic"];
  _units = units group _unit;
  _units deleteAt (_units find _unit);

  if (count _units == 0) exitWith {};

  _medic = [_units, {[_this] call AGM_Core_fnc_isMedic}] call AGM_Core_fnc_filter select 0;

  if (isNil "_medic") then {_medic = _units select 0};

  [_medic, _unit] spawn {
    sleep 5;
    _this call AGM_Medical_fnc_aiTreat;
  };
} else {
  [_unit, _unit] spawn {
    sleep 5;
    _this call AGM_Medical_fnc_aiTreat;
  };
};
