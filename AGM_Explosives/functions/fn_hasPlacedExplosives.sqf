/*
	Name: AGM_Explosives_fnc_hasPlacedExplosives
	
	Author: Garth de Wet (LH)
	
	Description:
		Whether the passed unit has placed any explosives or has a clacker that was used when explosives were placed.
	
	Parameters: 
		0: OBJECT - unit
	
	Returns:
		BOOLEAN - True if the unit has explosives.
	
	Example:
		_hasPLacedExplosives = [player] call AGM_Explosives_fnc_hasPlacedExplosives;
*/
private ["_unit", "_clackerList", "_adjustedList"];
_unit = _this select 0;
_adjustedList = false;

_clackerList = _unit getVariable ["AGM_Clacker", []];
{
	if isNull (_x select 0) then {
		_clackerList set [_foreachIndex, "X"];
		_adjustedList = true;
	};
} foreach _clackerList;
if (_adjustedList) then {
	_clackerList = _clackerList - ["X"];
	_unit SetVariable ["AGM_Clacker", _clackerList, true];
};

(count _clackerList > 0)
