class CfgPatches {
  class AGM_Wind {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi", "CAA-Picard"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Wind {
    class AGM_Wind {
      file = "AGM_Wind\functions";
      class firedEH;
      class init;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Wind {
    serverInit = "if (isServer && {call AGM_Core_fnc_isAutoWind}) then {setWind [wind select 0, wind select 1, true]};";
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Wind\clientInit.sqf'";
  };
};

class Extended_InitPost_EventHandlers {
  class CAManBase {
    class AGM_Wind {
      init = "_this call AGM_Wind_fnc_init";
    };
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Wind {
      clientFired = "_this call AGM_Wind_fnc_firedEH";
    };
  };
};

class RscText;
class RscTitles
{
  class AGM_Wind_Arrow
  {
    idd = -1;
    movingEnable=0;
    duration=0.5;
    fadeIn=0;
    fadeOut=0.25;
    onLoad = "with uiNameSpace do { AGM_Wind_Arrow = _this select 0 };";
    controls[] = {"AGM_Wind_Arrow_BG","AGM_Wind_Arrow_FW"};
    class AGM_Wind_Arrow_BG : RscText
    {
      idc = -1;
      type = 0;
      style = 128;
      colorBackground[] = {0,0,0,0};
      colorText[] = {0,0,0,0};
      text = "";
      sizeEx = 0.027;
      x = "SafeZoneX + 0.001";
      y = "SafeZoneY + 0.05";
      w = 0.25;
      h = 0.25;
      size = 0.034;
    };
    class AGM_Wind_Arrow_FW : AGM_Wind_Arrow_BG
    {
      idc = 185185;
      style = 48;
      colorText[] = {1,1,1,1};
      sizeEx = 0.03;
      text = "";
    };
  };
};
