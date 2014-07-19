class CfgPatches {
  class AGM_Wind {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"Falke", "commy2", "KoffeinFlummi", "CAA-Picard"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Wind {
    class AGM_Wind {
      file = "AGM_Wind\functions";
      class firedEH;
      class init;
      class openKestrel;
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

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class AGM_ItemKestrel: ItemCore {
    author = "Falke";
    scope = 2;
    displayName = "$STR_AGM_Kestrel_Name";
    descriptionShort = "$STR_AGM_Kestrel_Description";
    model = "\AGM_Wind\kestrel4500.p3d";
    picture = "\AGM_Wind\data\4500NV.paa";
    icon = "iconObject_circle";
    mapSize = 0.034;
    mass = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 10;
      type = 401;
    };
  };
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_OpenKestrel {
        displayName = "$STR_AGM_Wind_OpenKestrel";
        condition = "'AGM_ItemKestrel' in items player && {!underwater player} && {cameraView != 'Gunner'} && {!AGM_isKestrel}";
        statement = "call AGM_Wind_fnc_openKestrel";
        showDisabled = 0;
        priority = 2;
      };
      class AGM_CloseKestrel {
        displayName = "$STR_AGM_Wind_CloseKestrel";
        condition = "AGM_isKestrel";
        statement = "AGM_isKestrel = false";
        showDisabled = 0;
        priority = 2;
      };
    };
  };

  class Item_Base_F;
  class AGM_Item_ItemKestrel: Item_Base_F {
    author = "Falke";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_Kestrel_Name";
    vehicleClass = "Items";
    class TransportWeapons {
      class AGM_ItemKestrel {
        weapon = "AGM_ItemKestrel";
        count = 1;
      };
    };
  };
};


class RscText;
class AGM_Rsc_Control_Base;
class AGM_Rsc_Display_Base;
class RscTitles {
  titles[] = {AGM_Kestrel, AGM_KestrelWheel};

  class AGM_Wind_Arrow {
    idd = -1;
    movingEnable=0;
    duration=0.5;
    fadeIn=0;
    fadeOut=0.25;
    onLoad = "with uiNameSpace do { AGM_Wind_Arrow = _this select 0 };";
    controls[] = {"AGM_Wind_Arrow_BG","AGM_Wind_Arrow_FW"};
    class AGM_Wind_Arrow_BG: RscText {
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
    class AGM_Wind_Arrow_FW: AGM_Wind_Arrow_BG {
      idc = 185185;
      style = 48;
      colorText[] = {1,1,1,1};
      sizeEx = 0.03;
      text = "";
    };
  };

  class AGM_Kestrel {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "_this spawn compile preprocessFileLineNumbers '\AGM_Wind\scripts\KestrelonLoad.sqf'";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "AGM_Kestrel";
    class RscPicture;
    class RscText;
    class controls {
      class AGM_KestrelHUDpic: RscPicture {
        idc = 42001;
        type = 0;
        text = "AGM_Wind\data\4500NV1.paa";
        style = 48 + 0x800;
        x = safeZoneX -0.25;
        y = safeZoneY + safeZoneH - 0.8;
        h = 0.75;
        w = 0.75;
        scale = 1;
        font = "PuristaMedium";
        sizeEx = 1;
        colorText[] = {1, 1, 1, 1};
        colorBackground[] = {1, 1, 1, 1};
        shadow = 0;
      };
      class AGM_KestrelHUD1: RscText {
        idc = 42002;
        type = 0;
        style = 1;
        x = safeZoneX +0.08;
        y = safeZoneY + safeZoneH -0.51;
        h = 0.09;
        w = 0.108;
        sizeEx = 0.04;
        lineSpacing = 1;
        font = "PuristaMedium";
        text = " 0000";
        colorText[] = {0.0745,0.2196,0.1216, 0.7};
        colorBackground[] = {0, 0, 0, 0};
        shadow = 0;
      };
      class AGM_KestrelHUD2: RscText {
        idc = 42003;
        type = 0;
        style = 1;
        x = safeZoneX +0.08;
        y = safeZoneY + safeZoneH -0.48;
        h = 0.09;
        w = 0.108;
        sizeEx = 0.04;
        lineSpacing = 1;
        font = "PuristaMedium";
        text = " 0000";
        colorText[] = {0.0745,0.2196,0.1216, 0.7};
        colorBackground[] = {0, 0, 0, 0};
        shadow = 0;
      };
      class AGM_KestrelHUD3: RscText {
        idc = 42004;
        type = 0;
        style = 1;
        x = safeZoneX +0.08;
        y = safeZoneY + safeZoneH -0.45;
        h = 0.09;
        w = 0.108;
        sizeEx = 0.04;
        lineSpacing = 1;
        font = "PuristaMedium";
        text = " 0000";
        colorText[] = {0.0745,0.2196,0.1216, 0.7};
        colorBackground[] = {0, 0, 0, 0};
        shadow = 0;
      };
      class AGM_KestrelHUD4: RscText {
        idc = 42005;
        type = 0;
        style = 1;
        x = safeZoneX +0.068;
        y = safeZoneY + safeZoneH -0.418;
        h = 0.09;
        w = 0.138;
        sizeEx = 0.035;
        lineSpacing = 1;
        font = "PuristaMedium";
        text = " 0000";
        colorText[] = {0.0745,0.2196,0.1216, 0.7};
        colorBackground[] = {0, 0, 0, 0};
        shadow = 0;
      };
    };
  };
  class AGM_KestrelWheel {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "_this spawn compile preprocessFileLineNumbers '\AGM_Wind\scripts\KestrelonLoadRad.sqf'";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "AGM_KestrelWheel";
    class RscPicture;
    class controls {
      class AGM_KestrelHUDrad: RscPicture {
        idc = 42010;
        type = 0;
        text = "AGM_Wind\data\kestrel_0.paa";
        style = 48 + 0x800;
        x = safeZoneX + 0.07;
        y = safeZoneY + safeZoneH - 0.76;
        h = 0.15;
        w = 0.15;
        scale = 1;
        font = "PuristaMedium";
        sizeEx = 1;
        colorText[] = {1, 1, 1, 1};
        colorBackground[] = {1, 1, 1, 1};
        shadow = 0;
      };
    };
  };

  class AGM_KestrelWheel_Preload: AGM_Rsc_Display_Base {
    class controlsBackground {
      class Preload_0: AGM_Rsc_Control_Base {
        text = "\AGM_Wind\data\kestrel_0.paa";
      };
      class Preload_1: Preload_0 {
        text = "\AGM_Wind\data\kestrel_1.paa";
      };
      class Preload_2: Preload_0 {
        text = "\AGM_Wind\data\kestrel_2.paa";
      };
      class Preload_3: Preload_0 {
        text = "\AGM_Wind\data\kestrel_3.paa";
      };
      class Preload_4: Preload_0 {
        text = "\AGM_Wind\data\kestrel_4.paa";
      };
      class Preload_5: Preload_0 {
        text = "\AGM_Wind\data\kestrel_5.paa";
      };
      class Preload_6: Preload_0 {
        text = "\AGM_Wind\data\kestrel_6.paa";
      };
      class Preload_7: Preload_0 {
        text = "\AGM_Wind\data\kestrel_7.paa";
      };
      class Preload_8: Preload_0 {
        text = "\AGM_Wind\data\kestrel_8.paa";
      };
      class Preload_9: Preload_0 {
        text = "\AGM_Wind\data\kestrel_9.paa";
      };
    };
  };
};
