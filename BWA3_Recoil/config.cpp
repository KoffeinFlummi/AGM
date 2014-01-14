// SEE LICENSE.TXT FOR LICENSING INFORMATION

class CfgPatches {
	class BWA3_Recoil {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {A3_Weapons_F, A3_Anims_F, BWA3_Weapons};
		version = 1.0;
		author[] = {"KoffeinFLummi"};
		authorUrl = "http://www.bwmod.de";
	};
};

class CfgMods {
	class BWA3_Recoil {
		dir = "BWA3_Recoil";
		name = "BWA3: Recoil Module";
		picture = "";
		hidePicture = "true";
		hideName = "true";
		actionName = "Website";
		action = "http://www.bwmod.de";
	};
};

// EVERYTHING BELOW BELONGS TO TAOSENSAI

class Extended_PostInit_EventHandlers {
	class BWA3_Recoil {
		clientInit = "call compile preProcessFileLineNumbers '\BWA3_Recoil\init.sqf'";
	};
};

class Extended_FiredBIS_EventHandlers {
	class CAManBase {
		class BWA3_Recoil {
			clientFiredBISPlayer = "_this call BWA3_Recoil_fnc_firedEH";
		};
	};
};

// About recoils:
// Each recoil has a max of four frames.
//    Frame 1: Zero.
//    Frame 2: Muzzle climb, pushback
//    Frame 3: Climb recovery (downward)
//    Frame 4: Zero.
//
// The climb recovery frame can be omitted if you'd like the weapon to not recover at all. (For example, standing sniper rifle shots.)
//
// About recoil frames: Recoil is an array of triplets. Each triplet specifies a frame for the camera.
//
// Example: 0.020,           0.0115,              0.01572
//            ^                 ^                    ^
//    time since fired   rear movement of gun   camera climb

// Global muzzle climb increase over base. (For easy tuning.)
#define BWA3_MC 0.0089

// Global recovery sequence duration increase (For easy tuning.)
#define BWA3_RSD 0.06031

// Global recovery downward muzzle movement.
#define BWA3_RCT -0.0028


 // 0.114 +BWA3_RSD
