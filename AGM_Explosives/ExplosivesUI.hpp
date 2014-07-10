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

class RscListbox;
class IGUIBack;
class RscStructuredText;

#include "Interfaces\PhoneInterface.hpp"

class RscAGM_SelectAnItem
{
	idd = 8854;
	movingEnable = 0;
	class controls {
		class back:IGUIBack {
			x = 0;
			y = 0;
			w = 0.4;
			h = 0.655;
		};
		class itemList:RscListBox {
			idc = 8866;
			x = 0.005;
			w = 0.39;
			h = 0.54;
			y = 0.005;
		};
		class cancelBtn: RscButton {
			idc = 8855;
			x = 0.005;
			w = 0.15;
			h = 0.1;
			y = 0.55;
			text = "Cancel";
			action = "closeDialog 0;";
		};
		class approveBtn: RscButton {
			idc = 8860;
			x = 0.245;
			y = 0.55;
			h = 0.1;
			w = 0.15;
			text = "Approve";
			action = "closeDialog 0;";
		};
	};
};