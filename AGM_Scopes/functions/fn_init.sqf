/*
 * Author: KoffeinFlummi
 *
 * Initializes vars needed for scope adjustment and watches for scope changes.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 */

AGM_Scopes_Optics = [] call AGM_Scopes_fnc_getOptics;
AGM_Scopes_Adjustment = [[0,0], [0,0], [0,0]]; // primary, secondary, handgun

AGM_Scopes_inventoryCheck = {
  private ["_new"];

  _new = [] call AGM_Scopes_fnc_getOptics;
  for "_i" from 0 to 2 do {
    if (_new select _i != AGM_Scopes_Optics select _i) then {
      AGM_Scopes_Adjustment set [_i, [0,0]];
    };
  };
  AGM_Scopes_Optics = _new;
};

0 spawn {
  waitUntil {sleep 5; !(AGM_Scopes_Optics isEqualTo ([] call AGM_Scopes_fnc_getOptics))};
  [] call AGM_Scopes_inventoryCheck;
};

(_this select 0) addEventHandler ["Put", {
  [] call AGM_Scopes_inventoryCheck;
}];
(_this select 0) addEventHandler ["Take", {
  [] call AGM_Scopes_inventoryCheck;
}];

0 spawn {
  while {True} do {
    waitUntil {[0,0] call AGM_Scopes_fnc_canAdjustScope and cameraView != "GUNNER"};
    _layer = ["AGM_Scope_Zeroing"] call BIS_fnc_rscLayer;
    _layer cutRsc ["AGM_Scope_Zeroing", "PLAIN", 0, false];
    _weapon = currentWeapon player;
    _optics = [] call AGM_Scopes_fnc_getOptics;
    waitUntil {!([0,0] call AGM_Scopes_fnc_canAdjustScope) or cameraView == "GUNNER" or !(_optics isEqualTo ([] call AGM_Scopes_fnc_getOptics)) or (currentWeapon player != _weapon)};
    _layer cutText ["", "PLAIN", 0];
  };
};
