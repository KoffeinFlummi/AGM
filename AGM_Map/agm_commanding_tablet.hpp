#define GUI_GRID_X	(safezoneX)
#define GUI_GRID_Y	(safezoneY)
#define GUI_GRID_W	(safezoneW / 40)
#define GUI_GRID_H	(safezoneH / 25)
#define GUI_GRID_WAbs	(safezoneW)
#define GUI_GRID_HAbs	(safezoneH)


class AGM_RscButtonIn {
	access = 0;
	type = 1;
	text = "";
	colorText[] = {0, 0, 0, 0};
	colorDisabled[] = {0.4, 0.4, 0.4, 0.1};
	colorBackground[] = {0.6, 0.6, 0.6, 0.1};
	colorBackgroundDisabled[] = {0.9, 0.9, 0.9, 0.1};
	colorBackgroundActive[] = {0.5, 0.5, 0.5, 0.1};
	colorFocused[] = {0.6, 0.6, 0.6, 0};
	colorShadow[] = {0, 0, 0, 0};
	colorBorder[] = {0, 0, 0, 0};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.09, 1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.09, 1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1};
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 2;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	borderSize = 0;
};


class AGM_tablet_dlg {
	idd = 4277482;
	movingEnable = true;
	onLoad = "_dlgCommandingTab = _this select 0; {(_dlgCommandingTab displayCtrl _x) ctrlShow false} forEach [2, 9]; uiNamespace setVariable ['AGM_tablet_dlg', _dlgCommandingTab]; [] call AGM_Tab_fnc_onLoad;";
	onUnload = "[] call AGM_Tab_fnc_onUnload;";
	objects[] = {};
	class controlsBackground {

