class CfgPatches {
  class AGM_Logistics {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
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

  //Jerry Can
  class Items_base_F;
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

  //Crates
  class thingX;
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
      class AGM_loadBoxIntoVehicle {
        displayName = "Load Box";
        distance = 4;
        condition = "call AGM_Logistics_canLoadInto";
        statement = "[AGM_Interaction_Target] spawn AGM_Logistics_loadBoxIntoVehicle";
        showDisabled = 0;
        priority = 2.26;
      };
    };
  };

  //Men
  class Man;
  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_DropBoxSelf {
        displayName = "Drop Item";
        condition = "!isNil {player getVariable 'AGM_Logisitcs_carriedItem'}";
        statement = "0 spawn AGM_Logistics_dropItem";
        showDisabled = 0;
        priority = -2.1;
      };
    };
  };

  //Vehicles
  class LandVehicle;
  class Car: LandVehicle {
    AGM_Vehicle_Cargo = 4;
    class AGM_Actions {
      class AGM_unloadBox {
        displayName = "Unload Box";
        distance = 99;
        condition = "call AGM_Logistics_canUnload";
        statement = "[AGM_Interaction_Target] spawn AGM_Logistics_unloadBox";
        showDisabled = 0;
        priority = 2.25;
      };
    };
  };
  class Tank: LandVehicle {
    AGM_Vehicle_Cargo = 8;
    class AGM_Actions {
      class AGM_unloadBox {
        displayName = "Unload Box";
        distance = 99;
        condition = "call AGM_Logistics_canUnload";
        statement = "[AGM_Interaction_Target] spawn AGM_Logistics_unloadBox";
        showDisabled = 0;
        priority = 2.25;
      };
    };
  };
};
