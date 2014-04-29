class CfgPatches {
  class BWA3_Core {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {BWA3_Config};
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
      class getTargetDistance {};
      class isHigherRank {};
      class getDirectionVector2 {};
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
      class vectorLength {};

      class getWindDirection {};
      class setKeyDefault {};
      class convertKeyCode {};
      class revertKeyCodeLocalized {};
      class binarizeNumber {};
      class numberToDigits {};
      class numberToDigitsString {};
      class getDirection {};
      class getPitch {};
      class getBank {};
      class setPitchBank {};
      class getDirectionVector {};
      class getTargetDistance {};
      class getTurrets {};
      class getTurretIndex {};
      class isTurnedOut {};
      class isInBuilding {};
      class displayText {};
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
    clientInit = "execVM '\BWA3_Core\init.sqf'";
  };
};

#include <MenuConfig.hpp>
