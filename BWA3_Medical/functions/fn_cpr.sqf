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

private ["_unit", "_successrate", "_cpr", "_i"];

_unit = this select 0;

// DETERMINE IF UNIT IS MEDIC
if (true) then { // later
  _successrate = CPRSUCCESSRATEMEDIC;
} else {
  _successrate = CPRSUCCESSRATENONMEDIC;
};

if (_unit getVariable "BWA3_Epinephrine") then {
  _successrate = _successrate * EPIMULTIPLIER;
}

player switchMove "Acts_TreatingWounded01"; // cpr animation

// START COUNTDOWN RSC

//sleep CPRTIMEPERCYCLE;
_i = CPRTIMEPERCYCLE;
while (_i > 0) then {
  hint format ["%1", _i];
  _i = _i - 1;
  sleep 1;
}

// STOP COUNTDOWN RSC

_cpr = (_unit getVariable "BWA3_Dead") - random _successrate;

if (_cpr <= 0) then {
  _unit setVariable ["BWA3_Dead", 0];
  [_unit] call BWA3_Medical_fnc_revive;
} else {
  _unit setVariable ["BWA3_Dead", _cpr];
}

player switchMove "AidlPknlMstpSlowWrflDnon_G01_combat";