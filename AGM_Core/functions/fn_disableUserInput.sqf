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
	disableSerialization;

	if (!isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])) exitWith {};

	closeDialog 0;
	createDialog "AGM_Core_DisableMouse_Dialog";

	_dlg = uiNamespace getVariable "AGM_Core_dlgDisableMouse";

	if (isNil "AGM_Core_disableUserInput_KeydownEH") then {
		AGM_Core_disableUserInput_KeydownEH = {
			_key = _this select 1;

			if (_key == 1 && {alive player}) then {
				createDialog (["RscDisplayInterrupt", "RscDisplayMPInterrupt"] select isMultiplayer);

				disableSerialization;
				_dlg = finddisplay 49;
				for "_index" from 100 to 2000 do {
					(_dlg displayCtrl _index) ctrlEnable false;
				};

				_ctrlRespawn = _dlg displayctrl 104;
				_ctrlRespawn ctrlSetEventHandler ["buttonClick", "closeDialog 0; forceRespawn player; [false] call AGM_Core_fnc_disableUserInput;"];
				_ctrlRespawn ctrlEnable true;
				_ctrlRespawn ctrlSetText "RESPAWN";
			};

			if (_key in actionKeys "TeamSwitch" && {teamSwitchEnabled}) then {_acc = accTime; teamSwitch; setAccTime _acc};
			if (_key in actionKeys "CuratorInterface" && {player in allCurators}) then {openCuratorInterface};

			_key > 0
		};
	};

	_dlg displayAddEventHandler ["KeyDown", AGM_Core_disableUserInput_KeydownEH];
	_dlg displayAddEventHandler ["KeyUp", {true}];

	// diag_log text "[AGM] Debug: User Input disabled";
} else {
	if (!isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])) then {
		0 spawn {
			waitUntil {
				closeDialog 0;
				isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])
			};

			uiNamespace setVariable ["AGM_Core_dlgDisableMouse", displayNull];
			diag_log text "[AGM] Debug: User Input enabled";
		};
	};
};
