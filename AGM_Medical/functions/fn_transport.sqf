/*
 * Author: KoffeinFlummi
 *
 * Start dragging the given unit.
 *
 * Argument:
 * 0: Unit to be dragged (Object)
 * 1: Type of transportation
 *    - "drag"
 *    - "carry"
 *
 * Return value:
 * none
 */

_this spawn {
  _unit = _this select 0;
  _type = _this select 1;
  _player = call AGM_Core_fnc_player;

  _unit setVariable ["AGM_isTreatable", False, True];
  _player setVariable ["AGM_canTreat", False, False];

  // Everything but the rifle animation is fucked
  if (primaryWeapon _player == "") then {
    _player addWeapon "AGM_FakePrimaryWeapon";
  };
  _player selectWeapon (primaryWeapon player);

  if (_type == "drag") then {
    _unit setDir (getDir _player + 180) % 360;
    _unit setPos ((getPos _player) vectorAdd ((vectorDir player) vectorMultiply 1.5));
    [_player, "AcinPknlMstpSrasWrflDnon", 1, True] call AGM_Core_fnc_doAnimation;
    [_unit, "AinjPpneMrunSnonWnonDb_grab", 2, True] call AGM_Core_fnc_doAnimation;
    sleep 1.8;
  } else {
    _unit setDir (getDir _player + 180) % 360;
    _unit setPos ((getPos _player) vectorAdd (vectorDir player));
    [_player, "AcinPknlMstpSnonWnonDnon_AcinPercMrunSnonWnonDnon", 2, True] call AGM_Core_fnc_doAnimation;
    [_unit, "AinjPfalMstpSnonWrflDnon_carried_Up", 2, True] call AGM_Core_fnc_doAnimation;
    sleep 15;
  };

  // unit woke up while picking him up, abandon ship
  if !(_unit getVariable "AGM_isUnconscious") exitWith {
    detach _unit;
    _unit setVariable ["AGM_isTreatable", True, True];
    _player setVariable ["AGM_canTreat", True, False];
    _player removeWeapon "AGM_FakePrimaryWeapon";
    [_player, "", 2, True] call AGM_Core_fnc_doAnimation;
    _player removeAction (_player getVariable "AGM_Medical_Release");
  };

  _player setVariable ["AGM_Transporting", _unit, False];
  _releaseID = _player addAction [format ["<t color='#FF0000'>%1</t>", localize "STR_AGM_Medical_Release"], "[(player getVariable 'AGM_Transporting')] call AGM_Medical_fnc_release;", nil, 20, false, true, "", "!isNull (player getVariable ['AGM_Transporting', objNull])"];
  _player setVariable ["AGM_Medical_ReleaseID", _releaseID];

  if (_type == "drag") then {
    _unit attachTo [_player, [0, 1.1, 0.092]];
    [_unit, "{_this setDir 180;}", _unit] call AGM_Core_fnc_execRemoteFnc;
    [_unit, "AinjPpneMrunSnonWnonDb_still", 2, True] call AGM_Core_fnc_doAnimation;
  } else {
    _unit attachTo [_player, [0.4, -0.1, -1.25], "LeftShoulder"];
    [_unit, "{_this setDir 195;}", _unit] call AGM_Core_fnc_execRemoteFnc;
    [_player, "AcinPercMstpSnonWnonDnon", 2, True] call AGM_Core_fnc_doAnimation;
    [_unit, "AinjPfalMstpSnonWnonDf_carried_dead", 2, True] call AGM_Core_fnc_doAnimation;
  };

  // catch weird stuff happening
  // (player getting in vehicle, either person dying etc.)
  waitUntil {sleep 0.5;
    vehicle _player != _player or
    isNull (_player getVariable "AGM_Transporting") or
    !(alive _player) or
    !(alive _unit) or
    (_player getVariable "AGM_isUnconscious") or
    !(_unit getVariable "AGM_isUnconscious")
  };
  // release was properly done, do nothing
  if (isNull (_player getVariable "AGM_Transporting")) exitWith {};
  // weird shit happened, properly release unit
  [_player getVariable "AGM_Transporting"] call AGM_Medical_fnc_release;
};
