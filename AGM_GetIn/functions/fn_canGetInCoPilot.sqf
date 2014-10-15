// by commy2

private ["_player", "_vehicle", "_coPilotTurret", "_config", "_configTurret", "_memoryPointCoDriver", "_distance"];

_player = _this select 0;
_vehicle = _this select 1;


_coPilotTurret = [typeOf _vehicle] call AGM_Core_fnc_getCopilotTurret;

if (_coPilotTurret isEqualTo []) exitWith {false};


_config = configFile >> "CfgVehicles" >> typeOf _vehicle;
_configTurret = [_config, _coPilotTurret] call AGM_Core_fnc_getTurretConfigPath;

_memoryPointCoDriver = getText (_configTurret >> "memoryPointsGetInCargo"); //_memoryPointCoDriver = getText (_config >> "memoryPointsGetInCoDriver");

_distance = getNumber (_config >> "getInRadius");

AGM_Interaction_MenuData = [_coPilotTurret];



(isNull (_vehicle turretUnit _coPilotTurret) || (!alive (_vehicle turretUnit _coPilotTurret)))
&& {alive _vehicle}
&& {!(_vehicle lockedTurret _coPilotTurret)}
&& {!(locked _vehicle >= 2)}
&& {_player distance (_vehicle modeltoworld (_vehicle selectionPosition _memoryPointCoDriver)) < _distance || {vehicle _player == _vehicle}}
