/*
 * Author: KoffeinFlummi
 *
 * Administers the unit epinephrine.
 * 
 * Argument:
 * 0: Unit to be treated (Object)
 * 
 * Return value:
 * none
 */

#define EPITIMEMEDIC 5
#define EPITIMENONMEDIC 10

if ((_this select 0) getVariable "BWA3_Epinephrine") exitWith {};

_this spawn {
  _unit = _this select 0;

  // DETERMINE IF UNIT IS MEDIC
  _epitime = 0;
  if ([_unit] call BWA3_Medical_fnc_isMedic) then {
    _epitime = EPITIMEMEDIC;
  } else {
    _epitime = EPITIMENONMEDIC;
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation

  // START COUNTDOWN RSC (this is just a placeholder)
  _i = _epitime;
  while {_i > 0} do {
    hintSilent format ["Injecting Epinephrine:\n%1", _i];
    _i = _i - 1;
    sleep 1;
  };
  hintSilent "Injecting Epinephrine:\nDone.";
  sleep 1;
  hintSilent "";
  // STOP COUNTDOWN RSC

  _unit setVariable ["BWA3_Epinephrine", true];
};