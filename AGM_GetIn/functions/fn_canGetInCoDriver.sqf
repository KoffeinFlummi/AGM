// by commy2

private ["_player", "_vehicle", "_index", "_config", "_slots", "_memoryPointCoDriver", "_distance"];

_player = _this select 0;
_vehicle = _this select 1;

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_slots = getArray (_config >> "cargoIsCoDriver");
{if (_vehicle lockedCargo _x) then {_slots set [_forEachIndex, -1]}} forEach _slots; _slots = _slots - [-1];
_index = _slots select 0;
if (isNil "_index") exitWith {false}; AGM_Interaction_MenuData = [_index];

_memoryPointCoDriver = getText (_config >> "memoryPointsGetInCargo"); //_memoryPointCoDriver = getText (_config >> "memoryPointsGetInCoDriver");

_distance = getNumber (_config >> "getInRadius");

_vehicle emptyPositions "Cargo" > 0
&& {alive _vehicle}
&& {!(locked _vehicle >= 2)}
//&& {!(_vehicle lockedCargo _index)}
//&& {getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "isUav") != 1}
&& {_player distance (_vehicle modeltoworld (_vehicle selectionPosition _memoryPointCoDriver)) < _distance || {vehicle _player == _vehicle}}
