// by commy2, Nic547
// Makes a civilian unable to move

private ["_unit", "_state"];

_unit = _this select 0;
_state = _this select 1;

if (_state) then {
	if (_unit getVariable ["AGM_isCaptive", false]) exitWith {};

	_unit setVariable ["AGM_isCaptive", true, true];
	[_unit, "AGM_Handcuffed", true] call AGM_Interaction_fnc_setCaptivityStatus;

	_unit spawn {
		while {_this getVariable ["AGM_isCaptive", false]} do {
			_this playMove "AmovPercMstpSnonWnonDnon_Ease";

			if (!alive _this) then {
				_this setVariable ["AGM_isCaptive", false, true];
			};
		};
		_this playMoveNow "AmovPercMstpSnonWnonDnon_EaseOut";

		[_this, "AGM_Handcuffed", false] call AGM_Interaction_fnc_setCaptivityStatus;
	};
} else {
	_unit setVariable ["AGM_isCaptive", false, true];
};
