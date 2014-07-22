// by commy2

private ["_vehicle", "_config", "_turrets", "_crew", "_index", "_memoryPointCoDriver", "_distance", "_countCrew", "_coDrivers", "_countCoDrivers", "_isLocked"];

_vehicle = _this select 0;

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurrets;

_crew = crew _vehicle;

_index = crew _vehicle find driver _vehicle;
if (_index != -1) then {
	_crew set [_index, objNull];
};

{
	_index = crew _vehicle find (_vehicle turretUnit _x);
	if (_index != -1) then {
		_crew set [_index, objNull];
	};
} forEach _turrets;

_crew = _crew - [objNull];	//_vehicle emptyPositions "Cargo";

_memoryPointCoDriver = getText (_config >> "memoryPointsGetInCoDriver");
//_memoryPointCoDriver = getText (_config >> "memoryPointsGetInCargo");

_distance = getNumber (_config >> "getInRadius");

_countCrew = getNumber (_config >> "transportSoldier");	//count getArray (_config >> "cargoAction");

_coDrivers = getArray (_config >> "cargoIsCoDriver");
_countCoDrivers = {_x == 1} count _coDrivers;

_isLocked = false;
{
	if (_x == 1 && {_vehicle lockedCargo _forEachIndex}) then {
		_isLocked = true;
	};
} forEach _coDrivers;

count _crew < _countCrew &&
{alive _vehicle} &&
{!_isLocked} &&
{getNumber (_config >> "isUav") != 1} &&
{player distance (_vehicle modeltoworld (_vehicle selectionPosition _memoryPointCoDriver)) < _distance || {vehicle player == _vehicle}}
