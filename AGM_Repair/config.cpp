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

class Extended_PostInit_EventHandlers {
  class AGM_Repair {
    clientInit = "execVM 'AGM_Repair\init.sqf'";
  };
};

class CfgAddons {
  class AGM_Repair_Track {
    list[] = {"AGM"};
  };
};

class CfgVehicleClasses {
  class AGM_Repair_Track {
    displayName = "AGM";
  };
};

class CfgVehicles {
  class Car;
  class Tank;

  class Car_F: Car {
    class AGM_Actions {
  
      class AGM_Repair_L1Wheel {
        displayName = "$STR_AGM_Repair_L1Wheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLFWheel', 'wheel_1_1_steering', player] call AGM_Repair_fnc_repairWheel;";
        showDisabled = 1;
        priority = 0.9;
      };

      class AGM_Repair_L2Wheel {
        displayName = "$STR_AGM_Repair_L2Wheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLF2Wheel', 'wheel_1_2_steering'] call AGM_Repair_fnc_repairWheel;";
        showDisabled = 1;
        priority = 0.8;
      };

      class AGM_Repair_R1Wheel {
        displayName = "$STR_AGM_Repair_R1Wheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRFWheel', 'wheel_2_1_steering'] call AGM_Repair_fnc_repairWheel;";
        showDisabled = 1;
        priority = 0.7;
      };

      class AGM_Repair_R2Wheel {
        displayName = "$STR_AGM_Repair_R2Wheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRF2Wheel', 'wheel_2_2_steering'] call AGM_Repair_fnc_repairWheel;";
        showDisabled = 1;
        priority = 0.6;
      };
	  
	  class AGM_Repair_Engine {
        displayName = "$STR_AGM_Repair_Engine";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitEngine' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitEngine', 'motor'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };
	  
	  class AGM_Repair_Fuel {
        displayName = "$STR_AGM_Repair_Fuel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitFuel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitFuel', 'palivo'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.4;
      };
	  
	  class AGM_Repair_Body {
        displayName = "$STR_AGM_Repair_Body";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitBody' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitBody', 'karoserie'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.3;
      };

      class AGM_Repair_checkVehicle {
        displayName = "$STR_AGM_Repair_checkVehicle";
        distance = 4;
        condition = "damage AGM_Interaction_Target < 1";
        statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle;";
        showDisabled = 1;
        priority = 1.0;
      };
    };
  };
  
  class Tank_F: Tank {
    class AGM_Actions {
	
        class AGM_Repair_HitLTrack {
          displayName = "$STR_AGM_Repair_HitLTrack";
          distance = 4;
          condition = "(AGM_Interaction_Target getHitPointDamage 'HitLTrack' > 0.1) && (damage AGM_Interaction_Target < 1)";
          statement = "[AGM_Interaction_Target, 'HitLTrack', 'track_l_hit', player] call AGM_Repair_fnc_repairTrack;";
          showDisabled = 1;
          priority = 0.1;
        };

        class AGM_Repair_HitRTrack {
          displayName = "$STR_AGM_Repair_HitRTrack";
          distance = 4;
          condition = "(AGM_Interaction_Target getHitPointDamage 'HitRTrack' > 0.1) && (damage AGM_Interaction_Target < 1)";
          statement = "[AGM_Interaction_Target, 'HitRTrack', 'track_r_hit'] call AGM_Repair_fnc_repairTrack;";
          showDisabled = 1;
          priority = 0.2;
        };
  	  
  	  class AGM_Repair_Engine {
        displayName = "$STR_AGM_Repair_Engine";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitEngine' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitEngine', 'engine_hit'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.3;
      };
  	  
  	  class AGM_Repair_Body {
        displayName = "$STR_AGM_Repair_Body";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitHull' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitHull', 'hull_hit'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.4;
      };

      class AGM_Repair_Turret {
        displayName = "$STR_AGM_Repair_Turret";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitTurret' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitTurret', 'main_turret_hit'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };

      class AGM_Repair_Gun {
        displayName = "$STR_AGM_Repair_Gun";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitGun' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitGun', 'main_gun_hit'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.6;
      };

      class AGM_Repair_checkVehicle {
        displayName = "$STR_AGM_Repair_checkVehicle";
        distance = 4;
        condition = "damage AGM_Interaction_Target < 1";
        statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle;";
        showDisabled = 1;
        priority = 1.0;
      };
    };
  };
  
  class Truck_F: Car_F {
    class AGM_Actions {
	  class AGM_Repair_Wheels{
		displayName = "$STR_AGM_Repair_Wheels";
		condition = "true";
		statement = "'AGM_Repair_Wheels' call AGM_Interaction_fnc_openMenu;";
		distance = 4;
		showDisabled = 1;
		priority = 0.9;
	    
