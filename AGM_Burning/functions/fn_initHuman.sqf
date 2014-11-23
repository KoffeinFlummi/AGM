// by commy2

(_this select 0) addEventHandler ["HandleDamage", {
	private "_unit";

	_unit = _this select 0;

	if (isBurning _unit && {_unit getVariable ["AGM_Burning_lastFrameDamage", -1] != diag_frameno}) then {
		_unit setVariable ["AGM_Burning_lastFrameDamage", diag_frameno];
		_this call AGM_Burning_fnc_burn;
	};
	nil
}];
