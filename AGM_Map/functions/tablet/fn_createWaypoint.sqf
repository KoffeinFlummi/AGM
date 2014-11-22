_clickpos = player getVariable ["AGM_Pos_onDbl", []];
_position = ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1201) posScreenToWorld _clickpos;
_selectedGroup = lbCurSel ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622);
_selectedGroup = ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) lbText _selectedGroup;
_index = (random 100) * (random 100);

_type = "AGM_Waypoint";
_color = "ColorBlack";
_text = format["%1", _selectedGroup];
_selectedDir = 0;

_marker = createMarkerLocal [format ["AGM_Waypoint_ID:%1", _index], _position];
_marker setMarkerShapeLocal "ICON";
_marker setMarkerTypeLocal _type;
_marker setMarkerColorLocal _color;
_marker setMarkerTextLocal format ["%1", _text];
_marker setMarkerDir _selectedDir;
//AGM_Tablet_Markers set [count AGM_Tablet_Markers, [_position, format ["AGM_Waypoint_ID:%1", _index], _text, _color, _type, _selectedDir]];
[[_position, _index, _text, _color, _type, _selectedDir], "{AGM_Tablet_Markers set [count AGM_Tablet_Markers, [_this select 0 , format ['GM_Waypoint_ID:%1', _this select 1], _this select 2, _this select 3, _this select 4, _this select 5]];}", 2] call AGM_Core_fnc_execRemoteFnc;

_selectedGroupID = AGM_Waypoint_Names find _selectedGroup;
_selectedGroup_group = AGM_Waypoint_ListBox select _selectedGroupID;

_waypoint =_selectedGroup_group addWaypoint [_position, 0];
AGM_Tablet_Waypoint_Markers = AGM_Tablet_Waypoint_Markers + [_marker];
AGM_Tablet_Waypoint_WP = AGM_Tablet_Waypoint_WP + [_waypoint];

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1619) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1620) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1621) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) ctrlShow false;

lbClear ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622);

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1619) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1620) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1621) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) ctrlCommit 0;