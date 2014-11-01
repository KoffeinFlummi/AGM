/*
 * Author: commy2
 *
 * Check if the unit is in a vehicle and turned out.
 *
 * Argument:
 * 0: Unit, not the vehicle (Object)
 *
 * Return value:
 * Is the unit turned out or not? Will return false if there is no option to turn out in the first place. (Bool)
 */

private ["_unit", "_vehicle", "_config", "_animation", "_action", "_inAction", "_turretIndex"];

_unit = _this select 0;
_vehicle = vehicle _unit;
_config = configFile >> "CfgVehicles" >> typeOf _vehicle;
_animation = animationState _unit;

if (_unit == driver _vehicle) then {
  _action = getText (_config >> "driverAction");
  _inAction = getText (_config >> "driverInAction");
} else {
  _turretIndex = [_unit] call AGM_Core_fnc_getTurretIndex;

  _config = [_config, _turretIndex] call AGM_Core_fnc_getTurretConfigPath;

  _action = getText (_config >> "gunnerAction");
  _inAction = getText (_config >> "gunnerInAction");
};

if (_action == "" || {_inAction == ""} || {_action == _inAction}) exitWith {false};

_animation = toArray _animation;
_animation resize (count toArray _action);
_animation = toString _animation;

_animation == _action
