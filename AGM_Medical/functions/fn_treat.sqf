/*
 * By: KoffeinFlummi
 *
 * Starts the treatment of the unit.
 *
 * Arguments:
 * 0: Unit that is diagnosed (Object)
 * 1: Type of treatment:
 *    - "diagnose"
 *    - "bandage"
 *    - "morphine"
 *    - "epipen"
 *    - "bloodbag"
 * 2+: Additional parameters
 *
 * Return value:
 * none
 */

private ["_unit", "_type", "_player", "_triggers", "_inTrigger", "_item", "_animation", "_time", "_string"];

_unit = _this select 0;
_type = _this select 1;
_player = AGM_player;

// check if unit is medic and if that's even necessary
if (_type in ["epipen", "bloodbag"] and
    !(([_player] call AGM_Core_fnc_isMedic) or
    (_player getVariable ["AGM_Medical_AllowNonMedics", AGM_Medical_AllowNonMedics > 0]))) exitWith {
  [localize "STR_AGM_Medical_NotTrained"] call AGM_Core_fnc_displayTextStructured;
};

// check MEDEVAC conditions
_triggers = missionNamespace getVariable ["AGM_Medical_MEDEVACTriggers", []];
_inTrigger = False;
{
  if ([_x, _unit] call BIS_fnc_inTrigger) then {
    _inTrigger = True;
  };
} forEach _triggers;
if (_type == "epipen" and (_player getVariable ["AGM_Medical_RequireMEDEVAC", AGM_Medical_RequireMEDEVAC > 0]) and !_inTrigger) exitWith {
  [localize "STR_AGM_Medical_NotInMEDEVAC"] call AGM_Core_fnc_displayTextStructured;
};

// morphine warning
if (_type == "morphine" and
    _unit != AGM_player and
    [_unit] call AGM_Core_fnc_isPlayer) then {
  [[], "systemChat localize 'STR_AGM_Medical_GivingYouMorphine';", _unit] call AGM_Core_fnc_execRemoteFnc;
};

// remove item if necessary
_item = switch (_type) do {
  case "bandage"  : {"AGM_Bandage"};
  case "morphine" : {"AGM_Morphine"};
  case "epipen"   : {"AGM_Epipen"};
  case "bloodbag" : {"AGM_Bloodbag"};
  default           {""};
};
if (_item != "" and {!([_unit, _item] call AGM_Medical_fnc_takeItem)}) exitWith {};

// code to be executed if action is aborted
AGM_Medical_treatmentAbort = {
  if (vehicle AGM_player == AGM_player) then {
    [AGM_player, "AmovPknlMstpSrasWrflDnon", 1] call AGM_Core_fnc_doAnimation;
  };
  AGM_player setVariable ["AGM_canTreat", True, False];
};

player setVariable ["AGM_canTreat", False, False];

// self-diagnosis is instant
if (
    (_unit == AGM_player) and
    (_type == "diagnose")
  ) exitWith {
  _this call AGM_Medical_fnc_treatmentCallback;
};

// play appropriate animation
_animation = switch (_type) do {
  case "diagnose" : {"AinvPknlMstpSnonWnonDnon_medic3"};
  case "bandage"  : {"AinvPknlMstpSnonWnonDnon_medic4"};
  case "morphine" : {"AinvPknlMstpSnonWnonDnon_medic1"};
  case "epipen"   : {"AinvPknlMstpSnonWnonDnon_medic1"};
  case "bloodbag" : {"AinvPknlMstpSnonWnonDnon_medic1"};
  default           {""};
};
if (stance _player == "PRONE") then {
  _animation = switch (currentWeapon _unit) do {
    case (primaryWeapon _unit): {"AinvPpneMstpSlayWrflDnon_medic"};
    case (handgunWeapon _unit): {"AinvPpneMstpSlayWpstDnon_medic"};
    default                     {"AinvPpneMstpSlayWnonDnon_medic"};
  };
};
if (_player == _unit) then {
  _animation = switch (currentWeapon _unit) do {
    case (primaryWeapon _unit): {
      ["AinvPknlMstpSlayWrflDnon_medic", "AinvPpneMstpSlayWrflDnon_medic"] select (stance _unit == "PRONE")
    };
    case (handgunWeapon _unit): {
      ["AinvPknlMstpSlayWpstDnon_medic", "AinvPpneMstpSlayWpstDnon_medic"] select (stance _unit == "PRONE")
    };
    default {
      ["AinvPknlMstpSlayWnonDnon_medic", "AinvPpneMstpSlayWnonDnon_medic"] select (stance _unit == "PRONE")
    };
  };
};

if (vehicle _player == _player) then {
  [_player, _animation, 1] call AGM_Core_fnc_doAnimation;
};

// get time required for action to be completed
_time = switch (_type) do {
  case "diagnose" : {5};
  case "bandage"  : {8};
  case "morphine" : {5};
  case "epipen"   : {5};
  case "bloodbag" : {20};
  default           {10};
};
if !([_player] call AGM_Core_fnc_isMedic) then {
  _time = _time * (_player getVariable ["AGM_Medical_CoefNonMedic", AGM_Medical_CoefNonMedic]);
};
// increase treatment time when treating while prone or in (non-medical) vehicle
// (it's hard to bandage yourself in a tank you know)
if (stance _player == "PRONE" or (vehicle _player != _player and !([_vehicle] call AGM_Core_fnc_isMedic))) then {
  _time = _time * 1.2;
};

// select appropriate label for progress bar
_string = switch (_type) do {
  case "diagnose" : {localize "STR_AGM_Medical_Diagnosing"};
  case "bandage"  : {
    _selection = _this select 2;
    if (_selection == "All") then {
      localize "STR_AGM_Medical_Bandaging"
    } else {
      localize format ["STR_AGM_Medical_Bandaging_%1", _selection]
    };
  };
  case "morphine" : {localize "STR_AGM_Medical_Injecting_Morphine"};
  case "epipen"   : {localize "STR_AGM_Medical_Injecting_Epinephrine"};
  case "bloodbag" : {localize "STR_AGM_Medical_Transfusing_Blood"};
  default           {"Tell Flummi he's a dumbass ..."};
};

[
  _time,
  _this,
  "AGM_Medical_fnc_treatmentCallback",
  _string,
  "AGM_Medical_treatmentAbort"
] call AGM_Core_fnc_progressBar;
[_unit, True] call AGM_Core_fnc_closeDialogIfTargetMoves;
