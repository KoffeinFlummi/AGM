/*
 * Author: KoffeinFlummi
 *
 * Attaches a backpack ventrally.
 *
 * Arguments:
 * 0: Backpack (Object)
 *
 * Return Value:
 * None
 */

_backpack = _this select 0;
_unit = player;

_backpack attachTo [_unit, [-0.2,0.75,-0.1], "pelvis"];
_backpack setVectorDirAndUp [[0,0,-1], [0,1,0]];

_unit setVariable ["BWA3_Backpack", _backpack, true];

[_unit, _backpack] spawn {
  _unit = _this select 0;
  _backpack = _this select 1;

  while {true} do {
    if (isNull (_unit getVariable ["BWA3_Backpack", objNull])) exitWith {};
    if !(alive _unit) exitWith {[_unit] call BWA3_Interaction_fnc_putBackpack;};
    if (_unit getVariable ["BWA3_Unconscious", false]) exitWith {[_unit] call BWA3_Interaction_fnc_putBackpack;};
    sleep 0.1;
  };
};