// by commy2

private ["_player", "_vehicle", "_index", "_config", "_slots", "_memoryPointCargo", "_distance"];

_player = _this select 0;
_vehicle = _this select 1;
//_index = _this select 2;

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_slots = []; for "_a" from 0 to (getNumber (_config >> "transportSoldier") - 1) do {if !(_vehicle lockedCargo _a) then {_slots pushBack _a}};
_slots = _slots - getArray (_config >> "cargoIsCoDriver");
_index = _slots select 0;
if (isNil "_index") exitWith {false}; AGM_Interaction_MenuData = [_index];

_memoryPointCargo = getText (_config >> "memoryPointsGetInCargo");

_distance = getNumber (_config >> "getInRadius");

_vehicle emptyPositions "Cargo" > 0
&& {alive _vehicle}
&& {!(locked _vehicle >= 2)}
//&& {!(_vehicle lockedCargo _index)}
//&& {getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "isUav") != 1}
&& {_player distance (_vehicle modeltoworld (_vehicle selectionPosition _memoryPointCargo)) < _distance || {vehicle _player == _vehicle}}
