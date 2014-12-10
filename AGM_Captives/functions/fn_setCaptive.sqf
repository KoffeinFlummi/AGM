/*
 * Author: Nic547, commy2
 *
 * Makes a civilian unable to move.
 * 
 * Argument:
 * 0: Unit (Object)
 * 1: True to take captive, false to release captive (Object)
 * 
 * Return value:
 * Nothing
 */

private ["_unit", "_state"];

_unit = _this select 0;
_state = _this select 1;

if (!local _unit) exitWith {[[_unit, _state, true], _fnc_scriptName, _unit] call AGM_Core_fnc_execRemoteFnc};

if (_state) then {
  if (_unit getVariable ["AGM_isCaptive", false]) exitWith {};

  _unit setVariable ["AGM_isCaptive", true, true];
  [_unit, "AGM_Handcuffed", true] call AGM_Core_fnc_setCaptivityStatus;
  [_unit] call AGM_Core_fnc_fixLoweredRifleAnimation;
  //[_unit, "AGM_AmovPercMstpScapWnonDnon", 0] call AGM_Core_fnc_doAnimation;

  // fix anim on mission start
  _unit spawn {
    if (_this getVariable ["AGM_isCaptive", false] && {vehicle _this == _this}) then {
      [_this, "AGM_AmovPercMstpScapWnonDnon", 0] spawn AGM_Core_fnc_doAnimation;
    };
  };

  _unit setVariable ["AGM_Captives_CargoIndex", vehicle _unit getCargoIndex _unit, true];

  if (_unit == AGM_player) then {
    showHUD false;
  };
} else {
  if !(_unit getVariable ["AGM_isCaptive", false]) exitWith {};

  _unit setVariable ["AGM_isCaptive", false, true];
  [_unit, "AGM_Handcuffed", false] call AGM_Core_fnc_setCaptivityStatus;
  if (vehicle _unit == _unit) then {
    [_unit, "AGM_AmovPercMstpScapWnonDnon_AmovPercMstpSnonWnonDnon", 2] call AGM_Core_fnc_doAnimation;
  };

  if (_unit getVariable ["AGM_Captives_CargoIndex", -1] != -1) then {
    _unit setVariable ["AGM_Captives_CargoIndex", -1, true];
  };

  if (_unit == AGM_player) then {
    showHUD true;
  };
};
