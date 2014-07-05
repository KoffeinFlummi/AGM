class CfgPatches {
  class AGM_Repair {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
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

class CfgVehicles {
  class Car;
  class LandVehicle: Car{

  class HitPoints {
  
    class HitLFWheel{
    armor = 0.7;
    explosionShielding = 1;
    material = -1;
    name = "wheel_1_1_steering";
    passThrough = 0.3;
    visual = "";   
    };

    class HitLF2Wheel{
	  armor = 0.7;
	  explosionShielding = 1;
	  material = -1;
	  name = "wheel_1_2_steering";
	  passThrough = 0.3;
	  visual = "";		
    };

    class HitRFWheel{
    armor = 0.7;
    explosionShielding = 1;
    material = -1;
    name = "wheel_2_1_steering";
    passThrough = 0.3;
    visual = "";   
    };

    class HitRF2Wheel{
    armor = 0.7;
    explosionShielding = 1;
    material = -1;
    name = "wheel_2_2_steering";
    passThrough = 0.3;
    visual = "";    
    };
	
	class HitEngine{
    armor = 0.8;
    explosionShielding = 0.2;
    material = -1;
    name = "motor";
    passThrough = 0;
    visual = "";    
    };
	
	class HitFuel{
    armor = 0.6;
    explosionShielding = 0.2;
    material = -1;
    name = "palivo";
    passThrough = 1;
    visual = "";    
    };
	
	class HitBody{
    armor = 1;
    explosionShielding = 0.2;
    material = -1;
    name = "karoserie";
    passThrough = 1;
    visual = "";   
    };
  };
};
  

  class Car_F;
  //BLUFOR 
  class MRAP_01_base_F : Car_F{

    class AGM_Actions {
  
      class AGM_Repair_LFWheel {
        displayName = "$STR_AGM_Repair_LFWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLFWheel' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLFWheel', 'wheel_1_1_steering', player] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.1;
      };

      class AGM_Repair_LBWheel {
        displayName = "$STR_AGM_Repair_LBWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLF2Wheel' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLF2Wheel', 'wheel_1_2_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.2;
      };

      class AGM_Repair_RFWheel {
        displayName = "$STR_AGM_Repair_RFWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRFWheel' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRFWheel', 'wheel_2_1_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.3;
      };

      class AGM_Repair_RBWheel {
        displayName = "$STR_AGM_Repair_RBWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRF2Wheel' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRF2Wheel', 'wheel_2_2_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.4;
      };
	  
	  class AGM_Repair_Engine {
        displayName = "$STR_AGM_Repair_Engine";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitEngine' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitEngine', 'motor'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };
	  
	  class AGM_Repair_Fuel {
        displayName = "$STR_AGM_Repair_Fuel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitFuel' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitFuel', 'palivo'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };
	  
	  class AGM_Repair_Body {
        displayName = "$STR_AGM_Repair_Body";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitBody' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitBody', 'karoserie'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.6;
      };

      class AGM_Repair_checkVehicle {
        displayName = "$STR_AGM_Repair_checkVehicle";
        distance = 4;
        condition = "damage AGM_Interaction_Target < 1";
        statement = "[AGM_Interaction_Target] call AGM_Repair_checkVehicle;";
        showDisabled = 1;
        priority = 1.0;
      };
    };
  };

  //OPFOR
  class O_MRAP_02_F : Car_F{

    class AGM_Actions {
  
      class AGM_Repair_LFWheel {
        displayName = "$STR_AGM_Repair_LFWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLFWheel', 'wheel_1_1_steering', player] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.1;
      };

      class AGM_Repair_LBWheel {
        displayName = "$STR_AGM_Repair_LBWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLF2Wheel', 'wheel_1_2_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.2;
      };

      class AGM_Repair_RFWheel {
        displayName = "$STR_AGM_Repair_RFWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRFWheel', 'wheel_2_1_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.3;
      };

      class AGM_Repair_RBWheel {
        displayName = "$STR_AGM_Repair_RBWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRF2Wheel', 'wheel_2_2_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.4;
      };
	  
	  class AGM_Repair_Engine {
        displayName = "$STR_AGM_Repair_Engine";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'motor' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitEngine', 'motor'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };
	  
	  class AGM_Repair_Fuel {
        displayName = "$STR_AGM_Repair_Fuel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'palivo' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitFuel', 'palivo'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };

      class AGM_Repair_checkVehicle {
        displayName = "$STR_AGM_Repair_checkVehicle";
        distance = 4;
        condition = "damage AGM_Interaction_Target < 1";
        statement = "[AGM_Interaction_Target] call AGM_Repair_checkVehicle;";
        showDisabled = 1;
        priority = 1.0;
      };
	  
	  class AGM_Repair_Body {
        displayName = "$STR_AGM_Repair_Body";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitBody' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitBody', 'karoserie'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.6;
      };
    };
  };
  //INDEP
  class MRAP_03_base_F : Car_F{

    class AGM_Actions {
  
      class AGM_Repair_LFWheel {
        displayName = "$STR_AGM_Repair_LFWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLFWheel', 'wheel_1_1_steering', player] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.1;
      };

      class AGM_Repair_LBWheel {
        displayName = "$STR_AGM_Repair_LBWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLF2Wheel', 'wheel_1_2_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.2;
      };

      class AGM_Repair_RFWheel {
        displayName = "$STR_AGM_Repair_RFWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRFWheel', 'wheel_2_1_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.3;
      };

      class AGM_Repair_RBWheel {
        displayName = "$STR_AGM_Repair_RBWheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRF2Wheel', 'wheel_2_2_steering'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.4;
      };
	  
	  class AGM_Repair_Engine {
        displayName = "$STR_AGM_Repair_Engine";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'motor' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitEngine', 'motor'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };
	  
	  class AGM_Repair_Fuel {
        displayName = "$STR_AGM_Repair_Fuel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'palivo' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitFuel', 'palivo'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.5;
      };

      class AGM_Repair_checkVehicle {
        displayName = "$STR_AGM_Repair_checkVehicle";
        distance = 4;
        condition = "damage AGM_Interaction_Target < 1";
        statement = "[AGM_Interaction_Target] call AGM_Repair_checkVehicle;";
        showDisabled = 1;
        priority = 1.0;
      };
	  
	  class AGM_Repair_Body {
        displayName = "$STR_AGM_Repair_Body";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitBody' > 0.01) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitBody', 'karoserie'] call AGM_Repair_Vehicle;";
        showDisabled = 1;
        priority = 0.6;
      };
    };
  };
};

/*class CfgWeapons {						//Removes the ability to repair vehicles and disarm explosives. If you want to use this function, remove the "/*" and "* /".
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

