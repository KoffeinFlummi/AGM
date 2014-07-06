class CfgPatches {
  class AGM_VehicleNames {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {
      AGM_Core,
      A3_Armor_F,
      A3_Armor_F_AMV,
      A3_Armor_F_APC_Wheeled_03,
      A3_armor_f_beta,
      A3_armor_f_beta_APC_Tracked_02,
      A3_armor_F_EPB_APC_tracked_03,
      A3_Armor_F_EPB_MBT_03,
      A3_Armor_F_Marid,
      A3_Armor_F_Panther,
      A3_Armor_F_Slammer,
      A3_Armor_F_T100K,
      A3_Soft_F,
      A3_Soft_F_MRAP_01,
      A3_Soft_F_MRAP_02,
      A3_Soft_F_MRAP_03,
      A3_Soft_F_HEMTT,
      A3_Soft_F_TruckHeavy,
      A3_Soft_F_EPC_Truck_03
    };
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgVehicles {
  // Global Inheritance
  class StaticMGWeapon;
  class GMG_TriPod;
  class AT_01_base_F;
  class AA_01_base_F;

  // BLUFOR Inheritance
  class MRAP_01_base_F;
  class MRAP_01_gmg_base_F: MRAP_01_base_F {};
  class MRAP_01_hmg_base_F: MRAP_01_gmg_base_F {};
  class MBT_01_base_F;
  class B_MBT_01_base_F: MBT_01_base_F {};
  class MBT_01_arty_base_F: MBT_01_base_F {};
  class B_MBT_01_arty_base_F: MBT_01_arty_base_F {};
  class MBT_01_mlrs_base_F: MBT_01_base_F {};
  class B_MBT_01_mlrs_base_F: MBT_01_mlrs_base_F {};
  class B_APC_Wheeled_01_base_F;
  class B_APC_Tracked_01_base_F;
  class Truck_01_base_F;
  class Heli_Attack_01_base_F;
  class Heli_Light_01_base_F;
  class Heli_Light_01_armed_base_F;
  class Plane_CAS_01_base_F;

  // INDEP Inheritance
  class MRAP_03_base_F;
  class MRAP_03_hmg_base_F: MRAP_03_base_F {};
  class MRAP_03_gmg_base_F: MRAP_03_hmg_base_F {};
  class I_MBT_03_base_F;
  class I_APC_Wheeled_03_base_F;
  class I_APC_tracked_03_base_F;
  class Truck_02_base_F;
  class I_Heli_light_03_base_F;
  class I_Heli_light_03_unarmed_base_F;
  class Heli_Transport_02_base_F;
  class Plane_Fighter_03_base_F;

  // OPFOR Inheritance
  class MRAP_02_base_F;
  class MRAP_02_hmg_base_F: MRAP_02_base_F {};
  class MRAP_02_gmg_base_F: MRAP_02_hmg_base_F {};
  class MBT_02_base_F;
  class O_MBT_02_base_F: MBT_02_base_F {};
  class MBT_02_arty_base_F: MBT_02_base_F {};
  class O_MBT_02_arty_base_F: MBT_02_arty_base_F {};
  class O_APC_Wheeled_02_base_F;
  class O_APC_Tracked_02_base_F;
  class Truck_03_base_F;
  class Heli_Light_02_base_F;
  class Plane_CAS_02_base_F;

  ////////////////////////////////////

  // Global
  class HMG_01_base_F: StaticMGWeapon {
    displayName = "$STR_AGM_VehicleNames_HMG_01_Name";
  };
  class HMG_01_A_base_F: HMG_01_base_F {
    displayName = "$STR_AGM_VehicleNames_HMG_01_A_Name";
  };
  class HMG_01_high_base_F: HMG_01_base_F {
    displayName = "$STR_AGM_VehicleNames_HMG_01_high_Name";
  };
  class GMG_01_base_F: GMG_TriPod {
    displayName = "$STR_AGM_VehicleNames_GMG_01_Name";
  };
  class GMG_01_A_base_F: GMG_01_base_F {
    displayName = "$STR_AGM_VehicleNames_GMG_01_A_Name";
  };
  class GMG_01_high_base_F: GMG_01_base_F {
    displayName = "$STR_AGM_VehicleNames_GMG_01_high_Name";
  };

  // BLUFOR
  class B_MRAP_01_F: MRAP_01_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_01_Name";
  };
  class B_MRAP_01_hmg_F: MRAP_01_hmg_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_01_hmg_Name";
  };
  class B_MRAP_01_gmg_F: MRAP_01_gmg_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_01_gmg_Name";
  };

  class B_MBT_01_cannon_F: B_MBT_01_base_F {
    displayName = "$STR_AGM_VehicleNames_MBT_01_cannon_Name";
  };
  class B_MBT_01_TUSK_F: B_MBT_01_cannon_F {
    displayName = "$STR_AGM_VehicleNames_MBT_01_TUSK_Name";
  };
  class B_MBT_01_arty_F: B_MBT_01_arty_base_F {
    displayName = "$STR_AGM_VehicleNames_MBT_01_arty_Name";
  };
  class B_MBT_01_mlrs_F: B_MBT_01_mlrs_base_F {
    displayName = "$STR_AGM_VehicleNames_MBT_01_mlrs_Name"; // Fictional name, (probably wrong) hebrew translation of storm.
  };
  class B_APC_Tracked_01_rcws_F: B_APC_Tracked_01_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_Tracked_01_rcws_Name";
  };
  class B_APC_Tracked_01_AA_F: B_APC_Tracked_01_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_Tracked_01_AA_Name"; // Fictional name, (probably wrong) hebrew translation of cheetah.
  };
  class B_APC_Wheeled_01_cannon_F: B_APC_Wheeled_01_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_Wheeled_cannon_Name";
  };
  class B_APC_Tracked_01_CRV_F: B_APC_Tracked_01_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_Tracked_01_CRV_Name";
  };

  class B_Truck_01_transport_F: Truck_01_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_01_transport_Name";
  };
  class B_Truck_01_covered_F: B_Truck_01_transport_F {
    displayName = "$STR_AGM_VehicleNames_Truck_01_covered_Name";
  };
  class B_Truck_01_mover_F: B_Truck_01_transport_F {
    displayName = "$STR_AGM_VehicleNames_Truck_01_mover_Name";
  };
  class B_Truck_01_box_F: B_Truck_01_mover_F {
    displayName = "$STR_AGM_VehicleNames_Truck_01_box_Name";
  };
  class B_Truck_01_medical_F: B_Truck_01_transport_F {
    displayName = "$STR_AGM_VehicleNames_Truck_01_medical_Name";
  };
  class B_Truck_01_ammo_F: B_Truck_01_mover_F {
    displayName = "$STR_AGM_VehicleNames_Truck_01_ammo_Name";
  };
  class B_Truck_01_fuel_F: B_Truck_01_mover_F {
    displayName = "$STR_AGM_VehicleNames_Truck_01_fuel_Name";
  };
  class B_Truck_01_Repair_F: B_Truck_01_mover_F {
    displayName = "$STR_AGM_VehicleNames_Truck_01_Repair_Name";
  };

  class B_Heli_Attack_01_F: Heli_Attack_01_base_F {
    displayName = "$STR_AGM_VehicleNames_Heli_Attack_01_Name";
  };
  class B_Heli_Light_01_F: Heli_Light_01_base_F {
    displayName = "$STR_AGM_VehicleNames_Heli_Light_01_Name";
  };
  class B_Heli_Light_01_armed_F: Heli_Light_01_armed_base_F {
    displayName = "$STR_AGM_VehicleNames_Heli_Light_01_armed_Name";
  };
  class B_Plane_CAS_01_F: Plane_CAS_01_base_F {
    displayName = "$STR_AGM_VehicleNames_Plane_CAS_01_Name";
  };

  class B_static_AT_F: AT_01_base_F {
    displayName = "$STR_AGM_VehicleNames_static_AT_Name";
  };
  class B_static_AA_F: AA_01_base_F {
    displayName = "$STR_AGM_VehicleNames_static_AA_Name";
  };


  // INDEP
  class I_MRAP_03_F: MRAP_03_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_03_Name";
  };
  class I_MRAP_03_hmg_F: MRAP_03_hmg_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_03_hmg_Name";
  };
  class I_MRAP_03_gmg_F: MRAP_03_gmg_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_03_gmg_Name";
  };

  class I_MBT_03_cannon_F: I_MBT_03_base_F {
    displayName = "$STR_AGM_VehicleNames_MBT_03_cannon_Name";
  };
  class I_APC_tracked_03_cannon_F: I_APC_tracked_03_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_tracked_03_cannon_Name";
  };
  class I_APC_Wheeled_03_cannon_F: I_APC_Wheeled_03_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_Wheeled_03_cannon_Name";
  };

  class I_Truck_02_transport_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_transport_Name";
  };
  class I_Truck_02_covered_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_covered_Name";
  };
  class I_Truck_02_ammo_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_ammo_Name";
  };
  class I_Truck_02_fuel_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_fuel_Name";
  };
  class I_Truck_02_box_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_box_Name";
  };
  class I_Truck_02_medical_F: I_Truck_02_box_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_medical_Name";
  };

  class I_Heli_light_03_F: I_Heli_light_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Heli_light_03_Name";
  };
  class I_Heli_light_03_unarmed_F: I_Heli_light_03_unarmed_base_F {
    displayName = "$STR_AGM_VehicleNames_Heli_light_03_unarmed_Name";
  };
  class I_Heli_Transport_02_F: Heli_Transport_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Heli_Transport_02_Name";
  };
  class I_Plane_Fighter_03_CAS_F: Plane_Fighter_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Plane_Fighter_03_CAS_Name";
  };
  class I_Plane_Fighter_03_AA_F: I_Plane_Fighter_03_CAS_F {
    displayName = "$STR_AGM_VehicleNames_Plane_Fighter_03_AA_Name";
  };

  class I_static_AT_F: AT_01_base_F {
    displayName = "$STR_AGM_VehicleNames_static_AT_Name";
  };
  class I_static_AA_F: AA_01_base_F {
    displayName = "$STR_AGM_VehicleNames_static_AA_Name";
  };


  //OPFOR
  class O_MRAP_02_F: MRAP_02_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_02_Name";
  };
  class O_MRAP_02_hmg_F: MRAP_02_hmg_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_02_hmg_Name";
  };
  class O_MRAP_02_gmg_F: MRAP_02_gmg_base_F {
    displayName = "$STR_AGM_VehicleNames_MRAP_02_gmg_Name";
  };

  class O_MBT_02_cannon_F: O_MBT_02_base_F {
    displayName = "$STR_AGM_VehicleNames_MBT_02_cannon_Name";
  };
  class O_MBT_02_arty_F: O_MBT_02_arty_base_F {
    displayName = "$STR_AGM_VehicleNames_MBT_02_arty_Name";
  };
  class O_APC_Tracked_02_cannon_F: O_APC_Tracked_02_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_Tracked_02_cannon_Name";
  };
  class O_APC_Tracked_02_AA_F: O_APC_Tracked_02_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_Tracked_02_AA_Name";
  };
  class O_APC_Wheeled_02_rcws_F: O_APC_Wheeled_02_base_F {
    displayName = "$STR_AGM_VehicleNames_APC_Wheeled_02_rcws_Name";
  };

  class O_Truck_02_transport_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_transport_Name";
  };
  class O_Truck_02_covered_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_covered_Name";
  };
  class O_Truck_02_ammo_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_ammo_Name";
  };
  class O_Truck_02_fuel_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_fuel_Name";
  };
  class O_Truck_02_box_F: Truck_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_box_Name";
  };
  class O_Truck_02_medical_F: O_Truck_02_box_F {
    displayName = "$STR_AGM_VehicleNames_Truck_02_medical_Name";
  };

  class O_Truck_03_transport_F: Truck_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_03_transport_Name";
  };
  class O_Truck_03_covered_F: Truck_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_03_covered_Name";
  };
  class O_Truck_03_device_F: Truck_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_03_device_Name";
  };
  class O_Truck_03_ammo_F: Truck_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_03_ammo_Name";
  };
  class O_Truck_03_fuel_F: Truck_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_03_fuel_Name";
  };
  class O_Truck_03_repair_F: Truck_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_03_repair_Name";
  };
  class O_Truck_03_medical_F: Truck_03_base_F {
    displayName = "$STR_AGM_VehicleNames_Truck_03_medical_Name";
  };

  class O_Heli_Light_02_F: Heli_Light_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Heli_Light_02_Name";
  };
  class O_Heli_Light_02_unarmed_F: Heli_Light_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Heli_Light_02_unarmed_Name";
  };
  class O_Plane_CAS_02_F: Plane_CAS_02_base_F {
    displayName = "$STR_AGM_VehicleNames_Plane_CAS_02_Name";
  };

  class O_static_AT_F: AT_01_base_F {
    displayName = "$STR_AGM_VehicleNames_static_AT_Name";
  };
  class O_static_AA_F: AA_01_base_F {
    displayName = "$STR_AGM_VehicleNames_static_AA_Name";
  };
};
