class CfgPatches {
  class AGM_Overheat {
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
  class AGM_Overheat {
    class AGM_Overheat {
        file = "\AGM_overheat\functions";
      class firedEH {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Overheat {
    clientInit = "execVM '\AGM_overheat\init.sqf'";
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Overheat {
      clientFired = "if (player == (_this select 0)) then {_this call AGM_Overheat_fnc_firedEH}";
    };
  };
};

class AGM_Core_Default_Keys {
  class clearJam {
    displayName = "Unjam weapon";
    condition = "AGM_isWeaponJammed";
    statement = "call AGM_Overheat_clearJam";
    key = 19;
    shift = 1;
    control = 0;
    alt = 0;
  };
};

/*class CfgVehicles {
  class Man;
  class Land_CargoBox_V1_F;
  class ReammoBox;

  class CAManBase: Man {
    class AGM_Actions {
      class AGM_JoinGroup {
        displayName = "$STR_AGM_JoinGroup";
        distance = 4;
        condition = "playerSide == side AGM_Interaction_Target && {group player != group AGM_Interaction_Target}";
        statement = "[player] joinSilent group AGM_Interaction_Target;";
        showDisabled = 1;
        priority = -1;
      };
      class AGM_TapShoulder {
        displayName = "$STR_AGM_TapShoulder";
        distance = 4;
        condition = "playerSide == side AGM_Interaction_Target and alive AGM_Interaction_Target and !(AGM_Interaction_Target getVariable ['AGM_Unconscious', false])";
        statement = "[[player], 'AGM_Interaction_fnc_tapShoulder', AGM_Interaction_Target] call AGM_Core_fnc_execRemoteFnc";
        showDisabled = 1;
        priority = 0.1;
      };
    };
  };
};*/

class CfgWeapons {
  class PistolCore;
  class RifleCore;
  class MGunCore;

  class Pistol: PistolCore {
    AGM_Overheat_Increment = 0.03;
    AGM_Overheat_Cooldown = 0.002;
  };

  class Rifle: RifleCore {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
  };

  class MGun: MGunCore {
    AGM_Overheat_Increment = 0.01;
    AGM_Overheat_Cooldown = 0.002;
  };
};
