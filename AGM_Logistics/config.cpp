class CfgPatches {
  class AGM_Logistics {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core, AGM_Interaction};
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

/*class CfgFunctions {
  class AGM_Logistics {
    class AGM_Logistics {
      file = "\AGM_logistics\functions";
      class canLoadMagazine;
      class reloadMagazine;
      class getLoadableMagazines;
      class applyMagazineNames;
      class getWeaponsOfMagazine;
    };
  };
};*/

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

      class AGM_reloadMagazines {
        displayName = "Magazines >>";
        distance = 6;
        condition = "true";
        statement = "AGM_Logistics_loadableMagazines = [cursorTarget] call AGM_Logistics_getLoadableMagazines; AGM_Logistics_loadableMagazines resize 10; 'AGM_reloadMagazines' call AGM_Interaction_fnc_openMenu; [AGM_Logistics_loadableMagazines] call AGM_Logistics_applyMagazineNames";
        showDisabled = 1;
        priority = 1;

        class AGM_reloadMagazine0 {
          displayName = "Magazine 0";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 0] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 0] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 1;
        };
        class AGM_reloadMagazine1 {
          displayName = "Magazine 1";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 1] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 1] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.9;
        };
        class AGM_reloadMagazine2 {
          displayName = "Magazine 2";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 2] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 2] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.8;
        };
        class AGM_reloadMagazine3 {
          displayName = "Magazine 3";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 3] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 3] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.7;
        };
        class AGM_reloadMagazine4 {
          displayName = "Magazine 4";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 4] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 4] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.6;
        };
        class AGM_reloadMagazine5 {
          displayName = "Magazine 5";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 5] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 5] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.5;
        };
        class AGM_reloadMagazine6 {
          displayName = "Magazine 6";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 6] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 6] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.4;
        };
        class AGM_reloadMagazine7 {
          displayName = "Magazine 7";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 7] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 7] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.3;
        };
        class AGM_reloadMagazine8 {
          displayName = "Magazine 8";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 8] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 8] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.2;
        };
        class AGM_reloadMagazine9 {
          displayName = "Magazine 9";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 9] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 9] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.1;
        };
      };
    };
  };
};


// Handle vehicle magazines

class CfgMagazines {
  class CA_LauncherMagazine;
  class Titan_AA : CA_LauncherMagazine {
    AGM_MagazineReloadType = 1;
    AGM_Magazines[] = {"4Rnd_Titan_long_missiles"};
  };

  class Titan_AP : Titan_AA {
    AGM_Magazines[] = {};
  };

  class Titan_AT : Titan_AA {
    AGM_Magazines[] = {};
  };
};

class CfgWeapons {
  class MissileLauncher;
  class missiles_titan : MissileLauncher {
    AGM_Magazines[] = {"Titan_AA"};
  };
};
