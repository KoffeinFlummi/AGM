if (isNil "AGM_Tablet_Markers") then {AGM_Tablet_Markers = [];};
if (isNil "AGM_Tablet_Marker_Selected") then {AGM_Tablet_Marker_Selected = -1};
if (isNil "AGM_Tablet_Waypoint_Markers") then {AGM_Tablet_Waypoint_Markers = [];};
if (isNil "AGM_Tablet_Waypoint_WP") then {AGM_Tablet_Waypoint_WP = [];};
AGM_TABLET_ISOPEN = true;
AGM_TABLET_MAPISOPEN = true;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1612) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1613) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1615) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618) ctrlShow false;

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1619) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1620) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1621) ctrlShow false;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) ctrlShow false;


((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1612) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1613) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1615) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618) ctrlCommit 0;

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1619) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1620) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1621) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) ctrlCommit 0;

[] call AGM_Tab_fnc_showMarkers;
[] spawn AGM_Tab_fnc_blueForceTracker;