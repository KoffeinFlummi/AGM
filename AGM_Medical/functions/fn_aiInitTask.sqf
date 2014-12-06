// by commy2

private ["_unit", "_need"];
_unit = _this select 0;
_need = _this select 1;

if ([_unit] call AGM_Core_fnc_isPlayer || {_unit getVariable ["AGM_isUnconscious", false]}) then {
  private ["_units", "_medic"];
  _units = units group _unit;
  _units deleteAt (_units find _unit);

  if (count _units == 0) exitWith {};

  _medic = [_units, {[_this] call AGM_Core_fnc_isMedic}] call AGM_Core_fnc_filter;
  _medic = _medic select floor random count _medic;

  if (isNil "_medic") then {
    _medic = _units select floor random count _units;
  };

  [_medic, _unit, _need] call AGM_Medical_fnc_aiTreat;
} else {
  [_unit, _unit, _need] call AGM_Medical_fnc_aiTreat;
};
