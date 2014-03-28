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

player removeItem "BWA3_Morphine";

_this spawn {
  _unit = _this select 0;
  _painkillerOld = _unit getVariable "BWA3_Painkiller";

  if (_painkillerOld == 0) exitWith {
    if (_unit == player) then {
      [0, "BLACK", 0.15, 1] call BIS_fnc_FadeEffect;
    };
    [-2, {
      _this switchMove "Unconscious";
      _this playAction "GestureSpasm4";
    }, _unit] call CBA_fnc_globalExecute;
    _unit spawn {
      sleep 20;
      [_this, "HitHead", 1] call BWA3_Medical_fnc_setHitPointDamage;
    };
  };

  // DETERMINE IF PLAYER IS MEDIC
  _morphinetime = 0;
  if ([player] call BWA3_Medical_fnc_isMedic) then {
    _morphinetime = MORPHINETIMEMEDIC;
  } else {
    _morphinetime = MORPHINETIMENONMEDIC;
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation

  // START COUNTDOWN RSC (this is just a placeholder)
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

  if (player distance _unit > 4 or vehicle player != player or damage player >= 1) exitWith {};

  _painkiller = ((_unit getVariable "BWA3_Painkiller") - MORPHINEHEAL) max 0;
  _unit setVariable ["BWA3_Painkiller", _painkiller, true];

  _pain = ((_unit getVariable "BWA3_Pain") - MORPHINEHEAL) max 0;
  _unit setVariable ["BWA3_Pain", _pain, true];

  if (_painkillerOld < 1) then {
    0 = _unit spawn {
      while {_this getVariable "BWA3_Painkiller" < 1} do {
        _this setVariable ["BWA3_Painkiller", ((_this getVariable "BWA3_Painkiller") + MORPHINEREDUCTION) min 1];
        sleep 10;
      };
    };
  };
};