
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
  class AGM_O_Separatists_F {
    icon = "\A3\Data_F\Flags\Flag_Altis_CO.paa";
    displayName = "$STR_AGM_Seperatists_Faction";
    priority = 3;
    side = 0;
  };
};

class UniformSlotInfo;//
class CfgVehicles {
  /*class B_FieldPack_blk;
  class AGM_I_FieldPack_blk_AT: B_FieldPack_blk {
    scope = 2;

    class TransportMagazines {
      class _xx_Titan_AT {
        magazine = "Titan_AT";
        count = 2;
      };
    };
  };

  class AGM_I_FieldPack_blk_Medic: B_FieldPack_blk {
    scope = 2;

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
    scope = 2;

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
    scope = 2;

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
    scope = 2;

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
  };*/

  class Land;
  class Man: Land {
    class Eventhandlers;
  };

  class CAManBase: Man {
    class HeadLimits;
    class HitPoints;
  };

  class SoldierGB: CAManBase {
    class HeadLimits: HeadLimits {};
    class Wounds;
  };

  /*
    arifle_Mk20_plain_F
    arifle_Mk20C_plain_F
    arifle_Mk20_GL_plain_F

    arifle_Mk20_MRCO_plain_F
  */

    /*
rif at, marksman, engineer

    model = "\A3\characters_F\civil\c_hunter_f";
    uniformClass = "U_C_HunterBody_grn";
    hiddenSelections[] = {"insignia"};
    */

  class AGM_O_G_Soldier_base_F: SoldierGB {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_Soldier_base_F";
    expansion = 1;
    identityTypes[] = {"LanguageGRE_F","Head_Greek","G_GUERIL_default"};
    faceType = "Man_A3";
    side = 0;
    faction = "AGM_O_Separatists_F";
    genericNames = "GreekMen";
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
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla1_1.p3d";
    modelSides[] = {2,3};
    nakedUniform = "U_BasicBody";
    uniformClass = "U_IG_Guerilla1_1";
    canCarryBackPack = 1;
    scope = 0;
    scopeCurator = 0;

    class Wounds {
      tex[] = {};
      mat[] = {"A3\Characters_F\Civil\Data\c_cloth1.rvmat","A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth2.rvmat","A3\Characters_F\Civil\Data\c_cloth2_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth2_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth3.rvmat","A3\Characters_F\Civil\Data\c_cloth3_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth3_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth4.rvmat","A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat","A3\characters_f\civil\data\c_poloshirt.rvmat","A3\Characters_F\Civil\Data\c_poloshirt_injury.rvmat","A3\Characters_F\Civil\Data\c_poloshirt_injury.rvmat","A3\characters_f\common\data\coveralls.rvmat","A3\Characters_F\Common\Data\coveralls_injury.rvmat","A3\Characters_F\Common\Data\coveralls_injury.rvmat","A3\Characters_F\Civil\Data\hunter.rvmat","A3\Characters_F\Civil\Data\hunter_injury.rvmat","A3\Characters_F\Civil\Data\hunter_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"};
    };

