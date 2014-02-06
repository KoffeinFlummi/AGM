/*
 * Author: KoffeinFlummi
 *
 * Administers the unit morphine.
 * 
 * Argument:
 * 0: Unit to be treated (Object)
 * 
 * Return value:
 * none
 */

#define MORPHINETIMEMEDIC 5
#define MORPHINETIMENONMEDIC 10
#define MORPHINEHEAL 0.4

private ["_unit", "_morphinetime", "_painkiller", "_i"];

_unit = _this select 0;

// DETERMINE IF UNIT IS MEDIC
if (true) then { // later
  _morphinetime = MORPHINETIMEMEDIC;
} else {
  _morphinetime = MORPHINETIMENONMEDIC;
};

player switchMove "placeholder"; // healing animation

// START COUNTDOWN RSC

//sleep _morphinetime;
_i = _morphinetime;
while {_i > 0} do {
  hint format ["%1", _i];
  _i = _i - 1;
  sleep 1;
};

// STOP COUNTDOWN RSC

_painkiller = _unit getVariable "BWA3_Painkiller" + MORPHINEHEAL;
if (_painkiller > 1) then {_painkiller = 1;} // kill the patient?
_unit setVariable ["BWA3_Painkiller", _painkiller];

player switchMove "backtonormal";