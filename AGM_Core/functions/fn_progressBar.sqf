/*
 * Author: commy2
 *
 * Draw progress bar and execute given function if succesful.
 * 
 * Argument:
 * 0: Time of the action (Number)
 * 1: Arguments of the callback function (Array)
 * 2: Callback function name (String)
 * 3: Title of the loading bar (String)
 * 
 * Return value:
 * Nothing
 */

createDialog "AGM_Core_ProgressBar_Dialog";

_this spawn {
	_time = _this select 0;
	_arguments = _this select 1;
	_function = call compile (_this select 2);
	_title = _this select 3;

	disableSerialization;
	_ctrlProgressBar = uiNamespace getVariable "AGM_Core_ctrlProgressBar";
	_ctrlProgressBarTitle = uiNamespace getVariable "AGM_Core_ctrlProgressBarTitle";

	_ctrlProgressBar ctrlSetPosition [
		safezoneX + 0.1 * safezoneW,
		safezoneY + 0.2 * safezoneH,
		0.8 * safezoneW,
		0.01 * safezoneH
	];
	_ctrlProgressBar ctrlCommit _time;

	_ctrlProgressBarTitle ctrlSetText _title;

	_time = time + _time;
	waitUntil {
		!dialog || {!alive player} || {time > _time}
	};

	closeDialog 0;

	if (time > _time) then {
		_arguments call _function;
	};
};
