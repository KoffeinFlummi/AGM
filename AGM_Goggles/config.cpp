#define COLOUR 8.0
class CfgPatches {
  class AGM_Goggles {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {"A3_Weapons_F", "CBA_Main", "AGM_Core"};
    version = "0.91";
    versionStr = "0.91";
    versionAr[] = {0,91,0};
    author[] = {"Garth 'L-H' de Wet"};
    authorUrl = "https://github.com/CorruptedHeart";
  };
};

#include "CfgFunctions.hpp"

class CfgGlasses {
	class None {
		AGM_Goggles_Color[] = {0,0,0};
		AGM_TintAmount=0;
		AGM_Goggles_Image = "";
		AGM_Goggles_DirtImage = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
		AGM_Goggles_CrackedImage = "AGM_Goggles\textures\HUD\Cracked.paa";
		AGM_Goggles_CrackRating = 1;
		AGM_Goggles_EyeProtection = 0;
	};
	
	class G_Combat:None {
		AGM_Goggles_Image="AGM_Goggles\textures\HUD\CombatGoggles.paa";
		AGM_Goggles_CrackedImage = "AGM_Goggles\textures\HUD\CombatGogglesCracked.paa";
		AGM_Goggles_CrackRating = 2;
		AGM_Goggles_EyeProtection = 1;
	};
	
	class G_Diving:None {
		AGM_Goggles_Image="AGM_Goggles\textures\HUD\DivingGoggles.paa";
		AGM_Goggles_CrackedImage = "AGM_Goggles\textures\HUD\DivingGogglesCracked.paa";
		AGM_Goggles_CrackRating = 2;
		AGM_Goggles_EyeProtection = 1;
	};
	
	class G_Lowprofile:None {
		AGM_TintAmount=COLOUR*2;
		AGM_Goggles_CrackRating = 2;
		AGM_Goggles_EyeProtection = 1;
	};
	
	class G_Shades_Black:None {
		AGM_TintAmount=COLOUR*2;
	};
	
	class G_Shades_Blue:None{
		AGM_Goggles_Color[] = {0,0,1};
		AGM_TintAmount=COLOUR;
	};
	
	class G_Shades_Green:None{
		AGM_Goggles_Color[] = {0,1,0};
		AGM_TintAmount=COLOUR;
	};
	
	class G_Shades_Red:None{
		AGM_Goggles_Color[] = {1,0,0};
		AGM_TintAmount=COLOUR;
	};
	
	class G_Spectacles:None{
		AGM_TintAmount=COLOUR;
	};
	
	class G_Spectacles_Tinted:None{
		AGM_TintAmount=COLOUR*2;
	};
	
	class G_Sport_Blackred:None{
		AGM_Goggles_Color[] = {1,0,0};
		AGM_TintAmount=COLOUR;
	};
	
	class G_Sport_BlackWhite:None{
		AGM_Goggles_Color[] = {0,0,1};
		AGM_TintAmount=COLOUR;
	};
	
	class G_Sport_Blackyellow:None{
		AGM_TintAmount=COLOUR*2;
	};
	
	class G_Sport_Checkered:None{
		AGM_TintAmount=COLOUR*2;
	};
	
	class G_Sport_Greenblack:None{
		AGM_TintAmount=COLOUR*2;
	};
	
	class G_Sport_Red:None{
		AGM_TintAmount=COLOUR*2;
		AGM_Goggles_Color[] = {0,0,0};
	};
	
	class G_Squares:None{
		AGM_TintAmount=COLOUR;
	};
	
	class G_Squares_Tinted:None{
		AGM_TintAmount=COLOUR;
	};
	
	class G_Tactical_Black:None{
		AGM_TintAmount=COLOUR;
		AGM_Goggles_Color[] = {0,0,-1.5};
	};
	
	class G_Tactical_Clear:None{
		AGM_TintAmount=COLOUR;
		AGM_Goggles_Color[] = {0,0,-1};
	};
	
	class G_Aviator:None{
		AGM_Goggles_Color[] = {0,0,-1};
		AGM_TintAmount=COLOUR;
	};
	
	class G_Lady_Blue:None{
		AGM_Goggles_Color[] = {0,0,1};
		AGM_TintAmount=COLOUR;
	};
	
	class G_Lady_Red:None{
		AGM_Goggles_Color[] = {1,0,0};
		AGM_TintAmount=COLOUR;
	};
	
	class G_Lady_Dark:None{
		AGM_TintAmount=COLOUR*2;
	};
	
	class G_Lady_Mirror:None{
		AGM_TintAmount=COLOUR;
	};
	
	class AV_ESS_blk:None{
		AGM_Goggles_Image="AGM_Goggles\textures\HUD\CombatGoggles.paa";
		AGM_Goggles_CrackedImage = "AGM_Goggles\textures\HUD\CombatGogglesCracked.paa";
		AGM_Goggles_CrackRating = 2;
		AGM_Goggles_EyeProtection = 1;
	};
};

#include "RscTitles.hpp"

class CfgMovesBasic
{
	class ManActions
	{
		GestureWipeFace[] = {"GestureWipeFace", "gesture"};
	};
};

class CfgGesturesMale
{
	class States
	{
		class GestureFreezeStand;
		class GestureWipeFace: GestureFreezeStand
		{
			file = "\AGM_Goggles\anim\WipeGlasses.rtm";
			canPullTrigger = 0;
		};
	};
};

class CfgWeapons{
	class H_HelmetB;
	
	class H_CrewHelmetHeli_B:H_HelmetB {
		AGM_Goggles_EyeProtection = 1;
	};
	class H_PilotHelmetHeli_B:H_HelmetB {
		AGM_Goggles_EyeProtection = 1;
	};
	class H_PilotHelmetFighter_B:H_HelmetB {
		AGM_Goggles_EyeProtection = 1;
	};
};

class RifleAssaultCloud {
	AGM_Goggles_BulletCount = 4;
};
class MachineGunCloud {
	AGM_Goggles_BulletCount = 3;
};
class SniperCloud {
	AGM_Goggles_BulletCount = 1;
};

class AGM_Core_Default_Keys {
	class wipeGlasses {
		displayName = $STR_AGM_Goggles_WipeGlasses;
		condition = "!(player getVariable['AGM_Unconscious', false])";
		statement = "call AGM_Goggles_fnc_ClearGlasses;";
		key = 20; // T
		shift = 0;
		ctrl = 1;
		alt = 0;
	};
};

class AGM_Core_Options {
	class showInThirdPerson {
		displayName = $STR_AGM_Goggles_ShowInThirdPerson;
		default = 0;
	};
};