  		class AGM_Repair_L1Wheel {
            displayName = "$STR_AGM_Repair_L1Wheel";
            distance = 4;
            condition = "(AGM_Interaction_Target getHitPointDamage 'HitLFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
            statement = "[AGM_Interaction_Target, 'HitLFWheel', 'wheel_1_1_steering', player] call AGM_Repair_fnc_repairWheel;";
            showDisabled = 1;
            priority = 1;
  		};

  		class AGM_Repair_R1Wheel {
            displayName = "$STR_AGM_Repair_R1Wheel";
            distance = 4;
            condition = "(AGM_Interaction_Target getHitPointDamage 'HitRFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
            statement = "[AGM_Interaction_Target, 'HitRFWheel', 'wheel_2_1_steering'] call AGM_Repair_fnc_repairWheel;";
            showDisabled = 1;
            priority = 0.9;
  		};
  		
  		class AGM_Repair_L2Wheel {
            displayName = "$STR_AGM_Repair_L2Wheel";
            distance = 4;
            condition = "(AGM_Interaction_Target getHitPointDamage 'HitLF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
            statement = "[AGM_Interaction_Target, 'HitLF2Wheel', 'wheel_1_2_steering'] call AGM_Repair_fnc_repairWheel;";
            showDisabled = 1;
            priority = 0.8;
  		};

  		class AGM_Repair_R2Wheel {
            displayName = "$STR_AGM_Repair_R2Wheel";
            distance = 4;
            condition = "(AGM_Interaction_Target getHitPointDamage 'HitRF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
            statement = "[AGM_Interaction_Target, 'HitRF2Wheel', 'wheel_2_2_steering'] call AGM_Repair_fnc_repairWheel;";
            showDisabled = 1;
            priority = 0.7;
  		};
  		
  		class AGM_Repair_L3Wheel {
            displayName = "$STR_AGM_Repair_L3Wheel";
            distance = 4;
            condition = "(AGM_Interaction_Target getHitPointDamage 'HitLMWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
            statement = "[AGM_Interaction_Target, 'HitLMWheel', 'wheel_1_3_steering', player] call AGM_Repair_fnc_repairWheel;";
            showDisabled = 1;
            priority = 0.5;
  		};

  		class AGM_Repair_R3Wheel {
            displayName = "$STR_AGM_Repair_R3Wheel";
            distance = 4;
            condition = "(AGM_Interaction_Target getHitPointDamage 'HitRMWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
            statement = "[AGM_Interaction_Target, 'HitRMWheel', 'wheel_2_3_steering'] call AGM_Repair_fnc_repairWheel;";
            showDisabled = 1;
            priority = 0.4;
  		};
  		
  		class AGM_Repair_L4Wheel {
            displayName = "$STR_AGM_Repair_L4Wheel";
            distance = 4;
            condition = "(AGM_Interaction_Target getHitPointDamage 'HitLBWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
            statement = "[AGM_Interaction_Target, 'HitLBWheel', 'wheel_1_4_steering'] call AGM_Repair_fnc_repairWheel;";
            showDisabled = 1;
            priority = 0.3;
  		};
  	  
  		class AGM_Repair_R4Wheel {
            displayName = "$STR_AGM_Repair_R4Wheel";
            distance = 4;
            condition = "(AGM_Interaction_Target getHitPointDamage 'HitRBWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
            statement = "[AGM_Interaction_Target, 'HitRBWheel', 'wheel_2_4_steering'] call AGM_Repair_fnc_repairWheel;";
            showDisabled = 1;
            priority = 0.2;
  		};
	  };
	  
	  class AGM_Repair_Engine {
        displayName = "$STR_AGM_Repair_Engine";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitEngine' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitEngine', 'motor'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.9;
      };
	  
      class AGM_Repair_Fuel {
        displayName = "$STR_AGM_Repair_Fuel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitFuel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitFuel', 'palivo'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.8;
      };
	  
	  class AGM_Repair_Body {
        displayName = "$STR_AGM_Repair_Body";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitBody' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitBody', 'karoserie'] call AGM_Repair_fnc_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };

      class AGM_Repair_checkVehicle {
        displayName = "$STR_AGM_Repair_checkVehicle";
        distance = 4;
        condition = "damage AGM_Interaction_Target < 1";
        statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle;";
        showDisabled = 1;
        priority = 1.0;
      };
	  };
  };
  
  class thingX;
  class Land_Tyre_F: thingX {
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
  
  class Thing;
  class AGM_Repair_Track: Thing {
    scope = 2;
    model = "\AGM_Repair\track.p3d";
    icon = "iconObject_circle";
    displayName = "Track";
    mapSize = 0.7;
    accuracy = 0.2;
    vehicleClass = "AGM_Repair_Track";
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
class CfgWeapons {						//Removes the ability to repair vehicles and disarm explosives. If you want to use this function, remove the "/*" and "* /".
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

