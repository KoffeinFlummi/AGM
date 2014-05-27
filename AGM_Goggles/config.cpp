class CfgPatches {
  class AGM_Goggles {
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
  class AGM_Goggles {
    class AGM_Goggles {
        file = "\AGM_goggles\functions";
      class gogglesEffect {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Goggles {
    clientInit = "execVM '\AGM_goggles\init.sqf'";
  };
};

class CfgGlasses {
  class None;

  class G_Aviator: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Combat: None {
    AGM_gogglesEffect = "[1, 1, -0.1, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  /* // CHECK FOR PLAYER BEING IN THE WATER; ADD BLUR AT THE EDGE OF THE SCREEN
  class G_Diving: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  */
  class G_Lowprofile: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Shades_Black: None {
    AGM_gogglesEffect = "[1, 1, -0.12, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Shades_Blue: None {
    AGM_gogglesEffect = "[1, 1, -0.03, [0,0,1,0.1], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Shades_Green: None {
    AGM_gogglesEffect = "[1, 1, -0.03, [0,1,0,0.07], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Shades_Red: None {
    AGM_gogglesEffect = "[1, 1, -0.03, [1,0,0,0.07], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Spectacles: None {
    AGM_gogglesEffect = "[1, 1, -0.08, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Spectacles_Tinted: None {
    AGM_gogglesEffect = "[1, 1, -0.12, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Sport_Blackred: None {
    AGM_gogglesEffect = "[1, 1, -0.07, [1,0,0,0.08], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_BlackWhite: None {
    AGM_gogglesEffect = "[1, 1, -0.05, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_Blackyellow: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0.5,0.5,0,0.2], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_Checkered: None {
    AGM_gogglesEffect = "[1, 1, -0.05, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_Greenblack: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0,0.5,0,0.2], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_Red: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0.4,0,0,0.2], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Squares: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Squares_Tinted: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Tactical_Black: None {
    AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Tactical_Clear: None {
    AGM_gogglesEffect = "[1, 1, -0.08, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
};