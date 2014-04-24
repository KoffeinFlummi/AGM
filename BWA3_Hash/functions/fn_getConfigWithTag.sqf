// by commy2

private ["_tag", "_length", "_config", "_count", "_hits", "_configFile"];

_tag = _this select 0;
_length = count toArray _tag;

_config = configFile >> "CfgPatches";
_count = count _config;

_hits = [];
for "_i" from 0 to (_count - 1) do {
	_configFile = toArray configName (_config select _i);
	_configFile resize _length;
	_configFile = toString _configFile;
	if (_configFile == _tag) then {_hits set [count _hits, _config select _i]};
};
_hits

/* GET CONFIG VERSION
;
{
	_hits set [_forEachIndex, getText (_x >> "Version")];
} forEach _hits;
_hits
*/


/* GET CONFIG NAMES ARRAY
;
{
	_hits set [_forEachIndex, configName _x];
} forEach _hits;
*/