class CfgRecoils {
	bwa3_recoil_single_mx[] =                                 {0, 0.014, 0.024+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.081+BWA3_RSD, 0, -0.0069+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_mx[] =                                 {0, 0.014, 0.024+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.081+BWA3_RSD, 0, -0.0072+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_mx[] =                 {0, 0.014, 0.011+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.081+BWA3_RSD, 0, -0.0036+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_prone_mx[] =                         {0, 0.014, 0.011+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.081+BWA3_RSD, 0, -0.0038+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};

	bwa3_recoil_single_katiba[] =                         {0, 0.014, 0.022+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.078+BWA3_RSD, 0, -0.0068+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_katiba[] =                         {0, 0.014, 0.022+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.078+BWA3_RSD, 0, -0.0071+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_katiba[] =         {0, 0.014, 0.009+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.078+BWA3_RSD, 0, -0.0035+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_prone_katiba[] =                 {0, 0.014, 0.009+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.078+BWA3_RSD, 0, -0.0037+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};

	bwa3_recoil_single_mk20[] =                         {0, 0.013, 0.012+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.078+BWA3_RSD, 0, -0.0033+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_mk20[] =                                 {0, 0.013, 0.012+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.078+BWA3_RSD, 0, -0.0034+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_mk20[] =                 {0, 0.013, 0.002+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.078+BWA3_RSD, 0, -0.0007+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_prone_mk20[] =                 {0, 0.013, 0.002+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.078+BWA3_RSD, 0, -0.0008+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};

	bwa3_recoil_single_vermin[] =                         {0, 0.008, 0.011+BWA3_MC,                0.047+BWA3_RSD, 0, 0,                0.071+BWA3_RSD, 0, -0.0031+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_vermin[] =                         {0, 0.008, 0.011+BWA3_MC,                0.047+BWA3_RSD, 0, 0,                0.071+BWA3_RSD, 0, -0.0033+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_vermin[] =         {0, 0.008, 0.002+BWA3_MC,                0.047+BWA3_RSD, 0, 0,                0.071+BWA3_RSD, 0, -0.0007+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_prone_vermin[] =                 {0, 0.008, 0.002+BWA3_MC,                0.047+BWA3_RSD, 0, 0,                0.071+BWA3_RSD, 0, -0.0007+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};

	bwa3_recoil_single_scorpion[] =                 {0, 0.008, 0.012+BWA3_MC,                0.046+BWA3_RSD, 0, 0,                0.072+BWA3_RSD, 0, -0.0030+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_scorpion[] =                         {0, 0.008, 0.013+BWA3_MC,                0.046+BWA3_RSD, 0, 0,                0.072+BWA3_RSD, 0, -0.0033+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_scorpion[] =         {0, 0.008, 0.002+BWA3_MC,                0.047+BWA3_RSD, 0, 0,                0.071+BWA3_RSD, 0, -0.0007+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_prone_scorpion[] =         {0, 0.008, 0.002+BWA3_MC,                0.047+BWA3_RSD, 0, 0,                0.071+BWA3_RSD, 0, -0.0007+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};

	bwa3_recoil_single_mk200[] =                         {0, 0.014, 0.021+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.079+BWA3_RSD, 0, -0.0063+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_mk200[] =                         {0, 0.014, 0.021+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.079+BWA3_RSD, 0, -0.0143+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_mk200[] =         {0, 0.014, 0.002+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.077+BWA3_RSD, 0, -0.0037+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_prone_mk200[] =                 {0, 0.014, 0.002+BWA3_MC,                0.048+BWA3_RSD, 0, 0,                0.077+BWA3_RSD, 0, -0.0041+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};

	bwa3_recoil_single_zafir[] =                         {0, 0.015, 0.026+BWA3_MC,                0.045+BWA3_RSD, 0, 0,                0.088+BWA3_RSD, 0, -0.0072+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_zafir[] =                         {0, 0.015, 0.026+BWA3_MC,                0.045+BWA3_RSD, 0, 0,                0.088+BWA3_RSD, 0, -0.0147+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_zafir[] =         {0, 0.015, 0.004+BWA3_MC,                0.045+BWA3_RSD, 0, 0,                0.080+BWA3_RSD, 0, -0.0017+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_prone_zafir[] =                 {0, 0.015, 0.004+BWA3_MC,                0.045+BWA3_RSD, 0, 0,                0.080+BWA3_RSD, 0, -0.0070+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};

	bwa3_recoil_single_ebr[] =                         {0, 0.014, 0.028+BWA3_MC,                0.045+BWA3_RSD, 0, 0,                0.084+BWA3_RSD, 0, -0.0074+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_ebr[] =                                 {0, 0.014, 0.028+BWA3_MC,                0.045+BWA3_RSD, 0, 0,                0.084+BWA3_RSD, 0, -0.0077+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_ebr[] =                 {0, 0.014, 0.013+BWA3_MC,                0.045+BWA3_RSD, 0, 0,                0.084+BWA3_RSD, 0, -0.0038+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_auto_prone_ebr[] =                 {0, 0.014, 0.013+BWA3_MC,                0.045+BWA3_RSD, 0, 0,                0.084+BWA3_RSD, 0, -0.0041+BWA3_RCT,                 0.135+BWA3_RSD, 0, 0};

	bwa3_recoil_single_lrr[] =                         {0, 0.030, 0.114+BWA3_MC,                0.043+BWA3_RSD, 0, 0,                0.250+BWA3_RSD, 0, -0.0130+BWA3_RCT,                0.430+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_lrr[] =                 {0, 0.030, 0.074+BWA3_MC,                0.043+BWA3_RSD, 0, 0,                0.250+BWA3_RSD, 0, -0.0100+BWA3_RCT,                0.430+BWA3_RSD, 0, 0};

	bwa3_recoil_single_gm6[] =                         {0, 0.030, 0.114+BWA3_MC,                0.043+BWA3_RSD, 0, 0,                0.250+BWA3_RSD, 0, -0.0130+BWA3_RCT,                0.430+BWA3_RSD, 0, 0};
	bwa3_recoil_single_prone_gm6[] =                 {0, 0.030, 0.074+BWA3_MC,                0.043+BWA3_RSD, 0, 0,                0.250+BWA3_RSD, 0, -0.0100+BWA3_RCT,                0.430+BWA3_RSD, 0, 0};

	bwa3_recoil_single_pistol9mm[] =                 {0, 0.010, 0.029+BWA3_MC,                0.046+BWA3_RSD, 0, 0,                0.090+BWA3_RSD, 0, -0.0075+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
	bwa3_recoil_single_pistol45[] =                 {0, 0.010, 0.033+BWA3_MC,                0.047+BWA3_RSD, 0, 0,                0.085+BWA3_RSD, 0, -0.0079+BWA3_RCT,                0.135+BWA3_RSD, 0, 0};
};

class CfgCameraShake {
	// What does this do, really? It seems like the engine no longer respects it.
	defaultCaliberCoefWeaponFire = 0;
};


// Completely disable BI's camshake on fire.
#define BWA3_CAMSHAKEFIRE_BASE 0
#define BWA3_CAMSHAKEFIRE_LESS 0
#define BWA3_CAMSHAKEFIRE_MORE 0

// Go through all modes that have a camshakefire defined and change it to ours.
class CfgMovesBasic {
	class Default {
		camShakeFire = BWA3_CAMSHAKEFIRE_NORMAL;
	};
};
class CfgMovesMaleSdr : CfgMovesBasic {
	class States {
		class AmovPercMstpSlowWrflDnon;
		class AmovPknlMstpSlowWrflDnon : AmovPercMstpSlowWrflDnon {
			camShakeFire = BWA3_CAMSHAKEFIRE_LESS;
		};
		class AmovPercMstpSrasWrflDnon;
		class AmovPpneMstpSrasWrflDnon : AmovPercMstpSrasWrflDnon {
			camShakeFire = BWA3_CAMSHAKEFIRE_LESS;
		};
		class AmovPknlMstpSrasWlnrDnon : Default {
			camShakeFire = BWA3_CAMSHAKEFIRE_LESS;
		};
		class AmovPknlMrunSlowWrflDf;
		class AmovPknlMtacSlowWrflDf : AmovPknlMrunSlowWrflDf {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMrunSlowWrflDfl;
		class AmovPknlMtacSlowWrflDfl : AmovPknlMrunSlowWrflDfl {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMrunSlowWrflDl;
		class AmovPknlMtacSlowWrflDl : AmovPknlMrunSlowWrflDl {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMrunSlowWrflDbl;
		class AmovPknlMtacSlowWrflDbl : AmovPknlMrunSlowWrflDbl {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMrunSlowWrflDb;
		class AmovPknlMtacSlowWrflDb : AmovPknlMrunSlowWrflDb {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMrunSlowWrflDbr;
		class AmovPknlMtacSlowWrflDbr : AmovPknlMrunSlowWrflDbr {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMrunSlowWrflDr;
		class AmovPknlMtacSlowWrflDr : AmovPknlMrunSlowWrflDr {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMrunSlowWrflDfr;
		class AmovPknlMtacSlowWrflDfr : AmovPknlMrunSlowWrflDfr {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMstpSrasWrflDnon;
		class AmovPknlMwlkSrasWrflDf : AmovPknlMstpSrasWrflDnon {
			camShakeFire = BWA3_CAMSHAKEFIRE_NORMAL;
		};
		class AmovPknlMrunSrasWrflDf;
		class AmovPknlMtacSrasWrflDf : AmovPknlMrunSrasWrflDf {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
		class AmovPknlMwlkSrasWpstDf;
		class AmovPknlMtacSrasWpstDf : AmovPknlMwlkSrasWpstDf {
			camShakeFire = BWA3_CAMSHAKEFIRE_MORE;
		};
	};
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {
	/////////////////////////////////////////////////////////////////////////////////
	// SMALL ARMS ///////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////

	// 1. Set the recoil profiles for all fire modes.
	// 2. Set the shake multiplier. This determines the camshake for the weapon.
	//     Ex: bwa3_recoil_shakeMultiplier = 1;

	class Rifle_Base_F;

	class arifle_MX_Base_F : Rifle_Base_F {        
		bwa3_recoil_shakeMultiplier = 1;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_mx";
			recoilProne = "bwa3_recoil_single_prone_mx";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_mx";
			recoilProne = "bwa3_recoil_auto_prone_mx";
		};
	};

	class arifle_MX_SW_F : arifle_MX_Base_F {
		bwa3_recoil_shakeMultiplier = 0.95;
		class Single : Single {
			recoil = "bwa3_recoil_single_mx";
			recoilProne = "bwa3_recoil_single_prone_mx";
		};
		
		class manual : FullAuto {
			recoil = "bwa3_recoil_auto_mx";
			recoilProne = "bwa3_recoil_auto_prone_mx";
		};
	};

	class arifle_katiba_Base_F : Rifle_Base_F {        
		bwa3_recoil_shakeMultiplier = 1;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_katiba";
			recoilProne = "bwa3_recoil_single_prone_katiba";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_katiba";
			recoilProne = "bwa3_recoil_auto_prone_katiba";
		};
	};

	class mk20_base_F : Rifle_Base_F {
		bwa3_recoil_shakeMultiplier = 0.9;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_mk20";
			recoilProne = "bwa3_recoil_single_prone_mk20";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_mk20";
			recoilProne = "bwa3_recoil_auto_prone_mk20";
		};
	};

	class arifle_Mk20C_F : mk20_base_F {
		bwa3_recoil_shakeMultiplier = 0.9;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_mk20";
			recoilProne = "bwa3_recoil_single_prone_mk20";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_mk20";
			recoilProne = "bwa3_recoil_auto_prone_mk20";
		};
	};

	class Tavor_base_F : Rifle_Base_F {
		bwa3_recoil_shakeMultiplier = 0.9;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_mk20";
			recoilProne = "bwa3_recoil_single_prone_mk20";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_mk20";
			recoilProne = "bwa3_recoil_auto_prone_mk20";
		};
	};

	class SDAR_base_F : Rifle_Base_F {
		bwa3_recoil_shakeMultiplier = 0.9;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_mk20";
			recoilProne = "bwa3_recoil_single_prone_mk20";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_mk20";
			recoilProne = "bwa3_recoil_auto_prone_mk20";
		};
	};

	////////////////////////////////////////////////

	class SMG_01_Base : Rifle_Base_F {
		bwa3_recoil_shakeMultiplier = 0.9;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_vermin";
			recoilProne = "bwa3_recoil_single_prone_vermin";
		};

		class Burst : Mode_Burst {
			recoil = "bwa3_recoil_auto_vermin";
			recoilProne = "bwa3_recoil_auto_vermin";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_vermin";
			recoilProne = "bwa3_recoil_auto_prone_vermin";
		};
	};

	class SMG_02_Base_F : Rifle_Base_F {
		bwa3_recoil_shakeMultiplier = 0.9;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_scorpion";
			recoilProne = "bwa3_recoil_single_prone_scorpion";
		};

		class Burst : Mode_Burst {
			recoil = "bwa3_recoil_auto_scorpion";
			recoilProne = "bwa3_recoil_auto_scorpion";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_scorpion";
			recoilProne = "bwa3_recoil_auto_prone_scorpion";
		};
	};

	class pdw2000_base_F: Rifle_Base_F {
		bwa3_recoil_shakeMultiplier = 0.9;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_scorpion";
			recoilProne = "bwa3_recoil_single_prone_scorpion";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_scorpion";
			recoilProne = "bwa3_recoil_auto_prone_scorpion";
		};
	};

	////////////////////////////////////////////////

	class Rifle_Long_Base_F;

	class LMG_Mk200_F : Rifle_Long_Base_F {
		bwa3_recoil_shakeMultiplier = 1.1;
		class manual : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_mk200";
			recoilprone = "bwa3_recoil_auto_prone_mk200";
		};
		class Single : manual {
			recoil = "bwa3_recoil_single_mk200";
			recoilprone = "bwa3_recoil_single_prone_mk200";
		};
	};

	class LMG_Zafir_F: Rifle_Long_Base_F {
		bwa3_recoil_shakeMultiplier = 1.3;
		class Single: Mode_SemiAuto {
			recoil = "bwa3_recoil_single_zafir";
			recoilprone = "bwa3_recoil_single_prone_zafir";
		};
		class FullAuto: Mode_FullAuto {
			recoil = "bwa3_recoil_auto_zafir";
			recoilprone = "bwa3_recoil_auto_prone_zafir";
		};
	};

	////////////////////////////////////////////////

	class EBR_base_F : Rifle_Long_Base_F {
		bwa3_recoil_shakeMultiplier = 1.3;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_ebr";
			recoilProne = "bwa3_recoil_single_prone_ebr";
		};
		
		class FullAuto : Mode_FullAuto {
			recoil = "bwa3_recoil_auto_ebr";
			recoilProne = "bwa3_recoil_auto_prone_ebr";
		};
	};

	class LRR_base_F : Rifle_Long_Base_F {
		bwa3_recoil_shakeMultiplier = 2.3;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_lrr";
			recoilProne = "bwa3_recoil_single_prone_lrr";
		};
	};

	class GM6_base_F : Rifle_Long_Base_F {
		bwa3_recoil_shakeMultiplier = 2.3;
		class Single : Mode_SemiAuto {
			recoil = "bwa3_recoil_single_gm6";
			recoilProne = "bwa3_recoil_single_prone_gm6";
		};
	};

	/////////////////////////////////////////////////

	class Pistol_Base_F;
	class hgun_P07_F : Pistol_Base_F {
		recoil = "bwa3_recoil_single_pistol9mm";
		recoilProne = "bwa3_recoil_single_pistol9mm";
	};

	class hgun_Rook40_F : Pistol_Base_F {
		recoil = "bwa3_recoil_single_pistol9mm";
		recoilProne = "bwa3_recoil_single_pistol9mm";
	};

	class hgun_ACPC2_F : Pistol_Base_F {
		recoil = "bwa3_recoil_single_pistol45";
		recoilProne = "bwa3_recoil_single_pistol45";
	};
};