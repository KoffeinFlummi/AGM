class CfgPatches {
  class AGM_Wirecutter {
  units[] = {};
  weapons[] = {};
  requiredVersion = 0.60;
  requiredAddons[] = {A3_Functions_F, Extended_Eventhandlers, AGM_Core, AGM_Interaction};
  version = "0.9";
  versionStr = "0.9";
  versionAr[] = {0,9,0};
  author[] = {"gpgpgpgp"};
  authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Wirecutter {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Wirecutter\clientInit.sqf'";
  };
};

class CfgVehicles {
  class Wall_F;
  class Land_Net_Fence_4m_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_Net_Fence_8m_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[10, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_Net_FenceD_8m_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_New_WiredFence_5m_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_New_WiredFence_10m_Dam_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_New_WiredFence_10m_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[10, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_Pipe_fence_4m_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_Pipe_fence_4mNoLC_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_SportGround_fence_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_Wired_Fence_4m_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_Wired_Fence_4mD_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_Wired_Fence_8m_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[10, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class Land_Wired_Fence_8mD_F: Wall_F {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
  class NonStrategic;
  class Land_Razorwire_F: NonStrategic {
    class AGM_Actions {
      class AGM_Wirecutter_cut {
        displayName = "$STR_AGM_CutFence";
        distance = 4;
        condition = "!AGM_Wirecutter_isCutting && {'ToolKit' in items player} && {damage AGM_Interaction_Target < 1}";
        statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_CutdownFence";
        showDisabled = 1;
        priority = 2.1;
      };
    };
  };
};

class CfgSounds {
  class AGM_Wirecutter_sound {
    name = "AGM_wirecutter_sound";
    sound[] = {"AGM_wirecutter\sound\wire_cut.ogg", "db-0", 1};
    titles[] = {};
  };
  class AGM_Wirecutter_sound_long {
    name = "AGM_wirecutter_sound_long";
    sound[] = {"AGM_wirecutter\sound\wire_cut_long.ogg", "db-0", 1};
    titles[] = {};
  };
};
