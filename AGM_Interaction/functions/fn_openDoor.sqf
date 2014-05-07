// by commy2

#define MAX_DISTANCE 2
#define DOOR_ACTIONS ["Close", "Open", "OpenLocked"]

_house = cursorTarget;

_intersections = [_house, "GEOM"] intersect [
	positionCameraToWorld [0, 0, 0],
	positionCameraToWorld [0, 0, MAX_DISTANCE]
];

_door = "";
{
	_selection = toArray (_x select 0);
	_selection resize 5;

	if (toString _selection == "door_") then {
		_door = _x select 0;
	};
} forEach _intersections;

if (_door == "") exitWith {};

_config = configFile >> "CfgVehicles" >> typeOf _house >> "UserActions";

{
	_string = _x + _door;
	_condition = compile getText (_config >> _string >> "condition");
	_statement = compile getText (_config >> _string >> "statement");

	this = _house;
	if (call _condition) exitWith {call _statement};
} forEach DOOR_ACTIONS;
