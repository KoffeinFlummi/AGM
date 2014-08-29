// by commy2

_vehicle = _this select 0;
_turret = _this select 1;

player action [
	["GetInTurret", "MoveToTurret"] select (vehicle player == _vehicle),
	_vehicle,
	_turret
];

