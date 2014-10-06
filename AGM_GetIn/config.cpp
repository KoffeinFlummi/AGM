class CfgPatches {
	class AGM_GetIn {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core, AGM_Interaction};
		version = "0.931";
		versionStr = "0.931";
		versionAr[] = {0,931,0};
		author[] = {"commy2"};
		authorUrl = "https://github.com/commy2/";
	};
};

class CfgFunctions {
	class AGM_GetIn {
		class AGM_GetIn {
			file = "AGM_GetIn\functions";
			class canGetInCoDriver;
			class canGetInDriver;
			class canGetInGunner;
			class canGetInCommander;
			class canGetInPilot;
			class canGetInTurret;
			class canGetInCargo;
			class getInCoDriver;
			class getInDriver;
			class getInGunner;
			class getInCommander;
			class getInPilot;
			class getInTurret;
			class getInCargo;
		};
	};
};

class CfgVehicles {
	class LandVehicle;
	/*class StaticWeapon: LandVehicle {
		class AGM_Actions {
			class AGM_GetIn {
				displayName = "$STR_AGM_GetInVehicle";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
				showDisabled = 0;
				priority = -1.91;
			};
		};
	};

	class StaticMortar;
	class Mortar_01_base_F: StaticMortar {
		class AGM_Actions {
			class AGM_GetIn {
				displayName = "$STR_AGM_GetInVehicle";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
				showDisabled = 0;
				priority = -1.91;
			};
		};
	};*/

	class Car: LandVehicle {
		class AGM_Actions {
			class AGM_GetInDriver {
				displayName = "$STR_AGM_GetInVehicleAsDriver";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInDriver";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInDriver";
				showDisabled = 0;
				priority = -1.90;
				icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
			};
			class AGM_GetInGunner {
				displayName = "$STR_AGM_GetInVehicleAsGunner";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
				showDisabled = 0;
				priority = -1.91;
				icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
			};
			class AGM_GetInCommander {
				displayName = "$STR_AGM_GetInVehicleAsCommander";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCommander";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInCommander";
				showDisabled = 0;
				priority = -1.92;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
			};
			class AGM_GetInCargo {
				displayName = "$STR_AGM_GetInVehicleAsCargo";
				distance = 4;
				condition = "[AGM_Interaction_Target, -1] call AGM_GetIn_fnc_canGetInCargo";
				statement = "[AGM_Interaction_Target, -1] call AGM_GetIn_fnc_getInCargo";
				showDisabled = 0;
				priority = -1.93;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
			};
			class AGM_GetInCoDriver {
				displayName = "$STR_AGM_GetInVehicleAsCoDriver";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCoDriver";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInCoDriver";
				showDisabled = 0;
				priority = -1.94;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
			};
		};
		class AGM_SelfActions {
			class AGM_MoveToDriver {
				displayName = "$STR_AGM_MoveToDriver";
				condition = "[vehicle player] call AGM_GetIn_fnc_canGetInDriver";
				statement = "[vehicle player] call AGM_GetIn_fnc_getInDriver";
				showDisabled = 0;
				priority = -1.90;
				icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
				enableInside = 1;
			};
			class AGM_MoveToGunner {
				displayName = "$STR_AGM_MoveToGunner";
				condition = "[vehicle player] call AGM_GetIn_fnc_canGetInGunner";
				statement = "[vehicle player] call AGM_GetIn_fnc_getInGunner";
				showDisabled = 0;
				priority = -1.91;
				icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
				enableInside = 1;
			};
			class AGM_MoveToCommander {
				displayName = "$STR_AGM_MoveToCommander";
				condition = "[vehicle player] call AGM_GetIn_fnc_canGetInCommander";
				statement = "[vehicle player] call AGM_GetIn_fnc_getInCommander";
				showDisabled = 0;
				priority = -1.92;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
				enableInside = 1;
			};
			class AGM_MoveToCargo {
				displayName = "$STR_AGM_MoveToCargo";
				condition = "[vehicle player, -1] call AGM_GetIn_fnc_canGetInCargo";
				statement = "[vehicle player, -1] call AGM_GetIn_fnc_getInCargo";
				showDisabled = 0;
				priority = -1.93;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
				enableInside = 1;
			};
			class AGM_MoveToCoDriver {
				displayName = "$STR_AGM_MoveToCoDriver";
				condition = "[vehicle player] call AGM_GetIn_fnc_canGetInCoDriver";
				statement = "[vehicle player] call AGM_GetIn_fnc_getInCoDriver";
				showDisabled = 0;
				priority = -1.94;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
				enableInside = 1;
			};
		};
	};

