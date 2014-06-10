/*
 * Author: commy2
 *
 * Get a string from the mission.sqm file. Mission has to be saved in the Editor.
 * 
 * Argument:
 * 0: Path of the entry in the mission.sqm (Array)
 * 
 * Return value:
 * Value of the entry (String)
 */

private ["_path", "_mission", "_a", "_class", "_index", "_array", "_b", "_entry"];

_path = _this;

_mission = toArray toLower loadFile "mission.sqm";
{
	if (_x < 33) then {
		_mission set [_forEachIndex, -1];
	}
} forEach _mission;
_mission = toString (_mission - [-1]);

{_path set [_forEachIndex, toLower _x]} forEach _path;

for "_a" from 0 to (count _path - 2) do {
	_class = format ["class%1{", _path select _a];

	_index = [_class, _mission] call AGM_Core_fnc_findStringInString;

	_array = toArray _mission;
	for "_b" from 0 to (_index + count toArray _class - 1) do {
		_array set [_b, -1];
	};
	_array = _array - [-1];

	_mission = toString _array;
};

_entry = format ["%1=", _path select (count _path - 1)];
_index = [_entry, _mission] call AGM_Core_fnc_findStringInString;
if (_index == -1) exitWith {0};

_array = toArray _mission;
for "_b" from 0 to (_index + count toArray _entry - 1) do {
	_array set [_b, -1];
};
_mission = toString (_array - [-1]);

_index = [";", _mission] call AGM_Core_fnc_findStringInString;

_mission = toArray _mission;
_mission resize _index;
toString _mission;
