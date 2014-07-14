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

#define BLOODBAGTIMEMEDIC 20
#define BLOODBAGTIMENONMEDIC 30
#define BLOODBAGHEAL 0.7

// DETERMINE IF UNIT IS MEDIC
if !(([player] call AGM_Medical_fnc_isMedic) or {AGM_Medical_AllowNonMedics}) exitWith {
  [localize "STR_AGM_Medical_NotTrained"] call AGM_Core_fnc_displayTextStructured;
};

_this spawn {
  _unit = _this select 0;

  _bloodbagtime = 0;
  if (([player] call AGM_Medical_fnc_isMedic) or {!AGM_Medical_PunishNonMedics}) then {
    _bloodbagtime = BLOODBAGTIMEMEDIC;
  } else {
    _bloodbagtime = BLOODBAGTIMENONMEDIC;
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation
  player setVariable ["AGM_CanTreat", false, false];

  if !([_unit, "AGM_Bloodbag"] call AGM_Medical_fnc_takeItem) exitWith {};

  AGM_Medical_bloodbagCallback = {
    _unit = _this select 0;

    if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "AGM_Unconscious")) exitWith {};

    _blood = ((_unit getVariable "AGM_Blood") + BLOODBAGHEAL) min 1;
    _unit setVariable ["AGM_Blood", _blood, true];

    player setVariable ["AGM_CanTreat", true, false];

    if (profileNamespace getVariable ["AGM_keepMedicalMenuOpen", false]) then {
      if (_unit == player) then {
        "AGM_Medical" call AGM_Interaction_fnc_openMenuSelf;
      } else {
        "AGM_Medical" call AGM_Interaction_fnc_openMenu;
      };
    };
  };

  AGM_Medical_bloodbagAbort = {
    player playMoveNow "AmovPknlMstpSrasWrflDnon";
    player setVariable ["AGM_CanTreat", true, false];
  };

  [_bloodbagtime, _this, "AGM_Medical_bloodbagCallback", localize "STR_AGM_Medical_Transfusing_Blood", "AGM_Medical_bloodbagAbort"] call AGM_Core_fnc_progressBar;
};
