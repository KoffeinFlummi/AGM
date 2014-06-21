class CfgPatches {
  class AGM_UAVs {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Air_F_Gamma_UAV_01, AGM_Core, AGM_Interaction};
    version = "0.91";
    versionStr = "0.91";
    versionAr[] = {0,91,0};
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
  class UAV_01_base_F;

  class B_UAV_01_F: UAV_01_base_F {
    class AGM_Actions {
      class AGM_Refuel {
        displayName = "$STR_AGM_UAVs_Recharge";
        distance = 4;
        condition = "('AGM_UAVBattery' in items player) && {fuel cursorTarget < 1}";
        statement = "[AGM_Interaction_Target, player] call AGM_UAVs_fnc_refuel;";
        showDisabled = 1;
        priority = -2.5;
      };
    };
  };
  class O_UAV_01_F: UAV_01_base_F {
    class AGM_Actions {
      class AGM_Refuel {
        displayName = "$STR_AGM_UAVs_Recharge";
        distance = 4;
        condition = "('AGM_UAVBattery' in items player) && {fuel cursorTarget < 1}";
        statement = "[AGM_Interaction_Target, player] call AGM_UAVs_fnc_refuel;";
        showDisabled = 1;
        priority = -2.5;
      };
    };
  };
  class I_UAV_01_F: UAV_01_base_F {
    class AGM_Actions {
      class AGM_Refuel {
        displayName = "$STR_AGM_UAVs_Recharge";
        distance = 4;
        condition = "('AGM_UAVBattery' in items player) && {fuel cursorTarget < 1}";
        statement = "[AGM_Interaction_Target, player] call AGM_UAVs_fnc_refuel;";
        showDisabled = 1;
        priority = -2.5;
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
      type = 201;
    };
  };
};
