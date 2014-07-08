// by commy2

private ["_vehicle", "_index"];

_vehicle = _this select 0;
_index = _this select 1;

//isNull (AGM_Interaction_Target turretUnit _turret)

!(_vehicle lockedCargo _index)
