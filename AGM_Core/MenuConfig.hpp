
#define HSPACE 0.3
#define VSPACE 0.3
#define BORDER 0.1

class AGM_Core_Interactive_Button_Base {
  tooltip = "";
  action = "";

  idc = -1;
  access = 0;
  style = 0;
  type = 1;
  text = "";
  font = "PuristaMedium";
  sizeEx = "1 / 40 / (getResolution select 5) * safezoneX / safezoneXAbs";
  shadow = 2;

  x = 0;
  y = 0;
  w = 0;
  h = 0;

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
  colorFocused[] = {0,0,0,0};
  colorShadow[] = {0,0,0,0};
  colorBorder[] = {1,1,1,0.8};

  soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
  soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
  soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
  soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
};

class AGM_Core_Menu_Dialog {
  idd = -1;
  movingEnable = true;
  onLoad = "_dlgMenuDialog = _this select 0; for '_a' from 10 to 19 do {(_dlgMenuDialog displayCtrl _a) ctrlShow false}; uiNamespace setVariable ['AGM_Core_Menu_Dialog', _dlgMenuDialog];";
  objects[] = {};

  class controlsBackground {
    class Background {
      idc = 1;
      moving = 0;
      font = "TahomaB";
      text = "";
      sizeEx = 0;
      lineSpacing = 0;
      access = 0;
      type = 0;
      style = 0;
      size = 1;
      colorBackground[] = {0, 0.265, 0, 0.5};
      colorText[] = {0, 0, 0, 0};
      x = (HSPACE + 1 * 0.1 - BORDER / 16) * safezoneW + safezoneX;
      y = (VSPACE - 1 * 0.04 - BORDER / 9) * safezoneH + safezoneY;
      w = (2.0 + 2 * BORDER) / 16 * safezoneW;
      h = 0;
    };

    class Header {
      idc = 2;
      moving = 1;
      text = "HEADER";
      font = "PuristaMedium";
      sizeEx = "1 / 40 / (getResolution select 5) * safezoneX / safezoneXAbs";
      lineSpacing = 0;
      access = 0;
      type = 0;
      style = 2;
      size = 1;
      colorBackground[] = {0,0,0,0};
      colorText[] = {1,1,1,1};
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 1 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };
  };

  class controls {
    class Interactive_Button0 : AGM_Core_Interactive_Button_Base {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 0);";
      text = "0";
      idc = 10;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 0 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button1 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 1);";
      text = "1";
      idc = 11;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 1 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button2 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 2);";
      text = "2";
      idc = 12;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 2 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button3 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 3);";
      text = "3";
      idc = 13;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 3 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button4 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 4);";
      text = "4";
      idc = 14;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 4 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button5 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 5);";
      text = "5";
      idc = 15;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button6 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 6);";
      text = "6";
      idc = 16;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 6 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button7 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 7);";
      text = "7";
      idc = 17;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 7 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button8 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 8);";
      text = "8";
      idc = 18;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 8 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button9 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 9);";
      text = "9";
      idc = 19;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 9 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };
  };
};

////////////////////////////////////////////////////////////////////////////////////////////////////

#define HSPACE2 0.5-2.0/16/2
#define VSPACE2 0.5-0.3/9/2

class AGM_Core_Interactive_Button_Base_noFlash {
  tooltip = "";
  action = "";

  idc = -1;
  access = 0;
  style = 2;
  type = 1;
  text = "";
  font = "PuristaMedium";
  sizeEx = "1 / 40 / (getResolution select 5) * safezoneX / safezoneXAbs";
  shadow = 2;

  x = 0;
  y = 0;
  w = 0;
  h = 0;

  offsetX = 0;
  offsetY = 0;
  offsetPressedX = 0;
  offsetPressedY = 0;
  borderSize = 0;

  colorText[] = {1,1,1,1};
  colorDisabled[] = {0.5,0.5,0.5,1};
  colorBackground[] = {0,0,0,0.8};
  colorBackgroundDisabled[] = {0,0,0,0.8};
  colorBackgroundActive[] = {0,0,0,0.8};
  colorFocused[] = {0,0,0,0};
  colorShadow[] = {0,0,0,0};
  colorBorder[] = {1,1,1,0.8};

  soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
  soundPush[] = {"",0.09,1};
  soundClick[] = {"",0.09,1};
  soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
};

