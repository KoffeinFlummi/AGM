// by commy2

private ["_unit", "_allCaptives"];

_unit = _this select 0;

_allCaptives = missionNamespace getVariable ["AGM_allCaptives", []];
if !(_unit in _allCaptives) exitWith {};

_allCaptives deleteAt (_allCaptives find _unit);

if (count _allCaptives == 0) then {
  ["AGM_ForceAnimationForCaptives", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
};

AGM_allCaptives = _allCaptives;

_unit playMoveNow "AmovPercMstpSnonWnonDnon_EaseOut";
