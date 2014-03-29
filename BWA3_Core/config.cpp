class CfgPatches {
  class BWA3_Core {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {};
    version = 0.7;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class BWA3_Core {
    class BWA3_Core {
      file = "BWA3_Core\functions";
      class getDirectionVector {};
      class keyInput {};
      class openInteractionMenu {};
      class openSelfMenu {};
      class openMenu {};
      class toBin {};
      class toHex {};
      class addVector {};
      class subtractVector {};
      class scaleVector {};
      class scalarProduct {};
      class vectorProduct {};
      class vectorLenght {};
    };
  };
};

class CfgSounds {
  class BWA3_Sound_Click {
    sound[] = {"\bwa3_realism\sounds\BWA3_click.wav", 5, 1, 200};
    titles[] = {};
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Core {
    init = "call compile preProcessFileLineNumbers '\BWA3_Core\init.sqf'";
  };
};

#include <MenuConfig.hpp>