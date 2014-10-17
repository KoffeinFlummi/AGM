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

if (currentWeapon _unit == primaryWeapon _unit) exitWith {
  _unit playMoveNow "amovppnemstpsraswrfldnon";
};
if (currentWeapon _unit == secondaryWeapon _unit) exitWith {
  // _unit playMoveNow "amovppnemstpsraswlnrdnon"; (launchers can't go prone right now anyways)
  _unit playMoveNow "amovppnemstpsraswrfldnon";
};
if (currentWeapon _unit == handgunWeapon _unit) exitWith {
  _unit playMoveNow "AmovPpneMstpSrasWpstDnon";
};
_unit playMoveNow "amovppnemstpsnonwnondnon";
