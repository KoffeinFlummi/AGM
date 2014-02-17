/*
BWA3 function, by commy2
this code is property of the ArmA 3 Bundeswehr modification
ask us nicely at http://www.bwmod.de/ if you want to re-use any of this script
we don't support changed code based on this work
*/

private ["_config", "_count", "_array", "_a", "_configEntry", "_index", "_number", "_hash"];

_config = configFile >> "CfgPatches";
_count = count _config;

_array = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

for "_a" from 0 to (_count - 1) do {
	_configEntry = _config select _a;
	{
		_index = _forEachIndex mod 16;
		_number = _array select _index;
		_number = (_number + _x) mod 16;
		_array set [_index, _number];
	} forEach (toArray str _configEntry);
};

_hash = "";
{
	_number = _x call BWA3_Core_fnc_toHex;
	_hash = _hash + _number;
} forEach _array;
_hash
