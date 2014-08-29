// by commy2

_vehicle = _this select 0;
_index = _this select 1;

player action [
	["GetInCargo", "MoveToCargo"] select (vehicle player == _vehicle),
	_vehicle,
	_index
];

