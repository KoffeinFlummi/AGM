class CfgPatches {
  class AGM_Hearing {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = 0.7;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Hearing {
    clientInit = "execVM '\AGM_Hearing\init.sqf'";
  };
};
