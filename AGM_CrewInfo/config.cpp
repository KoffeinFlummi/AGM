/* 
	Description:
		Once you use scrollwheel and you are in vehicle, this addon shows
		vehicle crew names and roles, it also shows picture and name of the vehicle


	Credits:
		Rewritten for AGM by aeroson with given permission from [KH]Jman

		Created by [KH]Jman
		Creation date: 31/03/2011
		Email: jman@kellys-heroes.eu
		Web: http://www.kellys-heroes.eu

		Original script by =[A*C]= code34 
		Modified by [KH]Jman
		Part is modified code from WINSE - Valhalla mission 
		modified for MSO: 16/08/2012
		
*/



class CfgPatches {
	class AGM_CrewInfo {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core};
		version = "0.94.1";
		versionStr = "0.94.1";
		versionAr[] = {0,94,1};
		author[] = {"aeroson"};
		authorUrl = "https://github.com/aeroson/";
	};
};



class CfgFunctions {
	class AGM_CrewInfo {
		class AGM_CrewInfo {
			file = "\AGM_CrewInfo\functions";
			class canShow;
			class doShow;
			class setText;
			class onMouseZChanged;
			class module;
			//class postInit { postInit = 1; };
		};
	};
};



class Extended_PostInit_EventHandlers {
	class AGM_CrewInfo {
		clientInit = "call compile preprocessFileLineNumbers '\AGM_CrewInfo\clientInit.sqf'";
	};
};



class AGM_Core_Options {
	class CrewInfo_ShowVehicleCrewInfo {
		displayName = "$STR_AGM_CrewInfo_ShowVehicleCrewInfo";
		default = 1;
	};
};



class CfgVehicles {
	class Module_F;
	class AGM_ModuleCrewInfo: Module_F {
		author = "AGM Team";
		category = "AGM";
		displayName = "Crew Info";
		function = "AGM_CrewInfo_fnc_module";
		scope = 2;
		isGlobal = 1;
		//icon = "\AGM_NameTags\UI\IconInteraction_ca.paa";
		class Arguments {
			class Visibility {
				displayName = "Visibility of crew info";
				description = "Forces visibility of vehicle crew info, or by default allows players to choose it on their own. Default: Do Not Force";
				typeName = "INT";
				class values {
					class DoNotForce {
						default = 1;
						name = "Do Not Force";
						value = 0;
					};
					class ForceShow {						
						name = "Force Show";
						value = 1;
					};
					class ForceHide {
						name = "Force Hide";
						value = -1;
					};
				};
			};
		};
	};
};




#include "RscTitles.hpp"