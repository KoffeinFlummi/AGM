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
if !([player] call AGM_Medical_fnc_isMedic) exitWith {
  hintSilent "You are not trained to do that.";
};

_this spawn {
  _unit = _this select 0;

  player setVariable ["AGM_CanTreat", false, false];

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation
  player removeItem "AGM_Bloodbag";

  // START COUNTDOWN RSC (this is just a placeholder)
  _i = BLOODBAGTIME;
  while {_i > 0} do {
    hintSilent format ["Transfusing Blood:\n%1", _i];
    _i = _i - 1;
    sleep 1;
    if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "AGM_Unconscious")) exitWith {};
  };
  hintSilent "Transfusing Blood:\nDone.";
  sleep 1;
  hintSilent "";
  // STOP COUNTDOWN RSC

  player setVariable ["AGM_CanTreat", true, false];

  _blood = ((_unit getVariable "AGM_Blood") + BLOODBAGHEAL) min 1;
  _unit setVariable ["AGM_Blood", _blood, true];

  /* temp disabled
  if (getNumber(configFile >> "AGM_Realism_Settings" >> "reopenInteractionMenu") == 1) then {
    if (_unit == player) then {
      "AGM_Medical" call AGM_Interaction_fnc_openMenuSelf;
    } else {
      "AGM_Medical" call AGM_Interaction_fnc_openMenu;
    }
  };
  */
};