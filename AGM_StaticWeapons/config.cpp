class CfgPatches {
	class AGM_StaticWeapons {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core, AGM_Interaction};
		version = "0.92";
		versionStr = "0.92";
		versionAr[] = {0,92,0};
		author[] = {"commy2"};
		authorUrl = "https://github.com/commy2/";
	};
};

class CfgFunctions {
	class AGM_StaticWeapons {
		class AGM_StaticWeapons {
			file = "AGM_StaticWeapons\functions";
			class canGetIn;
			class canRotate;
			class getIn;
			class rotate;
		};
	};
};

class CfgVehicles {
	class LandVehicle;
	class StaticWeapon: LandVehicle {
		class AGM_Actions {
			class AGM_GetIn {
				displayName = "$STR_AGM_StaticWeapons_GetIn";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_StaticWeapons_fnc_canGetIn";
				statement = "[AGM_Interaction_Target] call AGM_StaticWeapons_fnc_getIn";
				showDisabled = 0;
				priority = 1;
			};
			class AGM_RotateClockwise {
				displayName = "$STR_AGM_StaticWeapons_RotateClockwise";
				distance = 4;
				condition = "[AGM_Interaction_Target, true] call AGM_StaticWeapons_fnc_canRotate";
				statement = "[AGM_Interaction_Target, true] call AGM_StaticWeapons_fnc_rotate";
				showDisabled = 1;
				priority = 2.1;
			};
			class AGM_RotateCounterclockwise {
				displayName = "$STR_AGM_StaticWeapons_RotateCounterclockwise";
				distance = 4;
				condition = "[AGM_Interaction_Target, false] call AGM_StaticWeapons_fnc_canRotate";
				statement = "[AGM_Interaction_Target, false] call AGM_StaticWeapons_fnc_rotate";
				showDisabled = 1;
				priority = 2;
			};
		};
	};

	class StaticMortar;
	class Mortar_01_base_F: StaticMortar {
		class AGM_Actions {
			class AGM_GetIn {
				displayName = "$STR_AGM_StaticWeapons_GetIn";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_StaticWeapons_fnc_canGetIn";
				statement = "[AGM_Interaction_Target] call AGM_StaticWeapons_fnc_getIn";
				showDisabled = 0;
				priority = 1;
			};
			class AGM_RotateClockwise {
				displayName = "$STR_AGM_StaticWeapons_RotateClockwise";
				distance = 4;
				condition = "[AGM_Interaction_Target, true] call AGM_StaticWeapons_fnc_canRotate";
				statement = "[AGM_Interaction_Target, true] call AGM_StaticWeapons_fnc_rotate";
				showDisabled = 1;
				priority = 2.1;
			};
			class AGM_RotateCounterclockwise {
				displayName = "$STR_AGM_StaticWeapons_RotateCounterclockwise";
				distance = 4;
				condition = "[AGM_Interaction_Target, false] call AGM_StaticWeapons_fnc_canRotate";
				statement = "[AGM_Interaction_Target, false] call AGM_StaticWeapons_fnc_rotate";
				showDisabled = 1;
				priority = 2;
			};
		};
	};
};
