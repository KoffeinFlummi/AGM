//by commy2

private ["_currentVeh", "_currentHMD", "_grainSetting", "_blurSetting"];

_currentVeh = objNull;
_currentHMD = "";

while {true} do {
  AGM_NightVision_ppEffectBlur ppEffectEnable false;
  AGM_NightVision_ppEffect ppEffectEnable false;
  AGM_NightVision_ppEffectNVGBrightness ppEffectEnable false;

  waitUntil {currentVisionMode AGM_player == 1};

  AGM_NightVision_ppEffect ppEffectEnable true;
  AGM_NightVision_ppEffectBlur ppEffectEnable true;
  AGM_NightVision_ppEffectNVGBrightness ppEffectEnable true;

  waitUntil {
    if (cameraView == "GUNNER" && {AGM_player != vehicle AGM_player}) then {

      // in vehicle and not using hmd
      if (_currentVeh != vehicle AGM_player) then {
        _currentVeh = vehicle AGM_player;

        _grainSetting = _currentVeh getVariable ["AGM_NightVision_grain", getNumber (configFile >> "CfgVehicles" >> typeOf _currentVeh >> "AGM_NightVision_grain")];
        _blurSetting = _currentVeh getVariable ["AGM_NightVision_blur", getNumber (configFile >> "CfgVehicles" >> typeOf _currentVeh >> "AGM_NightVision_blur")];

        AGM_NightVision_ppEffect ppEffectAdjust [0.25, 2.5, 2.5, _grainSetting, _grainSetting, false];
        AGM_NightVision_ppEffect ppEffectCommit 0;
        AGM_NightVision_ppEffectBlur ppEffectAdjust [_blurSetting];
        AGM_NightVision_ppEffectBlur ppEffectCommit 0;
      };

      _currentHMD = "";  // force change if unmounting vehicle
    } else {

      // on foot or in vehicle using hmd
      if (hmd AGM_player != _currentHMD) then {
        _currentHMD = hmd AGM_player;

        _grainSetting = getNumber (configFile >> "CfgWeapons" >> _currentHMD >> "AGM_NightVision_grain");
        _blurSetting = getNumber (configFile >> "CfgWeapons" >> _currentHMD >> "AGM_NightVision_blur");

        AGM_NightVision_ppEffect ppEffectAdjust [0.25, 2.5, 2.5, _grainSetting, _grainSetting, false];
        AGM_NightVision_ppEffect ppEffectCommit 0;
        AGM_NightVision_ppEffectBlur ppEffectAdjust [_blurSetting];
        AGM_NightVision_ppEffectBlur ppEffectCommit 0;
      };

      _currentVeh = objNull;  // force change if mounting vehicle
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

    currentVisionMode AGM_player != 1
  };
};
