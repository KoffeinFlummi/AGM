/*
 * Author: commy2
 *
 * Get all vehicle positions
 * 
 * Argument:
 * 0: Vehicle class name (String)
 * 
 * Return value:
 * 0: Vehicle positions (Array)
 */

private ["_type", "_config"];

_type = _this select 0;;

_config = configFile >> "CfgVehicles" >> _type;

if (!isClass _config) exitWith {
	[[],[],[],[],[],[]]
};

private ["_driver", "_turrets", "_gunner", "_commander", "_coPilot", "_ffvPositions", "_cargo", "_coDrivers"];

_driver = [];

_turrets = [_type] call AGM_Core_fnc_getTurrets;
_gunner = [];
_commander = [];
_coPilot = [];
_ffvPositions = [];

for "_index" from 0 to (count _turrets - 1) do {
  private ["_turret", "_turretConfig"];
  _turret = _turrets select _index;
  _turretConfig = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

  switch (1) do {
    case (getNumber (_turretConfig >> "primaryGunner")): {
      _gunner = _turret;
      _turrets set [_index, -1];
    };
    case (getNumber (_turretConfig >> "primaryObserver")): {
      _commander = _turret;
      _turrets set [_index, -1];
    };
    case (getNumber (_turretConfig >> "isPersonTurret")): {
      _ffvPositions pushBack _turret;
      _turrets set [_index, -1];
    };
    case (getNumber (_turretConfig >> "isCopilot")): {
      _coPilot = _turret;
      _turrets set [_index, -1];
    };
  };
};

_turrets = _turrets - [-1];

_cargo = [];
for "_index" from 0 to (getNumber (_config >> "transportSoldier") - 1) do {
	_cargo pushBack _index;
};

_coDrivers = [];
{
	private "_index";

	_index = _cargo find _x;

	if (_index != -1) then {
		_coDrivers pushBack _x;
		_cargo deleteAt _index;
	};
} forEach getArray (_config >> "cargoIsCoDriver");

[_driver, _gunner, _commander, _coPilot, _turrets, _ffvPositions, _cargo, _coDrivers]
