// by commy2, Nic547
// Makes a civilian unable to move

private "_unit";

_unit = _this select 0;
if (captive _unit) then {
	[_unit, "AGM_Handcuffed", false] call AGM_Interaction_fnc_setCaptivityStatus;
	_unit playMoveNow "AmovPercMstpSnonWnonDnon_EaseOut";
} else {
	[_unit, "AGM_Handcuffed", true] call AGM_Interaction_fnc_setCaptivityStatus;
	while {[_unit, "AGM_Handcuffed", true] call AGM_Interaction_fnc_setCaptivityStatus} do {
		_unit playMove "AmovPercMstpSnonWnonDnon_Ease";
	};
};
