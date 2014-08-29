// by commy2

private ["_vehicle", "_config", "_memoryPointDriver", "_distance"];

_vehicle = _this select 0;

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_memoryPointDriver = getText (_config >> "memoryPointsGetInDriver");

_distance = getNumber (_config >> "getInRadius");

isNull (driver _vehicle) &&
{alive _vehicle} &&
{!lockedDriver _vehicle} &&
{getNumber (_config >> "isUav") != 1} &&
{player distance (_vehicle modeltoworld (_vehicle selectionPosition _memoryPointDriver)) < _distance || {vehicle player == _vehicle}}
