class CfgPatches {
  class AGM_Core {
    units[] = {"AGM_Box_Misc"};
    weapons[] = {"AGM_ItemCore", "AGM_FakePrimaryWeapon"};
    requiredVersion = 0.60;
    requiredAddons[] = {
      "a3_air_f",
      "a3_air_f_beta",
      "a3_air_f_beta_heli_attack_01",
      "a3_air_f_beta_heli_attack_02",
      "a3_air_f_beta_heli_transport_01",
      "a3_air_f_beta_heli_transport_02",
      "a3_air_f_beta_parachute_01",
      "a3_air_f_beta_parachute_02",
      "a3_air_f_epb_heli_light_03",
      "a3_air_f_epc_plane_cas_01",
      "a3_air_f_epc_plane_cas_02",
      "a3_air_f_epc_plane_fighter_03",
      "a3_air_f_gamma_plane_fighter_03",
      "a3_air_f_gamma_uav_01",
      "a3_air_f_gamma_uav_02",
      "a3_air_f_heli",
      "a3_air_f_heli_heli_attack_01",
      "a3_air_f_heli_heli_attack_02",
      "a3_air_f_heli_heli_light_01",
      "a3_air_f_heli_heli_light_02",
      "a3_air_f_heli_heli_light_03",
      "a3_air_f_heli_heli_transport_01",
      "a3_air_f_heli_heli_transport_02",
      "a3_air_f_heli_heli_transport_03",
      "a3_air_f_heli_heli_transport_04",
      "a3_air_f_heli_light_01",
      "a3_air_f_heli_light_02",
      "a3_animals_f",
      "a3_animals_f_animconfig",
      "a3_animals_f_chicken",
      "a3_animals_f_dog",
      "a3_animals_f_fishes",
      "a3_animals_f_goat",
      "a3_animals_f_kestrel",
      "a3_animals_f_rabbit",
      "a3_animals_f_seagull",
      "a3_animals_f_sheep",
      "a3_animals_f_snakes",
      "a3_animals_f_turtle",
      "a3_anims_f",
      "a3_anims_f_config_sdr",
      "a3_anims_f_epa",
      "a3_anims_f_epc",
      "a3_anims_f_heli",
      "a3_anims_f_kart",
      "a3_armor_f",
      "a3_armor_f_amv",
      "a3_armor_f_apc_wheeled_03",
      "a3_armor_f_beta",
      "a3_armor_f_beta_apc_tracked_02",
      "a3_armor_f_epb_apc_tracked_03",
      "a3_armor_f_epb_mbt_03",
      "a3_armor_f_epc_mbt_01",
      "a3_armor_f_marid",
      "a3_armor_f_panther",
      "a3_armor_f_slammer",
      "a3_armor_f_t100k",
      "a3_baseconfig_f",
      "a3_boat_f",
      "a3_boat_f_beta_boat_armed_01",
      "a3_boat_f_beta_boat_transport_01",
      "a3_boat_f_boat_armed_01",
      "a3_boat_f_boat_transport_01",
      "a3_boat_f_civilian_boat",
      "a3_boat_f_epc_submarine_01_f",
      "a3_boat_f_gamma_boat_transport_01",
      "a3_boat_f_heli_boat_armed_01",
      "a3_boat_f_heli_sdv_01",
      "a3_boat_f_sdv_01",
      "a3_boat_f_trawler",
      "a3_cargoposes_f",
      "a3_cargoposes_f_heli",
      "a3_characters_f",
      "a3_characters_f_beta",
      "a3_characters_f_blufor",
      "a3_characters_f_bootcamp",
      "a3_characters_f_bootcamp_common",
      "a3_characters_f_civil",
      "a3_characters_f_common",
      "a3_characters_f_epa",
      "a3_characters_f_epb",
      "a3_characters_f_epb_heads",
      "a3_characters_f_epc",
      "a3_characters_f_gamma",
      "a3_characters_f_heads",
      "a3_characters_f_indep",
      "a3_characters_f_kart",
      "a3_characters_f_opfor",
      "a3_characters_f_proxies",
      "a3_data_f",
      "a3_data_f_bootcamp",
      "a3_data_f_curator",
      "a3_data_f_curator_characters",
      "a3_data_f_curator_eagle",
      "a3_data_f_curator_intel",
      "a3_data_f_curator_misc",
      "a3_data_f_curator_respawn",
      "a3_data_f_curator_virtual",
      "a3_data_f_heli",
      "a3_data_f_hook",
      "a3_data_f_kart",
      "a3_data_f_kart_particleeffects",
      "a3_data_f_particleeffects",
      "a3_dubbing_radio_f",
      "a3_editor_f",
      "a3_functions_f",
      "a3_functions_f_bootcamp",
      "a3_functions_f_curator",
      "a3_functions_f_epa",
      "a3_functions_f_epc",
      "a3_functions_f_heli",
      "a3_language_f",
      "a3_language_f_beta",
      "a3_language_f_bootcamp",
      "a3_language_f_curator",
      "a3_language_f_epa",
      "a3_language_f_epb",
      "a3_language_f_epc",
      "a3_language_f_gamma",
      "a3_language_f_heli",
      "a3_language_f_kart",
      "a3_languagemissions_f",
      "a3_languagemissions_f_beta",
      "a3_languagemissions_f_gamma",
      "a3_languagemissions_f_kart",
      "a3_map_altis",
      "a3_map_altis_scenes",
      "a3_map_data",
      "a3_map_stratis",
      "a3_map_stratis_scenes",
      "a3_map_vr_scenes",
      "a3_misc_f",
      "a3_misc_f_helpers",
      "a3_missions_f",
      "a3_missions_f_beta",
      "a3_missions_f_bootcamp",
      "a3_missions_f_curator",
      "a3_missions_f_epa",
      "a3_missions_f_epb",
      "a3_missions_f_epc",
      "a3_missions_f_gamma",
      "a3_missions_f_heli",
      "a3_missions_f_kart",
      "a3_modules_f",
      "a3_modules_f_beta",
      "a3_modules_f_beta_firingdrills",
      "a3_modules_f_bootcamp",
      "a3_modules_f_bootcamp_misc",
      "a3_modules_f_curator",
      "a3_modules_f_curator_animals",
      "a3_modules_f_curator_cas",
      "a3_modules_f_curator_chemlights",
      "a3_modules_f_curator_curator",
      "a3_modules_f_curator_effects",
      "a3_modules_f_curator_environment",
      "a3_modules_f_curator_flares",
      "a3_modules_f_curator_intel",
      "a3_modules_f_curator_lightning",
      "a3_modules_f_curator_mines",
      "a3_modules_f_curator_misc",
      "a3_modules_f_curator_multiplayer",
      "a3_modules_f_curator_objectives",
      "a3_modules_f_curator_ordnance",
      "a3_modules_f_curator_respawn",
      "a3_modules_f_curator_smokeshells",
      "a3_modules_f_dyno",
      "a3_modules_f_effects",
      "a3_modules_f_epb",
      "a3_modules_f_epb_misc",
      "a3_modules_f_events",
      "a3_modules_f_groupmodifiers",
      "a3_modules_f_hc",
      "a3_modules_f_heli",
      "a3_modules_f_heli_spawnai",
      "a3_modules_f_intel",
      "a3_modules_f_kart",
      "a3_modules_f_kart_timetrials",
      "a3_modules_f_livefeed",
      "a3_modules_f_marta",
      "a3_modules_f_misc",
      "a3_modules_f_multiplayer",
      "a3_modules_f_objectmodifiers",
      "a3_modules_f_sites",
      "a3_modules_f_skirmish",
      "a3_modules_f_strategicmap",
      "a3_modules_f_supports",
      "a3_modules_f_uav",
      "a3_music_f",
      "a3_music_f_bootcamp",
      "a3_music_f_epa",
      "a3_music_f_epb",
      "a3_music_f_epc",
      "a3_music_f_heli",
      "a3_plants_f_bush",
      "a3_roads_f",
      "a3_rocks_f",
      "a3_signs_f",
      "a3_signs_f_ad",
      "a3_soft_f",
      "a3_soft_f_beta_quadbike",
      "a3_soft_f_bootcamp_offroad_01",
      "a3_soft_f_bootcamp_quadbike",
      "a3_soft_f_bootcamp_truck",
      "a3_soft_f_car",
      "a3_soft_f_crusher_ugv",
      "a3_soft_f_epc_truck_03",
      "a3_soft_f_gamma_hemtt",
      "a3_soft_f_gamma_offroad",
      "a3_soft_f_gamma_quadbike",
      "a3_soft_f_gamma_truckheavy",
      "a3_soft_f_heli_car",
      "a3_soft_f_heli_crusher_ugv",
      "a3_soft_f_heli_mrap_01",
      "a3_soft_f_heli_mrap_02",
      "a3_soft_f_heli_mrap_03",
      "a3_soft_f_heli_quadbike",
      "a3_soft_f_heli_suv",
      "a3_soft_f_heli_truck",
      "a3_soft_f_hemtt",
      "a3_soft_f_kart_kart_01",
      "a3_soft_f_mrap_01",
      "a3_soft_f_mrap_02",
      "a3_soft_f_mrap_03",
      "a3_soft_f_offroad_01",
      "a3_soft_f_quadbike",
      "a3_soft_f_suv",
      "a3_soft_f_truck",
      "a3_soft_f_truckheavy",
      "a3_sounds_f",
      "a3_sounds_f_bootcamp",
      "a3_sounds_f_epb",
      "a3_sounds_f_epc",
      "a3_static_f",
      "a3_static_f_beta_mortar_01",
      "a3_static_f_gamma",
      "a3_static_f_gamma_aa",
      "a3_static_f_gamma_at",
      "a3_static_f_gamma_mortar_01",
      "a3_static_f_mortar_01",
      "a3_structures_f",
      "a3_structures_f_bootcamp_civ_camping",
      "a3_structures_f_bootcamp_civ_sportsgrounds",
      "a3_structures_f_bootcamp_ind_cargo",
      "a3_structures_f_bootcamp_items_electronics",
      "a3_structures_f_bootcamp_items_food",
      "a3_structures_f_bootcamp_items_sport",
      "a3_structures_f_bootcamp_system",
      "a3_structures_f_bootcamp_training",
      "a3_structures_f_bootcamp_vr_blocks",
      "a3_structures_f_bootcamp_vr_coverobjects",
      "a3_structures_f_bootcamp_vr_helpers",
      "a3_structures_f_bridges",
      "a3_structures_f_civ",
      "a3_structures_f_civ_accessories",
      "a3_structures_f_civ_ancient",
      "a3_structures_f_civ_belltowers",
      "a3_structures_f_civ_calvaries",
      "a3_structures_f_civ_camping",
      "a3_structures_f_civ_chapels",
      "a3_structures_f_civ_constructions",
      "a3_structures_f_civ_dead",
      "a3_structures_f_civ_garbage",
      "a3_structures_f_civ_graffiti",
      "a3_structures_f_civ_infoboards",
      "a3_structures_f_civ_kiosks",
      "a3_structures_f_civ_lamps",
      "a3_structures_f_civ_market",
      "a3_structures_f_civ_offices",
      "a3_structures_f_civ_pavements",
      "a3_structures_f_civ_playground",
      "a3_structures_f_civ_sportsgrounds",
      "a3_structures_f_civ_statues",
      "a3_structures_f_civ_tourism",
      "a3_structures_f_dominants",
      "a3_structures_f_dominants_amphitheater",
      "a3_structures_f_dominants_castle",
      "a3_structures_f_dominants_church",
      "a3_structures_f_dominants_hospital",
      "a3_structures_f_dominants_lighthouse",
      "a3_structures_f_dominants_wip",
      "a3_structures_f_epa_civ_camping",
      "a3_structures_f_epa_civ_constructions",
      "a3_structures_f_epa_items_electronics",
      "a3_structures_f_epa_items_food",
      "a3_structures_f_epa_items_medical",
      "a3_structures_f_epa_items_tools",
      "a3_structures_f_epa_items_vessels",
      "a3_structures_f_epa_mil_scrapyard",
      "a3_structures_f_epa_walls",
      "a3_structures_f_epb_civ_accessories",
      "a3_structures_f_epb_civ_camping",
      "a3_structures_f_epb_civ_dead",
      "a3_structures_f_epb_civ_garbage",
      "a3_structures_f_epb_civ_graffiti",
      "a3_structures_f_epb_civ_playground",
      "a3_structures_f_epb_furniture",
      "a3_structures_f_epb_items_documents",
      "a3_structures_f_epb_items_luggage",
      "a3_structures_f_epb_items_military",
      "a3_structures_f_epb_items_vessels",
      "a3_structures_f_epb_naval_fishing",
      "a3_structures_f_epc_civ_accessories",
      "a3_structures_f_epc_civ_camping",
      "a3_structures_f_epc_civ_garbage",
      "a3_structures_f_epc_civ_infoboards",
      "a3_structures_f_epc_civ_kiosks",
      "a3_structures_f_epc_civ_playground",
      "a3_structures_f_epc_civ_tourism",
      "a3_structures_f_epc_dominants_ghosthotel",
      "a3_structures_f_epc_dominants_stadium",
      "a3_structures_f_epc_furniture",
      "a3_structures_f_epc_items_documents",
      "a3_structures_f_epc_items_electronics",
      "a3_structures_f_epc_walls",
      "a3_structures_f_furniture",
      "a3_structures_f_heli_civ_accessories",
      "a3_structures_f_heli_civ_constructions",
      "a3_structures_f_heli_civ_garbage",
      "a3_structures_f_heli_civ_market",
      "a3_structures_f_heli_furniture",
      "a3_structures_f_heli_ind_airport",
      "a3_structures_f_heli_ind_cargo",
      "a3_structures_f_heli_ind_machines",
      "a3_structures_f_heli_items_airport",
      "a3_structures_f_heli_items_electronics",
      "a3_structures_f_heli_items_food",
      "a3_structures_f_heli_items_luggage",
      "a3_structures_f_heli_items_sport",
      "a3_structures_f_heli_items_tools",
      "a3_structures_f_heli_vr_helpers",
      "a3_structures_f_households",
      "a3_structures_f_households_addons",
      "a3_structures_f_households_house_big01",
      "a3_structures_f_households_house_big02",
      "a3_structures_f_households_house_shop01",
      "a3_structures_f_households_house_shop02",
      "a3_structures_f_households_house_small01",
      "a3_structures_f_households_house_small02",
      "a3_structures_f_households_house_small03",
      "a3_structures_f_households_slum",
      "a3_structures_f_households_stone_big",
      "a3_structures_f_households_stone_shed",
      "a3_structures_f_households_stone_small",
      "a3_structures_f_households_wip",
      "a3_structures_f_ind",
      "a3_structures_f_ind_airport",
      "a3_structures_f_ind_cargo",
      "a3_structures_f_ind_carservice",
      "a3_structures_f_ind_concretemixingplant",
      "a3_structures_f_ind_crane",
      "a3_structures_f_ind_dieselpowerplant",
      "a3_structures_f_ind_factory",
      "a3_structures_f_ind_fuelstation",
      "a3_structures_f_ind_fuelstation_small",
      "a3_structures_f_ind_pipes",
      "a3_structures_f_ind_powerlines",
      "a3_structures_f_ind_reservoirtank",
      "a3_structures_f_ind_shed",
      "a3_structures_f_ind_solarpowerplant",
      "a3_structures_f_ind_tank",
      "a3_structures_f_ind_transmitter_tower",
      "a3_structures_f_ind_wavepowerplant",
      "a3_structures_f_ind_windmill",
      "a3_structures_f_ind_windpowerplant",
      "a3_structures_f_items",
      "a3_structures_f_items_cans",
      "a3_structures_f_items_documents",
      "a3_structures_f_items_electronics",
      "a3_structures_f_items_gadgets",
      "a3_structures_f_items_luggage",
      "a3_structures_f_items_medical",
      "a3_structures_f_items_military",
      "a3_structures_f_items_stationery",
      "a3_structures_f_items_tools",
      "a3_structures_f_items_valuables",
      "a3_structures_f_items_vessels",
      "a3_structures_f_kart_civ_sportsgrounds",
      "a3_structures_f_kart_mil_flags",
      "a3_structures_f_kart_signs_companies",
      "a3_structures_f_mil",
      "a3_structures_f_mil_bagbunker",
      "a3_structures_f_mil_bagfence",
      "a3_structures_f_mil_barracks",
      "a3_structures_f_mil_bunker",
      "a3_structures_f_mil_cargo",
      "a3_structures_f_mil_flags",
      "a3_structures_f_mil_fortification",
      "a3_structures_f_mil_helipads",
      "a3_structures_f_mil_offices",
      "a3_structures_f_mil_radar",
      "a3_structures_f_mil_scrapyard",
      "a3_structures_f_mil_shelters",
      "a3_structures_f_mil_tenthangar",
      "a3_structures_f_naval",
      "a3_structures_f_naval_buoys",
      "a3_structures_f_naval_fishing",
      "a3_structures_f_naval_piers",
      "a3_structures_f_naval_rowboats",
      "a3_structures_f_research",
      "a3_structures_f_signs_companies",
      "a3_structures_f_system",
      "a3_structures_f_training",
      "a3_structures_f_training_invisibletarget",
      "a3_structures_f_walls",
      "a3_structures_f_wrecks",
      "a3_supplies_f_heli",
      "a3_supplies_f_heli_bladders",
      "a3_supplies_f_heli_cargonets",
      "a3_supplies_f_heli_fuel",
      "a3_supplies_f_heli_slingload",
      "a3_uav_f_characters_f_gamma",
      "a3_uav_f_weapons_f_gamma_ammoboxes",
      "a3_ui_f",
      "a3_ui_f_bootcamp",
      "a3_ui_f_curator",
      "a3_ui_f_heli",
      "a3_ui_f_kart",
      "a3_uifonts_f",
      "a3_weapons_f",
      "a3_weapons_f_aaf",
      "a3_weapons_f_acc",
      "a3_weapons_f_ammoboxes",
      "a3_weapons_f_beta",
      "a3_weapons_f_beta_acc",
      "a3_weapons_f_beta_ammoboxes",
      "a3_weapons_f_beta_ebr",
      "a3_weapons_f_beta_rifles_khaybar",
      "a3_weapons_f_beta_rifles_mx",
      "a3_weapons_f_beta_rifles_trg20",
      "a3_weapons_f_bootcamp",
      "a3_weapons_f_bootcamp_ammoboxes",
      "a3_weapons_f_bootcamp_longrangerifles_gm6",
      "a3_weapons_f_bootcamp_longrangerifles_m320",
      "a3_weapons_f_csat",
      "a3_weapons_f_dummyweapons",
      "a3_weapons_f_ebr",
      "a3_weapons_f_epa",
      "a3_weapons_f_epa_acc",
      "a3_weapons_f_epa_ammoboxes",
      "a3_weapons_f_epa_ebr",
      "a3_weapons_f_epa_longrangerifles_dmr_01",
      "a3_weapons_f_epa_longrangerifles_gm6",
      "a3_weapons_f_epa_rifles_mx",
      "a3_weapons_f_epb",
      "a3_weapons_f_epb_acc",
      "a3_weapons_f_epb_ammoboxes",
      "a3_weapons_f_epb_longrangerifles_gm3",
      "a3_weapons_f_epb_longrangerifles_m320",
      "a3_weapons_f_epb_rifles_mx_black",
      "a3_weapons_f_epc",
      "a3_weapons_f_explosives",
      "a3_weapons_f_fia",
      "a3_weapons_f_gamma",
      "a3_weapons_f_gamma_acc",
      "a3_weapons_f_gamma_ammoboxes",
      "a3_weapons_f_gamma_items",
      "a3_weapons_f_headgear",
      "a3_weapons_f_itemholders",
      "a3_weapons_f_items",
      "a3_weapons_f_kart",
      "a3_weapons_f_kart_pistols_pistol_signal_f",
      "a3_weapons_f_launchers_law",
      "a3_weapons_f_launchers_nlaw",
      "a3_weapons_f_launchers_titan",
      "a3_weapons_f_longrangerifles_gm6",
      "a3_weapons_f_longrangerifles_m320",
      "a3_weapons_f_machineguns_m200",
      "a3_weapons_f_machineguns_zafir",
      "a3_weapons_f_nato",
      "a3_weapons_f_pistols_acpc2",
      "a3_weapons_f_pistols_p07",
      "a3_weapons_f_pistols_pdw2000",
      "a3_weapons_f_pistols_pistol_heavy_01",
      "a3_weapons_f_pistols_pistol_heavy_02",
      "a3_weapons_f_pistols_rook40",
      "a3_weapons_f_rifles_khaybar",
      "a3_weapons_f_rifles_mk20",
      "a3_weapons_f_rifles_mx",
      "a3_weapons_f_rifles_sdar",
      "a3_weapons_f_rifles_smg_02",
      "a3_weapons_f_rifles_trg20",
      "a3_weapons_f_rifles_vector",
      "a3_weapons_f_uniforms",
      "a3_weapons_f_vests",
      "a3data",
      "cba_xeh",
      "extended_eventhandlers",
      "cba_extended_eventhandlers"
    };
    version = "0.95.2";
    versionStr = "0.95.2";
    versionAr[] = {0,95,2};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Core {
    class AGM_Core {
      file = "AGM_Core\functions";
      class addActionEventHandler;
      class addActionMenuEventHandler;
      class addCameraEventHandler;
      class addCustomEventHandler;
      class addInfoDisplayEventHandler;
      class addMapMarkerCreatedEventHandler;
      class addInventoryDisplayLoadedEventHandler;
      class addScrollWheelEventHandler;
      class adminKick;
      class ambientBrightness;
      class applyForceWalkStatus;
      class binarizeNumber;
      class callCustomEventHandlers;
      class callCustomEventHandlersGlobal;
      class canGetInPosition;
      class canInteractWith;
      class canUseWeapon;
      class changeProjectileDirection;
      class checkPBOs;
      class claim;
      class closeDialogIfTargetMoves;
      class codeToLetter;
      class codeToString;
      class convertKeyCode;
      class currentChannel;
      class disableUserInput;
      class displayText;
      class displayTextPicture;
      class displayTextStructured;
      class doAnimation;
      class endRadioTransmission;
      class execPersistentFnc;
      class execRemoteFnc;
      class executePersistent;
      class filter;
      class fixLoweredRifleAnimation;
      class getCaptivityStatus;
      class getConfigCommander;
      class getConfigGunner;
      class getDefaultAnim;
      class getDoorTurrets;
      class getForceWalkStatus;
      class getHitPoints;
      class getHitPointsWithSelections;
      class getInPosition;
      class getMarkerType;
      class getName;
      class getNumberFromMissionSQM;
      class getPitchBankYaw;
      class getStringFromMissionSQM;
      class getTargetAzimuthAndInclination;
      class getTargetDistance;
      class getTargetObject;
      class getTurretCommander;
      class getTurretConfigPath;
      class getTurretCopilot;
      class getTurretGunner;
      class getTurretIndex;
      class getTurrets;
      class getTurretsFFV;
      class getTurretsOther;
      class getUavControlPosition;
      class getVehicleCargo;
      class getVehicleCodriver;
      class getVehicleCrew;
      class getWeaponAzimuthAndInclination;
      class getWeaponType;
      class getWindDirection;
      class goKneeling;
      class hadamardProduct;
      class interpolateFromArray;
      class inTransitionAnim;
      class isAutoWind;
      class isEngineer;
      class isEOD;
      class isInBuilding;
      class isMedic;
      class isPlayer;
      class isTurnedOut;
      class letterToCode;
      class map;
      class moduleCheckPBOs;
      class moduleLSDVehicles;
      class muteUnit;
      class numberToDigits;
      class numberToDigitsString;
      class onLoadRscDisplayChannel;
      class owned;
      class player;
      class playerSide;
      class progressBar;
      class queueAnimation;
      class readBooleanParameterFromModule;
      class readNumericParameterFromModule;
      class removeActionEventHandler;
      class removeActionMenuEventHandler;
      class removeCameraEventHandler;
      class removeCustomEventHandler;
      class removeInfoDisplayEventHandler;
      class removeInventoryDisplayLoadedEventHandler;
      class removeMapMarkerCreatedEventHandler;
      class removeScrollWheelEventHandler;
      class restoreVariablesJIP;
      class revertKeyCodeLocalized;
      class sanitizeString;
      class serverLog;
      class setCaptivityStatus;
      class setForceWalkStatus;
      class setKeyDefault;
      class setName;
      class setParameter;
      class setPitchBankYaw;
      class setVariableJIP;
      class stringToColoredText;
      class subString;
      class toBin;
      class toBitmask;
      class toHex;
      class toNumber;
      class unmuteUnit;
    };
  };
  class AGM_Debug {
    class AGM_Debug {
      file = "AGM_Core\functions\Debug";
      class exportConfig;
      class getChildren;
      class getDisplayConfigName;
      class log;
      class logControls;
      class logDisplays;
      class monitor;
      class showUser;
    };
  };
  class AGM_CuratorFix {
    class AGM_CuratorFix {
      file = "AGM_Core\functions\CuratorFix";
      class addUnloadEventhandler;
      class fixCrateContent;
    };
  };
};

class CfgSounds {
  class AGM_Sound_Click {
    sound[] = {"\AGM_Core\sounds\AGM_click.wav", 1, 1, 200};
    titles[] = {};
  };
};

class Extended_PreInit_EventHandlers {
  class AGM_Core {
    init = "call compile preprocessFileLineNumbers '\AGM_Core\preInit.sqf'";
    serverInit = "call compile preprocessFileLineNumbers '\AGM_Core\scripts\readParameters.sqf'";
    disableModuload = true;
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Core {
    init = "call compile preprocessFileLineNumbers '\AGM_Core\init.sqf'";
    disableModuload = true;
  };
};

class Extended_InitPost_EventHandlers {
  class All {
    class AGM_Core_executePersistent {
      init = "[_this select 0] call AGM_Core_fnc_executePersistent";
    };
  };
  class CAManBase {
    class AGM_Core_setName {
      init = "if (local (_this select 0)) then {_this call AGM_Core_fnc_setName};";
    };
    class AGM_Core_forceWalk {
      init = "if (local (_this select 0)) then {_this call AGM_Core_fnc_applyForceWalkStatus;};";
    };
  };
};

class Extended_Respawn_EventHandlers {
  class All {
    class AGM_Core_restoreVariablesJIP {
      respawn = "_this call AGM_Core_fnc_restoreVariablesJIP";
    };
    class AGM_Core_setName {
      respawn = "_this call AGM_Core_fnc_setName";
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
  /*class Man;
  class CAManBase: Man {
    // @todo
    class UserActions {
      class AGM_Fire {
        displayName = "";
        priority = -99;
        available = 1;
        radius = 2.5;
        radiusView = 0;
        position = "";
        showWindow = 0;
        showIn3D = 0;
        onlyForPlayer = 1;
        shortcut = "DefaultAction";
        condition = "call AGM_Core_UserActionFireCondition";
        statement = "call AGM_Core_UserActionFire";
        userActionID = 100;
      };
    };
  };*/

