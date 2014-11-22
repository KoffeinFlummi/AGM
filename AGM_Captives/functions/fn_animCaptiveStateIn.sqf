// by commy2

private ["_unit", "_allCaptives"];

_unit = _this select 0;

_allCaptives = missionNamespace getVariable ["AGM_allCaptives", []];
if (_unit in _allCaptives) exitWith {};

if (_allCaptives pushBack _unit == 0) then {
  private "_fnc_doAnim";

  _fnc_doAnim = {
    {
      if !([_x] call AGM_Core_fnc_inTransitionAnim || {_x getVariable ["AGM_isUnconscious", false]}) then {
        _x playMove "AmovPercMstpSnonWnonDnon_Ease";
      };
    } forEach AGM_allCaptives;
  };

  ["AGM_ForceAnimationForCaptives", "onEachFrame", _fnc_doAnim] call BIS_fnc_addStackedEventHandler;
};

AGM_allCaptives = _allCaptives;
