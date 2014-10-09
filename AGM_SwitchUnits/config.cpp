class CfgPatches {
  class AGM_SwitchUnits {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.931";
    versionStr = "0.931";
    versionAr[] = {0,931,0};
    author[] = {"jodav"};
    authorUrl = "https://github.com/jodav/";
  };
};

class CfgFunctions {
  class AGM_SwitchUnits {
    class AGM_SwitchUnits {
      file = "AGM_SwitchUnits\functions";
      class addMapFunction;
      class handleMapClick;
      class initPlayer;
      class markAiOnMap;
      class module;
      class switchUnit;
    };
  };
};


class Extended_PostInit_EventHandlers {
  class AGM_SwitchUnits {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_SwitchUnits\clientInit.sqf'";
  };
};


class CfgVehicles {
  class Module_F;
  class AGM_ModuleSwitchUnits: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "SwitchUnits System";
    function = "AGM_SwitchUnits_fnc_module";
    scope = 2;
    isGlobal = 1;
    //icon = "\AGM_SwitchUnits\UI\IconSwitchUnits_ca.paa";
    class Arguments {
      class EnableSwitchUnits {
        displayName = "Enable SwitchUnits?";
        description = "Enable to switch to AI units? Default: No";
        typeName = "BOOL";
        class values {
          class Yes {name = "Yes"; value = 1;};
          class No {default = 1; name = "No"; value = 0;};
        };
      };
      class SwitchUnitsAllowedForSide {
        displayName = "Allow for which side?";
        description = "Which side should be allowed to switch to AI units?";
        typeName = "NUMBER";
        class values {
          class West {name = "West"; value = 0;};
          class East {default = 1; name = "East"; value = 1;};
          class Independent {name = "Independent"; value = 2;};
          class Civilian {name = "Civilian"; value = 3;};
        };
      };
    };
  };
};

class AGM_Parameters {
  AGM_SwitchUnits_EnableSwitchUnits = 0;
  AGM_SwitchUnits_SwitchUnitsAllowedForSide = "east";
};
