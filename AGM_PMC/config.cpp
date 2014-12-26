
/*
New classes:

    CfgVehicles
  AGM_I_PMC_Security_Contractor_F
  AGM_I_PMC_Security_Contractor_lite_F
  AGM_I_PMC_Squad_Coordinator_F
  AGM_I_PMC_Team_Coordinator_F
  AGM_I_PMC_Tactical_Specialist_AR_F
  AGM_I_PMC_Field_Medic_F
  AGM_I_PMC_Field_Technician_F
  AGM_I_PMC_Field_Specialist_exp_F
  AGM_I_PMC_Security_Contractor_GL_F
  AGM_I_PMC_Defensive_Marksman_F
  AGM_I_PMC_Field_Specialist_AT_F
  AGM_I_PMC_Tactical_Driver
  AGM_I_PMC_Tactical_Pilot

  AGM_I_PMC_SUV_01_F
  AGM_I_PMC_Quadbike_01_F
  AGM_I_PMC_Heli_Light_01_F
  AGM_I_PMC_Boat_Transport_01_F

  AGM_I_FieldPack_blk_AT
  AGM_I_FieldPack_blk_Medic
  AGM_I_TacticalPack_blk_Ammo
  AGM_I_TacticalPack_blk_Eng
  AGM_I_TacticalPack_blk_Exp

    CfgWeapons
  AGM_arifle_MX_Black_pointer_F
  AGM_arifle_MX_Black_Holo_pointer_F
  AGM_arifle_MX_Black_Hamr_pointer_F
  AGM_arifle_MX_Black_ACO_pointer_F
  AGM_arifle_MX_Black_ACO_F
  AGM_arifle_MX_Black_ACO_pointer_snds_F
  AGM_arifle_MX_Black_RCO_pointer_snds_F

  AGM_arifle_MX_GL_Black_ACO_F
  AGM_arifle_MX_GL_Black_ACO_pointer_F
  AGM_arifle_MX_GL_Black_Hamr_pointer_F
  AGM_arifle_MX_GL_Black_Holo_pointer_snds_F

  AGM_arifle_MXC_Black_Holo_F
  AGM_arifle_MXC_Black_Holo_pointer_F
  AGM_arifle_MXC_Black_ACO_F
  AGM_arifle_MXC_Black_Holo_pointer_snds_F
  AGM_arifle_MXC_Black_SOS_point_snds_F
  AGM_arifle_MXC_Black_ACO_pointer_snds_F
  AGM_arifle_MXC_Black_ACO_pointer_F

  AGM_arifle_MX_SW_Black_pointer_F
  AGM_arifle_MX_SW_Black_Hamr_pointer_F

  AGM_arifle_MXM_Black_Hamr_pointer_F
  AGM_arifle_MXM_Black_SOS_pointer_F
  AGM_arifle_MXM_Black_RCO_pointer_snds_F
  AGM_arifle_MXM_Black_DMS_F
*/

