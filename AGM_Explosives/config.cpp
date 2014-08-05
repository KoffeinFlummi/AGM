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
			class initialiseUnit;
			class isSpecialist;
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

#define MACRO_DETONATEACTION 		class AGM_SelfActions { \
			class AGM_Explosives { \
				displayName = $STR_AGM_Explosives_Menu;\
				condition = "true";\
				statement = "'AGM_Explosives' call AGM_Interaction_fnc_openMenuSelf;";\
				showDisabled = 1;\
				priority = 4;\
				class AGM_Detonate {\
					displayName = $STR_AGM_Explosives_Detonate;\
					condition = "[player] call AGM_Explosives_fnc_hasPlacedExplosives and {('AGM_Clacker' in (items player))}";\
					statement = "[player] call AGM_Explosives_fnc_openDetonateUI;";\
					showDisabled = 1;\
					priority = 2;\
				};\
			};\
		};

class CfgVehicles {
	class All;
	class AllVehicles: All {
		MACRO_DETONATEACTION
	};
	class LandVehicle;
	class Car: LandVehicle {
		MACRO_DETONATEACTION
	};
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
					condition = "[player] call AGM_Explosives_fnc_CanDefuse";
					statement = "[player, AGM_Interaction_Target] call AGM_Explosives_fnc_StartDefuse;";
					showDisabled = 0;
					priority = 0.8;
				};
				class AGM_PlaceExplosive {
					displayName = $STR_AGM_Explosives_PlaceAction;
					condition = "AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup)}";
					statement = "[] spawn AGM_Explosives_fnc_Place_Approve;";
					showDisabled = 0;
					priority = 0.4;
				};
				// Basic attach, needs to be improved.
				class AGM_AttachExplosive {
					displayName = $STR_AGM_Explosives_AttachTo;
					condition = "AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup) AND (cursorTarget isKindOf 'Car') AND (cursorTarget distance AGM_Explosives_Setup) < 2.5}";
					statement = "[player] call AGM_Explosives_fnc_openPlaceUI;";
					showDisabled = 0;
					priority = 0.3;
				};
				class AGM_CancelPlace {
					displayName = $STR_AGM_Explosives_CancelAction;
					condition = "AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup)}";
					statement = "call AGM_Explosives_fnc_Place_Cancel;";
					showDisabled = 0;
					priority = 0.2;
				};
			};
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
	
	#include "Module.hpp"
	
// Add AGM_Clacker and AGM_DefusalKit to every explosive unit.
class B_Soldier_base_F; class B_soldier_exp_F:B_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_engineer_F:B_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_Soldier_diver_base_F; class B_diver_exp_F:B_Soldier_diver_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_Soldier_recon_base; class B_recon_exp_F:B_Soldier_recon_base {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_CTRG_soldier_engineer_exp_F:B_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class I_G_Soldier_base_F; class I_G_engineer_F:I_G_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class I_G_Soldier_exp_F:I_G_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_G_engineer_F:I_G_engineer_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_G_engineer_F:I_G_engineer_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_G_Soldier_exp_F:I_G_Soldier_exp_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_G_Soldier_exp_F:I_G_Soldier_exp_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class I_Soldier_base_F; class I_Soldier_exp_F:I_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class I_engineer_F:I_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class I_Soldier_diver_base_F; class I_diver_exp_F:I_Soldier_diver_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_Soldier_base_F; class O_soldier_exp_F:O_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_engineer_F:O_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_Soldier_diver_base_F; class O_diver_exp_F:O_Soldier_diver_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_Soldier_recon_base; class O_recon_exp_F:O_Soldier_recon_base {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_Soldier_Urban_base; class O_soldierU_exp_F:O_Soldier_Urban_base {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_engineer_U_F:O_Soldier_Urban_base {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_Protagonist_VR_F:B_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_Protagonist_VR_F:O_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class I_Protagonist_VR_F:I_Soldier_base_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_Soldier_F; class b_soldier_universal_f:B_Soldier_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class B_G_Soldier_F; class b_g_soldier_universal_f:B_G_Soldier_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_Soldier_F; class o_soldier_universal_f:O_Soldier_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class O_G_Soldier_F; class o_g_soldier_universal_f:O_G_Soldier_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class I_soldier_F; class i_soldier_universal_f:I_soldier_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
class I_G_Soldier_F; class i_g_soldier_universal_f:I_G_Soldier_F {Items[] = {"FirstAidKit","AGM_Clacker", "AGM_DefusalKit"};};
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"

#include "ExplosivesUI.hpp"

class CfgActions {
	class None;
	class Deactivate:None {
		show = 0;
	};
	class DeactivateMine:None {
		show = 0;
	};
};

class AGM_Parameters {
  // Boolean Parameters (0/1)
  AGM_Explosives_RequireSpecialist = 0;
  AGM_Explosives_PunishNonSpecialists = 1;
};