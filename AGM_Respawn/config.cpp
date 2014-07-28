class CfgPatches {
  class AGM_Respawn {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"jodav"};
    authorUrl = "https://github.com/jodav/";
  };
};

class CfgFunctions {
  class AGM_Respawn {
    class AGM_Respawn {
      file = "AGM_Respawn\functions";
      class getAllGear;
      class module;
      class removeBody;
      class restoreGear;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Respawn {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Respawn\clientInit.sqf'";
  };
};

class CfgVehicles {
  class Module_F;
  class AGM_ModuleRespawn: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "Respawn System";
    function = "AGM_Respawn_fnc_module";
    scope = 2;
    isGlobal = 1;
    class Arguments {
      class SavePreDeathGear {
        displayName = "Save Gear?";
        description = "Respawn with the gear a soldier had just before his death?";
        typeName = "BOOL";
        class values {
          class Yes {
            name = "Yes";
            value = 1;
          };
          class No {
            default = 1;
            name = "No";
            value = 0;
          };
        };
      };
      class BodyRemoveTimer {
        displayName = "Time to remove bodies.";
        description = "The amount of time (in seconds) after that a unit's body gets removed. Default: 90";
        typeName = "NUMBER";
        defaultValue = 90;
      };
    };
  };
};
