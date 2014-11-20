class CfgPatches{
  class AGM_InventoryInteraction  {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.6;
    requiredAddons[] = {"AGM_Core"};

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

class Extended_PostInit_EventHandlers {
  class AGM_OpenedInventory {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_InventoryInteraction\clientInit.sqf'";
  };
};

#include "RscDisplayInventory.hpp"


//More of an example than something anyone needs
/*
class CfgWeapons {
  class ItemCore;
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
*/