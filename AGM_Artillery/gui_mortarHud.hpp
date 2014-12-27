#define COMPASS_SCALE  (safeZoneH / 2)

class RscInGameUI
{
  class AGM_Artillery_RscWeaponRangeArtilleryCustom {
    idd = 300;
    onLoad = "uiNamespace setVariable ['AGM_Artillery_RscWeaponRangeArtilleryCustom', _this select 0]; _this call AGM_Artillery_fnc_onHudLoad;";
    class controls
    {
      //game will auto fill data into these (hidden from sight)
      class CA_IGUI_elements_group: RscControlsGroup {
        idc = 170;
        class VScrollbar: VScrollbar {width = 0;};
        class HScrollbar: HScrollbar {height = 0;};
        x = "0 *     (0.01875 * SafezoneH) +     (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
        y = "0 *     (0.025 * SafezoneH) +     (SafezoneY)";
        w = "53.5 *   (0.01875 * SafezoneH)";
        h = "40 *     (0.025 * SafezoneH)";
        class controls
        {
          class CA_Heading: RscText
          {
            idc = 156;
            style = 0;
            colorText[] = {0.706,0.0745,0.0196,1};
            sizeEx = "0.028*SafezoneH";
            shadow = 0;
            font = "EtelkaMonospacePro";
            text = "015";
            x = -1;
            y = -1;
            w = 0;
            h = 0;
          };
          class CA_OpticsPitch: RscText
          {
            idc = 182;
            style = 1;
            colorText[] = {0.706,0.0745,0.0196,1};
            sizeEx = "0.028*SafezoneH";
            shadow = 0;
            font = "EtelkaMonospacePro";
            text = "34.5";
            x = -1;
            y = -1;
            w = 0;
            h = 0;
          };
          class CA_OpticsZoom: RscText
          {
            idc = 180;
            style = 1;
            colorText[] = {0.706,0.0745,0.0196,1};
            sizeEx = "0.028*SafezoneH";
            shadow = 0;
            font = "EtelkaMonospacePro";
            text = "4.5";
            x = -1;
            y = -1;
            w = 0;
            h = 0;
          };
          class CA_Distance: RscText
          {
            idc = 173;
            style = 1;
            sizeEx = "0.038*SafezoneH";
            colorText[] = {0.706,0.0745,0.0196,1};
            shadow = 0;
            font = "EtelkaMonospacePro";
            text = "2456";
            x = -1;
            y = -1;
            w = 0;
            h = 0;
          };
          class CA_Time: RscText
          {
            idc = 174;
            style = 1;
            sizeEx = "0.038*SafezoneH";
            colorText[] = {0.706,0.0745,0.0196,1};
            shadow = 0;
            font = "EtelkaMonospacePro";
            text = "25";
            x = -1;
            y = -1;
            w = 0;
            h = 0;
          };
          class CA_Elev: RscText
          {
            idc = 175;
            style = 1;
            sizeEx = "0.038*SafezoneH";
            colorText[] = {0.706,0.0745,0.0196,1};
            shadow = 0;
            font = "EtelkaMonospacePro";
            text = "80.5";
            x = -1;
            y = -1;
            w = 0;
            h = 0;
          };
          class CA_Elev_Need: RscText
          {
            idc = 176;
            style = 1;
            sizeEx = "0.038*SafezoneH";
            colorText[] = {0.706,0.0745,0.0196,1};
            shadow = 0;
            font = "EtelkaMonospacePro";
            text = "35.4";
            x = -1;
            y = -1;
            w = 0;
            h = 0;
          };
        };
      };

      //Real Controls
      class Vector_Center : RscPicture {
        idc = 800860;
        colorText[] = {1, 0, 0, 0.5};
        x = 0.488 * safezoneW + safezoneX;
        y = 0.4783 * safezoneH + safezoneY;
        w = 0.4 / 16 * safezoneW;
        h = 0.4 / 9 * safezoneH;
        text = "\AGM_Vector\rsc\Vector_Center.paa";
      };

