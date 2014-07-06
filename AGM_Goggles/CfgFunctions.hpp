class CfgFunctions
{
	class AGM_Goggles {
		class AGM_Goggles
		{
			file="AGM_Goggles\functions";
			class Glasses_Init
			{
				file="AGM_Goggles\functions\fn_Init.sqf";	
				description = "Initialises AGM Goggles.";
				postInit = 1;
			};
			class RainCheck;
			class ApplyGlassesEffect;
			class RemoveGlassesEffect;
			class ApplyDirtEffect;
			class RemoveDirtEffect;
			class isGogglesVisible;
			class isDivingGoggles;
			class ClearGlasses;
			class CheckGoggles;
			class GetExplosionIndex
			{
				file = "AGM_Goggles\functions\fn_ExplosionAmount.sqf";
			};
			class ApplyRainEffect;
			class RemoveRainEffect;
			class DustHandler;
			class ExternalCamera;
			class isInRotorWash;
			class OnEachFrame;
			class ApplyDust;
			class RemoveDustEffect;
		};
	};
};