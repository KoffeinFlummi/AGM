



if (!hasInterface) exitWith {};


/* 
 * Heavily modified for AGM by aeroson
 * 
 * Created by [KH]Jman
 * Creation date: 31/03/2011
 * Email: jman@kellys-heroes.eu
 * Web: http://www.kellys-heroes.eu
 * 
 * Original script by =[A*C]= code34 
 * Modified by [KH]Jman
 * Part is modified code from WINSE - Valhalla mission 
 * modified for MSO: 16/08/2012
 */


#include "macros.sqf"
#include "dialogDefines.sqf"



private ["_ctrl", "_crew", "_text", "_vehicle", "_role", "_name"];

GVAR(showTime) = -1;

(findDisplay 46) displayAddEventHandler ["MouseZChanged", {_this call GVAR(onMouseZChanged)}];

GVAR(onMouseZChanged) = {
  if(GET_OPTION_VALUE(showVehicleCrewInfo, false)) then {
    if(vehicle player != player) then {
      if(GVAR(showTime) < time) then {
        GVAR(showTime) = time + 1;
      } else {
        GVAR(showTime) = GVAR(showTime) + 0.5;
      };
      [] call GVAR(show);  
    };
  };
};



disableSerialization;
//uiNamespace setVariable ['AGM_CrewInfo_Display', objnull];


GVAR(show) = {

  _text = "";   
  /*if (isnull (uiNamespace getVariable "AGM_CrewInfo_Display")) then { 
    cutrsc ["AGM_CrewInfo", "PLAIN", 1, false]; 
  } else {
    cutrsc ["AGM_CrewInfo", "PLAIN", 0, false];
  };*/

  if(GVAR(showTime) > time) then {

    if (vehicle player!=player  && !(vehicle player isKindOf "ParachuteBase")) then { 

      _vehicle = vehicle player;
      _crew = crew _vehicle;
      _config = configFile >> "CfgVehicles" >> (typeOf vehicle player);
      _text= _text + format ["<t size='1.4'><img image='%1'></t> <t size='1.7' shadow='true'>%2</t><br/>", getText(_config>>"picture"), getText (_config >> "DisplayName")];

      {
        if(!(format["%1", name _x] == "") and !(format["%1", name _x] == "Error: No unit")) then {

          _role = assignedVehicleRole _x;
          switch (_x) do {
            
            case commander _vehicle: {
              _text=_text+format ["<t size='1.5' shadow='true'>%1</t> <t size='1.3'><img image='a3\ui_f\data\IGUI\Cfg\Actions\getincommander_ca.paa'></t><br/>", name _x];
            };
  
            case gunner _vehicle: {
              _text=_text+format ["<t size='1.5' shadow='true'>%1</t> <t size='1.3'><img image='a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa'></t><br/>", name _x];
            };
              
            case driver _vehicle: {   
              _text=_text+format ["<t size='1.5' shadow='true'>%1</t> <t size='1.3'><img image='a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa'></t><br/>", name _x];
            };
              
            default {
              if(format["%1", (_role select 0)] != "Turret") then {
                _text=_text+format ["<t size='1.5' shadow='true'>%1</t> <t size='1.3'><img image='a3\ui_f\data\IGUI\Cfg\Actions\getincargo_ca.paa'></t><br/>", name _x];
              } else {
                _text=_text+format ["<t size='1.5' shadow='true'>%1</t> <t size='1.3'><img image='a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa'></t><br/>", name _x];
              };
            };
  
          };

        };
      } forEach _crew;

    };

  };    

  _ctrl = (uiNamespace getVariable QGVAR(dialog)) displayCtrl AGM_CrewInfo_TextIDC;
  _ctrl ctrlSetStructuredText parseText _text;
  _ctrl ctrlCommit 0; 

};


while {true} do {
  sleep 0.5;
  if(GET_OPTION_VALUE(showVehicleCrewInfo, false)) then {
    call GVAR(show);    
  };
};

