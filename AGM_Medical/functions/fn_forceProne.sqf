/*
 * Author: KoffeinFlummi
 *
 * Force a unit to go prone.
 * 
 * Argument:
 * 0: Unit (Object)
 * 
 * Return value:
 * none
 */

_unit = _this select 0;
_anim1 = animationState _unit;
waitUntil { animationState _unit != _anim1; };

_anim = "amovppnemstpsnonwnondnon";
if (currentWeapon _unit == primaryWeapon _unit) then {
  _anim = "amovppnemstpsraswrfldnon";
};
if (currentWeapon _unit == secondaryWeapon _unit) then {
  // _anim = "amovppnemstpsraswlnrdnon"; (launchers can't go prone right now anyways)
   _anim = "amovppnemstpsraswrfldnon";
};
if (currentWeapon _unit == handgunWeapon _unit) then {
  _anim = "AmovPpneMstpSrasWpstDnon";
};
_unit playMoveNow _anim;
waitUntil { animationState _unit != _anim; };