class AGM_Core_CommyRose_Dialog {
  idd = -1;
  movingEnable = false;
  onLoad = "_dlgMenuDialog = _this select 0; for '_a' from 10 to 19 do {(_dlgMenuDialog displayCtrl _a) ctrlShow false}; uiNamespace setVariable ['AGM_Core_Menu_Dialog', _dlgMenuDialog];";
  objects[] = {};

  class controlsBackground {
    /*class Background {
      idc = 1;
      moving = 0;
      font = "TahomaB";
      text = "";
      sizeEx = 0;
      lineSpacing = 0;
      access = 0;
      type = 0;
      style = 0;
      size = 1;
      colorBackground[] = {0, 0.265, 0, 0.5};
      colorText[] = {0, 0, 0, 0};
      x = (HSPACE2 + 1 * 0.1 - BORDER / 16) * safezoneW + safezoneX;
      y = (VSPACE2 - 1 * 0.04 - BORDER / 9) * safezoneH + safezoneY;
      w = (2.0 + 2 * BORDER) / 16 * safezoneW;
      h = (2.0 + 2 * BORDER) / 9 * safezoneH;
    };*/
  };
  class controls {
    class Interactive_AGM_Logo : AGM_Core_Interactive_Button_Base {
      action = "closeDialog 0;";
      type = 0;
      style = 48;
      onMouseEnter = "hint ('_' + str(_this))";
      tooltip = "";
      text = "schinken";
      idc = 2;
      x = (0.5-1.0/16/2 + 0 * 0.1) * safezoneW + safezoneX;
      y = (0.5-1.0/9/2 + 0 * 0.04) * safezoneH + safezoneY;
      w = 1.0 / 16 * safezoneW;
      h = 1.0 / 9 * safezoneH;
    };

    class Interactive_Button0 : AGM_Core_Interactive_Button_Base {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 0);";
      style = 2;
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "0";
      idc = 10;
      x = (HSPACE2 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 - 2.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button1 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 1);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "1";
      idc = 11;
      x = (HSPACE2 + 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 - 1.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button2 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 2);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "2";
      idc = 12;
      x = (HSPACE2 + 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 - 0.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button3 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 3);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "3";
      idc = 13;
      x = (HSPACE2 + 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 + 0.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button4 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 4);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "4";
      idc = 14;
      x = (HSPACE2 + 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 + 1.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button5 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 5);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "5";
      idc = 15;
      x = (HSPACE2 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 + 2.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button6 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 6);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "6";
      idc = 16;
      x = (HSPACE2 - 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 + 1.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button7 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 7);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "7";
      idc = 17;
      x = (HSPACE2 - 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 + 0.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button8 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 8);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "8";
      idc = 18;
      x = (HSPACE2 - 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 - 0.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button9 : Interactive_Button0 {
      action = "closeDialog 0; call (AGM_Core_Menu_Button select 9);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "9";
      idc = 19;
      x = (HSPACE2 - 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE2 - 1.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };
  };
};

////////////////////////////////////////////////////////////////////////////////////////////////////

#define HSPACE3 0.05
#define VSPACE3 0.05
#define BORDER 0.1

class AGM_Core_Text_Button_Base {
  idc = 2;
  moving = 0;
  text = "";
  font = "PuristaMedium";
  sizeEx = "1 / 40 / (getResolution select 5) * safezoneX / safezoneXAbs";
  lineSpacing = 0;
  access = 0;
  type = 0;
  style = 2 + 0x800;
  size = 1;
  colorBackground[] = {0,0,0,0.8};
  colorText[] = {1,1,1,1};
  x = 0;
  y = 0;
  w = 0;
  h = 0;
};

class AGM_Core_OptionsMenu_Dialog {
  idd = -1;
  movingEnable = true;
  onLoad = "_dlgMenuDialog = _this select 0; for '_a' from 20 to 26 do {(_dlgMenuDialog displayCtrl _a) ctrlShow false}; for '_a' from 100 to 119 do {(_dlgMenuDialog displayCtrl _a) ctrlShow false}; for '_a' from 200 to 219 do {(_dlgMenuDialog displayCtrl _a) ctrlShow false}; uiNamespace setVariable ['AGM_Core_MenuDialog', _dlgMenuDialog];";
  objects[] = {};

