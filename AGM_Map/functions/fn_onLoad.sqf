if (isNil "AGM_Markers") then {AGM_Markers = [];};
if (isNil "AGM_Marker_Selected") then {AGM_Marker_Selected = -1};
AGM_TABLET_ISOPEN = true;
AGM_TABLET_MAPISOPEN = true;
ctrlShow [1612, false];
ctrlShow [1613, false];
[] call AGM_Tab_fnc_showMarkers;