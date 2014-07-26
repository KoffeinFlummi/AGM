/*
 * Author: commy2
 *
 * Disables key input. ESC can still be pressed to open the menu.
 *
 * Argument:
 * 0: True to disable key inputs, false to re-enable them (Bool)
 * 1: Allow Zeus and Team Switch? (Optional; default: no)	!OBSOLETE
 *
 * Return value:
 * Nothing
 */

private ["_state", "_allowTeamSwitch"];

_state = _this select 0;
_allowTeamSwitch = _this select 1;

if (_state) then {
	createDialog "AGM_Core_DisableMouse_Dialog";

	disableSerialization;
	_dlg = uiNamespace getVariable "AGM_Core_dlgDisableMouse";

	if (isNil "AGM_Core_disableUserInput_KeydownEH") then {
		AGM_Core_disableUserInput_KeydownEH = {
			_key = _this select 1;

			if (_key == 1) then {
				createDialog (["RscDisplayInterrupt", "RscDisplayMPInterrupt"] select isMultiplayer);
			};

			if (inputAction "TeamSwitch" > 0 && {teamSwitchEnabled}) then {teamSwitch};
			if (inputAction "CuratorInterface" > 0 && {player in allCurators}) then {openCuratorInterface};

			_this select 1 > 0
		};
	};

	_dlg displayAddEventHandler ["KeyDown", AGM_Core_disableUserInput_KeydownEH];
	_dlg displayAddEventHandler ["KeyUp", {true}];

	hintSilent systemChat "[AGM] Debug: User Input disabled";
} else {
	if (!isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])) then {
		0 spawn {
			waitUntil {
				closeDialog 0;
				isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])
			};
			systemChat "[AGM] Debug: User Input enabled";
		};
	};
};
