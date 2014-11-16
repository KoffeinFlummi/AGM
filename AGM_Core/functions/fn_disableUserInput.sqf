/*
 * Author: commy2
 *
 * Disables key input. ESC can still be pressed to open the menu.
 *
 * Argument:
 * 0: True to disable key inputs, false to re-enable them (Bool)
 * 1: Allow Zeus and Team Switch? (Optional; default: no)  !OBSOLETE
 *
 * Return value:
 * Nothing
 */

private ["_state", "_allowTeamSwitch", "_dlg"];

_state = _this select 0;
_allowTeamSwitch = _this select 1;

if (_state) then {
  disableSerialization;

  if (!isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])) exitWith {};

  // end TFAR and ACRE2 radio transmissions
  0 spawn AGM_Core_fnc_endRadioTransmission;

  // Close map
  if (visibleMap) then {openMap false};

  closeDialog 0;
  createDialog "AGM_Core_DisableMouse_Dialog";

  _dlg = uiNamespace getVariable "AGM_Core_dlgDisableMouse";

  _dlg displayAddEventHandler ["KeyDown", {
    _key = _this select 1;

    if (_key == 1 && {alive player}) then {
      createDialog (["RscDisplayInterrupt", "RscDisplayMPInterrupt"] select isMultiplayer);

      disableSerialization;
      _dlg = finddisplay 49;
      _dlg displayAddEventHandler ["KeyDown", {
        _key = _this select 1;
        !(_key == 1)
      }];

      for "_index" from 100 to 2000 do {
        (_dlg displayCtrl _index) ctrlEnable false;
      };

      _ctrl = _dlg displayctrl 103;
      _ctrl ctrlSetEventHandler ["buttonClick", "while {!isNull (uiNamespace getVariable ['AGM_Core_dlgDisableMouse', displayNull])} do {closeDialog 0}; failMission 'LOSER'; [false] call AGM_Core_fnc_disableUserInput;"];
      _ctrl ctrlEnable true;
      _ctrl ctrlSetText "ABORT";
      _ctrl ctrlSetTooltip "Abort.";

      _ctrl = _dlg displayctrl 104;
      _ctrl ctrlSetEventHandler ["buttonClick", "closeDialog 0; player setDamage 1; [false] call AGM_Core_fnc_disableUserInput;"];
      _ctrl ctrlEnable (call {_config = missionConfigFile >> "respawnButton"; !isNumber _config || {getNumber _config == 1}});
      _ctrl ctrlSetText "RESPAWN";
      _ctrl ctrlSetTooltip "Respawn.";
    };

    if (_key in actionKeys "TeamSwitch" && {teamSwitchEnabled}) then {_acc = accTime; teamSwitch; setAccTime _acc};
    if (_key in actionKeys "CuratorInterface" && {player in allCurators}) then {openCuratorInterface};

    if (serverCommandAvailable "#missions" || {player getVariable ["AGM_Unconscious", false] && {missionNamespace getVariable ["AGM_Medical_AllowChatWhileUnconscious", 0] > 0}})  then {
      if (!(_key in (actionKeys "DefaultAction" + actionKeys "Throw")) && {_key in (actionKeys "Chat" + actionKeys "PrevChannel" + actionKeys "NextChannel")}) then {
        _key = 0;
      };
    };

    _key > 0
  }];
  _dlg displayAddEventHandler ["KeyUp", {true}];

  //  diag_log text "[AGM] Debug: User Input disabled";
} else {
  while {!isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])} do {closeDialog 0};
};
