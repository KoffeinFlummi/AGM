// by commy2

_this spawn {
	_unit = _this select 0;
	_side = _this select 1;

	_rallypoint = [objNull, AGM_Rallypoint_West, AGM_Rallypoint_East, AGM_Rallypoint_Independent] select ([west, east, independent] find _side) + 1;

	if (isNull _rallypoint) exitWith {};

	_position = getPosATL player;
	_position = _position findEmptyPosition [0, 2, typeOf _rallypoint];
	if (count _position == 0) then {_position = getPosATL player};

	_position set [2, 0];

	["Deploy in 5 seconds ..."] call AGM_Core_fnc_displayTextStructured;

	sleep 5;
	_rallypoint setPosATL _position;

	/*
	_marker = format ["AGM_RallyPoint_%1", _side];
	_marker setMarkerPos _position;
	_marker setMarkerTextLocal format ["%1:%2", [date select 3, 2, 0] call CBA_fnc_FORMATNumber, [date select 4, 2, 0] call CBA_fnc_FORMATNumber];
	*/

	["Rallypoint deployed"] call AGM_Core_fnc_displayTextStructured;
};
