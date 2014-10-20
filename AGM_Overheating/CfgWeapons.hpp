  class Rifle;
  class Rifle_Base_F : Rifle {
    //AGM_Overheating_Increment = 0.012;  // How much the weapon heats up for every shot. Max temperature is 3. 0.012 means 250 shots for max temp. Converted to real life values: 0: 10°C, 1: 70°C, 2: 130°C, 3: 170°C.
    //AGM_Overheating_Cooldown = 0.002;   // How fast the weapon cools down every second. 0.002 means 1500 seconds (25 minutes) for a complete cooldown from max temp.
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};  // Dispersion in radians. First value is for temp. 0, second for temp. 1 and so on. Values inbetween get interpolated. Negative values get ignored and can be used to move the starting point to hotter temperatures.
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};        // How much the projectile gets slowed down before leaving the barrel. 0.9 means the bullet will lose 10% velocity. Values inbetween get interpolated. Numbers greater 1 increase the velocity, smaller 1 decrease it.
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};   // Chance to jam the weapon. 0.006 means 60 malfunctions on 10,000 rounds fired at this temperature. Values inbetween get interpolated. Negative values get ignored and can be used to move the starting point to hotter temperatures.
  };

  class Rifle_Long_Base_F : Rifle_Base_F {
    AGM_Overheating_Dispersion[] = {0, -0.001, 0.001, 0.003};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class arifle_MX_Base_F : Rifle_Base_F {
    AGM_clearJamAction = "GestureReloadMX";   // Custom jam clearing action. Default uses reload animation.
    AGM_checkTemperatureAction = "Gear";      // Custom check temperature action. Default uses gear animation.
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class arifle_MX_SW_F : arifle_MX_Base_F {
    AGM_clearJamAction = "";              // Custom jam clearing action. Use empty string to undefine.
    AGM_Overheating_allowSwapBarrel = 1;  // 1 to enable barrel swap. 0 to disable. Meant for machine guns where you can easily swap the barrel without dismantling the whole weapon.
    AGM_Overheating_Dispersion[] = {0, -0.001, 0.001, 0.003};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class arifle_Katiba_Base_F : Rifle_Base_F {
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class mk20_base_F : Rifle_Base_F {
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class Tavor_base_F : Rifle_Base_F {
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class SDAR_base_F : Rifle_Base_F {
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class EBR_base_F : Rifle_Long_Base_F {
    AGM_Overheating_Dispersion[] = {0, -0.001, 0.001, 0.003};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class DMR_01_base_F : Rifle_Long_Base_F {
    AGM_Overheating_Dispersion[] = {0, -0.001, 0.001, 0.003};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class GM6_base_F : Rifle_Long_Base_F {
    AGM_Overheating_Dispersion[] = {0, -0.001, 0.001, 0.003};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class LRR_base_F : Rifle_Long_Base_F {
    AGM_Overheating_Dispersion[] = {0, -0.001, 0.001, 0.003};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class LMG_Mk200_F : Rifle_Long_Base_F {
    AGM_Overheating_allowSwapBarrel = 1;   // 1 to enable barrel swap. 0 to disable. Meant for machine guns where you can easily swap the barrel without dismantling the whole weapon.
    AGM_Overheating_Dispersion[] = {0, -0.001, 0.001, 0.003};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class LMG_Zafir_F : Rifle_Long_Base_F {
    AGM_Overheating_allowSwapBarrel = 1;   // 1 to enable barrel swap. 0 to disable. Meant for machine guns where you can easily swap the barrel without dismantling the whole weapon.
    AGM_Overheating_Dispersion[] = {0, -0.001, 0.001, 0.003};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class SMG_01_Base : Rifle_Base_F {
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class SMG_02_base_F : Rifle_Base_F {
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };

  class pdw2000_base_F : Rifle_Base_F {
    AGM_Overheating_Dispersion[] = {0, 0.001, 0.002, 0.004};
    AGM_Overheating_SlowdownFactor[] = {1, 1, 1, 0.9};
    AGM_Overheating_JamChance[] = {0, 0.0003, 0.0015, 0.0075};
  };