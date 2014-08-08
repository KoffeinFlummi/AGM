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

if (player getVariable "AGM_NoLegs") then {
	if (stance player != "PRONE") then {
		if!(player getVariable "AGM_GoDown") then {
			player setVariable ["AGM_GoDown", true];
			[] spawn {
				_anim1 = animationState player;
				waitUntil { animationState player != _anim1; };
				sleep 2;
				player playActionNow "down";
				waituntil {stance player == "PRONE"};
				player setVariable ["AGM_GoDown", false];
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