class CfgPatches {
  class AGM_PMC {
    units[] = {
      "AGM_I_PMC_Security_Contractor_F",
      "AGM_I_PMC_Security_Contractor_lite_F",
      "AGM_I_PMC_Squad_Coordinator_F",
      "AGM_I_PMC_Team_Coordinator_F",
      "AGM_I_PMC_Tactical_Specialist_AR_F",
      "AGM_I_PMC_Field_Medic_F",
      "AGM_I_PMC_Field_Technician_F",
      "AGM_I_PMC_Field_Specialist_exp_F",
      "AGM_I_PMC_Security_Contractor_GL_F",
      "AGM_I_PMC_Defensive_Marksman_F",
      "AGM_I_PMC_Field_Specialist_AT_F",
      "AGM_I_PMC_SUV_01_F",
      "AGM_I_PMC_Quadbike_01_F",
      "AGM_I_PMC_Heli_Light_01_F",
      "AGM_I_PMC_Boat_Transport_01_F",
      "AGM_I_PMC_Tactical_Driver",
      "AGM_I_PMC_Tactical_Pilot"
    };
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.95";
    versionStr = "0.95";
    versionAr[] = {0,95,0};
    author[] = {"commy2", "Kickapoo"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFactionClasses {
  class AGM_I_PMC_F {
    icon = "\A3\Data_F\Flags\flag_ion_CO.paa";
    displayName = "$STR_AGM_PMC_Faction";
    priority = 3;
    side = 2;
  };
};

class CfgWeapons {
  class arifle_MX_Black_F;
  class arifle_MXC_Black_F;
  class arifle_MX_GL_Black_F;
  class arifle_MX_SW_Black_F;
  class arifle_MXM_Black_F;

  class AGM_arifle_MX_Black_pointer_F: arifle_MX_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_pointer_F";
    class LinkedItems {
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MX_Black_Holo_pointer_F: arifle_MX_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_Holo_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Holosight";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MX_Black_Hamr_pointer_F: arifle_MX_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_Hamr_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Hamr";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MX_Black_ACO_pointer_F: arifle_MX_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_ACO_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ACO";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MX_Black_ACO_F: arifle_MX_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_ACO_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ACO";
      };
    };
  };
  class AGM_arifle_MX_GL_Black_ACO_F: arifle_MX_GL_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_GL_ACO_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ACO";
      };
    };
  };
  class AGM_arifle_MX_GL_Black_ACO_pointer_F: arifle_MX_GL_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_GL_ACO_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ACO";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MX_GL_Black_Hamr_pointer_F: arifle_MX_GL_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_GL_Hamr_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Hamr";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MXC_Black_Holo_F: arifle_MXC_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXC_Holo_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Holosight";
      };
    };
  };
  class AGM_arifle_MXC_Black_Holo_pointer_F: arifle_MXC_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXC_Holo_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Holosight";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MX_SW_Black_pointer_F: arifle_MX_SW_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_SW_pointer_F";
    class LinkedItems {
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MX_SW_Black_Hamr_pointer_F: arifle_MX_SW_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_SW_Hamr_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Hamr";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MXM_Black_Hamr_pointer_F: arifle_MXM_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXM_Hamr_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Hamr";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MXC_Black_ACO_F: arifle_MXC_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXC_ACO_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ACO";
      };
    };
  };
  class AGM_arifle_MXC_Black_Holo_pointer_snds_F: arifle_MXC_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXC_Holo_pointer_snds_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Holosight";
      };
      class LinkedItemsMuzzle {
        slot = "MuzzleSlot";
        item = "muzzle_snds_H";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MXC_Black_SOS_point_snds_F: arifle_MXC_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXC_SOS_point_snds_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_SOS";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
      class LinkedItemsMuzzle {
        slot = "MuzzleSlot";
        item = "muzzle_snds_H";
      };
    };
  };
  class AGM_arifle_MXC_Black_ACO_pointer_snds_F: arifle_MXC_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXC_ACO_pointer_snds_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ACO";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
      class LinkedItemsMuzzle {
        slot = "MuzzleSlot";
        item = "muzzle_snds_H";
      };
    };
  };
  class AGM_arifle_MXC_Black_ACO_pointer_F: arifle_MXC_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXC_ACO_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ACO";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MX_Black_ACO_pointer_snds_F: arifle_MX_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_ACO_pointer_snds_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ACO";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
      class LinkedItemsMuzzle {
        slot = "MuzzleSlot";
        item = "muzzle_snds_H";
      };
    };
  };
  class AGM_arifle_MX_Black_RCO_pointer_snds_F: arifle_MX_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_RCO_pointer_snds_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ARCO";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
      class LinkedItemsMuzzle {
        slot = "MuzzleSlot";
        item = "muzzle_snds_H";
      };
    };
  };
  class AGM_arifle_MX_GL_Black_Holo_pointer_snds_F: arifle_MX_GL_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MX_GL_Holo_pointer_snds_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_Holosight";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
      class LinkedItemsMuzzle {
        slot = "MuzzleSlot";
        item = "muzzle_snds_H";
      };
    };
  };
  class AGM_arifle_MXM_Black_SOS_pointer_F: arifle_MXM_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXM_SOS_pointer_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_SOS";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
    };
  };
  class AGM_arifle_MXM_Black_RCO_pointer_snds_F: arifle_MXM_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXM_RCO_pointer_snds_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_ARCO";
      };
      class LinkedItemsAcc {
        slot = "PointerSlot";
        item = "acc_pointer_IR";
      };
      class LinkedItemsMuzzle {
        slot = "MuzzleSlot";
        item = "muzzle_snds_H";
      };
    };
  };
  class AGM_arifle_MXM_Black_DMS_F: arifle_MXM_Black_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "arifle_MXM_DMS_F";
    class LinkedItems {
      class LinkedItemsOptic {
        slot = "CowsSlot";
        item = "optic_DMS";
      };
    };
  };
};

class UniformSlotInfo;
class CfgVehicles {
  class B_FieldPack_blk;
  class AGM_I_FieldPack_blk_AT: B_FieldPack_blk {
    scope = 1;

    class TransportMagazines {
      class _xx_Titan_AT {
        magazine = "Titan_AT";
        count = 2;
      };
    };
  };

  class AGM_I_FieldPack_blk_Medic: B_FieldPack_blk {
    scope = 1;

    class TransportItems {
      class _xx_Medikit {
        name = "Medikit";
        count = 1;
      };
      class _xx_FirstAidKit {
        name = "FirstAidKit";
        count = 10;
      };
    };
  };

  class B_TacticalPack_blk;
  class AGM_I_TacticalPack_blk_Ammo: B_TacticalPack_blk {
    scope = 1;

