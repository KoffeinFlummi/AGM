class CfgPatches {
	class AGM_Explosives {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {A3_Weapons_F_Explosives, AGM_Interaction};
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
			class DefuseExplosive;
			class DetonateExplosive;
			class DialPhone;
			class HandleScrollWheel;
			
			class hasExplosives;
			class hasPlacedExplosives;
			
			class initialise{postInit=1;};
			//class JammerInit;
			
			class openDetonateUI;
			class openPlaceUI;
			class openTimerSetUI;
			class openTriggerSelectionUI;
			
			class Place_Approve;
			class Place_AttachTo;
			class Place_Cancel;
			class PlaceExplosive;
			
			class RemoveCodeFromSpeedDial;
			class SelectTrigger;
			class SetupExplosive;
			class SetSpeedDial;
			class StartTimer;
			
			class TriggerType;
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
				priority = 0.25;
				
				//Sub-menu items
				class AGM_Detonate {
					displayName = $STR_AGM_Explosives_Detonate;
					condition = "[player] call AGM_Explosives_fnc_hasPlacedExplosives and {('AGM_Clacker' in (items player))}";
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
				class AGM_Defuse {
					displayName = $STR_AGM_Explosives_Defuse;
					condition = "(vehicle player == player) and ('AGM_DefusalKit' in items player) and {AGM_Interaction_Target = nearestObject [player, 'TimeBombCore'];!isNull(AGM_Interaction_Target) and player distance AGM_Interaction_Target < 4}";
					statement = "[getNumber(ConfigFile >> 'CfgAmmo' >> typeOf (AGM_Interaction_Target) >> 'AGM_DefuseTime'), [player,AGM_Interaction_Target], 'AGM_Explosives_fnc_DefuseExplosive', localize 'STR_AGM_Explosives_DefusingExplosive'] call AGM_Core_fnc_progressBar;";
					showDisabled = 0;
					priority = 0.8;
				};
/*				class AGM_Cellphone {
					displayName = $STR_AGM_Explosives_cellphone_displayName;
					condition = "('AGM_Cellphone' in (items player))";
					statement = "closeDialog 0;createDialog 'RscAGM_PhoneInterface';";
					showDisabled = 0;
					priority = 0.8;
				};
				*/
			};
			/*
			class AGM_ExplosiveJammerOn {
				displayName = $STR_AGM_Explosives_Jammer_TurnOn;
				condition = "isClass (configFile >> 'CfgVehicles' >> (backpack player)) and {getNumber(configFile >> 'CfgVehicles' >> (backpack player) >> 'AGM_JammerRange') > 0 and !((unitBackpack player) getVariable ['AGM_JammerEnabled', false])}";
				statement = "(unitBackpack player) setVariable ['AGM_JammerEnabled', true, true];";
				showDisabled = 0;
				priority = 0.1;
			};
			class AGM_ExplosiveJammerOff {
				displayName = $STR_AGM_Explosives_Jammer_TurnOff;
				condition = "isClass (configFile >> 'CfgVehicles' >> (backpack player)) and {getNumber(configFile >> 'CfgVehicles' >> (backpack player) >> 'AGM_JammerRange') > 0 and (unitBackpack player) getVariable ['AGM_JammerEnabled', false]}";
				statement = "(unitBackpack player) setVariable ['AGM_JammerEnabled', false, true];";
				showDisabled = 0;
				priority = 0.1;
			};
			*/
		};
	};
	
	#include "CfgVehicles.hpp"

	class Box_NATO_Support_F;
	class AGM_Box_Misc: Box_NATO_Support_F {
		class TransportItems {
			class _xx_AGM_Clacker {
				count = 24;
				name = "AGM_Clacker";
			};
			class _xx_AGM_DefusalKit {
				count = 24;
				name = "AGM_DefusalKit";
			};
		};
	};
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"

#include "ExplosivesUI.hpp"