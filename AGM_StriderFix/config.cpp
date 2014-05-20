class CfgPatches {
  class AGM_StriderFix {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_StriderFix {
    clientInit = "execVM '\AGM_StriderFix\init.sqf'";
  };
};

class RscText;
class RscControlsGroup;

class RscInGameUI {
  //STRIDER
  class RscUnitInfo;
  class RscOptics_strider_commander: RscUnitInfo {
    controls[] = {"CA_IGUI_elements_group"};
    onLoad = "['onLoad',_this,'RscUnitInfo','IGUI'] call compile preprocessfilelinenumbers 'A3\ui_f\scripts\initDisplay.sqf'; [(_this select 0) displayCtrl 156] spawn AGM_StriderFix_displayAzimuth;";
    idd = 300;
    class CA_IGUI_elements_group: RscControlsGroup {
      idc = 170;
      x = "0 *    (0.01875 * SafezoneH) +     (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
      y = "0 *    (0.025 * SafezoneH) +     (SafezoneY)";
      w = "53.5 *     (0.01875 * SafezoneH)";
      h = "40 *     (0.025 * SafezoneH)";
      class HScrollbar {
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        autoScrollDelay = 5;
        autoScrollEnabled = 0;
        autoScrollRewind = 0;
        autoScrollSpeed = -1;
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        color[] = {1,1,1,1};
        colorActive[] = {1,1,1,1};
        colorDisabled[] = {1,1,1,0.3};
        height = 0;
        scrollSpeed = 0.06;
        shadow = 0;
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        width = 0;
      };
      class VScrollbar {
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        autoScrollDelay = 5;
        autoScrollEnabled = 1;
        autoScrollRewind = 0;
        autoScrollSpeed = -1;
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
        color[] = {1,1,1,1};
        colorActive[] = {1,1,1,1};
        colorDisabled[] = {1,1,1,0.3};
        height = 0;
        scrollSpeed = 0.06;
        shadow = 0;
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        width = 0;
      };
      class controls {
        class CA_Distance: RSCText {
          colorText[] = {0.706,0.0745,0.0196,1};
          font = "EtelkaMonospacePro";
          h = "1.5 *    (0.025 * SafezoneH)";
          idc = 151;
          shadow = 0;
          sizeEx = "0.038*SafezoneH";
          style = 0;
          text = "2456";
          w = "4 *    (0.01875 * SafezoneH)";
          x = "24.5 *     (0.01875 * SafezoneH)";
          y = "3 *    (0.025 * SafezoneH)";
        };

        class CA_Elev: RSCText {
          colorText[] = {0.706,0.0745,0.0196,1};
          font = "EtelkaMonospacePro";
          h = "1.5 *    (0.025 * SafezoneH)";
          idc = 175;
          shadow = 0;
          sizeEx = "0.038*SafezoneH";
          style = 1;
          text = "80.5";
          w = "5 *    (0.01875 * SafezoneH)";
          x = "32.7 *     (0.01875 * SafezoneH)";
          y = "3 *    (0.025 * SafezoneH)";
        };

        class CA_Heading: RSCText {
          colorText[] = {0.706,0.0745,0.0196,1};
          font = "EtelkaMonospacePro";
          h = "1.6 *    (0.025 * SafezoneH)";
          idc = 156;
          shadow = 0;
          sizeEx = "0.038*SafezoneH";
          style = 0;
          text = "023";
          w = "3.5 *    (0.01875 * SafezoneH)";
          x = "16.1 *     (0.01875 * SafezoneH)";
          y = "3 *    (0.025 * SafezoneH)";
        };

        class CA_Laser: RSCText {
          colorText[] = {0.706,0.0745,0.0196,1};
          font = "EtelkaMonospacePro";
          h = "1.5 *    (0.025 * SafezoneH)";
          idc = 158;
          shadow = 0;
          sizeEx = "0.038*SafezoneH";
          style = "0x30 + 0x800";
          text = "\A3\ui_f\data\igui\rscingameui\rscoptics\laser_designator_iconLaserOn.paa";
          w = "3.5 *    (0.01875 * SafezoneH)";
          x = "29.2 *     (0.01875 * SafezoneH)";
          y = "3 *    (0.025 * SafezoneH)";
        };

        class CA_OpticsZoom: RSCText {
          colorText[] = {0.706,0.0745,0.0196,1};
          font = "EtelkaMonospacePro";
          h = "1.1 *    (0.025 * SafezoneH)";
          idc = 180;
          shadow = 0;
          sizeEx = "0.038*SafezoneH";
          style = 1;
          type = 0;
          w = "4.5 *    (0.01875 * SafezoneH)";
          x = "43.85 *    (0.01875 * SafezoneH)";
          y = "19.6 *     (0.025 * SafezoneH)";
        };

        class CA_VisionMode: RSCText {
          colorText[] = {0.706,0.0745,0.0196,1};
          font = "EtelkaMonospacePro";
          h = "1.1 *    (0.025 * SafezoneH)";
          idc = 179;
          shadow = 0;
          sizeEx = "0.038*SafezoneH";
          style = 0;
          text = "VIS";
          w = "4 *    (0.01875 * SafezoneH)";
          x = "6.5 *    (0.01875 * SafezoneH)";
          y = "19.6 *     (0.025 * SafezoneH)";
        };
      };
    };
  };
};
