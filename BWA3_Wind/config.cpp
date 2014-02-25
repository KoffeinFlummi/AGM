class CfgPatches {
  class BWA3_Wind {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, A3_Anims_F};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
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