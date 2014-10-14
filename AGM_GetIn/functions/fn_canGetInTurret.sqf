// by commy2

private ["_player", "_vehicle", "_turret", "_config", "_configTurret", "_memoryPointGunner", "_distance"];

_player = _this select 0;
_vehicle = _this select 1;
_turret = _this select 2;

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;


_configTurret = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

if (_turret isEqualTo [] || {!(_turret in ([typeOf _vehicle] call AGM_Core_fnc_getTurrets))}) exitWith {false};

_memoryPointGunner = getText (_configTurret >> "memoryPointsGetInGunner");

_distance = getNumber (_config >> "getInRadius");

isNull (_vehicle turretUnit _turret)
&& {alive _vehicle}
&& {!(_vehicle lockedTurret _turret)}
&& {!(locked _vehicle >= 2)}
&& {getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "isUav") != 1}
&& {_player distance (_vehicle modeltoworld (_vehicle selectionPosition _memoryPointGunner)) < _distance || {vehicle _player == _vehicle}}
