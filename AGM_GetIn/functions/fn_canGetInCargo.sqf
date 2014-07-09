// by commy2

private ["_vehicle", "_index"];

_vehicle = _this select 0;
_index = _this select 1;

//isNull (_vehicle turretUnit _turret)

!(_vehicle lockedCargo _index)
