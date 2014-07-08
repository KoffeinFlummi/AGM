// by CAA-Picard

private ["_currentBlood"];

if (!hasInterface) exitWith {};

AGM_BloodLevel_CC = ppEffectCreate ["ColorCorrections", 4206];
AGM_BloodLevel_CC ppEffectForceInNVG true;

// Spawn a thread to handle graphical effects for player, regardless of which unit he's controlling
[] spawn {
  while {true} do {
    // TODO: Detect if curator interface is open and disable effects
    
    // Blood level
    _currentBlood = player getVariable ["AGM_Blood", 1];
    if (_currentBlood > 0.99) then {
      AGM_BloodLevel_CC ppEffectEnable false;
    } else {
      AGM_BloodLevel_CC ppEffectEnable true;
      AGM_BloodLevel_CC ppEffectAdjust [1, 1, 0, [0.0, 0.0, 0.0, 0.0], [1, 1, 1,_currentBlood],  [0.2, 0.2, 0.2, 0]];
      AGM_BloodLevel_CC ppEffectCommit 0;
    };

    // TODO: Bleeding effect?    
    // TODO: Pain effect ?
    // TODO: Unconciousness effect?
    
    sleep 1;
  };
};
