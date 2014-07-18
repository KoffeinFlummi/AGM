// by CAA-Picard

#define TEXTURE_WIDTH_IN_M    6205
#define CENTER_OFFSET_Y_PERC  0.1689
#define CONSTANT_SCALE        0.2

// Scale of both parts
_pos          = ((finddisplay 12) displayctrl 51) ctrlMapScreenToWorld [0.5, 0.5];
_screenOffset = ((finddisplay 12) displayctrl 51) posWorldToScreen [(_pos select 0) + 100, (_pos select 1)];
_scale        = TEXTURE_WIDTH_IN_M * CONSTANT_SCALE * ((_screenOffset select 0) - 0.5);
"MapToolFixed" setMarkerSizeLocal [_scale,_scale];
"MapToolRotating" setMarkerSizeLocal [_scale,_scale];

// Position of the fixed part 
_xPos = AGM_MapTools_pos select 0;
_yPos = (AGM_MapTools_pos select 1) + TEXTURE_WIDTH_IN_M * CENTER_OFFSET_Y_PERC;
"MapToolFixed" setMarkerPosLocal [_xPos,_yPos];

// Position and rotation of the rotating part
_xPos = (AGM_MapTools_pos select 0) + sin(AGM_MapTools_angle) * TEXTURE_WIDTH_IN_M * CENTER_OFFSET_Y_PERC;
_yPos = (AGM_MapTools_pos select 1) + cos(AGM_MapTools_angle) * TEXTURE_WIDTH_IN_M * CENTER_OFFSET_Y_PERC;
"MapToolRotating" setMarkerPosLocal [_xPos,_yPos];
"MapToolRotating" setMarkerDirLocal AGM_MapTools_angle;