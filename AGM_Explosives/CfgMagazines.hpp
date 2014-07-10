class CfgMagazines {
	class CA_Magazine;
	class ATMine_Range_Mag:CA_Magazine{
		AGM_Placeable = 1;
		useAction = 0;
		AGM_OnCreate = "";
		AGM_SetupObject = "Land_MultiMeter_F"; // CfgVehicle class for setup object.
		AGM_FuseTime = 0; // time of the fuse.
		AGM_MaxDistance = 100; // max distance before clacker/cellphone won't detonate explosive.
		AGM_Explosive_Type = 0;
	};
	/*class APERSBoundingMine_Range_Mag:ATMine_Range_Mag{
	};
	class APERSMine_Range_Mag:ATMine_Range_Mag{
	};
	class APERSTripMine_Wire_Mag:ATMine_Range_Mag{
	};*/
	
	class ClaymoreDirectionalMine_Remote_Mag:CA_Magazine{
		AGM_Placeable = 1;
		useAction = 0;
		AGM_OnCreate = "";
		AGM_SetupObject = "Land_MultiMeter_F"; // CfgVehicle class for setup object.
		AGM_FuseTime = 0; // time of the fuse.
		AGM_MaxDistance = 100; // max distance before clacker/cellphone won't detonate explosive.
		AGM_Explosive_Type = 0;
	};
	
	class SatchelCharge_Remote_Mag:CA_Magazine{
		AGM_Placeable = 1;
		useAction = 0;
		AGM_OnCreate = "";
		AGM_SetupObject = "Land_MultiMeter_F"; // CfgVehicle class for setup object.
		AGM_FuseTime = 0.5; // time of the fuse.
		AGM_MaxDistance = 100; // max distance before clacker/cellphone won't detonate explosive.
		AGM_Explosive_Type = 2; // 1 = cellphone, 2 = clacker
	};
	/*class DemoCharge_Remote_Mag:SatchelCharge_Remote_Mag{
	};
	
	class SLAMDirectionalMine_Wire_Mag: ATMine_Range_Mag{
	};*/
};