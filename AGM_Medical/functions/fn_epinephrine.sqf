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
if !([player] call AGM_Medical_fnc_isMedic) exitWith {
  hintSilent "You are not trained to do that.";
};

_this spawn {
  _unit = _this select 0;

  player setVariable ["AGM_CanTreat", false, false];

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation
  player removeItem "AGM_Epipen";

  // START COUNTDOWN RSC (this is just a placeholder)
  _i = EPINEPHRINETIME;
  while {_i > 0} do {
    hintSilent format ["Injecting Epinephrine:\n%1", _i];
    _i = _i - 1;
    sleep 1;
    if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "AGM_Unconscious")) exitWith {};
  };
  hintSilent "Injecting Epinephrine:\nDone.";
  sleep 1;
  hintSilent "";
  // STOP COUNTDOWN RSC

  player setVariable ["AGM_CanTreat", true, false];
  
  [_unit] call AGM_Medical_fnc_wakeUp;

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