if (AGM_TABLET_ISOPEN) then {
	{
		_marker = createMarkerLocal [_x select 1, _x select 0];
		_marker setMarkerShapeLocal "ICON";
		_marker setMarkerTypeLocal (_x select 4);
		_marker setMarkerColorLocal (_x select 3);
		_marker setMarkerTextLocal format ["%1", _x select 2];
		_marker setMarkerDir (_x select 5);
	} forEach AGM_Tablet_Markers;
	_position = AGM_Tablet_Markers select AGM_Tablet_Marker_Selected select 0;
	_markerselect = createMarkerLocal ["selected", _position];
	_markerselect setMarkerShapeLocal "ICON";
	_markerselect setMarkerTypeLocal "Select";
	_markerselect setMarkerColorLocal "ColorRed";
} else {
	{
	  	deleteMarkerLocal  format ["%1", _x select 1];
	} forEach AGM_Tablet_Markers;
	
	_markerselect = player getVariable ["AGM_Tablet_Marker_Select", []];
	deleteMarkerLocal _markerselect;
};