  class controlsBackground {
    class Background {
      idc = 1;
      moving = 0;
      font = "TahomaB";
      text = "";
      sizeEx = 0;
      lineSpacing = 0;
      access = 0;
      type = 0;
      style = 0 + 0x800;
      size = 1;
      //colorBackground[] = {0, 0.265, 0, 0.5};
      colorBackground[] = {0, 0, 0, 0.5};
      colorText[] = {0, 0, 0, 0};
      x = HSPACE3 / 2 * safezoneW + safezoneX;
      y = VSPACE3 / 2 * safezoneH + safezoneY;
      w = (1 - 2 * HSPACE3 / 2) * safezoneW;
      h = (1 - 2 * VSPACE3 / 2) * safezoneH;
    };

    class Header {
      idc = 2;
      moving = 0;
      text = "$STR_AGM_Core_Options";
      font = "PuristaMedium";
      sizeEx = "1 / 40 / (getResolution select 5) * safezoneX / safezoneXAbs";
      lineSpacing = 0;
      access = 0;
      type = 0;
      style = 1 + 0x800;
      size = 1;
      //colorBackground[] = {0,0,0,0};
      colorBackground[] = {1, 0.647, 0, 0.5};
      colorText[] = {1,1,1,1};
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 0.5 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class AGM_Logo : AGM_Core_Interactive_Button_Base {
      action = "closeDialog 0;";
      type = 0;
      style = 48;
      onMouseEnter = "hint ('_' + str(_this))";
      tooltip = "";
      text = "";//"\AGM_common\rsc\bwlogo.paa";
      idc = 2;
      x = ((1 - 2 * HSPACE3 / 2) - (HSPACE3 + 0.5 * 0.1)) * safezoneW + safezoneX;
      y = (VSPACE3 + 2 * 0.04) * safezoneH + safezoneY;
      w = 1.0 / 16 * safezoneW;
      h = 1.0 / 9 * safezoneH;
    };
  };

