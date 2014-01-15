class CfgPatches {
  class BWA3_Wind {
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
  class BWA3_Wind {
    dir = "BWA3_Wind";
    name = "BWA3: Wind Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Website";
    action = "http://www.bwmod.de";
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Wind {
    clientInit = "call compile preProcessFileLineNumbers '\BWA3_Wind\init.sqf'";
  };
};

class Extended_FiredBIS_EventHandlers {
  class CAManBase {
    class BWA3_Wind {
      clientFiredBISPlayer = "_this spawn BWA3_Wind_fnc_firedEH";
    };
  };
};

class CfgAmmo {
  class Default {
    BWA3_windCoefficient = 1;
  };
  class GrenadeCore: Default {
    BWA3_windCoefficient = 0.2;
  };
};
