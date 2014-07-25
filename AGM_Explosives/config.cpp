class CfgPatches {
	class AGM_Explosives {
		units[] = {};
		weapons[] = {"AGM_Clacker", "AGM_DefusalKit"};
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
			class CanDefuse;
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
			class StartDefuse;
			class StartTimer;
			
			class TriggerType;
		};
	};
};

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
  name = #ITEM; \
  count = COUNT; \
};

class CfgVehicles {
	class Man;

	class CAManBase: Man {
		class AGM_SelfActions {
			class AGM_Explosives {
				displayName = $STR_AGM_Explosives_Menu;
				condition = "true";
				statement = "'AGM_Explosives' call AGM_Interaction_fnc_openMenuSelf;";
				showDisabled = 1;
				priority = 4;
				
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
					condition = "[player] call AGM_Explosives_fnc_CanDefuse;";
					statement = "[AGM_Interaction_Target] call AGM_Explosives_fnc_StartDefuse;";
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

	class NATO_Box_Base;
	class EAST_Box_Base;
	class IND_Box_Base;
	class Box_NATO_Support_F;

	class Box_NATO_AmmoOrd_F: NATO_Box_Base {
		class TransportItems {
			MACRO_ADDITEM(AGM_Clacker,12)
			MACRO_ADDITEM(AGM_DefusalKit,12)
		};
	};

	class Box_East_AmmoOrd_F: EAST_Box_Base {
		class TransportItems {
			MACRO_ADDITEM(AGM_Clacker,12)
			MACRO_ADDITEM(AGM_DefusalKit,12)
		};
	};

	class Box_IND_AmmoOrd_F: IND_Box_Base {
		class TransportItems {
			MACRO_ADDITEM(AGM_Clacker,12)
			MACRO_ADDITEM(AGM_DefusalKit,12)
		};
	};

	class AGM_Box_Misc: Box_NATO_Support_F {
		class TransportItems {
			MACRO_ADDITEM(AGM_Clacker,24)
			MACRO_ADDITEM(AGM_DefusalKit,24)
		};
	};
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"

#include "ExplosivesUI.hpp"