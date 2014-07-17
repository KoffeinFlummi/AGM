class CfgPatches {
  class AGM_UAVs {
    units[] = {};
    weapons[] = {"AGM_UAVBattery"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"marc_book", "KoffeinFlummi"};
    authorUrl = "https://github.com/MarcBook/";
  };
};

class CfgFunctions {
  class AGM_UAVs {
    class AGM_UAVs {
      file = "AGM_UAVs\functions";
      class refuel;
      class refuelCallback;
    };
  };
};

class CfgVehicles {
  class Helicopter_Base_F;
  class UAV_01_base_F: Helicopter_Base_F {
    class AGM_Actions {
      class AGM_Refuel {
        displayName = "$STR_AGM_UAVs_Recharge";
        distance = 4;
        condition = "'AGM_UAVBattery' in items player && {fuel cursorTarget < 1}";
        statement = "[cursorTarget, player] call AGM_UAVs_fnc_refuel";
        showDisabled = 1;
        priority = -2.5;
      };
    };
  };

  class Box_NATO_Support_F;
  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      class _xx_AGM_UAVBattery {
        count = 24;
        name = "AGM_UAVBattery";
      };
    };
  };
};

class CfgWeapons{
  class ItemCore;
  class InventoryItem_Base_F;

  //ITEMS
  class AGM_UAVBattery: ItemCore {
    displayName = "$STR_AGM_UAVs_Battery_Name";
    descriptionShort = "$STR_AGM_UAVs_Battery_Description";
    model = "\A3\weapons_F\ammo\mag_univ.p3d";
    picture = "\AGM_UAVs\UI\AGM_battery.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 20;
      type = 401;
    };
  };
};
