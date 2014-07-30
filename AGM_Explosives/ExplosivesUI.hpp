#define GUI_GRID_X (0)
#define GUI_GRID_Y (0)
#define GUI_GRID_W (0.025)
#define GUI_GRID_H (0.04)

#define ST_CENTER 0x02

class RscPicture;
class RscText;
class RscButton;
class RscEdit;

class RscAGM_CallScreen_Edit:RscEdit
{
	canModify = 1;
	colorBackground[] = {0,0,0,1};
	colorText[] = {0,0,0,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelection[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		1
	};
	text = "";
	style = "0x00 + 0x40 + 0x200";
	shadow = 1;
	SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) * 1)";
	x = 0.288594 * safezoneW + safezoneX;
	w = 0.0825 * safezoneW;
	h = 0.044 * safezoneH;
};
class RscAGM_HiddenButton:RscButton
{
	colorText[] = {0, 0, 0, 0};
	colorDisabled[] = {0, 0, 0, 0};
	colorBackground[] = {0, 0, 0, 0};
	colorBackgroundDisabled[] = {0, 0, 0, 0};
	colorBackgroundActive[] = {0, 0, 0, 0};
	colorFocused[] = {0, 0, 0, 0};
	colorShadow[] = {0, 0, 0, 0};
	colorBorder[] = {0, 0, 0, 0};
	w = 0.095589;
	h = 0.039216;
	shadow = 0;
};

#include "UI\PhoneInterface.hpp"
#define X_OFFSET 0.25

class RscXSliderH;
class IGUIBack;

class Rsc_AGM_Timer_Slider:RscXSliderH{
    x = 0.4; 
    y = 0.2; 
    w = 0.3; 
    h = "1*((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = {0,0,0,0.5};
};

class RscAGM_SelectTimeUI
{
	idd = 8854;
	movingEnable = 0;
	class controls {
		class back:IGUIBack {
			x = X_OFFSET;
			y = 0;
			w = 0.5;
			h = 0.2;
			colorBackground[] = {0, 0, 0, 0.5};
		};
		class header: RscText{
			idc = 8870;
			x = X_OFFSET + 0.005;
			y = 0.005;
			w = 0.49;
			h = 0.05;
			style = ST_CENTER;
			text = "";
		};
		class slider: Rsc_AGM_Timer_Slider {
			idc = 8845;
			x = X_OFFSET + 0.005;
			y = 0.06;
			w = 0.49;
			h = 0.025;
			onSliderPosChanged = "private ['_mins', '_secs'];_mins = floor((_this select 1)/60);_secs=floor((_this select 1) - (_mins*60));ctrlSetText [8870, format[localize 'STR_AGM_Explosives_TimerMenu',_mins, _secs]];";
		};
		class cancelBtn: RscButton {
			idc = 8855;
			x = X_OFFSET + 0.005;
			w = 0.15;
			h = 0.1;
			y = 0.09;
			text = $STR_AGM_Explosives_Cancel;
			action = "closeDialog 0;";
		};
		class approveBtn: RscButton {
			idc = 8860;
			x = X_OFFSET + 0.345;
			y = 0.09;
			h = 0.1;
			w = 0.15;
			text = $STR_AGM_Explosives_SetTime;
			action = "closeDialog 0;";
		};
	};
};