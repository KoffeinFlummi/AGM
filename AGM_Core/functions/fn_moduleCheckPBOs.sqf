/*
 * Author: KoffeinFlummi
 *
 * Initializes the check-PBOs module.
 *
 * Arguments:
 * Whatever the module provides. (I dunno.)
 *
 * Return Value:
 * None
 */

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(isMultiplayer) exitWith {};
if !(isServer) exitWith {};
if !(_activated) exitWith {};

_action = parseNumber (_logic getVariable "Action");
if (_action == 0 and (_logic getVariable "Action") != "0") then {
  diag_log text "AGM: WARNING! Unexpected value in Check PBOs module for Action, replacing with 1 ('Warn Once').";
  _action = 1;
};

_activatedAddons = activatedAddons;
_addons = [];
{
  if ([_x, 0, 4] call AGM_Core_fnc_subString == "AGM_") then {
    _addons = _addons + [_x];
  };
} forEach _activatedAddons;

[-1, {
  _addonsServer = _this select 0;
  _action = _this select 1;

  _activatedAddons = activatedAddons;
  _addons = [];
  {
    if ([_x, 0, 4] call AGM_Core_fnc_subString == "AGM_") then {
      _addons = _addons + [_x];
    };
  } forEach _activatedAddons;

  if (_addons != _addonsServer) then {
    diag_log text "AGM: PBO Mismatch!";
    diag_log text format ["     Client-PBOs: %1", _addons];
    diag_log text format ["     Server-PBOs: %1", _addonsServer];

    systemChat "PBO Mismatch! Please check your rpt-file and restart the game with the proper PBOs.";

    if (_action == 2) exitWith {
      0 spawn {
        while {true} do {
          sleep 1;
          systemChat "PBO Mismatch! Please check your rpt-file and restart the game with the proper PBOs.";
        };
      };
    };

    [-2, {
      if (serverCommandAvailable "#kick") then {
        serverCommand format["#kick %1", _this];
      };
    }, (name player) call AGM_Core_fnc_sanitizeString] call CBA_fnc_globalExecute;
  };

}, [_addons, _action]] call CBA_fnc_globalExecute;

diag_log text "AGM: Check-PBOs Module Initialized.";
