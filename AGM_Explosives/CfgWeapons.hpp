class CfgWeapons {
	class ItemCore;
	class InventoryItem_Base_f;

	class AGM_ExplosiveItem: InventoryItem_Base_f {
		allowedSlots[] = {801,701,901};
		type = 620;
	};
	/*
	class AGM_Cellphone:ItemCore {
		scope = 2;
		displayName = $STR_AGM_Explosives_cellphone_displayName;
		descriptionShort = $STR_AGM_Explosives_cellphone_description;
		picture = "\AGM_Explosives\Data\UI\Cellphone_UI.paa";
		model = "\A3\Structures_F\Items\Electronics\MobilePhone_old_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"\A3\Structures_F\Items\Electronics\Data\electronics_screens.rvmat"};
		hiddenSelectionsTextures[] = {"\A3\Structures_F\Items\Electronics\Data\Electronics_screens_mobilePhone_old_CO.paa"};
		
		class ItemInfo: AGM_ExplosiveItem {
			mass = 5;
			uniformModel = "\A3\Structures_F\Items\Electronics\MobilePhone_old_F.p3d";
		};
	};*/

	class AGM_Clacker:ItemCore {
		scope = 2;
		displayName = $STR_AGM_Explosives_clacker_displayName;
		descriptionShort = $STR_AGM_Explosives_clacker_description;
		picture = "\AGM_Explosives\Data\UI\Clacker.paa";
		model = "\A3\Structures_F\Items\Tools\MultiMeter_F.p3d";
		
		class ItemInfo: AGM_ExplosiveItem {
			mass = 3;
			uniformModel = "\A3\Structures_F\Items\Tools\MultiMeter_F.p3d";
		};
	};
	class AGM_DefusalKit: ItemCore {
		scope = 2;
		displayName = $STR_AGM_Explosives_DefusalKit_displayName;
		descriptionShort = $STR_AGM_Explosives_DefusalKit_description;
		picture = "\AGM_Explosives\Data\UI\pliers.paa";
		model = "\A3\Structures_F\Items\Tools\Pliers_F.p3d";
		
		class ItemInfo: AGM_ExplosiveItem {
			mass = 5;
			uniformModel = "\A3\Structures_F\Items\Tools\Pliers_F.p3d";
		};
	};
};