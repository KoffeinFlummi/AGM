class CfgPatches {
	class AGM_Parachute {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core};
		version = "0.931";
		versionStr = "0.931";
		versionAr[] = {0,931,0};
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
		condition = "alive _player";
		statement = "[_player] call AGM_Parachute_fnc_showAltimeter;";
		conditionUp = "true";
		statementUp = "call AGM_Parachute_fnc_hideAltimeter;";
		exceptions[] = {"AGM_Drag_isNotDragging", "AGM_Medical_canTreat", "AGM_Interaction_isNotEscorting"};
		key = 20;
		shift = 0;
		control = 0;
		alt = 0;
	};
};

#include "RscTitles.hpp"