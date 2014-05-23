/*
 * Author: KoffeinFlummi
 *
 * Creates ear ringing effect with set strength.
 *
 * Arguments:
 * 0: strength of ear ringing (Number between 0 and 1)
 *
 * Return Value:
 * none
 */

_strength = _this select 0;

if (player getVariable ["X39_MedSys_var_hasEarplugs", false] or AGM_EarPlugsin) then {
  _strength = _strength / 4;
};

if (_strength > AGM_NewStrength) then {
  AGM_NewStrength = _strength;
};

if (_strength > 0.75 and !AGM_EarRingingPlaying) exitWith {
  playSound ["AGM_EarRinging_Heavy", true];
  AGM_EarRingingPlaying = true;
  0 spawn {
    sleep 7;
    AGM_EarRingingPlaying = false;
  };
};
if (_strength > 0.5 and !AGM_EarRingingPlaying) exitWith {
  playSound ["AGM_EarRinging_Medium", true];
  AGM_EarRingingPlaying = true;
  0 spawn {
    sleep 5;
    AGM_EarRingingPlaying = false;
  };
};
if (_strength > 0.2 and !AGM_EarRingingPlaying) exitWith {
  playSound ["AGM_EarRinging_Weak", true];
  AGM_EarRingingPlaying = true;
  0 spawn {
    sleep 3;
    AGM_EarRingingPlaying = false;
  };
};