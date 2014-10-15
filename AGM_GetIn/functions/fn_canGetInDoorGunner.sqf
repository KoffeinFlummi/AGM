// by jodav

private ["_player", "_vehicle", "_doorSide", "_config", "_doorTurrets", "_isPrimaryGunner", "_turret", "_configTurret", "_memoryPointGunner", "_distance"];

_player = _this select 0;
_vehicle = _this select 1;
_doorSide = _this select 2;


_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_doorTurrets = [typeOf _vehicle] call AGM_Core_fnc_getDoorTurrets;

if (count _doorTurrets == 0) exitWith {false};

{
  
  //_turret = _x;
  _configTurret = [_config, _x] call AGM_Core_fnc_getTurretConfigPath;
  
  _isPrimaryGunner = false;
  if (getNumber (_configTurret >> "primaryGunner") == 1) then {
    _isPrimaryGunner = true;
  };
  
  if (_doorSide == 0 && _isPrimaryGunner) then {
    _turret = _x;
  };
  
  if (_doorSide == 1 && !_isPrimaryGunner) then {
    _turret = _x;
  };

} forEach _doorTurrets;

if (isNil "_turret") exitWith {false};

AGM_Interaction_MenuData = [_turret];

_configTurret = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

_memoryPointGunner = getText (_configTurret >> "memoryPointsGetInGunner");

_distance = getNumber (_config >> "getInRadius");

(isNull (_vehicle turretUnit _turret) || (!alive (_vehicle turretUnit _turret)))
&& {alive _vehicle}
&& {!(_vehicle lockedTurret _turret)}
&& {!(locked _vehicle >= 2)}
&& {getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "isUav") != 1}
&& {_player distance (_vehicle modeltoworld (_vehicle selectionPosition _memoryPointGunner)) < _distance || {vehicle _player == _vehicle}}
