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

  AGM_Map_fnc_installEvents = {
    _d = _this;
    diag_log format ["Installing EH in display %1", _d];
    ((finddisplay _d) displayctrl 51) ctrlAddEventHandler ["MouseMoving", {_this call AGM_Map_fnc_handleMouseMove;}];
    ((finddisplay _d) displayctrl 51) ctrlAddEventHandler ["MouseButtonDown", {[1, _this] call AGM_Map_fnc_handleMouseButton;}];
    ((finddisplay _d) displayctrl 51) ctrlAddEventHandler ["MouseButtonUp", {[0, _this] call AGM_Map_fnc_handleMouseButton}];
    ((finddisplay _d) displayctrl 51) ctrlAddEventHandler ["Draw", {[] call AGM_Map_fnc_updateMapToolMarkers;}];
    (finddisplay _d) displayAddEventHandler ["KeyDown", {_this call AGM_Map_fnc_handleKeyDown;}];
  };

  // Wait until the briefing map is detected
  // display = 37 for SP
  // display = 52 for host server on MP;
  // display = 53 for MP clients)
  waitUntil {(!isNull findDisplay 37) || (!isNull findDisplay 52) || (!isNull findDisplay 53) || (!isNull findDisplay 12)};

  if (isNull findDisplay 12) then {
    // Install event handlers on the map control of the briefing screen (control = 51)
    AGM_Map_syncMarkers = true;
    switch {true} do {
      case (!isNull findDisplay 52) : {52 call AGM_Map_fnc_installEvents;};
      case (!isNull findDisplay 53) : {53 call AGM_Map_fnc_installEvents;};
      default {37 call AGM_Map_fnc_installEvents;};
    };
  } else {
    // Briefing screen was skipped; the player is JIP, create the markers defined during the briefing
    AGM_Map_syncMarkers = false;
    {
      _x call AGM_Map_fnc_addLineMarker;
    } forEach AGM_Map_serverLineMarkers;
  };

  // Wait until the main map display is detected (display = 12)
  waitUntil { !isNull findDisplay 12 };
  // Install event handlers on the map control and display (control = 51)
  AGM_Map_syncMarkers = false;
  12 call AGM_Map_fnc_installEvents;

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