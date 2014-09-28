/*
 * Author: KoffeinFlummi
 *
 * Start carrying the given unit.
 *
 * Argument:
 * 0: Unit to be carried (Object)
 *
 * Return value:
 * none
 */

_this spawn {
  _unit = _this select 0;

  _unit setVariable ["AGM_Treatable", false, true];
  player setVariable ["AGM_CanTreat", false, false];

  // Everything but the rifle animation is fucked
  if (primaryWeapon player == "") then {
    player addWeapon "AGM_FakePrimaryWeapon";
  };
  player selectWeapon (primaryWeapon player);

  [player, "AcinPercMstpSnonWnonDnon", 1] call AGM_Core_fnc_doAnimation;

  sleep 7;

  // Patient woke up while picking up, abandon ship.
  if !(_unit getVariable "AGM_Unconscious") exitWith {
    _unit setVariable ["AGM_Treatable", true, true];
    player setVariable ["AGM_CanTreat", true, false];
    player removeWeapon "AGM_FakePrimaryWeapon";
    [player, "", 2] call AGM_Core_fnc_doAnimation;
    player removeAction (player getVariable "AGM_Medical_ReleaseID");
  };

  player setVariable ["AGM_Carrying", _unit, false];
  _releaseID = player addAction [format ["<t color='#FF0000'>%1</t>", localize "STR_AGM_Medical_Release"], "[(player getVariable 'AGM_Carrying')] call AGM_Medical_fnc_release;", nil, 20, false, true, "", "!isNull (player getVariable ['AGM_Carrying', objNull])"];
  player setVariable ["AGM_Medical_ReleaseID", _releaseID];

  _unit attachTo [player, [0.1, -0.1, -1.25], "LeftShoulder"];
  [_unit, "AinjPfalMstpSnonWnonDf_carried_dead", 2] call AGM_Core_fnc_doAnimation;
  [-2, {
    _this setDir 15;
    _this setPos (getPos _this);
  }, _unit] call CBA_fnc_globalExecute;

  waitUntil {sleep 0.5; vehicle player != player or isNull (player getVariable "AGM_Carrying") or !(alive player) or !(alive _unit) or (player getVariable "AGM_Unconscious") or !(_unit getVariable "AGM_Unconscious")};
  if (isNull (player getVariable "AGM_Carrying")) exitWith {};
  [player getVariable "AGM_Carrying"] call AGM_Medical_fnc_release;
};
