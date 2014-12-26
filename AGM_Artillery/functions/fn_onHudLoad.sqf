/*
Name: AGM_Artillery_fnc_onHudLoad

Author: Pabst Mirror

Description:
  Called on mortart hud opening, continualy updates the hud (azimuth/elevation)

Parameters:
  0: DISPLAY - The RscInGameUI->AGM_Artillery_RscWeaponRangeArtilleryCustom display

Returns:
  NONE

Example:
  Called from "onLoad" in gui_mortarHud.hpp
*/

//Custom Hud Elements
#define CTRL_SOLUTIONCOMP_STRUCTEXT (_display displayCtrl 800858)
#define CTRL_VECTOR_DOT_PICTURE (_display displayCtrl 800860)
#define CTRL_AMMO_CHARGE_STRUCTEXT (_display displayCtrl 800859)
#define CTRL_ELEVATION_STRUCTEXT (_display displayCtrl 800855)
#define CTRL_AZIMUTH_STRUCTEXT (_display displayCtrl 800856)
#define CTRL_AZIMUTH_OBJECT (_display displayCtrl 800851)
#define CTRL_ELEVATION_OBJECT (_display displayCtrl 800853)

//BIS (Hidden) Elements
#define CTRL_CA_HEADING (_display displayCtrl 156)
#define CTRL_CA_OPTICSPITCH (_display displayCtrl 182)
#define CTRL_CA_DISTANCE (_display displayCtrl 173)
// #define CTRL_CA_TIME (_display displayCtrl 174)
// #define CTRL_CA_ELEV_NEEDED (_display displayCtrl 176)




