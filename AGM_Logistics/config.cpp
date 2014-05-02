class CfgPatches {
  class AGM_Logistics {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Logistics {
    clientInit = "execVM '\AGM_Logistics\init.sqf'";
  };
};

class CfgVehicles {
  class Items_base_F;
  class thingX;
  class Man;

  class Land_CanisterFuel_F: Items_base_F {
    class AGM_Actions {
      class AGM_CarryJerryCan {
        displayName = "Carry jerry can";
        distance = 4;
        condition = "isNil {player getVariable 'AGM_Logisitcs_carriedItem'}";
        statement = "[AGM_Interaction_Target] spawn AGM_Logistics_carryJerryCan";
        showDisabled = 1;
        priority = 2.2;
      };
      class AGM_DropJerryCan {
        displayName = "Drop jerry can";
        distance = 4;
        condition = "!isNil {player getVariable 'AGM_Logisitcs_carriedItem'}";
        statement = "0 spawn AGM_Logistics_dropJerryCan";
        showDisabled = 0;
        priority = 2.1;
      };
    };
  };

  class ReammoBox_F: thingX {
    class AGM_Actions {
      class AGM_CarryBox {
        displayName = "Carry Box";
        distance = 4;
        condition = "isNil {player getVariable 'AGM_Logisitcs_carriedItem'}";
        statement = "[AGM_Interaction_Target] spawn AGM_Logistics_carryItem";
        showDisabled = 1;
        priority = 2.2;
      };
      class AGM_DropBox {
        displayName = "Drop Box";
        distance = 4;
        condition = "!isNil {player getVariable 'AGM_Logisitcs_carriedItem'}";
        statement = "0 spawn AGM_Logistics_dropItem";
        showDisabled = 0;
        priority = 2.1;
      };
    };
  };

  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_DropBoxSelf {
        displayName = "Drop Box";
        condition = "!isNil {player getVariable 'AGM_Logisitcs_carriedItem'}";
        statement = "0 spawn AGM_Logistics_dropItem";
        showDisabled = 0;
        priority = -2.1;
      };
      class AGM_DropJerryCanSelf {
        displayName = "Drop jerry can";
        condition = "!isNil {player getVariable 'AGM_Logisitcs_carriedItem'}";
        statement = "0 spawn AGM_Logistics_dropJerryCan";
        showDisabled = 0;
        priority = -2.1;
      };
    };
  };
};
