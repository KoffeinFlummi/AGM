class CfgPatches {
  class AGM_Respawn {
    units[] = {};
    weapons[] = {"AGM_Rallypoint_West", "AGM_Rallypoint_East", "AGM_Rallypoint_Independant", "AGM_RallypointExit_West", "AGM_RallypointExit_East", "AGM_RallypointExit_Independant"};
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
      class moveRallypoint;
      class removeBody;
      class restoreGear;
      class teleportToRallypoint;
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
    icon = "\AGM_Respawn\UI\IconRespawn_ca.paa";
    class Arguments {
      class SavePreDeathGear {
        displayName = "Save Gear?";
        description = "Respawn with the gear a soldier had just before his death?";
        typeName = "BOOL";
        class values {
          class Yes { name = "Yes"; value = 1;};
          class No { default = 1; name = "No"; value = 0; };
        };
      };
      class RemoveDeadBodies {
        displayName = "Remove bodies?";
        description = "Remove player bodies after respawn?";
        typeName = "BOOL";
        class values {
          class Yes { default = 1; name = "Yes"; value = 1;};
          class No { name = "No"; value = 0; };
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
/*
  // rallypoints
  class FlagCarrier;
  class Flag_NATO_F: FlagCarrier {
    class AGM_Actions;
  };

  class Flag_CSAT_F: FlagCarrier {
    class AGM_Actions;
  };

  class Flag_AAF_F: FlagCarrier {
    class AGM_Actions;
  };

  // static
  class AGM_Rallypoint_West: Flag_NATO_F {
    class AGM_Actions: AGM_Actions {
      class AGM_Teleport {
        displayName = "Teleport to Rallypoint";
        distance = 4;
        condition = "playerSide == west";
        statement = "[player, false] call AGM_Respawn_fnc_teleportToRallypoint;";
        showDisabled = 1;
        priority = 1;
      };
    };
  };

  class AGM_Rallypoint_East: Flag_CSAT_F {
    class AGM_Actions: AGM_Actions {
      class AGM_Teleport {
        displayName = "Teleport to Rallypoint";
        distance = 4;
        condition = "playerSide == east";
        statement = "[player, false] call AGM_Respawn_fnc_teleportToRallypoint;";
        showDisabled = 1;
        priority = 1;
      };
    };
  };

  class AGM_Rallypoint_Independant: Flag_AAF_F {
    class AGM_Actions: AGM_Actions {
      class AGM_Teleport {
        displayName = "Teleport to Rallypoint";
        distance = 4;
        condition = "playerSide == independant";
        statement = "[player, false] call AGM_Respawn_fnc_teleportToRallypoint;";
        showDisabled = 1;
        priority = 1;
      };
    };
  };

  // moveable
  class AGM_RallypointExit_West: Flag_NATO_F {
    class AGM_Actions: AGM_Actions {
      class AGM_Teleport {
        displayName = "Teleport to Base";
        distance = 4;
        condition = "playerSide == west";
        statement = "[player, true] call AGM_Respawn_fnc_teleportToRallypoint;";
        showDisabled = 1;
        priority = 1;
      };
    };
  };

  class AGM_RallypointExit_East: Flag_CSAT_F {
    class AGM_Actions: AGM_Actions {
      class AGM_Teleport {
        displayName = "Teleport to Base";
        distance = 4;
        condition = "playerSide == east";
        statement = "[player, true] call AGM_Respawn_fnc_teleportToRallypoint;";
        showDisabled = 1;
        priority = 1;
      };
    };
  };

  class AGM_RallypointExit_Independant: Flag_AAF_F {
    class AGM_Actions: AGM_Actions {
      class AGM_Teleport {
        displayName = "Teleport to Base";
        distance = 4;
        condition = "playerSide == independant";
        statement = "[player, true] call AGM_Respawn_fnc_teleportToRallypoint;";
        showDisabled = 1;
        priority = 1;
      };
    };
  };

  // team leader
  class Man;
  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_MoveRallypoint {
        displayName = "Move Rallypoint";
        condition = "playerSide in [west, east, independant]";
        statement = "[player, playerSide] call AGM_Respawn_fnc_moveRallypoint;";
        showDisabled = 0;
        priority = 0.5;
      };
    };
  };
};

//init rallypoints
class Extended_Init_EventHandlers {
  class AGM_Rallypoint_West {
    class AGM_InitRallypoint {
      serverInit = "_oldFlag = missionNamespace getVariable 'AGM_Rallypoint'";
    };
  };
};

AGM_Rallypoint_West
AGM_Rallypoint_East
AGM_Rallypoint_Independant
AGM_RallypointExit_West
AGM_RallypointExit_East
AGM_RallypointExit_Independant
*/
