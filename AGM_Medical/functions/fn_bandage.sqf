/*
 * Author: KoffeinFlummi
 *
 * Bandage the given unit.
 * 
 * Argument:
 * 0: Unit to be bandaged (Object)
 * 1: HitPoint to be healed (String; Example: "HitLeftShoulder")
 * 
 * Return value:
 * none
 */

#define BANDAGETIMEMEDIC 4
#define BANDAGETIMENONMEDIC 8
#define BANDAGEHEAL 0.8

#define LEGDAMAGETHRESHOLD1 1
#define LEGDAMAGETHRESHOLD2 2
#define ARMDAMAGETHRESHOLD 2

_this spawn {
  _unit = _this select 0;
  _selection = _this select 1;

  player setVariable ["AGM_CanTreat", false, false];

  // determine if unit is medic
  _healtime = 0;
  if ([player] call AGM_Medical_fnc_isMedic) then {
    _healtime = BANDAGETIMEMEDIC;
  } else {
    _healtime = BANDAGETIMENONMEDIC;
  };

  // animation
  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1";
  player removeItem "AGM_Bandage";

  // countdown
  _i = _healtime;
  while {_i > 0} do {
    hintSilent format ["Bandaging %1:\n%2", _selection, _i];
    _i = _i - 1;
    sleep 1;
    if (player distance _unit > 4 or vehicle player != player or damage player >= 1 or (player getVariable "AGM_Unconscious")) exitWith {};
  };
  hintSilent format ["Bandaging %1:\nDone", _selection];
  sleep 1;
  hintSilent "";

  player setVariable ["AGM_CanTreat", true, false];

  // change damage of body part
  _damage = ((_unit getHitPointDamage _selection) - BANDAGEHEAL) max 0;
  [_unit, _selection, _damage] call AGM_Medical_fnc_setHitPointDamage;

  // since we have to set the damage remotely, it might take some time.
  waitUntil {sleep 0.1; _unit getHitPointDamage _selection == _damage};

  // check if legs are healed
  _legdamage = (_unit getHitPointDamage "HitLeftLeg") + (_unit getHitPointDamage "HitRightLeg");
  if (_legdamage < LEGDAMAGETHRESHOLD1) then {
    [_unit, "HitLegs", 0] call AGM_Medical_fnc_setHitPointDamage;
  };

  // remove extremely small wounds
  _fullyHealed = true;
  {
    if ((_unit getHitPointDamage _x) > 0.02) exitWith {_fullyHealed = false;};
  } forEach ["HitHead","HitBody","HitLeftArm","HitRightArm","HitLeftLeg","HitRightLeg"];
  if (_fullyHealed) then {
    _unit setDamage 0;
  };

  /* temporarily disabled
  if (getNumber(configFile >> "AGM_Realism_Settings" >> "reopenInteractionMenu") == 1) then {
    if (_unit == player) then {
      "AGM_Medical" call AGM_Interaction_fnc_openMenuSelf;
    } else {
      "AGM_Medical" call AGM_Interaction_fnc_openMenu;
    }
  };
  */
};