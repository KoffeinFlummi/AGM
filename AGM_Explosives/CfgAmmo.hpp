class CfgAmmo {
	/*class Default;
	class TimeBombCore:Default;
	class BoundingMineCore:TimeBombCore;
	class BoundingMineBase:BoundingMineCore;
	class APERSBoundingMine_Range_Ammo:BoundingMineBase;
	
	class MineCore: TimeBombCore;
	class MineBase:MineCore;
	class APERSMine_Range_Ammo:MineBase;
	class ATMine_Range_Ammo:MineBase;
	
	class UnderwaterMine_Range_Ammo:MineBase;
	class UnderwaterMineAB_Range_Ammo:UnderwaterMine_Range_Ammo;
	class UnderwaterMinePDM_Range_Ammo:UnderwaterMine_Range_Ammo;
	
	class DirectionalBombCore:TimeBombCore;
	class DirectionalBombBase:DirectionalBombCore;
	class APERSTripMine_Wire_Ammo:DirectionalBombBase;
	
	class ClaymoreDirectionalMine_Remote_Ammo:DirectionalBombBase;
	class ClaymoreDirectionalMine_Remote_Ammo_Scripted:ClaymoreDirectionalMine_Remote_Ammo;
	
	class SLAMDirectionalMine_Wire_Ammo:DirectionalBombBase;
	
	class PipeBombCore: TimeBombCore;
	class PipeBombBase:PipeBombCore;*/
	class PipeBombBase;
	class DemoCharge_Remote_Ammo:PipeBombBase{
		AGM_Explosive = "DemoCharge_Remote_Ammo_Scripted";
	};
	//class DemoCharge_Remote_Ammo_Scripted:DemoCharge_Remote_Ammo;
	class SatchelCharge_Remote_Ammo:PipeBombBase{
		AGM_Explosive = "SatchelCharge_Remote_Ammo_Scripted";
	};
	/*class SatchelCharge_Remote_Ammo_Scripted:SatchelCharge_Remote_Ammo;
	
	class IEDLandBig_Remote_Ammo:PipeBombBase{
		triggerWhenDestroyed = 1;
	};
	class IEDLandSmall_Remote_Ammo:PipeBombBase{
		triggerWhenDestroyed = 1;
	};
	class IEDUrbanBig_Remote_Ammo:PipeBombBase{
		triggerWhenDestroyed = 1;
	};
	class IEDUrbanSmall_Remote_Ammo:PipeBombBase{
		triggerWhenDestroyed = 1;
	};*/
};