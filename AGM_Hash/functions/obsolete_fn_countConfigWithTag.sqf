// by commy2

private ["_tag", "_length", "_config", "_count", "_hits", "_configFile"];

_tag = _this select 0;
_length = count toArray _tag;

_config = configFile >> "CfgPatches";
_count = count _config;

_hits = 0;
for "_i" from 0 to (_count - 1) do {
	_configFile = toArray configName (_config select _i);
	_configFile resize _length;
	_configFile = toString _configFile;
	if (_configFile == _tag) then {_hits = _hits + 1};
};
_hits
