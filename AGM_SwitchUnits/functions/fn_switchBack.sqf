private ["_originalPlayerUnit", "_currentUnit"];
_originalPlayerUnit = _this select 0;
_currentUnit = _this select 1;

waitUntil {local _originalPlayerUnit};

selectPlayer _originalPlayerUnit;

deleteVehicle _currentUnit;
