class CfgPatches {
	class AGM_Explosives {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core, AGM_Interaction};
		version = "0.92";
		versionStr = "0.92";
		versionAr[] = {0,92,0};
		author[] = {"Garth 'L-H' de Wet"};
		authorUrl = "https://github.com/corruptedheart/";
	};
};

class CfgFunctions
{
	class AGM_Explosives {
		class Explosives {
			file="AGM_Explosives\functions";
			
			class AddCodeToSpeedDial;
			class DetonateExplosive;
			class DialPhone;
			class HandleScrollWheel;
			
			class hasExplosives;
			class hasPlacedExplosives;
			
			class initialise{postInit=1;};
			class JammerInit;
			
			class openDetonateUI;
			class openPlaceUI;
			
			class Place_Approve;
			class Place_AttachTo;
			class Place_Cancel;
			class PlaceExplosive;
			
			class RemoveCodeFromSpeedDial;
			class SetupExplosive;
			class SetSpeedDial;
		};
	};
};

class CfgVehicles {
	class Man;

	class CAManBase: Man {
		class AGM_SelfActions {
			class AGM_Explosives {
				displayName = $STR_AGM_Explosives_Menu;
				condition = "true";
				statement = "AGM_Interaction_Target=player;'AGM_Explosives' call AGM_Interaction_fnc_openMenuSelf;";
				showDisabled = 1;
				priority = 1;
				
				//Sub-menu items
				class AGM_Detonate {
					displayName = $STR_AGM_Explosives_Detonate;
					condition = "[player] call AGM_Explosives_fnc_hasPlacedExplosives";
					statement = "[player] call AGM_Explosives_fnc_openDetonateUI;";
					showDisabled = 1;
					priority = 2;
				};
				class AGM_Place {
					displayName = $STR_AGM_Explosives_Place;
					condition = "(vehicle player == player) and {[player] call AGM_Explosives_fnc_hasExplosives}";
					statement = "[player] call AGM_Explosives_fnc_openPlaceUI;";
					showDisabled = 1;
					priority = 1;
				};
			};
		};
	};
};

#include "ExplosivesUI.hpp"