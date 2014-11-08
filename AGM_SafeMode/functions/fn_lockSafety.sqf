// by commy2

private ["_unit", "_weapon", "_safedWeapons"];

_unit = _this select 0;
_weapon = _this select 1;

_safedWeapons = _unit getVariable ["AGM_SafeMode_safedWeapons", []];

if (_weapon in _safedWeapons) exitWith {
	_this call AGM_SafeMode_fnc_unlockSafety;
};

_safedWeapons pushBack _weapon;

_unit setVariable ["AGM_SafeMode_safedWeapons", _safedWeapons];

if (_unit getVariable ["AGM_SafeWeaponActionIDs", [-1, -1]] select 0 == -1) then {
  private ["_condition", "_statement", "_actionIDs"];

  _condition = {
    _this select 1 == vehicle (_this select 1)
    && {currentMuzzle (_this select 1) in ((_this select 1) getVariable ["AGM_SafeMode_safedWeapons", []])}
  };

  _statement = {
    [_this select 1, currentWeapon (_this select 1)] call AGM_SafeMode_fnc_unlockSafety;
  };

  _actionIDs = [
    [_unit, "DefaultAction", _condition, {}] call AGM_Core_fnc_addActionEventHandler,
    [_unit, "nextWeapon", {true}, _statement] call AGM_Core_fnc_addActionEventHandler
  ];

  _unit setVariable ["AGM_SafeWeaponActionIDs", _actionIDs];
};

_unit selectWeapon _weapon;

playSound "AGM_Sound_Click";
