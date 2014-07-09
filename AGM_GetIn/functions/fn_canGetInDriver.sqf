// by commy2

private "_vehicle";

_vehicle = _this select 0;

isNull (driver _vehicle) && {!lockedDriver _vehicle} && {getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "isUav") != 1}
