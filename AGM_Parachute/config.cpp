class CfgPatches {
	class AGM_Parachute {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core, AGM_Interaction};
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
		};
	};
};