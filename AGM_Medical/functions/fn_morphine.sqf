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

  // DETERMINE IF PLAYER IS MEDIC
  _morphinetime = 0;
  if ([player] call AGM_Medical_fnc_isMedic) then {
    _morphinetime = MORPHINETIMEMEDIC;
  } else {
    _morphinetime = MORPHINETIMENONMEDIC;
  };

  player setVariable ["AGM_CanTreat", false, false];
  _morphinetime spawn {
    sleep _this;
    player setVariable ["AGM_CanTreat", true, false];
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation

  AGM_Medical_morphineCallback = {
    _unit = _this select 0;
    _painkillerOld = _this select 1;
  
    if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "AGM_Unconscious")) exitWith {};

    player removeItem "AGM_Morphine";

    if (_painkillerOld < 0.1) exitWith {
      if (_unit == player) then {
        AGM_UnconsciousCC = ppEffectCreate ["ColorCorrections", 4208];
        AGM_UnconsciousCC ppEffectEnable true;
        AGM_UnconsciousCC ppEffectForceInNVG true;
        AGM_UnconsciousCC ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[0.4,0.4,0,0,0,0.1,0.3]];
        AGM_UnconsciousCC ppEffectCommit 0.15;

        AGM_UnconsciousRB = ppEffectCreate ["RadialBlur", 4207];
        AGM_UnconsciousRB ppEffectEnable true;
        AGM_UnconsciousRB ppEffectForceInNVG true;
        AGM_UnconsciousRB ppEffectAdjust [0.4, 0.4, 0, 0];
        AGM_UnconsciousRB ppEffectCommit 0.5;
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

    if (_painkillerOld == 1) then {
      0 = _unit spawn {
        while {_this getVariable "AGM_Painkiller" < 1} do {
          _this setVariable ["AGM_Painkiller", ((_this getVariable "AGM_Painkiller") + MORPHINEREDUCTION) min 1];
          sleep 10;
        };
      };
    };

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

  AGM_Medical_morphineAbort = {
    player playMoveNow "AmovPknlMstpSrasWrflDnon";
  };

  [_morphinetime, (_this + [_painkillerOld]), "AGM_Medical_morphineCallback", localize "STR_AGM_Medical_Injecting_Morphine", "AGM_Medical_morphineAbort"] call AGM_Core_fnc_progressBar;

};