	class Tank: LandVehicle {
		class AGM_Actions {
			class AGM_GetInDriver {
				displayName = "$STR_AGM_GetInVehicleAsDriver";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInDriver";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInDriver";
				showDisabled = 0;
				priority = -1.90;
				icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
			};
			class AGM_GetInGunner {
				displayName = "$STR_AGM_GetInVehicleAsGunner";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
				showDisabled = 0;
				priority = -1.91;
				icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
			};
			class AGM_GetInCommander {
				displayName = "$STR_AGM_GetInVehicleAsCommander";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCommander";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInCommander";
				showDisabled = 0;
				priority = -1.92;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
			};
			class AGM_GetInCargo {
				displayName = "$STR_AGM_GetInVehicleAsCargo";
				distance = 4;
				condition = "[AGM_Interaction_Target, -1] call AGM_GetIn_fnc_canGetInCargo";
				statement = "[AGM_Interaction_Target, -1] call AGM_GetIn_fnc_getInCargo";
				showDisabled = 0;
				priority = -1.93;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
			};
			class AGM_GetInCoDriver {
				displayName = "$STR_AGM_GetInVehicleAsCoDriver";
				distance = 4;
				condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCoDriver";
				statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInCoDriver";
				showDisabled = 0;
				priority = -1.94;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
			};
		};
		class AGM_SelfActions {
			class AGM_MoveToDriver {
				displayName = "$STR_AGM_MoveToDriver";
				condition = "[vehicle player] call AGM_GetIn_fnc_canGetInDriver";
				statement = "[vehicle player] call AGM_GetIn_fnc_getInDriver";
				showDisabled = 0;
				priority = -1.90;
				icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
				enableInside = 1;
			};
			class AGM_MoveToGunner {
				displayName = "$STR_AGM_MoveToGunner";
				condition = "[vehicle player] call AGM_GetIn_fnc_canGetInGunner";
				statement = "[vehicle player] call AGM_GetIn_fnc_getInGunner";
				showDisabled = 0;
				priority = -1.91;
				icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
				enableInside = 1;
			};
			class AGM_MoveToCommander {
				displayName = "$STR_AGM_MoveToCommander";
				condition = "[vehicle player] call AGM_GetIn_fnc_canGetInCommander";
				statement = "[vehicle player] call AGM_GetIn_fnc_getInCommander";
				showDisabled = 0;
				priority = -1.92;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
				enableInside = 1;
			};
			class AGM_MoveToCargo {
				displayName = "$STR_AGM_MoveToCargo";
				condition = "[vehicle player, -1] call AGM_GetIn_fnc_canGetInCargo";
				statement = "[vehicle player, -1] call AGM_GetIn_fnc_getInCargo";
				showDisabled = 0;
				priority = -1.93;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
				enableInside = 1;
			};
			class AGM_MoveToCoDriver {
				displayName = "$STR_AGM_MoveToCoDriver";
				condition = "[vehicle player] call AGM_GetIn_fnc_canGetInCoDriver";
				statement = "[vehicle player] call AGM_GetIn_fnc_getInCoDriver";
				showDisabled = 0;
				priority = -1.94;
				icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
				enableInside = 1;
			};
		};
	};
};
