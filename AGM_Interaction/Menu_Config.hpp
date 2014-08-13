
#define HSPACE 0.5-2.0/16/2
#define VSPACE 0.5-0.3/9/2

class AGM_Interaction_Button_Base {
  tooltip = "";
  action = "AGM_Interaction_isMousePressed = true;(findDisplay 1713999) closeDisplay 1;_action = AGM_Interaction_Buttons select AGM_Interaction_SelectedButton;AGM_Interaction_SelectedButton = -1; if (call (_action select 2)) then {call (_action select 1)};"; 

  idc = -1;
  access = 0;
  type = 1;
  text = "";
  font = "PuristaMedium";
  //sizeEx = "1 / 40 / (getResolution select 5) / (16 / 9) * (getResolution select 4)";
  sizeEx = "0.8 / 40 / (getResolution select 5)";// * safezoneX / safezoneXAbs";
  shadow = 2;

  style = 2;
  x = 0;
  y = 0;
  w = 2.0 / 16 * safezoneW;
  h = 0.3 / 9 * safezoneH;

  offsetX = 0.003;
  offsetY = 0.003;
  offsetPressedX = 0.002;
  offsetPressedY = 0.002;
  borderSize = 0;

  colorText[] = {1,1,1,1};
  colorDisabled[] = {0.5,0.5,0.5,1};
  colorBackground[] = {0,0,0,0.8};
  colorBackgroundDisabled[] = {0,0,0,0.8};
  colorBackgroundActive[] = {1,1,1,0.8};
  colorFocused[] = {1,1,1,0.8};
  colorShadow[] = {0,0,0,0};
  colorBorder[] = {1,1,1,0.8};

  soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
  soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
  soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
  soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
};

class AGM_Interaction_Dialog {
  idd = 1713999;
  enableSimulation = 1;
  movingEnable = 0;
  onLoad = "_dlgInteractionDialog = _this select 0; for '_a' from 10 to 19 do {(_dlgInteractionDialog displayCtrl _a) ctrlShow false}; uiNamespace setVariable ['AGM_Interaction_Dialog', _dlgInteractionDialog];";
  onUnload = "uiNamespace setVariable ['AGM_Interaction_Dialog', objNull];";
  objects[] = {};
  class controls {
    /*
    class Interaction_AGM_Logo : AGM_Interaction_Button_Base {
      action = "call AGM_Interaction_fnc_hideMenu;";
      type = 0;
      style = 48;
      //onMouseEnter = "hint ('_' + str(_this))";
      tooltip = "";
      text = "\AGM_common\rsc\bwlogo.paa";
      idc = 2;
      x = (0.5-1.0/16/2 + 0 * 0.1) * safezoneW + safezoneX;
      y = (0.5-1.0/9/2 + 0 * 0.04) * safezoneH + safezoneY;
      w = 1.0 / 16 * safezoneW;
      h = 1.0 / 9 * safezoneH;
    };
    */
    class Interaction_ButtonMain : AGM_Interaction_Button_Base {
      action = "AGM_Interaction_isMousePressed = true;(findDisplay 1713999) closeDisplay 1; call AGM_Interaction_MainButton; AGM_Interaction_SelectedButton = -1;";
      onMouseEnter = "AGM_Interaction_SelectedButton = -1; ctrlSetFocus (_this select 0);";
      text = "Interaction Menu";
      idc = 2;
      //sizeEx = "0.8 / 40 / (getResolution select 5) / (16 / 9) * (getResolution select 4)";
      sizeEx = "0.6 / 40 / (getResolution select 5)";// * safezoneX / safezoneXAbs";
      x = (0.5-1.8/16/2 + 0 * 0.1) * safezoneW + safezoneX;
      y = (0.5-0.55/9/2 + 0 * 0.04) * safezoneH + safezoneY;
      w = 1.8 / 16 * safezoneW;
      h = 0.55 / 9 * safezoneH;
    };

