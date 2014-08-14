// by CAA-Picard

if (!hasInterface) exitWith{};

[] spawn {
  // Wait until the main map display is detected (display = 12)
  waitUntil { !(isNull (findDisplay 12)) };

  // Install key press event handlers on the map display
  //(finddisplay 12) displayAddEventHandler ["onKeydown", {[1, _this] call AGM_Map_fnc_handleKeyPress;}];
  //(finddisplay 12) displayAddEventHandler ["onKeyup", {[0, _this] call AGM_Map_fnc_handleKeyPress;}];

  // Install mouse event handlers on the map control (control = 51)
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Mousemoving", {_this call AGM_Map_fnc_handleMouseMove;}];
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Mousebuttondown", {[1, _this] call AGM_Map_fnc_handleMouseButton;}];
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Mousebuttonup", {[0, _this] call AGM_Map_fnc_handleMouseButton}];
  // Install draw event on the map control
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Draw", {[] call AGM_Map_fnc_updateMapToolMarkers;}];

  // Init variables
  AGM_Map_mapToolsShown = 0;
  AGM_Map_pos = [0,0];
  AGM_Map_angle = 0;
  AGM_Map_dragging = false;
  AGM_Map_rotating = false;

  // Update the size and rotation
  [] call AGM_Map_fnc_updateMapToolMarkers;

  while {true} do {
    waitUntil {visibleMap};
    [] call AGM_Map_fnc_updateMapToolMarkers;

    waitUntil {!visibleMap};
    deleteMarkerLocal "MapToolFixed";
    deleteMarkerLocal "MapToolRotatingNormal";
    deleteMarkerLocal "MapToolRotatingSmall";
    AGM_Map_mapToolFixed = nil;
    AGM_Map_mapToolRotatingNormal = nil;
    AGM_Map_mapToolRotatingSmall = nil;
  };
};