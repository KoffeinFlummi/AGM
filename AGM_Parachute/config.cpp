class CfgPatches {
	class AGM_Parachute {
		units[] = {};
		weapons[] = {"AGM_Altimeter"};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core};
		version = "0.94";
		versionStr = "0.94";
		versionAr[] = {0,94,0};
		author[] = {"Garth 'LH' de Wet"};
	};
};

class CfgFunctions {	
	class AGM_Parachute {
		class AGM_Parachute {
			file = "\AGM_Parachute\functions";
			class Init{postInit = 1;};
			class onEachFrame;
			class doLanding;
			class hideAltimeter;
			class showAltimeter;
		};
	};
};

class AGM_Core_Default_Keys {
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
};

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
};
