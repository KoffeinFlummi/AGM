class CfgPatches {
  class AGM_Repair {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction, AGM_Logistics};
    version = "0.9";
    versionStr = "0.9";
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
  };
};
  
  // WEST
  class MRAP_01_base_F;
  class B_MRAP_01_F : MRAP_01_base_F{

    class AGM_Actions {
  
      class AGM_Repair_LFWheel {
        displayName = "Repair LF Wheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLFWheel', 'wheel_1_1_steering', player] call AGM_Repair_Wheel;";
        showDisabled = 1;
        priority = 0.1;
      };

      class AGM_Repair_LBWheel {
        displayName = "Repair LB Wheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitLF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitLF2Wheel', 'wheel_1_2_steering'] call AGM_Repair_Wheel;";
        showDisabled = 1;
        priority = 0.2;
      };

      class AGM_Repair_RFWheel {
        displayName = "Repair RF Wheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRFWheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRFWheel', 'wheel_2_1_steering'] call AGM_Repair_Wheel;";
        showDisabled = 1;
        priority = 0.3;
      };

      class AGM_Repair_RBWheel {
        displayName = "Repair RB Wheel";
        distance = 4;
        condition = "(AGM_Interaction_Target getHitPointDamage 'HitRF2Wheel' > 0.1) && (damage AGM_Interaction_Target < 1)";
        statement = "[AGM_Interaction_Target, 'HitRF2Wheel', 'wheel_2_2_steering'] call AGM_Repair_Wheel;";
        showDisabled = 1;
        priority = 0.4;
      };

      class AGM_Repair_checkVehicle {
        displayName = "check Vehicle";
        distance = 4;
        condition = "damage AGM_Interaction_Target < 1";
        statement = "[AGM_Interaction_Target] call AGM_Repair_checkVehicle;";
        showDisabled = 1;
        priority = 1.0;
      };

    };
  };

  //EAST

};

