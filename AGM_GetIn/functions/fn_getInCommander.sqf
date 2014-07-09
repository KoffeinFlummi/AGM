// by commy2

_vehicle = _this select 0;

player action [
	["GetInCommander", "MoveToCommader"] select (vehicle player == _vehicle),
	_vehicle
];
