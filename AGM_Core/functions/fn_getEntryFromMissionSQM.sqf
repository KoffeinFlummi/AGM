/*
 * Author: commy2
 *
 * Get an entry from the mission.sqm file. Caution: this function is sucks and is really slow.
 * 
 * Argument:
 * 0: Path of the entry in the mission.sqm (Array)
 * 
 * Return value:
 * Value of the entry (String)
 */

private ["_path", "_mission", "_index0", "_index1", "_array1", "_a"];

_path = _this;

_mission = toArray toLower loadFile "mission.sqm";

{
	if (_x < 33) then {
		_mission set [_forEachIndex, -1];
	}
} forEach _mission;
_mission = toString (_mission - [-1]);

{_path set [_forEachIndex, toLower _x]} forEach _path;

_class = format ["class%1{", _path select 0];

//WIP



_index0 = [_class, loadFile "mission.sqm"] call AGM_Core_fnc_findStringInString;
_index1 = ["{", loadFile "mission.sqm"] call AGM_Core_fnc_findStringInString;

_array1 = toArray _mission;
_array1 resize _index1;
for "_a" from 0 to (_index0 - 1) do {
	_array1 set [_a, -1];
};
_array1 = _array1 - [-1];

toString _array1










{_array set [_forEachIndex, toLower _x]} forEach _array; _array

nmn class {

4


Mission

Intel

windForced



;

loadFile "mission.sqm"


