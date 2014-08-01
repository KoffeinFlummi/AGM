class CfgMagazines {
/*
	AGM_Trigger:
		0 - Default (mine/tripwire)
		2 - Clacker
		4 - Timer
		6 - Clacker + Timer
		8 - Cellphone
		10 - Clacker + Cellphone
		12 - Cellphone + Timer
		14 - Cellphone + Timer + Clacker
		
		_binary = [AGM_Trigger, 4] call AGM_Core_fnc_binarizeNumber;
		for "_index" from 0 to count _binary step 1 do {
			
		};
*/
	class CA_Magazine;
	class ATMine_Range_Mag:CA_Magazine{
		AGM_Placeable = 1;
		useAction = 0;
		AGM_OnCreate = "";
		AGM_SetupObject = "AGM_Explosives_Place_ATMine"; // CfgVehicle class for setup object.
		AGM_FuseTime = 0; // time of the fuse.
		AGM_MaxDistance = 100; // max distance before clacker/cellphone won't detonate explosive.
		AGM_DelayTime = 2.5;
		AGM_Trigger = 0;
	};
	class APERSBoundingMine_Range_Mag:ATMine_Range_Mag{
		AGM_SetupObject = "AGM_Explosives_Place_APERSBoundingMine";
	};
	class APERSMine_Range_Mag:ATMine_Range_Mag{
		AGM_SetupObject = "AGM_Explosives_Place_APERSMine";
	};
	class APERSTripMine_Wire_Mag:ATMine_Range_Mag{
		AGM_SetupObject = "AGM_Explosives_Place_APERSTripwireMine";
		AGM_OnCreate = "";
	};
	
	class ClaymoreDirectionalMine_Remote_Mag:CA_Magazine{
		AGM_Placeable = 1;
		useAction = 0;
		AGM_OnCreate = "";
		AGM_SetupObject = "AGM_Explosives_Place_Claymore"; // CfgVehicle class for setup object.
		AGM_FuseTime = 0.5; // time of the fuse.
		AGM_MaxDistance = 100; // max distance before clacker/cellphone won't detonate explosive.
		AGM_DelayTime = 1.5;
		AGM_Trigger = 2;
	};
	
	class SatchelCharge_Remote_Mag:CA_Magazine{
		AGM_Placeable = 1;
		useAction = 0;
		AGM_OnCreate = "";
		AGM_SetupObject = "AGM_Explosives_Place_SatchelCharge"; // CfgVehicle class for setup object.
		AGM_FuseTime = 0.5; // time of the fuse.
		AGM_MaxDistance = 100; // max distance before clacker/cellphone won't detonate explosive.
		AGM_Explosive_Type = 2; // 1 = cellphone, 2 = clacker
		AGM_DelayTime = 1;
		AGM_Trigger = 6;
	};
	class DemoCharge_Remote_Mag:SatchelCharge_Remote_Mag{
		AGM_SetupObject = "AGM_Explosives_Place_DemoCharge"; // CfgVehicle class for setup object.
		model = "\A3\Weapons_F\explosives\c4_charge_small_d";
	};
	
	class SLAMDirectionalMine_Wire_Mag: ATMine_Range_Mag{
		AGM_SetupObject = "AGM_Explosives_Place_SLAM";
	};
};