    hiddenSelections[] = {"Camo","insignia"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_1_co.paa"};

    class EventHandlers: Eventhandlers {
      init = "(_this select 0) execVM ""\A3\Characters_F_Bootcamp\Data\Scripts\randomize_gue1.sqf""";
    };

    items[] = {"FirstAidKit"};
    respawnitems[] = {"FirstAidKit"};
    weapons[] = {"arifle_Mk20_plain_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20_plain_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_Chestrig_oli","H_Shemag_olive","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_Chestrig_oli","H_Shemag_olive","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
  };

  class AGM_O_G_Soldier_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_Soldier_F";
    scope = 2;
    displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
    hiddenSelections[] = {"camo1","camo2"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Guerrilla\Data\c_cloth1_kabeiroi_co.paa","a3\characters_f_beta\indep\data\ia_soldier_01_clothing_co.paa"};
    headgearProbability = 100;
    allowedHeadgear[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_lite_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "I_Soldier_lite_F";
    scope = 2;
    displayName = "$STR_B_Soldier_lite_F0";
    hiddenSelections[] = {"camo1","camo2"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Guerrilla\Data\c_cloth1_kabeiroi_co.paa","a3\characters_f_beta\indep\data\ia_soldier_01_clothing_co.paa"};
    cost = 90000;
    camouflage = 1.2;
    weapons[] = {"arifle_Mk20C_plain_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20C_plain_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_BandollierB_blk","H_Cap_oli","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_BandollierB_blk","H_Cap_oli","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    headgearProbability = 100;
    allowedHeadgear[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_SL_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_Soldier_SL_F";
    scope = 2;
    displayName = "$STR_B_Soldier_SL_F0";
    cost = 500000;
    camouflage = 1.6;
    sensitivity = 3.2;
    icon = "iconManLeader";
    weapons[] = {"arifle_Mk20C_plain_F","hgun_ACPC2_F","Throw","Put","Binocular"};
    respawnWeapons[] = {"arifle_Mk20C_plain_F","hgun_ACPC2_F","Throw","Put","Binocular"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag_Tracer_Yellow","30Rnd_556x45_Stanag_Tracer_Yellow","9Rnd_45ACP_Mag","9Rnd_45ACP_Mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","SmokeShellRed","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag_Tracer_Yellow","30Rnd_556x45_Stanag_Tracer_Yellow","9Rnd_45ACP_Mag","9Rnd_45ACP_Mag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","SmokeShellRed","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_Chestrig_blk","H_Watchcap_blk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_Chestrig_blk","H_Watchcap_blk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_leader.p3d";
    uniformClass = "U_IG_leader";
    headgearProbability = 50;
    allowedHeadgear[] = {"H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven"};
    allowedHeadgearB[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_TL_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_Soldier_TL_F";
    scope = 2;
    cost = 450000;
    sensitivity = 3.2;
    threat[] = {1,0.3,0.1};
    icon = "iconManLeader";
    displayName = "$STR_B_Soldier_TL_F0";
    weapons[] = {"arifle_Mk20_GL_plain_F","hgun_ACPC2_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20_GL_plain_F","hgun_ACPC2_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag_Tracer_Yellow","30Rnd_556x45_Stanag_Tracer_Yellow","9Rnd_45ACP_Mag","9Rnd_45ACP_Mag","HandGrenade","MiniGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell"};
    respawnmagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag_Tracer_Yellow","30Rnd_556x45_Stanag_Tracer_Yellow","9Rnd_45ACP_Mag","9Rnd_45ACP_Mag","HandGrenade","MiniGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell"};
    linkedItems[] = {"V_TacVest_blk","H_Booniehat_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_TacVest_blk","H_Booniehat_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_leader.p3d";
    uniformClass = "U_IG_leader";
    headgearProbability = 60;
    allowedHeadgear[] = {"H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven"};
    allowedHeadgearB[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_AR_F: AGM_O_G_Soldier_base_F {
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
    _generalMacro = "AGM_O_G_Soldier_AR_F";
    scope = 2;
    displayName = "$STR_B_Soldier_AR_F0";
    weapons[] = {"LMG_Mk200_F","Throw","Put"};
    respawnWeapons[] = {"LMG_Mk200_F","Throw","Put"};
    magazines[] = {"200Rnd_65x39_cased_Box","200Rnd_65x39_cased_Box","200Rnd_65x39_cased_Box","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"200Rnd_65x39_cased_Box","200Rnd_65x39_cased_Box","200Rnd_65x39_cased_Box","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    cost = 120000;
    icon = "iconManMG";
    linkedItems[] = {"V_TacVest_blk","H_Bandanna_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_TacVest_blk","H_Bandanna_khk","D efaultManGuerillaLinkedItems"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_1";
    headgearProbability = 60;
    allowedHeadgear[] = {"H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk"};
    allowedHeadgearB[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_medic_F: AGM_O_G_Soldier_base_F {
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
    _generalMacro = "AGM_O_G_medic_F";
    scope = 2;
    displayName = "$STR_B_medic_F0";
    backpack = "G_FieldPack_Medic";
    weapons[] = {"arifle_Mk20_plain_F","hgun_ACPC2_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20_plain_F","hgun_ACPC2_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","9Rnd_45ACP_Mag","9Rnd_45ACP_Mag","MiniGrenade","SmokeShell","SmokeShellGreen","SmokeShellRed","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnmagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","9Rnd_45ACP_Mag","9Rnd_45ACP_Mag","MiniGrenade","SmokeShell","SmokeShellGreen","SmokeShellRed","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_TacVest_blk","H_Cap_oli","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_TacVest_blk","H_Cap_oli","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    attendant = 1;
    icon = "iconManMedic";
    picture = "pictureHeal";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_3";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Guerrilla\Data\ig_guerrilla2_3_co.paa"};
    cost = 300000;
    headgearProbability = 50;
    allowedHeadgear[] = {"H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven"};
    allowedHeadgearB[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_engineer_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_engineer_F";
    scope = 2;
    displayName = "$STR_B_engineer_F0";
    backpack = "G_TacticalPack_Eng";
    canDeactivateMines = 1;
    engineer = 1;
    detectSkill = 70;
    weapons[] = {"arifle_Mk20C_plain_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20C_plain_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MiniGrenade","SmokeShell","SmokeShellGreen","SmokeShellRed","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnmagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","MiniGrenade","SmokeShell","SmokeShellGreen","SmokeShellRed","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    cost = 220000;
    linkedItems[] = {"V_Chestrig_blk","H_Watchcap_camo","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_Chestrig_blk","H_Watchcap_camo","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    icon = "iconManEngineer";
    picture = "pictureRepair";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_2";
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_2_co.paa"};
    headgearProbability = 50;
    allowedHeadgear[] = {"H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven"};
    allowedHeadgearB[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_exp_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_Soldier_exp_F";
    scope = 2;
    displayName = "$STR_B_Soldier_exp_F0";
    cost = 115000;
    camouflage = 1.6;
    sensitivity = 2.8;
    backpack = "G_Carryall_Exp";
    weapons[] = {"arifle_Mk20C_plain_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20C_plain_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","MiniGrenade","APERSMine_Range_Mag","APERSMine_Range_Mag","APERSMine_Range_Mag","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","MiniGrenade","APERSMine_Range_Mag","APERSMine_Range_Mag","APERSMine_Range_Mag","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    canDeactivateMines = 1;
    detectSkill = 80;
    threat[] = {1,0.5,0.1};
    linkedItems[] = {"V_Chestrig_blk","H_Shemag_olive","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_Chestrig_blk","H_Shemag_olive","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    icon = "iconManExplosive";
    picture = "pictureExplosive";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_1";
    headgearProbability = 60;
    allowedHeadgear[] = {"H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk"};
    allowedHeadgearB[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_GL_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_Soldier_GL_F";
    scope = 2;
    displayName = "$STR_B_Soldier_GL_F0";
    weapons[] = {"arifle_Mk20_GL_plain_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20_GL_plain_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell"};
    respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell"};
    cost = 130000;
    linkedItems[] = {"V_Chestrig_blk","H_Bandanna_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_Chestrig_blk","H_Bandanna_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
    uniformClass = "U_IG_Guerilla2_3";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Guerrilla\Data\ig_guerrilla2_3_co.paa"};
    headgearProbability = 50;
    allowedHeadgear[] = {};
    allowedHeadgearB[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_M_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_Soldier_M_F";
    scope = 2;
    displayName = "$STR_B_Soldier_M_F0";
    weapons[] = {"arifle_Mk20_MRCO_plain_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20_MRCO_plain_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    cost = 150000;
    linkedItems[] = {"V_BandollierB_khk","H_Shemag_olive","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_BandollierB_khk","H_Shemag_olive","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla3_1.p3d";
    uniformClass = "U_IG_Guerilla3_1";
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla3_1_co.paa"};
    headgearProbability = 60;
    allowedHeadgear[] = {"H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl"};
    allowedHeadgearB[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_LAT_F: AGM_O_G_Soldier_base_F {
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
    _generalMacro = "AGM_O_G_Soldier_LAT_F";
    scope = 2;
    displayName = "$STR_B_Soldier_LAT_F0";
    backpack = "G_FieldPack_LAT";
    weapons[] = {"arifle_Mk20_plain_F","launch_RPG32_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20_plain_F","launch_RPG32_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","RPG32_F","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    respawnmagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","RPG32_F","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    threat[] = {1,0.6,0.1};
    icon = "iconManAT";
    linkedItems[] = {"V_TacVest_blk","H_Bandanna_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_TacVest_blk","H_Bandanna_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    model = "\A3\Characters_F_Bootcamp\Guerrilla\ig_guerrilla_6_1.p3d";
    uniformClass = "U_IG_Guerrilla_6_1";
    hiddenSelections[] = {"camo","insignia"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Guerrilla\Data\ig_guerrilla_6_1_co.paa"};
    headgearProbability = 100;
    allowedHeadgear[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_Soldier_A_F: AGM_O_G_Soldier_base_F {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_O_G_Soldier_A_F";
    scope = 2;
    displayName = "$STR_B_Soldier_A_F0";
    cost = 110000;
    backpack = "G_Carryall_Ammo";
    weapons[] = {"arifle_Mk20C_plain_F","Throw","Put"};
    respawnWeapons[] = {"arifle_Mk20C_plain_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    respawnmagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade","MiniGrenade","SmokeShell","SmokeShellGreen","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_Chestrig_oli","H_Booniehat_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_Chestrig_oli","H_Booniehat_khk","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    hiddenSelections[] = {"camo1","camo2"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Guerrilla\Data\c_cloth1_kabeiroi_co.paa","a3\characters_f_beta\indep\data\ia_soldier_01_clothing_co.paa"};
    headgearProbability = 60;
    allowedHeadgear[] = {"H_Bandanna_gry","H_Bandanna_blu","H_Bandanna_cbr","H_Bandanna_khk_hs","H_Bandanna_khk","H_Bandanna_sgg","H_Bandanna_sand","H_Bandanna_surfer","H_Bandanna_surfer_blk","H_Bandanna_surfer_grn","H_Bandanna_camo"};
    allowedHeadgearB[] = {"H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_Booniehat_khk_hs","H_Booniehat_khk","H_Booniehat_oli","H_Booniehat_tan","H_Booniehat_dgtl","H_Cap_blk","H_Cap_grn","H_Cap_oli","H_Cap_oli_hs","H_Cap_tan","H_Cap_blk_Raven","H_Shemag_olive","H_Shemag_olive_hs","H_ShemagOpen_tan","H_ShemagOpen_khk"};
  };

  class AGM_O_G_officer_F: AGM_O_G_Soldier_base_F {
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
    _generalMacro = "AGM_O_G_officer_F";

    class Wounds {
      tex[] = {};
      mat[] = {"A3\Characters_F_Beta\INDEP\Data\officer.rvmat","A3\Characters_F_Beta\INDEP\Data\officer_injury.rvmat","A3\Characters_F_Beta\INDEP\Data\officer_injury.rvmat"};
    };

    cost = 600000;
    camouflage = 1.6;
    sensitivity = 3;
    icon = "iconManOfficer";
    scope = 2;
    displayName = "$STR_B_officer_F0";
    weapons[] = {"arifle_Mk20_MRCO_plain_F","hgun_ACPC2_F","Throw","Put"};
    respawnweapons[] = {"arifle_Mk20_MRCO_plain_F","hgun_ACPC2_F","Throw","Put"};
    magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","9Rnd_45ACP_Mag","9Rnd_45ACP_Mag","SmokeShell","SmokeShellGreen","SmokeShellRed","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","9Rnd_45ACP_Mag","9Rnd_45ACP_Mag","SmokeShell","SmokeShellGreen","SmokeShellRed","SmokeShellBlue","Chemlight_blue","Chemlight_blue"};
    linkedItems[] = {"V_Chestrig_oli","H_Watchcap_blk","ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    respawnLinkedItems[] = {"V_Chestrig_oli","H_Watchcap_blk","ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
    uniformClass = "U_IG_Guerilla2_3";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Guerrilla\Data\ig_guerrilla2_3_co.paa"};
    headgearProbability = 100;
    allowedHeadgear[] = {"H_Beret_blk"};
  };
};
