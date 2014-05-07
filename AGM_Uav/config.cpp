class CfgPatches {
  class AGM_Uav {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Air_F_Gamma_UAV_01, AGM_Core, AGM_Interaction};
    version = 1.0;
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
				displayName = "Refuel";
				distance = 4;
				condition = "true";
				statement = "[AGM_Interaction_Target, player] execVM ""AGM_Uav\scripts\refuel.sqf"";";
				showDisabled = 0;
				priority = -2.5;
				};
			};
	  };
};