/*
 * Author: commy2
 *
 * Move unit into given vehicle position. Or switch to that position if the unit is already inside the vehicle.
 *
 * Arguments:
 * 0: Unit to enter the vehicle (Object)
 * 1: The vehicle to be entered (Object)
 * 2: Position. Can be "Driver", "Pilot", "Gunner", "Commander", "Copilot", "Turret", "FFV", "Codriver" or "Cargo" (String)
 * 3: Index. "Turret", "FFV", "Codriver" and "Cargo" support this optional parameter. Which position should be taken.
 *    Note: This index is diffrent from Armas "cargoIndex". (Number, optinal Default: next free index)
 *
 * Return Value:
 * Nothing
 */

private ["_unit", "_vehicle", "_position", "_index", "_isInside"];

_unit = _this select 0;
_vehicle = _this select 1;
_position = _this select 2;
_index = _this select 3;	// optional, please don't use

if (isNil "_index") then {_index = -1};

_isInside = vehicle _unit == _vehicle;

switch (toLower _position) do {
	case "driver" : {
		_unit action [
			["GetInDriver", "MoveToDriver"] select _isInside,
			_vehicle
		];
	};

	case "pilot" : {
		_unit action [
			["GetInPilot", "MoveToPilot"] select _isInside,
			_vehicle
		];
	};

	case "gunner" : {
		_unit action [
			["GetInGunner", "MoveToGunner"] select _isInside,
			_vehicle
		];
	};

	case "commander" : {
		_unit action [
			["GetInCommander", "MoveToCommander"] select _isInside,
			_vehicle
		];
	};

	case "copilot" : {
		private "_turret";
		_turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretCopilot;

		_unit action [
			["GetInTurret", "moveToTurret"] select _isInside,
			_vehicle,
			_turret
		];
	};

	case "turret" : {
		private ["_turrets", "_turret"];
		_turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurretsOther;

		if (_index != -1 && {_turret = _turrets select _index; isNull (_vehicle turretUnit _turret)}) then {

			_unit action [
				["GetInTurret", "moveToTurret"] select _isInside,
				_vehicle,
				_turret
			];
		} else {

			for "_index" from 0 to (count _turrets - 1) do {
				_turret = _turrets select _index;
				if (isNull (_vehicle turretUnit _turret)) exitWith {

					_unit action [
						["GetInTurret", "moveToTurret"] select _isInside,
						_vehicle,
						_turret
					];
				};
			};
		};
	};

	case "ffv" : {
		private ["_turrets", "_turret"];
		_turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurretsFFV;

		if (_index != -1 && {_turret = _turrets select _index; isNull (_vehicle turretUnit _turret)}) then {

			_unit action [
				["GetInTurret", "moveToTurret"] select _isInside,
				_vehicle,
				_turret
			];
		} else {

			for "_index" from 0 to (count _turrets - 1) do {
				_turret = _turrets select _index;
				if (isNull (_vehicle turretUnit _turret)) exitWith {

					_unit action [
						["GetInTurret", "moveToTurret"] select _isInside,
						_vehicle,
						_turret
					];
				};
			};
		};
	};

	case "codriver" : {
		private "_positions";
		_positions = [typeOf _vehicle] call AGM_Core_fnc_getVehicleCodriver;

		{
			_positions deleteAt (_positions find (_vehicle getCargoIndex _x));
		} forEach crew _vehicle;

		if (_index != -1 && {_index in _positions}) then {
			_unit action [
				["GetInCargo", "MoveToCargo"] select _isInside,
				_vehicle,
				_index
			];
		} else {

			_index = _positions select 0;
			if (!isNil "_index") then {

				_unit action [
					["GetInCargo", "MoveToCargo"] select _isInside,
					_vehicle,
					_index
				];
			};
		};
	};

	case "cargo" : {
		private "_positions";
		_positions = [typeOf _vehicle] call AGM_Core_fnc_getVehicleCargo;

		{
			_positions deleteAt (_positions find (_vehicle getCargoIndex _x));
		} forEach crew _vehicle;

		if (_index != -1 && {_index in _positions}) then {
			_unit action [
				["GetInCargo", "MoveToCargo"] select _isInside,
				_vehicle,
				_index
			];
		} else {

			_index = _positions select 0;
			if (!isNil "_index") then {

				_unit action [
					["GetInCargo", "MoveToCargo"] select _isInside,
					_vehicle,
					_index
				];
			};
		};
	};

	default {};
};
