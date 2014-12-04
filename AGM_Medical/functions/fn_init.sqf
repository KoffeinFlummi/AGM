/*
Author: KoffeinFlummi

Do I really need to explain what this does?!
*/

_unit = _this select 0;

if !(local _unit) exitWith {};

if (_unit == AGM_player) then {
  _unit setVariable ["tf_globalVolume", 1];
  _unit setVariable ["tf_voiceVolume", 1, True];
  _unit setVariable ["tf_unable_to_use_radio", False, True];

  _unit setVariable ["acre_sys_core_isDisabled", False, True];
  _unit setVariable ["acre_sys_core_globalVolume", 1];
};

[_unit, "AGM_Unconscious", false] call AGM_Core_fnc_setCaptivityStatus;
if  (_unit getVariable ["AGM_isDiagnosed", False]) then {_unit setVariable ["AGM_isDiagnosed", False, True]};   // Is the unit diagnosed?
if !(_unit getVariable ["AGM_canTreat", True])     then {_unit setVariable ["AGM_canTreat", True, False]};      // Can unit treat others?
if !(_unit getVariable ["AGM_isTreatable", True])  then {_unit setVariable ["AGM_isTreatable", True, True]};    // Can unit be treated/diagnosed?

_unit setVariable ["AGM_Blood", 1, True];             // Amount of blood in the body.
_unit setVariable ["AGM_isBleeding", False, True];    // Is the unit losing blood? (Rate is determined by damage.)
_unit setVariable ["AGM_Painkiller", 1, True];        // How much painkillers the guy is on. (smaller = more)
_unit setVariable ["AGM_Pain", 0, True];              // Amount of pain the unit is in.

if (_unit getVariable ["AGM_isUnconscious", False]) then {_unit setVariable ["AGM_isUnconscious", False, True]}; // figure it out
if (_unit getVariable ["AGM_Unconscious", False])   then {_unit setVariable ["AGM_Unconscious", False, True]};   // deprecated since v0.95
if (_unit getVariable ["AGM_isOverdosing", False])  then {_unit setVariable ["AGM_isOverdosing", False]};
if (!isNull (_unit getVariable ["AGM_Transporting", objNull])) then {_unit setVariable ["AGM_Transporting", objNull]};

_unit spawn {
  while {alive _this} do {
    [_this] call AGM_Medical_fnc_itemCheck;
    sleep 1;
  };
};
