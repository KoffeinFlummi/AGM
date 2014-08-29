// by commy2

_vehicle = _this select 0;
_index = _this select 1;

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_coDrivers = getArray (_config >> "cargoIsCoDriver");
_countCoDrivers = {_x == 1} count _coDrivers;

if (isNil "_index") then {
	_index = _countCoDrivers - 1;
};

player action [
	["GetInCargo", "MoveToCargo"] select (vehicle player == _vehicle),
	_vehicle,
	_index
];

