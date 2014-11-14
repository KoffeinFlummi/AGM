class CfgPatches{
  class AGM_InventoryInteraction  {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.6;
    requiredAddons[] = {"AGM_Core", "A3_UI_F", "A3_Weapons_F",      "AGM_Explosives", "AGM_Wind", "AGM_Hearing", "AGM_Overheating"};

    version = "0.99";
    versionStr = "0.99";
    versionAr[] = {0,99,0};
    author[] = {"CorruptedHeart", "Pabst Mirror"};
  };
};

class CfgFunctions {
  class AGM_InventoryInteraction {
    class AGM_InventoryInteraction {
      file = "\AGM_InventoryInteraction\functions";
      class actionButton;
      class addItemAction;
      class closeItemInfoBox;
      class handleClickEquiped;
      class handleClickInvList;
      class handleSelChangeInvList;
      class inventoryOpened;
      class openItemInfoBox;
      class removeItemAction;
    };
  };
};

class AGM_Core_Options {
  class InvInteractDoubleClick {
    displayName = "$STR_AGM_InventoryInteraction_UseDoubleClick";
    default = 0;
  };
};

class Extended_InventoryOpened_EventHandlers {
  class CAManBase {
    class AGM_OpenedInventory {
      clientInventoryOpened = "_this call AGM_InventoryInteraction_fnc_inventoryOpened;";
    };
  };
};

#include "RscDisplayInventory.hpp"

/* class CfgWeapons {
  class ItemCore;
  
  //More of an example than something anyone needs
  class ItemMap: ItemCore  {
    class AGM_InventoryActions {
      class OpenMap {
        displayName = "Open Map";  //todo localize
        condition = "(_idc == 6211)";  //show only when sloted in a specifc slot (based on control's IDC)
        statement = "openMap true";        
        closeInventory = 1;  //runs after closing inv display
      };
    };
  };
};
// #include "actions_test.hpp"
*/