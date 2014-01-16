class CfgPatches {
  class BWA3_Vehicles {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, A3_Anims_F};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "http://www.bwmod.de";
  };
};

class CfgMods {
  class BWA3_Vehicles {
    dir = "BWA3_Vehicles";
    name = "BWA3: Vehicle Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Website";
    action = "http://www.bwmod.de";
  };
};

class Mode_Burst;

// Manual Switching Of Flare Mode
class CfgWeapons {
  class SmokeLauncher;

  class CMFlareLauncher: SmokeLauncher {
    modes[] = {"Single", "Burst", "AIBurst"};
    class Burst: Mode_Burst {
      displayName = "Burst";
    };
  };
};


class CfgVehicles {

  // BLUFOR
  class B_MRAP_01_F {
    displayName = "M-ATV";
  };
  class B_MRAP_01_hmg_F {
    displayName = "M-ATV (HMG)";
  };
  class B_MRAP_01_gmg_F {
    displayName = "M-ATV (GMG)";
  };
  class B_MBT_01_cannon_F {
    displayName = "Merkava Mk IV";
  };
  class B_MBT_01_arty_F {
    displayName = "Sholef";
  };
  class B_MBT_01_mlrs_F {
    displayName = "Seara";
  };
  class B_APC_Tracked_01_rcws_F {
    displayName = "Namer";
  };
  class B_APC_Tracked_01_AA_F {
    displayName = "Bardelas";
  };
  class B_APC_Wheeled_01_cannon_F {
    displayName = "Patria AMV";
  };
  class B_APC_Tracked_01_CRV_F {
    displayName = "Nemmera";
  };
  class B_Truck_01_ammo_F {
    displayName = "HEMTT (Ammo)";
  };
  class B_Truck_01_fuel_F {
    displayName = "HEMTT (Fuel)";
  };
  class B_Truck_01_medical_F {
    displayName = "HEMTT (Medical)";
  };
  class B_Truck_01_Repair_F {
    displayName = "HEMTT (Repair)";
  };

  // INDEP
  class I_MRAP_03_F {
    displayName = "Fennek";
  };
  class I_MRAP_03_hmg_F {
    displayName = "Fennek (HMG)";
  };
  class I_MRAP_03_gmg_F {
    displayName = "Fennek (GMG)";
  };
  class I_Truck_02_transport_F {
    displayName = "Kamaz";
  };
  class I_Truck_02_covered_F {
    displayName = "Kamaz (Covered)";
  };
  class I_MBT_03_cannon_F {
    displayName = "MBT Revolution";
  };
  class I_APC_tracked_03_cannon_F {
    displayName = "FV510 Warrior";
  };
  class I_APC_Wheeled_03_cannon_F {
    displayName = "Pandur II";
  };
  class I_Truck_02_ammo_F {
    displayName = "Kamaz (Ammo)";
  };
  class I_Truck_02_fuel_F {
    displayName = "Kamaz (Fuel)";
  };
  class I_Truck_02_medical_F {
    displayName = "Kamaz (Medical)";
  };
  class I_Truck_02_box_F {
    displayName = "Kamaz (Repair)";
  };

  //OPFOR
  class O_MRAP_02_F {
    displayName = "Punisher";
  };
  class O_MRAP_02_hmg_F {
    displayName = "Punisher (HMG)";
  };
  class O_MRAP_02_gmg_F {
    displayName = "Punisher (GMG)";
  };
  class O_Truck_02_transport_F {
    displayName = "Kamaz";
  };
  class O_Truck_02_covered_F {
    displayName = "Kamaz (Covered)";
  };
  class O_MBT_02_cannon_F {
    displayName = "T100 Black Eagle";
  };
  class O_MBT_02_arty_F {
    displayName = "2S9 Sochor";
  };
  class O_APC_Tracked_02_cannon_F {
    displayName = "BMP-K Kamysh";
  };
  class O_APC_Tracked_02_AA_F {
    displayName = "ZSU-39 Tigris";
  };
  class O_APC_Wheeled_02_rcws_F {
    displayName = "Arma";
  };
  class O_Truck_02_Ammo_F {
    displayName = "Kamaz (Ammo)";
  };
  class O_Truck_02_fuel_F {
    displayName = "Kamaz (Fuel)";
  };
  class O_Truck_02_medical_F {
    displayName = "Kamaz (Medical)";
  };
  class O_Truck_02_box_F {
    displayName = "Kamaz (Repair)";
  };
};