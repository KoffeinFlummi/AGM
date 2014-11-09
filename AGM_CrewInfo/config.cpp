/* 
	Description:
		Once you use scrollwheel and you are in vehicle, this addon shows
		vehicle crew names and roles, it also shows picture and name of the vehicle
		

	Credits:
		Rewritten for AGM by aeroson

		Original script by =[A*C]= code34 
		Modified by [KH]Jman
		Part is modified code from WINSE - Valhalla mission 
		modified for MSO: 16/08/2012

		Created by [KH]Jman
		Creation date: 31/03/2011
		Email: jman@kellys-heroes.eu
		Web: http://www.kellys-heroes.eu
*/


#include "macros.sqf"
#include "dialogDefines.sqf"


class CfgPatches {
  class DOUBLES(PREFIX,COMPONENT) {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"aeroson"};
    authorUrl = "https://github.com/aeroson/";
  };
};




class Extended_PostInit_EventHandlers {
  class DOUBLES(PREFIX,COMPONENT) {
    clientInit = call compile preprocessFileLineNumbers '\DOUBLES(PREFIX,COMPONENT)\clientInit.sqf';
  };
};



#define CT_STRUCTURED_TEXT 13 
#define ST_LEFT 0

class RscTitles 
{

  titles[]={QGVAR(dialog)};
  class GVAR(dialog)
  {

    idd = -1;
    movingEnable=1;
    duration = 1; 
    fadein=0;
    fadeout=1;    
    name=QGVAR(dialog);
    controlsBackground[] = {QGVAR(text)};
    onLoad = uiNamespace setVariable ['GVAR(dialog)', _this select 0];
	onUnload = uiNamespace setVariable ['GVAR(dialog)', objNull];


    class GVAR(text) { 
      idc = AGM_CrewInfo_TextIDC; 
      type = CT_STRUCTURED_TEXT; 
      style = ST_LEFT; 
      x = SafeZonex + SafezoneW - 0.31;
      y = SafeZoneY + SafeZoneH*0.4;
      w = 0.3;
      h = 0.6;
      size = 0.018; 
      colorBackground[] = { 0, 0, 0, 0 };
      colortext[] = {0,0,0,0.7};
      text = "";
      class Attributes {
        align = right;
      };
    };

  };
  
};