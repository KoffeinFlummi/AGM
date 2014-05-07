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
#define MORPHINEREDUCTION 0.015

_this spawn {
  _unit = _this select 0;
  _painkillerOld = _unit getVariable "AGM_Painkiller";

  player setVariable ["AGM_CanTreat", false, false];

  // DETERMINE IF PLAYER IS MEDIC
  _morphinetime = 0;
  if ([player] call AGM_Medical_fnc_isMedic) then {
    _morphinetime = MORPHINETIMEMEDIC;
  } else {
    _morphinetime = MORPHINETIMENONMEDIC;
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation
  player removeItem "AGM_Morphine";

  // START COUNTDOWN RSC (this is just a placeholder)
  _i = _morphinetime;
  while {_i > 0} do {
    hintSilent format ["Injecting Morphine:\n%1", _i];
    _i = _i - 1;
    sleep 1;
    if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "AGM_Unconscious")) exitWith {};
  };
  hintSilent "Injecting Morphine:\nDone.";
  sleep 1;
  hintSilent "";
  // STOP COUNTDOWN RSC

  player setVariable ["AGM_CanTreat", true, false];

  if (_painkillerOld < 0.1) exitWith {
    if (_unit == player) then {
      [0, "BLACK", 0.15, 1] spawn BIS_fnc_FadeEffect;
    };
    [-2, {
      _this switchMove "Unconscious";
      _this playAction "GestureSpasm4";
    }, _unit] call CBA_fnc_globalExecute;
    _unit spawn {
      sleep 20;
      [_this, "HitHead", 1] call AGM_Medical_fnc_setHitPointDamage;
    };
  };

  _painkiller = ((_unit getVariable "AGM_Painkiller") - MORPHINEHEAL) max 0;
  _unit setVariable ["AGM_Painkiller", _painkiller, true];

  _pain = ((_unit getVariable "AGM_Pain") - MORPHINEHEAL) max 0;
  _unit setVariable ["AGM_Pain", _pain, true];

  if (_painkillerOld < 1) then {
    0 = _unit spawn {
      while {_this getVariable "AGM_Painkiller" < 1} do {
        _this setVariable ["AGM_Painkiller", ((_this getVariable "AGM_Painkiller") + MORPHINEREDUCTION) min 1];
        sleep 10;
      };
    };
  };

  /*
  if (getNumber(configFile >> "AGM_Realism_Settings" >> "reopenInteractionMenu") == 1) then {
    if (_unit == player) then {
      "AGM_Medical" call AGM_Interaction_fnc_openMenuSelf;
    } else {
      "AGM_Medical" call AGM_Interaction_fnc_openMenu;
    }
  };
  */
};