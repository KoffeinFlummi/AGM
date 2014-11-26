// by commy2, Nic547
// Makes a civilian unable to move

private ["_unit", "_state", "_remote"];

_unit = _this select 0;
_state = _this select 1;
_remote = false;
if (count _this > 2) then {
  _remote = _this select 2;
};

if (!_remote && {_state}) then {
  AGM_player removeItem "AGM_CableTie";
};

if (!local _unit) exitWith {[[_unit, _state, true], _fnc_scriptName, _unit] call AGM_Core_fnc_execRemoteFnc};

if (_state) then {
  if (_unit getVariable ["AGM_isCaptive", false]) exitWith {};

  _unit setVariable ["AGM_isCaptive", true, true];
  [_unit, "AGM_Handcuffed", true] call AGM_Core_fnc_setCaptivityStatus;
  [_unit] call AGM_Captives_fnc_animCaptiveStateIn;

  if (_unit == AGM_player) then {//moveto loop
    [false] call AGM_Core_fnc_disableUserInput;
    showHUD false;
  };
} else {
  if !(_unit getVariable ["AGM_isCaptive", false]) exitWith {};

  _unit setVariable ["AGM_isCaptive", false, true];
  [_unit, "AGM_Handcuffed", false] call AGM_Core_fnc_setCaptivityStatus;
  [_unit] call AGM_Captives_fnc_animCaptiveStateOut;

  if (_unit == AGM_player) then {//moveto loop
    [true] call AGM_Core_fnc_disableUserInput;
    showHUD true;
  };
};