    class Interaction_Button0 : AGM_Interaction_Button_Base {
      onMouseEnter = "AGM_Interaction_SelectedButton = 0; ctrlSetFocus (_this select 0);";
      idc = 10;
      x = (HSPACE + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 2.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button1 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 1; ctrlSetFocus (_this select 0);";
      idc = 11;
      x = (HSPACE + 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 1.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button2 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 2; ctrlSetFocus (_this select 0);";
      idc = 12;
      x = (HSPACE + 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 0.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button3 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 3; ctrlSetFocus (_this select 0);";
      idc = 13;
      x = (HSPACE + 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 0.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button4 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 4; ctrlSetFocus (_this select 0);";
      idc = 14;
      x = (HSPACE + 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 1.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button5 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 5; ctrlSetFocus (_this select 0);";
      idc = 15;
      x = (HSPACE + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 2.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button6 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 6; ctrlSetFocus (_this select 0);";
      idc = 16;
      x = (HSPACE - 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 1.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button7 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 7; ctrlSetFocus (_this select 0);";
      idc = 17;
      x = (HSPACE - 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 0.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button8 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 8; ctrlSetFocus (_this select 0);";
      idc = 18;
      x = (HSPACE - 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 0.5 * 0.04) * safezoneH + safezoneY;
    };

    class Interaction_Button9 : Interaction_Button0 {
      onMouseEnter = "AGM_Interaction_SelectedButton = 9; ctrlSetFocus (_this select 0);";
      idc = 19;
      x = (HSPACE - 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 1.5 * 0.04) * safezoneH + safezoneY;
    };

    /*class Interaction_Icon0 : Interaction_Button0 {
      idc = 20;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon1 : Interaction_Button1 {
      idc = 21;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon2 : Interaction_Button2 {
      idc = 22;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon3 : Interaction_Button3 {
      idc = 23;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon4 : Interaction_Button4 {
      idc = 24;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon5 : Interaction_Button5 {
      idc = 25;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon6 : Interaction_Button6 {
      idc = 26;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon7 : Interaction_Button7 {
      idc = 27;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon8 : Interaction_Button8 {
      idc = 28;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };

    class Interaction_Icon9 : Interaction_Button9 {
      idc = 29;
      type = 0;
      style = 48;
      colorBackground[] = {0,0,0,0};
      w = 0.3 / 16 * safezoneW;
    };*/

  };
};

class RscListbox;
class IGUIBack;
class RscText;
#define X_OFFSET 0.2

class RscAGM_SelectAnItem {
	idd = 8854;
	movingEnable = 0;
	class controls {
		class back:IGUIBack {
			x = X_OFFSET;
			y = 0;
			w = 0.6;
			h = 0.71;
			colorBackground[] = {0, 0, 0, 0.5};
		};
		class header: RscText{
			idc = 8870;
			x = X_OFFSET + 0.005;
			y = 0.005;
			w = 0.59;
			h = 0.05;
			style = 0x02;
			text = "";
		};
		class itemList:RscListBox {
			idc = 8866;
			x = X_OFFSET + 0.005;
			w = 0.59;
			h = 0.54;
			y = 0.06;
		};
		class cancelBtn: AGM_Interaction_Button_Base {
			idc = 8855;
			x = X_OFFSET + 0.005;
			w = 0.15;
			h = 0.1;
			y = 0.605;
			style = 2;
			text = $STR_AGM_Interaction_CancelSelection;
			action = "call AGM_Interaction_fnc_hideMenu;";   //'Default' call AGM_Interaction_fnc_openMenu;    'Default' call AGM_Interaction_fnc_openMenuSelf;
		};
		class approveBtn: AGM_Interaction_Button_Base {
			idc = 8860;
			x = X_OFFSET + 0.445;
			y = 0.605;
			h = 0.1;
			w = 0.15;
			style = 2;
			text = $STR_AGM_Interaction_MakeSelection;
			action = "call AGM_Interaction_fnc_hideMenu;";
		};
	};
};
#define GUI_GRID_X	(0)
#define GUI_GRID_Y	(0)
#define GUI_GRID_W	(0.025)
#define GUI_GRID_H	(0.04)

class RscPicture;
class RscStructuredText;
class RscInteractionIcon: RscPicture {
	x = 19.25 * GUI_GRID_W + GUI_GRID_X;
	y = 15.75 * GUI_GRID_H + GUI_GRID_Y;
	w = 2 * GUI_GRID_W;
	h = 2 * GUI_GRID_H;
};
class RscInteractionHelperIcon: RscInteractionIcon {
	x = 20 * GUI_GRID_W + GUI_GRID_X;
	y = 16 * GUI_GRID_H + GUI_GRID_Y;
	w = 1 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class RscInteractionText: RscText{
	x = 21 * GUI_GRID_W + GUI_GRID_X;
	y = 16 * GUI_GRID_H + GUI_GRID_Y;
	w = 8 * GUI_GRID_W;
	h = 1.5 * GUI_GRID_H;
};
class RscTitles {
	class AGM_FlowMenu {
		idd = 9920;
		enableSimulation = 1;
		movingEnable = 0;
		fadeIn=0.5;
		fadeOut=0.5;
		duration = 10e10;
		onLoad = "uiNamespace setVariable ['AGM_Flow_Display', _this select 0];";
		
		class controls {
			class RearIcon: RscInteractionIcon{
				idc = 999;
				text = "AGM_interaction\UI\CenterIcon_ca.paa";
				x = 17.975 * GUI_GRID_W;
				y = 10 * GUI_GRID_H;
				w = 4.5 * GUI_GRID_W;
				h = 5.75 * GUI_GRID_H;
			};
			class TopIcon: RscInteractionIcon{
				idc = 1200;
				h = 1 * GUI_GRID_H;
				y = 9 * GUI_GRID_H + GUI_GRID_Y;
			};
			class FirstIcon: RscInteractionIcon{
				idc = 1201;
				y = 10.25 * GUI_GRID_H + GUI_GRID_Y;
				h = 1.5 * GUI_GRID_H;
			};
			class SelectedItemIcon: RscInteractionIcon{
				idc = 1202;
				y = 12 * GUI_GRID_H + GUI_GRID_Y;
			};
			class ThirdIcon: RscInteractionIcon{
				idc = 1203;
				y = 14.25 * GUI_GRID_H + GUI_GRID_Y;
				h = 1.5 * GUI_GRID_H;
			};
			class BottomIcon: TopIcon{
				idc = 1204;
				y = 16 * GUI_GRID_H + GUI_GRID_Y;
			};
			class ItemName: RscText{
				idc = 1000;
				style = 0x01;
				x = 5.25 * GUI_GRID_W + GUI_GRID_X;
				y = 12.15 * GUI_GRID_H + GUI_GRID_Y;
				w = 13 * GUI_GRID_W;
				h = 1.5 * GUI_GRID_H;
				colorBackground[] = {0.3,0.3,0.3,0.8};
			};
			class BackIcon: RscInteractionIcon{
				idc = 1210;
				text = "AGM_interaction\UI\backArrow_ca.paa";
				x = 18.25 * GUI_GRID_W;
				y = 12.69 * GUI_GRID_H;
				w = 0.5 * GUI_GRID_W;
				h = 0.5 * GUI_GRID_H;
			};
			class SelectIcon: RscInteractionHelperIcon{
				idc = 1211;
				text = "AGM_interaction\UI\mouse_left_ca.paa";
				y = 17.5 * GUI_GRID_H;
			};
			class SelectText: RscInteractionText{
				idc = 1021;
				y = 17 * GUI_GRID_H;
				text = $STR_AGM_Interaction_MakeSelection;
			};
			class ScrollIcon: RscInteractionHelperIcon{
				idc = 1212;
				text = "AGM_interaction\UI\mouse_scroll_ca.paa";
				y = 18.5 * GUI_GRID_H;
			};
			class ScrollText: RscInteractionText{
				idc = 1022;
				y = 18 * GUI_GRID_H;
				text = $STR_AGM_Interaction_ScrollHint;
			};
			class GoBackIcon: RscInteractionHelperIcon{
				idc = 1213;
				text = "AGM_interaction\UI\mouse_right_ca.paa";
				y = 19.5 * GUI_GRID_H;
			};
			class GoBackText: RscInteractionText{
				idc = 1023;
				y = 19 * GUI_GRID_H;
				text = $STR_AGM_Interaction_Back;
			};
			class ItemDetails: RscStructuredText{
				idc = 1100;
				style = 0x0c;
				x = 21.5 * GUI_GRID_W + GUI_GRID_X;
				y = 11 * GUI_GRID_H + GUI_GRID_Y;
				w = 13 * GUI_GRID_W;
				h = 3.5 * GUI_GRID_H;
				colorBackground[] = {0,0,0,0.4};
			};
		};
	};
};
