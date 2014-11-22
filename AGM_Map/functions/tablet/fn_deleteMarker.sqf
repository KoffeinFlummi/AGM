private ["_step", "_marker", "_action", "_position"];
_step = _this select 0;
_action = _this select 1;

if ((_action == "delete") && (AGM_Tablet_Marker_Selected > -1) && ((count AGM_Tablet_Markers - 1) >= AGM_Tablet_Marker_Selected)) then {
	_marker = AGM_Tablet_Markers select AGM_Tablet_Marker_Selected select 1;
	hint format ["%1", _marker];
	if(["AGM_Waypoint_ID:", _marker] call AGM_Core_fnc_findStringInString != -1) then {

		{
			_wpGroup = waypoints _x;
			_wpCount = count _wpGroup;

			_markerCount = AGM_Tablet_Waypoint_Markers find _marker;
			_waypointDelete = AGM_Tablet_Waypoint_WP select _markerCount;

			//deleteWaypoint _waypointDelete;
			[_waypointDelete, "{deleteWaypoint _this}", 2] call AGM_Core_fnc_execRemoteFnc;

		} forEach allGroups;

	};
	//deleteMarkerLocal format ["%1", _marker];
	[_marker, "{deleteMarkerLocal _this}", 2] call AGM_Core_fnc_execRemoteFnc;
	AGM_Tablet_Markers set [AGM_Tablet_Marker_Selected, "delete"];
	AGM_Tablet_Markers = AGM_Tablet_Markers - ["delete"];
	AGM_Tablet_Marker_Selected = AGM_Tablet_Marker_Selected - 1;
	_markerselect = player getVariable ["AGM_Tablet_Marker_Select", []];
	if (AGM_Tablet_Marker_Selected > -1) then {
		_position = AGM_Tablet_Markers select AGM_Tablet_Marker_Selected select 0;
		if (_markerselect != "[]") then {
			_markerselect setMarkerPos _position;
		};
	} else {
		deleteMarkerLocal _markerselect;
		player setVariable ["AGM_Tablet_Marker_Select", []];
	};
} else {
	AGM_Tablet_Marker_Selected = AGM_Tablet_Marker_Selected + (_step);
	if (AGM_Tablet_Marker_Selected < -1) exitWith {
		AGM_Tablet_Marker_Selected = -1;
		_markerselect = player getVariable ["AGM_Tablet_Marker_Select", []];
		deleteMarkerLocal _markerselect;
	};
	if ((count AGM_Tablet_Markers - 1) < AGM_Tablet_Marker_Selected) exitWith {
		AGM_Tablet_Marker_Selected = 0;
		_position = AGM_Tablet_Markers select AGM_Tablet_Marker_Selected select 0;
		_markerselect = player getVariable ["AGM_Tablet_Marker_Select", []];
		_markerselect setMarkerPosLocal _position;
	};
	_position = AGM_Tablet_Markers select AGM_Tablet_Marker_Selected select 0;
	_markerselect = player getVariable ["AGM_Tablet_Marker_Select", []];
	if (format ["%1", _markerselect] == "[]" && AGM_Tablet_Marker_Selected > -1) then {
		_marker = createMarkerLocal ["selected", _position];
		_marker setMarkerShapeLocal "ICON";
		_marker setMarkerTypeLocal "Select";
		_marker setMarkerColorLocal "ColorRed";
		_markerselect = _marker;
		
		player setVariable ["AGM_Tablet_Marker_Select", _markerselect];
	} else {
		_markerselect setMarkerPos _position;
	};
};