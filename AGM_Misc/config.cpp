class CfgPatches {
  class AGM_Misc {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

/* deactivated temporarily, cause too lazy to fix bugs
class Extended_PostInit_EventHandlers {
  class BWA3_Misc {
    clientInit = "call compile preprocessFileLineNumbers '\BWA3_Misc\clientInit.sqf'";
  };
};

class CfgMagazines {
  class CA_Magazine;

  class B_IR_Grenade: CA_Magazine {
    displayName = "IR Strobe [NATO]";
    displayNameShort = "IR Strobe";
  };
  class I_IR_Grenade: B_IR_Grenade {
    displayName = "IR Strobe [AAF]";
    displayNameShort = "IR Strobe";
  };
  class O_IR_Grenade: B_IR_Grenade {
    displayName = "IR Strobe [CSAT]";
    displayNameShort = "IR Strobe";
  };
};
*/
