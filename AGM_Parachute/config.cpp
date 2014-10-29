class CfgPatches {
	class AGM_Parachute {
		units[] = {"AGM_NonSteerableParachute"};
		weapons[] = {"AGM_Altimeter"};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core};
		version = "0.94.1";
		versionStr = "0.94.1";
		versionAr[] = {0,94,1};
		author[] = {"Garth 'LH' de Wet"};
	};
};

class CfgFunctions {	
	class AGM_Parachute {
		class AGM_Parachute {
			file = "\AGM_Parachute\functions";
			class onEachFrame;
			class doLanding;
			class hideAltimeter;
			class showAltimeter;
		};
	};
};

class Extended_PostInit_EventHandlers {
  class AGM_Parachute {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Parachute\clientInit.sqf';";
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_Parachute_Altimeter {
      clientInit = "_this call compile preprocessFileLineNumbers '\AGM_Parachute\initActions.sqf';";
    };
  };
};

/*class AGM_Core_Default_Keys {
	class showAltimeter {
		displayName = "$STR_AGM_Parachute_showAltimeter";
		condition = "(alive _player) && {'AGM_Altimeter' in assignedItems _player}";
		statement = "[_player] call AGM_Parachute_fnc_showAltimeter;";
		conditionUp = "true";
		statementUp = "call AGM_Parachute_fnc_hideAltimeter;";
		exceptions[] = {"AGM_Drag_isNotDragging", "AGM_Medical_canTreat", "AGM_Interaction_isNotEscorting"};
		key = 35;
		shift = 0;
		control = 1;
		alt = 0;
	};
};*/

#include "RscTitles.hpp"

class CfgWeapons {
	class ItemWatch;
	class AGM_Altimeter:ItemWatch {
		author = "AGM";
		descriptionShort = "$STR_AGM_Parachute_AltimeterDescription";
		displayName = "$STR_AGM_Parachute_AltimeterDisplayName";
		picture = "\AGM_Parachute\UI\watch_altimeter.paa";
	};
};

class CfgVehicles {
	class Box_NATO_Support_F;
	class AGM_Box_Misc: Box_NATO_Support_F {
		class TransportItems {
			class _xx_AGM_Altimeter {
				name = "AGM_Altimeter";
				count = 6;
			};
		};
	};

	class B_Parachute;
	class AGM_NonSteerableParachute: B_Parachute {
		author = "$STR_AGM_Core_AGMTeam";
		scope = 2;
		displayName = "$STR_AGM_Parachute_NonSteerableParachute";
		//picture = "\A3\Characters_F\data\ui\icon_b_parachute_ca.paa";	// @todo
		//model = "\A3\Weapons_F\Ammoboxes\Bags\Backpack_Parachute";	// @todo
		backpackSimulation = "ParachuteNonSteerable";	//ParachuteSteerable
		ParachuteClass = "NonSteerable_Parachute_F";
		maximumLoad = 0;
		mass = 100;
	};

	class Parachute;
	class NonSteerable_Parachute_F: Parachute {
		model = "\A3\Air_F_Beta\Parachute_02\Parachute_02_F.p3d";
	};
};
