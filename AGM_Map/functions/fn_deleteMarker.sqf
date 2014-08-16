private ["_step", "_marker", "_action", "_position"];
_step = _this select 0;
_action = _this select 1;

if ((_action == "delete") && (AGM_Marker_Selected > -1) && ((count AGM_Markers - 1) >= AGM_Marker_Selected)) then {
	_marker = AGM_Markers select AGM_Marker_Selected select 1;
	deleteMarkerLocal format ["%1", _marker];
	AGM_Markers set [AGM_Marker_Selected, "delete"];
	AGM_Markers = AGM_Markers - ["delete"];
	AGM_Marker_Selected = AGM_Marker_Selected - 1;
	_markerselect = player getVariable ["AGM_Marker_Select", []];
	if (AGM_Marker_Selected > -1) then {
		_position = AGM_Markers select AGM_Marker_Selected select 0;
		if (_markerselect != "[]") then {
			_markerselect setMarkerPos _position;
		};
	} else {
		deleteMarkerLocal _markerselect;
		player setVariable ["AGM_Marker_Select", []];
		hint "d";
	};
} else {
	AGM_Marker_Selected = AGM_Marker_Selected + (_step);
	if (AGM_Marker_Selected < -1) exitWith {
		AGM_Marker_Selected = -1;
		_markerselect = player getVariable ["AGM_Marker_Select", []];
		deleteMarkerLocal _markerselect;
		hint "delete";
	};
	if ((count AGM_Markers - 1) < AGM_Marker_Selected) exitWith {
		AGM_Marker_Selected = 0;
		_position = AGM_Markers select AGM_Marker_Selected select 0;
		_markerselect = player getVariable ["AGM_Marker_Select", []];
		_markerselect setMarkerPosLocal _position;
		hint "delete";
	};
	_position = AGM_Markers select AGM_Marker_Selected select 0;
	_markerselect = player getVariable ["AGM_Marker_Select", []];
	if (format ["%1", _markerselect] == "[]" && AGM_Marker_Selected > -1) then {
		_marker = createMarkerLocal ["selected", _position];
		_marker setMarkerShapeLocal "ICON";
		_marker setMarkerTypeLocal "mil_circle";
		_marker setMarkerColorLocal "ColorRed";
		_markerselect = _marker;
		
		player setVariable ["AGM_Marker_Select", _markerselect];
	} else {
		_markerselect setMarkerPos _position;
		hint "this";
	};
};