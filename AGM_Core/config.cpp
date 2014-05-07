class CfgPatches {
  class AGM_Core {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_UI_F};
    version = 0.7;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Core {
    class AGM_Core {
      file = "AGM_Core\functions";
      class execRemoteFnc;
      class getDirectionVector2;
      class keyInput;
      class openInteractionMenu;
      class openSelfMenu;
      class openMenu;
      class toBin;
      class toHex;
      class addVector;
      class subtractVector;
      class scaleVector;
      class scalarProduct;
      class vectorProduct;
      class vectorLength;
      class getWindDirection;
      class setKeyDefault;
      class convertKeyCode;
      class revertKeyCodeLocalized;
      class binarizeNumber;
      class numberToDigits;
      class numberToDigitsString;
      class getDirection;
      class getPitch;
      class getBank;
      class setPitchBank;
      class getDirectionVector;
      class getTargetDistance;
      class getTurrets;
      class getTurretIndex;
      class isTurnedOut;
      class isInBuilding;
      class displayText;
    };
  };
};

class CfgSounds {
  class AGM_Sound_Click {
    sound[] = {"\AGM_Core\sounds\AGM_click.wav", 5, 1, 200};
    titles[] = {};
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Core {
    clientInit = "execVM '\AGM_Core\init.sqf'";
  };
};

#include <MainMenu.hpp>
#include <MenuConfig.hpp>
