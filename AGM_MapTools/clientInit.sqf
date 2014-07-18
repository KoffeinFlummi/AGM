// by CAA-Picard

if (!hasInterface) exitWith{};

[] spawn {
  // Wait until the main map display is detected (display = 12)
  waitUntil { !(isNull (findDisplay 12)) };

  // Install key press event handlers on the map display
  //(finddisplay 12) displayAddEventHandler ["onKeydown", {[1, _this] call AGM_MapTools_fnc_handleKeyPress;}];
  //(finddisplay 12) displayAddEventHandler ["onKeyup", {[0, _this] call AGM_MapTools_fnc_handleKeyPress;}];

  // Install mouse event handlers on the map control (control = 51)
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Mousemoving", {_this call AGM_MapTools_fnc_handleMouseMove;}];
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Mousebuttondown", {[1, _this] call AGM_MapTools_fnc_handleMouseButton;}];
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Mousebuttonup", {[0, _this] call AGM_MapTools_fnc_handleMouseButton}];
  // Install draw event on the map control
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Draw", {[] call AGM_MapTools_fnc_updateMapToolMarkers;}];

  // Init variables
  AGM_MapTools_pos = [1000,1000];
  AGM_MapTools_angle = 0;

  AGM_MapTools_dragging = false;
  AGM_MapTools_rotating = false;

  // Create the markers
  AGM_MapTools_mapToolFixed = createMarkerLocal ["MapToolFixed", AGM_MapTools_pos];
  "MapToolFixed" setMarkerType "MapToolFixed";
  AGM_MapTools_mapToolRotating = createMarkerLocal ["MapToolRotating", AGM_MapTools_pos];
  "MapToolRotating" setMarkerType "MapToolRotating";

  // Update the size and rotation
  [] call AGM_MapTools_fnc_updateMapToolMarkers;
};