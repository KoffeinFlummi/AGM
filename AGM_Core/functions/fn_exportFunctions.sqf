/*
 * Author: commy2
 *
 * Dumps all functions with given tag to the RPT file.
 * 
 * Argument:
 * 0: Function tag, e.g. "BIS_" (String)
 * 
 * Return value:
 * Nothing
 */

private ["_tag", "_length", "_configFile", "_count", "_index", "_config", "_configTag", "_index1", "_configSub", "_configSubTag", "_path", "_index2", "_function", "_functionName", "_data"];

_tag = _this select 0;

_length = count toArray _tag;
_configFile = configFile >> "CfgFunctions";

_count = count _configFile;
for "_index" from 0 to (_count - 1) do {
	_config = _configFile select _index;

	_configTag = toArray configName _config;
	_configTag resize _length;
	_configTag = toString _configTag;

	if (isClass _config && {_configTag == _tag}) then {
		_count = count _config;
		for "_index1" from 0 to (_count - 1) do {
			_configSub = _config select _index1;
			_configSubTag = configName _configSub;

			_path = getText (_configSub >> "file");

			_count = count _configSub;
			for "_index2" from 0 to (_count - 1) do {
				_function = _configSub select _index2;

				if (isClass _function) then {
					_functionName = configName _function;

					_data = loadFile format ["%1\fn_%2.sqf", _path, _functionName];

					diag_log text "____________________________________________________________________________________________________";
					diag_log text "";
					diag_log text format ["%1_fnc_%2", _configSubTag, _functionName];
					diag_log text "";
					diag_log text _data;
					diag_log text "";
				};
			};
		};
	};
};
