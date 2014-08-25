// by CAA-Picard

private ["_currentBlood"];

if (!hasInterface) exitWith {};

AGM_BloodLevel_CC = ppEffectCreate ["ColorCorrections", 4206];
AGM_UnconsciousCC = ppEffectCreate ["ColorCorrections", 4208];
AGM_UnconsciousRB = ppEffectCreate ["RadialBlur", 4207];
AGM_BloodLevel_CC ppEffectForceInNVG true;
AGM_UnconsciousCC ppEffectForceInNVG true;
AGM_UnconsciousRB ppEffectForceInNVG true;
AGM_UnconsciousCC ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[0.4,0.4,0,0,0,0.1,0.3]];
AGM_UnconsciousCC ppEffectCommit 0.15;
AGM_UnconsciousRB ppEffectAdjust [0.4, 0.4, 0, 0];
AGM_UnconsciousRB ppEffectCommit 0.5;

// Spawn a thread to handle graphical effects for player, regardless of which unit he's controlling
[] spawn {
  while {true} do {

    // Detect if curator interface is open and disable effects
    if (!isNull(findDisplay 312)) then {
      AGM_BloodLevel_CC ppEffectEnable false;
      AGM_UnconsciousCC ppEffectEnable false;
      AGM_UnconsciousRB ppEffectEnable false;
      while {!isNull(findDisplay 312)} do {
        sleep 1;
      };
    };

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

    // Unconciousness effect
    if (player getVariable ["AGM_Unconscious", false] or player getVariable ["AGM_Overdosing", false]) then {
      AGM_UnconsciousCC ppEffectEnable true;
      AGM_UnconsciousRB ppEffectEnable true;
      if (isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])) then {
        [true, true] call AGM_Core_fnc_disableUserInput;
      };
    } else {
      AGM_UnconsciousCC ppEffectEnable false;
      AGM_UnconsciousRB ppEffectEnable false;
      if !(isNull (uiNamespace getVariable ["AGM_Core_dlgDisableMouse", displayNull])) then {
        [false] call AGM_Core_fnc_disableUserInput;
      };
    };

    sleep 1;
  };
};