  class controls {
    class Text_Button0 : AGM_Core_Text_Button_Base {
      text = "";
      idc = 100;
      style = 0 + 0x800;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 2 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button1 : Text_Button0 {
      text = "";
      idc = 101;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 3 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button2 : Text_Button0 {
      text = "";
      idc = 102;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 4 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button3 : Text_Button0 {
      text = "";
      idc = 103;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 5 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button4 : Text_Button0 {
      text = "";
      idc = 104;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 6 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button5 : Text_Button0 {
      text = "";
      idc = 105;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 7 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button6 : Text_Button0 {
      text = "";
      idc = 106;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 8 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button7 : Text_Button0 {
      text = "";
      idc = 107;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 9 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button8 : Text_Button0 {
      text = "";
      idc = 108;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 10 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button9 : Text_Button0 {
      text = "";
      idc = 109;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 11 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button10 : Text_Button0 {
      text = "";
      idc = 110;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 12 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button11 : Text_Button0 {
      text = "";
      idc = 111;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 13 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button12 : Text_Button0 {
      text = "";
      idc = 112;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 14 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button13 : Text_Button0 {
      text = "";
      idc = 113;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 15 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button14 : Text_Button0 {
      text = "";
      idc = 114;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 16 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button15 : Text_Button0 {
      text = "";
      idc = 115;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 17 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button16 : Text_Button0 {
      text = "";
      idc = 116;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 18 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button17 : Text_Button0 {
      text = "";
      idc = 117;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 19 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button18 : Text_Button0 {
      text = "";
      idc = 118;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 20 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Text_Button19 : Text_Button0 {
      text = "";
      idc = 119;
      x = (HSPACE3 + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 21 * 0.04) * safezoneH + safezoneY;
      w = 4.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button0 : AGM_Core_Interactive_Button_Base {
      action = "AGM_Core_keySet = -1; [0] spawn AGM_Core_editKey";
      idc = 200;
      style = 2 + 0x800;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 2 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button1 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [1] spawn AGM_Core_editKey";
      idc = 201;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 3 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button2 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [2] spawn AGM_Core_editKey";
      idc = 202;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 4 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button3 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [3] spawn AGM_Core_editKey";
      idc = 203;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 5 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button4 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [4] spawn AGM_Core_editKey";
      idc = 204;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 6 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button5 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [5] spawn AGM_Core_editKey";
      idc = 205;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 7 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button6 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [6] spawn AGM_Core_editKey";
      idc = 206;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 8 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button7 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [7] spawn AGM_Core_editKey";
      idc = 207;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 9 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button8 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [8] spawn AGM_Core_editKey";
      idc = 208;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 10 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button9 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [9] spawn AGM_Core_editKey";
      idc = 209;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 11 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button10 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [10] spawn AGM_Core_editKey";
      idc = 210;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 12 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button11 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [11] spawn AGM_Core_editKey";
      idc = 211;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 13 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button12 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [12] spawn AGM_Core_editKey";
      idc = 212;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 14 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button13 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [13] spawn AGM_Core_editKey";
      idc = 213;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 15 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button14 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [14] spawn AGM_Core_editKey";
      idc = 214;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 16 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button15 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [15] spawn AGM_Core_editKey";
      idc = 215;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 17 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button16 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [16] spawn AGM_Core_editKey";
      idc = 216;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 18 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button17 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [17] spawn AGM_Core_editKey";
      idc = 217;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 19 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button18 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [18] spawn AGM_Core_editKey";
      idc = 218;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 20 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button19 : Interactive_Button0 {
      action = "AGM_Core_keySet = -1; [19] spawn AGM_Core_editKey";
      idc = 219;
      x = (HSPACE3 + 3 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 21 * 0.04) * safezoneH + safezoneY;
      w = 3.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class TextBox_KeyChange : Text_Button0 {
      text = "";
      idc = 20;
      style = 2 + 0x800;
      x = (6 * 0.1) * safezoneW + safezoneX;
      y = (8 * 0.04) * safezoneH + safezoneY;
      w = (6.0 / 16 - HSPACE3 / 2) * safezoneW;
      h = (3.0 / 9 - VSPACE3 / 2) * safezoneH;
    };

    class TextBox_Key_Shift : TextBox_KeyChange {
      text = "$STR_AGM_Core_Shift";
      idc = 21;
      colorText[] = {0.25,0.25,0.25,1};
      colorBackground[] = {0,0,0,0};
      x = (3 / 4 * HSPACE3 + 5.75 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 10 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class TextBox_Key_Control : TextBox_Key_Shift {
      text = "$STR_AGM_Core_Ctrl";
      idc = 22;
      x = (3 / 4 * HSPACE3 + 6.75 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 10 * 0.04) * safezoneH + safezoneY;
    };

    class TextBox_Key_Alt : TextBox_Key_Shift {
      text = "$STR_AGM_Core_Alt";
      idc = 23;
      x = (3 / 4 * HSPACE3 + 7.75 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 10 * 0.04) * safezoneH + safezoneY;
    };
 
    class TextBox_Key : TextBox_Key_Shift {
      text = "";
      idc = 24;
      colorText[] = {1,1,1,1};
      colorBackground[] = {0,0,0,0};
      x = (3 / 4 * HSPACE3 + 6.75 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 8 * 0.04) * safezoneH + safezoneY;
    };

    class Interactive_ButtonV : Interactive_Button0 {
      action = "AGM_Core_keySet = 1";
      text = "$STR_AGM_Core_Save";
      idc = 25;
      colorBackground[] = {0,0,0,0};
      x = (HSPACE3 + 6 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 13 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_ButtonW : Interactive_ButtonV {
      action = "AGM_Core_keySet = -1";
      text = "$STR_AGM_Core_Cancel";
      idc = 26;
      x = (HSPACE3 + 7.5 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE3 + 13 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_ButtonX : Interactive_Button0 {
      action = "AGM_Core_keySave = 1; closeDialog 0";
      text = "$STR_AGM_Core_Save";
      idc = 10;
      x = ((1 - 2 * HSPACE3 / 2) - (HSPACE3 + 2.5 * 0.1)) * safezoneW + safezoneX;
      y = (VSPACE3 + 21 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_ButtonY : Interactive_Button0 {
      action = "AGM_Core_keySave = -1; closeDialog 0";
      text = "$STR_AGM_Core_Cancel";
      idc = 11;
      x = ((1 - 2 * HSPACE3 / 2) - (HSPACE3 + 1 * 0.1)) * safezoneW + safezoneX;
      y = (VSPACE3 + 21 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };
  };
};
