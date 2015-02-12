// by commy2

private ["_unit", "_anim"];

_unit = _this select 0;

// only play animation when standing due to lack of animations, sry
if !(stance _unit in ["CROUCH", "STAND"]) exitWith {};

// get correct animation by weapon
_anim = switch (currentWeapon _unit) do {
  case (""): {"AmovPercMsprSnonWnonDf_AmovPpneMstpSnonWnonDnon"};
  case (primaryWeapon _unit): {
    [
      ["AmovPercMsprSlowWrfldf_AmovPpneMstpSrasWrflDnon_2", "AmovPercMsprSlowWrfldf_AmovPpneMstpSrasWrflDnon"] select (speed _unit > 1),
      ["AmovPercMsprSlowWrfldf_AmovPpneMstpSrasWrflDnon_2", "AmovPercMsprSlowWrfldf_AmovPpneMstpSrasWrflDnon"] select (speed _unit > 1),
      "AmovPercMstpSrasWrflDnon_AadjPpneMstpSrasWrflDleft",
      "AmovPercMstpSrasWrflDnon_AadjPpneMstpSrasWrflDright"
    ] select floor random 4;
  };
  case (handgunWeapon _unit): {
    [
      "AmovPercMsprSlowWpstDf_AmovPpneMstpSrasWpstDnon",
      "AmovPercMsprSlowWpstDf_AmovPpneMstpSrasWpstDnon",
      "AmovPercMstpSrasWpstDnon_AadjPpneMstpSrasWpstDleft",
      "AmovPercMstpSrasWpstDnon_AadjPpneMstpSrasWpstDright"
    ] select floor random 4;
  };
  default {""};
};

// exit if no animation for this weapon exists, i.E. binocular or rocket launcher
if (_anim == "") exitWith {};

// don't mess with transitions. don't fall then.
if ([_unit] call AGM_Core_fnc_inTransitionAnim) exitWith {};

[_unit, _anim, 2] call AGM_Core_fnc_doAnimation;