  // += needs a non inherited entry in that class, otherwise it simply overwrites
  //#include <DefaultItems.hpp>

  class Module_F;
  class AGM_ModuleCheckPBOs: Module_F {
    author = "$STR_AGM_Core_AGMTeam";
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
      class CheckAll {
        displayName = "Check all addons";
        description = "Check all addons instead of only those of AGM?";
        typeName = "BOOL";
        class values {
          class WarnOnce {
            default = 1;
            name = "No";
            value = 0;
          };
          class Warn {
            name = "Yes";
            value = 1;
          };
        };
      };
      class Whitelist {
        displayName = "Whitelist";
        description = "What addons are allowed regardless?";
        typeName = "STRING";
        class values {
            default = "[]";
        };
      };
    };
  };

  class AGM_ModuleLSDVehicles: Module_F {
    author = "$STR_AGM_Core_AGMTeam";
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
    author = "$STR_AGM_Core_AGMTeam";
    displayName = "$STR_AGM_Core_MiscItems";
    transportMaxWeapons = 9001;
    transportMaxMagazines = 9001;
    transportMaxItems = 9001;
    maximumload = 2000;

    class TransportWeapons {};
    class TransportMagazines {};
    class TransportItems {};
    class TransportBackpacks {};
  };
};

class CfgWeapons {
  class ItemCore;
  class AGM_ItemCore: ItemCore {
    type = 4096;//4;
    detectRange = -1;
    simulation = "ItemMineDetector";
  };

  class Rifle_Base_F;
  class AGM_FakePrimaryWeapon: Rifle_Base_F {
    discreteDistance[] = {};
    discreteDistanceInitIndex = 0;
    displayName = "";
    picture = "";
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

class AGM_Core_canInteractConditions {
  class AGM_Core_notOnMap {
    condition = "!visibleMap";
  };
};

class AGM_Core_Options {
  class enableNumberHotkeys {
    displayName = "$STR_AGM_Core_EnableNumberHotkeys";
    default = 1;
  };
};

#include <MainMenu.hpp>
#include <MenuConfig.hpp>
#include <ProgressScreen.hpp>
#include <HintConfig.hpp>

/*
class RscControlsGroupNoScrollbars; 
class RscAttributeInventory: RscControlsGroupNoScrollbars {
  onSetFocus = "[_this,""RscAttributeInventory"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute""); _this select 0 call AGM_CuratorFix_fnc_addUnloadEventhandler;";
};
*/

#include <RscInfoType.hpp>
#include <FixPickup.hpp>
#include <FixAnimations.hpp>
#include <NoVoice.hpp>
