/*
 * Author: KoffeinFlummi, CAA-Picard
 *
 * Simulate the health evolution of a unit. Simulates:
 *   - Blood level
 *   - Pain  level
 *   - Morphine level
 *
 * Arguments:
 * 0: Unit to simulate (Object)
 *
 * Return value:
 * None
 */

#define UNCONSCIOUSNESSTRESHOLD 0.6

#define PAINKILLERTRESHOLD 0.1
#define PAINLOSS 0.0001

#define BLOODTRESHOLD0 0.5
#define BLOODTRESHOLD1 0.2
#define BLOODTRESHOLD2 0
#define BLOODLOSSRATE 0.003

#define DELTATIME 5

private ["_unit", "_script", "_blood", "_pain", "_painkiller", "_epinephrine", "_bloodLossRate"];

_unit          = _this select 0;

// Ensure there's only one thread for this
_script = _unit getVariable ["AGM_simulateHealthScript", scriptNull];
if (isNull _script) then {

  // Unit is not local, so spawn this thread elsewhere
  if !(local _unit) exitWith {
    [[_unit], "AGM_Medical_fnc_simulateHealth", _unit] call AGM_Core_fnc_execRemoteFnc;
  };

  _unit setVariable ["AGM_simulateHealthScript", _unit spawn {
    _unit = _this;

    // If the unit is completely healed terminate the loop
    while {alive _unit and
           (damage _unit > 0 or
           _unit getVariable ["AGM_Pain", 0] > 0 or
           _unit getVariable ["AGM_Painkiller", 0] > 0 or
           _unit getVariable ["AGM_Epinephrine", 0] > 0)
          } do {

      // Unit has changed locality, so kill this thread and respawn it elsewhere
      if !(local _unit) exitWith {
        [[_unit], "AGM_Medical_fnc_simulateHealth", _unit] call AGM_Core_fnc_execRemoteFnc;
      };

      _blood      = _unit getVariable ["AGM_Blood",      1];
      _pain       = _unit getVariable ["AGM_Pain",       0];
      _painkiller = _unit getVariable ["AGM_Painkiller", 0];
      _epinephrine= _unit getVariable ["AGM_Epinephrine", 0];

      // Bleeding
      if !([_unit] call AGM_Medical_fnc_isInMedicalVehicle) then {
        _bloodLossRate = (damage _unit) * BLOODLOSSRATE *
                         (_unit getVariable ["AGM_Medical_CoefBleeding", AGM_Medical_CoefBleeding]) *
                         (1 + 5 * getFatigue _unit) *
                         (1 + 5 * _epinephrine);

        _blood = _blood - _bloodLossRate * DELTATIME;
        _blood = _blood max 0;
      };

      // Pain Reduction
      _pain = (_pain - 0.001 * DELTATIME) max 0;

      // Pain killer Reduction
      _painkiller = (_painkiller - 0.0015 * DELTATIME) max 0;

      // Epinephrine Reduction
      _epinephrine = (_epinephrine - 0.015 * DELTATIME) max 0;

      _unit setVariable ["AGM_Blood",      _blood,      True];
      _unit setVariable ["AGM_Pain",       _pain,       True];
      _unit setVariable ["AGM_Painkiller", _painkiller, True];
      _unit setVariable ["AGM_Epinephrine",_epinephrine, True];

      // Pass out due to low blood
      if (_blood <= BLOODTRESHOLD0 and !(_unit getVariable ["AGM_isUnconscious", False])) then {
        _passoutFatigue = ((_blood - BLOODTRESHOLD0) / (BLOODTRESHOLD1 - BLOODTRESHOLD0)) max 0.01;
        if ((getFatigue _unit) - 0.1 * _epinephrine > _passoutFatigue) then {
          [_unit] call AGM_Medical_fnc_knockOut;
        };
      };

      // Die from low blood
      if (_blood <= BLOODTRESHOLD2 and {AGM_Medical_PreventDeathWhileUnconscious == 0}) then {
        // fx: don't get the uniform bloody if there are no wounds
        _unit setHitPointDamage ["HitHead", 1];
      };

      sleep DELTATIME;
    };

  }];
};
