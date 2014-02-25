class CfgPatches {
  class BWA3_Goggles {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class BWA3_Goggles {
    class BWA3_Goggles {
        file = "\bwa3_goggles\functions";
      class gogglesEffect {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Goggles {
    clientInit = "execVM '\bwa3_goggles\init.sqf'";
  };
};

class CfgGlasses {
  class None;

  class G_Aviator: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Combat: None {
    BWA3_gogglesEffect = "[1, 1, -0.1, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  /* // CHECK FOR PLAYER BEING IN THE WATER; ADD BLUR AT THE EDGE OF THE SCREEN
  class G_Diving: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  */
  class G_Lowprofile: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Shades_Black: None {
    BWA3_gogglesEffect = "[1, 1, -0.12, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Shades_Blue: None {
    BWA3_gogglesEffect = "[1, 1, -0.03, [0,0,1,0.1], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Shades_Green: None {
    BWA3_gogglesEffect = "[1, 1, -0.03, [0,1,0,0.07], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Shades_Red: None {
    BWA3_gogglesEffect = "[1, 1, -0.03, [1,0,0,0.07], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Spectacles: None {
    BWA3_gogglesEffect = "[1, 1, -0.08, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Spectacles_Tinted: None {
    BWA3_gogglesEffect = "[1, 1, -0.12, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Sport_Blackred: None {
    BWA3_gogglesEffect = "[1, 1, -0.07, [1,0,0,0.08], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_BlackWhite: None {
    BWA3_gogglesEffect = "[1, 1, -0.05, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_Blackyellow: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0.5,0.5,0,0.2], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_Checkered: None {
    BWA3_gogglesEffect = "[1, 1, -0.05, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_Greenblack: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0,0.5,0,0.2], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Sport_Red: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0.4,0,0,0.2], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Squares: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Squares_Tinted: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };

  class G_Tactical_Black: None {
    BWA3_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
  class G_Tactical_Clear: None {
    BWA3_gogglesEffect = "[1, 1, -0.08, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
  };
};