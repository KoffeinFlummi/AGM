// by commy2

private ["_unit", "_killer"];

_unit = _this select 0;
_killer = _this select 1;

if (_unit != _killer && side group _unit in [side group AGM_player, civilian] && {side group _killer == side group AGM_player}) then {
  systemChat format ["%1 was killed by %2", name _unit, name _killer];
};

[_unit, "FriendlyFire", [_unit, _killer]] call AGM_Core_fnc_callCustomEventHandlers;