_this spawn {
  AGM_Artillery_rangefinderKeyDown = false;
  AGM_Artillery_computingSolution = false;
  AGM_Artillery_currentWeaponSettings = [];

  disableSerialization;
  _display = _this select 0;

  _mortarVeh = vehicle AGM_player;

  if ((count (weapons _mortarVeh)) < 1) exitWith {systemChat "Error: No Tube";};//should never happen
  _tubeWeaponName = (weapons _mortarVeh) select 0;
  _fireModes = getArray (configFile >> "CfgWeapons" >> _tubeWeaponName >> "modes");

  //Digital Azimuth/Elevation display
  _digialDisplayEnabled = (_mortarVeh getVariable ["AGM_Artillery_digialDisplayEnabled", true]);

  //Solution Display if either rangefinder or map computer
  _solutionDisplayShown = (_mortarVeh getVariable ["AGM_Artillery_mapComputerEnabled", false]) || (_mortarVeh getVariable ["AGM_Artillery_rangefinderEnabled", false]);
  CTRL_SOLUTIONCOMP_STRUCTEXT ctrlShow _solutionDisplayShown;

  waitUntil {
    if ((isNull _display) || {(vehicle AGM_player) != _mortarVeh}) exitWith {true};
    //Compute: Current Tube Settings (from animationPhase)
    _elevationDegrees = ((180 / PI) * (_mortarVeh animationPhase "mainGun")) + 75;
    _rotationDegrees = ((getDir _mortarVeh) + (((-180 / PI) * (_mortarVeh animationPhase "mainTurret")) + 360)) % 360;

    //Pull Values from 'unseen' ui (from ArmA internals) - IN STRING FORMAT!!
    _CA_Heading = ctrlText CTRL_CA_HEADING;
    _CA_OpticsPitch = ctrlText CTRL_CA_OPTICSPITCH;
    _CA_Distance = ctrlText CTRL_CA_DISTANCE;

    //Compute: Rangefinder gives total range, we want "horizontal distance" and "height"
    _numViewPitch = parseNumber _CA_OpticsPitch;
    _numHorizontalDistance = round ((cos (parseNumber _CA_OpticsPitch)) * (parseNumber _CA_Distance));
    _numHeightDiff = round ((sin (parseNumber _CA_OpticsPitch)) * (parseNumber _CA_Distance));

    //Compute: 'charge' from weaponstate
    _currentFireMode = (weaponState [_mortarVeh, [0]]) select 2;
    _currentChargeMode = _fireModes find _currentFireMode;

    //Set: rangefinder (tab held down) -> show crosshair
    CTRL_VECTOR_DOT_PICTURE ctrlShow AGM_Artillery_rangefinderKeyDown;

    //Update: 'charge' text in upper right (default arma - ammo count)
    _chargeText = format ["CHARGE  %1<img image='\AGM_Artillery\UI\ui_charges.paa'/>", _currentChargeMode];
    CTRL_AMMO_CHARGE_STRUCTEXT ctrlSetStructuredText parseText _chargeText;

    //Update: Elevation Text
    _elevText = format ["<t font='EtelkaMonospacePro'><t align='left'>ELEVATION:</t><br/>"];
    if (_digialDisplayEnabled) then {
      _elevationString = [_elevationDegrees, "mil4", true] call AGM_Artillery_fnc_formatNumber;
      _elevText = _elevText + format ["<img image='\AGM_Vector\rsc\d%1.paa'/>", (_elevationString select [0, 1])];
      _elevText = _elevText + format ["<img image='\AGM_Vector\rsc\d%1.paa'/>", (_elevationString select [1, 1])];
      _elevText = _elevText + format ["<img image='\AGM_Vector\rsc\d%1.paa'/>", (_elevationString select [2, 1])];
      _elevText = _elevText + format ["<img image='\AGM_Vector\rsc\d%1.paa'/></t></t>", (_elevationString select [3, 1])];
    };
    CTRL_ELEVATION_STRUCTEXT  ctrlSetStructuredText parseText _elevText;

    //Update: Azimuth Text
    _aziText = format ["<t font='EtelkaMonospacePro'>AZIMUTH:<br/>"];
    if (_digialDisplayEnabled) then {
      _azimuthString = [_rotationDegrees, "mil4", true] call AGM_Artillery_fnc_formatNumber;
      _aziText = _aziText + format ["<img image='\AGM_Vector\rsc\d%1.paa'/>", (_azimuthString select [0, 1])];
      _aziText = _aziText + format ["<img image='\AGM_Vector\rsc\d%1.paa'/>", (_azimuthString select [1, 1])];
      _aziText = _aziText + format ["<img image='\AGM_Vector\rsc\d%1.paa'/>", (_azimuthString select [2, 1])];
      _aziText = _aziText + format ["<img image='\AGM_Vector\rsc\d%1.paa'/></t></t>", (_azimuthString select [3, 1])];
    };
    CTRL_AZIMUTH_STRUCTEXT ctrlSetStructuredText parseText _aziText;

    //Update: Computer Display
    if (_solutionDisplayShown) then {
      _compDisplayAzimuth = (_mortarVeh getVariable ["AGM_Artillery_targetAzimuth", 0]);
      _compDisplayAzimuth = [_compDisplayAzimuth, "mil4", true] call AGM_Artillery_fnc_formatNumber;
      _compDisplayDist = (_mortarVeh getVariable ["AGM_Artillery_targetHorziontalDistance", 0]);
      _compDisplayDist = [_compDisplayDist, "meters", false] call AGM_Artillery_fnc_formatNumber;
      _compDisplayHeight = (_mortarVeh getVariable ["AGM_Artillery_targetHeightDiff", 0]);
      _compDisplayHeight = [_compDisplayHeight, "meters", false] call AGM_Artillery_fnc_formatNumber;
      _compDisplayCharge = str (_mortarVeh getVariable ["AGM_Artillery_solutionCharge", "--"]);
      _compDisplayElev = (_mortarVeh getVariable ["AGM_Artillery_solutionElev", 0]);
      _compDisplayElev = [_compDisplayElev, "mil4", true] call AGM_Artillery_fnc_formatNumber;
      _compDisplayTime = (_mortarVeh getVariable ["AGM_Artillery_solutionTime", 0]);
      _compDisplayTime = [_compDisplayTime, "sec", false] call AGM_Artillery_fnc_formatNumber;

      _compText = format ["<t font='EtelkaMonospacePro'>TARGET:<t size='0.75'>" ];
      _compText = _compText + format ["<br/><t align='left'>-AZIMUTH</t><t align='right'>%1</t>", _compDisplayAzimuth];
      _compText = _compText + format ["<br/><t align='left'>-RANGE</t><t align='right'>%1</t>", _compDisplayDist];
      _compText = _compText + format ["<br/><t align='left'>-HEIGHT</t><t align='right'>%1</t>", _compDisplayHeight];
      _compText = _compText + format ["</t><br/>SOLUTION:<t size='0.75'>"];
      if (AGM_Artillery_computingSolution) then {
        _compText = _compText + format ["<br/><t align='center' color='#FF0000'>-COMPUTING-</t>"];
      } else {
        _compText = _compText + format ["<br/><t align='left'>-CHARGE</t><t align='right'>%1</t>", _compDisplayCharge];
        if ((_mortarVeh getVariable ["AGM_Artillery_solutionTime", -1]) != -1) then {
          _compText = _compText + format ["<br/><t align='left'>-ELEVATION</t><t align='right'>%1</t>", _compDisplayElev];
          _compText = _compText + format ["<br/><t align='left'>-TIME</t><t align='right'>%1</t>", _compDisplayTime];
        } else {
          _compText = _compText + format ["<br/><t align='center' color='#FF0000'>--RANGE--</t>"];
          _compText = _compText + format ["<br/><t align='center' color='#FF0000'>--RANGE--</t>"];
        };
      };
      CTRL_SOLUTIONCOMP_STRUCTEXT ctrlSetStructuredText parseText _compText;
    };

    //Update: Analog Wheels
    CTRL_AZIMUTH_OBJECT ctrlSetModelDirAndUp [[0,1,0], [-1 * (sin _rotationDegrees), 0, cos _rotationDegrees]];
    CTRL_ELEVATION_OBJECT ctrlSetModelDirAndUp [[0,1,0], [(cos _elevationDegrees), 0, (sin _elevationDegrees)]];

    //Set currentSettings: for rangefinder function
    AGM_Artillery_currentWeaponSettings = [_mortarVeh, (currentMagazine _mortarVeh), _currentChargeMode, _rotationDegrees, _numHorizontalDistance, _numHeightDiff];

    false
  };

  AGM_Artillery_currentWeaponSettings = [];
};
