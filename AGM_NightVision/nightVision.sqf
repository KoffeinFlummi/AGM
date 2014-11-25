//by commy2

private ["_currentVeh", "_grainSetting", "_blurSetting"];

while {true} do {
  AGM_NightVision_ppEffectBlur ppEffectEnable false;
  AGM_NightVision_ppEffect ppEffectEnable false;
  AGM_NightVision_ppEffectNVGBrightness ppEffectEnable false;

  waitUntil {currentVisionMode AGM_player == 1};

  AGM_NightVision_ppEffect ppEffectEnable true;
  AGM_NightVision_ppEffectBlur ppEffectEnable true;
  AGM_NightVision_ppEffectNVGBrightness ppEffectEnable true;

  _currentVeh = objNull;
  while {currentVisionMode AGM_player == 1} do {

    if ((vehicle AGM_player) != _currentVeh) then {
      _currentVeh = vehicle AGM_player;
      _grainSetting = 0;
      _blurSetting = 0;
      if (_currentVeh != AGM_player) then {  //In a vehicle use defaults, can override with setVariable
        _grainSetting = _currentVeh getVariable ["AGM_NightVision_grain", 0.75];
        _blurSetting = _currentVeh getVariable ["AGM_NightVision_blur", 0];
      } else {  //load from config, if not found use defaults
        _grainSetting = [(configFile >> "CfgWeapons" >> (hmd AGM_player)), "AGM_NightVision_grain", 0.75] call BIS_fnc_returnConfigEntry;
        _blurSetting = [(configFile >> "CfgWeapons" >> (hmd AGM_player)), "AGM_NightVision_blur", 0] call BIS_fnc_returnConfigEntry;
      };
	  // systemChat format ["Debug: %1 gain - %2 blur", _grainSetting, _blurSetting];
      AGM_NightVision_ppEffect ppEffectAdjust [0.25, 2.5, 2.5, _grainSetting, _grainSetting, false];
      AGM_NightVision_ppEffect ppEffectCommit 0;
      AGM_NightVision_ppEffectBlur ppEffectAdjust [_blurSetting];
      AGM_NightVision_ppEffectBlur ppEffectCommit 0;
    };

    // Detect if curator interface is open and disable effects
    if (!isNull findDisplay 312) then {
      AGM_NightVision_ppEffect ppEffectEnable false;
      AGM_NightVision_ppEffectBlur ppEffectEnable false;
      AGM_NightVision_ppEffectNVGBrightness ppEffectEnable false;

      waitUntil {isNull findDisplay 312};

      AGM_NightVision_ppEffect ppEffectEnable true;
      AGM_NightVision_ppEffectBlur ppEffectEnable true;
      AGM_NightVision_ppEffectNVGBrightness ppEffectEnable true;
    };
    sleep 0.1;
  };
};
