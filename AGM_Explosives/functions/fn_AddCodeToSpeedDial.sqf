/*
	Name: AGM_Explosives_fnc_AddCodeToSpeedDial
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Adds an explosive code to the speed dial of the player.
	
	Parameters:
		0: STRING - Name of speed dial
		1: STRING - Code to add to speed dial
	
	Returns:
		Nothing
	
	Example:
		["My Speed Dial","2131"] call AGM_Explosives_fnc_AddCodeToSpeedDial;
*/
private ["_count", "_name"];
_name = _this select 0;
if ((_this select 1) == "") ExitWith {
	_name call AGM_Explosives_fnc_RemoveCodeFromSpeedDial;
};
_count = 0;
{
	if ((_x select 0) == _name) exitWith {
		_count = -1;
	};
	_count = _count + 1;
} count AGM_Explosives_Phone_SpeedDial;
if (_count != -1) then {
	AGM_Explosives_Phone_SpeedDial set [_count, _this];
};