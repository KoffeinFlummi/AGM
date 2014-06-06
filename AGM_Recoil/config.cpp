// SEE LICENSE.TXT FOR LICENSING INFORMATION

class CfgPatches {
  class AGM_Recoil {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, A3_Anims_F, AGM_Smallarms};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"TaoSensai"};
    authorUrl = "https://github.com/Taosenai/tmr";
  };
};

class CfgFunctions {
  class AGM_Recoil {
    class AGM_Recoil {
      file = "\AGM_Recoil\functions";
      class burstDispersion;
      class camshake;
      class camshakeNear;
    };
  };
};

// Fired EH
class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Recoil {
      clientFired = "if (player == _this select 0) then {_this call AGM_Recoil_fnc_camshake; _this call AGM_Recoil_fnc_burstDispersion}";
    };
  };
  class Tank {
    class AGM_Recoil {
      clientFired = "if (vehicle player == _this select 0) then {_this call AGM_Recoil_fnc_camshake}";
    };
  };
  class Car {
    class AGM_Recoil {
      clientFired = "if (vehicle player == _this select 0) then {_this call AGM_Recoil_fnc_camshake}";
    };
  };
  class Helicopter {
    class AGM_Recoil {
      clientFired = "if (vehicle player == _this select 0) then {_this call AGM_Recoil_fnc_camshake}";
    };
  };
  class Plane {
    class AGM_Recoil {
      clientFired = "if (vehicle player == _this select 0) then {_this call AGM_Recoil_fnc_camshake}";
    };
  };
};

//FiredNear EH
class Extended_FiredNear_EventHandlers {
  class CAManBase {
    class AGM_Camshake {
      clientFired = "if (player == _this select 0) then {_this call AGM_Recoil_fnc_camshakeNear}";
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
#define AGM_MC 0.0089

// Global recovery sequence duration increase (For easy tuning.)
#define AGM_RSD 0.06031

// Global recovery downward muzzle movement.
#define AGM_RCT -0.0028

 // 0.114 +AGM_RSD
class CfgRecoils {
  /*
  agm_recoil_single_mx[] =             {0,0.014,0.024+AGM_MC, 0.048+AGM_RSD,0,0, 0.081+AGM_RSD,0,-0.0069+AGM_RCT, 0.135+AGM_RSD,0,0};
  agm_recoil_auto_mx[] =               {0,0.014,0.024+AGM_MC, 0.048+AGM_RSD,0,0, 0.081+AGM_RSD,0,-0.0072+AGM_RCT, 0.135+AGM_RSD,0,0};
  agm_recoil_single_prone_mx[] =       {0,0.014,0.011+AGM_MC, 0.048+AGM_RSD,0,0, 0.081+AGM_RSD,0,-0.0036+AGM_RCT, 0.135+AGM_RSD,0,0};
  agm_recoil_auto_prone_mx[] =         {0,0.014,0.011+AGM_MC, 0.048+AGM_RSD,0,0, 0.081+AGM_RSD,0,-0.0038+AGM_RCT, 0.135+AGM_RSD,0,0};
  */

  agm_recoil_single_mx[] =             {0,0.07,0.01,  0.1,0,0,  0.15,-0.05,-0.005,  0.2,0,0};
  agm_recoil_auto_mx[] =               {0,0.07,0.01,  0.1,0,0,  0.15,-0.05,-0.005,  0.2,0,0};
  agm_recoil_single_prone_mx[] =       {0,0.07,0.01,  0.1,0,0,  0.15,-0.05,-0.005,  0.2,0,0};
  agm_recoil_auto_prone_mx[] =         {0,0.07,0.01,  0.1,0,0,  0.15,-0.05,-0.005,  0.2,0,0};