    class TransportMagazines {
      class _xx_30Rnd_65x39_caseless_mag {
        magazine = "30Rnd_65x39_caseless_mag";
        count = 12;
      };
      class _xx_100Rnd_65x39_caseless_mag {
        magazine = "100Rnd_65x39_caseless_mag";
        count = 1;
      };
      class _xx_HandGrenade {
        magazine = "HandGrenade";
        count = 2;
      };
      class _xx_MiniGrenade {
        magazine = "MiniGrenade";
        count = 2;
      };
      class _xx_SmokeShell {
        magazine = "SmokeShell";
        count = 2;
      };
      class _xx_SmokeShellBlue {
        magazine = "SmokeShellBlue";
        count = 2;
      };
      class _xx_SmokeShellRed {
        magazine = "SmokeShellRed";
        count = 2;
      };
      class _xx_SmokeShellOrange {
        magazine = "SmokeShellOrange";
        count = 2;
      };
      class _xx_Chemlight_blue {
        magazine = "Chemlight_blue";
        count = 2;
      };
    };

    class TransportItems {
      class _xx_FirstAidKit {
        name = "FirstAidKit";
        count = 4;
      };
    };
  };

  class AGM_I_TacticalPack_blk_Eng: B_TacticalPack_blk {
    scope = 1;

    class TransportMagazines {
      class _xx_SatchelCharge_Remote_Mag {
        magazine = "SatchelCharge_Remote_Mag";
        count = 1;
      };
      class _xx_DemoCharge_Remote_Mag {
        magazine = "DemoCharge_Remote_Mag";
        count = 2;
      };
    };

    class TransportItems {
      class _xx_ToolKit {
        name = "ToolKit";
        count = 1;
      };
      class _xx_MineDetector {
        name = "MineDetector";
        count = 1;
      };
    };
  };

  class AGM_I_TacticalPack_blk_Exp: B_TacticalPack_blk {
    scope = 1;

    class TransportMagazines {
      class _xx_APERSBoundingMine_Range_Mag {
        magazine = "APERSBoundingMine_Range_Mag";
        count = 3;
      };
      class _xx_ClaymoreDirectionalMine_Remote_Mag {
        magazine = "ClaymoreDirectionalMine_Remote_Mag";
        count = 2;
      };
      class _xx_SLAMDirectionalMine_Wire_Mag {
        magazine = "SLAMDirectionalMine_Wire_Mag";
        count = 2;
      };
      class _xx_DemoCharge_Remote_Mag {
        magazine = "DemoCharge_Remote_Mag";
        count = 1;
      };
    };

    class TransportItems {
      class _xx_ToolKit {
        name = "ToolKit";
        count = 0;
      };
      class _xx_MineDetector {
        name = "MineDetector";
        count = 1;
      };
    };
  };

  class Man;
  class CAManBase: Man {
    class HeadLimits;
    class HitPoints;
  };

  class SoldierGB: CAManBase {
    class HeadLimits: HeadLimits {};
    class Wounds;
  };

  class AGM_I_PMC_Security_Contractor_base_F: SoldierGB {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Security_Contractor_base_F";
    expansion = 1;
    identityTypes[] = {"LanguageENG_F", "Head_NATO", "G_NATO_default"};
    faceType = "Man_A3";
    side = 2;
    faction = "AGM_I_PMC_F";
    genericNames = "NATOMen";
    vehicleClass = "Men";
    portrait = "";
    picture = "";
    icon = "iconMan";
    accuracy = 3.9;
    sensitivity = 2;
    threat[] = {1,0.1,0.1};
    camouflage = 1.1;
    minFireTime = 10;
    cost = 100000;
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    modelSides[] = {0,1,2,3};//
    nakedUniform = "U_BasicBody";
    uniformClass = "U_IG_Guerilla2_3";
    canCarryBackPack = 1;
    scope = 0;
    scopeCurator = 0;

    class Wounds {
      tex[] = {};
      mat[] = {"A3\Characters_F\Civil\Data\c_cloth1.rvmat","A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth2.rvmat","A3\Characters_F\Civil\Data\c_cloth2_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth2_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth3.rvmat","A3\Characters_F\Civil\Data\c_cloth3_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth3_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth4.rvmat","A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat","A3\characters_f\civil\data\c_poloshirt.rvmat","A3\Characters_F\Civil\Data\c_poloshirt_injury.rvmat","A3\Characters_F\Civil\Data\c_poloshirt_injury.rvmat","A3\characters_f\common\data\coveralls.rvmat","A3\Characters_F\Common\Data\coveralls_injury.rvmat","A3\Characters_F\Common\Data\coveralls_injury.rvmat","A3\Characters_F\Civil\Data\hunter.rvmat","A3\Characters_F\Civil\Data\hunter_injury.rvmat","A3\Characters_F\Civil\Data\hunter_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"};
    };

