class CfgPatches {
  class AGM_Grenade {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Grenade {
    class AGM_Grenade {
        file = "\AGM_grenade\functions";
      class firedEH {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Grenade {
    clientInit = "execVM '\AGM_grenade\init.sqf'";
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Grenade {
      clientFired = "if (player == (_this select 0)) then {_this call AGM_Grenade_fnc_firedEH}";
    };
  };
};

class AGM_Core_Default_Keys {
  class switchGrenadeMode {
    displayName = "Switch grenade mode";
    condition = "player == vehicle player";
    statement = "call AGM_Grenade_nextMode";
    key = 34;
    shift = 0;
    control = 0;
    alt = 1;
  };
};