		class background: RscPicture {
			moving = 1;
			idc = 1200;
			text = "AGM_Map\data\agm_commanding_tablet.paa"
			x = 5.71 * GUI_GRID_W + GUI_GRID_X;
			y = -0.74 * GUI_GRID_H + GUI_GRID_Y;
			w = 27.5 * GUI_GRID_W;
			h = 26.5 * GUI_GRID_H;
		};
		class map_screen: RscMapControl {
			idc = 1201;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 9.05 * GUI_GRID_W + GUI_GRID_X;
			y = 7.0 * GUI_GRID_H + GUI_GRID_Y;
			w = 15 * GUI_GRID_W;
			h = 11 * GUI_GRID_H;
			onDraw = "";
			onMouseButtonClick = "[_this select 1, _this select 2, _this select 3, _this select 5] spawn AGM_Tab_fnc_addWaypoint;";
			onMouseButtonDblClick = "[_this select 2, _this select 3] spawn AGM_Tab_fnc_openMarkerMenu"; //[_this select 2, _this select 3] spawn AGM_Tab_fnc_createMarker
		};
	};
	class controls {
		class btn0: AGM_RscButtonIn {
			idc = 1600;
			x = 26.45 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "Blue Force Tracker";
			action = "";
		};
		class btn1: AGM_RscButtonIn {
			idc = 1601;
			x = 27.7 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "UAV Control";
			action = "";
		};
		class btn2: AGM_RscButtonIn {
			idc = 1602;
			x = 28.95 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "Camera";
			action = "";
		};
		class btn3: AGM_RscButtonIn {
			idc = 1603;
			x = 26.45 * GUI_GRID_W + GUI_GRID_X;
			y = 11.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "";
			action = "";
		};
		class btn4: AGM_RscButtonIn {
			idc = 1604;
			x = 27.7 * GUI_GRID_W + GUI_GRID_X;
			y = 11.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "";
			action = "";
		};
		class btn5: AGM_RscButtonIn {
			idc = 1605;
			x = 28.95 * GUI_GRID_W + GUI_GRID_X;
			y = 11.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "";
			action = "";
		};
		class btn6: AGM_RscButtonIn {
			idc = 1606;
			x = 26.45 * GUI_GRID_W + GUI_GRID_X;
			y = 12.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "";
			action = "";
		};
		class btn7: AGM_RscButtonIn {
			idc = 1607;
			x = 27.7 * GUI_GRID_W + GUI_GRID_X;
			y = 12.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "";
			action = "";
		};
		class btn8: AGM_RscButtonIn {
			idc = 1608;
			x = 28.95 * GUI_GRID_W + GUI_GRID_X;
			y = 12.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "";
			action = "";
		};
		class btn9: AGM_RscButtonIn {
			idc = 1609;
			x = 26.45 * GUI_GRID_W + GUI_GRID_X;
			y = 13.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "Delete";
			action = "[0,'delete'] call AGM_Tab_fnc_deleteMarker";
		};
		class btnPrev: AGM_RscButtonIn {
			idc = 1610;
			x = 26.8 * GUI_GRID_W + GUI_GRID_X;
			y = 15.902 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "Prev";
			action = "[-1, 'prev'] call AGM_Tab_fnc_deleteMarker";
		};
		class btnNext: AGM_RscButtonIn {
			idc = 1611;
			x = 28.82 * GUI_GRID_W + GUI_GRID_X;
			y = 15.902 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "Next";
			action = "[1, 'next'] call AGM_Tab_fnc_deleteMarker";
		};
		class BgMarkerCreate: RscText {
			idc = 1615;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 4 * GUI_GRID_W;
			h = 5 * GUI_GRID_H;
			colorBackground[] = {0, 0, 0, 0.7};
		};
		class ButtonOK: RscButton {
			idc = 1612;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.2 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			text = "OK"
			tooltip = "Create Marker";
			action = "[] spawn AGM_Tab_fnc_createMarker"; //_this select 2, _this select 3
		};
		class ButtonCancel: RscButton {
			idc = 1613;
			x = 23 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.2 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			text = "Cancel"
			tooltip = "Cancel";
			action = "ctrlShow [1612, false]; ctrlShow [1613, false]; ctrlShow [1614, false]; ctrlShow [1615, false]; ctrlShow [1616, false]; lbClear 1616; ctrlShow [1617, false]; lbClear 1617; ctrlShow [1618, false];";
		};
		class MarkerName: RscEdit {
			idc = 1614;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.5 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
		};
		class SelectMarkerColor: RscCombo {
			idc = 1616;
			onLBSelChanged = "";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.5 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			sizeEx = 0.025;
   			rowHeight = 0.025;
  			wholeHeight = 8 * 0.025;
		};
		class SelectMarkerType: RscCombo {
			idc = 1617;
			onLBSelChanged = "";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.5 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			sizeEx = 0.025;
   			rowHeight = 0.025;
  			wholeHeight = 8 * 0.025;
		};
		class SelectDirection: RscSlider {
			idc = 1618;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.5 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
		};
		class BgWaypointCreate: RscText {
			idc = 1619;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 4 * GUI_GRID_W;
			h = 5 * GUI_GRID_H;
			colorBackground[] = {0, 0, 0, 0.7};
		};
		class WaypointButtonOK: RscButton {
			idc = 1620;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.2 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			text = "OK"
			tooltip = "Create Waypoint";
			action = "[] spawn AGM_Tab_fnc_createWaypoint"; //_this select 2, _this select 3 [] spawn AGM_Tab_fnc_createMarker
		};
		class WaypointButtonCancel: RscButton {
			idc = 1621;
			x = 23 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.2 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			text = "Cancel"
			tooltip = "Cancel";
			action = "ctrlShow [1619, false]; ctrlShow [1620, false]; ctrlShow [1621, false]; ctrlShow [1622, false]; lbClear 1622;";
		};
		class SelectWaypointGroup: RscCombo {
			idc = 1622;
			onLBSelChanged = "";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.5 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			sizeEx = 0.025;
   			rowHeight = 0.025;
  			wholeHeight = 8 * 0.025;
		};
	};
};