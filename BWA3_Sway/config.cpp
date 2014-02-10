// SEE LICENSE.TXT FOR LICENSING INFORMATION

class CfgPatches {
  class BWA3_Recoil {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, A3_Anims_F};
    version = 1.0;
    author[] = {"TaoSensai"};
    authorUrl = "https://github.com/Taosenai/tmr";
  };
};

class CfgMods {
  class BWA3_Recoil {
    dir = "BWA3_Sway";
    name = "BWA3: Sway Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

// EVERYTHING BELOW BELONGS TO TAOSENSAI

#define TMR_SWAY_005 0.048
#define TMR_SWAY_01 0.09
#define TMR_SWAY_03 0.28
#define TMR_SWAY_05 0.47
#define TMR_SWAY_055 0.53
#define TMR_SWAY_07 0.67
#define TMR_SWAY_10 1.02
#define TMR_SWAY_105 1.07
#define TMR_SWAY_12 1.13
#define TMR_SWAY_15 1.43
#define TMR_SWAY_165 1.5
#define TMR_SWAY_17 1.6
#define TMR_SWAY_20 1.8
#define TMR_SWAY_25 2.2
#define TMR_SWAY_30 3.1
#define TMR_SWAY_40 3.8
#define TMR_SWAY_50 4.8
#define TMR_SWAY_70 6.8


class CfgMovesBasic {
  class Default {
    aimPrecision = TMR_SWAY_10;
  };
};
class CfgMovesMaleSdr : CfgMovesBasic { 
  class States {
    class AidlPercMstpSrasWrflDnon_G0S;
    class AmovPercMstpSrasWrflDnon_turnL : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPercMstpSrasWrflDnon_turnR : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPercMstpSrasWrflDnon_AadjPercMstpSrasWrflDup : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_10;

    };
    class AmovPercMstpSrasWrflDnon_AadjPercMstpSrasWrflDdown : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_10;

    };
    class AmovPercMstpSrasWrflDnon_AadjPercMstpSrasWrflDleft : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_10;

    };
    class AmovPercMstpSrasWrflDnon_AadjPercMstpSrasWrflDright : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_10;

    };
    class AadjPercMstpSrasWrflDup : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_10;

    };
    class AmovPercMstpSlowWrflDnon;
    class AmovPknlMstpSlowWrflDnon : AmovPercMstpSlowWrflDnon {
      aimPrecision = TMR_SWAY_055;

    };
    class AmovPknlMstpSlowWrflDnon_relax : AmovPknlMstpSlowWrflDnon {
      aimPrecision = TMR_SWAY_05;

    };
    class AmovPknlMstpSrasWrflDnon;
    class AmovPknlMstpSrasWrflDnon_turnL : AmovPknlMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_25;

    };
    class AmovPknlMstpSrasWrflDnon_turnR : AmovPknlMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_25;

    };
    class AmovPercMstpSrasWrflDnon;
    class AmovPpneMstpSrasWrflDnon : AmovPercMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_01;
    };
    class AidlPpneMstpSrasWrflDnon_G0S;
    class AmovPpneMstpSrasWrflDnon_relax : AidlPpneMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_03;

    };
    class AmovPpneMstpSrasWrflDnon_turnL : AidlPpneMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_40;

    };
    class AmovPpneMstpSrasWrflDnon_turnR : AidlPpneMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_40;

    };
    class AmovPercMstpSrasWpstDnon;
    class AmovPercMstpSrasWpstDnon_AadjPercMstpSrasWpstDup : AmovPercMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_10;

    };
    class AmovPercMstpSrasWpstDnon_AadjPercMstpSrasWpstDdown : AmovPercMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_10;

    };
    class AmovPercMstpSrasWpstDnon_AadjPercMstpSrasWpstDleft : AmovPercMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_10;

    };
    class AmovPercMstpSrasWpstDnon_AadjPercMstpSrasWpstDright : AmovPercMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_10;

    };
    class AadjPercMstpSrasWpstDup : AmovPercMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_10;

    };
    class AmovPercMstpSrasWpstDnon_turnL : AmovPercMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPercMstpSrasWpstDnon_turnR : AmovPercMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPknlMstpSrasWpstDnon;
    class AmovPcrhMstpSrasWpstDnon_AadjPcrhMstpSrasWpstDup : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_105;

    };
    class AmovPcrhMstpSrasWpstDnon_AadjPcrhMstpSrasWpstDdown : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_105;

    };
    class AmovPcrhMstpSrasWpstDnon_AadjPcrhMstpSrasWpstDleft : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_105;

    };
    class AmovPcrhMstpSrasWpstDnon_AadjPcrhMstpSrasWpstDright : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_105;

    };
    class AadjPcrhMstpSrasWpstDup : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_105;

    };
    class AmovPknlMstpSrasWpstDnon_AadjPknlMstpSrasWpstDup : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_055;

    };
    class AmovPknlMstpSrasWpstDnon_AadjPknlMstpSrasWpstDdown : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_055;

    };
    class AmovPknlMstpSrasWpstDnon_AadjPknlMstpSrasWpstDleft : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_055;

    };
    class AmovPknlMstpSrasWpstDnon_AadjPknlMstpSrasWpstDright : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_055;

    };
    class AadjPknlMstpSrasWpstDup : AmovPknlMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_055;

    };
    class AmovPknlMwlkSlowWpstDf;
    class AmovPknlMtacSlowWpstDf : AmovPknlMwlkSlowWpstDf {
      aimPrecision = TMR_SWAY_30;

    };
    class AmovPknlMstpSrasWpstDnon_turnL : AmovPknlMstpSrasWpstDnon {
      aimPrecision =TMR_SWAY_30;

    };
    class AmovPknlMstpSrasWpstDnon_turnR : AmovPknlMstpSrasWpstDnon {
      aimPrecision =TMR_SWAY_30;

    };
    class AmovPpneMstpSrasWpstDnon : AmovPercMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_01;

    };
    class AidlPpneMstpSrasWpstDnon_G0S;
    class AmovPpneMstpSrasWpstDnon_turnL : AidlPpneMstpSrasWpstDnon_G0S {
      aimPrecision = TMR_SWAY_40;

    };
    class AmovPpneMstpSrasWpstDnon_turnR : AidlPpneMstpSrasWpstDnon_G0S {
      aimPrecision = TMR_SWAY_40;
    };
    class AmovPknlMstpSrasWlnrDnon : Default {
      aimPrecision = TMR_SWAY_055;

    };
    class AidlPknlMstpSrasWlnrDnon_G0S;
    class AmovPknlMstpSrasWlnrDnon_turnL : AidlPknlMstpSrasWlnrDnon_G0S {
      aimPrecision =TMR_SWAY_30;

    };
    class AmovPknlMstpSrasWlnrDnon_turnR : AidlPknlMstpSrasWlnrDnon_G0S {
      aimPrecision =TMR_SWAY_30;

    };
    class amovppnemstpsraswlnrdnon;
    class amovppnemstpsraswlnrdnon_turnl : amovppnemstpsraswlnrdnon {
      aimPrecision = TMR_SWAY_40;

    };
    class amovppnemstpsraswlnrdnon_turnr : amovppnemstpsraswlnrdnon {
      aimPrecision = TMR_SWAY_40;

    };
    class AmovPercMwlkSlowWrflDf : AmovPercMstpSlowWrflDnon {
      aimPrecision = TMR_SWAY_30;

    };
    class AmovPercMwlkSrasWrflDf : AmovPercMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_15;
    };
    class AmovPercMtacSrasWrflDf : AmovPercMwlkSrasWrflDf {
      aimPrecision = TMR_SWAY_30;
    };
    class AmovPercMrunSrasWrflDf : AmovPercMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_50;
    };
    class AidlPknlMstpSlowWpstDnon_G0S;
    class AmovPknlMwlkSlowWrflDf : AidlPknlMstpSlowWpstDnon_G0S {
      aimPrecision = TMR_SWAY_165;
    };
    class AmovPknlMrunSlowWrflDf;
    class AmovPknlMtacSlowWrflDf : AmovPknlMrunSlowWrflDf {
      aimPrecision = TMR_SWAY_165;
    };
    class AmovPknlMrunSlowWrflDfl;
    class AmovPknlMtacSlowWrflDfl : AmovPknlMrunSlowWrflDfl {
      aimPrecision = TMR_SWAY_165;

    };
    class AmovPknlMrunSlowWrflDl;
    class AmovPknlMtacSlowWrflDl : AmovPknlMrunSlowWrflDl {
      aimPrecision = TMR_SWAY_165;

    };
    class AmovPknlMrunSlowWrflDbl;
    class AmovPknlMtacSlowWrflDbl : AmovPknlMrunSlowWrflDbl {
      aimPrecision = TMR_SWAY_165;

    };
    class AmovPknlMrunSlowWrflDb;
    class AmovPknlMtacSlowWrflDb : AmovPknlMrunSlowWrflDb {
      aimPrecision = TMR_SWAY_165;

    };
    class AmovPknlMrunSlowWrflDbr;
    class AmovPknlMtacSlowWrflDbr : AmovPknlMrunSlowWrflDbr {
      aimPrecision = TMR_SWAY_165;

    };
    class AmovPknlMrunSlowWrflDr;
    class AmovPknlMtacSlowWrflDr : AmovPknlMrunSlowWrflDr {
      aimPrecision = TMR_SWAY_165;

    };
    class AmovPknlMrunSlowWrflDfr;
    class AmovPknlMtacSlowWrflDfr : AmovPknlMrunSlowWrflDfr {
      aimPrecision = TMR_SWAY_165;

    };
    class AmovPknlMwlkSrasWrflDf : AmovPknlMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_12;

    };
    class AmovPknlMrunSrasWrflDf;
    class AmovPknlMtacSrasWrflDf : AmovPknlMrunSrasWrflDf {
      aimPrecision = TMR_SWAY_25;

    };
    class AmovPercMwlkSrasWpstDf : AmovPercMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_15;

    };
    class AmovPercMwlkSlowWpstDf;
    class AmovPercMtacSlowWpstDf : AmovPercMwlkSlowWpstDf {
      aimPrecision = TMR_SWAY_30;

    };
    class AmovPercMtacSrasWpstDf : AmovPercMwlkSrasWpstDf {
      aimPrecision = TMR_SWAY_30;

    };
    class AmovPknlMwlkSrasWpstDf : AmovPknlMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_12;

    };
    class AmovPknlMtacSrasWpstDf : AmovPknlMwlkSrasWpstDf {
      aimPrecision = TMR_SWAY_25;

    };
    class AmovPknlMwlkSrasWlnrDf : AidlPknlMstpSrasWlnrDnon_G0S {
      aimPrecision = TMR_SWAY_15;

    };
    class AmovPknlMtacSrasWlnrDf : AidlPknlMstpSrasWlnrDnon_G0S {
      aimPrecision = TMR_SWAY_165;
    };
    class AmovPincMstpSrasWrflDnon : AmovPpneMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_03;

    };
    class WeaponMagazineReloadStand;
    class WeaponMagazineReloadProne : WeaponMagazineReloadStand {
      aimPrecision = TMR_SWAY_05;

    };
    class PistolMagazineReloadStand;
    class PistolMagazineReloadProne : PistolMagazineReloadStand {
      aimPrecision = TMR_SWAY_05;

    };
    class AadjPknlMstpSrasWrflDdown;
    class AadjPpneMstpSrasWrflDup_AadjPknlMstpSrasWrflDdown : AadjPknlMstpSrasWrflDdown {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPpneMstpSrasWrflDup;
    class AadjPknlMstpSrasWrflDdown_AadjPpneMstpSrasWrflDup : AadjPpneMstpSrasWrflDup {
      aimPrecision = TMR_SWAY_01;

    };
    class TransAnimBase;
    class AmovPercMstpSrasWlnrDnon_AmovPpneMstpSrasWlnrDnon : TransAnimBase {
      aimPrecision = TMR_SWAY_01;

    };
    class AmovPercMstpSrasWrflDnon_AmovPpneMstpSrasWrflDnon : AmovPpneMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_01;

    };
    class AmovPknlMstpSrasWrflDnon_AmovPpneMstpSrasWrflDnon : AmovPpneMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_01;

    };
    class amovpercmstpsraswrfldnon_amovpercmstpsraswlnrdnon;
    class AmovPknlMstpSrasWrflDnon_AmovPknlMstpSrasWlnrDnon : amovpercmstpsraswrfldnon_amovpercmstpsraswlnrdnon {
      aimPrecision = TMR_SWAY_055;

    };
    class AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWlnrDnon_end;
    class AmovPknlMstpSrasWrflDnon_AmovPknlMstpSrasWlnrDnon_end : AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWlnrDnon_end {
      aimPrecision = TMR_SWAY_055;

    };
    class amovpercmstpsraswlnrdnon_amovpercmstpsraswrfldnon;
    class AmovPknlMstpSrasWlnrDnon_AmovPknlMstpSrasWrflDnon : amovpercmstpsraswlnrdnon_amovpercmstpsraswrfldnon {
      aimPrecision = TMR_SWAY_055;

    };
    class amovpercmstpsraswlnrdnon_amovpercmstpsraswrfldnon_end;
    class AmovPknlMstpSrasWlnrDnon_AmovPknlMstpSrasWrflDnon_end : amovpercmstpsraswlnrdnon_amovpercmstpsraswrfldnon_end {
      aimPrecision = TMR_SWAY_055;

    };
    class AmovPercMevaSrasWrflDf;
    class AmovPercMevaSlowWrflDfl : AmovPercMevaSrasWrflDf {
      aimPrecision = TMR_SWAY_30;

    };
    class AdvePercMstpSnonWrflDnon : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_17;

    };
    class AsdvPercMstpSnonWrflDnon : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_17;

    };
    class AbdvPercMstpSnonWrflDnon : AidlPercMstpSrasWrflDnon_G0S {
      aimPrecision = TMR_SWAY_17;

    };
    class AdvePercMstpSnonWrflDnon_AdvePercMstpSnonWnonDnon : AdvePercMstpSnonWrflDnon {
      aimPrecision = TMR_SWAY_07;

    };
    class AdvePercMstpSnonWnonDnon;
    class AdvePercMstpSnonWnonDnon_AdvePercMstpSnonWrflDnon : AdvePercMstpSnonWnonDnon {
      aimPrecision = TMR_SWAY_07;

    };
    class AbdvPercMstpSnonWnonDnon;
    class AbdvPercMstpSnonWnonDnon_AbdvPercMstpSnonWrflDnon : AbdvPercMstpSnonWnonDnon {
      aimPrecision = TMR_SWAY_07;

    };
    class AsdvPercMstpSnonWrflDnon_AsdvPercMstpSnonWnonDnon : AsdvPercMstpSnonWrflDnon {
      aimPrecision = TMR_SWAY_07;

    };
    class AsdvPercMstpSnonWnonDnon;
    class AsdvPercMstpSnonWnonDnon_AsdvPercMstpSnonWrflDnon : AsdvPercMstpSnonWnonDnon {
      aimPrecision = TMR_SWAY_07;

    };
    class AwopPercMstpSoptWbinDnon_rfl : AmovPercMstpSlowWrflDnon {
      aimprecision = TMR_SWAY_10;

    };
    class AmovPercMwlkSoptWbinDf_rfl : AwopPercMstpSoptWbinDnon_rfl {
      aimprecision = TMR_SWAY_10;

    };
    class AwopPknlMstpSoptWbinDnon_rfl : AmovPknlMstpSrasWrflDnon {
      aimprecision = TMR_SWAY_03;

    };
    class AmovPknlMwlkSoptWbinDf_rfl : AwopPknlMstpSoptWbinDnon_rfl {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPpneMstpSoptWbinDnon_rfl : AmovPpneMstpSrasWrflDnon {
      aimprecision = TMR_SWAY_005;

    };
    class AmovPpneMwlkSoptWbinDf_rfl : AwopPpneMstpSoptWbinDnon_rfl {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPercMstpSoptWbinDnon_pst : AmovPercMstpSlowWrflDnon {
      aimprecision = TMR_SWAY_10;

    };
    class AmovPercMwlkSoptWbinDf_pst : AwopPercMstpSoptWbinDnon_pst {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPknlMstpSoptWbinDnon_pst : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_03;

    };
    class AmovPknlMwlkSoptWbinDf_pst : AwopPknlMstpSoptWbinDnon_pst {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPpneMstpSoptWbinDnon_pst : AmovPpneMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_005;

    };
    class AmovPpneMwlkSoptWbinDf_pst : AwopPpneMstpSoptWbinDnon_pst {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPercMstpSoptWbinDnon_lnr : AmovPercMstpSlowWrflDnon {
      aimprecision = TMR_SWAY_10;

    };
    class AmovPercMwlkSoptWbinDf_lnr : AwopPercMstpSoptWbinDnon_lnr {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPknlMstpSoptWbinDnon_lnr : AmovPknlMstpSrasWlnrDnon {
      aimprecision = TMR_SWAY_03;

    };
    class AmovPknlMwlkSoptWbinDf_lnr : AwopPknlMstpSoptWbinDnon_lnr {
      aimprecision = TMR_SWAY_25;
    };
    class AwopPpneMstpSoptWbinDnon_lnr : amovppnemstpsraswlnrdnon {
      aimprecision = TMR_SWAY_005;

    };
    class AmovPpneMwlkSoptWbinDf_lnr : AwopPpneMstpSoptWbinDnon_lnr {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPercMstpSoptWbinDnon_non : AmovPercMstpSlowWrflDnon {
      aimprecision = TMR_SWAY_10;

    };
    class AmovPercMwlkSoptWbinDf_non : AwopPercMstpSoptWbinDnon_non {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPknlMstpSoptWbinDnon_non : AmovPknlMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_03;

    };
    class AmovPknlMwlkSoptWbinDf_non : AwopPknlMstpSoptWbinDnon_non {
      aimprecision = TMR_SWAY_25;

    };
    class AwopPpneMstpSoptWbinDnon_non : AmovPpneMstpSrasWpstDnon {
      aimprecision = TMR_SWAY_005;

    };
    class AmovPpneMwlkSoptWbinDf_non : AwopPpneMstpSoptWbinDnon_non {
      aimprecision = TMR_SWAY_25;

    };
    class AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_1;
    class AcinPknlMstpSrasWrflDnon : AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_1 {
      aimPrecision = TMR_SWAY_30;

    };
    class AcinPknlMwlkSrasWrflDb : AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_1 {
      aimPrecision = TMR_SWAY_50;

    };
    class AcinPknlMstpSrasWrflDnon_AcinPercMrunSrasWrflDnon;
    class AcinPercMstpSrasWrflDnon : AcinPknlMstpSrasWrflDnon_AcinPercMrunSrasWrflDnon {
      aimPrecision = TMR_SWAY_30;

    };
    class AcinPknlMstpSnonWnonDnon_AcinPercMrunSnonWnonDnon;
    class AcinPercMstpSnonWnonDnon : AcinPknlMstpSnonWnonDnon_AcinPercMrunSnonWnonDnon {
      aimPrecision = TMR_SWAY_50;

    };
    class AcinPercMstpSnonWpstDnon : AcinPercMstpSnonWnonDnon {
      aimPrecision = TMR_SWAY_30;

    };
    class amovpercmstpsraswlnrdnon;
    class amovpercmstpSlowwlnrdnon : amovpercmstpsraswlnrdnon {
      aimPrecision = TMR_SWAY_10;

    };
    class AmovPercMwlkSlowWlnrDf : amovpercmstpSlowwlnrdnon {
      aimPrecision = TMR_SWAY_30;

    };
    class AidlPercMstpSrasWlnrDnon_G0S;
    class AmovPercMwlkSrasWlnrDf : AidlPercMstpSrasWlnrDnon_G0S {
      aimPrecision = TMR_SWAY_30;

    };
    class AmovPercMtacSrasWlnrDf : AidlPercMstpSrasWlnrDnon_G0S {
      aimPrecision = TMR_SWAY_30;

    };
    class amovpercmstpsraswlnrdnon_turnl : amovpercmstpsraswlnrdnon {
      aimPrecision = TMR_SWAY_20;

    };
    class amovpercmstpSraswlnrdnon_turnr : amovpercmstpsraswlnrdnon {
      aimPrecision = TMR_SWAY_20;

    };
    class AadjPknlMstpSrasWrflDleft;
    class AadjPercMstpSrasWrflDleft_AadjPknlMstpSrasWrflDleft : AadjPknlMstpSrasWrflDleft {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPknlMstpSrasWrflDright;
    class AadjPercMstpSrasWrflDright_AadjPknlMstpSrasWrflDright : AadjPknlMstpSrasWrflDright {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPercMstpSrasWrflDdown_AadjPknlMstpSrasWrflDdown : AadjPknlMstpSrasWrflDdown {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPknlMstpSrasWrflDup;
    class AadjPercMstpSrasWrflDdown_AadjPknlMstpSrasWrflDup : AadjPknlMstpSrasWrflDup {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPercMstpSrasWrflDup_AadjPknlMstpSrasWrflDup : AadjPknlMstpSrasWrflDup {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPknlMstpSrasWpstDleft;
    class AadjPercMstpSrasWpstDleft_AadjPknlMstpSrasWpstDleft : AadjPknlMstpSrasWpstDleft {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPknlMstpSrasWpstDright;
    class AadjPercMstpSrasWpstDright_AadjPknlMstpSrasWpstDright : AadjPknlMstpSrasWpstDright {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPknlMstpSrasWpstDdown;
    class AadjPercMstpSrasWpstDdown_AadjPknlMstpSrasWpstDdown : AadjPknlMstpSrasWpstDdown {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPercMstpSrasWpstDdown_AadjPknlMstpSrasWpstDup : AadjPknlMstpSrasWpstDup {
      aimPrecision = TMR_SWAY_055;

    };
    class AadjPercMstpSrasWpstDup_AadjPknlMstpSrasWpstDup : AadjPknlMstpSrasWpstDup {
      aimPrecision = TMR_SWAY_055;

    };
    class AmovPercMrunSrasWrflDf_AmovPercMrunSrasWrflDfr : AmovPercMrunSrasWrflDf {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPercMrunSrasWrflDf_AmovPercMrunSrasWrflDfl : AmovPercMrunSrasWrflDf {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPercMrunSrasWrflDfl;
    class AmovPercMrunSrasWrflDfl_AmovPercMrunSrasWrflDfr : AmovPercMrunSrasWrflDfl {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPercMrunSrasWrflDfl_AmovPercMrunSrasWrflDf : AmovPercMrunSrasWrflDfl {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPercMrunSrasWrflDfr;
    class AmovPercMrunSrasWrflDfr_AmovPercMrunSrasWrflDfl : AmovPercMrunSrasWrflDfr {
      aimPrecision = TMR_SWAY_20;

    };
    class AmovPercMrunSrasWrflDfr_AmovPercMrunSrasWrflDf : AmovPercMrunSrasWrflDfr {
      aimPrecision = TMR_SWAY_20;

    };
    class AfalPercMstpSrasWrflDnon : AmovPercMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AfalPknlMstpSrasWrflDnon : AmovPknlMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AfalPpneMstpSrasWrflDnon : AmovPpneMstpSrasWrflDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AfalPercMstpSrasWpstDnon : AmovPercMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AfalPknlMstpSrasWpstDnon : AmovPknlMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AfalPpneMstpSrasWpstDnon : AmovPpneMstpSrasWpstDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AmovPercMstpSnonWnonDnon;
    class AfalPercMstpSnonWnonDnon : AmovPercMstpSnonWnonDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AmovPknlMstpSnonWnonDnon;
    class AfalPknlMstpSnonWnonDnon : AmovPknlMstpSnonWnonDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AmovPpneMstpSnonWnonDnon;
    class AfalPpneMstpSnonWnonDnon : AmovPpneMstpSnonWnonDnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AfalPercMstpSrasWlnrDnon : amovpercmstpsraswlnrdnon {
      aimPrecision = TMR_SWAY_70;

    };
    class AfalPknlMstpSrasWlnrDnon : AmovPknlMstpSrasWlnrDnon {
      aimPrecision = TMR_SWAY_70;

    };
  };
};