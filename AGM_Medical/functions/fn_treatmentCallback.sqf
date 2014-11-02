/*
 * Author: KoffeinFlummi
 *
 * Code to be executed upon the successfull treatment.
 *
 * Arguments:
 * 0: Unit to be treated
 * 1: Type of treatment:
 *    - "diagnose"
 *    - "bandage"
 *    - "morphine"
 *    - "epipen"
 *    - "bloodbag"
 * 2+: additional parameters
 *
 * Return Value:
 * None
 */

#define BANDAGEHEAL 0.8
#define MORPHINEHEAL 0.4
#define BLOODBAGHEAL 0.7

private ["_unit", "_type", "_player"];

_unit = _this select 0;
_type = _this select 1;

_player = call AGM_Core_fnc_player;
if ((_unit != _player or _type != "diagnose") and (vehicle _player == _player)) then {
  [_player, "AmovPknlMstpSrasWrflDnon", 1] call AGM_Core_fnc_doAnimation;
};
_player setVariable ["AGM_canTreat", True, False];

switch (_type) do {
  case "diagnose" : {
    // this is way too messy to all do here.
    [_unit] call AGM_Medical_fnc_diagnose;
  };

  case "bandage" : {
    private ["_selection", "_damage"];

    _selection = _this select 2;
    if (_selection == "All") then {
      _unit setDamage ((damage _unit - BANDAGEHEAL) max 0);
    } else {
      _damage = ((_unit getHitPointDamage _selection) - BANDAGEHEAL) max 0;
      [_unit, _selection, _damage] call AGM_Medical_fnc_setHitPointDamage;

      [
        _unit,
        (_unit getHitPointDamage "HitLeftLeg") + (_unit getHitPointDamage "HitRightLeg"),
        (_unit getHitPointDamage "HitLeftArm") + (_unit getHitPointDamage "HitRightArm"),
        True
      ] call AGM_Medical_fnc_checkDamage;
    };
  };

  case "morphine" : {
    private ["_painkillerOld", "_painkiller"];

    _painkillerOld = _unit getVariable "AGM_Painkiller";

    // reduce pain, pain sensitivity
    _painkiller = (_painkillerOld - MORPHINEHEAL) max 0;
    _pain = ((_unit getVariable "AGM_Pain") - MORPHINEHEAL) max 0;
    _unit setVariable ["AGM_Painkiller", _painkiller, True];
    _unit setVariable ["AGM_Pain", _pain, True];

    // overdose if necessary (unit was already full of painkillers)
    if (_painkillerOld < 0.05 and _unit getVariable ["AGM_Medical_EnableOverdosing", AGM_Medical_EnableOverdosing] > 0) then {
      [_unit] call AGM_Medical_fnc_overdose;
    };

    // Painkiller Reduction
    if (_painkillerOld == 1) then {
      _unit spawn {
        while {_this getVariable "AGM_Painkiller" < 1} do {
          sleep 1;
          _painkiller = ((_this getVariable ["AGM_Painkiller", 1]) + 0.0015) min 1;
          _this setVariable ["AGM_Painkiller", _painkiller, True];
        };
      };
    };
  };

  case "epipen" : {
    [_unit] call AGM_Medical_fnc_wakeUp; // short and sweet
  };

  case "bloodbag" : {
    private ["_blood"];

    _blood = ((_unit getVariable "AGM_Blood") + BLOODBAGHEAL) min 1;
    _unit setVariable ["AGM_Blood", _blood, True];
  };

  default {};
};

// reopen menu if desired
if (profileNamespace getVariable ["AGM_keepMedicalMenuOpen", False]) then {
  if (_unit == _player) then {
    [1, _unit, "AGM_Medical"] call AGM_Interaction_fnc_showMenu;
  } else {
    [0, _unit, "AGM_Medical"] call AGM_Interaction_fnc_showMenu;
  };
};
