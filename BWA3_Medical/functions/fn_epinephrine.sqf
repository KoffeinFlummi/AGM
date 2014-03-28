/*
 * Author: KoffeinFlummi
 *
 * Administers the unit epinephrine, waking it up.
 * 
 * Argument:
 * 0: Unit to be treated (Object)
 * 
 * Return value:
 * none
 */

#define EPINEPHRINETIME 8

// DETERMINE IF UNIT IS MEDIC
if !([player] call BWA3_Medical_fnc_isMedic) exitWith {
  hintSilent "You are not trained to do that.";
};

player removeItem "BWA3_Epipen";

_this spawn {
  _unit = _this select 0;

  player setVariable ["BWA3_CanTreat", false, false];

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation

  // START COUNTDOWN RSC (this is just a placeholder)
  _i = EPINEPHRINETIME;
  while {_i > 0} do {
    hintSilent format ["Injecting Epinephrine:\n%1", _i];
    _i = _i - 1;
    sleep 1;
  };
  hintSilent "Injecting Epinephrine:\nDone.";
  sleep 1;
  hintSilent "";
  // STOP COUNTDOWN RSC
  
  if (player distance _unit > 4 or vehicle player != player or damage player >= 1) exitWith {};

  [_unit] call BWA3_Medical_fnc_wakeUp;

  player setVariable ["BWA3_CanTreat", true, false];
};