      //Charge display will sit on the weapon/ammo part of the hud, can move anywhere so get cords from profilenamespace
      class ChargeText: RscStructuredText {
        idc = 800859;
        colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
        x = "0 *           (      ((safezoneW / safezoneH) min 1.2) / 40) +     (profilenamespace getvariable [""IGUI_GRID_WEAPON_X"",    ((safezoneX + safezoneW) -     (12.4 *       (      ((safezoneW / safezoneH) min 1.2) / 40)) - 0.5 *       (      ((safezoneW / safezoneH) min 1.2) / 40))])";
        y = "2.5 *           (      (      ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) +     (profilenamespace getvariable [""IGUI_GRID_WEAPON_Y"",    (safezoneY + 0.5 *       (      (      ((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
        w = "10 *           (      ((safezoneW / safezoneH) min 1.2) / 40)";
        h = "1 *           (      (      ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        size = "0.8 *           (      (      ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
      };
      class RscStructuredText_1100: RscStructuredText {
        idc = 800858;
        x = 0.11 * safeZoneH + safezoneX;
        y = 0.4083335 * safeZoneH + safeZoneY;
        w = 0.183333 * (3/4) * safeZoneH;
        h = 0.183333 * safeZoneH;
        size = "0.0266667 * safeZoneH;";
        colorBackground[] = {0,0,0,0.5};
      };
      class Text_Elevation: RscStructuredText {
        idc = 800855;
        text = "";
        x = 0 * safezoneW + safezoneX;
        y = (1 * safezoneH + safezoneY) - ((4/3) * (COMPASS_SCALE)) + 0.5 * (COMPASS_SCALE * .2) * (4/3);
        w = (COMPASS_SCALE * .2);
        h = 0.5 * (COMPASS_SCALE * .2) * (4/3);
        colorBackground[] = {1,1,1,0.01};
        size = ((COMPASS_SCALE * .2) * (4/3)) / 7;
      };
      class Text_az: RscStructuredText {
        idc = 800856;
        text = "";
        x = (0.5 * safezoneW + safezoneX) - (COMPASS_SCALE / 2);
        y = (1 * safezoneH + safezoneY) - ((COMPASS_SCALE * .2) * (4/3));
        w = (COMPASS_SCALE * .2);
        h = (COMPASS_SCALE * .2) * (4/3);
        colorBackground[] = {1,1,1,0.01};
        size = ((COMPASS_SCALE * .2) * (4/3)) / 7;
      };
    };
    class objects {
      class Azimuth_Star {
        idc = 800851;
        type = 82;
        model = "\AGM_Artillery\data\compass_star.p3d";
        scale = COMPASS_SCALE;
        direction[] = {0, 0, 1};
        up[] = {0, 1, 0};
        x = 0.5 * safezoneW + safezoneX;
        y = (1 * safezoneH + safezoneY + (0.4 * COMPASS_SCALE));
        z = 1.01;
        xBack = .5;
        yBack = .5;
        zBack = 0;
        inBack =0;
        enableZoom = 0;
        zoomDuration = 4.001;
      };
      class Azimuth_Base: Azimuth_Star {
        idc = 800852;
        model = "\AGM_Artillery\data\compass_base.p3d";
        z = 1;
      };
      class Elevation_Star: Azimuth_Star {
        idc = 800853;
        x = (0 * safezoneW + safezoneX - (0.3 * COMPASS_SCALE));
        y = (1 * safezoneH + safezoneY) - ((4/3) * (COMPASS_SCALE / 2));
        up[] = {0, 0, -1};
      };
      class Elevation_Base: Azimuth_Base {
        idc = 800854;
        x = (0 * safezoneW + safezoneX - (0.3 * COMPASS_SCALE));
        y = (1 * safezoneH + safezoneY) - ((4/3) * (COMPASS_SCALE / 2));
        up[] = {1, 0, 0};
      };
    };
  };
};
