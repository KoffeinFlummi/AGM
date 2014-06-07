_vehicle = _this select 0;
_repairSelection = _this select 1;
_repairSelectionName = _this select 2;
_caller = _this select 3;

if((_vehicle getHitPointDamage _repairSelection > 0.1) && (damage player < 1) && (speed _vehicle == 0)) then {
	_vehicle setHit [_repairSelectionName, 0];
};