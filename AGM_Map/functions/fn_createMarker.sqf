private "_time";
_position = ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1201) posScreenToWorld _this;
_index = (random 100) * (random 100);

if ((date select 4) < 10) then {
	_time = format["%1:0%2", date select 3, date select 4];
	hint format ["%1", _time];
} else {
	_time = format["%1:%2", date select 3, date select 4];
	hint format ["%1", _time];
};
//_time = format ["%1:%2", (date select 3), (date select 4)];
_marker = createMarkerLocal [format ["AGM_Marker_ID:%1", _index], _position];
_marker setMarkerShapeLocal "ICON";
_marker setMarkerTypeLocal "mil_dot";
_marker setMarkerColorLocal "ColorRed";
_marker setMarkerTextLocal format ["%1", _time];
AGM_Markers set [count AGM_Markers, [_position, format ["AGM_Marker_ID:%1", _index], _time]];  