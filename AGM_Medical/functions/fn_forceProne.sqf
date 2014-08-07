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

private ["_unit"];
_unit = _this select 0;
if (_unit getVariable "AGM_NoLegs") then {
	if (stance _unit != "PRONE") then {
		if(!_unit getVariable "AGM_GoDown") then {
			hint "ok";
			_unit setVariable ["AGM_GoDown", true];
			[_unit] spawn {
				private ["_unit","_anim1"];
				_unit = _this select 0;
				_anim1 = animationState _unit;
				waitUntil { animationState _unit != _anim1; };
				sleep 2;
				_unit playActionNow "down";
				waituntil {stance _unit == "PRONE"};
				_unit setVariable ["AGM_GoDown", false];
			};
		};
	};
};

/*
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
*/
