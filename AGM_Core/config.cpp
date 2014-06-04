class CfgPatches {
  class AGM_Core {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_UI_F};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
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
      class progressBar;
      class getWeaponType;
      class codeToString;
      class createUpdateLoop;
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
    Init = "execVM '\AGM_Core\init.sqf'";
  };
};

class CfgFactionClasses {
  class AGM {
    displayName = "AGM";
    priority = 0.1;
    side = 7;
  };
};

class CfgWeapons {
  class Rifle_Base_F;

  class AGM_FakePrimaryWeapon: Rifle_Base_F {
    discreteDistance[] = {};
    discreteDistanceInitIndex = 0;
    displayName = "";
    model = "";
    magazines[] = {"AGM_FakeMagazine"};
    scope = 2;
  };
};

class CfgMagazines {
  class CA_Magazine;

  class AGM_FakeMagazine: CA_Magazine {
    descriptionShort = "";
    displayName = "";
    displayNameShort = "";
    count = 0;
  };
};

#include <MainMenu.hpp>
#include <MenuConfig.hpp>
#include <ProgressScreen.hpp>
