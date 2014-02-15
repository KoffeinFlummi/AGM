
#define HSPACE 0.3
#define VSPACE 0.3
#define BORDER 0.1

class BWA3_Interactive_Button_Base {
  tooltip = "";
  action = "";

  idc = -1;
  access = 0;
  style = 0;
  type = 1;
  text = "";
  font = "PuristaMedium";
  sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
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

class BWA3_Menu_Dialog {
  idd = -1;
  movingEnable = true;
  onLoad = "_dlgMenuDialog = _this select 0; for '_a' from 10 to 19 do {(_dlgMenuDialog displayCtrl _a) ctrlShow false}; uiNamespace setVariable ['BWA3_Menu_Dialog', _dlgMenuDialog];"
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
      sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
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
    class Interactive_Button0 : BWA3_Interactive_Button_Base {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 0);";
      text = "0";
      idc = 10;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 0 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button1 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 1);";
      text = "1";
      idc = 11;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 1 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button2 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 2);";
      text = "2";
      idc = 12;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 2 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button3 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 3);";
      text = "3";
      idc = 13;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 3 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button4 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 4);";
      text = "4";
      idc = 14;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 4 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button5 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 5);";
      text = "5";
      idc = 15;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button6 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 6);";
      text = "6";
      idc = 16;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 6 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button7 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 7);";
      text = "7";
      idc = 17;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 7 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button8 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 8);";
      text = "8";
      idc = 18;
      x = (HSPACE + 1 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 8 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button9 : Interactive_Button0 {
      tooltip = "";
      action = "closeDialog 0; call (BWA3_Menu_Button select 9);";
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

class BWA3_QuickMenu_Control_Base {
  default = 0;
  idc = -1;
  access = 0;
  type = 11;
  style = 2;
  text = "";
  font = "TahomaB";
  sizeEx = 0;
  color[] = {0, 0, 0, 1};
  colorActive[] = {0.3, 0.4, 0, 1};
  colortext[] = {0, 0, 0, 1};
  soundEnter[] = {"", 0.1, 1};
  soundPush[] = {"", 0.1, 1};
  soundClick[] = {"", 0.1, 1};
  soundEscape[] = {"", 0.1, 1};
  x = 0;
  y = 0;
  h = 0;
  w = 0;
};

class BWA3_QuickMenu_Dialog {
  idd = -1;
  movingEnable = false;
  onLoad = "uiNamespace setVariable ['BWA3_QuickMenu_Dialog', _this select 0]; setMousePosition [0.5, 0.5];"
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
      type = 48;
      style = 0;
      size = 1;
      colorBackground[] = {0, 0.265, 0, 0.5};
      colorText[] = {1, 1, 1, 1};
      x = (-0.5) * safezoneW + safezoneX;
      y = (-0.5) * safezoneH + safezoneY;
      w = 1 * safezoneW;
      h = 1 * safezoneH;
    };
  };

  class controls {
    class BWA3_QuickMenu_Control : BWA3_QuickMenu_Control_Base {
      onMouseMoving = "BWA3_Menu_MousePosition = [_this select 1, _this select 2]; hintSilent str(BWA3_Menu_MousePosition);";
      idc = -1;
      style = 48;
      text = "#(argb,8,8,3)color(1,1,1,1)";
      color[] = {0, 0, 0, 0};
      colorActive[] = {0, 0, 0, 0};
      x = 0 * safezoneW + safezoneX;
      y = 0 * safezoneH + safezoneY;
      w = 1 * safezoneW;
      h = 1 * safezoneH;
    };
  };
};

////////////////////////////////////////////////////////////////////////////////////////////////////

#define HSPACE 0.5-2.0/16/2
#define VSPACE 0.5-0.3/9/2

class BWA3_Interactive_Button_Base_noFlash {
  tooltip = "";
  action = "";

  idc = -1;
  access = 0;
  style = 2;
  type = 1;
  text = "";
  font = "PuristaMedium";
  sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
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

class BWA3_CommyRose_Dialog {
  idd = -1;
  movingEnable = false;
  onLoad = "_dlgMenuDialog = _this select 0; for '_a' from 10 to 19 do {(_dlgMenuDialog displayCtrl _a) ctrlShow false}; uiNamespace setVariable ['BWA3_Menu_Dialog', _dlgMenuDialog];"
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
      x = (HSPACE + 1 * 0.1 - BORDER / 16) * safezoneW + safezoneX;
      y = (VSPACE - 1 * 0.04 - BORDER / 9) * safezoneH + safezoneY;
      w = (2.0 + 2 * BORDER) / 16 * safezoneW;
      h = (2.0 + 2 * BORDER) / 9 * safezoneH;
    };*/
  };
  class controls {
    class Interactive_BWA3_Logo : BWA3_Interactive_Button_Base {
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

    class Interactive_Button0 : BWA3_Interactive_Button_Base {
      action = "closeDialog 0; call (BWA3_Menu_Button select 0);";
      style = 2;
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "0";
      idc = 10;
      x = (HSPACE + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 2.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button1 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 1);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "1";
      idc = 11;
      x = (HSPACE + 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 1.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button2 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 2);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "2";
      idc = 12;
      x = (HSPACE + 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 0.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button3 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 3);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "3";
      idc = 13;
      x = (HSPACE + 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 0.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button4 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 4);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "4";
      idc = 14;
      x = (HSPACE + 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 1.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button5 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 5);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "5";
      idc = 15;
      x = (HSPACE + 0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 2.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button6 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 6);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "6";
      idc = 16;
      x = (HSPACE - 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 1.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button7 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 7);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "7";
      idc = 17;
      x = (HSPACE - 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE + 0.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button8 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 8);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "8";
      idc = 18;
      x = (HSPACE - 1.25 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 0.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };

    class Interactive_Button9 : Interactive_Button0 {
      action = "closeDialog 0; call (BWA3_Menu_Button select 9);";
      //onMouseEnter = "hint str(_this)";
      tooltip = "";
      text = "9";
      idc = 19;
      x = (HSPACE - 1.0 * 0.1) * safezoneW + safezoneX;
      y = (VSPACE - 1.5 * 0.04) * safezoneH + safezoneY;
      w = 2.0 / 16 * safezoneW;
      h = 0.3 / 9 * safezoneH;
    };
  };
};