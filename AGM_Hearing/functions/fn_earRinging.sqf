/*
 * Author: KoffeinFlummi, commy2
 *
 * Creates ear ringing effect with set strength.
 *
 * Arguments:
 * 0: strength of ear ringing (Number between 0 and 1)
 *
 * Return Value:
 * none
 */

private ["_unit", "_strength"];

_unit = _this select 0;
_strength = _this select 1;

if (_player getVariable ["AGM_hasEarPlugsin", false] || {_player getVariable ["X39_MedSys_var_hasEarplugs", false]}) then {
  _strength = _strength / 4;
};

AGM_NewStrength = AGM_NewStrength max _strength;

if (AGM_EarRingingPlaying) exitWith {};

if (_strength > 0.75) exitWith {
  playSound ["AGM_EarRinging_Heavy", true];
  AGM_EarRingingPlaying = true;
  0 spawn {
    sleep 7;
    AGM_EarRingingPlaying = false;
  };
};
if (_strength > 0.5) exitWith {
  playSound ["AGM_EarRinging_Medium", true];
  AGM_EarRingingPlaying = true;
  0 spawn {
    sleep 5;
    AGM_EarRingingPlaying = false;
  };
};
if (_strength > 0.2) exitWith {
  playSound ["AGM_EarRinging_Weak", true];
  AGM_EarRingingPlaying = true;
  0 spawn {
    sleep 3;
    AGM_EarRingingPlaying = false;
  };
};