    hiddenSelections[] = {"Camo","insignia"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_3_co.paa"};

    class EventHandlers;

    items[] = {"FirstAidKit"};
    respawnitems[] = {"FirstAidKit"};
    weapons[] = {"AGM_arifle_MX_Black_Hamr_pointer_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MX_Black_Hamr_pointer_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_PlateCarrier1_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_PlateCarrier1_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class AGM_I_PMC_Security_Contractor_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Security_Contractor_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Security_Contractor";
  };

  class AGM_I_PMC_Security_Contractor_lite_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "I_Soldier_lite_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Security_Contractor_lite";
    cost = 90000;
    camouflage = 1.2;
    weapons[] = {"AGM_arifle_MXC_Black_ACO_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MXC_Black_ACO_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_BandollierB_blk","H_MilCap_gry","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_BandollierB_blk","H_MilCap_gry","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_1";
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_1_co.paa"};
  };

  class AGM_I_PMC_Squad_Coordinator_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Squad_Coordinator_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Squad_Coordinator";
    cost = 500000;
    camouflage = 1.6;
    sensitivity = 3.2;
    icon = "iconManLeader";
    weapons[] = {"AGM_arifle_MXC_Black_ACO_pointer_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put","Binocular"};
    respawnWeapons[] = {"AGM_arifle_MXC_Black_ACO_pointer_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put","Binocular"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag_Tracer","30Rnd_65x39_caseless_mag_Tracer","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","SmokeShellRed","SmokeShellOrange","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag_Tracer","30Rnd_65x39_caseless_mag_Tracer","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","SmokeShellRed","SmokeShellOrange","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_TacVest_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_TacVest_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_1";
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_1_co.paa"};
  };

  class AGM_I_PMC_Team_Coordinator_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Team_Coordinator_F";
    scope = 2;
    scopeCurator = 2;
    cost = 450000;
    sensitivity = 3.2;
    threat[] = {1,0.3,0.1};
    icon = "iconManLeader";
    displayName = "$STR_AGM_PMC_Team_Coordinator";
    weapons[] = {"AGM_arifle_MX_GL_Black_ACO_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MX_GL_Black_ACO_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag_Tracer","30Rnd_65x39_caseless_mag_Tracer","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","HandGrenade","MiniGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell"};
    respawnmagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag_Tracer","30Rnd_65x39_caseless_mag_Tracer","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","HandGrenade","MiniGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell"};
    linkedItems[] = {"V_TacVest_blk","H_Booniehat_khk_hs","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_TacVest_blk","H_Booniehat_khk_hs","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_1";
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_1_co.paa"};
  };

  class AGM_I_PMC_Tactical_Specialist_AR_F: AGM_I_PMC_Security_Contractor_base_F {
    class SpeechVariants {
      class Default {
        speechSingular[] = {"veh_infantry_MG_s"};
        speechPlural[] = {"veh_infantry_MG_p"};
      };
    };

    textSingular = "$STR_A3_nameSound_veh_infantry_MG_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_MG_p";
    nameSound = "veh_infantry_MG_s";
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Tactical_Specialist_AR_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Tactical_Specialist_AR";
    weapons[] = {"AGM_arifle_MX_SW_Black_Hamr_pointer_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MX_SW_Black_Hamr_pointer_F","Throw","Put"};
    magazines[] = {"100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","100Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    cost = 40000;
    icon = "iconManMG";
    linkedItems[] = {"V_PlateCarrier1_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_PlateCarrier1_blk","H_Cap_blk_ION","D efaultManGuerillaLinkedItems"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_1";
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_1_co.paa"};
  };

  class AGM_I_PMC_Field_Medic_F: AGM_I_PMC_Security_Contractor_base_F {
    class SpeechVariants {
      class Default {
        speechSingular[] = {"veh_infantry_medic_s"};
        speechPlural[] = {"veh_infantry_medic_p"};
      };
    };

    textSingular = "$STR_A3_nameSound_veh_infantry_medic_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_medic_p";
    nameSound = "veh_infantry_medic_s";
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Field_Medic_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Field_Medic";
    backpack = "AGM_I_FieldPack_blk_Medic";
    weapons[] = {"AGM_arifle_MX_Black_ACO_pointer_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MX_Black_ACO_pointer_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","MiniGrenade","SmokeShell","SmokeShellBlue","SmokeShellRed","SmokeShellOrange","Chemlight_blue","Chemlight_blue"};
    respawnmagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","MiniGrenade","SmokeShell","SmokeShellBlue","SmokeShellRed","SmokeShellOrange","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_TacVestIR_blk","H_Booniehat_khk_hs","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_TacVestIR_blk","H_Booniehat_khk_hs","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    attendant = 1;
    icon = "iconManMedic";
    picture = "pictureHeal";
    model = "\A3\Characters_F\Civil\c_poloshirtpants.p3d";
    uniformClass = "U_Competitor";
    hiddenSelections[] = {"camo","insignia"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Beta\Civil\Data\c_competitor_co.paa"};
    cost = 300000;
  };

  class AGM_I_PMC_Field_Technician_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Field_Technician_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Field_Technician";
    backpack = "AGM_I_TacticalPack_blk_Eng";
    canDeactivateMines = 1;
    engineer = 1;
    detectSkill = 70;
    weapons[] = {"AGM_arifle_MXC_Black_ACO_pointer_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MXC_Black_ACO_pointer_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","MiniGrenade","SmokeShell","SmokeShellBlue","SmokeShellRed","SmokeShellOrange","Chemlight_blue","Chemlight_blue"};
    respawnmagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","MiniGrenade","SmokeShell","SmokeShellBlue","SmokeShellRed","SmokeShellOrange","Chemlight_blue","Chemlight_blue"};
    cost = 220000;
    linkedItems[] = {"V_Chestrig_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_Chestrig_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    icon = "iconManEngineer";
    picture = "pictureRepair";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_1";
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_1_co.paa"};
  };

  class AGM_I_PMC_Field_Specialist_exp_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "I_Soldier_exp_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Field_Specialist_exp";
    cost = 115000;
    camouflage = 1.6;
    sensitivity = 2.8;
    backpack = "AGM_I_TacticalPack_blk_Exp";
    weapons[] = {"AGM_arifle_MX_Black_ACO_pointer_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MX_Black_ACO_pointer_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","APERSMine_Range_Mag","APERSMine_Range_Mag","APERSMine_Range_Mag","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","APERSMine_Range_Mag","APERSMine_Range_Mag","APERSMine_Range_Mag","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    canDeactivateMines = 1;
    detectSkill = 80;
    threat[] = {1,0.5,0.1};
    linkedItems[] = {"V_PlateCarrier1_blk","H_Booniehat_khk_hs","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_PlateCarrier1_blk","H_Booniehat_khk_hs","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    icon = "iconManExplosive";
    picture = "pictureExplosive";
    model = "\A3\Characters_F\Civil\c_poloshirtpants.p3d";
    uniformClass = "U_Competitor";
    hiddenSelections[] = {"camo","insignia"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Beta\Civil\Data\c_competitor_co.paa"};
  };

  class AGM_I_PMC_Security_Contractor_GL_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Security_Contractor_GL_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Security_Contractor_GL";
    weapons[] = {"AGM_arifle_MX_GL_Black_Hamr_pointer_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MX_GL_Black_Hamr_pointer_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell"};
    cost = 130000;
    linkedItems[] = {"V_TacVest_blk","H_Watchcap_camo","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_TacVest_blk","H_Watchcap_camo","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class AGM_I_PMC_Defensive_Marksman_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Defensive_Marksman_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Defensive_Marksman";
    weapons[] = {"AGM_arifle_MXM_Black_SOS_pointer_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MXM_Black_SOS_pointer_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    cost = 150000;
    linkedItems[] = {"V_PlateCarrier1_blk","H_Watchcap_camo","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_PlateCarrier1_blk","H_Watchcap_camo","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class AGM_I_PMC_Field_Specialist_AT_F: AGM_I_PMC_Security_Contractor_base_F {
    class SpeechVariants {
      class Default {
        speechSingular[] = {"veh_infantry_AT_s"};
        speechPlural[] = {"veh_infantry_AT_p"};
      };
    };

    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Field_Specialist_AT_F";
    scope = 2;
    scopeCurator = 2;
    displayName = "$STR_AGM_PMC_Field_Specialist_AT";
    backpack = "AGM_I_FieldPack_blk_AT";
    weapons[] = {"AGM_arifle_MX_Black_Hamr_pointer_F","launch_I_Titan_short_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MX_Black_Hamr_pointer_F","launch_I_Titan_short_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","RPG32_F","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnmagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","RPG32_F","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    icon = "iconManAT";
    linkedItems[] = {"V_PlateCarrier1_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_PlateCarrier1_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class AGM_I_PMC_Soldier_A_F: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Soldier_A_F";
    scope = 0;
    scopeCurator = 0;
    displayName = "$STR_AGM_PMC_Soldier_ammo";
    cost = 50000;
    backpack = "AGM_I_TacticalPack_blk_Ammo";
    weapons[] = {"AGM_arifle_MX_Black_ACO_pointer_F","Throw","Put"};
    respawnWeapons[] = {"AGM_arifle_MX_Black_ACO_pointer_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnmagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_PlateCarrier1_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_PlateCarrier1_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class AGM_I_PMC_officer_F: AGM_I_PMC_Security_Contractor_base_F {
    class SpeechVariants {
      class Default {
        speechSingular[] = {"veh_infantry_officer_s"};
        speechPlural[] = {"veh_infantry_officer_p"};
      };
    };

    textSingular = "$STR_A3_nameSound_veh_infantry_officer_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_officer_p";
    nameSound = "veh_infantry_officer_s";
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_officer_F";

    class Wounds {
      tex[] = {};
      mat[] = {"A3\Characters_F_Beta\INDEP\Data\officer.rvmat","A3\Characters_F_Beta\INDEP\Data\officer_injury.rvmat","A3\Characters_F_Beta\INDEP\Data\officer_injury.rvmat"};
    };

    cost = 600000;
    camouflage = 1.6;
    sensitivity = 3;
    icon = "iconManOfficer";
    scope = 0;
    scopeCurator = 0;
    displayName = "$STR_AGM_PMC_Soldier_Officer";
    weapons[] = {"AGM_arifle_MX_Black_pointer_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    respawnweapons[] = {"AGM_arifle_MX_Black_pointer_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","SmokeShell","SmokeShellBlue","SmokeShellRed","SmokeShellOrange","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","SmokeShell","SmokeShellBlue","SmokeShellRed","SmokeShellOrange","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_BandollierB_blk","H_MilCap_gry","ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_BandollierB_blk","H_MilCap_gry","ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class AGM_I_PMC_Tactical_Driver: AGM_I_PMC_Security_Contractor_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Tactical_Driver";
    class UniformInfo {
      class SlotsInfo {
        class Googles: UniformSlotInfo {
          slotType = 603;
        };
        class Headgear: UniformSlotInfo {
          slotType = 605;
        };
      };
    };

    scope = 2;
    displayName = "$STR_AGM_PMC_Tactical_Driver";
    weapons[] = {"arifle_MXC_black_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    respawnWeapons[] = {"arifle_MXC_black_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","HandGrenade","HandGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","HandGrenade","HandGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    cost = 90000;
    camouflage = 1.6;
    sensitivity = 2.5;
    linkedItems[] = {"V_BandollierB_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_BandollierB_blk","H_Cap_blk_ION","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class AGM_I_PMC_Tactical_Pilot: AGM_I_PMC_Security_Contractor_base_F {
    class SpeechVariants {
      class Default {
        speechSingular[] = {"veh_infantry_pilot_s"};
        speechPlural[] = {"veh_infantry_pilot_p"};
      };
    };

    textSingular = "$STR_A3_nameSound_veh_infantry_pilot_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_pilot_p";
    nameSound = "veh_infantry_pilot_s";
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Tactical_Pilot";
    scope = 2;
    displayName = "$STR_AGM_PMC_Tactical_Pilot";
    weapons[] = {"arifle_MXC_black_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    respawnWeapons[] = {"arifle_MXC_black_F","hgun_Pistol_heavy_01_MRD_F","Throw","Put"};
    magazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","HandGrenade","HandGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","11Rnd_45ACP_Mag","HandGrenade","HandGrenade","SmokeShell","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_BandollierB_blk","H_PilotHelmetHeli_B","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_BandollierB_blk","H_PilotHelmetHeli_B","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class SUV_01_base_F;
  class AGM_I_PMC_SUV_01_F: SUV_01_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_SUV_01_F";
    scope = 2;
    crew = "AGM_I_PMC_Tactical_Driver";
    typicalCargo[] = {"AGM_I_PMC_Security_Contractor_F"};
    side = 2;
    displayName = "$STR_AGM_PMC_Vehicle_SUV";
    faction = "AGM_I_PMC_F";
    accuracy = 1.25;
    hiddenSelectionsTextures[] = {"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_02_CO.paa"};
    class TransportMagazines {
      class _xx_30Rnd_65x39_caseless_mag {
        magazine = "30Rnd_65x39_caseless_mag";
        count = 12;
      };
      class _xx_100Rnd_65x39_caseless_mag {
        magazine = "100Rnd_65x39_caseless_mag";
        count = 6;
      };
      class _xx_HandGrenade {
        magazine = "HandGrenade";
        count = 10;
      };
      class _xx_1Rnd_HE_Grenade_shell {
        magazine = "1Rnd_HE_Grenade_shell";
        count = 6;
      };
      class _xx_1Rnd_Smoke_Grenade_shell {
        magazine = "1Rnd_Smoke_Grenade_shell";
        count = 3;
      };
      class _xx_1Rnd_SmokeBlue_Grenade_shell {
        magazine = "1Rnd_SmokeBlue_Grenade_shell";
        count = 3;
      };
      class _xx_1Rnd_SmokeRed_Grenade_shell {
        magazine = "1Rnd_SmokeRed_Grenade_shell";
        count = 3;
      };
      class _xx_1Rnd_SmokeOrange_Grenade_shell {
        magazine = "1Rnd_SmokeOrange_Grenade_shell";
        count = 3;
      };
      class _xx_SmokeShell {
        magazine = "SmokeShell";
        count = 8;
      };
      class _xx_SmokeShellBlue {
        magazine = "SmokeShellBlue";
        count = 8;
      };
      class _xx_SmokeShellRed {
        magazine = "SmokeShellRed";
        count = 8;
      };
      class _xx_SmokeShellOrange {
        magazine = "SmokeShellOrange";
        count = 8;
      };
      class _xx_Titan_AT {
        magazine = "Titan_AT";
        count = 2;
      };
    };
    class TransportItems {
      class _xx_FirstAidKit {
        name = "FirstAidKit";
        count = 10;
      };
    };
    class TransportWeapons {
      class _xx_arifle_MXC_Black_F {
        weapon = "arifle_MXC_Black_F";
        count = 2;
      };
    };
  };

  class Quadbike_01_base_F;
  class AGM_I_PMC_Quadbike_01_F: Quadbike_01_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Quadbike_01_F";
    scope = 2;
    side = 2;
    faction = "AGM_I_PMC_F";
    crew = "AGM_I_PMC_Tactical_Driver";
    typicalCargo[] = {"AGM_I_PMC_Security_Contractor_F"};
    hiddenSelectionsTextures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLACK_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLACK_CO.paa"};
  };

  class B_Heli_Light_01_F;
  class AGM_I_PMC_Heli_Light_01_F: B_Heli_Light_01_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Heli_Light_01_F";
    scope = 2;
    accuracy = 1;
    side = 2;
    faction = "AGM_I_PMC_F";
    crew = "AGM_I_PMC_Tactical_Pilot";
    hiddenSelectionsTextures[] = {"\A3\Air_F\Heli_Light_01\Data\Skins\Heli_Light_01_ext_wasp_co.paa"};
    class TransportBackpacks {
      /*class _xx_B_Parachute {
        backpack = "B_Parachute";
        count = 4;
      };*/
    };
    class TransportMagazines {
      class _xx_30Rnd_65x39_caseless_mag {
        magazine = "30Rnd_65x39_caseless_mag";
        count = 12;
      };
      class _xx_100Rnd_65x39_caseless_mag {
        magazine = "100Rnd_65x39_caseless_mag";
        count = 6;
      };
      class _xx_HandGrenade {
        magazine = "HandGrenade";
        count = 10;
      };
      class _xx_1Rnd_HE_Grenade_shell {
        magazine = "1Rnd_HE_Grenade_shell";
        count = 6;
      };
      class _xx_1Rnd_Smoke_Grenade_shell {
        magazine = "1Rnd_Smoke_Grenade_shell";
        count = 3;
      };
      class _xx_1Rnd_SmokeBlue_Grenade_shell {
        magazine = "1Rnd_SmokeBlue_Grenade_shell";
        count = 3;
      };
      class _xx_1Rnd_SmokeRed_Grenade_shell {
        magazine = "1Rnd_SmokeRed_Grenade_shell";
        count = 3;
      };
      class _xx_1Rnd_SmokeOrange_Grenade_shell {
        magazine = "1Rnd_SmokeOrange_Grenade_shell";
        count = 3;
      };
      class _xx_SmokeShell {
        magazine = "SmokeShell";
        count = 8;
      };
      class _xx_SmokeShellBlue {
        magazine = "SmokeShellBlue";
        count = 8;
      };
      class _xx_SmokeShellRed {
        magazine = "SmokeShellRed";
        count = 8;
      };
      class _xx_SmokeShellOrange {
        magazine = "SmokeShellOrange";
        count = 8;
      };
      class _xx_Titan_AT {
        magazine = "Titan_AT";
        count = 2;
      };
    };
    class TransportItems {
      class _xx_FirstAidKit {
        name = "FirstAidKit";
        count = 10;
      };
    };
    class TransportWeapons {
      class _xx_arifle_MXC_Black_F {
        weapon = "arifle_MXC_Black_F";
        count = 2;
      };
    };
  };

  class Rubber_duck_base_F;
  class AGM_I_PMC_Boat_Transport_01_F: Rubber_duck_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_I_PMC_Boat_Transport_01_F";
    scope = 2;
    crew = "AGM_I_PMC_Tactical_Driver";
    faction = "AGM_I_PMC_F";
    side = 2;
    typicalCargo[] = {"AGM_I_PMC_Security_Contractor_F","AGM_I_PMC_Security_Contractor_F"};
  };
};

class CfgGroups {
  class Indep {
    class AGM_PMC {
      name = "$STR_AGM_PMC_Groups";
      class Infantry {
        name = "$STR_AGM_PMC_Infantry";
        class AGM_PMC_InfSquad {
          name = "$STR_AGM_PMC_InfSquad";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Squad_Coordinator_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Team_Coordinator_F";
            rank = "SERGEANT";
            position[] = {5,-5,0};
          };
          class Unit2 {
            side = 2;
            vehicle = "AGM_I_PMC_Tactical_Specialist_AR_F";
            rank = "CORPORAL";
            position[] = {-5,-5,0};
          };
          class Unit3 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_GL_F";
            rank = "PRIVATE";
            position[] = {10,-10,0};
          };
          class Unit4 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "PRIVATE";
            position[] = {-10,-10,0};
          };
          class Unit5 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Medic_F";
            rank = "CORPORAL";
            position[] = {15,-15,0};
          };
          class Unit6 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "PRIVATE";
            position[] = {-15,-15,0};
          };
          class Unit7 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "PRIVATE";
            position[] = {20,-20,0};
          };
        };

        class AGM_PMC_InfSquad_Weapons {
          name = "$STR_AGM_PMC_InfSquad_Weapons";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Squad_Coordinator_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Defensive_Marksman_F";
            rank = "SERGEANT";
            position[] = {5,-5,0};
          };
          class Unit2 {
            side = 2;
            vehicle = "AGM_I_PMC_Tactical_Specialist_AR_F";
            rank = "CORPORAL";
            position[] = {-5,-5,0};
          };
          class Unit3 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_GL_F";
            rank = "SERGEANT";
            position[] = {10,-10,0};
          };
          class Unit4 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Specialist_AT_F";
            rank = "CORPORAL";
            position[] = {-10,-10,0};
          };
          class Unit6 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "PRIVATE";
            position[] = {15,-15,0};
          };
          class Unit5 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "PRIVATE";
            position[] = {-15,-15,0};
          };
          class Unit7 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Medic_F";
            rank = "PRIVATE";
            position[] = {20,-20,0};
          };
        };

        class AGM_PMC_InfTeam {
          name = "$STR_AGM_PMC_InfTeam";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Team_Coordinator_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Tactical_Specialist_AR_F";
            rank = "CORPORAL";
            position[] = {5,-5,0};
          };
          class Unit2 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_GL_F";
            rank = "PRIVATE";
            position[] = {-5,-5,0};
          };
          class Unit3 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "PRIVATE";
            position[] = {10,-10,0};
          };
        };

