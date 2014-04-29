// by commy2

private ["_unit", "_vehicle", "_config", "_animation", "_action", "_inAction", "_turretIndex", "_count", "_index"];

_unit = _this select 0;
_vehicle = vehicle _unit;
_config = configFile >> "CfgVehicles" >> typeOf _vehicle;
_animation = animationState _unit;

if (_unit == driver _vehicle) then {
	_action = getText (_config >> "driverAction");
	_inAction = getText (_config >> "driverInAction");
} else {
	_turretIndex = [_unit] call AGM_Core_fnc_getTurretIndex;

	_count = count _turretIndex;

	for "_index" from 0 to (_count - 1) do {
		_config = _config >> "Turrets";
		_config = _config select (_turretIndex select _index);
	};

	_action = getText (_config >> "gunnerAction");
	_inAction = getText (_config >> "gunnerInAction");
};

if (_action == "" || {_inAction == ""} || {_action == _inAction}) exitWith {false};

_animation = toArray _animation;
_animation resize (count toArray _action);
_animation = toString _animation;

_animation == _action
