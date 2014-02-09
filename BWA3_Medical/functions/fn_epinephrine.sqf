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
 *
 * !!! NEEDS TO BE CALLED USING spawn !!!
 */

#define EPITIMEMEDIC 5
#define EPITIMENONMEDIC 10

private ["_unit", "_epitime", "_i"];

_unit = _this select 0;

if (_unit getVariable "BWA3_Epinephrine") exitWith {};

// DETERMINE IF UNIT IS MEDIC
if (getNumber (configfile >> "CfgVehicles" >> typeOf player >> "attendant") == 1) then {
  _epitime = EPITIMEMEDIC;
} else {
  _epitime = EPITIMENONMEDIC;
};

player switchMove "Acts_TreatingWounded02"; // healing animation

// START COUNTDOWN RSC

//sleep _epitime;
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

player switchMove "AidlPknlMstpSlowWrflDnon_G01_combat";