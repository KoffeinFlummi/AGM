/*
	Name: AGM_Logistics_fnc_getLoadPoints
	
	Author: 
		commy2
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters: 
		0: OBJECT - item to attempt to load
	
	Returns:
		BOOLEAN
	
	Example:
		_attachPoints = _truck call AGM_Logistics_fnc_getLoadPoints;
*/
#define TRUNK_SELECTION "doplnovani"
#define MAX_DISTANCE 8

_nearestVehicles = [
	getPos player nearestObject "Car",
	getPos player nearestObject "Tank"
];

_distances = [];
{
	if (typeName _x == "OBJECT") then {
		_distances set [count _distances, player distance _x];
	};
} count _nearestVehicles;

_distance = MAX_DISTANCE;
{
	_distance = _distance min _x;
} count _distances;

if (_distance == MAX_DISTANCE) exitWith {false};

AGM_Logistics_targetVehicle = _nearestVehicles select (_distances find _distance);
_attachPoints = AGM_Logistics_targetVehicle call AGM_Logistics_fnc_getLoadPoints;
_size = getNumber(ConfigFile >> "CfgVehicles" >> Typeof(_this select 0) >> "AGM_Size");

_result = false;
{
    if ([_x select 1, _x select 3] call AGM_Logistics_fnc_remainingSpace >= _size) exitWith {
		_result = true;
    };
} count _attachPoints;

_result