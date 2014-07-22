// by commy2

#define TRUNK_SELECTION "doplnovani"
#define MAX_DISTANCE 4

_nearestVehicles = [
	getPos player nearestObject "Car",
	getPos player nearestObject "Tank"
];

_distances = [];
{
	if (typeName _x == "OBJECT") then {
		_distances set [_forEachIndex, player distance (_x modelToWorld (_x selectionPosition TRUNK_SELECTION))];
	};
} forEach _nearestVehicles;

_distance = MAX_DISTANCE;
{
	_distance = _distance min _x;
} forEach _distances;

if (_distance == 4) exitWith {false};

AGM_Logistics_targetVehicle = _nearestVehicles select (_distances find _distance);
true
