class CfgPatches {
  class AGM_Map {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_UI_F, A3_Misc_F};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class RscControlsGroup;
class RscActiveText;
class RscPicture;
class RscText;
class RscObject;

class RscMapControl {
  sizeExGrid = 0.032;
};
class RscDisplayMainMap {
  // get rid of the "center to player position" - button (as it works even on elite)
  class controls {
    class TopRight: RscControlsGroup {
      class controls {
        class ButtonPlayer: RscActiveText {
          text = "";
          w = 0;
          h = 0;
          sizeEx = 0;
          onButtonClick = "";
        };
        class CA_PlayerName: RscText {
          x = "2 *    ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfilePicture: RscPicture {
          x = "13.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfileBackground: RscText {
          x = "13.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class Separator1: RscPicture {
          x = "14.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
      };
    };
  };
  // scale up the compass
  class objects {
    class Compass: RscObject {
      scale = 0.7;
      zoomDuration = 0;
    };
  };
};