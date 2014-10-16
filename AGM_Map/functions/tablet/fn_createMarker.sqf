private ["_time", "_color"];
_clickpos = player getVariable ["AGM_Pos_onDbl", []];
_position = ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1201) posScreenToWorld _clickpos;
_index = (random 100) * (random 100);
_text = ctrlText ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614);
_selectedColor = lbCurSel ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616);
_selectedColor = ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) lbText _selectedColor;
_selectedType = lbCurSel ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617);
_selectedType = ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) lbText _selectedType;
_selectedDir = sliderPosition ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618);

_color = (switch (_selectedColor) do {
	case "Black" : {"ColorBlack"};
	case "Yellow" : {"ColorYellow"};
	case "BLUFOR" : {"ColorWEST"};
	case "OPFOR" : {"ColorEAST"};
	case "INDEPENDENT" : {"ColorGUER"};
	case "CIVILIAN" : {"ColorCIV"};
	default {"ColorBlack"};
});

_type = (switch (_selectedType) do {
	case "Dot" : {"mil_dot"};
	case "Infantery" : {"b_inf"};
	case "Armored" : {"b_armor"};
	case "Aircraft" : {"b_air"};
	case "Pick Up" : {"mil_pickup"};
	case "Ambush" : {"mil_ambush"};
	case "Destroy" : {"mil_destroy"};
	default {"mil_dot"};
});

if ((date select 4) < 10) then {
	_time = format["%1:0%2", date select 3, date select 4];
} else {
	_time = format["%1:%2", date select 3, date select 4];
};
//_time = format ["%1:%2", (date select 3), (date select 4)];
_marker = createMarkerLocal [format ["AGM_Marker_ID:%1", _index], _position];
_marker setMarkerShapeLocal "ICON";
_marker setMarkerTypeLocal _type;
_marker setMarkerColorLocal _color;
_marker setMarkerTextLocal format ["%1", _text];
_marker setMarkerDir _selectedDir;
AGM_Tablet_Markers set [count AGM_Tablet_Markers, [_position, format ["AGM_Marker_ID:%1", _index], _text, _color, _type, _selectedDir]]; //_type geht in showMarker nicht 

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1612) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1613) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1615) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618) ctrlShow false;

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614) ctrlSetText "";
lbClear ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616);
lbClear ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617);

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1612) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1613) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1615) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618) ctrlCommit 0;