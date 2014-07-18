/*
 * Author: CAA-Picard
 *
 * Update the map tool markers, position, size, rotation and visibility.
 *
 * Argument:
 * None
 *
 * Return value:
 * Nothing
 */

#define TEXTURE_WIDTH_IN_M    6205
#define CENTER_OFFSET_Y_PERC  0.1606
#define CONSTANT_SCALE        0.2

if !("AGM_MapTools" in items player) exitWith {
  // If markers exist, delete them
  if (!isNil "AGM_Map_mapToolFixed") then {
    deleteMarkerLocal "MapToolFixed";
    deleteMarkerLocal "MapToolRotating";
    deleteMarkerLocal "MapToolFixed";
    AGM_Map_mapToolFixed = nil;
    AGM_Map_mapToolRotating = nil;
  };
};

// If markers don't exist, create them
if (isNil "AGM_Map_mapToolFixed") then {
  // Create the markers
  AGM_Map_mapToolFixed = createMarkerLocal ["MapToolFixed", AGM_Map_pos];
  AGM_Map_mapToolRotating = createMarkerLocal ["MapToolRotating", AGM_Map_pos];
  "MapToolFixed" setMarkerType "MapToolFixed";
  "MapToolRotating" setMarkerType "MapToolRotating";
};

// Update scale of both parts
_pos          = ((finddisplay 12) displayctrl 51) ctrlMapScreenToWorld [0.5, 0.5];
_screenOffset = ((finddisplay 12) displayctrl 51) posWorldToScreen [(_pos select 0) + 100, (_pos select 1)];
_scale        = TEXTURE_WIDTH_IN_M * CONSTANT_SCALE * ((_screenOffset select 0) - 0.5);
"MapToolFixed" setMarkerSizeLocal [_scale,_scale];
"MapToolRotating" setMarkerSizeLocal [_scale,_scale];

// Position of the fixed part
_xPos = AGM_Map_pos select 0;
_yPos = (AGM_Map_pos select 1) + TEXTURE_WIDTH_IN_M * CENTER_OFFSET_Y_PERC;
"MapToolFixed" setMarkerPosLocal [_xPos,_yPos];

// Position and rotation of the rotating part
_xPos = (AGM_Map_pos select 0) + sin(AGM_Map_angle) * TEXTURE_WIDTH_IN_M * CENTER_OFFSET_Y_PERC;
_yPos = (AGM_Map_pos select 1) + cos(AGM_Map_angle) * TEXTURE_WIDTH_IN_M * CENTER_OFFSET_Y_PERC;
"MapToolRotating" setMarkerPosLocal [_xPos,_yPos];
"MapToolRotating" setMarkerDirLocal AGM_Map_angle;