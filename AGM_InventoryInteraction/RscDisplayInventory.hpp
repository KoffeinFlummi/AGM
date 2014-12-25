class RscText;
class RscActiveText;
class RscControlsGroupNoScrollbars;

/*
Adjust the scaling of the inventory screen
-changes it from scaling based on user's interface size to a static size
-text size and row height size are uneffected
-also tweaks the height of the two ProgressBars which looked odd scaled up so much
*/

class RscDisplayInventory {
  class controls {
    //resize moved to AGM_Inventory

    //New Addition: ItemInfoBox
    class ItemSelectedControlGroup: RscControlsGroupNoScrollbars {
      idc = 800847;
      x = "26.6 *           (safeZoneH / 40) +       (safezoneX + (safezoneW - safeZoneH)/2)";
      y = "11.5 *           ((safeZoneH / 1.2) / 25) +   (safezoneY + (safezoneH - (safeZoneH / 1.2))/2))";
      w = 0;
      h = 0;
      class controls {
        class ItemSelectedBackground: RscText {
          idc = -1;
          x = "0 *       (safeZoneH / 40)";
          y = "0 *       ((safeZoneH / 1.2) / 25)";
          w = "6 *       (safeZoneH / 40)";
          h = "6 *       ((safeZoneH / 1.2) / 25)";
          colorBackground[] = {0.05,0.05,0.05,1};
        };
        class ItemSelectedText: RscText {
          idc = 800848;
          x = "0 *         (safeZoneH / 40)";
          y = "0 *         ((safeZoneH / 1.2) / 25)";
          w = "6 *         (safeZoneH / 40)";
          h = "0.7 *       ((safeZoneH / 1.2) / 25)";
          SizeEx = "0.65 *     ((safeZoneH / 1.2) / 25)";
          colorBackground[] = {0.00,0.00,0.00,1};
        };
        class ItemSelectedMass: ItemSelectedText {
          idc = 800849;
          y = "0.7 *         ((safeZoneH / 1.2) / 25)";
        };
        class ItemSelectedButton0: RscActiveText  {
          idc = 800850;
          style = 1;
          x = "0 *       (safeZoneH / 40)";
          y = "1.4 *     ((safeZoneH / 1.2) / 25)";
          w = "6 *       (safeZoneH / 40)";
          h = "0.7 *     ((safeZoneH / 1.2) / 25)";
          text = "";
          SizeEx = "0.65 *   ((safeZoneH / 1.2) / 25)";
          soundDoubleClick[] = {"",0.1,1};
          color[] = {0.85,0.85,0.85,1};
          colorText[] = {0.85,0.85,0.85,1};
          colorActive[] = {1,1,1,1};
        };
        class ItemSelectedButton1: ItemSelectedButton0  {
          idc = 800851;
          y = "2.1 *   ((safeZoneH / 1.2) / 25)";
        };
        class ItemSelectedButton2: ItemSelectedButton0  {
          idc = 800852;
          y = "2.8 *     ((safeZoneH / 1.2) / 25)";
        };
        class ItemSelectedButton3: ItemSelectedButton0  {
          idc = 800853;
          y = "3.5 *     ((safeZoneH / 1.2) / 25)";
        };
        class ItemSelectedButton4: ItemSelectedButton0  {
          idc = 800854;
          y = "4.2 *     ((safeZoneH / 1.2) / 25)";
        };
        class ItemSelectedButton5: ItemSelectedButton0  {
          idc = 800855;
          y = "4.9 *     ((safeZoneH / 1.2) / 25)";
        };
        class ItemSelectedButton6: ItemSelectedButton0  {
          idc = 800856;
          y = "5.6 *     ((safeZoneH / 1.2) / 25)";
        };
        class ItemSelectedButton7: ItemSelectedButton0  {
          idc = 800857;
          y = "6.3 *     ((safeZoneH / 1.2) / 25)";
        };

        class ItemSelectedButtonClose: RscActiveText  {
          onButtonClick = "[] call AGM_InventoryInteraction_fnc_closeItemInfoBox;";
          idc = -1;
          style = 48;
          color[] = {1,1,1,0.7};
          text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
          x = "5.5 *       (safeZoneH / 40)";
          y = "0 *       ((safeZoneH / 1.2) / 25)";
          w = "0.5 *       (safeZoneH / 40)";
          h = "0.5 *       ((safeZoneH / 1.2) / 25)";
          colorText[] = {1,1,1,0.7};
          colorActive[] = {1,1,1,1};
          tooltip = "Close";
        };
      };
    };
  };
};