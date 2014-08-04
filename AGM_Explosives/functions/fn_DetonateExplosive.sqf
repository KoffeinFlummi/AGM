/*
	Name: AGM_Explosives_fnc_DetonateExplosive
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Detonates a remote Explosive.
	
	Parameters:
		0: OBJECT - Unit detonating explosive
		1: ARRAY - Explosive
			0: OBJECT - Explosive
			1: NUMBER - Fuse Time
			2: NUMBER - Max range
		2: BOOLEAN - Ignore Range
		3: BOOLEAN - Ignore Jammer
	
	Returns:
		Nothing
	
	Example:
		// Clacker
		[player, [Explosive, 1, 75], false, false] call AGM_Explosives_fnc_DetonateExplosive;
*/
private ["_item","_result", "_ignoreRange", "_ignoreJammer", "_unit"];
_unit = (_this select 0);
_item = (_this select 1);
_ignoreRange = (_this select 2);
_ignoreJammer = true;//(_this select 3); // disabled while jammers aren't in place.
_result = true;
if (!_ignoreRange) then {
	if ((_unit distance (_item select 0)) > (_item select 2)) then {_result = false;};
};
if (!_result) exitWith{};
if (!_ignoreJammer) then {
	{
		if (((_x select 2) getVariable ["AGM_JammerEnabled",false]) and {(_x select 0) distance (_item select 0) <= (_x select 1)}) exitWith {
			_result = false;
		};
	} count AGM_Explosives_Jammers;
};
if (!_result) exitWith{};
if (getNumber (ConfigFile >> "CfgAmmo" >> typeof (_item select 0) >> "TriggerWhenDestroyed") == 0) then {
	private ["_exp", "_previousExp"];
	_previousExp = _item select 0;
	_exp = getText (ConfigFile >> "CfgAmmo" >> typeof (_previousExp) >> "AGM_Explosive");
	if (_exp != "") then {
		_exp = createVehicle [_exp, getPos _previousExp, [], 0, "NONE"];
		_exp setDir (getDir _previousExp);
		_item set [0, _exp];
		deleteVehicle _previousExp;
	};
};
_item spawn {
	sleep (_this select 1);
	(_this select 0) setDamage 1;
};
_result