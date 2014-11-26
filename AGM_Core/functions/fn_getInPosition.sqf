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
 *    Note: This index is diffrent from Armas "cargoIndex". (Number, optional default: next free index)
 *
 * Return Value:
 * Nothing
 */

#define CANGETINDRIVER      (isNull (driver _vehicle)             || {!alive driver _vehicle})               && {!lockedDriver _vehicle}           && {getNumber (_config >> "isUav") != 1}
#define CANGETINTURRETINDEX (isNull (_vehicle turretUnit _turret) || {!alive (_vehicle turretUnit _turret)}) && {!(_vehicle lockedTurret _turret)} && {getNumber (_config >> "isUav") != 1}

private ["_unit", "_vehicle", "_position", "_index"];

_unit = _this select 0;
_vehicle = _this select 1;
_position = toLower (_this select 2);
_index = _this select 3;  // optional, please don't use

if (isNil "_index") then {_index = -1};

// general
if (!alive _vehicle || {locked _vehicle > 1}) exitWith {false};

private ["_config", "_turret", "_isInside", "_script", "_enemiesInVehicle"];

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;
_turret = [];

_isInside = vehicle _unit == _vehicle;

_script = {};
_enemiesInVehicle = false;   //Possible Side Restriction
{
  if (side _unit getFriend side _x < 0.6) exitWith {_enemiesInVehicle = true};
} forEach crew _vehicle;

