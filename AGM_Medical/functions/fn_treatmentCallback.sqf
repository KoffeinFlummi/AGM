/*
 * Author: KoffeinFlummi
 *
 * Code to be executed upon the successfull treatment.
 *
 * Arguments:
 * 0: Unit that does the treatment (Object)
 * 1: Unit to be treated (Object)
 * 2: Type of treatment:
 *    - "diagnose"
 *    - "bandage"
 *    - "morphine"
 *    - "epipen"
 *    - "bloodbag"
 * 3+: additional parameters
 *
 * Return Value:
 * None
 */

#define BANDAGEHEAL 0.8
#define MORPHINEHEAL 0.4
#define BLOODBAGHEAL 0.7

private ["_unit", "_target", "_type"];

_unit = _this select 0;
_target = _this select 1;
_type = _this select 2;

if ((_target != _unit or _type != "diagnose") and (vehicle _unit == _unit)) then {
  [_unit, "", 1] call AGM_Core_fnc_doAnimation;
};
_unit setVariable ["AGM_canTreat", True, False];

switch (_type) do {
  case "diagnose" : {
    // this is way too messy to all do here.
    [_target] call AGM_Medical_fnc_diagnose;
  };

  case "bandage" : {
    private ["_selection", "_damage"];

    _selection = _this select 3;
    if (_selection == "All") then {
      _target setDamage ((damage _target - BANDAGEHEAL) max 0);
    } else {
      _damage = ((_target getHitPointDamage _selection) - BANDAGEHEAL) max 0;
      [_target, _selection, _damage] call AGM_Medical_fnc_setHitPointDamage;

      [
        _target,
        (_target getHitPointDamage "HitLeftLeg") + (_target getHitPointDamage "HitRightLeg"),
        (_target getHitPointDamage "HitLeftArm") + (_target getHitPointDamage "HitRightArm"),
        True
      ] call AGM_Medical_fnc_checkDamage;
    };
  };

  case "morphine" : {
    private ["_painkillerOld", "_painkiller"];

    // reduce pain, pain sensitivity
    _painkillerOld = _target getVariable ["AGM_Painkiller", 0];

    // overdose if necessary (unit was already full of painkillers)
    if (_painkillerOld > 0.95 and _target getVariable ["AGM_Medical_EnableOverdosing", AGM_Medical_EnableOverdosing] > 0) then {
      [_target] call AGM_Medical_fnc_overdose;
    };

    _painkiller = (_painkillerOld + MORPHINEHEAL) min 1;
    _pain = ((_target getVariable ["AGM_Pain", 0]) - MORPHINEHEAL) max 0;
    _target setVariable ["AGM_Painkiller", _painkiller, True];
    _target setVariable ["AGM_Pain", _pain, True];


    // Painkiller Reduction
    [_target] call AGM_Medical_fnc_simulateHealth;
  };

  case "epipen" : {
    _target setVariable ["AGM_Epinephrine", 1, True];
    [_target] call AGM_Medical_fnc_wakeUp;
  };

  case "bloodbag" : {
    private ["_blood"];

    _blood = ((_target getVariable ["AGM_Blood", 1]) + BLOODBAGHEAL) min 1;
    _target setVariable ["AGM_Blood", _blood, True];
  };

  default {};
};

// reopen menu if desired
if (profileNamespace getVariable ["AGM_keepMedicalMenuOpen", False] and _unit == AGM_player) then {
  if (_target == _unit) then {
    [3, _target, "AGM_Medical"] call AGM_Interaction_fnc_showMenu;
  } else {
    [2, _target, "AGM_Medical"] call AGM_Interaction_fnc_showMenu;
  };
};
