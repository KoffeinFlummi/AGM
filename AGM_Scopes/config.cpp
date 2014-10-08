class CfgPatches {
  class AGM_Scopes {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.931";
    versionStr = "0.931";
    versionAr[] = {0,931,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi";
  };
};

class CfgFunctions {
  class AGM_Scopes {
    class AGM_Scopes {
      file = "AGM_Scopes\functions";
      class adjustScope;
      class canAdjustScope;
      class firedEH;
      class getOptics;
      class init;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Scopes {
    clientInit = "[] call AGM_Scopes_fnc_init;";
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Scopes {
      clientFired = "_this call AGM_Scopes_fnc_firedEH";
    };
  };
};

class AGM_Core_Default_Keys {
  class adjustScopeUp {
    displayName = "$STR_AGM_Scopes_AdjustUp";
    condition = "[0, 0.1] call AGM_Scopes_fnc_canAdjustScope;";
    statement = "[0, 0.1] call AGM_Scopes_fnc_adjustScope;";
    allowHolding = 1;
    key = 201;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class adjustScopeDown: adjustScopeUp {
    displayName = "$STR_AGM_Scopes_AdjustDown";
    condition = "[0, -0.1] call AGM_Scopes_fnc_canAdjustScope;";
    statement = "[0, -0.1] call AGM_Scopes_fnc_adjustScope;";
    key = 209;
  };
  class adjustScopeLeft: adjustScopeUp {
    displayName = "$STR_AGM_Scopes_AdjustLeft";
    condition = "[-0.1, 0] call AGM_Scopes_fnc_canAdjustScope;";
    statement = "[-0.1, 0] call AGM_Scopes_fnc_adjustScope;";
    key = 209;
    control = 1;
  };
  class adjustScopeRight: adjustScopeLeft {
    displayName = "$STR_AGM_Scopes_AdjustRight";
    condition = "[0.1, 0] call AGM_Scopes_fnc_canAdjustScope;";
    statement = "[0.1, 0] call AGM_Scopes_fnc_adjustScope;";
    key = 201;
  };
};

class CfgSounds {
  class AGM_Sound_Click;
  class AGM_Scopes_Click_1: AGM_Sound_Click {
    sound[] = {"\AGM_Scopes\sounds\agm_scopes_click.wav", 3, 2, 200};
  };
  class AGM_Scopes_Click_2: AGM_Scopes_Click_1 {
    sound[] = {"\AGM_Scopes\sounds\agm_scopes_click.wav", 3.3, 1.8, 200};
  };
  class AGM_Scopes_Click_3: AGM_Scopes_Click_1 {
    sound[] = {"\AGM_Scopes\sounds\agm_scopes_click.wav", 2.8, 2.3, 200};
  };
};

// TODO: check other scopes, realistic values, check inheritance
class CfgWeapons {
  class ItemCore;
  class InventoryOpticsItem_Base_F;

  class optic_LRPS: ItemCore {
    AGM_ScopeAdjust_Horizontal[] = {-50,50};
    AGM_ScopeAdjust_Vertical[] = {-70,70};
    class ItemInfo: InventoryOpticsItem_Base_F {
      class OpticsModes {
        class Snip {
          discreteDistance[] = {};
          discreteDistanceIndex = 0;
        };
      };
    };
  };

  class optic_SOS: ItemCore {
    AGM_ScopeAdjust_Horizontal[] = {-50,50};
    AGM_ScopeAdjust_Vertical[] = {-60,60};
    class ItemInfo: InventoryOpticsItem_Base_F {
      class OpticsModes {
        class Snip {
          discreteDistance[] = {};
          discreteDistanceIndex = 0;
        };
      };
    };
  };
};

class RscTitles {
  class AGM_Scope_Zeroing {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "_this spawn compile preprocessFileLineNumbers '\AGM_Scopes\scripts\zeroingOnLoad.sqf'; uiNamespace setVariable ['AGM_Scope_Debug', _this];";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "AGM_Scope_Zeroing";
    class RscPicture;
    class RscText;
    class controls {
      class AGM_Scope_Zeroing_BG: RscPicture {
        idc = 925001;
        type = 0;
        text = "AGM_Scopes\UI\scopes_bg.paa";
        style = 48 + 0x800;
        x = (safeZoneX + 0.5 * safeZoneW) - (0.4 * safeZoneW / 2);
        y = safezoneY + 0 * safezoneH;
        w = 0.4 * safeZoneW;
        h = 0.3 * safeZoneH;
        scale = 1;
        sizeEx = 1;
        font = "PuristaMedium";
        colorText[] = {1,1,1,1};
        colorBackground[] = {1,1,1,1};
        shadow = 1;
      };
      class AGM_Scope_Zeroing_Vertical: RscText {
        idc = 925002;
        type = 0;
        style = 2;
        x = (safeZoneX + 0.5 * safeZoneW) - (0.04 * safeZoneW / 2);
        y = safezoneY + 0.06 * safezoneH;
        w = 0.04 * safeZoneW;
        h = 0.025 * safeZoneH;
        sizeEx = 0.04;
        lineSpacing = 1;
        font = "PuristaMedium";
        text = "";
        colorText[] = {1,1,1, 0.9};
        colorBackground[] = {1,0,0, 1};
        shadow = 0;
      };
      class AGM_Scope_Zeroing_Horizontal: RscText {
        idc = 925003;
        type = 0;
        style = 0;
        x = (safeZoneX + 0.5 * safeZoneW) + (0.04 * safeZoneW);
        y = (safezoneY + 0.3 * safezoneH / 2) - (0.025 * safeZoneH / 2);
        w = 0.04  * safeZoneW;
        h = 0.025 * safeZoneH;
        sizeEx = 0.04;
        lineSpacing = 1;
        font = "PuristaMedium";
        text = "";
        colorText[] = {1,1,1, 0.9};
        colorBackground[] = {1,0,0, 1};
        shadow = 0;
      };
    };
  };
};
