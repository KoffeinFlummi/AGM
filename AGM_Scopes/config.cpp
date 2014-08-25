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
  class adjustScopeLeft: adjustRangeUp {
    displayName = "$STR_AGM_Scopes_AdjustLeft";
    condition = "[-0.1, 0] call AGM_Scopes_fnc_canAdjustScope;";
    statement = "[-0.1, 0] call AGM_Scopes_fnc_adjustScope;";
    key = 201;
    control = 1;
  };
  class adjustScopeRight: adjustScopeLeft {
    displayName = "$STR_AGM_Scopes_AdjustRight";
    condition = "[0.1, 0] call AGM_Scopes_fnc_canAdjustScope;";
    statement = "[0.1, 0] call AGM_Scopes_fnc_adjustScope;";
    key = 209;
  };
};

// TODO: check other scopes, realistic values, check inheritance
class CfgWeapons {
  class ItemCore;
  class InventoryOpticsItem_Base_F;

  class optic_LRPS: ItemCore {
    AGM_ScopeAdjust_Horizontal = {-5,5};
    AGM_ScopeAdjust_Vertical = {-7,7};
    class ItemInfo: InventoryOpticsItem_Base_F {
      class OpticsModes {
        class Snip {
          discreteDistance[] = {};
          discreteDistance[] = 0;
        };
      };
    };
  };

  class optic_SOS: ItemCore {
    AGM_ScopeAdjust_Horizontal = {-5,5};
    AGM_ScopeAdjust_Vertical = {-6,6};
    class ItemInfo: InventoryOpticsItem_Base_F {
      class OpticsModes {
        class Snip {
          discreteDistance[] = {};
          discreteDistance[] = 0;
        };
      };
    };
  };
};
