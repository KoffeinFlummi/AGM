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

#define EPINEPHRINETIMEMEDIC 8
#define EPINEPHRINETIMENONMEDIC 14

// DETERMINE IF UNIT IS MEDIC
if !(([player] call AGM_Medical_fnc_isMedic) or (!(isNil "AGM_Medical_AllowNonMedics") and {AGM_Medical_AllowNonMedics})) exitWith {
  [localize "STR_AGM_Medical_NotTrained"] call AGM_Core_fnc_displayTextStructured;
};

_this spawn {
  _unit = _this select 0;

  _epinephrinetime = 0;
  if (([player] call AGM_Medical_fnc_isMedic) or {!(isNil "AGM_Medical_PunishNonMedics") and {!AGM_Medical_PunishNonMedics}}) then {
    _epinephrinetime = EPINEPHRINETIMEMEDIC;
  } else {
    _epinephrinetime = EPINEPHRINETIMENONMEDIC;
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation
  player setVariable ["AGM_CanTreat", false, false];

  AGM_Medical_epinephrineCallback = {
    _unit = _this select 0;

    if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "AGM_Unconscious")) exitWith {};

    player removeItem "AGM_Epipen";

    [_unit] call AGM_Medical_fnc_wakeUp;

    if (["AGM_Medical", "keepMedicalMenuOpen"] call AGM_Core_fnc_getOption) then {
      "AGM_Medical" call AGM_Interaction_fnc_openMenu;
    };

    player setVariable ["AGM_CanTreat", true, false];
  };

  AGM_Medical_epinephrineAbort = {
    player playMoveNow "AmovPknlMstpSrasWrflDnon";
    player setVariable ["AGM_CanTreat", true, false];
  };

  [_epinephrinetime, _this, "AGM_Medical_epinephrineCallback", localize "STR_AGM_Medical_Injecting_Epinephrine", "AGM_Medical_epinephrineAbort"] call AGM_Core_fnc_progressBar;

};