switch (_position) do {
  case "driver" : {
    if (CANGETINDRIVER) then {
      _script = [
        {_unit action [["GetInDriver", "MoveToDriver"] select _isInside, _vehicle];},
        {if (_isInside) then {moveOut _unit}; _unit moveInDriver _vehicle; call _fnc_getInEH;}
      ] select _enemiesInVehicle;
    };
  };

  case "pilot" : {
    if (CANGETINDRIVER) then {
      _script = [
        {_unit action [["GetInPilot", "MoveToPilot"] select _isInside, _vehicle];},
        {if (_isInside) then {moveOut _unit}; _unit moveInDriver _vehicle; call _fnc_getInEH;}
      ] select _enemiesInVehicle;
      _position = "driver";
    };
  };

  case "gunner" : {
    _turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretGunner;

    if (CANGETINTURRETINDEX) then {
      _script = [
        {_unit action [["GetInGunner", "MoveToGunner"] select _isInside, _vehicle];},
        {if (_isInside) then {moveOut _unit}; _unit moveInGunner _vehicle; call _fnc_getInEH;}
      ] select _enemiesInVehicle;
    };
  };

  case "commander" : {
    _turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretCommander;

    if (CANGETINTURRETINDEX) then {
      _script = [
        {_unit action [["GetInCommander", "MoveToCommander"] select _isInside, _vehicle];},
        {if (_isInside) then {moveOut _unit}; _unit moveInCommander _vehicle; call _fnc_getInEH;}
      ] select _enemiesInVehicle;
    };
  };

  case "copilot" : {
    _turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretCopilot;

    if (CANGETINTURRETINDEX) then {
      _script = [
        {_unit action [["GetInTurret", "moveToTurret"] select _isInside, _vehicle, _turret];},
        {if (_isInside) then {moveOut _unit}; _unit moveInTurret [_vehicle, _turret]; call _fnc_getInEH;}
      ] select _enemiesInVehicle;

      _position = "gunner";  // I think. It's a turret after all and turrets supposedly return "gunner"
    };
  };

  case "turret" : {
    private "_turrets";
    _turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurretsOther;

    if (_index != -1 && {_turret = _turrets select _index; CANGETINTURRETINDEX}) then {
      _script = [
        {_unit action [["GetInTurret", "moveToTurret"] select _isInside, _vehicle, _turret];},
        {if (_isInside) then {moveOut _unit}; _unit moveInTurret [_vehicle, _turret]; call _fnc_getInEH;}
      ] select _enemiesInVehicle;

      _position = "gunner";
    } else {

      for "_index" from 0 to (count _turrets - 1) do {
        _turret = _turrets select _index;
        if (CANGETINTURRETINDEX) exitWith {
          _script = [
            {_unit action [["GetInTurret", "moveToTurret"] select _isInside, _vehicle, _turret];},
            {if (_isInside) then {moveOut _unit}; _unit moveInTurret [_vehicle, _turret]; call _fnc_getInEH;}
          ] select _enemiesInVehicle;

          _position = "gunner";
        };
      };
    };
  };

  case "ffv" : {
    private "_turrets";
    _turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurretsFFV;

    if (_index != -1 && {_turret = _turrets select _index; CANGETINTURRETINDEX}) then {
      _script = [
        {_unit action [["GetInTurret", "moveToTurret"] select _isInside, _vehicle, _turret];},
        {if (_isInside) then {moveOut _unit}; _unit moveInTurret [_vehicle, _turret]; call _fnc_getInEH;}
      ] select _enemiesInVehicle;

      _position = "gunner";  // I think. It's a turret after all and turrets supposedly return "gunner"
    } else {

      for "_index" from 0 to (count _turrets - 1) do {
        _turret = _turrets select _index;
        if (CANGETINTURRETINDEX) exitWith {
          _script = [
            {_unit action [["GetInTurret", "moveToTurret"] select _isInside, _vehicle, _turret];},
            {if (_isInside) then {moveOut _unit}; _unit moveInTurret [_vehicle, _turret]; call _fnc_getInEH;}
          ] select _enemiesInVehicle;

          _position = "gunner";  // I think. It's a turret after all and turrets supposedly return "gunner"
        };
      };
    };
  };

  case "codriver" : {
    private "_positions";
    _positions = [typeOf _vehicle] call AGM_Core_fnc_getVehicleCodriver;

    {
      if (alive _x) then {_positions deleteAt (_positions find (_vehicle getCargoIndex _x))};
    } forEach crew _vehicle;

    if (_index != -1 && {_index in _positions}) then {
      _script = [
        {_unit action [["GetInCargo", "MoveToCargo"] select _isInside, _vehicle, _index];},
        {if (_isInside) then {moveOut _unit}; _unit moveInCargo [_vehicle, _index]; call _fnc_getInEH;}
      ] select _enemiesInVehicle;

      _position = "cargo";
    } else {

      _index = _positions select 0;
      if (!isNil "_index") then {
        _script = [
          {_unit action [["GetInCargo", "MoveToCargo"] select _isInside, _vehicle, _index];},
          {if (_isInside) then {moveOut _unit}; _unit moveInCargo [_vehicle, _index]; call _fnc_getInEH;}
        ] select _enemiesInVehicle;

        _position = "cargo";
      };
    };
  };

  case "cargo" : {
    private "_positions";
    _positions = [typeOf _vehicle] call AGM_Core_fnc_getVehicleCargo;

    {
      if (alive _x) then {_positions deleteAt (_positions find (_vehicle getCargoIndex _x))};
    } forEach crew _vehicle;

    if (_index != -1 && {_index in _positions}) then {
      _script = [
        {_unit action [["GetInCargo", "MoveToCargo"] select _isInside, _vehicle, _index];},
        {if (_isInside) then {moveOut _unit}; _unit moveInCargo [_vehicle, _index]; call _fnc_getInEH;}
      ] select _enemiesInVehicle;

      _position = "cargo";
    } else {

      _index = _positions select 0;
      if (!isNil "_index") then {
        _script = [
          {_unit action [["GetInCargo", "MoveToCargo"] select _isInside, _vehicle, _index];},
          {if (_isInside) then {moveOut _unit}; _unit moveInCargo [_vehicle, _index]; call _fnc_getInEH;}
        ] select _enemiesInVehicle;

        _position = "cargo";
      };
    };
  };

  default {};
};

// this will execute all config based event handlers. Not script based ones unfortunately, but atleast we don't use any.
private "_fnc_getInEH";
_fnc_getInEH = {
  private "_config";
  // config based getIn EHs are assigned to the soldier, not the vehicle. Why Bis? Why?
  _config = configFile >> "CfgVehicles" >> typeOf _unit >> "EventHandlers";

  if (isClass _config) then {
    //getIn is local effects with global arguments. It doesn't trigger if the unit was already inside and only switched seats
    if !(_isInside) then {
      [_vehicle, _position, _unit, _turret] call compile getText (_config >> "getIn");
    };
  };
};

// if you want into the cargo and you can't, then check ffv turrets aswell
if (_position == "cargo") exitWith {
  if (_script isEqualTo {}) then {
    [_unit, _vehicle, "ffv"] call AGM_Core_fnc_getInPosition;
  } else {
    call _script;
  };
};

call _script;

/*
  sleep 0.1;
  if ((vehicle _unit) != _vehicle) then {
    ["fn_getInPosition.sqf - Side Restriction, failed to move _unit into vehicle"] call bis_fnc_error;
    _unit moveInAny _vehicle;  //attempt to fail gracefully
  };
*/
