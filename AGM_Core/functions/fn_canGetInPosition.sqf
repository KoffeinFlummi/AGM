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

private ["_unit", "_vehicle", "_position", "_checkDistance", "_index"];

_this resize 5;

_unit = _this select 0;
_vehicle = _this select 1;
_position = _this select 2;
_checkDistance = _this select 3;
_index = _this select 4;	// optional, please don't use

if (isNil "_checkDistance") then {_checkDistance = false};
if (isNil "_index") then {_index = -1};

// general
if (!alive _vehicle || {locked _vehicle > 1}) exitWith {false};

private ["_config", "_selection", "_radius", "_return"];

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_selection = "";
_radius = 0;

_return = false;
switch (toLower _position) do {
	case "driver" : {
		_selection = getText (_config >> "memoryPointsGetInDriver");
		_radius = getNumber (_config >> "getInRadius");

		isNull (driver _vehicle) && {!lockedDriver _vehicle} && {getNumber (_config >> "isUav") != 1}
	};

	case "pilot" : {
		_selection = getText (_config >> "memoryPointsGetInDriver");
		_radius = getNumber (_config >> "getInRadius");

		_return = isNull (driver _vehicle) && {!lockedDriver _vehicle} && {getNumber (_config >> "isUav") != 1}
	};

	case "gunner" : {
		private ["_turret", "_turretConfig"];
		_turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretGunner;
		if (_turret isEqualTo []) exitWith {false};

		_turretConfig = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

		_selection = getText (_turretConfig >> "memoryPointsGetInGunner");
		_radius = getNumber (_config >> "getInRadius");

		_return = isNull (_vehicle turretUnit _turret) && {!(_vehicle lockedTurret _turret)} && {getNumber (_config >> "isUav") != 1}
	};

	case "commander" : {
		private ["_turret", "_turretConfig"];
		_turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretCommander;
		if (_turret isEqualTo []) exitWith {false};

		_turretConfig = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

		_selection = getText (_turretConfig >> "memoryPointsGetInGunner");
		_radius = getNumber (_config >> "getInRadius");

		_return = isNull (_vehicle turretUnit _turret) && {!(_vehicle lockedTurret _turret)} && {getNumber (_config >> "isUav") != 1}
	};

	case "copilot" : {
		private ["_turret", "_turretConfig"];
		_turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretCopilot;
		if (_turret isEqualTo []) exitWith {false};

		_turretConfig = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

		_selection = getText (_turretConfig >> "memoryPointsGetInGunner");
		_radius = getNumber (_config >> "getInRadius");

		_return = isNull (_vehicle turretUnit _turret) && {!(_vehicle lockedTurret _turret)} && {getNumber (_config >> "isUav") != 1}
	};

	case "turret" : {
		private ["_turrets", "_turret", "_turretConfig"];
		_turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurretsOther;

		if (_index != -1 && {_turret = _turrets select _index; 
			isNull (_vehicle turretUnit _turret) && {!(_vehicle lockedTurret _turret)} && {getNumber (_config >> "isUav") != 1}
		}) then {
			_turretConfig = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

			_selection = getText (_turretConfig >> "memoryPointsGetInGunner");
			_radius = getNumber (_config >> "getInRadius");

			_return = true
		} else {
			for "_index" from 0 to (count _turrets - 1) do {
				_turret = _turrets select _index;
				if (isNull (_vehicle turretUnit _turret) && {!(_vehicle lockedTurret _turret)} && {getNumber (_config >> "isUav") != 1}) exitWith {
					_turretConfig = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

					_selection = getText (_turretConfig >> "memoryPointsGetInGunner");
					_radius = getNumber (_config >> "getInRadius");

					_return = true
				};
			};
		};
	};

	case "ffv" : {
		private ["_turrets", "_turret", "_turretConfig"];
		_turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurretsFFV;

		if (_index != -1 && {_turret = _turrets select _index; 
			isNull (_vehicle turretUnit _turret) && {!(_vehicle lockedTurret _turret)} && {getNumber (_config >> "isUav") != 1}
		}) then {
			_turretConfig = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

			_selection = getText (_turretConfig >> "memoryPointsGetInGunner");
			_radius = getNumber (_config >> "getInRadius");

			_return = true
		} else {
			for "_index" from 0 to (count _turrets - 1) do {
				_turret = _turrets select _index;
				if (isNull (_vehicle turretUnit _turret) && {!(_vehicle lockedTurret _turret)} && {getNumber (_config >> "isUav") != 1}) exitWith {
					_turretConfig = [_config, _turret] call AGM_Core_fnc_getTurretConfigPath;

					_selection = getText (_turretConfig >> "memoryPointsGetInGunner");
					_radius = getNumber (_config >> "getInRadius");

					_return = true
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
			_selection = getText (_config >> "memoryPointsGetInCargo");
			_radius = getNumber (_config >> "getInRadius");

			_return = true
		} else {

			_index = _positions select 0;
			if (!isNil "_index") then {
				_selection = getText (_config >> "memoryPointsGetInCargo");
				_radius = getNumber (_config >> "getInRadius");

				_return = true
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
			_selection = getText (_config >> "memoryPointsGetInCargo");
			_radius = getNumber (_config >> "getInRadius");

			_return = true
		} else {

			_index = _positions select 0;
			if (!isNil "_index") then {
				_selection = getText (_config >> "memoryPointsGetInCargo");
				_radius = getNumber (_config >> "getInRadius");

				_return = true
			};
		};
	};

	default {};
};

if (!_checkDistance || {_radius == 0} || {_vehicle == vehicle _unit}) exitWith {_return};

_return && {(getPos _unit) distance (_vehicle modelToWorld (_vehicle selectionPosition _selection)) < _radius}
