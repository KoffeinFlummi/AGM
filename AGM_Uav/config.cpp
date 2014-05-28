class CfgPatches {
  class AGM_Uav {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Air_F_Gamma_UAV_01, AGM_Core, AGM_Interaction};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"marc_book"};
    authorUrl = "http://jgbtl14.bplaced.net/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Uav {
    clientInit = "execVM '\AGM_Uav\init.sqf'";
  };
};

class CfgVehicles {

  class UAV_01_base_F;
  class B_UAV_01_F: UAV_01_base_F {
    class AGM_Actions {
      class AGM_Refuel {
        displayName = "$STR_AGM_Refuel";
        distance = 4;
        condition = "true";
        statement = "[AGM_Interaction_Target, player] execVM ""AGM_Uav\scripts\refuel.sqf"";";
        showDisabled = 1;
        priority = -2.5;
      };
    };
  };
  class O_UAV_01_F: UAV_01_base_F {
    class AGM_Actions {
      class AGM_Refuel {
        displayName = "$STR_AGM_Refuel";
        distance = 4;
        condition = "true";
        statement = "[AGM_Interaction_Target, player] call AGM_Medical_fnc_bandage;";
        showDisabled = 1;
        priority = -2.5;
      };
    };
  };
  class I_UAV_01_F: UAV_01_base_F {
    class AGM_Actions {
      class AGM_Refuel {
        displayName = "$STR_AGM_Refuel";
        distance = 4;
        condition = "true";
        statement = "[AGM_Interaction_Target, player] execVM ""AGM_Uav\scripts\refuel.sqf"";";
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
	class AGM_UAV_Batterie: ItemCore {
		displayName = "$STR_AGM_Uav_Batterie_Name";
		descriptionShort = "$STR_AGM_Uav_Batterie_Description";
		model = "\A3\weapons_F\ammo\mag_univ.p3d";
		picture = "\AGM_Uav\UI\AGM_batterie.paa";
		scope = 2;
		class ItemInfo: InventoryItem_Base_F {
		  mass = 20;
		  type = 201;
		};
	};
};
