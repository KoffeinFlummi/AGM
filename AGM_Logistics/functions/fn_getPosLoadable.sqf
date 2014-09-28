/*
by PabstMirror

Right now, when you load a crate into a vehicle, the crate moves to [-1000, -1000] (check past the SW corner of the map and it's marker should be there)

to get it's real pos you'll need a custom getPos, something like this (sorry not tested)

if the crate is "loaded" into a vehicle, then use it's pos instead of the cratess 
*/

private "_theCrate";

_theCrate = _this select 0;
{
	if (_theCrate in (_x getVariable ["AGM_Logistics_loadedItems", []])) then {
		_theCrate = _x;
	};
} forEach vehicles;

(getPos _theCrate)
