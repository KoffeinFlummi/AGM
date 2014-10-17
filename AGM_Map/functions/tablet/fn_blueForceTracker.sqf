if (count allMissionObjects "AGM_ModuleBlueForceTracking" > 0) exitWith {};
if (isNil "AGM_BFT_Markers") then {AGM_BFT_Markers = [];};
_markers = [];

if (AGM_TABLET_ISOPEN) then {
	_side = side player;
	while {AGM_TABLET_ISOPEN} do {
		{
			deleteMarkerLocal _x;
			systemChat "del";
		} count _markers;
		_markers = [];
		_groupsside = [allGroups, {side leader _this == _side}] call AGM_Core_fnc_filter;
		systemChat format ["%1", _groupsside];
		for "_i" from 0 to (count _groupsside - 1) do {
			_groupside = _groupsside select _i;
			_markerType = [_groupside] call AGM_Core_fnc_getMarkerType;
			_color = ["ColorGUER", "ColorWEST", "ColorEAST", "ColorCIVILIAN"] select ((["GUER", "WEST", "EAST", "CIVILIAN"] find (str side leader _groupside)) max 0);

			_marker = createMarker ["AGM_BFT_"+(str _i), [(getPos leader _groupside) select 0, (getPos leader _groupside) select 1]];
			_marker setMarkerTypeLocal _markerType;
			_marker setMarkerColorLocal _color;
			_marker setMarkerTextLocal (groupID _groupside);

			_markers = _markers + [_marker];
			
			AGM_BFT_Markers = _markers;
		};
		sleep 1;
	};
} else {
	{
	  	deleteMarkerLocal _x;
	} forEach _markers;
};