/*
 * Author: KoffeinFlummi
 *
 * Transfuses blood to compensate for heavy blood loss.
 * 
 * Argument:
 * 0: Unit to be treated (Object)
 * 
 * Return value:
 * none
 */

#define BLOODBAGTIME 20
#define BLOODBAGHEAL 0.7

// DETERMINE IF UNIT IS MEDIC
if !([player] call BWA3_Medical_fnc_isMedic) exitWith {
  hintSilent "You are not trained to do that.";
};

player removeItem "BWA3_Bloodbag";

_this spawn {
  _unit = _this select 0;

  player setVariable ["BWA3_CanTreat", false, false];

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation

  // START COUNTDOWN RSC (this is just a placeholder)
  _i = BLOODBAGTIME;
  while {_i > 0} do {
    hintSilent format ["Transfusing Blood:\n%1", _i];
    _i = _i - 1;
    sleep 1;
  };
  hintSilent "Transfusing Blood:\nDone.";
  sleep 1;
  hintSilent "";
  // STOP COUNTDOWN RSC

  if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "BWA3_Unconscious")) exitWith {};

  _blood = ((_unit getVariable "BWA3_Blood") + BLOODBAGHEAL) min 1;
  _unit setVariable ["BWA3_Blood", _blood, true];

  player setVariable ["BWA3_CanTreat", true, false];
};