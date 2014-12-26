class AGM_Artillery_MapComputer_Dialog
{
  idd = -1;
  movingEnable = 0;
  enableSimulation = 1;
  enableDisplay = 1;
  onLoad = "((uiNamespace getVariable ['AGM_Artillery_RscWeaponRangeArtilleryCustom', displayNull]) displayCtrl 800858) ctrlSetBackgroundColor [0,0,0,1]; uiNamespace setVariable ['AGM_Artillery_MapComputer_Dialog', _this select 0];";
  onUnLoad = "((uiNamespace getVariable ['AGM_Artillery_RscWeaponRangeArtilleryCustom', displayNull]) displayCtrl 800858) ctrlSetBackgroundColor [0,0,0,0.5];";
  duration = 2147483647;
  fadein = 0;
  fadeout = 0;

  class controlsBackground {
    class BGR_BLACK_TOP: RscText {
      idc = -1;
      x = 0.11 * safeZoneH + safezoneX;
      y = 0 * safeZoneH + safezoneY;
      w = 0.183333 * (3/4) * safeZoneH;
      h = 0.4083335 * safeZoneH;
      colorbackground[] = {0.0,0.0,0.0,1};
    };
    class BGR_BLACK_BOTTOM: RscText {
      idc = -1;
      x = 0.11 * safeZoneH + safezoneX;
      y = 0.5916665 * safeZoneH + safezoneY;
      w = 0.183333 * (3/4) * safeZoneH;
      h = 0.4083335 * safeZoneH;
      colorbackground[] = {0.0,0.0,0.0,1};
    };
  };

  class controls {
    class MiniMap: RscMapControl
    {
      idc = -1;
      type = 101;  //100 hides all markers
      scaleDefault = 0.25;
      colorbackground[] = {0.9,0.9,0.9,1};
      maxSatelliteAlpha = 0.15;
      x = 0.2475 * safeZoneH + safezoneX;
      y = 0 * safeZoneH + safeZoneY;
      w = safeZoneW - (0.2475 * safeZoneH);
      h = 1 * safeZoneH;

      onMouseButtonClick = "_this call AGM_Artillery_fnc_mapCompEventClickOnMap";
      onDraw = "_this call AGM_Artillery_fnc_mapCompEventDrawMap";
    };
    class ChargeListBox: RscListbox {
      idc = 233232;
      style = ST_RIGHT;
      x = 0.11 * safeZoneH + safezoneX;
      y = 4.5 * ((safeZoneH / 1.2) / 25) +   (safezoneY + (safezoneH - (safeZoneH / 1.2))/2);
      w = 5.475 * (safeZoneH / 40);
      h = 5 * ((safeZoneH / 1.2) / 25);
    };

    class MapCordsFrame: RscFrame {
      idc = -1;
      text = "Load Map Cords"; //--- ToDo: Localize;
      x = 0.1125 * safeZoneH + safezoneX;
      y = 15.25 * ((safeZoneH / 1.2) / 25) + (safezoneY + (safezoneH - (safeZoneH / 1.2))/2);
      w = 5.3 * (safeZoneH / 40);
      h = 1.5 * ((safeZoneH / 1.2) / 25);
      sizeEx = "0.5 * ((safeZoneH / 1.2) / 25)";
    };
    class MapCordsEdit: RscEdit {
      idc = 233237;
      x = 0.115 * safeZoneH + safezoneX;
      y = 15.75 * ((safeZoneH / 1.2) / 25) + (safezoneY + (safezoneH - (safeZoneH / 1.2))/2);
      w = 3.1 * (safeZoneH / 40);
      h = 0.9 * ((safeZoneH / 1.2) / 25);
    };
    class MapCordsButton: RscButton {
      idc = -1;
      text = "Load"; //--- ToDo: Localize;
      x = 0.195 * safeZoneH + safezoneX;
      y = 15.75 * ((safeZoneH / 1.2) / 25) + (safezoneY + (safezoneH - (safeZoneH / 1.2))/2);
      w = 1.9 * (safeZoneH / 40);
      h = 0.9 * ((safeZoneH / 1.2) / 25);
      action = "[] spawn AGM_Artillery_fnc_mapCompEventEnterCords";
    };

    class CloseButton: RscButton {
      idc = -1;
      x = 0.11625 * safeZoneH + safezoneX;
      y = 17.0 * ((safeZoneH / 1.2) / 25) + (safezoneY + (safezoneH - (safeZoneH / 1.2))/2);
      w = 5 * (safeZoneH / 40);
      h = 1 * ((safeZoneH / 1.2) / 25);
      text = "Close";
      action = "closeDialog 0;";
    };
  };
};