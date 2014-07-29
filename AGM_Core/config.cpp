class CfgPatches {
  class AGM_Core {
    units[] = {"AGM_Box_Misc"};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {
      "a3_air_f",
      "a3_air_f_heli_light_01",
      "a3_air_f_heli_light_02",
      "a3_air_f_beta",
      "a3_air_f_beta_heli_attack_01",
      "a3_air_f_beta_heli_attack_02",
      "a3_air_f_beta_heli_transport_01",
      "a3_air_f_beta_heli_transport_02",
      "a3_air_f_beta_parachute_01",
      "a3_air_f_beta_parachute_02",
      "a3_air_f_gamma_plane_fighter_03",
      "a3_air_f_gamma_uav_01",
      "a3_air_f_gamma_uav_02",
      "a3_air_f_epb_heli_light_03",
      "a3_air_f_epc_plane_cas_01",
      "a3_air_f_epc_plane_cas_02",
      "a3_air_f_epc_plane_fighter_03",
      "a3_anims_f",
      "a3_anims_f_config_sdr",
      "a3_anims_f_epa",
      "a3_anims_f_epc",
      "a3_anims_f_kart",
      "a3_armor_f",
      "a3_armor_f_panther",
      "a3_armor_f_beta_apc_tracked_02",
      "a3_armor_f_amv",
      "a3_armor_f_marid",
      "a3_armor_f_beta",
      "a3_armor_f_apc_wheeled_03",
      "a3_armor_f_slammer",
      "a3_armor_f_t100k",
      "a3_armor_f_epb_apc_tracked_03",
      "a3_armor_f_epb_mbt_03",
      "a3_armor_f_epc_mbt_01",
      "a3_cargoposes_f",
      "a3_characters_f_blufor",
      "a3_characters_f",
      "a3_characters_f_civil",
      "a3_characters_f_common",
      "a3_characters_f_heads",
      "a3_characters_f_opfor",
      "a3_characters_f_proxies",
      "a3_characters_f_beta",
      "a3_characters_f_indep",
      "a3_characters_f_gamma",
      "a3_characters_f_epb",
      "a3_characters_f_epb_heads",
      "a3_characters_f_epc",
      "a3_characters_f_bootcamp",
      "a3_characters_f_bootcamp_common",
      "a3_data_f",
      "a3_data_f_particleeffects",
      "a3_data_f_bootcamp",
      "a3_data_f_curator",
      "a3_data_f_curator_characters",
      "a3_data_f_curator_intel",
      "a3_data_f_curator_respawn",
      "a3_data_f_kart",
      "a3_data_f_kart_particleeffects",
      "a3_data_f_curator_eagle",
      "a3_data_f_curator_misc",
      "a3_data_f_curator_virtual",
      "a3_dubbing_radio_f",
      "a3_functions_f",
      "a3_misc_f",
      "a3_misc_f_helpers",
      "a3_soft_f_crusher_ugv",
      "a3_soft_f",
      "a3_soft_f_mrap_01",
      "a3_soft_f_mrap_02",
      "a3_soft_f_offroad_01",
      "a3_soft_f_quadbike",
      "a3_soft_f_mrap_03",
      "a3_soft_f_beta_quadbike",
      "a3_soft_f_hemtt",
      "a3_soft_f_truckheavy",
      "a3_soft_f_car",
      "a3_soft_f_gamma_offroad",
      "a3_soft_f_gamma_quadbike",
      "a3_soft_f_suv",
      "a3_soft_f_gamma_hemtt",
      "a3_soft_f_gamma_truckheavy",
      "a3_soft_f_truck",
      "a3_soft_f_epc_truck_03",
      "a3_soft_f_bootcamp_offroad_01",
      "a3_soft_f_bootcamp_quadbike",
      "a3_soft_f_bootcamp_truck",
      "a3_soft_f_kart_kart_01",
      "a3_uav_f_characters_f_gamma",
      "a3_uav_f_weapons_f_gamma_ammoboxes",
      "a3_ui_f",
      "a3_ui_f_bootcamp",
      "a3_ui_f_curator",
      "a3_ui_f_kart",
      "a3_weapons_f_gamma_items",
      "a3_weapons_f_acc",
      "a3_weapons_f_ammoboxes",
      "a3_weapons_f",
      "a3_weapons_f_dummyweapons",
      "a3_weapons_f_explosives",
      "a3_weapons_f_items",
      "a3_weapons_f_launchers_nlaw",
      "a3_weapons_f_launchers_law",
      "a3_weapons_f_ebr",
      "a3_weapons_f_longrangerifles_gm6",
      "a3_weapons_f_longrangerifles_m320",
      "a3_weapons_f_machineguns_m200",
      "a3_weapons_f_pistols_p07",
      "a3_weapons_f_pistols_rook40",
      "a3_weapons_f_rifles_khaybar",
      "a3_weapons_f_rifles_mx",
      "a3_weapons_f_rifles_sdar",
      "a3_weapons_f_rifles_trg20",
      "a3_weapons_f_beta_acc",
      "a3_weapons_f_beta_ammoboxes",
      "a3_weapons_f_beta",
      "a3_weapons_f_launchers_titan",
      "a3_weapons_f_beta_ebr",
      "a3_weapons_f_machineguns_zafir",
      "a3_weapons_f_pistols_acpc2",
      "a3_weapons_f_beta_rifles_khaybar",
      "a3_weapons_f_rifles_mk20",
      "a3_weapons_f_beta_rifles_mx",
      "a3_weapons_f_beta_rifles_trg20",
      "a3_weapons_f_rifles_vector",
      "a3_weapons_f_rifles_smg_02",
      "a3_weapons_f_gamma_acc",
      "a3_weapons_f_gamma_ammoboxes",
      "a3_weapons_f_gamma",
      "a3_weapons_f_pistols_pdw2000",
      "a3_weapons_f_nato",
      "a3_weapons_f_csat",
      "a3_weapons_f_aaf",
      "a3_weapons_f_fia",
      "a3_weapons_f_itemholders",
      "a3_weapons_f_headgear",
      "a3_weapons_f_uniforms",
      "a3_weapons_f_vests",
      "a3_weapons_f_epa",
      "a3_weapons_f_epa_acc",
      "a3_weapons_f_epa_ammoboxes",
      "a3_weapons_f_epa_longrangerifles_dmr_01",
      "a3_weapons_f_epa_ebr",
      "a3_weapons_f_epa_longrangerifles_gm6",
      "a3_weapons_f_pistols_pistol_heavy_01",
      "a3_weapons_f_pistols_pistol_heavy_02",
      "a3_weapons_f_epa_rifles_mx",
      "a3_weapons_f_epb",
      "a3_weapons_f_epb_acc",
      "a3_weapons_f_epb_ammoboxes",
      "a3_weapons_f_epb_longrangerifles_gm3",
      "a3_weapons_f_epb_longrangerifles_m320",
      "a3_weapons_f_epb_rifles_mx_black",
      "a3_weapons_f_epc",
      "a3_weapons_f_bootcamp",
      "a3_weapons_f_bootcamp_ammoboxes",
      "a3_weapons_f_bootcamp_longrangerifles_gm6",
      "a3_weapons_f_bootcamp_longrangerifles_m320",
      "a3_weapons_f_kart",
      "a3_weapons_f_kart_pistols_pistol_signal_f",
      "cba_xeh",
      "extended_eventhandlers",
      "cba_extended_eventhandlers"
    };
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Core {
    class AGM_Core {
      file = "AGM_Core\functions";
      class adminKick;
      class binarizeNumber;
      class canInteractWith;
      class claim;
      class closeDialogIfTargetMoves;
      class codeToString;
      class convertKeyCode;
      class disableUserInput;
      class disableUserInput2;
      class displayText;
      class displayTextPicture;
      class displayTextStructured;
      class execRemoteFnc;
      class filter;
      class findStringInString;
      class getBinocular;
      class getConfigCommander;
      class getConfigGunner;
      class getMarkerType;
      class getNumberFromMissionSQM;
      class getStringFromMissionSQM;
      class getTargetAzimuthAndInclination;
      class getTargetDistance;
      class getTurretConfigPath;
      class getTurretIndex;
      class getTurrets;
      class getTurretCommander;
      class getTurretGunner;
      class getWeaponAzimuthAndInclination;
      class getWeaponType;
      class getWindDirection;
      class goKneeling;
      class hadamardProduct;
      class inTransitionAnim;
      class isAutoWind;
      class isEngineer;
      class isInBuilding;
      class isMedic;
      class isTurnedOut;
      class map;
      class moduleCheckPBOs;
      class moduleLSDVehicles;
      class numberToDigits;
      class numberToDigitsString;
      class progressBar;
      class revertKeyCodeLocalized;
      class sanitizeString;
      class setKeyDefault;
      class setName;
      class setParameter;
      class stringToColoredText;
      class subString;
      class toBin;
      class toBitmask;
      class toHex;
    };
  };
  class AGM_Debug {
    class AGM_Debug {
      file = "AGM_Core\functions\Debug";
      class showUser;
    };
  };
};

class CfgSounds {
  class AGM_Sound_Click {
    sound[] = {"\AGM_Core\sounds\AGM_click.wav", 5, 1, 200};
    titles[] = {};
  };
};

class Extended_PreInit_EventHandlers {
  class AGM_Core {
    serverInit = "call compile preprocessFileLineNumbers '\AGM_Core\scripts\readParameters.sqf'";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Core {
    Init = "call compile preprocessFileLineNumbers '\AGM_Core\init.sqf'";
    disableModuload = true;
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_SetName {
      init = "if (local (_this select 0)) then {_this call AGM_Core_fnc_setName};";
    };
  };
};

class Extended_Local_EventHandlers {
  class CAManBase {
    class AGM_SetName {
      local = "if (_this select 1) then {_this call AGM_Core_fnc_setName};";
    };
  };
};

class CfgFactionClasses {
  class AGM {
    displayName = "AGM";
    priority = 0.1;
    side = 7;
  };
};

class CfgVehicles {
  class Module_F;
  class AGM_ModuleCheckPBOs: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "Check PBOs";
    function = "AGM_Core_fnc_moduleCheckPBOs";
    scope = 2;
    isGlobal = 1;
    icon = "\AGM_Core\UI\IconCheckPBO_ca.paa";
    class Arguments {
      class Action {
        displayName = "Action";
        description = "What to do with people who do not have the right PBOs?";
        class values {
          class WarnOnce {
            default = 1;
            name = "Warn once";
            value = 0;
          };
          class Warn {
            name = "Warn (permanent)";
            value = 1;
          };
          class Kick {
            name = "Kick";
            value = 2;
          };
        };
      };
    };
  };

  class AGM_ModuleLSDVehicles: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "LSD Vehicles";
    function = "AGM_Core_fnc_moduleLSDVehicles";
    scope = 2;
    isGlobal = 1;
    class Arguments {
    };
  };

  class Box_NATO_Support_F;
  class AGM_Box_Misc: Box_NATO_Support_F {
    author = "AGM";
    displayName = "$STR_AGM_Core_MiscItems";
    transportmaxmagazines = 9001;
    transportmaxbackbacks = 0;
    maximumload = 2000;

    class TransportWeapons {};
    class TransportMagazines {};
    class TransportItems {};
  };
};

