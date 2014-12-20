// by commy2

#define CLIMB_ANIM "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInMedium" //"AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh"

private "_unit";

_unit = _this select 0;

if !(_unit getVariable ["AGM_isClimbInit", false]) then {
	_unit addEventHandler ["AnimDone", {
		if (local (_this select 0) && {_this select 1 == CLIMB_ANIM}) then {_this call AGM_Movement_fnc_handleClimb}
	}];

	_unit setVariable ["AGM_isClimbInit", true];
};

[_unit] call AGM_Core_fnc_fixLoweredRifleAnimation;
[_unit, CLIMB_ANIM, 0] call AGM_Core_fnc_doAnimation;
