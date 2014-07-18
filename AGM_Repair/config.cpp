class CfgPatches {
  class AGM_Repair {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction, AGM_Drag};
    version = "0.93";
    versionStr = "0.93";
    versionAr[] = {0,9,0};
    author[] = {"marc_book"};
    authorUrl = "https://github.com/MarcBook/";
  };
};

class CfgFunctions {
  class AGM_Repair {
    class AGM_Repair {
      file = "AGM_Repair\functions";
      class canRepair;
      class checkVehicle;
      /*class canRepairTrack;
      class canRepairWheel;*/
      class openSelectWheelUI;
      class repair;
      class repairAbort;
      class repairCallback;
      /*class repairTrack;
      class repairWheel;*/
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Repair {
    clientInit = "call compile preprocessFileLineNumbers 'AGM_Repair\clientInit.sqf'";
  };
};

class CfgAddons {
  class AGM_Repair_Items {
    list[] = {"AGM_Repair_Track", "AGM_Repair_Wheel"};
  };
};

class CfgVehicleClasses {
  class AGM_Repair_Items {
    displayName = "AGM";
  };
};

/*
HitBody
HitEngine
HitFuel
HitTurret
HitGun
HitAvionics
HitHRotor
HitVRotor
*/

class CfgVehicles {
  class LandVehicle;
  class Air;

  class Car: LandVehicle {
    class AGM_Actions;
  };
  class Tank: LandVehicle {
    class AGM_Actions;
  };

  class Car_F: Car {
    class AGM_Actions: AGM_Actions {

      class AGM_Repair {
        displayName = "$STR_AGM_Repair";
        distance = 4;
        condition = "alive AGM_Interaction_Target";
        statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
        showDisabled = 1;
        priority = 1;

        class AGM_Repair_checkVehicle {
          displayName = "$STR_AGM_Repair_checkVehicle";
          distance = 4;
          condition = "alive AGM_Interaction_Target";
          statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle";
          showDisabled = 1;
          priority = 1;
        };
        class AGM_Repair_Wheels {
          displayName = "$STR_AGM_Repair_Wheels";
          distance = 4;
          condition = "alive AGM_Interaction_Target";
          statement = "[AGM_Interaction_Target, ['HitLFWheel', 'HitLBWheel', 'HitLMWheel', 'HitLF2Wheel', 'HitRFWheel', 'HitRBWheel', 'HitRMWheel', 'HitRF2Wheel']] call AGM_Repair_fnc_openSelectWheelUI";
          showDisabled = 0;
          priority = 0.9;
        };
        class AGM_Repair_Body {
          displayName = "$STR_AGM_Repair_Body";
          distance = 4;
          condition = "[AGM_Interaction_Target, 'HitBody'] call AGM_Repair_fnc_canRepair";
          statement = "[AGM_Interaction_Target, 'HitBody'] call AGM_Repair_fnc_repair";
          showDisabled = 0;
          priority = 0.5;
        };
        class AGM_Repair_Engine {
          displayName = "$STR_AGM_Repair_Engine";
          distance = 4;
          condition = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_canRepair";
          statement = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_repair";
          showDisabled = 0;
          priority = 0.4;
        };
        class AGM_Repair_Fuel {
          displayName = "$STR_AGM_Repair_Fuel";
          distance = 4;
          condition = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_canRepair";
          statement = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_repair";
          showDisabled = 0;
          priority = 0.3;
        };
        class AGM_OpenUIDummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -9;
        };
      };
    };
  };

  class Tank_F: Tank {
    class AGM_Actions: AGM_Actions {
    };
  };
  
  class Truck_F: Car_F {
    class AGM_Actions: AGM_Actions {
    };
  };
  
  class Helicopter: Air {
    class AGM_Actions {
    };
  };

  class Plane: Air {
    class AGM_Actions {
    };
  };

  class Thing;
  class AGM_Repair_Track: Thing {
    scope = 2;
    model = "\AGM_Repair\track.p3d";
    icon = "iconObject_circle";
    displayName = "Track";
    mapSize = 0.7;
    accuracy = 0.2;
    vehicleClass = "AGM_Repair_Items";
    destrType = "DesturctNo";

    class AGM_Actions {
      class AGM_DragItem {
      displayName = "$STR_AGM_Drag_StartDrag";
      distance = 4;
      condition = "!(player call AGM_Drag_fnc_isDraggingObject) AND {[AGM_Interaction_Target, player] call AGM_Drag_fnc_isDraggable}";
      statement = "[AGM_Interaction_Target, player] call AGM_Drag_fnc_dragObject;";
      showDisabled = 1;
      priority = 2.2;
      };
      class AGM_ReleaseItem {
      displayName = "$STR_AGM_Drag_EndDrag";
      distance = 4;
      condition = "(player call AGM_Drag_fnc_isDraggingObject)";
      statement = "player call AGM_Drag_fnc_releaseObject;";
      showDisabled = 0;
      priority = 2.1;
      };
    };
  };

  class AGM_Repair_Wheel: Thing {
    scope = 2;
    model = "\AGM_Repair\wheel.p3d";
    icon = "iconObject_circle";
    displayName = "Wheel";
    mapSize = 0.7;
    accuracy = 0.2;
    vehicleClass = "AGM_Repair_Items";
    destrType = "DesturctNo";

    class AGM_Actions {
      class AGM_DragItem {
      displayName = "$STR_AGM_Drag_StartDrag";
      distance = 4;
      condition = "!(player call AGM_Drag_fnc_isDraggingObject) AND {[AGM_Interaction_Target, player] call AGM_Drag_fnc_isDraggable}";
      statement = "[AGM_Interaction_Target, player] call AGM_Drag_fnc_dragObject;";
      showDisabled = 1;
      priority = 2.2;
      };
      class AGM_ReleaseItem {
      displayName = "$STR_AGM_Drag_EndDrag";
      distance = 4;
      condition = "(player call AGM_Drag_fnc_isDraggingObject)";
      statement = "player call AGM_Drag_fnc_releaseObject;";
      showDisabled = 0;
      priority = 2.1;
      };
    };
  };
};

/*
class CfgWeapons {						//Removes the ability to repair vehicles and disarm explosives. If you want to use this function, remove the "/ *" and "* /".
  class ItemCore;
  class InventoryItem_Base_F;
  
  class ToolKit: ItemCore {
  class ItemInfo: InventoryItem_Base_F {
      mass = 80;
      type = 401;
    };
  };
};
*/

