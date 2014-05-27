class CfgPatches {
  class AGM_Grenades {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Grenades {
    class AGM_Grenades {
      file = "\AGM_Grenades\functions";
      class firedEH {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Grenades {
    clientInit = "execVM '\AGM_Grenades\init.sqf'";
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Grenades {
      clientFired = "if (player == (_this select 0)) then {_this call AGM_Grenades_fnc_firedEH}";
    };
  };
};

class AGM_Core_Default_Keys {
  class switchGrenadeMode {
    displayName = "$STR_AGM_Grenades_SwitchGrenadeMode";
    condition = "player == vehicle player";
    statement = "call AGM_Grenades_nextMode";
    key = 34;
    shift = 0;
    control = 0;
    alt = 1;
  };
};
