/*
 * Author: KoffeinFlummi
 *
 * Start dragging the given unit.
 *
 * Argument:
 * 0: Unit to do the dragging (Object)
 * 1: Unit to be dragged (Object)
 * 2: Type of transportation
 *    - "drag"
 *    - "carry"
 *
 * Return value:
 * none
 */

_this spawn {
  _unit = _this select 0;
  _target = _this select 1;
  _type = _this select 2;

  _target setVariable ["AGM_isTreatable", False, True];
  _unit setVariable ["AGM_canTreat", False, False];

  // Everything but the rifle animation is fucked
  if (primaryWeapon _unit == "") then {
    _unit addWeapon "AGM_FakePrimaryWeapon";
  };
  _unit selectWeapon (primaryWeapon _unit);

  if (_type == "drag") then {
    _target setDir (getDir _unit + 180) % 360;
    _target setPos ((getPos _unit) vectorAdd ((vectorDir _unit) vectorMultiply 1.5));
    [_unit, "AcinPknlMstpSrasWrflDnon", 1, True] call AGM_Core_fnc_doAnimation;
    [_target, "AinjPpneMrunSnonWnonDb_grab", 2, True] call AGM_Core_fnc_doAnimation;
    sleep 1.8;
  } else {
    _target setDir (getDir _unit + 180) % 360;
    _target setPos ((getPos _unit) vectorAdd (vectorDir _unit));
    [_unit, "AcinPknlMstpSnonWnonDnon_AcinPercMrunSnonWnonDnon", 2, True] call AGM_Core_fnc_doAnimation;
    [_target, "AinjPfalMstpSnonWrflDnon_carried_Up", 2, True] call AGM_Core_fnc_doAnimation;
    sleep 15;
  };

  // unit woke up while picking him up, abandon ship
  if !(_target getVariable "AGM_isUnconscious") exitWith {
    detach _target;
    _target setVariable ["AGM_isTreatable", True, True];
    _unit setVariable ["AGM_canTreat", True, False];
    _unit removeWeapon "AGM_FakePrimaryWeapon";
    [_unit, "", 2, True] call AGM_Core_fnc_doAnimation;
    _unit removeAction (_unit getVariable "AGM_Medical_Release");
  };

  _unit setVariable ["AGM_Transporting", _target, False];
  _releaseID = _unit addAction [format ["<t color='#FF0000'>%1</t>", localize "STR_AGM_Medical_Release"], "[(_this select 1), ((_this select 1) getVariable 'AGM_Transporting')] call AGM_Medical_fnc_release;", nil, 20, false, true, "", "!isNull (_this getVariable ['AGM_Transporting', objNull])"];
  _unit setVariable ["AGM_Medical_ReleaseID", _releaseID];

  if (_type == "drag") then {
    _target attachTo [_unit, [0, 1.1, 0.092]];
    [_target, "{_this setDir 180;}", _target] call AGM_Core_fnc_execRemoteFnc;
    [_target, "AinjPpneMrunSnonWnonDb_still", 2, True] call AGM_Core_fnc_doAnimation;
  } else {
    _target attachTo [_unit, [0.4, -0.1, -1.25], "LeftShoulder"];
    [_target, "{_this setDir 195;}", _target] call AGM_Core_fnc_execRemoteFnc;
    [_unit, "AcinPercMstpSnonWnonDnon", 2, True] call AGM_Core_fnc_doAnimation;
    [_target, "AinjPfalMstpSnonWnonDf_carried_dead", 2, True] call AGM_Core_fnc_doAnimation;
  };

  // catch weird stuff happening
  // (player getting in vehicle, either person dying etc.)
  waitUntil {sleep 0.5;
    vehicle _unit != _unit or
    isNull (_unit getVariable "AGM_Transporting") or
    !(alive _unit) or
    !(alive _target) or
    (_unit getVariable "AGM_isUnconscious") or
    !(_target getVariable "AGM_isUnconscious")
  };
  // release was properly done, do nothing
  if (isNull (_unit getVariable "AGM_Transporting")) exitWith {};
  // weird shit happened, properly release unit
  [_unit, _unit getVariable "AGM_Transporting"] call AGM_Medical_fnc_release;
};
