// by commy2 and CAA-Picard
#define StrenghToDeafness 3
#define MaxDeafness 1.1

AGM_EarRingingPlaying = false;

AGM_EarPlugsIn = false;
AGM_hasEarBuds = false;

player addEventHandler ["firedNear", {_this call AGM_Hearing_fnc_firedNearEH}];
player addEventHandler ["explosion", {_this call AGM_Hearing_fnc_explosionEH}];

//give earbuds
_this spawn {
  waitUntil {!isNull (findDisplay 46)};
  _ammo = getText (configFile >> "CfgMagazines" >> currentMagazine player >> "ammo");
  if (getNumber (configFile >> "CfgAmmo" >> _ammo >> "audiblefire") > 8) then {
      player addItem "AGM_EarBuds";
  };
};

AGM_CurrentDeafness = 0;
AGM_NewStrength = 0;

// Spawn volume updating process
[] spawn {
  while {true} do {

    // Check if new noises increase deafness
    if (AGM_NewStrength * StrenghToDeafness > AGM_CurrentDeafness) then {
      AGM_CurrentDeafness = AGM_NewStrength * StrenghToDeafness;

      if (AGM_CurrentDeafness > MaxDeafness) then {
        AGM_CurrentDeafness = MaxDeafness;
      };
    };
    AGM_NewStrength = 0;

    // Recover rate is slower if deafness is severe
    _recoverRate = 0.01;
    if (AGM_CurrentDeafness > 0.7) then {
      _recoverRate = 0.005;
      if (AGM_CurrentDeafness > 0.9) then {
        _recoverRate = 0.002;
      };
    };

    // Deafness recovers with time
    AGM_CurrentDeafness = AGM_CurrentDeafness - _recoverRate;
    if (AGM_CurrentDeafness < 0) then {
        AGM_CurrentDeafness = 0
    };

    // Compute volume
    _clampedDeafness = (1 - AGM_CurrentDeafness);
    if (_clampedDeafness < 0) then {
      _clampedDeafness = 0
    };

    // needed until Bohemia fixes playSound to actually use the second argument
    _volume = (_clampedDeafness * _clampedDeafness) max 0.1;

    // Earplugs reduce hearing 20%
    if (player getVariable ["X39_MedSys_var_hasEarplugs", false] or AGM_EarPlugsin) then {
      if (_volume > 0.8) then {
        _volume = 0.8;
      };
    };

    // Reduce volume if player is unconscious
    if (player getVariable ["AGM_Unconscious", false]) then {
      if (_volume > 0.4) then {
        _volume = 0.4;
      };
    };

    0.1 fadeSound _volume;
    0.1 fadeSpeech _volume;
    player setVariable ["tf_globalVolume", _volume];
    player setVariable ["acre_sys_core_globalVolume", _volume];

    //hintSilent format ["AGM_CurrentDeafness, _Volume = %1, %2", AGM_CurrentDeafness, _volume];

    sleep 0.1;
  };
};

