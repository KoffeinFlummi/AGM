// by CAA-Picard

if (!hasInterface) exitWith{};

[] spawn {
  // Init variables
  AGM_Map_mapToolsShown = 0;
  AGM_Map_pos = [0,0];
  AGM_Map_angle = 0;
  AGM_Map_dragging = false;
  AGM_Map_rotating = false;
  AGM_Map_mapGpsShow = true;
  AGM_Map_drawing = false;
  AGM_Map_tempLineMarker = [];
  AGM_Map_lineMarkers = [];
  AGM_Map_drawColor = "ColorBlack";
  AGM_Map_drawingControls = [36732, 36733, 36734, 36735, 36736, 36737];

  // Wait until the main map display is detected (display = 12)
  waitUntil { !(isNull (findDisplay 12)) };

  // Hide draw buttons
  { ((finddisplay 12) displayctrl _x) ctrlShow false; } forEach AGM_Map_drawingControls;

  // Install mouse event handlers on the map control (control = 51)
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["MouseMoving", {_this call AGM_Map_fnc_handleMouseMove;}];
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["MouseButtonDown", {[1, _this] call AGM_Map_fnc_handleMouseButton;}];
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["MouseButtonUp", {[0, _this] call AGM_Map_fnc_handleMouseButton}];
  //((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["MouseZChanged", {_this call AGM_Map_fnc_handleMouseZChanged}];
  // Install draw event on the map control
  ((finddisplay 12) displayctrl 51) ctrlAddEventHandler ["Draw", {[] call AGM_Map_fnc_updateMapToolMarkers;}];

  // Install key press event handlers on the map display
  (finddisplay 12) displayAddEventHandler ["KeyDown", {_this call AGM_Map_fnc_handleKeyDown;}];
  //(finddisplay 12) displayAddEventHandler ["onKeyup", {[0, _this] call AGM_Map_fnc_handleKeyPress;}];

  // Update the size and rotation of map tools
  [] call AGM_Map_fnc_updateMapToolMarkers;

  while {true} do {
    waitUntil {visibleMap};

    // Show and update map tools if required
    [] call AGM_Map_fnc_updateMapToolMarkers;
    // Show GPS if required
    [AGM_Map_mapGpsShow] call AGM_Map_fnc_openMapGps;

    // Update visibility of maptools and gps, handling inventory changes
    [] spawn {
      while {visibleMap} do {

        //[AGM_Map_mapGpsShow] call AGM_Map_fnc_openMapGps;

        // Show/Hide draw buttons
        if ("AGM_MapTools" in items player) then {
          { ((finddisplay 12) displayctrl _x) ctrlShow true; } forEach AGM_Map_drawingControls;
        } else {
          { ((finddisplay 12) displayctrl _x) ctrlShow false; } forEach AGM_Map_drawingControls;
          if (AGM_Map_drawing) then {
            call AGM_Map_fnc_cancelDrawing;
          };
        };
        sleep 1;
      };
    };

    waitUntil {!visibleMap};

    // Hide GPS
    [false] call AGM_Map_fnc_openMapGps;
    // Hide Map tools
    deleteMarkerLocal "MapToolFixed";
    deleteMarkerLocal "MapToolRotatingNormal";
    deleteMarkerLocal "MapToolRotatingSmall";
    AGM_Map_mapToolFixed = nil;
    AGM_Map_mapToolRotatingNormal = nil;
    AGM_Map_mapToolRotatingSmall = nil;
    // Cancel drawing
    call AGM_Map_fnc_cancelDrawing;
  };
};