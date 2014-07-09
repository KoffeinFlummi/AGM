/*
	Name: AGM_Explosives_fnc_DetonateExplosive
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Detonates a remote Explosive that belongs to the passed code.
	
	Parameters:
		0: OBJECT - Unit detonating explosive
		1: STRING - Explosive code
		/
		1: ARRAY - Explosive
			0: OBJECT - Explosive
			1: NUMBER - Fuse Time
			2: NUMBER - Max range
		2: BOOLEAN - Ignore Range
		3: BOOLEAN - Ignore Jammer
	
	Returns:
		Nothing
	
	Example:
		// Cellphone
		[player, "2123", false, false] call AGM_Explosives_fnc_DetonateExplosive;
		// Clacker
		[player, [Explosive, 1, 75], false, false] call AGM_Explosives_fnc_DetonateExplosive;
*/
private ["_item","_result", "_ignoreRange", "_ignoreJammer", "_unit"];
_unit = (_this select 0);
_item = (_this select 1);
_ignoreRange = (_this select 2);
_ignoreJammer = (_this select 3);
_result = true;
if ((typeName _item) == "ARRAY") then {
	if (!_ignoreRange) then {
		if ((_unit distance (_item select 0)) > (_item select 2)) exitWith {_result = false;};
	};
	if (!_result) exitWith{};
	if (!_ignoreJammer) then {
		{
			if (((_x select 2) getVariable ["AGM_Explosives_JammerEnabled",false]) and {(_x select 0) distance (_item select 0) <= (_x select 1)}) exitWith {
				_result = false;
			};
		} count AGM_Explosives_Jammers;
	};
	if (!_result) exitWith{};
	_item spawn {
		sleep (_this select 1);
		(_this select 0) setDamage 1;
	};
	_result = true;
} else {
	{
		if ((_x select 1) == _item) exitWith {
			if (isNull(_x select 0)) exitWith {
				AGM_Explosives_List set [_foreachIndex, "x"];
				AGM_Explosives_List = AGM_Explosives_List - ["x"];
				publicVariable "AGM_Explosives_List";
				_result = false;
			};
			private "_explosive";
			_explosive = _x select 0;
			if (!_ignoreRange) then {
				if ((_unit distance _explosive) > (_x select 3)) exitWith {_result=false;};
			};
			if (!_result) exitWith{};
			if (!_ignoreJammer) then {
				{
					if (((_x select 2) getVariable ["AGM_Explosives_JammerEnabled",false]) and {(_x select 0) distance _explosive <= (_x select 1)}) exitWith {
						_result = false;
					};
				} count AGM_Explosives_Jammers;
			};
			if (!_result) exitWith{};
			[_x,_foreachIndex] spawn {
				playSound3D ["AGM_Explosives\Data\Audio\cellphone_ring.wss",((_this select 0) select 0), false,getPosATL ((_this select 0) select 0),3.16228,1,75];
				sleep ((_this select 0) select 2);
				((_this select 0) select 0) setDamage 1;
				AGM_Explosives_List set [_this select 1, "x"];
				AGM_Explosives_List = AGM_Explosives_List - ["x"];
				publicVariable "AGM_Explosives_List";
			};
			_result = true;
		};
	} foreach AGM_Explosives_List;
};
_result