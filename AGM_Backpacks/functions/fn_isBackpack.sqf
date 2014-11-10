// by commy2

private ["_object", "_config"];

_object = _this select 0;

_config = configFile >> "CfgVehicles" >> typeOf _object;

getText (_config >> "vehicleClass") == "backpacks"
&& {getNumber (_config >> "maximumLoad") > 0}
