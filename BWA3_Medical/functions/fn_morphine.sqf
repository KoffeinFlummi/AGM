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
 *
 * !!! NEEDS TO BE CALLED USING spawn !!!
 */

#define MORPHINETIMEMEDIC 5
#define MORPHINETIMENONMEDIC 10
#define MORPHINEHEAL 0.4

private ["_unit", "_morphinetime", "_painkiller", "_i"];

_unit = _this select 0;

// DETERMINE IF UNIT IS MEDIC
if (getNumber (configfile >> "CfgVehicles" >> typeOf player >> "attendant") == 1) then {
  _morphinetime = MORPHINETIMEMEDIC;
} else {
  _morphinetime = MORPHINETIMENONMEDIC;
};

player switchMove "Acts_TreatingWounded02"; // healing animation

// START COUNTDOWN RSC

//sleep _morphinetime;
_i = _morphinetime;
while {_i > 0} do {
  hintSilent format ["Injecting Morphine:\n%1", _i];
  _i = _i - 1;
  sleep 1;
};
hintSilent "Injecting Morphine:\nDone.";
sleep 1;
hintSilent "";

// STOP COUNTDOWN RSC

_painkiller = (_unit getVariable "BWA3_Painkiller" + MORPHINEHEAL) min 1;
_unit setVariable ["BWA3_Painkiller", _painkiller];

player switchMove "AidlPknlMstpSlowWrflDnon_G01_combat";