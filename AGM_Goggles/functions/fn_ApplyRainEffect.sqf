/*
	Name: AGM_Goggles_fnc_ApplyRainEffect
	
	Author: Garth de Wet (LH)
	
	Description:
	Sets screen tint for glasses.
	Sets screen overlay for glasses. (broken/fixed)
	Sets dirt/rain overlay for glasses.
	
	Parameters: 
	0: ARRAY
		0: BOOL - Whether to set the rain effect or not
		1: NUMBER - The rain drop texture to use.
	
	Returns:
	Nothing
	
	Example:
	AGM_Goggles_Effects set [2, [true, 4, time]];
	[true, 4] call AGM_Goggles_fnc_ApplyRainEffect;
*/
#include "\AGM_Goggles\script.sqf"
if !(_this select 0) exitWith{
	call AGM_Goggles_fnc_removeRainEffect;
	false
};
AGM_Goggles_Test = {
	disableSerialization;
	_display = _this select 0;
	_ctrls = [];
	_dupCtrls = [];
	for "_i" from 0 to 3 do {
		private "_ctrl";
		_ctrl = (_display displayCtrl (10670 + _i));
		_ctrls pushBack [_ctrl,ctrlPosition _ctrl];
		
		_ctrl = (_display displayCtrl (10680 + _i));
		_dupCtrls pushBack [_ctrl,ctrlPosition _ctrl];
	};
	while {GETRAINT(RAMOUNT) > 0} do {
		_waitTime = (4/GETRAINT(RAMOUNT)) * 10;
		for "_i" from 0 to 3 do {
			private "_ctrl";
			_ctrl = (_ctrls select _i);
			_pos = +(_ctrl select 1);
			_pos set [1, safeZoneH];
			(_ctrl select 0) ctrlSetPosition _pos;
			(_ctrl select 0) ctrlCommit _waitTime;
			
			_ctrl = (_dupCtrls select _i);
			_pos = +(_ctrl select 1);
			_pos set [1, safeZoneY];
			(_ctrl select 0) ctrlSetPosition _pos;
			(_ctrl select 0) ctrlCommit _waitTime;
		};
		sleep (_waitTime);
		for "_i" from 0 to 3 do {
			private "_ctrl";
			_ctrl = (_ctrls select _i);
			_pos = (_ctrl select 1);
			(_ctrl select 0) ctrlSetPosition _pos;
			(_ctrl select 0) ctrlCommit 0;
			
			_ctrl = (_dupCtrls select _i);
			_pos = (_ctrl select 1);
			(_ctrl select 0) ctrlSetPosition _pos;
			(_ctrl select 0) ctrlCommit 0;
		};
		sleep 0.1;
	};
	for "_i" from 0 to 3 do {
		private "_ctrl";
		_ctrl = (_ctrls select _i);
		(_ctrl select 0) ctrlSetPosition (_ctrl select 1);
		(_ctrl select 0) ctrlCommit 0;
		
		_ctrl = (_dupCtrls select _i);
		(_ctrl select 0) ctrlSetPosition (_ctrl select 1);
		(_ctrl select 0) ctrlCommit 0;		
	};
};
if (cameraOn == player) then {
	if (isNull(uiNamespace getVariable ["AGM_Goggles_Rain", displayNull])) then {
		101 cutRsc["RscAGM_RainEffects", "PLAIN",0, false];
		AGM_Goggles_RainHandler = [uiNamespace getVariable ["AGM_Goggles_Rain", displayNull]] spawn AGM_Goggles_Test;
	};
	_limit = (_this select 1) - 1;
	disableSerialization;
	_display = (uiNamespace getVariable ["AGM_Goggles_Rain", displayNull]);
	for "_i" from 0 to 3 do {
		(_display displayCtrl (10670 + _i)) ctrlShow (_i <= _limit);
		(_display displayCtrl (10680 + _i)) ctrlShow (_i <= _limit);
	};
};