class CfgWeapons {
  class Rifle_Base_F;

  class AGM_FakePrimaryWeapon: Rifle_Base_F {
    discreteDistance[] = {};
    discreteDistanceInitIndex = 0;
    displayName = "";
    model = "";
    magazines[] = {"AGM_FakeMagazine"};
    scope = 2;
  };
};

class CfgMagazines {
  class CA_Magazine;

  class AGM_FakeMagazine: CA_Magazine {
    descriptionShort = "";
    displayName = "";
    displayNameShort = "";
    count = 0;
  };
};

class AGM_Rsc_Display_Base {
  idd = -1;
  type = 0;
  style = 48;
  name = "";
  duration = 999999;
  fadeIn = 0;
  fadeOut = 0;
  font = "TahomaB";
  size = 1;
  colorBackground[] = {1, 1, 1, 0};
  colorText[] = {1, 1, 1, 1};
};

class AGM_Rsc_Control_Base {
  idc = 1;
  type = 0;
  style = 48;
  access = 0;
  lineSpacing = 0;
  moving = 1;
  text = "";
  size = 1;
  sizeEx = 0;
  font = "TahomaB";
  colorBackground[] = {1, 1, 1, 0};
  colorText[] = {1, 1, 1, 1};
  x = 0;
  y = 0;
  w = 0;
  h = 0;
};

class AGM_Core_canInteractConditions {};

#include <MainMenu.hpp>
#include <MenuConfig.hpp>
#include <ProgressScreen.hpp>
#include <HintConfig.hpp>
