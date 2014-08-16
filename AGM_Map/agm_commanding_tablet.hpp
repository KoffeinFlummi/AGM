#define GUI_GRID_X	(safezoneX)
#define GUI_GRID_Y	(safezoneY)
#define GUI_GRID_W	(safezoneW / 40)
#define GUI_GRID_H	(safezoneH / 25)
#define GUI_GRID_WAbs	(safezoneW)
#define GUI_GRID_HAbs	(safezoneH)


class AGM_tablet_dlg {
	idd = 4277482;
	movingEnable = true;
	onLoad = "_dlgCommandingTab = _this select 0; {(_dlgCommandingTab displayCtrl _x) ctrlShow false} forEach [2, 9]; uiNamespace setVariable ['AGM_tablet_dlg', _dlgCommandingTab]; [] call AGM_Tab_fnc_onLoad;";
	onUnload = "[] call AGM_Tab_fnc_onUnload;";
	objects[] = {};
	class controlsBackground {

		class background: AGM_RscPictures {
			moving = 1;
			idc = 1200;
			text = "AGM_Map\data\agm_commanding_tablet.paa"
			x = 5.71 * GUI_GRID_W + GUI_GRID_X;
			y = -0.74 * GUI_GRID_H + GUI_GRID_Y;
			w = 27.5 * GUI_GRID_W;
			h = 26.5 * GUI_GRID_H;
		};
		class map_screen: AGM_RscMapControl {
			idc = 1201;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 9.05 * GUI_GRID_W + GUI_GRID_X;
			y = 7.0 * GUI_GRID_H + GUI_GRID_Y;
			w = 15 * GUI_GRID_W;
			h = 11 * GUI_GRID_H;
			onDraw = "";
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
			tooltip = "Blue Force Tracker";
			action = "";
		};
		class btn4: AGM_RscButtonIn {
			idc = 1604;
			x = 27.7 * GUI_GRID_W + GUI_GRID_X;
			y = 11.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "UAV Control";
			action = "";
		};
		class btn5: AGM_RscButtonIn {
			idc = 1605;
			x = 28.95 * GUI_GRID_W + GUI_GRID_X;
			y = 11.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "Camera";
			action = "";
		};
		class btn6: AGM_RscButtonIn {
			idc = 1606;
			x = 26.45 * GUI_GRID_W + GUI_GRID_X;
			y = 12.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "Blue Force Tracker";
			action = "";
		};
		class btn7: AGM_RscButtonIn {
			idc = 1607;
			x = 27.7 * GUI_GRID_W + GUI_GRID_X;
			y = 12.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "UAV Control";
			action = "";
		};
		class btn8: AGM_RscButtonIn {
			idc = 1608;
			x = 28.95 * GUI_GRID_W + GUI_GRID_X;
			y = 12.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			tooltip = "Camera";
			action = "";
		};
		class btn9: AGM_RscButtonIn {
			idc = 1609;
			x = 27.7 * GUI_GRID_W + GUI_GRID_X;
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
	};
	class marker_control {
		class ButtonOK: AGM_RscButton {
			idc = 1612;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			text = "OK"
			tooltip = "Create Marker";
			action = "[_this select 2, _this select 3] spawn AGM_Tab_fnc_createMarker";
		};
		class ButtonCancel: AGM_RscButton {
			idc = 1613;
			x = 23 * GUI_GRID_W + GUI_GRID_X;
			y = 10.241 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.8 * GUI_GRID_W;
			h = 0.7 * GUI_GRID_H;
			text = "Cancel"
			tooltip = "Cancel";
			action = "";
		};
	};
};