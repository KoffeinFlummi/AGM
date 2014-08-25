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

AGM_Scopes_Optics = [] call AGM_Scopes_fnc_getScopes;
AGM_Scopes_Adjustment = [[0,0], [0,0], [0,0]]; // primary, secondary, handgun

AGM_Scopes_inventoryCheck = {
  private ["_new"];

  _new = [] call AGM_Scopes_fnc_getScopes;
  for "_i" from 0 to 2 do {
    if (_new select _i != AGM_Scopes_Optics select _i) then {
      AGM_Scopes_Adjustment set [_i, [0,0]];
    };
  };
  AGM_Scopes_Optics = _new;
};

0 spawn {
  waitUntil {sleep 5; AGM_Scopes_Optics != [] call AGM_Scopes_fnc_getScopes};
  [] call AGM_Scopes_inventoryCheck;
};

(_this select 0) addEventHandler ["Put", {
  [] call AGM_Scopes_inventoryCheck;
}];
(_this select 0) addEventHandler ["Take", {
  [] call AGM_Scopes_inventoryCheck;
}];
