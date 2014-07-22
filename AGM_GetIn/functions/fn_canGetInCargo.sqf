// by commy2

private ["_vehicle", "_index", "_config", "_memoryPointCargo", "_distance"];

_vehicle = _this select 0;
_index = _this select 1;

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_memoryPointCargo = getText (_config >> "memoryPointsGetInCargo");

_distance = getNumber (_config >> "getInRadius");

_vehicle emptyPositions "Cargo" > 0 &&
{alive _vehicle} &&
{!(_vehicle lockedCargo _index)} &&
//{getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "isUav") != 1} &&
{player distance (_vehicle modeltoworld (_vehicle selectionPosition _memoryPointCargo)) < _distance || {vehicle player == _vehicle}}
