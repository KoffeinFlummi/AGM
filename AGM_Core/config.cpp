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
      class binarizeNumber;
      class codeToString;
      class convertKeyCode;
      class createUpdateLoop;
      class displayText;
      class execRemoteFnc;
      class findStringInString;
      class getBinocular;
      class getDirectionVector;
      class getDirectionVector2;
      class getNumberFromMissionSQM;
      class getStringFromMissionSQM;
      class getTargetDistance;
      class getTurretIndex;
      class getTurrets;
      class getWeaponType;
      class getWindDirection;
      class isAutoWind;
      class isInBuilding;
      class isTurnedOut;
      class keyInput;
      class moduleCheckPBOs;
      class numberToDigits;
      class numberToDigitsString;
      class progressBar;
      class revertKeyCodeLocalized;
      class setKeyDefault;
      class subString;
      class toBin;
      class toHex;
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
    Init = "call compile preprocessFileLineNumbers '\AGM_Core\init.sqf'";
  };
};

class CfgFactionClasses {
  class AGM {
    displayName = "AGM";
    priority = 0.1;
    side = 7;
  };
};

class CfgVehicles {
  class Module_F;
  class AGM_ModuleCheckPBOs: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "Check PBOs";
    function = "AGM_Core_fnc_moduleCheckPBOs";
    scope = 2;
    isGlobal = 1;
    class Arguments {
      class Action {
        displayName = "Action";
        description = "What to do with people who do not have the right PBOs?";
        class values {
          class WarnOnce {
            default = 1;
            name = "Warn Once";
            value = 1;
          };
          class WarnRepeatedly {
            name = "Warn Repeatedly (Annoying)";
            value = 2;
          };
          class Kick {
            name = "Kick";
            value = 3;
          };
        };
      };
    };
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
