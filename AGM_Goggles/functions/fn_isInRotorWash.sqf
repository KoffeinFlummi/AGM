/*
	Name: AGM_Goggles_fnc_isInRotorWash
	
	Author: Garth de Wet (LH)
	
	Description:
	Checks for nearby helicopters (within 15m)
	
	Parameters:
	0: Object - Unit
	
	Returns:
	Array:
		0 - boolean - If in rotorwash
		1 - number - Amount of rotor wash.
	
	Example:
	if ((player call AGM_Goggles_fnc_isInRotorWash) select 0) then { hint "Rotor wash"; };
*/
private ["_heli", "_unit", "_result"];
#define RADIUS 15
_unit = _this;
_result = [false, RADIUS + 2];

_heli = (getPosATL _unit) nearEntities [["Helicopter"], RADIUS];
{
	if !(_x isKindOf "ParachuteBase") then {
		if (isEngineOn _x) then {
			private "_distance";
			_distance = (RADIUS - (_unit distance _x));
			if (_distance != 0) then {
				_distance = _distance / RADIUS;
			};
			if (_distance < (_result select 1)) then {
				_result = [true, _distance];
			};
		};
	};
} count _heli;

_result