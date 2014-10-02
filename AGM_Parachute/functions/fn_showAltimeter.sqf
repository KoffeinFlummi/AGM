/*
	Name: AGM_Parachute_fnc_showAltimeter
	
	Author: Garth de Wet (LH)
	
	Description:
		Displays the altimeter on screen.
	
	Parameters: 
		0: OBJECT - unit to track for the altimeter
	
	Returns:
		Nothing
	
	Example:
		[player] call AGM_Parachute_fnc_showAltimeter
*/
private ["_unit"];
_unit = _this select 0;
(["AGM_Altimeter"] call BIS_fnc_rscLayer) cutRsc ["AGM_Altimeter", "PLAIN",0,true];
if (isNull (uiNamespace getVariable ["AGM_Altimeter", displayNull])) exitWith {};

AGM_Parachute_AltimeterFnc = [uiNamespace getVariable ["AGM_Altimeter", displayNull], _unit] spawn {
	private ["_height", "_hour", "_minute", "_second", "_decend"];
	_unit = _this select 1;
	_height = floor ((getPosASL _unit) select 2);
	_oldHeight =  _height;
	_decend = 0;
	_hour = floor daytime;
	_minute = floor ((daytime - _hour) * 60);
	disableSerialization;
	private ["_HeightText", "_DecendRate", "_TimeText"];
	_HeightText = (_this select 0) displayCtrl 1100;
	_DecendRate = (_this select 0) displayCtrl 1000;
	_TimeText = (_this select 0) displayCtrl 1001;
	while {true} do {
		_TimeText ctrlSetText (format ["%1:%2",[_hour, 2] call AGM_Core_fnc_numberToDigitsString,[_minute, 2] call AGM_Core_fnc_numberToDigitsString]);
		_HeightText ctrlSetText (format ["%1", _height]);
		_DecendRate ctrlSetText (format ["%1",_decend]);
		sleep 0.2;
		_height = floor ((getPosASL _unit) select 2);
		_decend = _oldHeight - _height;
		_oldHeight = _height;
	};
};