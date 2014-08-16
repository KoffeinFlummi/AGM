hint format ["%1", AGM_TABLET_ISOPEN];
if (AGM_TABLET_ISOPEN) then {
	hint "Open";
	{
		_marker = createMarkerLocal [_x select 1, _x select 0];
		_marker setMarkerShapeLocal "ICON";
		_marker setMarkerTypeLocal "mil_dot";
		_marker setMarkerColorLocal "ColorRed";
		_marker setMarkerTextLocal format ["%1", _x select 2];
	} forEach AGM_Markers;
} else {
	hint "Close";
	{
	  	deleteMarkerLocal  format ["%1", _x select 1];
	} forEach AGM_Markers;
};