  agm_recoil_single_katiba[] =         {0, 0.014, 0.022+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.078+AGM_RSD, 0, -0.0068+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_katiba[] =           {0, 0.014, 0.022+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.078+AGM_RSD, 0, -0.0071+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_single_prone_katiba[] =   {0, 0.014, 0.009+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.078+AGM_RSD, 0, -0.0035+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_prone_katiba[] =     {0, 0.014, 0.009+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.078+AGM_RSD, 0, -0.0037+AGM_RCT, 0.135+AGM_RSD, 0, 0};

  agm_recoil_single_mk20[] =           {0, 0.013, 0.012+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.078+AGM_RSD, 0, -0.0033+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_mk20[] =             {0, 0.013, 0.012+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.078+AGM_RSD, 0, -0.0034+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_single_prone_mk20[] =     {0, 0.013, 0.002+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.078+AGM_RSD, 0, -0.0007+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_prone_mk20[] =       {0, 0.013, 0.002+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.078+AGM_RSD, 0, -0.0008+AGM_RCT, 0.135+AGM_RSD, 0, 0};

  agm_recoil_single_vermin[] =         {0, 0.008, 0.011+AGM_MC, 0.047+AGM_RSD, 0, 0, 0.071+AGM_RSD, 0, -0.0031+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_vermin[] =           {0, 0.008, 0.011+AGM_MC, 0.047+AGM_RSD, 0, 0, 0.071+AGM_RSD, 0, -0.0033+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_single_prone_vermin[] =   {0, 0.008, 0.002+AGM_MC, 0.047+AGM_RSD, 0, 0, 0.071+AGM_RSD, 0, -0.0007+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_prone_vermin[] =     {0, 0.008, 0.002+AGM_MC, 0.047+AGM_RSD, 0, 0, 0.071+AGM_RSD, 0, -0.0007+AGM_RCT, 0.135+AGM_RSD, 0, 0};

  agm_recoil_single_scorpion[] =       {0, 0.008, 0.012+AGM_MC, 0.046+AGM_RSD, 0, 0, 0.072+AGM_RSD, 0, -0.0030+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_scorpion[] =         {0, 0.008, 0.013+AGM_MC, 0.046+AGM_RSD, 0, 0, 0.072+AGM_RSD, 0, -0.0033+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_single_prone_scorpion[] = {0, 0.008, 0.002+AGM_MC, 0.047+AGM_RSD, 0, 0, 0.071+AGM_RSD, 0, -0.0007+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_prone_scorpion[] =   {0, 0.008, 0.002+AGM_MC, 0.047+AGM_RSD, 0, 0, 0.071+AGM_RSD, 0, -0.0007+AGM_RCT, 0.135+AGM_RSD, 0, 0};

  agm_recoil_single_mk200[] =          {0, 0.014, 0.021+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.079+AGM_RSD, 0, -0.0063+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_mk200[] =            {0, 0.014, 0.021+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.079+AGM_RSD, 0, -0.0143+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_single_prone_mk200[] =    {0, 0.014, 0.002+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.077+AGM_RSD, 0, -0.0037+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_prone_mk200[] =      {0, 0.014, 0.002+AGM_MC, 0.048+AGM_RSD, 0, 0, 0.077+AGM_RSD, 0, -0.0041+AGM_RCT, 0.135+AGM_RSD, 0, 0};

  agm_recoil_single_zafir[] =          {0, 0.015, 0.026+AGM_MC, 0.045+AGM_RSD, 0, 0, 0.088+AGM_RSD, 0, -0.0072+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_zafir[] =            {0, 0.015, 0.026+AGM_MC, 0.045+AGM_RSD, 0, 0, 0.088+AGM_RSD, 0, -0.0147+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_single_prone_zafir[] =    {0, 0.015, 0.004+AGM_MC, 0.045+AGM_RSD, 0, 0, 0.080+AGM_RSD, 0, -0.0017+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_prone_zafir[] =      {0, 0.015, 0.004+AGM_MC, 0.045+AGM_RSD, 0, 0, 0.080+AGM_RSD, 0, -0.0070+AGM_RCT, 0.135+AGM_RSD, 0, 0};

  agm_recoil_single_ebr[] =            {0, 0.014, 0.028+AGM_MC, 0.045+AGM_RSD, 0, 0, 0.084+AGM_RSD, 0, -0.0074+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_ebr[] =              {0, 0.014, 0.028+AGM_MC, 0.045+AGM_RSD, 0, 0, 0.084+AGM_RSD, 0, -0.0077+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_single_prone_ebr[] =      {0, 0.014, 0.013+AGM_MC, 0.045+AGM_RSD, 0, 0, 0.084+AGM_RSD, 0, -0.0038+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_auto_prone_ebr[] =        {0, 0.014, 0.013+AGM_MC, 0.045+AGM_RSD, 0, 0, 0.084+AGM_RSD, 0, -0.0041+AGM_RCT, 0.135+AGM_RSD, 0, 0};

  agm_recoil_single_lrr[] =            {0, 0.030, 0.114+AGM_MC, 0.043+AGM_RSD, 0, 0, 0.250+AGM_RSD, 0, -0.0130+AGM_RCT, 0.430+AGM_RSD, 0, 0};
  agm_recoil_single_prone_lrr[] =      {0, 0.030, 0.074+AGM_MC, 0.043+AGM_RSD, 0, 0, 0.250+AGM_RSD, 0, -0.0100+AGM_RCT, 0.430+AGM_RSD, 0, 0};

  agm_recoil_single_gm6[] =            {0, 0.030, 0.114+AGM_MC, 0.043+AGM_RSD, 0, 0, 0.250+AGM_RSD, 0, -0.0130+AGM_RCT, 0.430+AGM_RSD, 0, 0};
  agm_recoil_single_prone_gm6[] =      {0, 0.030, 0.074+AGM_MC, 0.043+AGM_RSD, 0, 0, 0.250+AGM_RSD, 0, -0.0100+AGM_RCT, 0.430+AGM_RSD, 0, 0};

  agm_recoil_single_pistol9mm[] =      {0, 0.010, 0.029+AGM_MC, 0.046+AGM_RSD, 0, 0, 0.090+AGM_RSD, 0, -0.0075+AGM_RCT, 0.135+AGM_RSD, 0, 0};
  agm_recoil_single_pistol45[] =       {0, 0.010, 0.033+AGM_MC, 0.047+AGM_RSD, 0, 0, 0.085+AGM_RSD, 0, -0.0079+AGM_RCT, 0.135+AGM_RSD, 0, 0};
};

class CfgCameraShake {
  // What does this do, really? It seems like the engine no longer respects it.
  defaultCaliberCoefWeaponFire = 0;
};

// Completely disable BI's camshake on fire.
#define AGM_CAMSHAKEFIRE_BASE 0
#define AGM_CAMSHAKEFIRE_LESS 0
#define AGM_CAMSHAKEFIRE_MORE 0

// Go through all modes that have a camshakefire defined and change it to ours.
class CfgMovesBasic {
  class Default {
    camShakeFire = AGM_CAMSHAKEFIRE_NORMAL;
  };
};
class CfgMovesMaleSdr : CfgMovesBasic {
  class States {
    class AmovPercMstpSlowWrflDnon;
    class AmovPknlMstpSlowWrflDnon : AmovPercMstpSlowWrflDnon {
      camShakeFire = AGM_CAMSHAKEFIRE_LESS;
    };
    class AmovPercMstpSrasWrflDnon;
    class AmovPpneMstpSrasWrflDnon : AmovPercMstpSrasWrflDnon {
      camShakeFire = AGM_CAMSHAKEFIRE_LESS;
    };
    class AmovPknlMstpSrasWlnrDnon : Default {
      camShakeFire = AGM_CAMSHAKEFIRE_LESS;
    };
    class AmovPknlMrunSlowWrflDf;
    class AmovPknlMtacSlowWrflDf : AmovPknlMrunSlowWrflDf {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMrunSlowWrflDfl;
    class AmovPknlMtacSlowWrflDfl : AmovPknlMrunSlowWrflDfl {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMrunSlowWrflDl;
    class AmovPknlMtacSlowWrflDl : AmovPknlMrunSlowWrflDl {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMrunSlowWrflDbl;
    class AmovPknlMtacSlowWrflDbl : AmovPknlMrunSlowWrflDbl {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMrunSlowWrflDb;
    class AmovPknlMtacSlowWrflDb : AmovPknlMrunSlowWrflDb {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMrunSlowWrflDbr;
    class AmovPknlMtacSlowWrflDbr : AmovPknlMrunSlowWrflDbr {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMrunSlowWrflDr;
    class AmovPknlMtacSlowWrflDr : AmovPknlMrunSlowWrflDr {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMrunSlowWrflDfr;
    class AmovPknlMtacSlowWrflDfr : AmovPknlMrunSlowWrflDfr {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMstpSrasWrflDnon;
    class AmovPknlMwlkSrasWrflDf : AmovPknlMstpSrasWrflDnon {
      camShakeFire = AGM_CAMSHAKEFIRE_NORMAL;
    };
    class AmovPknlMrunSrasWrflDf;
    class AmovPknlMtacSrasWrflDf : AmovPknlMrunSrasWrflDf {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
    class AmovPknlMwlkSrasWpstDf;
    class AmovPknlMtacSrasWpstDf : AmovPknlMwlkSrasWpstDf {
      camShakeFire = AGM_CAMSHAKEFIRE_MORE;
    };
  };
};

#include <CamShake_Ammo_Config.hpp>
#include <CamShake_Vehicles_Config.hpp>
#include <CamShake_Weapons_Config.hpp>
