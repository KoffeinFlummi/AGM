/*
 * Author: KoffeinFlummi
 *
 * Performs CPR on the given unit.
 * 
 * Argument:
 * 0: Unit to be bandage (Object)
 * 
 * Return value:
 * none
 */

#define CPRSUCCESSRATEMEDIC 0.5
#define CPRSUCCESSRATENONMEDIC 0.3
#define CPRTIMEPERCYCLE 15
#define EPIMULTIPLIER 1.5

_this spawn {
  _unit = this select 0;

  // DETERMINE IF UNIT IS MEDIC
  _successrate = 0;
  if ([_unit] call BWA3_Medical_fnc_isMedic) then { // later
    _successrate = CPRSUCCESSRATEMEDIC;
  } else {
    _successrate = CPRSUCCESSRATENONMEDIC;
  };

  if (_unit getVariable "BWA3_Epinephrine") then {
    _successrate = _successrate * EPIMULTIPLIER;
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // animation

  // START COUNTDOWN RSC (this is just a placeholder)
  _i = CPRTIMEPERCYCLE;
  while {_i > 0} do {
    hintSilent format ["CPR:\n%1", _i];
    _i = _i - 1;
    sleep 1;
  };
  hintSilent "CPR:\nDone.";
  sleep 1;
  hintSilent "";
  // STOP COUNTDOWN RSC

  _cpr = (_unit getVariable "BWA3_Dead") - (random _successrate);

  if (_cpr <= 0) then {
    _unit setVariable ["BWA3_Dead", 0];
    [_unit] call BWA3_Medical_fnc_revive;
  } else {
    _unit setVariable ["BWA3_Dead", _cpr];
  };
};