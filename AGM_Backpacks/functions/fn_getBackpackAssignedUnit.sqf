// by commy2

private "_backpack";

_backpack = _this select 0;

{
  if (backpackContainer _x == _backpack) exitWith {_x};
  objNull
} forEach (allUnits + allDeadMen);