        class AGM_PMC_InfTeam_AT {
          name = "$STR_AGM_PMC_InfTeam_AT";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Team_Coordinator_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Specialist_AT_F";
            rank = "CORPORAL";
            position[] = {5,-5,0};
          };
          class Unit2 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Specialist_AT_F";
            rank = "PRIVATE";
            position[] = {-5,-5,0};
          };
          class Unit3 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "PRIVATE";
            position[] = {10,-10,0};
          };
        };

        class AGM_PMC_ReconTeam {
          name = "$STR_AGM_PMC_ReconTeam";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "CORPORAL";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "PRIVATE";
            position[] = {5,-5,0};
          };
        };

        class AGM_PMC_SniperTeam {
          name = "$STR_AGM_PMC_SniperTeam";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Defensive_Marksman_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "CORPORAL";
            position[] = {5,-5,0};
          };
        };
      };

      class Support {
        name = "$STR_AGM_PMC_Support";
        class AGM_PMC_Support_CLS {
          name = "$STR_AGM_PMC_Support_CLS";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Team_Coordinator_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Tactical_Specialist_AR_F";
            rank = "CORPORAL";
            position[] = {5,-5,0};
          };
          class Unit2 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Medic_F";
            rank = "PRIVATE";
            position[] = {-5,-5,0};
          };
          class Unit3 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Medic_F";
            rank = "PRIVATE";
            position[] = {10,-10,0};
          };
        };

        class AGM_PMC_Support_EOD {
          name = "$STR_AGM_PMC_Support_EOD";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Team_Coordinator_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Specialist_exp_F";
            rank = "CORPORAL";
            position[] = {5,-5,0};
          };
          class Unit2 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Specialist_exp_F";
            rank = "PRIVATE";
            position[] = {-5,-5,0};
          };
          class Unit3 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Specialist_exp_F";
            rank = "PRIVATE";
            position[] = {10,-10,0};
          };
        };

        class AGM_PMC_Support_ENG {
          name = "$STR_AGM_PMC_Support_ENG";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_Team_Coordinator_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "CORPORAL";
            position[] = {5,-5,0};
          };
          class Unit2 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Technician_F";
            rank = "PRIVATE";
            position[] = {-5,-5,0};
          };
          class Unit3 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Technician_F";
            rank = "PRIVATE";
            position[] = {10,-10,0};
          };
        };
      };

      class Motorized_MTP {
        name = "$STR_AGM_PMC_Motorized_MTP";
        class IRG_MotInf_Team {
          name = "$STR_AGM_PMC_Motorized_MTP_MotInfTeam";
          side = 2;
          faction = "AGM_I_PMC_F";
          class Unit0 {
            side = 2;
            vehicle = "AGM_I_PMC_SUV_01_F";
            rank = "SERGEANT";
            position[] = {0,0,0};
          };
          class Unit1 {
            side = 2;
            vehicle = "AGM_I_PMC_Team_Coordinator_F";
            rank = "SERGEANT";
            position[] = {13,-12,0};
          };
          class Unit2 {
            side = 2;
            vehicle = "AGM_I_PMC_Tactical_Specialist_AR_F";
            rank = "CORPORAL";
            position[] = {-5,-5,0};
          };
          class Unit3 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F"; //"AGM_I_PMC_Field_Specialist_AT_F";
            rank = "CORPORAL";
            position[] = {25,-25,2};
          };
          /*class Unit4 {
            side = 2;
            vehicle = "AGM_I_PMC_Field_Medic_F";
            rank = "CORPORAL";
            position[] = {-10,-10,0};
          };
          class Unit5 {
            side = 2;
            vehicle = "AGM_I_PMC_Security_Contractor_F";
            rank = "CORPORAL";
            position[] = {30,-30,1};
          };*/
        };
      };
    };
  };
};
