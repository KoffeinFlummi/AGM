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

#define BLOODTRESHOLD1 0.35
#define BLOODTRESHOLD2 0
#define BLOODLOSSRATE 0.04

private ["_unit", "_script", "_blood", "_pain"];

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
           (damage _unit < 1 or
           _unit getVariable ["AGM_Pain", 0] > 0 or
           _unit getVariable ["AGM_Painkiller", 0] > 0)
          } do {

      // Unit has changed locality, so kill this thread and respawn it elsewhere
      if !(local _unit) exitWith {
        [[_unit], "AGM_Medical_fnc_simulateHealth", _unit] call AGM_Core_fnc_execRemoteFnc;
      };

      _blood      = _unit getVariable ["AGM_Blood",      1];
      _pain       = _unit getVariable ["AGM_Pain",       0];
      _painkiller = _unit getVariable ["AGM_Painkiller", 0];

      // Bleeding
      if !([_unit] call AGM_Medical_fnc_isInMedicalVehicle) then {
        _blood = _blood - BLOODLOSSRATE * (_unit getVariable ["AGM_Medical_CoefBleeding", AGM_Medical_CoefBleeding]) * (damage _unit);
        _blood = _blood max 0;
      };

      // Pain Reduction
      _pain = (_pain - 0.01) max 0;

      // Pain killer Reduction
      _painkiller = (_painkiller - 0.015) max 0;


      _unit setVariable ["AGM_Blood",      _blood,      True];
      _unit setVariable ["AGM_Pain",       _pain,       True];
      _unit setVariable ["AGM_Painkiller", _painkiller, True];


      // Pass out due to low blood
      if (_blood <= BLOODTRESHOLD1 and !(_unit getVariable ["AGM_isUnconscious", False])) then {
        [_unit] call AGM_Medical_fnc_knockOut;
      };

      // Die from low blood
      if (_blood <= BLOODTRESHOLD2 and {AGM_Medical_PreventDeathWhileUnconscious == 0}) then {
        // fx: don't get the uniform bloody if there are no wounds
        _unit setHitPointDamage ["HitHead", 1];
      };

      sleep 10;
    };

  }];
};
